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

TString Folder = "result";
TString rootfile = "/Users/matthias/alice/Master/Makros/Rootfiles/DataH3.root";
TString rootfileyield = "/Users/matthias/alice/Master/Makros/Rootfiles/DataYield.root";
//____________________________________________________________________________________________
void H3He3_ratioHisto(){
    histRatio();
}
//_____________________________________________________________________________________________
void histRatio(){
	TFile *fH3 = TFile::Open(rootfile, "UPDATE");
	TH1D * yieldH3[nParticles] = {0};
    TH1D * yieldHe3[nParticles] = {0};
	TH1D * yieldCombined[nParticles] = {0};
	TH1D * yieldCombinedAnti = {0};
	TCanvas *ratioPlot[nParticles] = {0};
	TLegend *legendratio[nParticles] = {0};
	TLine * l[nParticles] = {0};
	for (int particle = 0; particle < nParticles; particle++){
		yieldH3[particle] = (TH1D*) fH3->Get(Form("histRaw%02d", particle));
		yieldH3[particle]->SetName(Form("histYieldH3%02d",particle));
		yieldCombined[particle] = (TH1D*)yieldH3[particle]->Clone("histratio");
		yieldCombined[particle]->SetName(Form("histRatio%02d",particle));
	}
	
	TFile *fHe = TFile::Open("/Users/matthias/alice/Master/Makros/Rootfiles/Data.root", "UPDATE");
	for (int particle = 0; particle < nParticles; particle++){
        yieldHe3[particle] = (TH1D*) fHe->Get(Form("histRaw%02d%02d",0, particle));
		yieldHe3[particle]->SetName(Form("histYieldHe3%02d",particle));
	}
	
	
	TFile * f = new TFile(rootfileyield,"recreate");
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
	l[particle] = new TLine(1.4,1.,2.6,1.);
	l[particle]->SetLineColor(kGray+2);
	l[particle]->SetLineStyle(3);
	l[particle]->SetLineWidth(3);
	l[particle]->Draw();
	legendratio[particle] = new TLegend(0.1,0.7,0.48,0.9);
	legendratio[particle]->SetEntrySeparation(.4);
	legendratio[particle]->SetBorderSize(0);
	legendratio[particle]->AddEntry((TObject*)0, "This work", "");
	legendratio[particle]->AddEntry((TObject*)0, "ALICE pp #sqrt{s} = 13 TeV", "");
	legendratio[particle]->AddEntry((TObject*)0, "High-multiplicity trigger", "");
	legendratio[particle]->Draw();
	}
	ratioPlot[2]->SaveAs(Folder + Form("/Plots/H3/HM/ratioHe3H3.png"));
	ratioPlot[2]->SaveAs(Folder + Form("/Plots/H3/HM/ratioHe3H3.root"));
	ratioPlot[2]->SaveAs(Folder + Form("/Plots/H3/HM/ratioHe3H3.C"));
	ratioPlot[1]->SaveAs(Folder + Form("/Plots/H3/HM/ratioAntiHe3H3.png"));
	ratioPlot[1]->SaveAs(Folder + Form("/Plots/H3/HM/ratioAntiHe3H3.root"));
	ratioPlot[1]->SaveAs(Folder + Form("/Plots/H3/HM/ratioAntiHe3H3.C"));
	ratioPlot[0]->SaveAs(Folder + Form("/Plots/H3/HM/ratioNorHe3H3.png"));
	ratioPlot[0]->SaveAs(Folder + Form("/Plots/H3/HM/ratioNorHe3H3.root"));
	ratioPlot[0]->SaveAs(Folder + Form("/Plots/H3/HM/ratioNorHe3H3.C"));
}
void histRatioCorrected(){
	TFile *fH3 = TFile::Open("/Users/matthiasherzer/alice/He3H3_analysis/analysis/result/Correction/correctionresult.root", "UPDATE");
	TH1D * yieldH3[nParticles] = {0};
    TH1D * yieldHe3[nParticles] = {0};
	TH1D * yieldCombined[nParticles] = {0};
	TH1D * yieldCombinedAnti = {0};
	TH1D * yieldCombinedPerEvent = {0};
	TCanvas *ratioPlot = {0};
	TCanvas *ratioPlot2 = {0};
	TCanvas *ratioPlot3 = {0};
	TCanvas *ratioPlot4 = {0};
	double eventnumber = 6.79038e+08 + 2.98214e+08;
	ratioPlot = new TCanvas("ratioPlot", "", 2000,2000);
	THStack *ratioStack = new THStack("ratioStack", " ; #it{p}_{T} (GeV/#it{c}); #frac{{}^{3}H}{{}^{3}He}");
	for (int particle = 0; particle < nParticles; particle++){
		yieldH3[particle] = (TH1D*) fH3->Get(Form("hCorr%d", particle));
		yieldH3[particle]->SetName(Form("histYieldH3%02d",particle));
		yieldCombined[particle] = (TH1D*)yieldH3[particle]->Clone("histratio");
		yieldCombined[particle]->SetName(Form("histRatio%02d",particle));
	}
	
	for (int particle = 0; particle < nParticles; particle++){
        yieldHe3[particle] = (TH1D*) fH3->Get(Form("hCorrHe%d", particle));
		yieldHe3[particle]->SetName(Form("histYieldHe3%02d",particle));
	}
	
	
	TFile * f = new TFile("/Users/matthiasherzer/alice/He3H3_analysis/analysis/result/Correction/ratioyieldcorr.root","recreate");
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
	legendratio->AddEntry((TObject*)0, "High-multiplicity trigger", "");
	legendratio->Draw();
	ratioPlot->SaveAs(Folder + Form("/Plots/Korrekturen/corrRatioHe3H3.png"));
	ratioPlot->SaveAs(Folder + Form("/Plots/Korrekturen/corrRatioHe3H3.root"));
	ratioPlot->SaveAs(Folder + Form("/Plots/Korrekturen/corrRatioHe3H3.C"));
	ratioPlot2 = new TCanvas("ratioPlot2", "", 2000,2000);
	yieldCombined[0]->SetTitle(" ");
	yieldCombined[0]->SetStats(0);
	yieldCombined[0]->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
	yieldCombined[0]->GetYaxis()->SetTitle("#frac{{}^{3}H}{{}^{3}He}");
	yieldCombined[0]->SetMarkerStyle(8);
	yieldCombined[0]->Draw();
	TLine *l2 = new TLine(1.4,1.,2.6,1.);
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
	legendratio2->AddEntry((TObject*)0, "High Multiplicity trigger", "");
	legendratio2->Draw();
	ratioPlot2->SaveAs(Folder + Form("/Plots/Korrekturen/corrRatioPartHe3H3.png"));
	ratioPlot2->SaveAs(Folder + Form("/Plots/Korrekturen/corrRatioPartHe3H3.root"));
	ratioPlot2->SaveAs(Folder + Form("/Plots/Korrekturen/corrRatioPartHe3H3.C"));
	ratioPlot3 = new TCanvas("ratioPlot3", "", 2000,2000);
	yieldCombined[1]->SetTitle(" ");
	yieldCombined[1]->SetStats(0);
	yieldCombined[1]->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
	yieldCombined[1]->GetYaxis()->SetTitle("#frac{{}^{3}#bar{H}}{{}^{3}#bar{He}}");
	yieldCombined[1]->SetMarkerStyle(8);
	yieldCombined[1]->Draw();
	TLine *l3 = new TLine(1.4,1.,2.6,1.);
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
	legendratio3->AddEntry((TObject*)0, "High-multiplicity trigger", "");
	legendratio3->Draw();
	ratioPlot3->SaveAs(Folder + Form("/Plots/Korrekturen/corrRatioAntiPartHe3H3.png"));
	ratioPlot3->SaveAs(Folder + Form("/Plots/Korrekturen/corrRatioAntiPartHe3H3.root"));
	ratioPlot3->SaveAs(Folder + Form("/Plots/Korrekturen/corrRatioAntiPartHe3H3.C"));
	yieldCombinedPerEvent = (TH1D*)yieldH3[2]->Clone("yieldCombinedPerEvent");
	yieldCombinedPerEvent->Scale(1./eventnumber);
	ratioPlot4 = new TCanvas("ratioPlot4", "", 2000,2000);
	yieldCombinedPerEvent->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
	yieldCombinedPerEvent->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
	yieldCombinedPerEvent->SetStats(0);
	yieldCombinedPerEvent->SetMarkerStyle(8);
	yieldCombinedPerEvent->SetMarkerSize(1.5);
	gPad->SetLogy();
	yieldCombinedPerEvent->Draw();
	TLegend *legendratio4 = new TLegend(0.5344418,0.6865854,0.9041964,0.8865854,NULL,"brNDC");
	legendratio4->SetEntrySeparation(.4);
	legendratio4->SetBorderSize(0);
	legendratio4->SetFillStyle(0);
	//legendrat4io->AddEntry(yieldCombined[2], "#frac{{}^{3}H}{{}^{3}He}", "lep");
	legendratio4->AddEntry((TObject*)0, "Corrected", "");
	legendratio4->AddEntry((TObject*)0, "ALICE pp #sqrt{s} = 13 TeV, |y| < 0.5", "");
	legendratio4->AddEntry((TObject*)0, "High Multiplicity trigger", "");
	//yieldCombinedPerEvent->GetXaxis()->SetRange(1.,6.);
	legendratio4->Draw();
	ratioPlot4->SaveAs(Folder + Form("/Plots/Korrekturen/H3perEvent.C"));
}	