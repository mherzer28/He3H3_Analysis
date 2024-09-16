#include <iostream>
#include "AliPWGFunc.h"
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
using namespace std;
int const nParticles = 3;
const TString particleNames[] = {"{}^{3}H","{}^{3}#bar{H}","{}^{3}H+{}^{3}#bar{H}"};
const TString particleNamesHe[] = {"{}^{3}He","{}^{3}#bar{He}","{}^{3}He+{}^{3}#bar{He}"};
int particleColors[] = {kBlue, kRed, kBlack};
TFile *result;
TFile *resultHe;
TFile *result2;
TFile *result2He;
TFile *resultCorrection;
TString triggerH3 = "HQU";//HNUHQU HNU HQU
TString triggerHe = "HNU";

//_____________________________________________________________________________________________________________
void normHisto(TH1D* hist) {
  // teilt jedes Bin durch Binbreite
	for (int bin = 0; bin <= hist->GetNbinsX(); bin++){
		hist->SetBinContent(bin, hist->GetBinContent(bin) / hist->GetBinWidth(bin));
		hist->SetBinError(bin, hist->GetBinError(bin) / hist->GetBinWidth(bin));
	}
}
//_____________________________________________________________________________________________________________
TF1* getFunction() {
	// gemessene pt-shape für 3He (pp 13 TeV, HM-trigger) aus Analyse von M. Habib	
	// die kannst du erstmal auch für 3H nehmen (ggf. später nochmal Rücksprache mit Benjamin)
	AliPWGFunc * pf = new AliPWGFunc();
	pf->SetVarType(AliPWGFunc::kdNdpt);
	TF1 *func = pf->GetLevi(2.991, 0.66, 365137, 1, "LeviHyp");
	return func;
}
//_____________________________________________________________________________________________________________
TH1D* wAvgHist(TH1D* hRaw, TH1D* hFine, TString hName) {
  // Generated / Recos gewichtet mit pt-Verteilung im Analyse-Binning
	TF1 *funcWgt = getFunction();
	
	TH1D* hwAvg = (TH1D*) hRaw->Clone(hName);
    hwAvg->Reset();
	
	double *edge = new double[hwAvg->GetNbinsX()];
	hwAvg->GetXaxis()->GetLowEdge(edge);
	
	for (int i = 0; i < hwAvg->GetNbinsX(); i++) { 
		double intFrom = edge[i];
		double intTo = intFrom + hwAvg->GetXaxis()->GetBinWidth(i+1) - 1e-3;

		double sum_wi = 0;
		double sum_wixi = 0;
		for (int bin = hFine->FindBin(intFrom); bin < hFine->FindBin(intTo); bin++){
			double xi = hFine->GetBinContent(bin);
			double wi = funcWgt->Eval(hFine->GetBinCenter(bin));
			sum_wi = sum_wi + wi;
			sum_wixi = sum_wixi + (wi*xi);
		}	
		double wavg = sum_wixi / sum_wi;

		hwAvg->SetBinContent(i+1, wavg);
		hwAvg->SetBinError(i+1, TMath::Sqrt(wavg));
	}
	return hwAvg;
}
//_________________________________________________________________________________________________________
void setYaxis(TAxis *axis,double dist) {
	axis->SetTitleSize(16);
	axis->SetTitleFont(43);
	axis->SetTitleOffset(dist);
	axis->SetLabelFont(43); 
	axis->SetLabelSize(15);		
}
//_________________________________________________________________________________________________________________
void plotRatio(TPad* pad, TH1D* h[2], Bool_t log, double dist){
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
	h3->GetYaxis()->SetTitle("{}^{3}#bar{H} / {}^{3}H");
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
	h3->Draw("ep");       // Draw the ratio plot    
	pad1->cd();               
}
//___________________________________________________________________________
void plotRatioHe(TPad* pad, TH1D* h[2], Bool_t log, double dist){
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
	h3->Draw("ep");       // Draw the ratio plot    
	pad1->cd();               
}
//_____________________________________________________________________________________________________________
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
		//		particleLegend->AddEntry(h[particle] , "(" + particleNames[particle] + ")/2)", "L");	
		}	
	}
	return particleLegend;
}
//_____________________________________________________________________________________________________________
TLegend* legendParticleHe(TH1D* h[nParticles], int partMode) {
// partMode : 0 particle, anti; 1 particle, anti, particle+anti; 2 particle, anti, (particle+anti)/2;
	TLegend *particleLegend = new TLegend(0.75,0.75,0.95,0.9);
	particleLegend->SetTextFont(43);
	particleLegend->SetTextSize(18);
	particleLegend->SetBorderSize(0);
	particleLegend->SetFillStyle(0);
	for (int particle = 0; particle < nParticles; particle++){
		if (particle < 2)
			particleLegend->AddEntry(h[particle] , particleNamesHe[particle], "L");
		else {
			if (partMode == 1)
				particleLegend->AddEntry(h[particle] , particleNamesHe[particle], "L");	
			//if (partMode == 2)		
			//	particleLegend->AddEntry(h[particle] , "(" + particleNamesHe[particle] + ")/2)", "L");	
		}	
	}
	return particleLegend;
}
//_____________________________________________________________________________________________________________
void correctionH3(){
	double rapidity = 1.0;
    TH1D* rawHist[nParticles] = {0};
    TH1D* hCorr[nParticles] = {0};
    TH1D* hGenH3[nParticles] = {0};
    TH1D* hRecH3[nParticles] = {0};
    TH1D* hGenH3W[nParticles] = {0};
    TH1D* hRecH3W[nParticles] = {0};
    TH1D* hAccEffH3[nParticles] = {0};
    TH1D* ratio[nParticles] = {0};
    gStyle->SetOptStat(0);	
    if (triggerH3 == "HNU"){
        result = new TFile("/Users/matthias/alice/Master/Makros/result/correction/correctionYield_HNU.root", "UPDATE");
	}
    else if (triggerH3 == "HQU"){
        result = new TFile("/Users/matthias/alice/Master/Makros/result/correction/correctionYield_HQU.root", "UPDATE");
	}
    else if (triggerH3 == "HNUHQU"){
        result = new TFile("/Users/matthias/alice/Master/Makros/result/correction/correctionYield_HNUHQU.root", "UPDATE");
	}
    if (result->IsZombie()) {
        std::cerr << "Error: Could not open the file for H3." << std::endl;
        return;
    }
	for (int particle = 0; particle < nParticles; particle++){
        rawHist[particle] = (TH1D*) result->Get(Form("histRaw%02d", particle));
        rawHist[particle]->SetName(Form("rawHist%d", particle));
        rawHist[particle]->GetXaxis()->SetTitle("#it{p}_{T} (Gev/#it{c})");
        rawHist[particle]->GetYaxis()->SetTitle("Counts");
        normHisto(rawHist[particle]);
        rawHist[particle]->Scale(1. / rapidity);
    }
	std::cout << "test1" << std::endl;
	if (triggerH3 == "HNU")
	{
		result2 = new TFile("/Users/matthias/alice/Master/Makros/result/correction/correction_HNU.root", "UPDATE");
	}
	else if (triggerH3 == "HQU")
	{
		result2 = new TFile("/Users/matthias/alice/Master/Makros/result/correction/correction_HQU.root", "UPDATE");
	}
	else if (triggerH3 == "HNUHQU")
	{
		result2 = new TFile("/Users/matthias/alice/Master/Makros/result/correction/correction_HNUHQU.root", "UPDATE");
	}
	std::cout << "test1" << std::endl;
    hGenH3[0] = (TH1D*)result2->Get("hGen");
    hRecH3[0] = (TH1D*)result2->Get("hRec");
    hGenH3[1] = (TH1D*)result2->Get("hGenAnti");
    hRecH3[1] = (TH1D*)result2->Get("hRecAnti");
    hGenH3[2] = (TH1D*) hGenH3[0]->Clone(Form("hGenH3%d", 2));
    hGenH3[2]->Add(hGenH3[1]);
    hRecH3[2] = (TH1D*) hRecH3[0]->Clone(Form("hRecH3%d", 2));
    hRecH3[2]->Add(hRecH3[1]);
	std::cout << "test1" << std::endl;
    if (triggerH3 == "HNU")
	{
		resultCorrection = new TFile("/Users/matthias/alice/Master/Makros/result/correction/correctionresult_HNU.root", "recreate");
	}
	else if (triggerH3 == "HQU")
	{
		resultCorrection = new TFile("/Users/matthias/alice/Master/Makros/result/correction/correctionresult_HQU.root", "recreate");
	}
	else if (triggerH3 == "HNUHQU")
	{
		resultCorrection = new TFile("/Users/matthias/alice/Master/Makros/result/correction/correctionresult_HNUHQU.root", "recreate");
	}
	std::cout << "test1" << std::endl;
    for (int particle = 0; particle < nParticles; particle++){
        hGenH3[particle]->Write(0, TObject::kOverwrite);
        hRecH3[particle]->Write(0, TObject::kOverwrite);
    }
    for (int particle = 0; particle < nParticles; particle++){
        rawHist[particle]->Write(0, TObject::kOverwrite);
    }

    for (int particle = 0; particle < nParticles; particle++){
        hGenH3W[particle] = wAvgHist(rawHist[particle], hGenH3[particle], Form("hGenH3W%d", particle));
	    hRecH3W[particle] = wAvgHist(rawHist[particle], hRecH3[particle], Form("hGRecH3W%d", particle));
        hGenH3W[particle]->Write(0, TObject::kOverwrite);
        hRecH3W[particle]->Write(0, TObject::kOverwrite);
    }
    
    for (int particle = 0; particle < nParticles; particle++){
        hAccEffH3[particle] = (TH1D*) hRecH3W[particle]->Clone(Form("hAccEffH3%d", particle));
        hAccEffH3[particle]->Divide(hGenH3W[particle]);
        hAccEffH3[particle]->SetTitle(";#it{p}_{T} (GeV/c);acc x eff");
        hAccEffH3[particle]->Write(0, TObject::kOverwrite);
    }
    
    for (int particle = 0; particle < nParticles-1; particle++){
        hCorr[particle] = (TH1D*) rawHist[particle]->Clone(Form("hCorr%d", particle));
        hCorr[particle]->Divide(hAccEffH3[particle]);
        hCorr[particle]->Write(0, TObject::kOverwrite);
    }
    hCorr[2] = (TH1D*) hCorr[0]->Clone(Form("hCorr%d", 2));
    hCorr[2]->Add(hCorr[1]);
    hCorr[2]->Write(0, TObject::kOverwrite);
    hCorr[0]->SetTitle("{}^{3}H");
    hCorr[1]->SetTitle("{}^{3}#bar{H}");
    hCorr[2]->SetTitle("{}^{3}H + {}^{3}#bar{H}");
    hAccEffH3[0]->SetTitle("{}^{3}H");
    hAccEffH3[1]->SetTitle("{}^{3}#bar{H}");
    TCanvas * c = new TCanvas("H3", "H3" , 1920, 1080);
    
    c->Divide(3,2);
    int i = 1;
    c->cd(i);
    gPad->SetLeftMargin(0.18);
    hAccEffH3[0]->Draw();
    c->cd(i+1);
    gPad->SetLeftMargin(0.18);
    hAccEffH3[1]->Draw();
    c->cd(i+2);
    gPad->SetLeftMargin(0.18);
    //hAccEffH3[2]->Draw();
    TPaveText *infoLabel=new TPaveText(0.1, .1, 0.9, 0.9, "blNDC");
	infoLabel->SetTextAlign(13);
	infoLabel->SetTextFont(43);
	infoLabel->SetTextSize(18);
	infoLabel->SetBorderSize(0);
	infoLabel->SetFillStyle(0);
 	infoLabel->AddText("Particle: " + particleNames[0] + "+" + particleNames[1]);
 	infoLabel->AddText("pp #sqrt{s} = 13 TeV");	 	
	if (triggerH3 == "HNU")
	{
		infoLabel->AddText("Trigger: HNU");
	}
	else if (triggerH3 == "HQU")
	{
		infoLabel->AddText("Trigger: HQU");
	}
	else if (triggerH3 == "HNUHQU")
	{
		infoLabel->AddText("Trigger: HNU HQU");
	}
	infoLabel->AddText("work in progress");  
    infoLabel->Draw();   
    i = 4;
    for (int particle = 0; particle < nParticles; particle++){
        c->cd(i);
        gPad->SetLeftMargin(0.18);
        hCorr[particle]->Draw();
        i++;
    }
	if (triggerH3 == "HNU")
	{
		c->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNU/corryield_H3_HNU.pdf");
	}
	else if (triggerH3 == "HQU")
	{
		c->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HQU/corryield_H3_HQU.pdf");
	}
	else if (triggerH3 == "HNUHQU")
	{
		c->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNUHQU/corryield_H3_HNUHQU.pdf");
	}

    
    TCanvas *canYield = new TCanvas("CorrYield", "corr yield bin counting", 1920, 1080);
    TLegend *particleLegend = legendParticle(hCorr, 2);
	canYield->cd();
	canYield->Update();
    plotRatio((TPad*) gROOT->GetSelectedPad(), hCorr, 0, 1.);
    particleLegend->Draw("Same");
    //hCorr[2]->Scale(1./2.);
	//hCorr[2]->Draw("SAME");
	if (triggerH3 == "HNU")
	{
		canYield->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNU/ratiocorryield_H3_HNU.pdf");
    	canYield->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNU/ratiocorryield_H3_HNU.root");
		canYield->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNU/ratiocorryield_H3_HNU.C");
	}
	else if (triggerH3 == "HQU")
	{
		canYield->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HQU/ratiocorryield_H3_HQU.pdf");
    	canYield->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HQU/ratiocorryield_H3_HQU.root");
		canYield->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HQU/ratiocorryield_H3_HQU.C");
	}
	else if (triggerH3 == "HNUHQU")
	{
		canYield->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNUHQU/ratiocorryield_H3_HNUHQU.pdf");
    	canYield->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNUHQU/ratiocorryield_H3_HNUHQU.root");
		canYield->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNUHQU/ratiocorryield_H3_HNUHQU.C");
	}
    
    canYield->Write(0, TObject::kOverwrite);
}
//_____________________________________________________________________________________________________________
void correctionHe(){
	double rapidity = 1.0;
    TH1D* rawHistHe[nParticles] = {0};
    TH1D* hCorrHe[nParticles] = {0};
    TH1D* hGenHe[nParticles] = {0};
    TH1D* hRecHe[nParticles] = {0};
    TH1D* hGenHeW[nParticles] = {0};
    TH1D* hRecHeW[nParticles] = {0};
    TH1D* hAccEffHe[nParticles] = {0};
    TH1D* ratio[nParticles] = {0};

    gStyle->SetOptStat(0);
	if (triggerHe == "HNU")
	{
		resultHe = new TFile("/Users/matthias/alice/Master/Makros/result/correction/correctionYieldHe_HNU.root", "UPDATE");
	}
	else if (triggerHe == "HQU")
	{
		resultHe = new TFile("/Users/matthias/alice/Master/Makros/result/correction/correctionYieldHe_HQU.root", "UPDATE");
	}
	else if (triggerHe == "HNUHQU")
	{
		resultHe = new TFile("/Users/matthias/alice/Master/Makros/result/correction/correctionYieldHe_HNUHQU.root", "UPDATE");
	}
    for (int particle = 0; particle < nParticles; particle++){
        rawHistHe[particle] = (TH1D*)resultHe->Get(Form("histRaw%02d%02d", 0,particle));
        rawHistHe[particle]->SetName(Form("rawHistHe%d", particle));
        rawHistHe[particle]->GetXaxis()->SetTitle("#it{p}_{T} (Gev/#it{c})");
        rawHistHe[particle]->GetYaxis()->SetTitle("Counts");
        normHisto(rawHistHe[particle]);
        rawHistHe[particle]->Scale(1. / rapidity);
    }
	if (triggerHe == "HNU")
	{
		result2He = new TFile("/Users/matthias/alice/Master/Makros/result/correction/correction_HNU.root", "UPDATE");
	}
	else if (triggerHe == "HQU")
	{
		result2He = new TFile("/Users/matthias/alice/Master/Makros/result/correction/correction_HQU.root", "UPDATE");
	}
	else if (triggerHe == "HNUHQU")
	{
		result2He = new TFile("/Users/matthias/alice/Master/Makros/result/correction/correction_HNUHQU.root", "UPDATE");
	}
    hGenHe[0] = (TH1D*)result2He->Get("hGenHe");
    hRecHe[0] = (TH1D*)result2He->Get("hRecHe");
    hGenHe[1] = (TH1D*)result2He->Get("hGenHeAnti");
    hRecHe[1] = (TH1D*)result2He->Get("hRecHeAnti");
    hGenHe[2] = (TH1D*) hGenHe[0]->Clone(Form("hGenHe%d", 2));
    hGenHe[2]->Add(hGenHe[1]);
    hRecHe[2] = (TH1D*) hRecHe[0]->Clone(Form("hRecHe%d", 2));
    hRecHe[2]->Add(hRecHe[1]);
    if (triggerHe == "HNU")
	{
		resultCorrection = new TFile("/Users/matthias/alice/Master/Makros/result/correction/correctionresult_HNU.root", "recreate");
	}
	else if (triggerHe == "HQU")
	{
		resultCorrection = new TFile("/Users/matthias/alice/Master/Makros/result/correction/correctionresult_HQU.root", "recreate");
	}
	else if (triggerHe == "HNUHQU")
	{
		resultCorrection = new TFile("/Users/matthias/alice/Master/Makros/result/correction/correctionresult_HNUHQU.root", "recreate");
	}
    for (int particle = 0; particle < nParticles; particle++){
        hGenHe[particle]->Write(0, TObject::kOverwrite);
        hRecHe[particle]->Write(0, TObject::kOverwrite);
    }
    for (int particle = 0; particle < nParticles; particle++){
        rawHistHe[particle]->Write(0, TObject::kOverwrite);
    }

    for (int particle = 0; particle < nParticles; particle++){
        hGenHeW[particle] = wAvgHist(rawHistHe[particle], hGenHe[particle], Form("hGenHeW%d", particle));
	    hRecHeW[particle] = wAvgHist(rawHistHe[particle], hRecHe[particle], Form("hRecHeW%d", particle));
        hGenHeW[particle]->Write(0, TObject::kOverwrite);
        hRecHeW[particle]->Write(0, TObject::kOverwrite);
    }
    
   
    for (int particle = 0; particle < nParticles; particle++){
        hAccEffHe[particle] = (TH1D*) hRecHeW[particle]->Clone(Form("hAccEffHe%d", particle));
        hAccEffHe[particle]->Divide(hGenHeW[particle]);
        hAccEffHe[particle]->SetTitle(";#it{p}_{T} (GeV/c);acc x eff");
        hAccEffHe[particle]->Write(0, TObject::kOverwrite);
    }

    for (int particle = 0; particle < nParticles-1; particle++){
        hCorrHe[particle] = (TH1D*) rawHistHe[particle]->Clone(Form("hCorrHe%d", particle));
        hCorrHe[particle]->Divide(hAccEffHe[particle]);
        hCorrHe[particle]->Write(0, TObject::kOverwrite);
    }
    hCorrHe[2] = (TH1D*) hCorrHe[0]->Clone(Form("hCorrHe%d", 2));
    hCorrHe[2]->Add(hCorrHe[1]);
    hCorrHe[2]->Write(0, TObject::kOverwrite);
    hCorrHe[0]->SetTitle("{}^{3}He");
    hCorrHe[1]->SetTitle("{}^{3}#bar{He}");
    hCorrHe[2]->SetTitle("{}^{3}He + {}^{3}#bar{He}");
    hAccEffHe[0]->SetTitle("{}^{3}He");
    hAccEffHe[1]->SetTitle("{}^{3}#bar{He}");
 
    TCanvas * c2 = new TCanvas("He", "He" , 1920, 1080);

    c2->Divide(3,2);
    int i = 1;
    c2->cd(i);
    gPad->SetLeftMargin(0.18);
    hAccEffHe[0]->Draw();
    c2->cd(i+1);
    gPad->SetLeftMargin(0.18);
    hAccEffHe[1]->Draw();
    c2->cd(i+2);
    gPad->SetLeftMargin(0.18);
    //hAccEffHe[2]->Draw();
    TPaveText *infoLabelHe=new TPaveText(0.1, .1, 0.9, 0.9, "blNDC");
	infoLabelHe->SetTextAlign(13);
	infoLabelHe->SetTextFont(43);
	infoLabelHe->SetTextSize(18);
	infoLabelHe->SetBorderSize(0);
	infoLabelHe->SetFillStyle(0);
 	infoLabelHe->AddText("Particle: " + particleNamesHe[0] + "+" + particleNamesHe[1]);
 	infoLabelHe->AddText("pp #sqrt{s} = 13 TeV");	
	if (triggerHe == "HNU")
	{
		infoLabelHe->AddText("Trigger: HNU");
	}
	if (triggerHe == "HQU")
	{
		infoLabelHe->AddText("Trigger: HQU");
	}
	if (triggerHe == "HNUHQU")
	{
		infoLabelHe->AddText("Trigger: HNU HQU");
	}
	infoLabelHe->AddText("work in progress");  
    infoLabelHe->Draw();
    i = 4;
    for (int particle = 0; particle < nParticles; particle++){
        c2->cd(i);
        gPad->SetLeftMargin(0.18);
        hCorrHe[particle]->Draw();
        i++;
    }
	if (triggerHe == "HNU")
	{
		c2->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNU/corryield_He_HNU.pdf");
	}
	else if (triggerHe == "HQU")
	{
		c2->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HQU/corryield_He_HQU.pdf");
	}
	else if (triggerHe == "HNUHQU")
	{
		c2->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNUHQU/corryield_He_HNUHQU.pdf");
	}

    TCanvas *canYieldHe = new TCanvas("CorrYieldHe", "He corr yield bin counting", 1920, 1080);
    TLegend *particleLegendHe = legendParticleHe(hCorrHe, 2);
	canYieldHe->cd();
	canYieldHe->Update();
    plotRatioHe((TPad*) gROOT->GetSelectedPad(), hCorrHe, 0, 1.);
    particleLegendHe->Draw("Same");
    //hCorrHe[2]->Scale(1./2.);
	//hCorrHe[2]->Draw("SAME");
	if (triggerHe == "HNU")
	{
		canYieldHe->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNU/ratiocorryield_He3_HNU.pdf");
    	canYieldHe->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNU/ratiocorryield_He3_HNU.root");
		canYieldHe->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNU/ratiocorryield_He3_HNU.C");
	}
	else if (triggerHe == "HQU")
	{
		canYieldHe->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HQU/ratiocorryield_He3_HQU.pdf");
    	canYieldHe->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HQU/ratiocorryield_He3_HQU.root");
		canYieldHe->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HQU/ratiocorryield_He3_HQU.C");
	}
	else if (triggerHe == "HNUHQU")
	{
		canYieldHe->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNUHQU/ratiocorryield_He3_HNUHQU.pdf");
    	canYieldHe->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNUHQU/ratiocorryield_He3_HNUHQU.root");
		canYieldHe->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/ratio/HNUHQU/ratiocorryield_He3_HNUHQU.C");
	}
    
    canYieldHe->Write(0, TObject::kOverwrite);
}
//_____________________________________________________________________________________________________________
void correctionHNU(){
	correctionH3();
	correctionHe();
}
//_____________________________________________________________________________________________________________
   