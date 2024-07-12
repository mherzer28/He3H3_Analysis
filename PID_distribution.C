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
#include "PID_distribution.h"

TString periods16 = "deghijklop";
TString periods17 = "cefghijklmor";
TString periods18 = "bdefghilmnop";
TString resultPathMC = "/Users/matthias/alice/root_results/MC";
TString resultPath = "";
TString resultfile = "/Users/matthias/alice/Master/Makros/Rootfiles/PID.root";
//________________________________________________________________________________________________________
void PID_distribution(){
    PID_MC();
    //PID_Data();
    plot();
}
//________________________________________________________________________________________________________
void setTreeBranchHe3(TTree *fTree) {
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
//________________________________________________________________________________________________________
void setTreeBranchH3(TTree *fTree) {
	fTree->SetBranchAddress("tRunNumber"       , &tRunNumber       );
	fTree->SetBranchAddress("tEventId"         , &tEventId         );	
	fTree->SetBranchAddress("tPt"              , &tPt              );
	fTree->SetBranchAddress("tChargeTri"       , &tChargeTri          );
	fTree->SetBranchAddress("tE"               , &tE               );
	fTree->SetBranchAddress("tY"               , &tY               );
	fTree->SetBranchAddress("tEta"             , &tEta             );
	fTree->SetBranchAddress("tPhi"             , &tPhi             );
	fTree->SetBranchAddress("tP"               , &tP               );
	fTree->SetBranchAddress("tPx"              , &tPx              );
	fTree->SetBranchAddress("tPy"              , &tPy              );
	fTree->SetBranchAddress("tPz"              , &tPz              );
	fTree->SetBranchAddress("tTriSigma"        , &tTriSigma           );
	fTree->SetBranchAddress("tTriDedx"         , &tTriDedx            );
	fTree->SetBranchAddress("tDcaXY"           , &tDcaXY           );
	fTree->SetBranchAddress("tDcaZ"            , &tDcaZ            );
	fTree->SetBranchAddress("tSigmaYX"         , &tSigmaYX         );
	fTree->SetBranchAddress("tSigmaXYZ"        , &tSigmaXYZ        );
	fTree->SetBranchAddress("tSigmaZ"          , &tSigmaZ          );
	fTree->SetBranchAddress("tMCtrue"          , &tMCtrue          );
	fTree->SetBranchAddress("tTrigMB"          , &tTrigMB          );
	fTree->SetBranchAddress("tTrigHMV0"        , &tTrigHMV0        );
	fTree->SetBranchAddress("tTrigHMSPD"       , &tTrigHMSPD       );
	fTree->SetBranchAddress("tTrigHNU"         , &tTrigHNU         );
	fTree->SetBranchAddress("tTrigHQU"         , &tTrigHQU         );
	fTree->SetBranchAddress("tMagField"        , &tMagField        );
	fTree->SetBranchAddress("tTRDvalid"        , &tTRDvalid        );
	fTree->SetBranchAddress("tTRDPid"          , &tTRDPid          );
	fTree->SetBranchAddress("tTRDnTracklets"   , &tTRDnTracklets   );
	fTree->SetBranchAddress("tTRDPt"           , &tTRDPt           );
	fTree->SetBranchAddress("tTRDLayerMask"    , &tTRDLayerMask    );
	fTree->SetBranchAddress("tTRDSagitta"      , &tTRDSagitta      );
	fTree->SetBranchAddress("tTRDStack"        , &tTRDStack        );
	fTree->SetBranchAddress("tTRDSector"       , &tTRDSector       );
	fTree->SetBranchAddress("tTRDPID0"         , &tTRDPID0         );
	fTree->SetBranchAddress("tTRDPID1"         , &tTRDPID1         );
	fTree->SetBranchAddress("tTRDPID2"         , &tTRDPID2         );
	fTree->SetBranchAddress("tTRDPID3"         , &tTRDPID3         );
	fTree->SetBranchAddress("tTRDPID4"         , &tTRDPID4         );
	fTree->SetBranchAddress("tTRDPID5"         , &tTRDPID5         );
	fTree->SetBranchAddress("tnTPCcluster"     , &tnTPCcluster     );
	fTree->SetBranchAddress("tnITScluster"     , &tnITScluster     );
	fTree->SetBranchAddress("tTPCchi2"         , &tTPCchi2         );
	fTree->SetBranchAddress("tSPDFiredChips0"  , &tSPDFiredChips0  );
	fTree->SetBranchAddress("tSPDFiredChips1"  , &tSPDFiredChips1  );
	fTree->SetBranchAddress("tSPDTracklets"    , &tSPDTracklets    );
	fTree->SetBranchAddress("tSPDCluster"      , &tSPDCluster      );
	fTree->SetBranchAddress("tV0Multiplicity"  , &tV0Multiplicity  );
	fTree->SetBranchAddress("tNTracks"         , &tNTracks         );
	fTree->SetBranchAddress("tMultV0M"         , &tMultV0M         );
	fTree->SetBranchAddress("tMultOfV0M"       , &tMultOfV0M       );
	fTree->SetBranchAddress("tMultSPDTracklet" , &tMultSPDTracklet );
	fTree->SetBranchAddress("tMultSPDCluster"  , &tMultSPDCluster  );
	fTree->SetBranchAddress("tMultRef05"       , &tMultRef05       );
	fTree->SetBranchAddress("tMultRef08"       , &tMultRef08       );
	fTree->SetBranchAddress("tKink"            , &tKink            );
	fTree->SetBranchAddress("tTPCrefit"        , &tTPCrefit        );
	fTree->SetBranchAddress("tITSrefit"        , &tITSrefit        );
	fTree->SetBranchAddress("tTOFSignalTri"    , &tTOFSignalTri    );
	fTree->SetBranchAddress("tPrimary"         , &tPrimary         );
	fTree->SetBranchAddress("tWeak"            , &tWeak            );
	fTree->SetBranchAddress("tMaterial"        , &tMaterial        );
	fTree->SetBranchAddress("tPdg"			 , &tPdg		);	
}
//___________________________________________________________________________
void PID_MC(){
    TH1D* histo_dist_mc_He3 = {0};
    TH1D* histo_dist_mc_He3_anti = {0};
    TH1D* histo_dist_mc_H3 = {0};
    TH1D* histo_dist_mc_H3_anti = {0};
    TFile * f = new TFile(resultfile,"recreate");
    TChain *fTreeDataHe3= new TChain("He3TriTree/treeHe");
    for (Int_t i = 0; i < periods16.Length(); i++){
      fTreeDataHe3->Add(resultPathMC+ "/LHC16"  + periods16(i,1)+ "/AnalysisResults.root");
      }
    for (Int_t i = 0; i < periods17.Length(); i++){
      fTreeDataHe3->Add(resultPathMC+ "/LHC17"  + periods17(i,1)+ "/AnalysisResults.root");
      }
    for (Int_t i = 0; i < periods18.Length(); i++){
      fTreeDataHe3->Add(resultPathMC+ "/LHC18"  + periods18(i,1)+ "/AnalysisResults.root");
      }
    setTreeBranchHe3(fTreeDataHe3);
    histo_dist_mc_He3 = new TH1D("histo_dist_mc_he3", "", 300, 0 ,255);
    histo_dist_mc_He3_anti = new TH1D("histo_dist_mc_he3_anti", "", 300, 0 ,255);
    histo_dist_mc_He3->SetStats(0);
    histo_dist_mc_He3_anti->SetStats(0);
    Int_t nEntries = (Int_t)fTreeDataHe3->GetEntries();
	for (Int_t i=0; i<nEntries; i++) {
		if (i % (nEntries/2000) == 0) 
			cout << Form("\rreading data tree: %1.2f %%", 100. * i / (double) nEntries) << flush; 
		fTreeDataHe3->GetEntry(i);
		
		if (TMath::Abs(tY) > 0.5)	continue;	// set rapidity range
        //if (!tTrigHNU && !tTrigHQU) continue;	//Nuclei Trigger
		int particle = 0;
		if (tCharge < 0) particle = 1;
        if (tTOFSignalHe > 1.75 && tTOFSignalHe < 2.39 && tMCtrue > 0 && tPrimary > 0 && tTRDPid > 0 && tTRDPid <= 255){
        //if (tMCtrue > 0 && tPrimary > 0 && tTRDPid > 0 && tTRDPid <= 255){
		    if (particle == 0){
                histo_dist_mc_He3->Fill(tTRDPid);
            }
            else if (particle == 1){
                histo_dist_mc_He3_anti->Fill(tTRDPid);
            }
            //histo_dist_mc_He3->Fill(tTRDPid);
		}		
	}
	cout << endl;
    histo_dist_mc_He3->Write(0, TObject::kOverwrite);
    histo_dist_mc_He3_anti->Write(0, TObject::kOverwrite);
    TChain *fTreeDataH3= new TChain("He3TriTree/treeTri");
    for (Int_t i = 0; i < periods16.Length(); i++){
      fTreeDataH3->Add(resultPathMC+ "/LHC16"  + periods16(i,1)+ "/AnalysisResults.root");
      }
    for (Int_t i = 0; i < periods17.Length(); i++){
      fTreeDataH3->Add(resultPathMC+ "/LHC17"  + periods17(i,1)+ "/AnalysisResults.root");
      }
    for (Int_t i = 0; i < periods18.Length(); i++){
      fTreeDataH3->Add(resultPathMC+ "/LHC18"  + periods18(i,1)+ "/AnalysisResults.root");
      }
    setTreeBranchH3(fTreeDataH3);
    histo_dist_mc_H3 = new TH1D("histo_dist_mc_h3", "", 300, 0 ,255);
    histo_dist_mc_H3_anti = new TH1D("histo_dist_mc_h3_anti", "", 300, 0 ,255);
    histo_dist_mc_H3->SetStats(0);
    histo_dist_mc_H3_anti->SetStats(0);
    Int_t nEntriesH3 = (Int_t)fTreeDataH3->GetEntries();
	for (Int_t i=0; i<nEntriesH3; i++) {
		if (i % (nEntriesH3/2000) == 0) 
			cout << Form("\rreading data tree: %1.2f %%", 100. * i / (double) nEntriesH3) << flush; 
		fTreeDataH3->GetEntry(i);
		
		if (TMath::Abs(tY) > 0.5)	continue;	// set rapidity range
        //if (!tTrigHNU && !tTrigHQU) continue;	//Nuclei Trigger
		int particle = 0;
		if (tChargeTri < 0) particle = 1;
        if (tTOFSignalTri > 7.04 && tTOFSignalHe < 8.91 && tMCtrue > 0 && tPrimary > 0 && tTRDPid > 0 && tTRDPid <= 255){
        //if (tMCtrue > 0 && tPrimary > 0 && tTRDPid > 0 && tTRDPid <= 255){
		    if (particle == 0){
                histo_dist_mc_H3->Fill(tTRDPid);
            }
            else if (particle == 1){
                histo_dist_mc_H3_anti->Fill(tTRDPid);
            }
            //histo_dist_mc_He3->Fill(tTRDPid);
		}		
	}
	cout << endl;
    histo_dist_mc_H3->Write(0, TObject::kOverwrite);
    histo_dist_mc_H3_anti->Write(0, TObject::kOverwrite);
    f->Close();
}
//________________________________________________________________________________________________________
/*void PID_Data(){
    TH1D* histo_dist_He3 = {0};
    TH1D* histo_dist_He3_anti = {0};
    TH1D* histo_dist_H3 = {0};
    TH1D* histo_dist_H3_anti = {0};
    TFile * fData = new TFile(resultfileData,"recreate");
    TChain *fTreeDataH3= new TChain("He3TriTree/treeHe");
    for (Int_t i = 0; i < periods16.Length(); i++){
      fTreeDataHe3->Add(resultPath+ "/LHC16"  + periods16(i,1)+ "/AnalysisResults.root");
      }
    for (Int_t i = 0; i < periods17.Length(); i++){
      fTreeDataHe3->Add(resultPath+ "/LHC17"  + periods17(i,1)+ "/AnalysisResults.root");
      }
    for (Int_t i = 0; i < periods18.Length(); i++){
      fTreeDataHe3->Add(resultPath+ "/LHC18"  + periods18(i,1)+ "/AnalysisResults.root");
      }
    setTreeBranchHe3(fTreeDataHe3);
    histo_dist_He3 = new TH1D("histo_dist_he3", "", 300, 0 ,255);
    histo_dist_He3_anti = new TH1D("histo_dist_he3_anti", "", 300, 0 ,255);
    histo_dist_He3->SetStats(0);
    histo_dist_He3_anti->SetStats(0);
    Int_t nEntries = (Int_t)fTreeDataHe3->GetEntries();
	for (Int_t i=0; i<nEntries; i++) {
		if (i % (nEntries/2000) == 0) 
			cout << Form("\rreading data tree: %1.2f %%", 100. * i / (double) nEntries) << flush; 
		fTreeDataHe3->GetEntry(i);
		
		if (TMath::Abs(tY) > 0.5)	continue;	// set rapidity range

		int particle = 0;
		if (tCharge < 0) particle = 1;
        //if (tTOFSignalHe > 1.75 && tTOFSignalHe < 2.39 && tMCtrue > 0 && tPrimary > 0 && tTRDPid > 0 && tTRDPid <= 255){
        if (tMCtrue > 0 && tPrimary > 0 && tTRDPid > 0 && tTRDPid <= 255){
		    if (particle == 0){
                histo_dist_mc_He3->Fill(tTRDPid);
            }
            else if (particle == 1){
                histo_dist_mc_He3_anti->Fill(tTRDPid);
            }
            //histo_dist_mc_He3->Fill(tTRDPid);
		}		
	}
	cout << endl;
    histo_dist_mc_He3->Write(0, TObject::kOverwrite);
    histo_dist_mc_He3_anti->Write(0, TObject::kOverwrite);
    TChain *fTreeDataH3= new TChain("He3TriTree/treeTri");
    for (Int_t i = 0; i < periods16.Length(); i++){
      fTreeDataH3->Add(resultPathMC+ "/LHC16"  + periods16(i,1)+ "/AnalysisResults.root");
      }
    for (Int_t i = 0; i < periods17.Length(); i++){
      fTreeDataH3->Add(resultPathMC+ "/LHC17"  + periods17(i,1)+ "/AnalysisResults.root");
      }
    for (Int_t i = 0; i < periods18.Length(); i++){
      fTreeDataH3->Add(resultPathMC+ "/LHC18"  + periods18(i,1)+ "/AnalysisResults.root");
      }
    setTreeBranchH3(fTreeDataH3);
    histo_dist_mc_H3 = new TH1D("histo_dist_mc_h3", "", 300, 0 ,255);
    histo_dist_mc_H3_anti = new TH1D("histo_dist_mc_h3_anti", "", 300, 0 ,255);
    histo_dist_mc_H3->SetStats(0);
    histo_dist_mc_H3_anti->SetStats(0);
    Int_t nEntriesH3 = (Int_t)fTreeDataH3->GetEntries();
	for (Int_t i=0; i<nEntriesH3; i++) {
		if (i % (nEntriesH3/2000) == 0) 
			cout << Form("\rreading data tree: %1.2f %%", 100. * i / (double) nEntriesH3) << flush; 
		fTreeDataH3->GetEntry(i);
		
		if (TMath::Abs(tY) > 0.5)	continue;	// set rapidity range

		int particle = 0;
		if (tChargeTri < 0) particle = 1;
        //if (tTOFSignalHe > 1.75 && tTOFSignalHe < 2.39 && tMCtrue > 0 && tPrimary > 0 && tTRDPid > 0 && tTRDPid <= 255){
        if (tMCtrue > 0 && tPrimary > 0 && tTRDPid > 0 && tTRDPid <= 255){
		    if (particle == 0){
                histo_dist_mc_H3->Fill(tTRDPid);
            }
            else if (particle == 1){
                histo_dist_mc_H3_anti->Fill(tTRDPid);
            }
            //histo_dist_mc_He3->Fill(tTRDPid);
		}		
	}
	cout << endl;
    histo_dist_mc_H3->Write(0, TObject::kOverwrite);
    histo_dist_mc_H3_anti->Write(0, TObject::kOverwrite);
    f->Close();
}
*/
//________________________________________________________________________________________________________
void plot(){
    TH1D* histoPID_He3_MC[2] = {0};
    TCanvas* canPID_He3_MC = {0};
    TFile* file = new TFile(resultfile, "UPDATE");
    canPID_He3_MC = new TCanvas("canPID_He3_MC", "pid distribution He3", 1400,900);
    histoPID_He3_MC[0] = (TH1D*)file->Get("histo_dist_mc_he3");
    histoPID_He3_MC[1] = (TH1D*)file->Get("histo_dist_mc_he3_anti");
    if (!histoPID_He3_MC[0]) {
        std::cerr << "Error: Histograms not found in file!" << std::endl;
        file->Close();
        return;
    }
    histoPID_He3_MC[0]->SetLineColor(kBlue); 
    histoPID_He3_MC[1]->SetLineColor(kRed);  
    histoPID_He3_MC[0]->SetMarkerColor(kBlue); 
    histoPID_He3_MC[1]->SetMarkerColor(kRed);  
    histoPID_He3_MC[1]->SetMarkerStyle(8);
    histoPID_He3_MC[0]->SetMarkerStyle(8);

    //Fit:
    TF1 *fit0 = new TF1("fitfunc0", "gaus", 193, 255);
    fit0->SetParNames("Constant", "Mean", "Sigma");
    fit0->SetParameters(10000, histoPID_He3_MC[0]->GetMean(), histoPID_He3_MC[0]->GetRMS());
    fit0->SetLineColor(kBlue);
    histoPID_He3_MC[0]->Fit(fit0, "R");
    TF1 *fit1 = new TF1("fitfunc1", "gaus", 193, 255);
    fit1->SetParNames("Constant", "Mean", "Sigma");
    fit1->SetParameters(12000, histoPID_He3_MC[1]->GetMean(), histoPID_He3_MC[1]->GetRMS());
    fit1->SetLineColor(kRed);
    histoPID_He3_MC[1]->Fit(fit1, "R");


    histoPID_He3_MC[1]->Draw("P");
    histoPID_He3_MC[0]->Draw("PSame");
    TLegend* legendPID_He3_MC = new TLegend(0.15, 0.75, 0.35, 0.85);
    legendPID_He3_MC->SetEntrySeparation(.2);
    legendPID_He3_MC->SetFillStyle(0);
    legendPID_He3_MC->SetTextFont(43);
    legendPID_He3_MC->SetTextSize(20);
    legendPID_He3_MC->SetBorderSize(0);
    legendPID_He3_MC->AddEntry(histoPID_He3_MC[0], "{}^{3}He", "l");
    legendPID_He3_MC->AddEntry(histoPID_He3_MC[1], "{}^{3}#bar{He}", "l");
    legendPID_He3_MC->Draw("same");
    canPID_He3_MC->Update();
    canPID_He3_MC->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/He3/PID_distr_MC_He3.pdf");
    canPID_He3_MC->Close();
    //H3:
    TH1D* histoPID_H3_MC[2] = {0};
    TCanvas* canPID_H3_MC = {0};
    canPID_H3_MC = new TCanvas("canPID_H3_MC", "pid distribution H3", 1400,900);
    histoPID_H3_MC[0] = (TH1D*)file->Get("histo_dist_mc_h3");
    histoPID_H3_MC[1] = (TH1D*)file->Get("histo_dist_mc_h3_anti");
    if (!histoPID_H3_MC[0]) {
        std::cerr << "Error: Histograms not found in file!" << std::endl;
        file->Close();
        return;
    }
    histoPID_H3_MC[0]->SetLineColor(kBlue); 
    histoPID_H3_MC[1]->SetLineColor(kRed);  
    histoPID_H3_MC[0]->SetMarkerColor(kBlue); 
    histoPID_H3_MC[1]->SetMarkerColor(kRed);  
    histoPID_H3_MC[1]->SetMarkerStyle(8);
    histoPID_H3_MC[0]->SetMarkerStyle(8);

    auto crystalBallFunc = [](double *x, double *par) {
        return par[4] * ROOT::Math::crystalball_function(x[0], par[0], par[1], par[2], par[3]);
    };

    //Fit:
    TF1 *fit0H3 = new TF1("fitfunc0H3", crystalBallFunc, 0, 255, 5);
    //fit0H3->SetParNames("Constant", "Mean", "Sigma");
    fit0H3->SetParNames("Alpha", "n", "Mean", "Sigma", "Constant");
    //fit0H3->SetParameters(10000, histoPID_H3_MC[0]->GetMean(), histoPID_H3_MC[0]->GetRMS());
    fit0H3->SetParameters(1.5, 3.0, 100, 25, 4500);
    fit0H3->SetLineColor(kBlue);
    histoPID_H3_MC[0]->Fit(fit0H3, "R");
    TF1 *fit1H3 = new TF1("fitfunc1H3", crystalBallFunc, 0, 255, 5);    //fit1H3->SetParNames("Constant", "Mean", "Sigma");
    fit1H3->SetParNames("Alpha", "n", "Mean", "Sigma", "Constant");
    //fit1H3->SetParameters(10000, histoPID_H3_MC[1]->GetMean(), histoPID_H3_MC[1]->GetRMS());
    fit1H3->SetParameters(1.5, 3.0, 110, 25, 4700);
    fit1H3->SetLineColor(kRed);
    fit1H3->Print();
    histoPID_H3_MC[1]->Fit(fit1H3, "R");


    histoPID_H3_MC[1]->Draw("P");
    histoPID_H3_MC[0]->Draw("PSame");
    TLegend* legendPID_H3_MC = new TLegend(0.15, 0.75, 0.35, 0.85);
    legendPID_H3_MC->SetEntrySeparation(.2);
    legendPID_H3_MC->SetFillStyle(0);
    legendPID_H3_MC->SetTextFont(43);
    legendPID_H3_MC->SetTextSize(20);
    legendPID_H3_MC->SetBorderSize(0);
    legendPID_H3_MC->AddEntry(histoPID_H3_MC[0], "{}^{3}H", "l");
    legendPID_H3_MC->AddEntry(histoPID_H3_MC[1], "{}^{3}#bar{H}", "l");
    legendPID_H3_MC->Draw("same");
    canPID_H3_MC->Update();
    canPID_H3_MC->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/H3/PID_distr_MC_H3.pdf");
    file->Close();
    canPID_H3_MC->Close();
}
