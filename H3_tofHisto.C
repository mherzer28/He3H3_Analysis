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
#include "H3_tofHisto.h"

TString trigger = "HQU"; // "HNU" "HNU&QHU" "HQU" or "HM" 
const Int_t nParticles = 3;	
const Int_t nPtBins = 3;
const TString particleNames[] = {"{}^{3}H","{}^{3}#bar{H}","{}^{3}H+{}^{3}#bar{H}"};
const TString particleShortNames[] = {"H3", "AntiH3", "both"}; 
int particleColors[] = {kBlue, kRed, kBlack};
TString Folder = "result";
TString rootFilePath = Folder;
TString rootfile;
std::vector<std::vector<int>> tofBinsH3(3, std::vector<int>(100, 0)); // Changed to vector
std::vector<double> ptBins; // Changed to vector
std::vector<double> cutConf(10, 0); // Changed to vector
//________________________________________________________________________________________________________________________
void H3_tofHisto(){
    fit();
    histoH3();
}
//___________________________________________________________________________________________________________
void fit(){
	if (trigger == "HNU") {
        rootfile = "/Users/matthias/alice/Master/Makros/Rootfiles/DataH3_HNU.root";
        tofBinsH3[0] = {25, 25, 25, 25, 25, 25, 25, 35, 25}; // TRD H3 TRD
        tofBinsH3[1] = {25, 25, 25, 25, 25, 25, 25, 35, 25}; // TRD Anti H3
        tofBinsH3[2] = {25, 25, 25, 25, 25, 25, 25, 35, 25}; // Both
        ptBins = {1.3, 1.8, 2.3, 2.8}; // HNU
        cutConf = {0.15,  0.15,  2.0,    120,    2,     1,      1,       0,        0,       0};
    } else if (trigger == "HQU") {
        rootfile = "/Users/matthias/alice/Master/Makros/Rootfiles/DataH3_HQU.root";
        tofBinsH3[0] = {25, 25, 25, 15, 25, 25, 25, 35, 25}; // TRD H3 TRD
        tofBinsH3[1] = {25, 25, 25, 15, 25, 25, 25, 35, 25}; // TRD Anti H3
        tofBinsH3[2] = {25, 25, 25, 15, 25, 25, 25, 35, 25}; // Both
        ptBins = {1.3, 1.8, 2.3, 2.8}; // HNU
        cutConf = {0.15,  0.15,  2.0,    120,    2,     1,      1,       0,        0,       0};
    } else if (trigger == "HNU&HQU") {
        rootfile = "/Users/matthias/alice/Master/Makros/Rootfiles/DataH3_HNUHQU.root";
        tofBinsH3[0] = {25, 25, 25, 25, 25, 25, 25, 35, 25}; // TRD H3 TRD
        tofBinsH3[1] = {25, 25, 25, 25, 25, 25, 25, 35, 25}; // TRD Anti H3
        tofBinsH3[2] = {25, 25, 25, 25, 25, 25, 25, 35, 25}; // Both
        ptBins = {1.3, 1.8, 2.3, 2.8}; // HNU
        cutConf = {0.15,  0.15,  2.0,    120,    2,     1,      1,       0,        0,       0};
    } else {
        rootfile = "/Users/matthias/alice/Master/Makros/Rootfiles/DataH3.root";
        tofBinsH3[0] = {30, 30, 30, 30, 30, 40, 25, 35, 25}; // TRD H3 HM
        tofBinsH3[1] = {30, 30, 30, 30, 30, 40, 25, 35, 25}; // TRD Anti H3
        tofBinsH3[2] = {30, 30, 30, 30, 30, 40, 25, 35, 25}; // TRD Both
        ptBins = {1.4, 1.8, 2.2, 2.6};
		cutConf = {0.15,  0.15,  2.0,    120,    2,     1,      1,       3,        0,       0};
    }
	TH1D * histTOFfit[nParticles][nPtBins] = {0};
	TH1D * histRawYield[nParticles] = {0};
    TH1D * histRawYieldFit[nParticles] = {0};
	TH1D * histSpectra[nParticles] = {0};
	TFile *f = new TFile(rootfile, "UPDATE");
	TCanvas *c = new TCanvas(); 
    
	for (int particle = 0; particle < nParticles; particle++){
		// create histos for raw yield, mean, sigma  
		histRawYield[particle] = new TH1D(Form("histRaw%02d",particle), "", nPtBins, ptBins.data());
        histRawYieldFit[particle] = new TH1D(Form("histRawFit%02d",particle), "", nPtBins, ptBins.data());
		histSpectra[particle] = new TH1D(Form("histSpectra%02d",particle), "", nPtBins, ptBins.data());
		for (int pt = 0; pt < nPtBins; pt++){
			// load pt-bin histos from file
			histTOFfit[particle][pt] = (TH1D*)f->Get(Form("histPtH3%02d%02d",particle, pt));
			histTOFfit[particle][pt]->SetName(Form("histTOFfit%02d%02d",particle, pt));
			histTOFfit[particle][pt]->SetTitle("");
			TF1 *fitGaus = new TF1("gauss", "gaus(0)", 7., 9.);
            TF1 *backg = new TF1("backg", "expo(3)", 5., 11.);
			TF1 *fit = new TF1("fitfunc", "gaus(0)+expo(3)", 5, 11.);
			fit->SetParNames("Constant", "Mean", "Sigma", "p0", "p1");
			fit->SetParameters(20,7.89,0.25);
			if (trigger == "HNU&HQU")
			{
				if (particle == 0){
				if (pt == 0){
					fit->FixParameter(0, 6.53981);
					fit->FixParameter(1, 8.02328);
					fit->FixParameter(2, 0.231111);
					fit->FixParameter(3, 0.0335589);
					fit->FixParameter(4, 0.00379432);
					}	
				}
				if (particle == 1){
				if (pt == 0){
					fit->FixParameter(0, 6.13366);
					fit->FixParameter(1, 8.02857);
					fit->FixParameter(2, 0.141486);
					fit->FixParameter(3, -0.0814496);
					fit->FixParameter(4, 0.00890916);
					}	
				}
			}
			if (trigger == "HQU")
			{
				if (particle == 0){
				if (pt == 0){
					fit->FixParameter(2, 0.141263);
					}	
				}
				if (particle == 1){
				if (pt == 2){
					fit->FixParameter(0, 33);
					fit->FixParameter(1, 7.95);
					fit->FixParameter(2, 0.27);
					}	
				}
			}
            //histTOFfit[particle][pt]->Fit(fitGaus,"R");
			//histTOFfit[particle][pt]->Fit(backg,"R+");
			Double_t par[6];
			//fitGaus->GetParameters(&par[0]);
			//backg->GetParameters(&par[3]);
			
			//fit->SetParameters(par);
			histTOFfit[particle][pt]->Fit(fit, "R");
			TFitResultPtr fp = histTOFfit[particle][pt]->Fit(fit,"RS");
			backg->SetParameters(fit->GetParameter(3), fit->GetParameter(4));
            //histTOFfit[particle][pt]->Fit(backg,"R+");		
			//histTOFfit[particle][pt]->GetFunction("backg")->SetLineColor(kMagenta);
			// fit histo and get parameter
			Double_t integral = 0, intError = 0;
            Double_t backInt = 0, backIntError = 0, fitInt = 0, fitIntError = 0;
			if (fit){
				Double_t *fitParams = fit->GetParameters();				
				// raw yield
                backg->SetParameters(fit->GetParameter(3), fit->GetParameter(4));
				Double_t lo = fitParams[1] - 3*fitParams[2];
				Double_t hi = fitParams[1] + 3*fitParams[2];
				integral = histTOFfit[particle][pt]->IntegralAndError(histTOFfit[particle][pt]->FindBin(lo), histTOFfit[particle][pt]->FindBin(hi), intError);
                backInt = backg->Integral(lo, hi) / histTOFfit[particle][pt]->GetBinWidth(1);
                fitInt = fit->Integral(lo, hi) / histTOFfit[particle][pt]->GetBinWidth(1);
				fitIntError = fit->IntegralError(lo, hi, fp->GetParams(), fp->GetCovarianceMatrix().GetMatrixArray());
				histRawYield[particle]->SetBinContent(pt+1, integral - backInt);
				histRawYield[particle]->SetBinError(pt+1, intError + backIntError);
                histRawYieldFit[particle]->SetBinContent(pt+1, fitInt - backInt);
				histRawYieldFit[particle]->SetBinError(pt+1, fitIntError + backIntError);
                cout << "Bin Counting " << integral - backInt << ", Funktion " << fitInt - backInt << endl;
				cout << "Bin Counting error " << intError << ", Funktion " << fitIntError << endl;
                cout << "Param High " << hi << ", Low " << lo << endl;
				histSpectra[particle]->SetBinContent(pt+1, integral - backInt);
				histSpectra[particle]->SetBinError(pt+1, intError + backIntError);
				histSpectra[particle]->GetXaxis()->SetRangeUser(0.8, 4.5);
			}
			histTOFfit[particle][pt]->Write(0, TObject::kOverwrite);
		}
		histRawYield[particle]->Write(0, TObject::kOverwrite);
        histRawYieldFit[particle]->Write(0, TObject::kOverwrite);
		histSpectra[particle]->Write(0, TObject::kOverwrite);
	}
	f->Close();
	c->Close();
}
//________________________________________________________________________________________________________________________
void histoH3(){
	TH1::AddDirectory(kFALSE);
	gStyle->SetOptFit(111);
	gStyle->SetOptStat("ne");
    //TFile *f = TFile::Open(rootfile);
	TFile *f = TFile::Open(rootfile, "UPDATE");
	//TFile * file = new TFile(Folder + "/ResultsH3.root", "UPDATE");
    TH1D *histTOFfit[nParticles][nPtBins] = {0};
    TCanvas *canPtBinsH3[nParticles] = {0};
    int rows = 3;
	if (nPtBins > 10) rows++;
	if (nPtBins <= 4) rows--;
    for (int particle = 0; particle < nParticles; particle++) {
		canPtBinsH3[particle] = new TCanvas(Form("ptBinsH3%02d%02d", 0, particle), "pt bins", 1920,1080);
		canPtBinsH3[particle]->Divide(3,rows);
		for (int pt = 0; pt < nPtBins; pt++){
			canPtBinsH3[particle]->cd(pt + 1);
			histTOFfit[particle][pt] = (TH1D*)f->Get(Form("histTOFfit%02d%02d",particle, pt));
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
		cutLabel->AddText(Form("|TPC n#sigma| < %.0f",cutConf[2]));
		cutLabel->AddText("|Dca XY| < 0.15 cm");
		cutLabel->AddText("|Dca Z| < 0.15 cm");
		if (trigger == "HM"){
			cutLabel->AddText("tTRDnTracklets > 0");
		}
	
		TPaveText *infoLabel=new TPaveText(0.1, .1, 0.9, 0.9, "blNDC");
		infoLabel->SetTextAlign(13);
		infoLabel->SetTextFont(43);
		infoLabel->SetTextSize(11);
		infoLabel->SetBorderSize(0);
		infoLabel->SetFillStyle(0);
 		infoLabel->AddText("Particle: " + particleNames[particle]);
 		infoLabel->AddText("pp #sqrt{s} = 13 TeV");	 	
 		if (trigger == "HM"){
		infoLabel->AddText("Trigger: HM");
		}
		else if (trigger == "HNU&HQU"){
			infoLabel->AddText("Trigger: HNU & HQU");
		}
		else if (trigger == "HNU"){
			infoLabel->AddText("Trigger: HNU");
		}
		else if (trigger == "HQU"){
			infoLabel->AddText("Trigger: HQU");
		}

		infoLabel->AddText("work in progress"); 
		canPtBinsH3[particle]->cd(3 * rows);
		cutLabel->Draw();
		canPtBinsH3[particle]->cd(3 * rows - 1);
		infoLabel->Draw();
		if (trigger == "HM"){
			canPtBinsH3[particle]->SaveAs(Folder + Form("/Plots/H3/HM/%02dBinsH3%02d.pdf", nPtBins, particle));
			canPtBinsH3[particle]->SaveAs(Folder + Form("/Plots/H3/HM/%02dBinsH3%02d.png", nPtBins, particle));
			canPtBinsH3[particle]->SaveAs(Folder + Form("/Plots/H3/HM/%02dBinsH3%02d.root", nPtBins, particle));	
		}
		else if (trigger == "HNU&HQU"){
			canPtBinsH3[particle]->SaveAs(Folder + Form("/Plots/H3/HNUHQU/%02dBinsH3%02d.pdf", nPtBins, particle));
			canPtBinsH3[particle]->SaveAs(Folder + Form("/Plots/H3/HNUHQU/%02dBinsH3%02d.png", nPtBins, particle));
			canPtBinsH3[particle]->SaveAs(Folder + Form("/Plots/H3/HNUHQU/%02dBinsH3%02d.root", nPtBins, particle));	
		}
		else if (trigger == "HNU"){
			canPtBinsH3[particle]->SaveAs(Folder + Form("/Plots/H3/HNU/%02dBinsH3%02d.pdf", nPtBins, particle));
			canPtBinsH3[particle]->SaveAs(Folder + Form("/Plots/H3/HNU/%02dBinsH3%02d.png", nPtBins, particle));
			canPtBinsH3[particle]->SaveAs(Folder + Form("/Plots/H3/HNU/%02dBinsH3%02d.root", nPtBins, particle));	
		}
		else if (trigger == "HQU"){
			canPtBinsH3[particle]->SaveAs(Folder + Form("/Plots/H3/HQU/%02dBinsH3%02d.pdf", nPtBins, particle));
			canPtBinsH3[particle]->SaveAs(Folder + Form("/Plots/H3/HQU/%02dBinsH3%02d.png", nPtBins, particle));
			canPtBinsH3[particle]->SaveAs(Folder + Form("/Plots/H3/HQU/%02dBinsH3%02d.root", nPtBins, particle));	
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
			legendtof[particle][pt] = new TLegend(0.532765,0.586242,0.922674,0.905549);
			legendtof[particle][pt]->SetEntrySeparation(.4);
			legendtof[particle][pt]->SetFillStyle(0);
			legendtof[particle][pt]->SetTextFont(42);
			legendtof[particle][pt]->SetTextSize(0.042);
			histTOFfit[particle][pt]->SetLineWidth(5);
			canTOF[particle][pt]->SetLeftMargin(0.15);
			canTOF[particle][pt]->SetTopMargin(0.0661157);
   			canTOF[particle][pt]->SetBottomMargin(0.133412);
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
				legendtof[particle][pt]->AddEntry((TObject*)0, Form("Particle: {}^{3}%sH", "#bar"), "");
			}
			if(particle == 2){
				legendtof[particle][pt]->AddEntry((TObject*)0, Form("Particle: {}^{3}H + {}^{3}%sH", "#bar"), "");
			}
			if(particle == 0){
				legendtof[particle][pt]->AddEntry((TObject*)0, Form("Particle: {}^{3}H"), "");
			}
			legendtof[particle][pt]->AddEntry((TObject*)0, Form("%1.2f < #frac{#it{p}_{T}}{(GeV/#it{c})} < %1.2f ",ptBins[pt], ptBins[pt+1]), "");
			if (trigger == "HM")
			{
				legendtof[particle][pt]->AddEntry((TObject*)0, "High-multiplicity trigger", "");
			}
			else if (trigger == "HNU&HQU"){
				legendtof[particle][pt]->AddEntry((TObject*)0, "TRD HNU & HQU trigger", "");
			}
			else if (trigger == "HNU"){
				legendtof[particle][pt]->AddEntry((TObject*)0, "TRD HNU trigger", "");
			}
			else if (trigger == "HQU"){
				legendtof[particle][pt]->AddEntry((TObject*)0, "TRD HQU trigger", "");
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
			if(trigger == "HM"){
				canTOF[particle][pt]->SaveAs(Folder + Form("/Plots/H3/HM/bins/H3Plot%02d%02d.pdf", particle, pt));
				canTOF[particle][pt]->SaveAs(Folder + Form("/Plots/H3/HM/bins/H3Plot%02d%02d.root", particle, pt));
				canTOF[particle][pt]->SaveAs(Folder + Form("/Plots/H3/HM/bins/H3Plot%02d%02d.C", particle, pt));
			}
			else if (trigger == "HNU&HQU"){
				canTOF[particle][pt]->SaveAs(Folder + Form("/Plots/H3/HNUHQU/bins/H3Plot%02d%02d.pdf", particle, pt));
				canTOF[particle][pt]->SaveAs(Folder + Form("/Plots/H3/HNUHQU/bins/H3Plot%02d%02d.root", particle, pt));
				canTOF[particle][pt]->SaveAs(Folder + Form("/Plots/H3/HNUHQU/bins/H3Plot%02d%02d.C", particle, pt));
			}
			else if (trigger == "HNU"){
				canTOF[particle][pt]->SaveAs(Folder + Form("/Plots/H3/HNU/bins/H3Plot%02d%02d.pdf", particle, pt));
				canTOF[particle][pt]->SaveAs(Folder + Form("/Plots/H3/HNU/bins/H3Plot%02d%02d.root", particle, pt));
				canTOF[particle][pt]->SaveAs(Folder + Form("/Plots/H3/HNU/bins/H3Plot%02d%02d.C", particle, pt));
			}
			else if (trigger == "HQU"){
				canTOF[particle][pt]->SaveAs(Folder + Form("/Plots/H3/HQU/bins/H3Plot%02d%02d.pdf", particle, pt));
				canTOF[particle][pt]->SaveAs(Folder + Form("/Plots/H3/HQU/bins/H3Plot%02d%02d.root", particle, pt));
				canTOF[particle][pt]->SaveAs(Folder + Form("/Plots/H3/HQU/bins/H3Plot%02d%02d.C", particle, pt));
			}
		}
	}
	// raw yield
	TH1D * histRaw[nParticles] = {0};
    TH1D * histRawFit[nParticles] = {0};
	for (int particle = 0; particle < nParticles; particle++){
		histRaw[particle] = (TH1D*) f->Get(Form("histRaw%02d", particle));
        histRawFit[particle] = (TH1D*) f->Get(Form("histRawFit%02d", particle));
        histRawFit[particle]->SetMarkerStyle(43);
	}
	histRaw[0]->SetMarkerStyle(4);
	histRaw[1]->SetMarkerStyle(8);
    //bin counting yield plot:
	TCanvas *canRaw = new TCanvas("rawBin", "raw yield bin counting", 1200, 1200);
    TLegend *particleLegend = legendParticle(histRaw, 2);
	canRaw->cd();
	canRaw->Update();
    plotRatio((TPad*) gROOT->GetSelectedPad(), histRaw);
    particleLegend->Draw("Same");
    //histRaw[2]->Scale(1./2.);
	//histRaw[2]->Draw("SAME");
	if (trigger == "HM"){
    	canRaw->SaveAs(Folder + Form("/Plots/H3/HM/rawYieldH3BinCounting.pdf"));
    	canRaw->SaveAs(Folder + Form("/Plots/H3/HM/rawYieldH3BinCounting.root"));
		canRaw->SaveAs(Folder + Form("/Plots/H3/HM/rawYieldH3BinCounting.C"));
	}
	else if (trigger == "HNU&HQU"){
		canRaw->SaveAs(Folder + Form("/Plots/H3/HNUHQU/rawYieldH3BinCounting.pdf"));
    	canRaw->SaveAs(Folder + Form("/Plots/H3/HNUHQU/rawYieldH3BinCounting.root"));
		canRaw->SaveAs(Folder + Form("/Plots/H3/HNUHQU/rawYieldH3BinCounting.C"));
	}
	else if (trigger == "HNU"){
		canRaw->SaveAs(Folder + Form("/Plots/H3/HNU/rawYieldH3BinCounting.pdf"));
    	canRaw->SaveAs(Folder + Form("/Plots/H3/HNU/rawYieldH3BinCounting.root"));
		canRaw->SaveAs(Folder + Form("/Plots/H3/HNU/rawYieldH3BinCounting.C"));
	}
	else if (trigger == "HQU"){
		canRaw->SaveAs(Folder + Form("/Plots/H3/HQU/rawYieldH3BinCounting.pdf"));
    	canRaw->SaveAs(Folder + Form("/Plots/H3/HQU/rawYieldH3BinCounting.root"));
		canRaw->SaveAs(Folder + Form("/Plots/H3/HQU/rawYieldH3BinCounting.C"));
	}
    canRaw->Write(0, TObject::kOverwrite);
    
    //fit function yield plot:
    TCanvas *canRawFit = new TCanvas("rawFit", "raw yield function", 1200, 1200);
    TLegend *particleLegendFit = legendParticle(histRawFit, 2);
    canRawFit->cd();
    canRawFit->Update();
    plotRatio((TPad*) gROOT->GetSelectedPad(), histRawFit);
    particleLegendFit->Draw("SAME");
    //histRawFit[2]->Scale(1./2.);
	//histRawFit[2]->Draw("SAME");
	if (trigger == "HM"){
		canRawFit->SaveAs(Folder + Form("/Plots/H3/HM/rawYieldH3FitFunc.pdf"));
    	canRawFit->SaveAs(Folder + Form("/Plots/H3/HM/rawYieldH3FitFunc.root"));
	}
   else if (trigger == "HNU&HQU"){
		canRawFit->SaveAs(Folder + Form("/Plots/H3/HNUHQU/rawYieldH3FitFunc.pdf"));
    	canRawFit->SaveAs(Folder + Form("/Plots/H3/HNUHQU/rawYieldH3FitFunc.root"));
	}
	else if (trigger == "HNU"){
		canRawFit->SaveAs(Folder + Form("/Plots/H3/HNU/rawYieldH3FitFunc.pdf"));
    	canRawFit->SaveAs(Folder + Form("/Plots/H3/HNU/rawYieldH3FitFunc.root"));
	}
	else if (trigger == "HQU"){
		canRawFit->SaveAs(Folder + Form("/Plots/H3/HQU/rawYieldH3FitFunc.pdf"));
    	canRawFit->SaveAs(Folder + Form("/Plots/H3/HQU/rawYieldH3FitFunc.root"));
	}
    canRawFit->Write(0, TObject::kOverwrite);

    //combined yield plot
   	//TCanvas *canRawCombined = new TCanvas("raw yield Combined", "raw yield", 1200,1200);
    //THStack *hs = new THStack("hs","raw yield");
    //TLegend *legend = new TLegend(0.1,0.7,0.48,0.9); 
    //for (int particle = 0; particle < nParticles; particle++){
		//hs->Add(histRaw[particle]);
        //legend->AddEntry(histRaw[particle],"Bin counting","l");
        //hs->Add(histRawFit[particle]);
        //legend->AddEntry(histRawFit[particle],"Fit","l");
	//}
    //legend->Draw();
    //hs->Draw();
    //canRawCombined->SaveAs(Folder + Form("/Plots/H3/HM/rawYieldH3Comb.pdf"));
    //canRawCombined->Write(0, TObject::kOverwrite);

	f->Close();

}
//___________________________________________________________________________
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
	//THStack *hs = new THStack("hs" + (TString)h[0]->GetName(),title);
	THStack *hs = new THStack("hs", " ; #it{p}_{T} (GeV/#it{c}); Counts");
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
	h3->GetYaxis()->SetTitle("{}^{3}#bar{H} / {}^{3}H");
	setYaxis(h3->GetYaxis(), dist);
	
	h3->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
	//h3->SetMaximum(h3->GetMaximum()*1.49); 
	 h3->GetYaxis()->SetNdivisions(5);
	// X axis ratio plot settings
	h3->GetXaxis()->SetTitleSize(22);
	h3->GetXaxis()->SetTitleFont(43);
	h3->GetXaxis()->SetTitleOffset(4.);
	//h3->GetXaxis()->SetLabelOffset(2.);
	h3->GetXaxis()->SetLabelFont(43); 
	h3->GetXaxis()->SetLabelSize(25);
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