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
#include "He3_readData.h"

TString trigger = "HNU&HQU"; // "HNU" or "HM" or "HNU&HQU" or "HQU"
//TString resultPath = "/Users/matthias/alice/root_results/He3";
TString resultPath = "/Volumes/MyPassport/pass2/HeTri_pass2";
const Int_t nPtBins = 3;
TString periods16 = "deghijklop";
TString periods17 = "cefghijklmor"; //klmor + cefghij
TString periods18 = "bdefghilmnop";
const Int_t nParticles = 3;
const TString particleNames[] = {"{}^{3}He","{}^{3}#bar{He}","{}^{3}He+{}^{3}#bar{He}"};
const TString particleShortNames[] = {"He3", "AntiHe3", "both"};
int particleColors[] = {kBlue, kRed, kBlack};
TString Folder = "result";
TString rootFilePath = Folder;
std::vector<double> cutConf(10, 0); // Changed to vector
const double cutYHe = 0.5; //set rapidity range: -0.5 - 0.5
TString rootfile;
std::vector<std::vector<int>> tofBinsHe3(3, std::vector<int>(100, 0)); // Changed to vector
std::vector<double> ptBins; // Changed to vector
//________________________________________________________________________________________________________________________
void He3_readData(){
    createDir();
    readDataHe3();
}
//________________________________________________________________________________________________________________________
void createDir(){
    gSystem->Exec("mkdir " + Folder);
	gSystem->Exec("mkdir /Users/matthias/alice/Master/readData/Rootfiles");
	gSystem->Exec("mkdir " + Folder + "/Plots");
	gSystem->Exec("mkdir " + Folder + "/Plots/He3");
	gSystem->Exec("mkdir " + Folder + "/Plots/H3");
	gSystem->Exec("mkdir " + Folder + "/Plots/H3/HM");
	gSystem->Exec("mkdir " + Folder + "/Plots/H3/HNU");
	gSystem->Exec("mkdir " + Folder + "/Plots/He3/HM");
	gSystem->Exec("mkdir " + Folder + "/Plots/He3/HNU");
	gSystem->Exec("mkdir " + Folder + "/Plots/Pt");
	gSystem->Exec("mkdir " + Folder + "/Plots/Pt");
	gSystem->Exec("mkdir " + Folder + "/Plots/Pt/H3");
	gSystem->Exec("mkdir " + Folder + "/Plots/Pt/He3");
}
//________________________________________________________________________________________________________________________
bool Cut() {
		if (TMath::Abs(tDcaXY) > cutConf[0]) return false;
		if (TMath::Abs(tDcaZ) > cutConf[1]) return false;
		if (TMath::Abs(tHeSigma) > cutConf[2]) return false;
		if (tnTPCcluster < cutConf[3]) return false;
		if (tTPCchi2 > cutConf[4]) return false;
		if (!tTPCrefit && cutConf[5]) return false;
		if (tKink && cutConf[6]) return false;
		//if (tTRDnTracklets < cutConf[7]) return false;
		return true;	
}
//________________________________________________________________________________________________________________________
void setTreeBranch(TTree *fTree) {
	fTree->SetBranchAddress("tnTPCcluster" , &tnTPCcluster);
	fTree->SetBranchAddress("tTPCchi2"     , &tTPCchi2);
	fTree->SetBranchAddress("tKink"        , &tKink);
	fTree->SetBranchAddress("tTPCrefit"    , &tTPCrefit);
	fTree->SetBranchAddress("tTrigMB"      , &tTrigMB);
	fTree->SetBranchAddress("tTrigHMV0"    , &tTrigHMV0);
	fTree->SetBranchAddress("tTrigHMSPD"   , &tTrigHMSPD);
	fTree->SetBranchAddress("tTrigHNU"     , &tTrigHNU);
	fTree->SetBranchAddress("tTrigHQU"     , &tTrigHQU);
	fTree->SetBranchAddress("tPt"          , &tPt);
	fTree->SetBranchAddress("tCharge"      , &tCharge);
	fTree->SetBranchAddress("tY"           , &tY);
	fTree->SetBranchAddress("tEta"         , &tEta);
	fTree->SetBranchAddress("tPhi"         , &tPhi);
	fTree->SetBranchAddress("tP"           , &tP);
	fTree->SetBranchAddress("tHeDEdx"      , &tHeDEdx);
	fTree->SetBranchAddress("tHeSigma"     , &tHeSigma);
	fTree->SetBranchAddress("tTOFSignalHe" , &tTOFSignalHe);
	fTree->SetBranchAddress("tDcaXY"       , &tDcaXY);
	fTree->SetBranchAddress("tDcaZ"        , &tDcaZ);
	fTree->SetBranchAddress("tSigmaYX"     , &tSigmaYX);
	fTree->SetBranchAddress("tSigmaXYZ"    , &tSigmaXYZ);
	fTree->SetBranchAddress("tSigmaZ"      , &tSigmaZ);
	fTree->SetBranchAddress("tMCtrue"      , &tMCtrue);
	fTree->SetBranchAddress("tPrimary"     , &tPrimary);
	fTree->SetBranchAddress("tWeak"        , &tWeak);
	fTree->SetBranchAddress("tMaterial"    , &tMaterial);
	fTree->SetBranchAddress("tMultV0M"     , &tMultV0M);
	fTree->SetBranchAddress("tRunNumber"   , &tRunNumber);
		
	fTree->SetBranchAddress("tTRDnTracklets" , &tTRDnTracklets);
	fTree->SetBranchAddress("tTRDPid"        , &tTRDPid);
	fTree->SetBranchAddress("tTRDvalid"      , &tTRDvalid);
	fTree->SetBranchAddress("tTRDPt"         , &tTRDPt);
	fTree->SetBranchAddress("tTRDSagitta"    , &tTRDSagitta);
	fTree->SetBranchAddress("tTRDLayerMask"  , &tTRDLayerMask);
	}
