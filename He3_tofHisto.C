#include <iostream>
#include <fstream>
#include <cstdlib>
#include "TROOT.h"
#include "TH1D.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TF1.h"
#include "TH2.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TLegend.h"
#include "THStack.h"
#include "TPaveText.h"
#include "TCanvas.h"
#include "TObject.h"
#include "TGraph.h"
#include "TLine.h"
#include "He3_tofHisto.h"

TString trigger = "HM"; // "HNU" or "HM" 
const Int_t nParticles = 3;	
const Int_t nPtBins = 3;
Double_t ptBins[] = {1.4, 1.8, 2.2, 2.6};
const TString particleNames[] = {"{}^{3}He", "{}^{3}#bar{He}","{}^{3}He+{}^{3}#bar{He}"};
const TString particleShortNames[] = {"He3", "AntiHe", "both"};
int particleColors[] = {kBlue, kRed, kBlack};
TString Folder = "result";
TString rootfile = "/Users/matthias/alice/Master/Makros/Rootfiles/Data.root";
TString rootFilePath = "/Users/matthias/alice/Master/Makros/Rootfiles";
//________________________________________________________________________________________________________________________
void He3_tofHisto(){
    fit();
    histoHe3();
}
//________________________________________________________________________________________________________________________
void fit(){
	TH1D * histTOFfit[nParticles][nPtBins] = {0};
	TH1D * histRawYield[nParticles] = {0};
	TH1D * histRawYieldFit[nParticles] = {0};
	TFile * f = new TFile(rootfile, "UPDATE");
	TCanvas *c = new TCanvas();

	for (int particle = 0; particle < nParticles; particle++){
		// create histos for raw yield, mean, sigma  
		histRawYield[particle] = new TH1D(Form("histRaw%02d%02d", 0,particle), ";#it{p}_{T} (Gev/#it{c});Counts", nPtBins, ptBins);
		histRawYieldFit[particle] = new TH1D(Form("histRawFit%02d",particle), ";#it{p}_{T} (Gev/#it{c});Counts", nPtBins, ptBins);
		for (int pt = 0; pt < nPtBins; pt++){
			// load pt-bin histos from file
			histTOFfit[particle][pt] = (TH1D*)f->Get(Form("histPtHe3%02d%02d%02d", 0, particle, pt));
			histTOFfit[particle][pt]->SetName(Form("histTOFfit%02d%02d%02d", 0, particle, pt));
			histTOFfit[particle][pt]->SetTitle("");
			// define fit function
			TF1 *fit = new TF1("fitfunc", "gaus(0)", 1.5, 2.5); // use "crystalball" instead of "gaus" if there is a tail  
			fit->SetParNames("Constant", "Mean", "Sigma");
			fit->SetParameters(20,1.96,0.2);
			
			if (particle == 0){
				if (pt == 0){
					fit->FixParameter(2, 0.0927816);
				}	
			}
			if (particle == 0){
				if (pt == 1){
					fit->FixParameter(0, 65);
					fit->FixParameter(2, 0.0586948);
				}	
			}
			if (particle == 1){
				if (pt == 0){
					fit->FixParameter(0, 12);
					fit->FixParameter(1, 2.10);
					fit->FixParameter(2, 0.106929);
				}	
			}
			if (particle == 1){
				if (pt == 2){
					fit->FixParameter(2, 0.0753235);
				}	
			}
			
			//TFitResultPtr fp = histTOFfit[particle][pt]->Fit("fitfunc","S");
			histTOFfit[particle][pt]->Fit(fit, "B");
			// fit histo and get parameter
			Double_t integral = 0, intError = 0, fitInt = 0;
			if (fit){
				Double_t *fitParams = fit->GetParameters();				
				// raw yield
				Double_t lo = fitParams[1] - 3*fitParams[2];
				Double_t hi = fitParams[1] + 3*fitParams[2];
				integral = histTOFfit[particle][pt]->IntegralAndError(histTOFfit[particle][pt]->FindBin(lo), histTOFfit[particle][pt]->FindBin(hi), intError);
				histRawYield[particle]->SetBinContent(pt+1, integral);
				histRawYield[particle]->SetBinError(pt+1, intError);
				fitInt = fit->Integral(lo, hi) / histTOFfit[particle][pt]->GetBinWidth(1);
			    histRawYieldFit[particle]->SetBinContent(pt+1, fitInt);
				cout << "Bin Counting " << integral << ", Funktion " << fitInt << endl;
                cout << "Param High " << hi << ", Low " << lo << endl;

			}
			histTOFfit[particle][pt]->Write(0, TObject::kOverwrite);
		}
		histRawYield[particle]->Write(0, TObject::kOverwrite);
		histRawYieldFit[particle]->Write(0, TObject::kOverwrite);
	}
	f->Close();
	c->Close();
}
//________________________________________________________________________________________________________________________
void histoHe3(){
	TH1::AddDirectory(kFALSE);
	gStyle->SetOptFit(111);
	gStyle->SetOptStat("ne");
    //TFile *f = TFile::Open(rootfile);
	TFile * f = new TFile(rootfile);
	TFile * file = new TFile(Folder + "/ResultsHe3.root", "UPDATE");
    TH1D * histTOFfit[nParticles][nPtBins] = {0};
    TCanvas * canPtBinsHe3[nParticles] = {0};
    int rows = 3;
	if (nPtBins > 10) rows++;
	if (nPtBins <= 4) rows--;
    for (int particle = 0; particle < nParticles; particle++) {
		canPtBinsHe3[particle] = new TCanvas(Form("ptBinsHe3%02d%02d", 0, particle), "pt bins", 1400,900);
		canPtBinsHe3[particle]->Divide(3,rows);
		for (int pt = 0; pt < nPtBins; pt++){
			canPtBinsHe3[particle]->cd(pt + 1);
			histTOFfit[particle][pt] = (TH1D*)f->Get(Form("histTOFfit%02d%02d%02d", 0, particle, pt));
			histTOFfit[particle][pt]->SetStats(0);
			histTOFfit[particle][pt]->Draw();
		}
	TPaveText *cutLabel = new TPaveText(0.1, .1, 0.9, 0.9, "blNDC"); 
	cutLabel->SetTextAlign(13);
	cutLabel->SetTextFont(43);
	cutLabel->SetTextSize(22);
	cutLabel->SetBorderSize(0);
	cutLabel->SetFillStyle(0);
	cutLabel->AddText("|y| < 0.5");
	cutLabel->AddText("|TPC n#sigma| < 3");
	cutLabel->AddText("|Dca XY| < 0.15 cm");
	cutLabel->AddText("|Dca Z| < 0.15 cm");
	TPaveText *infoLabel=new TPaveText(0.1, .1, 0.9, 0.9, "blNDC");
	infoLabel->SetTextAlign(13);
	infoLabel->SetTextFont(43);
	infoLabel->SetTextSize(24);
	infoLabel->SetBorderSize(0);
	infoLabel->SetFillStyle(0);
 	infoLabel->AddText("Particle: " + particleNames[particle]);
 	infoLabel->AddText("pp #sqrt{s} = 13 TeV");	 
	if (trigger == "HM")
	{
		infoLabel->AddText("Trigger: HM");
	}
	if (trigger == "HNU")
	{
		infoLabel->AddText("Trigger: HNU HQU");
	}
	infoLabel->AddText("work in progress"); 
	canPtBinsHe3[particle]->cd(3 * rows - 1);
	cutLabel->Draw();
	canPtBinsHe3[particle]->cd(3 * rows);
	infoLabel->Draw();
	if (trigger == "HM")
	{
		canPtBinsHe3[particle]->SaveAs(Folder + Form("/Plots/He3/HM/%02dBinsHe3%02d.pdf", nPtBins, particle));
		canPtBinsHe3[particle]->SaveAs(Folder + Form("/Plots/He3/HM/%02dBinsHe3%02d.png", nPtBins, particle));
		canPtBinsHe3[particle]->SaveAs(Folder + Form("/Plots/He3/HM/%02dBinsHe3%02d.root", nPtBins, particle));	
	}
	if (trigger == "HNU")
	{
		canPtBinsHe3[particle]->SaveAs(Folder + Form("/Plots/He3/HNU/%02dBinsHe3%02d.pdf", nPtBins, particle));
		canPtBinsHe3[particle]->SaveAs(Folder + Form("/Plots/He3/HNU/%02dBinsHe3%02d.png", nPtBins, particle));
		canPtBinsHe3[particle]->SaveAs(Folder + Form("/Plots/He3/HNU/%02dBinsHe3%02d.root", nPtBins, particle));	
	}
	
    }
	TCanvas *canTOF[nParticles][nPtBins] = {0}; 
	TLegend *legendtof[nParticles][nPtBins] = {0};
	TLegend *legendtof2[nParticles][nPtBins] = {0};
	TF1* fitres[nParticles][nPtBins] = {0};
		for (int particle = 0; particle < nParticles; particle++){
		for (int pt = 0; pt < nPtBins; pt++){
			fitres[particle][pt] = histTOFfit[particle][pt]->GetFunction("fitfunc");
			fitres[particle][pt]->SetLineWidth(5);
			canTOF[particle][pt] = new TCanvas(Form("pt%1d%1d", particle, pt),Form("pt%1d%1d", particle, pt), 1400,1400);
			canTOF[particle][pt]->cd();
			canTOF[particle][pt]->SetHighLightColor(2);
			histTOFfit[particle][pt]->SetStats(0);
			histTOFfit[particle][pt]->SetTitle("");
			histTOFfit[particle][pt]->Draw();
			legendtof[particle][pt] = new TLegend(0.537196,0.583235,0.927039,0.903188);
			legendtof[particle][pt]->SetEntrySeparation(.4);
			legendtof[particle][pt]->SetFillStyle(0);
			legendtof[particle][pt]->SetTextFont(42);
			legendtof[particle][pt]->SetTextSize(0.042);
			canTOF[particle][pt]->SetLeftMargin(0.15);
			canTOF[particle][pt]->SetTopMargin(0.0661157);
   			canTOF[particle][pt]->SetBottomMargin(0.133412);
			histTOFfit[particle][pt]->SetLineWidth(5);
			histTOFfit[particle][pt]->SetLineColor(kBlack);
   			histTOFfit[particle][pt]->SetMarkerStyle(20);
   			histTOFfit[particle][pt]->SetMarkerSize(2);
			histTOFfit[particle][pt]->GetYaxis()->SetLabelFont(42);
   			histTOFfit[particle][pt]->GetYaxis()->SetLabelSize(0.05);
   			histTOFfit[particle][pt]->GetYaxis()->SetTitleSize(0.05);
   			histTOFfit[particle][pt]->GetYaxis()->SetTitleFont(42);
			histTOFfit[particle][pt]->GetXaxis()->SetLabelFont(42);
   			histTOFfit[particle][pt]->GetXaxis()->SetLabelSize(0.05);
   			histTOFfit[particle][pt]->GetXaxis()->SetTitleOffset(1);
   			histTOFfit[particle][pt]->GetXaxis()->SetTitleFont(42);
			histTOFfit[particle][pt]->GetXaxis()->SetTitleSize(0.05);
			legendtof[particle][pt]->AddEntry((TObject*)0, "This work", "");
			legendtof[particle][pt]->AddEntry((TObject*)0, "ALICE pp #sqrt{s} = 13 TeV", "");
			if(particle == 1){
				legendtof[particle][pt]->AddEntry((TObject*)0, Form("Particle: {}^{3}%sHe", "#bar"), "");
			}
			if(particle == 2){
				legendtof[particle][pt]->AddEntry((TObject*)0, Form("Particle: {}^{3}He + {}^{3}%sHe", "#bar"), "");
			}
			if(particle == 0){
				legendtof[particle][pt]->AddEntry((TObject*)0, Form("Particle: {}^{3}He"), "");
			}
			legendtof[particle][pt]->AddEntry((TObject*)0, Form("%1.2f < #frac{#it{p}_{T}}{(GeV/#it{c})} < %1.2f ",ptBins[pt], ptBins[pt+1]), "");
			if (trigger == "HM")
			{
				legendtof[particle][pt]->AddEntry((TObject*)0, "High-multiplicity trigger", "");
			}
			if (trigger == "HNU")
			{
				legendtof[particle][pt]->AddEntry((TObject*)0, "TRD trigger", "");
			}
			legendtof[particle][pt]->SetBorderSize(0);
			legendtof[particle][pt]->Draw("same");
			legendtof2[particle][pt] = new TLegend(0.213504,0.701511,0.532847,0.845088);
			legendtof2[particle][pt]->SetEntrySeparation(.2);
			legendtof2[particle][pt]->SetFillStyle(0);
			legendtof2[particle][pt]->SetTextFont(43);
			legendtof2[particle][pt]->SetTextSize(30);
			legendtof2[particle][pt]->SetBorderSize(0);
			legendtof2[particle][pt]->AddEntry(fitres[particle][pt],"Fit","l");
			legendtof2[particle][pt]->AddEntry(histTOFfit[particle][pt],"Data","l");
			legendtof2[particle][pt]->Draw("same");
			if (trigger == "HM")
			{
				canTOF[particle][pt]->SaveAs(Folder + Form("/Plots/He3/HM/bins/He3Plot%02d%02d.pdf", particle, pt));
				canTOF[particle][pt]->SaveAs(Folder + Form("/Plots/He3/HM/bins/He3Plot%02d%02d.root", particle, pt));
				canTOF[particle][pt]->SaveAs(Folder + Form("/Plots/He3/HM/bins/He3Plot%02d%02d.C", particle, pt));
			}
			if (trigger == "HNU")
			{
				canTOF[particle][pt]->SaveAs(Folder + Form("/Plots/He3/HNU/bins/He3Plot%02d%02d.pdf", particle, pt));
				canTOF[particle][pt]->SaveAs(Folder + Form("/Plots/He3/HNU/bins/He3Plot%02d%02d.root", particle, pt));
				canTOF[particle][pt]->SaveAs(Folder + Form("/Plots/He3/HNU/bins/He3Plot%02d%02d.C", particle, pt));
			}
			
		}
	}
	// raw yield
	TH1D * histRaw[nParticles] = {0};
	TH1D * histRawFit[nParticles] = {0};
	for (int particle = 0; particle < nParticles; particle++){
		histRaw[particle] = (TH1D*) f->Get(Form("histRaw%02d%02d", 0, particle));
		histRawFit[particle] = (TH1D*) f->Get(Form("histRawFit%02d", particle));  
		histRaw[particle]->SetTitle(" ");
	}
	histRaw[0]->SetMarkerStyle(4);
	histRaw[1]->SetMarkerStyle(8);
	TCanvas *canRaw = new TCanvas("raw", "Raw Yield", 800, 1000);
	TLegend *particleLegend = legendParticle(histRaw, 2);
	canRaw->cd();
	canRaw->Update();
	plotRatio((TPad*)gROOT->GetSelectedPad(), histRaw);
	particleLegend->Draw("Same");
	//histRaw[2]->Scale(1./2.);
	//histRaw[2]->Draw("SAME");
	if (trigger == "HM")
	{
		canRaw->SaveAs(Folder + "/Plots/He3/HM/rawYieldHe3Bin.pdf");
		canRaw->SaveAs(Folder + "/Plots/He3/HM/rawYieldHe3Bin.C");
	}
	if (trigger == "HNU")
	{
		canRaw->SaveAs(Folder + "/Plots/He3/HNU/rawYieldHe3Bin.pdf");
		canRaw->SaveAs(Folder + "/Plots/He3/HNU/rawYieldHe3Bin.C");
	}
	
	canRaw->Write(0, TObject::kOverwrite);
	//canRaw->Close();
	TCanvas *canRawFit = new TCanvas("rawFit", "Raw Yield Function", 800, 1000);
    TLegend *particleLegendFit = legendParticle(histRawFit, 2);
    canRawFit->cd();
    canRawFit->Update();
    plotRatio((TPad*) gROOT->GetSelectedPad(), histRawFit);
    particleLegendFit->Draw("SAME");
    histRawFit[2]->Scale(1./2.);
	histRawFit[2]->Draw("SAME");
	if (trigger == "HM")
	{
		canRawFit->SaveAs(Folder + Form("/Plots/He3/HM/rawYieldHe3FitFunc.pdf"));
	}
	if (trigger == "HNU")
	{
		canRawFit->SaveAs(Folder + Form("/Plots/He3/HNU/rawYieldHe3FitFunc.pdf"));
	}
    canRawFit->Write(0, TObject::kOverwrite);

    f->Close();
}
//_________________________________________________________________________________________________________
TLegend* legendParticle(TH1D* h[nParticles], int partMode) {
// partMode : 0 particle, anti; 1 particle, anti, particle+anti; 2 particle, anti, (particle+anti)/2;
	TLegend *particleLegend = new TLegend(0.75,0.75,0.95,0.9);
	particleLegend->SetTextFont(43);
	particleLegend->SetTextSize(18);
	particleLegend->SetBorderSize(0);
	particleLegend->SetFillStyle(0);
	for (int particle = 0; particle < nParticles; particle++){
		if (particle < 2)
			particleLegend->AddEntry(h[particle] , particleNames[particle], "L");
		else {
			if (partMode == 1)
				particleLegend->AddEntry(h[particle] , particleNames[particle], "L");	
			//if (partMode == 2)		
			//	particleLegend->AddEntry(h[particle] , "(" + particleNames[particle] + ")/2)", "L");	
		}	
	}
	return particleLegend;
}
//_________________________________________________________________________________________________________
void plotRatio(TPad* pad, TH1D* h[2], Bool_t log, double dist) {
	for (int i = 0; i < 2; i++) {
		h[i]->SetLineColor(particleColors[i]);
		h[i]->SetStats(0);
	}
	double left = 0.15, right = 0.02;
	if (dist > 4.1) left = 0.25;
	pad->cd();	
	TPad *pad1 = new TPad("pad1" + (TString)h[0]->GetName(), "pad1", 0, 0.4, 1, 1.0);
	pad1->SetBottomMargin(0);
	pad1->SetLeftMargin(left);
	pad1->SetRightMargin(right);
	pad1->Draw(); 
	if (log) pad1->SetLogy();           
	pad1->cd();               
	TString title = (TString)h[0]->GetTitle() + ";" + h[0]->GetXaxis()->GetTitle() + ";" + h[0]->GetYaxis()->GetTitle();			
	THStack *hs = new THStack("hs" + (TString)h[0]->GetName(),title);
	hs->Add(h[0]);
	hs->Add(h[1]);
	if (log) 
		hs->SetMaximum(5 * hs->GetMaximum("nostack"));
	else {
		hs->SetMaximum(1.3 * hs->GetMaximum("nostack"));
		hs->SetMinimum(0.01);
	}
	hs->Draw("nostack");
	gPad->Update(); 
	setYaxis(hs->GetYaxis(), dist);
	pad->cd();	
	TPad *pad2 = new TPad("pad2" + (TString)h[0]->GetName(), "pad2", 0, 0.05, 1, 0.4);
	pad2->SetTopMargin(0);
	pad2->SetLeftMargin(left);
	pad2->SetRightMargin(right);
	pad2->SetBottomMargin(0.3);
	pad2->SetGridy(); // vertical grid
	pad2->Draw();
	pad2->cd();  
	TH1D *h3 = (TH1D*)h[1]->Clone("histRatio" + (TString)h[0]->GetName());
	h3->SetLineColor(kBlack);

	h3->SetStats(0);      
	h3->Divide(h[0]);
	//h3->SetMarkerStyle(21);
	h3->SetTitle(""); 
	// Y axis ratio plot settings
	h3->GetYaxis()->SetTitle("{}^{3}#bar{He} / {}^{3}He");
	setYaxis(h3->GetYaxis(), dist);
	//h3->SetMaximum(h3->GetMaximum()*1.49); 
	 h3->GetYaxis()->SetNdivisions(5);
	// X axis ratio plot settings
	h3->GetXaxis()->SetTitleSize(16);
	h3->GetXaxis()->SetTitleFont(43);
	h3->GetXaxis()->SetTitleOffset(4.);
	//h3->GetXaxis()->SetLabelOffset(2.);
	h3->GetXaxis()->SetLabelFont(43); 
	h3->GetXaxis()->SetLabelSize(15);
	h3->GetXaxis()->SetTitle("#it{p}_t (GeV/c)");

	h3->Draw("ep");       // Draw the ratio plot    
	pad1->cd();               
}
//_________________________________________________________________________________________________________
void setYaxis(TAxis *axis,double dist) {
	axis->SetTitleSize(16);
	axis->SetTitleFont(43);
	axis->SetTitleOffset(dist);
	axis->SetLabelFont(43); 
	axis->SetLabelSize(15);		
}
//_________________________________________________________________________________________________________