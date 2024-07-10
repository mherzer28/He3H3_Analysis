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
#include "H3He3_ratioHisto.h"

const TString trigger = "HM"; //HM or HNU
TString Folder = "result";
TString rootfile = "/Users/matthias/alice/Master/Makros/Rootfiles/DataH3.root";
TString rootfileHe3 = "/Users/matthias/alice/Master/Makros/Rootfiles/DataHe3.root";
TString	rootfileYield = "/Users/matthias/alice/Master/Makros/Rootfiles/DataYield.root";
TString rootfile_HNU = "/Users/matthias/alice/Master/Makros/Rootfiles/DataH3_HNU.root";
TString rootfileHe3_HNU = "/Users/matthias/alice/Master/Makros/Rootfiles/DataHe3_HNU.root";
TString	rootfileYield_HNU = "/Users/matthias/alice/Master/Makros/Rootfiles/DataYield_HNU.root";
//Correction root files:
TString rootfileYield_corr = "/Users/matthias/alice/Master/Makros/result/correction/DataYield_corr.root";
TString rootfileYield_corr_HNU = "/Users/matthias/alice/Master/Makros/result/correction/DataYield_corr_HNU.root";
const Int_t nParticles = 3;	
double eventnumber = 6.79038e+08 + 2.98214e+08; //HM
double eventnumberHM = 1.6013576e+09 + 3.2440317e+08; // HMV0 + HMSPD
double eventnumberMB = 3.0283497e+09;
double eventnumberHNUHQU = 58430772 + 1.5739238e+08; // HNU + HQU
//____________________________________________________________________________________________
void H3He3_ratioHisto(){
    histRatio();
	histRatioCorrected();
}
//_____________________________________________________________________________________________
void histRatio(){
	TFile *fH3;
	TFile *fHe;
	TFile *fYield;
	if (trigger == "HM")
	{
		fH3 = TFile::Open(rootfile, "UPDATE");
	}
	if (trigger == "HNU")
	{
		fH3 = TFile::Open(rootfile_HNU, "UPDATE");
	}
	TH1D * yieldH3[nParticles] = {0};
    TH1D * yieldHe3[nParticles] = {0};
	TH1D * yieldCombined[nParticles] = {0};
	TH1D * yieldCombinedAnti = {0};
	TCanvas *ratioPlot[nParticles] = {0};
	TCanvas *ratioPlot_event1[nParticles] = {0};
	TCanvas *ratioPlot_event2[nParticles] = {0};
	TLegend *legendratio[nParticles] = {0};
	TH1D * yieldCombinedPerEventH3_uncorrected[nParticles] = {0};
	TH1D * yieldCombinedPerEventHe3_uncorrected[nParticles] = {0};
	TLegend *legendratioH3_uncorrected[nParticles] = {0};
	TLegend *legendratioHe3_uncorrected[nParticles] = {0};
	TLine * l[nParticles] = {0};
	for (int particle = 0; particle < nParticles; particle++){
		yieldH3[particle] = (TH1D*) fH3->Get(Form("histRaw%02d", particle));
		yieldH3[particle]->SetName(Form("histYieldH3%02d",particle));
		yieldCombined[particle] = (TH1D*)yieldH3[particle]->Clone("histratio");
		yieldCombined[particle]->SetName(Form("histRatio%02d",particle));
	}
	if (trigger == "HM")
	{
		fHe = TFile::Open(rootfileHe3, "UPDATE");
	}
	if (trigger == "HNU")
	{
		fHe = TFile::Open(rootfileHe3_HNU, "UPDATE");
	}
	for (int particle = 0; particle < nParticles; particle++){
        yieldHe3[particle] = (TH1D*) fHe->Get(Form("histRaw%02d%02d",0, particle));
		yieldHe3[particle]->SetName(Form("histYieldHe3%02d",particle));
	}
	if (trigger == "HM")
	{
		fYield = new TFile(rootfileYield,"recreate");
	}
	if (trigger == "HNU")
	{
		fYield = new TFile(rootfileYield_HNU,"recreate");
	}	
	for (int particle = 0; particle < nParticles; particle++){
		yieldH3[particle]->SetMarkerStyle(42);
		yieldHe3[particle]->SetMarkerStyle(43);
		yieldH3[particle]->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c}");
		yieldHe3[particle]->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c}");
		yieldCombined[particle]->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
		yieldCombined[particle]->Divide(yieldHe3[particle]);
		yieldCombined[particle]->GetYaxis()->SetRangeUser(0.,2.);
	}
	yieldCombined[0]->SetMarkerStyle(8);
	yieldCombined[1]->SetMarkerStyle(8);
	yieldH3[0]->SetLineColor(kRed);
	yieldHe3[0]->SetLineColor(kRed);
	yieldCombined[0]->SetLineColor(kRed);
	yieldH3[1]->SetLineColor(kBlue);
	yieldHe3[1]->SetLineColor(kBlue);
	yieldCombined[1]->SetLineColor(kBlue);
	yieldCombined[0]->GetYaxis()->SetTitle("#frac{{}^{3}H}{{}^{3}He}");
	yieldCombined[2]->GetYaxis()->SetTitle("#frac{{}^{3}H}{{}^{3}He}");
	yieldCombined[1]->GetYaxis()->SetTitle("#frac{{}^{3}#bar{H}}{{}^{3}#bar{He}}");
	yieldCombined[2]->SetLineColor(kMagenta+2);
	yieldCombined[0]->SetLineColor(kBlue);
	yieldCombined[1]->SetLineColor(kRed);
	for (int particle = 0; particle < 2; particle++){
		yieldCombined[particle]->Write(0, TObject::kOverwrite);
		yieldHe3[particle]->Write(0, TObject::kOverwrite);	
		yieldH3[particle]->Write(0, TObject::kOverwrite);
	}
	for (int particle = 0; particle < nParticles; particle++){
		ratioPlot[particle] = new TCanvas(Form("ratioPlot%i", particle), "", 2000,2000);
		ratioPlot[particle]->cd();
		yieldCombined[particle]->SetTitle(" ");
		yieldCombined[particle]->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
		yieldCombined[particle]->SetMarkerStyle(8);
		//yieldCombined[2]->SetTitleSize(22);
		yieldCombined[particle]->SetStats(0);
		//ratioStack->Draw();
		yieldCombined[particle]->Draw();
		if (trigger == "HM")
		{
			l[particle] = new TLine(1.4,1.,2.6,1.);
		}
		if (trigger == "HNU")
		{
			l[particle] = new TLine(1.3,1.,2.8,1.);
		}
		l[particle]->SetLineColor(kGray+2);
		l[particle]->SetLineStyle(3);
		l[particle]->SetLineWidth(3);
		l[particle]->Draw();
		legendratio[particle] = new TLegend(0.1,0.7,0.48,0.9);
		legendratio[particle]->SetEntrySeparation(.4);
		legendratio[particle]->SetBorderSize(0);
		legendratio[particle]->AddEntry((TObject*)0, "This work", "");
		legendratio[particle]->AddEntry((TObject*)0, "ALICE pp #sqrt{s} = 13 TeV", "");
		if (trigger == "HM")
		{
			legendratio[particle]->AddEntry((TObject*)0, "High-multiplicity trigger", "");
		}
		if (trigger == "HNU")
		{
			legendratio[particle]->AddEntry((TObject*)0, "TRD trigger", "");
		}
		legendratio[particle]->Draw();
		}
		if (trigger == "HM")
		{
			ratioPlot[2]->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HM/ratioHe3H3.pdf");
			ratioPlot[2]->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HM/ratioHe3H3.root");
			ratioPlot[2]->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HM/ratioHe3H3.C");
			ratioPlot[1]->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HM/ratioAntiHe3H3.pdf");
			ratioPlot[1]->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HM/ratioAntiHe3H3.root");
			ratioPlot[1]->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HM/ratioAntiHe3H3.C");
			ratioPlot[0]->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HM/ratioNorHe3H3.pdf");
			ratioPlot[0]->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HM/ratioNorHe3H3.root");
			ratioPlot[0]->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HM/ratioNorHe3H3.C");
		}
		if (trigger == "HNU")
		{
			ratioPlot[2]->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNU/ratioHe3H3.pdf");
			ratioPlot[2]->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNU/ratioHe3H3.root");
			ratioPlot[2]->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNU/ratioHe3H3.C");
			ratioPlot[1]->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNU/ratioAntiHe3H3.pdf");
			ratioPlot[1]->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNU/ratioAntiHe3H3.root");
			ratioPlot[1]->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNU/ratioAntiHe3H3.C");
			ratioPlot[0]->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNU/ratioNorHe3H3.pdf");
			ratioPlot[0]->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNU/ratioNorHe3H3.root");
			ratioPlot[0]->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNU/ratioNorHe3H3.C");
	}
	//Per Event:
	for (int i = 0; i < nParticles; i++)
	{
		yieldCombinedPerEventH3_uncorrected[i] = (TH1D*)yieldH3[i]->Clone(Form("yieldCombinedPerEventH3_uncorrected%i", i));
		if (trigger == "HM")
		{
			yieldCombinedPerEventH3_uncorrected[i]->Scale(1./eventnumber);
		}
		if (trigger == "HNU")
		{
			yieldCombinedPerEventH3_uncorrected[i]->Scale(1./eventnumberMB);
		}
		ratioPlot_event1[i] = new TCanvas(Form("ratioPlot_event1%i",i), "", 2000,2000);
		yieldCombinedPerEventH3_uncorrected[i]->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
		yieldCombinedPerEventH3_uncorrected[i]->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
		yieldCombinedPerEventH3_uncorrected[i]->SetStats(0);
		yieldCombinedPerEventH3_uncorrected[i]->SetMarkerStyle(8);
		yieldCombinedPerEventH3_uncorrected[i]->SetMarkerSize(1.5);		
		yieldCombinedPerEventH3_uncorrected[i]->SetMarkerSize(1.5);
		yieldCombinedPerEventH3_uncorrected[i]->SetLineWidth(2);
	    if (i == 0) {
            yieldCombinedPerEventH3_uncorrected[i]->SetMarkerColor(kBlue);
            yieldCombinedPerEventH3_uncorrected[i]->SetLineColor(kBlue);
        } 
		else if (i == 1) {
            yieldCombinedPerEventH3_uncorrected[i]->SetMarkerColor(kRed);
            yieldCombinedPerEventH3_uncorrected[i]->SetLineColor(kRed);
        } 
		else if (i == 2) {
            yieldCombinedPerEventH3_uncorrected[i]->SetMarkerColor(kMagenta+2);
            yieldCombinedPerEventH3_uncorrected[i]->SetLineColor(kMagenta+2);
        }
		gPad->SetLogy();
		yieldCombinedPerEventH3_uncorrected[i]->Draw();
		legendratioH3_uncorrected[i] = new TLegend(0.570932,0.27129,0.94089,0.470803,NULL,"brNDC");
		legendratioH3_uncorrected[i]->SetEntrySeparation(.4);
		legendratioH3_uncorrected[i]->SetBorderSize(0);
		legendratioH3_uncorrected[i]->SetFillStyle(0);
		//legendratioH3_uncorrected[i]->AddEntry(yieldCombined[2], "#frac{{}^{3}H}{{}^{3}He}", "lep");
		legendratioH3_uncorrected[i]->AddEntry((TObject*)0, "Uncorrected", "");
		legendratioH3_uncorrected[i]->AddEntry((TObject*)0, "ALICE pp #sqrt{s} = 13 TeV, |y| < 0.5", "");
		legendratioH3_uncorrected[i]->AddEntry((TObject*)0, "Particle: {}^{3}H", "");
		if (trigger == "HM")
		{
			legendratioH3_uncorrected[i]->AddEntry((TObject*)0, "High Multiplicity trigger", "");
		}
		if (trigger == "HNU")
		{
			legendratioH3_uncorrected[i]->AddEntry((TObject*)0, "TRD trigger", "");
		}
		//yieldCombinedPerEvent->GetXaxis()->SetRange(1.,6.);
		legendratioH3_uncorrected[i]->Draw();
		if (trigger == "HM")
		{	
			ratioPlot_event1[i]->SaveAs(Form("/Users/matthias/alice/Master/Makros/result/Plots/H3/HM/H3perEvent%i.C",i));
			ratioPlot_event1[i]->SaveAs(Form("/Users/matthias/alice/Master/Makros/result/Plots/H3/HM/H3perEvent%i.pdf",i));
			ratioPlot_event1[i]->SaveAs(Form("/Users/matthias/alice/Master/Makros/result/Plots/H3/HM/H3perEvent%i.root",i));
		}
		if (trigger == "HNU")
		{	
			ratioPlot_event1[i]->SaveAs(Form("/Users/matthias/alice/Master/Makros/result/Plots/H3/HNU/H3perEvent%i.C", i));
			ratioPlot_event1[i]->SaveAs(Form("/Users/matthias/alice/Master/Makros/result/Plots/H3/HNU/H3perEvent%i.pdf", i));
			ratioPlot_event1[i]->SaveAs(Form("/Users/matthias/alice/Master/Makros/result/Plots/H3/HNU/H3perEvent%i.root", i));
		}
	}
	TCanvas* combinedCanvasH3 = new TCanvas("combinedCanvasH3", "", 2000, 2000);
	yieldCombinedPerEventH3_uncorrected[0]->Draw();
	yieldCombinedPerEventH3_uncorrected[1]->Draw("same");
	TLegend* combinedLegendH3 = new TLegend(0.5, 0.75, 0.9, 0.9);
	combinedLegendH3->SetEntrySeparation(.4);
	combinedLegendH3->SetBorderSize(0);
	combinedLegendH3->SetFillStyle(0);
	combinedLegendH3->AddEntry(yieldCombinedPerEventH3_uncorrected[0], "{}^{3}He", "lep");
	combinedLegendH3->AddEntry(yieldCombinedPerEventH3_uncorrected[1], "{}^{3}#bar{He}", "lep");
	combinedLegendH3->Draw();
	if (trigger == "HM")
	{
		combinedCanvasH3->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/He3/HM/He3perEvent_UC_combined.pdf");
		combinedCanvasH3->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/He3/HM/He3perEvent_UC_combined.C");
		combinedCanvasH3->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/He3/HM/He3perEvent_UC_combined.root");
	}
	if (trigger == "HNU")
	{
		combinedCanvasH3->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/He3/HNU/He3perEvent_UC_combined.pdf");
		combinedCanvasH3->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/He3/HNU/He3perEvent_UC_combined.C");
		combinedCanvasH3->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/He3/HNU/He3perEvent_UC_combined.root");
	}
	for (int i = 0; i < nParticles; i++)
	{
		yieldCombinedPerEventHe3_uncorrected[i] = (TH1D*)yieldHe3[i]->Clone(Form("yieldCombinedPerEventHe3_uncorrected%i", i));
		if (trigger == "HM")
		{
			yieldCombinedPerEventHe3_uncorrected[i]->Scale(1./eventnumber);
		}
		if (trigger == "HNU")
		{
			yieldCombinedPerEventHe3_uncorrected[i]->Scale(1./eventnumberMB);
		}

		ratioPlot_event2[i] = new TCanvas(Form("ratioPlot_event2%i", i), "", 2000,2000);
		yieldCombinedPerEventHe3_uncorrected[i]->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
		yieldCombinedPerEventHe3_uncorrected[i]->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
		yieldCombinedPerEventHe3_uncorrected[i]->SetStats(0);
		yieldCombinedPerEventHe3_uncorrected[i]->SetMarkerStyle(8);
		yieldCombinedPerEventHe3_uncorrected[i]->SetMarkerSize(1.5);
		yieldCombinedPerEventHe3_uncorrected[i]->SetMarkerSize(1.5);
		yieldCombinedPerEventHe3_uncorrected[i]->SetLineWidth(2);
		if (i == 0) {
            yieldCombinedPerEventHe3_uncorrected[i]->SetMarkerColor(kBlue);
            yieldCombinedPerEventHe3_uncorrected[i]->SetLineColor(kBlue);
        } 
		else if (i == 1) {
            yieldCombinedPerEventHe3_uncorrected[i]->SetMarkerColor(kRed);
            yieldCombinedPerEventHe3_uncorrected[i]->SetLineColor(kRed);
        } 
		else if (i == 2) {
            yieldCombinedPerEventHe3_uncorrected[i]->SetMarkerColor(kMagenta+2);
            yieldCombinedPerEventHe3_uncorrected[i]->SetLineColor(kMagenta+2);
        }
		gPad->SetLogy();
		yieldCombinedPerEventHe3_uncorrected[i]->Draw();
		legendratioHe3_uncorrected[i] = new TLegend(0.5344418,0.6865854,0.9041964,0.8865854,NULL,"brNDC");
		legendratioHe3_uncorrected[i]->SetEntrySeparation(.4);
		legendratioHe3_uncorrected[i]->SetBorderSize(0);
		legendratioHe3_uncorrected[i]->SetFillStyle(0);
		//legendratioHe3_uncorrected->AddEntry(yieldCombined[2], "#frac{{}^{3}H}{{}^{3}He}", "lep");
		legendratioHe3_uncorrected[i]->AddEntry((TObject*)0, "Uncorrected", "");
		legendratioHe3_uncorrected[i]->AddEntry((TObject*)0, "ALICE pp #sqrt{s} = 13 TeV, |y| < 0.5", "");
		legendratioHe3_uncorrected[i]->AddEntry((TObject*)0, "Particle: {}^{3}He", "");
		if (trigger == "HM")
		{
			legendratioHe3_uncorrected[i]->AddEntry((TObject*)0, "High Multiplicity trigger", "");
		}
		if (trigger == "HNU")
		{
			legendratioHe3_uncorrected[i]->AddEntry((TObject*)0, "TRD trigger", "");
		}
		//yieldCombinedPerEvent->GetXaxis()->SetRange(1.,6.);
		legendratioHe3_uncorrected[i]->Draw();
		if (trigger == "HM")
		{
			ratioPlot_event2[i]->SaveAs(Form("/Users/matthias/alice/Master/Makros/result/Plots/He3/HM/He3perEvent_UC%i.C", i));
			ratioPlot_event2[i]->SaveAs(Form("/Users/matthias/alice/Master/Makros/result/Plots/He3/HM/He3perEvent_UC%i.pdf", i));
			ratioPlot_event2[i]->SaveAs(Form("/Users/matthias/alice/Master/Makros/result/Plots/He3/HM/He3perEvent_UC%i.root", i));
		}
		if (trigger == "HNU")
		{
			ratioPlot_event2[i]->SaveAs(Form("/Users/matthias/alice/Master/Makros/result/Plots/He3/HNU/He3perEvent_UC%i.C", i));
			ratioPlot_event2[i]->SaveAs(Form("/Users/matthias/alice/Master/Makros/result/Plots/He3/HNU/He3perEvent_UC%i.pdf", i));
			ratioPlot_event2[i]->SaveAs(Form("/Users/matthias/alice/Master/Makros/result/Plots/He3/HNU/He3perEvent_UC%i.root", i));;
		}
	}
	TCanvas* combinedCanvas = new TCanvas("combinedCanvas", "", 2000, 2000);
	yieldCombinedPerEventHe3_uncorrected[0]->Draw();
	yieldCombinedPerEventHe3_uncorrected[1]->Draw("same");
	TLegend* combinedLegend = new TLegend(0.5, 0.75, 0.9, 0.9);
	combinedLegend->SetEntrySeparation(.4);
	combinedLegend->SetBorderSize(0);
	combinedLegend->SetFillStyle(0);
	combinedLegend->AddEntry(yieldCombinedPerEventHe3_uncorrected[0], "{}^{3}He", "lep");
	combinedLegend->AddEntry(yieldCombinedPerEventHe3_uncorrected[1], "{}^{3}#bar{He}", "lep");
	combinedLegend->Draw();
	if (trigger == "HM")
	{
		combinedCanvas->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/H3/HM/He3perEvent_UC_combined.pdf");
		combinedCanvas->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/H3/HM/He3perEvent_UC_combined.C");
		combinedCanvas->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/H3/HM/He3perEvent_UC_combined.root");
	}
	if (trigger == "HNU")
	{
		combinedCanvas->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/H3/HNU/He3perEvent_UC_combined.pdf");
		combinedCanvas->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/H3/HNU/He3perEvent_UC_combined.C");
		combinedCanvas->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/H3/HNU/He3perEvent_UC_combined.root");
	}
}
void histRatioCorrected(){
	TFile *fH3_corr;
	TFile *fYield_corr;
	TLine *l2;
	TLine *l3; 
	if (trigger == "HM")
	{
		fH3_corr = TFile::Open("/Users/matthias/alice/Master/Makros/result/correction/correctionresult.root", "UPDATE");
	}
	if (trigger == "HNU")
	{
		fH3_corr = TFile::Open("/Users/matthias/alice/Master/Makros/result/correction/correctionresult_HNU.root", "UPDATE");
	}
	TH1D * yieldH3[nParticles] = {0};
    TH1D * yieldHe3[nParticles] = {0};
	TH1D * yieldCombined[nParticles] = {0};
	TH1D * yieldCombinedAnti = {0};
	TH1D * yieldCombinedPerEvent[nParticles] = {0};
	TH1D * yieldCombinedPerEventHe[nParticles] = {0};
	TLegend *legendratioH3[nParticles] = {0};
	TLegend *legendratioHe3[nParticles] = {0};
	TLegend *legendratio4[nParticles] = {0};
	TLegend *legendratio5[nParticles] = {0};
	TCanvas *ratioPlot = {0};
	TCanvas *ratioPlot22 = {0};
	TCanvas *ratioPlot3 = {0};
	TCanvas *ratioPlot_event_corr1[nParticles] = {0};
	TCanvas *ratioPlot5[nParticles] = {0};
	TGraphErrors* compare_graph = {0};
	ratioPlot = new TCanvas("ratioPlot", "", 2000,2000);
	THStack *ratioStack = new THStack("ratioStack", " ; #it{p}_{T} (GeV/#it{c}); #frac{{}^{3}H}{{}^{3}He}");
	for (int particle = 0; particle < nParticles; particle++){
		yieldH3[particle] = (TH1D*) fH3_corr->Get(Form("hCorr%d", particle));
		yieldH3[particle]->SetName(Form("histYieldH3%02d",particle));
		yieldCombined[particle] = (TH1D*)yieldH3[particle]->Clone("histratio");
		yieldCombined[particle]->SetName(Form("histRatio%02d",particle));
	}
	
	for (int particle = 0; particle < nParticles; particle++){
        yieldHe3[particle] = (TH1D*) fH3_corr->Get(Form("hCorrHe%d", particle));
		yieldHe3[particle]->SetName(Form("histYieldHe3%02d",particle));
	}
	if (trigger == "HM")
	{
		fYield_corr = new TFile(rootfileYield_corr,"recreate");
	}
	if (trigger == "HNU")
	{
		fYield_corr = new TFile(rootfileYield_corr_HNU,"recreate");
	}
	
	for (int particle = 0; particle < nParticles; particle++){
		yieldH3[particle]->SetMarkerStyle(42);
		yieldHe3[particle]->SetMarkerStyle(43);
		yieldH3[particle]->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c}");
		yieldHe3[particle]->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c}");
		yieldCombined[particle]->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
		yieldCombined[particle]->Divide(yieldHe3[particle]);
		yieldCombined[particle]->GetYaxis()->SetRangeUser(0.,2.);
	}
	yieldCombined[0]->SetMarkerStyle(42);
	yieldCombined[1]->SetMarkerStyle(43);
	yieldH3[0]->SetLineColor(kRed);
	yieldHe3[0]->SetLineColor(kRed);
	yieldCombined[0]->SetLineColor(kRed);
	yieldH3[1]->SetLineColor(kBlue);
	yieldHe3[1]->SetLineColor(kBlue);
	yieldCombined[1]->SetLineColor(kBlue);
	ratioPlot->cd();
	for (int particle = 0; particle < 2; particle++){
	yieldCombined[particle]->Write(0, TObject::kOverwrite);
	yieldHe3[particle]->Write(0, TObject::kOverwrite);	
	yieldH3[particle]->Write(0, TObject::kOverwrite);
	ratioStack->Add(yieldCombined[particle]);	
	}
	yieldHe3[2]->Write(0, TObject::kOverwrite);	
	yieldH3[2]->Write(0, TObject::kOverwrite);
	yieldCombined[2]->SetTitle(" ");
	yieldCombined[2]->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
	yieldCombined[2]->GetYaxis()->SetTitle("#frac{{}^{3}H}{{}^{3}He}");
	yieldCombined[2]->SetMarkerStyle(8);
	yieldCombined[2]->SetLineColor(kMagenta+2);
	//yieldCombined[2]->SetTitleSize(22);
	yieldCombined[2]->SetStats(0);
	//ratioStack->Draw();
	yieldCombined[2]->Draw();
	yieldCombined[2]->Write(0, TObject::kOverwrite);
	TLine *l = new TLine(1.4,1.,2.6,1.);
	l->SetLineColor(kGray+2);
	l->SetLineStyle(3);
	l->SetLineWidth(1);
	l->Draw();
	TLegend *legendratio = new TLegend(0.0748175,0.672544,0.444343,0.871537,NULL,"brNDC");
	legendratio->SetEntrySeparation(.4);
	legendratio->SetBorderSize(0);
	legendratio->SetFillStyle(0);
	//legendratio->AddEntry(yieldCombined[2], "#frac{{}^{3}H}{{}^{3}He}", "lep");
	legendratio->AddEntry((TObject*)0, "Corrected", "");
	legendratio->AddEntry((TObject*)0, "ALICE pp #sqrt{s} = 13 TeV", "");
	if (trigger == "HM")
	{
		legendratio->AddEntry((TObject*)0, "High-multiplicity trigger", "");
	}
	if (trigger == "HNU")
	{
		legendratio->AddEntry((TObject*)0, "TRD trigger", "");
	}
	legendratio->Draw();
	if (trigger == "HM")
	{
		ratioPlot->SaveAs(Folder + Form("/Plots/ratio/HM/corrRatioHe3H3.png"));
		ratioPlot->SaveAs(Folder + Form("/Plots/ratio/HM/corrRatioHe3H3.root"));
		ratioPlot->SaveAs(Folder + Form("/Plots/ratio/HM/corrRatioHe3H3.C"));
	}
	if (trigger == "HNU")
	{
		ratioPlot->SaveAs(Folder + Form("/Plots/ratio/HNU/corrRatioHe3H3_HNU.png"));
		ratioPlot->SaveAs(Folder + Form("/Plots/ratio/HNU/corrRatioHe3H3_HNU.root"));
		ratioPlot->SaveAs(Folder + Form("/Plots/ratio/HNU/corrRatioHe3H3_HNU.C"));
	}
	
	ratioPlot22 = new TCanvas(Form("ratioPlot22"), "", 2000,2000);
	yieldCombined[0]->SetTitle(" ");
	yieldCombined[0]->SetStats(0);
	yieldCombined[0]->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
	yieldCombined[0]->GetYaxis()->SetTitle("#frac{{}^{3}H}{{}^{3}He}");
	yieldCombined[0]->SetMarkerStyle(8);
	yieldCombined[0]->Draw();
	if (trigger == "HM")
	{
		l2 = new TLine(1.4,1.,2.6,1.);
	}
	if (trigger == "HNU")
	{
		l2 = new TLine(1.3,1.,2.8,1.);
	}
	l2->SetLineColor(kGray+2);
	l2->SetLineStyle(3);
	l2->SetLineWidth(3);
	l2->Draw();
	TLegend *legendratio2 = new TLegend(0.0748175,0.672544,0.444343,0.871537,NULL,"brNDC");
	legendratio2->SetEntrySeparation(.4);
	legendratio2->SetBorderSize(0);
	legendratio2->SetFillStyle(0);
	//legendrat2io->AddEntry(yieldCombined[2], "#frac{{}^{3}H}{{}^{3}He}", "lep");
	legendratio2->AddEntry((TObject*)0, "Corrected", "");
	legendratio2->AddEntry((TObject*)0, "ALICE pp #sqrt{s} = 13 TeV", "");
	if (trigger == "HM")
	{
		legendratio2->AddEntry((TObject*)0, "High Multiplicity trigger", "");
	}
	if (trigger == "HNU")
	{
		legendratio2->AddEntry((TObject*)0, "TRD trigger", "");
	}
	
	legendratio2->Draw();
	if (trigger == "HM")
	{
		ratioPlot22->SaveAs(Folder + Form("/Plots/ratio/HM/corrRatioPartHe3H3.png"));
		ratioPlot22->SaveAs(Folder + Form("/Plots/ratio/HM/corrRatioPartHe3H3.root"));
		ratioPlot22->SaveAs(Folder + Form("/Plots/ratio/HM/corrRatioPartHe3H3.C"));
	}
	if (trigger == "HNU")
	{
		ratioPlot22->SaveAs(Folder + Form("/Plots/ratio/HNU/corrRatioPartHe3H3_HNU.png"));
		ratioPlot22->SaveAs(Folder + Form("/Plots/ratio/HNU/corrRatioPartHe3H3_HNU.root"));
		ratioPlot22->SaveAs(Folder + Form("/Plots/ratio/HNU/corrRatioPartHe3H3_HNU.C"));
	}
	
	ratioPlot3 = new TCanvas("ratioPlot3", "", 2000,2000);
	yieldCombined[1]->SetTitle(" ");
	yieldCombined[1]->SetStats(0);
	yieldCombined[1]->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
	yieldCombined[1]->GetYaxis()->SetTitle("#frac{{}^{3}#bar{H}}{{}^{3}#bar{He}}");
	yieldCombined[1]->SetMarkerStyle(8);
	yieldCombined[1]->Draw();
	if (trigger == "HM")
	{
		l3 = new TLine(1.4,1.,2.6,1.);
	}
	if (trigger == "HNU")
	{
		l3 = new TLine(1.3,1.,2.8,1.);
	}
	l3->SetLineColor(kGray+2);
	l3->SetLineStyle(3);
	l3->SetLineWidth(1);
	l3->Draw();
	TLegend *legendratio3 = new TLegend(0.0748175,0.672544,0.444343,0.871537,NULL,"brNDC");
	legendratio3->SetEntrySeparation(.4);
	legendratio3->SetBorderSize(0);
	legendratio3->SetFillStyle(0);
	//legendrat3io->AddEntry(yieldCombined[2], "#frac{{}^{3}H}{{}^{3}He}", "lep");
	legendratio3->AddEntry((TObject*)0, "Corrected", "");
	legendratio3->AddEntry((TObject*)0, "ALICE pp #sqrt{s} = 13 TeV", "");
	if (trigger == "HM")
	{
		legendratio3->AddEntry((TObject*)0, "High-multiplicity trigger", "");
	}
	if (trigger == "HNU")
	{
		legendratio3->AddEntry((TObject*)0, "TRD trigger", "");
	}
	

	legendratio3->Draw();
	if (trigger == "HM")
	{
		ratioPlot3->SaveAs(Folder + Form("/Plots/ratio/HM/corrRatioAntiPartHe3H3.png"));
		ratioPlot3->SaveAs(Folder + Form("/Plots/ratio/HM/corrRatioAntiPartHe3H3.root"));
		ratioPlot3->SaveAs(Folder + Form("/Plots/ratio/HM/corrRatioAntiPartHe3H3.C"));
	}
	if (trigger == "HNU")
	{
		ratioPlot3->SaveAs(Folder + Form("/Plots/ratio/HNU/corrRatioAntiPartHe3H3_HNU.png"));
		ratioPlot3->SaveAs(Folder + Form("/Plots/ratio/HNU/corrRatioAntiPartHe3H3_HNU.root"));
		ratioPlot3->SaveAs(Folder + Form("/Plots/ratio/HNU/corrRatioAntiPartHe3H3_HNU.C"));
	}
	//Per Event:
	for (int i = 0; i < nParticles; i++)
	{
		yieldCombinedPerEvent[i] = (TH1D*)yieldH3[i]->Clone(Form("yieldCombinedPerEvent%i", i));
		if (trigger == "HM")
		{
			yieldCombinedPerEvent[i]->Scale(1./eventnumberHM);	
		}
		if (trigger == "HNU")
		{
			yieldCombinedPerEvent[i]->Scale(1./eventnumberMB);	
		}
		ratioPlot_event_corr1[i] = new TCanvas(Form("ratioPlot_event_corr1%i",i), "", 2000,2000);
		yieldCombinedPerEvent[i]->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
		yieldCombinedPerEvent[i]->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
		yieldCombinedPerEvent[i]->SetStats(0);
		yieldCombinedPerEvent[i]->SetMarkerStyle(8);
		yieldCombinedPerEvent[i]->SetMarkerColor(kMagenta+2);
		yieldCombinedPerEvent[i]->SetLineColor(kMagenta+2);
		yieldCombinedPerEvent[i]->SetMarkerSize(1.5);
		yieldCombinedPerEvent[i]->SetLineWidth(2);
		gPad->SetLogy();
		if (i == 0) {
            yieldCombinedPerEvent[i]->SetMarkerColor(kBlue);
            yieldCombinedPerEvent[i]->SetLineColor(kBlue);
        } 
		else if (i == 1) {
            yieldCombinedPerEvent[i]->SetMarkerColor(kRed);
            yieldCombinedPerEvent[i]->SetLineColor(kRed);
        } 
		else if (i == 2) {
            yieldCombinedPerEvent[i]->SetMarkerColor(kMagenta+2);
            yieldCombinedPerEvent[i]->SetLineColor(kMagenta+2);
        }
		yieldCombinedPerEvent[i]->Draw();
		legendratio4[i] = new TLegend(0.5344418,0.6865854,0.9041964,0.8865854,NULL,"brNDC");
		legendratio4[i]->SetEntrySeparation(.4);
		legendratio4[i]->SetBorderSize(0);
		legendratio4[i]->SetFillStyle(0);
		//legendrat4[i]->AddEntry(yieldCombined[2], "#frac{{}^{3}H}{{}^{3}He}", "lep");
		legendratio4[i]->AddEntry((TObject*)0, "Corrected", "");
		legendratio4[i]->AddEntry((TObject*)0, "ALICE pp #sqrt{s} = 13 TeV, |y| < 0.5", "");
		legendratio4[i]->AddEntry((TObject*)0, "Particle: {}^{3}H", "");
		if (trigger == "HM")
		{
			legendratio4[i]->AddEntry((TObject*)0, "High Multiplicity trigger", "");
		}
		if (trigger == "HNU")
		{
			legendratio4[i]->AddEntry((TObject*)0, "TRD trigger", "");
		}
		legendratio4[i]->Draw();
		if (trigger == "HM")
		{
			ratioPlot_event_corr1[i]->SaveAs(Folder + Form("/Plots/H3/Korrekturen/HM/H3perEvent%i.C", i));
			ratioPlot_event_corr1[i]->SaveAs(Folder + Form("/Plots/H3/Korrekturen/HM/H3perEvent%i.pdf",i));
			ratioPlot_event_corr1[i]->SaveAs(Folder + Form("/Plots/H3/Korrekturen/HM/H3perEvent%i.root",i));
		}
		if (trigger == "HNU")
		{
			ratioPlot_event_corr1[i]->SaveAs(Folder + Form("/Plots/H3/Korrekturen/HNU/H3perEvent_HNU%i.C",i));
			ratioPlot_event_corr1[i]->SaveAs(Folder + Form("/Plots/H3/Korrekturen/HNU/H3perEvent_HNU%i.pdf",i));
			ratioPlot_event_corr1[i]->SaveAs(Folder + Form("/Plots/H3/Korrekturen/HNU/H3perEvent_HNU%i.root",i));
		}
	}
	TCanvas* combinedCanvascorrH3 = new TCanvas("combinedCanvasCorrH3", "", 2000, 2000);
	yieldCombinedPerEvent[0]->Draw();
	yieldCombinedPerEvent[1]->Draw("same");
	TLegend* combinedLegendcorrH3 = new TLegend(0.5, 0.75, 0.9, 0.9);
	combinedLegendcorrH3->SetEntrySeparation(.4);
	combinedLegendcorrH3->SetBorderSize(0);
	combinedLegendcorrH3->SetFillStyle(0);
	combinedLegendcorrH3->AddEntry(yieldCombinedPerEvent[0], "{}^{3}H", "lep");
	combinedLegendcorrH3->AddEntry(yieldCombinedPerEvent[1], "{}^{3}#bar{H}", "lep");
	combinedLegendcorrH3->Draw();
	if (trigger == "HM")
	{
		combinedCanvascorrH3->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/H3/Korrekturen/HM/H3perEvent_corr_combined.pdf");
		combinedCanvascorrH3->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/H3/Korrekturen/HM/H3perEvent_corr_combined.C");
		combinedCanvascorrH3->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/H3/Korrekturen/HM/H3perEvent_corr_combined.root");
	}
	if (trigger == "HNU")
	{
		combinedCanvascorrH3->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/H3/Korrekturen/HNU/H3perEvent_corr_combined.pdf");
		combinedCanvascorrH3->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/H3/Korrekturen/HNU/H3perEvent_corr_combined.C");
		combinedCanvascorrH3->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/H3/Korrekturen/HNU/H3perEvent_corr_combined.root");
	}	
	for (int i = 0; i < nParticles; i++)
	{	
		yieldCombinedPerEventHe[i] = (TH1D*)yieldHe3[i]->Clone("yieldCombinedPerEventHe");
		if (trigger == "HM")
		{
			yieldCombinedPerEventHe[i]->Scale(1./eventnumberHM);
		}
		if (trigger == "HNU")
		{
			yieldCombinedPerEventHe[i]->Scale(1./eventnumberMB);
		}

		ratioPlot5[i] = new TCanvas(Form("ratioPlot5%i", i), "", 2000,2000);
		yieldCombinedPerEventHe[i]->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
		yieldCombinedPerEventHe[i]->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
		yieldCombinedPerEventHe[i]->SetStats(0);
		yieldCombinedPerEventHe[i]->SetMarkerStyle(8);
		yieldCombinedPerEventHe[i]->SetMarkerColor(kMagenta+2);
		yieldCombinedPerEventHe[i]->SetLineColor(kMagenta+2);
		yieldCombinedPerEventHe[i]->SetMarkerSize(1.5);
		yieldCombinedPerEventHe[i]->SetLineWidth(2);
		gPad->SetLogy();
		if (i == 0) {
            yieldCombinedPerEventHe[i]->SetMarkerColor(kBlue);
            yieldCombinedPerEventHe[i]->SetLineColor(kBlue);
        } 
		else if (i == 1) {
            yieldCombinedPerEventHe[i]->SetMarkerColor(kRed);
            yieldCombinedPerEventHe[i]->SetLineColor(kRed);
        } 
		else if (i == 2) {
            yieldCombinedPerEventHe[i]->SetMarkerColor(kMagenta+2);
            yieldCombinedPerEventHe[i]->SetLineColor(kMagenta+2);
        }
		yieldCombinedPerEventHe[i]->Draw();
		legendratio5[i] = new TLegend(0.5344418,0.6865854,0.9041964,0.8865854,NULL,"brNDC");
		legendratio5[i]->SetEntrySeparation(.4);
		legendratio5[i]->SetBorderSize(0);
		legendratio5[i]->SetFillStyle(0);
		//legendrat5io->AddEntry(yieldCombined[2], "#frac{{}^{3}H}{{}^{3}He}", "lep");
		legendratio5[i]->AddEntry((TObject*)0, "Corrected", "");
		legendratio5[i]->AddEntry((TObject*)0, "ALICE pp #sqrt{s} = 13 TeV, |y| < 0.5", "");
		legendratio5[i]->AddEntry((TObject*)0, "Particle: {}^{3}He", "");
		if (trigger == "HM")
		{
			legendratio5[i]->AddEntry((TObject*)0, "High Multiplicity trigger", "");
		}
		if (trigger == "HNU")
		{
			legendratio5[i]->AddEntry((TObject*)0, "TRD trigger", "");
		}
		yieldCombinedPerEventHe[i]->GetXaxis()->SetRange(1.,3);
		legendratio5[i]->Draw();
		if (trigger == "HM")
		{
			ratioPlot5[i]->SaveAs(Folder + Form("/Plots/He3/Korrekturen/HM/He3perEvent.C"));
			ratioPlot5[i]->SaveAs(Folder + Form("/Plots/He3/Korrekturen/HM/He3perEvent.pdf"));
			ratioPlot5[i]->SaveAs(Folder + Form("/Plots/He3/Korrekturen/HM/He3perEvent.root"));
		}
		if (trigger == "HNU")
		{
			ratioPlot5[i]->SaveAs(Folder + Form("/Plots/He3/Korrekturen/HNU/He3perEvent_HNU.C"));
			ratioPlot5[i]->SaveAs(Folder + Form("/Plots/He3/Korrekturen/HNU/He3perEvent_HNU.pdf"));
			ratioPlot5[i]->SaveAs(Folder + Form("/Plots/He3/Korrekturen/HNU/He3perEvent_HNU.root"));
		}
	}
	TCanvas* combinedCanvascorrHe = new TCanvas("combinedCanvasCorr", "", 2000, 2000);
	yieldCombinedPerEventHe[0]->Draw();
	yieldCombinedPerEventHe[1]->Draw("same");
	TLegend* combinedLegendcorrHe = new TLegend(0.5, 0.75, 0.9, 0.9);
	combinedLegendcorrHe->SetEntrySeparation(.4);
	combinedLegendcorrHe->SetBorderSize(0);
	combinedLegendcorrHe->SetFillStyle(0);
	combinedLegendcorrHe->AddEntry(yieldCombinedPerEventHe[0], "{}^{3}He", "lep");
	combinedLegendcorrHe->AddEntry(yieldCombinedPerEventHe[1], "{}^{3}#bar{He}", "lep");
	combinedLegendcorrHe->Draw();
	if (trigger == "HM")
	{
		combinedCanvascorrHe->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/He3/Korrekturen/HM/He3perEvent_corr_combined.pdf");
		combinedCanvascorrHe->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/He3/Korrekturen/HM/He3perEvent_corr_combined.C");
		combinedCanvascorrHe->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/He3/Korrekturen/HM/He3perEvent_corr_combined.root");
	}
	if (trigger == "HNU")
	{
		combinedCanvascorrHe->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/He3/Korrekturen/HNU/He3perEvent_corr_combined.pdf");
		combinedCanvascorrHe->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/He3/Korrekturen/HNU/He3perEvent_corr_combined.C");
		combinedCanvascorrHe->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/He3/Korrekturen/HNU/He3perEvent_corr_combined.root");
	}
	
	/*
	//comparison habib:
	const int n = 3;
    double x[n] = {1.25, 1.75, 2.25}; 
    double y[n] = {1.0374E-6, 1.1954E-6, 8.4629E-7};
    //double ex[n] = {1.9493E-07, 1.211E-7, 8.6239E-8}; 
	double ex[n] = {0.25, 0.25, 0.25}; 
    double ey[n] = {1.5696E-7,6.8876E-8 ,6.407E-8 }; 
	compare_graph = new TGraphErrors(n, x, y, ex, ey);
    compare_graph->SetMarkerStyle(8);  
    compare_graph->SetMarkerSize(1.5);
    compare_graph->SetLineWidth(2);
    for (int i = 0; i < n; i++) {
        compare_graph->SetPoint(i, x[i], y[i]);
        compare_graph->SetPointError(i, ex[i], ey[i]);
    }
	compare_graph->SetMarkerColor(kBlue);
    compare_graph->SetLineColor(kBlue);
	compare_graph->Draw("P SAME"); //comparison habib
	*/
}	