//________________________________________________________________________________________________________________________
void readDataHe3(){
	if (trigger == "HNU") {
        rootfile = "/Users/matthias/alice/Master/Makros/Rootfiles/DataHe3_HNU.root";
        tofBinsHe3[0] = {25, 25, 25, 25, 25, 25, 25, 35, 25}; // TRD He3 TRD
        tofBinsHe3[1] = {25, 25, 25, 25, 25, 25, 25, 35, 25}; // TRD Anti He3
        tofBinsHe3[2] = {25, 25, 25, 25, 25, 25, 25, 35, 25}; // Both
        ptBins = {1.3, 1.8, 2.3, 2.8}; // HNU
        cutConf = {0.15,  0.15,  3.0,    120,    2,     1,      1,       0,        0,       0};
    } else if (trigger == "HQU") {
        rootfile = "/Users/matthias/alice/Master/Makros/Rootfiles/DataHe3_HQU.root";
        tofBinsHe3[0] = {25, 25, 25, 25, 25, 25, 25, 35, 25}; // TRD He3 TRD
        tofBinsHe3[1] = {25, 25, 25, 25, 25, 25, 25, 35, 25}; // TRD Anti He3
        tofBinsHe3[2] = {25, 25, 25, 25, 25, 25, 25, 35, 25}; // Both
        ptBins = {1.3, 1.8, 2.3, 2.8}; // HNU
        cutConf = {0.15,  0.15,  3.0,    120,    2,     1,      1,       0,        0,       0};
    } else if (trigger == "HNU&HQU") {
        rootfile = "/Users/matthias/alice/Master/Makros/Rootfiles/DataHe3_HNUHQU.root";
        tofBinsHe3[0] = {25, 25, 25, 25, 25, 25, 25, 35, 25}; // TRD He3 TRD
        tofBinsHe3[1] = {25, 25, 25, 25, 25, 25, 25, 35, 25}; // TRD Anti He3
        tofBinsHe3[2] = {25, 25, 25, 25, 25, 25, 25, 35, 25}; // Both
        ptBins = {1.3, 1.8, 2.3, 2.8}; // HNU
        cutConf = {0.15,  0.15,  3.0,    120,    2,     1,      1,       0,        0,       0};
    }   
	else {
        rootfile = "/Users/matthias/alice/Master/Makros/Rootfiles/DataHe3.root";
        tofBinsHe3[0] = {30, 30, 30, 30, 30, 40, 25, 35, 25}; // TRD He3 HM
        tofBinsHe3[1] = {30, 30, 30, 30, 30, 40, 25, 35, 25}; // TRD Anti He3
        tofBinsHe3[2] = {30, 30, 30, 30, 30, 40, 25, 35, 25}; // TRD Both
        ptBins = {1.4, 1.8, 2.2, 2.6};
        cutConf = {0.15,  0.15,  3.0,    120,    2,     1,      1,       0,        0,       0};
    }
	TCanvas *c1;
	//TChain *fTreeData= new TChain("treeHeHM");
	TChain *fTreeData= new TChain("He3TriTree/treeHe");
	//fTreeData->Add(resultPath + "/Analysis_merged_all_He.root");
	for (Int_t i = 0; i < periods16.Length(); i++){
		fTreeData->Add(resultPath+ "/Data/LHC16"  + periods16(i,1)+ "/AnalysisResults.root");
		}
	for (Int_t i = 0; i < periods17.Length(); i++){
		fTreeData->Add(resultPath+ "/Data/LHC17"  + periods17(i,1)+ "/AnalysisResults.root");
		}
		
	for (Int_t i = 0; i < periods18.Length(); i++){
		fTreeData->Add(resultPath+ "/Data/LHC18"  + periods18(i,1)+ "/AnalysisResults.root");
		}
	
	setTreeBranch(fTreeData);
	
	//create pt bin histograms
	gStyle->SetOptFit(111);
	gStyle->SetOptStat("ne");
	TH1D * histPtHe3[nParticles][nPtBins] = {0};
	for (int particle = 0; particle < nParticles; particle++){
		for (int pt = 0; pt < nPtBins; pt++){
			TString name = Form("histPtHe3%02d%02d%02d", 0, particle, pt);
			TString title = Form("%1.2f < p_{T} < %1.2f", ptBins[pt], ptBins[pt+1]);
			histPtHe3[particle][pt] = new  TH1D(name , title , tofBinsHe3[particle][pt], 1.4, 3.2);
			histPtHe3[particle][pt]->GetXaxis()->SetTitle("m^{2}/z^{2} (GeV^{2}/c^{4})");
			int binWidth = histPtHe3[particle][pt]->GetXaxis()->GetBinWidth(1)*1000;
			histPtHe3[particle][pt]->GetYaxis()->SetTitle(Form("Counts / (%02d MeV^{2}/c^{4})", binWidth));
			histPtHe3[particle][pt]->Sumw2();
			histPtHe3[particle][pt]->GetXaxis()->SetRangeUser(1.4, 3.2);
		}
	}
  // loop over tree and fill histograms
	Long64_t nEntries = (Int_t)fTreeData->GetEntries();
	for (Long64_t i=0; i<nEntries; i++) {
		if (i % (nEntries/2000) == 0) 
			cout << Form("\rreading data tree: %1.2f %%", 100. * i / (double) nEntries) << flush;
		fTreeData->GetEntry(i);
		

		if (TMath::Abs(tY) > cutYHe)	continue;	// set rapidity range 

		if (trigger == "HM"){
			if (!tTrigHMV0 && !tTrigHMSPD) continue;  // use high multiplicity triggers (w/o multiplicity cut!)
		}
		if (trigger == "HNU&HQU")
		{
			if (!tTrigHNU && !tTrigHQU) continue;	//Nuclei Trigger
		}
		if (trigger == "HNU")
		{
			if (!tTrigHNU) continue;	//Nuclei Trigger
		}
		if (trigger == "HQU")
		{
			if (!tTrigHQU) continue;	//Nuclei Trigger
		}
		
		int particle = 0;
		if (tCharge < 0) particle = 1;
		for (int pt = 0; pt < nPtBins; pt++){
			if (tPt >= ptBins[pt] && tPt < ptBins[pt+1] && tTOFSignalHe >= 0) {
				if (Cut()) {
					//cout << tPt << endl;
					histPtHe3[particle][pt]->Fill(tTOFSignalHe);
					histPtHe3[2][pt]->Fill(tTOFSignalHe);
				}		
			}
		}
	}
	cout << endl;
	// save histos
	TFile * f = new TFile(rootfile,"recreate");
	for (int particle = 0; particle < nParticles; particle++){
		for (int pt = 0; pt < nPtBins; pt++){
			histPtHe3[particle][pt]->Write(0, TObject::kOverwrite);		
		}
	}
	f->Close();
}
//_________________________________________________________________________________________________________
