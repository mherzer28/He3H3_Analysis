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
TString resultPath = "/Volumes/MyPassport/pass2/HeTri_pass2/Data";
TString resultPathH3 = "/Users/matthias/alice/root_results/H3";
TString resultfile = "/Users/matthias/alice/Master/Makros/Rootfiles/PID.root";
TString resultfileData = "/Users/matthias/alice/Master/Makros/Rootfiles/PID_data.root";

enum cutNames             {DcaXY, DcaZ, TriTPCnSigma, TPCnCls, TPCchi2, TPCrefit, Kink, TRDnTracklets, ITSnCluster, ITSrefit};
const double cutConf[10] = {0.15,  0.15, 	 2.0, 		    120,      2,       1,      1,         1,           1,           0};
const double cutConfHe[8] = {0.15, 0.15,   3.0,         70,       2,       1,      1,		1};
//________________________________________________________________________________________________________
void PID_distribution(){
    PID_MC();
    PID_Data();
    plot();
    plot_Data();
}
//________________________________________________________________________________________________________
bool Cut(int mode) {
  if (mode == 1){
		if (TMath::Abs(tDcaXY) > cutConf[0]) return false;
		if (TMath::Abs(tDcaZ) > cutConf[1]) return false;
		if (TMath::Abs(tTriSigma) > cutConf[2]) return false;
		if (tnTPCcluster < cutConf[3]) return false;
		if (tTPCchi2 > cutConf[4]) return false;
		if (!tTPCrefit && cutConf[5]) return false;
		if (tKink && cutConf[6]) return false; 
    if (tTRDnTracklets < cutConf[7]) return false;
    //if (tnITScluster < cutConf[8]) return false;
    //if (!tITSrefit && cutConf[9]) return false;
		return true;
  }
  if (mode == 2){
    if (TMath::Abs(tDcaXY) > cutConfHe[0]) return false;
		if (TMath::Abs(tDcaZ) > cutConfHe[1]) return false;
		if (TMath::Abs(tHeSigma) > cutConfHe[2]) return false;
		if (tnTPCcluster < cutConfHe[3]) return false;
		if (tTPCchi2 > cutConfHe[4]) return false;
		if (!tTPCrefit && cutConfHe[5]) return false;
		if (tKink && cutConfHe[6]) return false;
		//if (tTRDnTracklets < cutConfHe[7]) return false;
    return true;
  }
    return false;
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
	fTree->SetBranchAddress("tTRDPID0"         , &tTRDPID0         );
	fTree->SetBranchAddress("tTRDPID1"         , &tTRDPID1         );
	fTree->SetBranchAddress("tTRDPID2"         , &tTRDPID2         );
	fTree->SetBranchAddress("tTRDPID3"         , &tTRDPID3         );
	fTree->SetBranchAddress("tTRDPID4"         , &tTRDPID4         );
	fTree->SetBranchAddress("tTRDPID5"         , &tTRDPID5         );
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
double crystalball_function(double x, double alpha, double n, double sigma, double mean) {
  // evaluate the crystal ball function
  if (sigma < 0.)     return 0.;
  double z = (x - mean)/sigma; 
  if (alpha < 0) z = -z; 
  double abs_alpha = std::abs(alpha);
  // double C = n/abs_alpha * 1./(n-1.) * std::exp(-alpha*alpha/2.);
  // double D = std::sqrt(M_PI/2.)*(1.+ROOT::Math::erf(abs_alpha/std::sqrt(2.)));
  // double N = 1./(sigma*(C+D));
  if (z  > - abs_alpha)
    return std::exp(- 0.5 * z * z);
  else {
    //double A = std::pow(n/abs_alpha,n) * std::exp(-0.5*abs_alpha*abs_alpha);
    double nDivAlpha = n/abs_alpha;
    double AA =  std::exp(-0.5*abs_alpha*abs_alpha);
    double B = nDivAlpha -abs_alpha;
    double arg = nDivAlpha/(B-z);
    return AA * std::pow(arg,n);
  }
}

double crystalball_function(const double *x, const double *p) {
  // if ((!x) || (!p)) return 0.; // just a precaution
  // [Constant] * ROOT::Math::crystalball_function(x, [Alpha], [N], [Sigma], [Mean])
  return (p[0] * crystalball_function(x[0], p[3], p[4], p[2], p[1]));
}
Double_t skewedGaussian(Double_t *x, Double_t *par) {
    // par[0] = Normalization
    // par[1] = Mean
    // par[2] = Sigma
    // par[3] = Skewness
    Double_t t = (x[0] - par[1]) / par[2];
    return par[0] * TMath::Exp(-0.5 * t * t) * (1 + TMath::Erf(par[3] * t / TMath::Sqrt(2)));
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
  int modeHe = 2;
	for (Int_t i=0; i<nEntries; i++) {
		if (i % (nEntries/2000) == 0) 
			cout << Form("\rreading data tree: %1.2f %%", 100. * i / (double) nEntries) << flush; 
		fTreeDataHe3->GetEntry(i);
		
		if (TMath::Abs(tY) > 0.5)	continue;	// set rapidity range
        //if (!tTrigHNU && !tTrigHQU) continue;	//Nuclei Trigger
		int particle = 0;
		if (tCharge < 0) particle = 1;
      if (tTOFSignalHe > 1.72 && tTOFSignalHe < 2.50 && tMCtrue > 0 && tPrimary > 0 && tTRDPid > 0 && tTRDPid <= 255){
        //if (tMCtrue > 0 && tPrimary > 0 && tTRDPid > 0 && tTRDPid <= 255);
        if (Cut(modeHe)){
		      if (particle == 0){
            histo_dist_mc_He3->Fill(tTRDPid);
          }
          else if (particle == 1){
            histo_dist_mc_He3_anti->Fill(tTRDPid);
          } 
        }  //histo_dist_mc_He3->Fill(tTRDPid);
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
  int mode = 1;
	for (Int_t i=0; i<nEntriesH3; i++) {
		if (i % (nEntriesH3/2000) == 0) 
			cout << Form("\rreading data tree: %1.2f %%", 100. * i / (double) nEntriesH3) << flush; 
		fTreeDataH3->GetEntry(i);
		
		if (TMath::Abs(tY) > 0.5)	continue;	// set rapidity range
		int particle = 0;
		if (tChargeTri < 0) particle = 1;
      if (tTOFSignalTri > 7.04 && tTOFSignalTri < 8.91 && tMCtrue > 0 && tPrimary > 0 && tTRDPid > 0 && tTRDPid <= 255){
        //if (tMCtrue > 0 && tPrimary > 0 && tTRDPid > 0 && tTRDPid <= 255){
        if (Cut(mode)){
		      if (particle == 0){
                histo_dist_mc_H3->Fill(tTRDPid);
            }
            else if (particle == 1){
                histo_dist_mc_H3_anti->Fill(tTRDPid);
            }
            //histo_dist_mc_He3->Fill(tTRDPid);
        }
      }		
	}
	cout << endl;
    histo_dist_mc_H3->Write(0, TObject::kOverwrite);
    histo_dist_mc_H3_anti->Write(0, TObject::kOverwrite);
    f->Close();
}
//________________________________________________________________________________________________________
void PID_Data(){
  TH1D* histo_dist_He3 = {0};
  TH1D* histo_dist_He3_anti = {0};
  TH1D* histo_dist_H3 = {0};
  TH1D* histo_dist_H3_anti = {0};
  TFile * fData = new TFile(resultfileData,"recreate");
  int mode = 2;
  
	TChain *fTreeDataHe3= new TChain("He3TriTree/treeHe");
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
  histo_dist_He3 = new TH1D("histo_dist_he3", "", 32, 0 ,255);
  histo_dist_He3_anti = new TH1D("histo_dist_he3_anti", "", 32, 0 ,255);
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
    if (tTOFSignalHe > 1.72 && tTOFSignalHe < 2.50 && tTRDPid > 0 && tTRDPid <= 255){
      if (Cut(mode)) {
		    if (particle == 0){
          histo_dist_He3->Fill(tTRDPid);
        }
        else if (particle == 1){
          histo_dist_He3_anti->Fill(tTRDPid);
        }
      }  //histo_dist_mc_He3->Fill(tTRDPid);
		}		
	}
	cout << endl;
  histo_dist_He3->Write(0, TObject::kOverwrite);
  histo_dist_He3_anti->Write(0, TObject::kOverwrite);
  TChain *fTreeDataH3 = new TChain("treeTriHM");
	fTreeDataH3->Add(resultPathH3 + "/Analysis_merged_all.root");
  setTreeBranchH3(fTreeDataH3);
  histo_dist_H3 = new TH1D("histo_dist_h3", "", 11, 0 ,255); //18
  histo_dist_H3_anti = new TH1D("histo_dist_h3_anti", "", 11, 0 ,255); //18
  histo_dist_H3->SetStats(0);
  histo_dist_H3_anti->SetStats(0);
  Int_t nEntriesH3 = (Int_t)fTreeDataH3->GetEntries();
  mode = 1;
	for (Int_t i=0; i<nEntriesH3; i++) {
		if (i % (nEntriesH3/2000) == 0) 
			cout << Form("\rreading data tree: %1.2f %%", 100. * i / (double) nEntriesH3) << flush; 
		fTreeDataH3->GetEntry(i);
		
		if (TMath::Abs(tY) > 0.5)	continue;	// set rapidity range

		int particle = 0;
		if (tChargeTri < 0) particle = 1;
    if (tTOFSignalTri > 7.04 && tTOFSignalTri < 8.91 && tTRDPid > 0 && tTRDPid <= 255){
		  if (Cut(mode)){
        if(particle == 0){
          histo_dist_H3->Fill(tTRDPid);
        }
        else if (particle == 1){
          histo_dist_H3_anti->Fill(tTRDPid);
        }
      }//histo_dist_mc_He3->Fill(tTRDPid);
		}		
	}
	cout << endl;
  histo_dist_H3->Write(0, TObject::kOverwrite);
  histo_dist_H3_anti->Write(0, TObject::kOverwrite);
  fData->Close();
}
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
  histoPID_He3_MC[0]->GetXaxis()->SetTitle("TRD PID [a.u.]");
  histoPID_He3_MC[1]->GetXaxis()->SetTitle("TRD PID [a.u.]");
  histoPID_He3_MC[0]->GetYaxis()->SetTitle("Counts");
  histoPID_He3_MC[1]->GetYaxis()->SetTitle("Counts");
  //Fit:
  TF1 *fit0 = new TF1("fitfunc0", crystalball_function, 140, 255, 5);
  fit0->SetParNames("Constant", "Mean", "Sigma", "Alpha", "N");
  Double_t max0 = histoPID_He3_MC[0]->GetMaximum();
  Double_t mean0_1 = histoPID_He3_MC[0]->GetMean();
  Double_t rms0 = histoPID_He3_MC[0]->GetRMS();
  std::cout << max0 << " " << mean0_1 << " " << rms0 << " " << endl; 
  fit0->SetParameters(10000, 230, 20, 1.0, 2.0);  
  //fit0->SetParameters(max0, mean0_1, rms0, 1.0, 2.0); 
  fit0->SetLineColor(kBlue);
  for (int i = 0; i < 10; i++) {
  histoPID_He3_MC[0]->Fit(fit0, "R+ME");
  fit0->SetParameters(fit0->GetParameters());
  }
  TF1 *fit1 = new TF1("fitfunc1", crystalball_function, 140, 255, 5);
  fit1->SetParNames("Constant", "Mean", "Sigma", "Alpha", "N");
  fit1->SetParameters(histoPID_He3_MC[1]->GetMaximum(), 
                    histoPID_He3_MC[1]->GetMean(), 
                    histoPID_He3_MC[1]->GetRMS(),
                    1, 2);
  fit1->SetLineColor(kRed);
  for (int i = 0; i < 10; i++) {
  histoPID_He3_MC[1]->Fit(fit1, "R+ME");
  fit1->SetParameters(fit1->GetParameters());
  }
  histoPID_He3_MC[0]->GetListOfFunctions()->Clear();
  histoPID_He3_MC[0]->Fit(fit0, "R+ME+");
  histoPID_He3_MC[1]->GetListOfFunctions()->Clear();
  histoPID_He3_MC[1]->Fit(fit1, "R+ME+");

  double chi2He = fit0->GetChisquare();
  int ndfHe = fit0->GetNDF();
  double pvalueHe = TMath::Prob(chi2He, ndfHe);
  std::cout << "Chi2/ndf = " << chi2He/ndfHe << ", p-value = " << pvalueHe << std::endl;

  double chi2He_2 = fit1->GetChisquare();
  int ndfHe_2 = fit1->GetNDF();
  double pvalueHe_2 = TMath::Prob(chi2He_2, ndfHe_2);
  std::cout << "Chi2/ndf = " << chi2He_2/ndfHe_2 << ", p-value = " << pvalueHe_2 << std::endl;
  double mean0 = fit0->GetParameter(1);
  double meanError0 = fit0->GetParError(1);
  double mean1 = fit1->GetParameter(1);
  double meanError1 = fit1->GetParError(1);
  histoPID_He3_MC[1]->Draw("P");
  histoPID_He3_MC[0]->Draw("PSame");
  fit0->Draw("Same");
  fit1->Draw("Same");

  TLegend* legendPID_He3_MC = new TLegend(0.15, 0.65, 0.45, 0.85); 
  legendPID_He3_MC->SetEntrySeparation(.21);
  legendPID_He3_MC->SetFillStyle(0);
  legendPID_He3_MC->SetTextFont(43);
  legendPID_He3_MC->SetTextSize(26);
  legendPID_He3_MC->SetBorderSize(0);
  legendPID_He3_MC->AddEntry(histoPID_He3_MC[0], "{}^{3}He", "l");
  legendPID_He3_MC->AddEntry((TObject*)0, Form("mean: %.2f #pm %.2f", mean0, meanError0), "");
  legendPID_He3_MC->AddEntry(histoPID_He3_MC[1], "{}^{3}#bar{He}", "l");
  legendPID_He3_MC->AddEntry((TObject*)0, Form("mean: %.2f #pm %.2f", mean1, meanError1), "");
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
  histoPID_H3_MC[0]->GetXaxis()->SetTitle("TRD PID [a.u.]");
  histoPID_H3_MC[1]->GetXaxis()->SetTitle("TRD PID [a.u.]");
  histoPID_H3_MC[0]->GetYaxis()->SetTitle("Counts");
  histoPID_H3_MC[1]->GetYaxis()->SetTitle("Counts");

  //Fit:
  TF1 *fit0H3 = new TF1("fitfunc0H3", crystalball_function, 30, 160, 5);
  fit0H3->SetParNames("Constant", "Mean", "Sigma", "Alpha", "N");
  fit0H3->SetParameters(histoPID_H3_MC[0]->GetMaximum(), 
                      histoPID_H3_MC[0]->GetMean(), 
                      histoPID_H3_MC[0]->GetRMS(),
                      -1, 2);
  fit0H3->SetLineColor(kBlue);
  fit0H3->SetParLimits(0, 0, 1e5);  // Constant
  fit0H3->SetParLimits(1, 50, 150); // Mean
  fit0H3->SetParLimits(2, 1, 50);   // Sigma
  fit0H3->SetParLimits(3, -10, -0.1); // Alpha
  fit0H3->SetParLimits(4, 0.1, 10); // N
  for (int i = 0; i < 20; i++) {
  histoPID_H3_MC[0]->Fit(fit0H3, "R+SIME");
  fit0H3->SetParameters(fit0H3->GetParameters());
  }
  histoPID_H3_MC[0]->Fit(fit0H3, "R+SIME+");
  TF1 *fit1H3 = new TF1("fitfunc1H3", crystalball_function, 30, 160, 5);    
  fit1H3->SetParNames("Constant", "Mean", "Sigma", "Alpha", "N");
  fit1H3->SetParameters(histoPID_H3_MC[1]->GetMaximum(), 
                      histoPID_H3_MC[1]->GetMean(), 
                      histoPID_H3_MC[1]->GetRMS(),
                      -1, 2);
  fit1H3->SetLineColor(kRed);
  fit1H3->SetParLimits(0, 0, 1e5);  // Constant
  fit1H3->SetParLimits(1, 50, 150); // Mean
  fit1H3->SetParLimits(2, 1, 50);   // Sigma
  fit1H3->SetParLimits(3, -10, -0.1); // Alpha
  fit1H3->SetParLimits(4, 0.1, 10); // N
  fit1H3->Print();
  for (int i = 0; i < 10; i++) {
  histoPID_H3_MC[1]->Fit(fit1H3, "R+SIME");
  fit1H3->SetParameters(fit1H3->GetParameters());
  }
  histoPID_H3_MC[1]->Fit(fit1H3, "R+SIME+");

  histoPID_H3_MC[0]->GetListOfFunctions()->Clear();
  histoPID_H3_MC[0]->Fit(fit0H3, "R+SIME+");

  histoPID_H3_MC[1]->GetListOfFunctions()->Clear();
  histoPID_H3_MC[1]->Fit(fit1H3, "R+SIME+");

  double chi2 = fit0H3->GetChisquare();
  int ndf = fit0H3->GetNDF();
  double pvalue = TMath::Prob(chi2, ndf);
  std::cout << "Chi2/ndf = " << chi2/ndf << ", p-value = " << pvalue << std::endl;

  double chi2_2 = fit1H3->GetChisquare();
  int ndf_2 = fit1H3->GetNDF();
  double pvalue_2 = TMath::Prob(chi2_2, ndf_2);
  std::cout << "Chi2/ndf = " << chi2_2/ndf_2 << ", p-value = " << pvalue_2 << std::endl;
  double mean0_H3 = fit0H3->GetParameter(1);
  double meanError0_H3 = fit0H3->GetParError(1);
  double mean1_H3 = fit1H3->GetParameter(1);
  double meanError1_H3 = fit1H3->GetParError(1);
  histoPID_H3_MC[1]->Draw("P");
  histoPID_H3_MC[0]->Draw("PSame");

  fit0H3->Draw("Same");
  fit1H3->Draw("Same");

  TLegend* legendPID_H3_MC = new TLegend(0.65, 0.65, 0.85, 0.85); // Adjusted position for more space
  legendPID_H3_MC->SetEntrySeparation(.21);
  legendPID_H3_MC->SetFillStyle(0);
  legendPID_H3_MC->SetTextFont(43);
  legendPID_H3_MC->SetTextSize(26);
  legendPID_H3_MC->SetBorderSize(0);
  legendPID_H3_MC->AddEntry(histoPID_H3_MC[0], "{}^{3}H", "l");
  legendPID_H3_MC->AddEntry((TObject*)0, Form("mean: %.2f #pm %.2f", mean0_H3, meanError0_H3), "");
  legendPID_H3_MC->AddEntry(histoPID_H3_MC[1], "{}^{3}#bar{H}", "l");
  legendPID_H3_MC->AddEntry((TObject*)0, Form("mean: %.2f #pm %.2f", mean1_H3, meanError1_H3), "");
  legendPID_H3_MC->Draw("same");

  canPID_H3_MC->Update();
  canPID_H3_MC->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/H3/PID_distr_MC_H3.pdf");
  histoPID_He3_MC[1]->Write(0, TObject::kOverwrite);	
  histoPID_He3_MC[0]->Write(0, TObject::kOverwrite);	
  histoPID_He3_MC[1]->Write(0, TObject::kOverwrite);	
  histoPID_He3_MC[0]->Write(0, TObject::kOverwrite);	
  file->Close();
  canPID_H3_MC->Close();
}
//________________________________________________________________________________________________________
void plot_Data(){
  TH1D* histoPID_He3[2] = {0};
  TCanvas* canPID_He3 = {0};
  TFile* file = new TFile(resultfileData, "UPDATE");
  canPID_He3 = new TCanvas("canPID_He3", "pid distribution He3 data", 1400,900);
  histoPID_He3[0] = (TH1D*)file->Get("histo_dist_he3");
  histoPID_He3[1] = (TH1D*)file->Get("histo_dist_he3_anti");
  if (!histoPID_He3[0]) {
      std::cerr << "Error: Histograms not found in file!" << std::endl;
      file->Close();
      return;
  }
  histoPID_He3[0]->SetLineColor(kBlue); 
  histoPID_He3[1]->SetLineColor(kRed);  
  histoPID_He3[0]->SetMarkerColor(kBlue); 
  histoPID_He3[1]->SetMarkerColor(kRed);  
  histoPID_He3[1]->SetMarkerStyle(8);
  histoPID_He3[0]->SetMarkerStyle(8);
  histoPID_He3[0]->GetXaxis()->SetTitle("TRD PID [a.u.]");
  histoPID_He3[1]->GetXaxis()->SetTitle("TRD PID [a.u.]");
  histoPID_He3[0]->GetYaxis()->SetTitle("Counts");
  histoPID_He3[1]->GetYaxis()->SetTitle("Counts");
  //Fit:
  TF1 *fit0 = new TF1("fitfunc0", crystalball_function, 170, 255, 5);
  fit0->SetParNames("Constant", "Mean", "Sigma", "Alpha", "N");
  Double_t max0 = histoPID_He3[0]->GetMaximum();
  Double_t mean0_1 = histoPID_He3[0]->GetMean();
  Double_t rms0 = histoPID_He3[0]->GetRMS();
  std::cout << max0 << " " << mean0_1 << " " << rms0 << " " << endl; 
  fit0->SetParameters(105, 214, 49, 1.0, 2.0);  // Initial parameters
  //fit0->SetParameters(max0, mean0_1, rms0, 1.0, 2.0);  // Initial parameters
  fit0->SetLineColor(kBlue);
  for (int i = 0; i < 10; i++) {
  histoPID_He3[0]->Fit(fit0, "R+ME");
  fit0->SetParameters(fit0->GetParameters());
  }
  TF1 *fit1 = new TF1("fitfunc1", crystalball_function, 170, 255, 5);
  fit1->SetParNames("Constant", "Mean", "Sigma", "Alpha", "N");
  fit1->SetParameters(histoPID_He3[1]->GetMaximum(), 
                    histoPID_He3[1]->GetMean(), 
                    histoPID_He3[1]->GetRMS(),
                    1, 2);
  fit1->SetLineColor(kRed);
  for (int i = 0; i < 10; i++) {
  histoPID_He3[1]->Fit(fit1, "R+ME");
  fit1->SetParameters(fit1->GetParameters());
  }
  histoPID_He3[0]->GetListOfFunctions()->Clear();
  histoPID_He3[0]->Fit(fit0, "R+ME+");
  histoPID_He3[1]->GetListOfFunctions()->Clear();
  histoPID_He3[1]->Fit(fit1, "R+ME+");

  double chi2He = fit0->GetChisquare();
  int ndfHe = fit0->GetNDF();
  double pvalueHe = TMath::Prob(chi2He, ndfHe);
  std::cout << "Chi2/ndf = " << chi2He/ndfHe << ", p-value = " << pvalueHe << std::endl;

  double chi2He_2 = fit1->GetChisquare();
  int ndfHe_2 = fit1->GetNDF();
  double pvalueHe_2 = TMath::Prob(chi2He_2, ndfHe_2);
  std::cout << "Chi2/ndf = " << chi2He_2/ndfHe_2 << ", p-value = " << pvalueHe_2 << std::endl;
  double mean0 = fit0->GetParameter(1);
  double meanError0 = fit0->GetParError(1);
  double mean1 = fit1->GetParameter(1);
  double meanError1 = fit1->GetParError(1);
  histoPID_He3[1]->Draw("PE");
  histoPID_He3[0]->Draw("PESame");
  fit0->Draw("Same");
  fit1->Draw("Same");

  TLegend* legendPID_He3= new TLegend(0.15, 0.65, 0.45, 0.85); // Adjusted position for more space
  legendPID_He3->SetEntrySeparation(.21);
  legendPID_He3->SetFillStyle(0);
  legendPID_He3->SetTextFont(43);
  legendPID_He3->SetTextSize(26);
  legendPID_He3->SetBorderSize(0);
  legendPID_He3->AddEntry(histoPID_He3[0], "{}^{3}He", "l");
  //legendPID_He3->AddEntry((TObject*)0, Form("mean: %.2f #pm %.2f", mean0, meanError0), "");
  legendPID_He3->AddEntry(histoPID_He3[1], "{}^{3}#bar{He}", "l");
  //legendPID_He3->AddEntry((TObject*)0, Form("mean: %.2f #pm %.2f", mean1, meanError1), "");
  legendPID_He3->Draw("same");

  canPID_He3->Update();
  canPID_He3->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/He3/PID_distr_He3.pdf");
  canPID_He3->Close();
  //H3:
  TH1D* histoPID_H3[2] = {0};
  TCanvas* canPID_H3 = {0};
  canPID_H3 = new TCanvas("canPID_H3", "pid distribution H3 data", 1400,900);
  histoPID_H3[0] = (TH1D*)file->Get("histo_dist_h3");
  histoPID_H3[1] = (TH1D*)file->Get("histo_dist_h3_anti");
  if (!histoPID_H3[0]) {
    std::cerr << "Error: Histograms not found in file!" << std::endl;
    file->Close();
    return;
  }
  histoPID_H3[0]->SetLineColor(kBlue); 
  histoPID_H3[1]->SetLineColor(kRed);  
  histoPID_H3[0]->SetMarkerColor(kBlue); 
  histoPID_H3[1]->SetMarkerColor(kRed);  
  histoPID_H3[1]->SetMarkerStyle(8);
  histoPID_H3[0]->SetMarkerStyle(8);
  histoPID_H3[0]->GetXaxis()->SetTitle("TRD PID [a.u.]");
  histoPID_H3[1]->GetXaxis()->SetTitle("TRD PID [a.u.]");
  histoPID_H3[0]->GetYaxis()->SetTitle("Counts");
  histoPID_H3[1]->GetYaxis()->SetTitle("Counts");

  //Fit:
  TF1 *fit0H3 = new TF1("fitfunc0H3", crystalball_function,   0, 255, 5);
  fit0H3->SetParNames("Constant", "Mean", "Sigma", "Alpha", "N");
  fit0H3->SetParameters(histoPID_H3[0]->GetMaximum(), 
                      60, 
                      histoPID_H3[0]->GetRMS(),
                      -1, 2);
  fit0H3->SetLineColor(kBlue);
  fit0H3->SetParLimits(0, 0, 1e5);  // Constant
  fit0H3->SetParLimits(1, 40, 80); // Mean
  fit0H3->SetParLimits(2, 1, 50);   // Sigma
  fit0H3->SetParLimits(3, -10, -0.1); // Alpha
  fit0H3->SetParLimits(4, 0.1, 10); // N
  for (int i = 0; i < 20; i++) {
  histoPID_H3[0]->Fit(fit0H3, "R+SIME");
  fit0H3->SetParameters(fit0H3->GetParameters());
  }
  histoPID_H3[0]->Fit(fit0H3, "R+SIME+");
  TF1 *fit1H3 = new TF1("fitfunc1H3", crystalball_function, 0, 255, 5);    
  fit1H3->SetParNames("Constant", "Mean", "Sigma", "Alpha", "N");
  fit1H3->SetParameters(histoPID_H3[1]->GetMaximum(), 
                      60, 
                      histoPID_H3[1]->GetRMS(),
                      -1, 2);
  fit1H3->SetLineColor(kRed);
  fit1H3->SetParLimits(0, 3000, 3400);  // Constant
  fit1H3->SetParLimits(1, 58, 64); // Mean
  fit1H3->SetParLimits(2, 1, 50);   // Sigma
  fit1H3->SetParLimits(3, -10, -0.1); // Alpha
  fit1H3->SetParLimits(4, 0.1, 10); // N
  //fit1H3->FixParameter(1, 63);
  fit1H3->Print();
  for (int i = 0; i < 10; i++) {
  histoPID_H3[1]->Fit(fit1H3, "R+SIME");
  fit1H3->SetParameters(fit1H3->GetParameters());
  }
  histoPID_H3[1]->Fit(fit1H3, "R+SIME+");

  histoPID_H3[0]->GetListOfFunctions()->Clear();
  histoPID_H3[0]->Fit(fit0H3, "R+SIME+");

  histoPID_H3[1]->GetListOfFunctions()->Clear();
  histoPID_H3[1]->Fit(fit1H3, "R+SIME+");

  double chi2 = fit0H3->GetChisquare();
  int ndf = fit0H3->GetNDF();
  double pvalue = TMath::Prob(chi2, ndf);
  std::cout << "Chi2/ndf = " << chi2/ndf << ", p-value = " << pvalue << std::endl;

  double chi2_2 = fit1H3->GetChisquare();
  int ndf_2 = fit1H3->GetNDF();
  double pvalue_2 = TMath::Prob(chi2_2, ndf_2);
  std::cout << "Chi2/ndf = " << chi2_2/ndf_2 << ", p-value = " << pvalue_2 << std::endl;
  double mean0_H3 = fit0H3->GetParameter(1);
  double meanError0_H3 = fit0H3->GetParError(1);
  double mean1_H3 = fit1H3->GetParameter(1);
  double meanError1_H3 = fit1H3->GetParError(1);
  histoPID_H3[1]->Draw("PE");
  histoPID_H3[0]->Draw("PESame");

  fit0H3->Draw("Same");
  fit1H3->Draw("Same");

  TLegend* legendPID_H3 = new TLegend(0.65, 0.65, 0.85, 0.85); // Adjusted position for more space
  legendPID_H3->SetEntrySeparation(.21);
  legendPID_H3->SetFillStyle(0);
  legendPID_H3->SetTextFont(43);
  legendPID_H3->SetTextSize(26);
  legendPID_H3->SetBorderSize(0);
  legendPID_H3->AddEntry(histoPID_H3[0], "{}^{3}H", "l");
  legendPID_H3->AddEntry((TObject*)0, Form("mean: %.2f #pm %.2f", mean0_H3, meanError0_H3), "");
  legendPID_H3->AddEntry(histoPID_H3[1], "{}^{3}#bar{H}", "l");
  legendPID_H3->AddEntry((TObject*)0, Form("mean: %.2f #pm %.2f", mean1_H3, meanError1_H3), "");
  legendPID_H3->Draw("same");

  canPID_H3->Update();
  canPID_H3->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/H3/PID_distr_H3.pdf");
  histoPID_He3[1]->Write(0, TObject::kOverwrite);	
  histoPID_He3[0]->Write(0, TObject::kOverwrite);	
  histoPID_H3[1]->Write(0, TObject::kOverwrite);	
  histoPID_H3[0]->Write(0, TObject::kOverwrite);	
  file->Close();
  canPID_H3->Close();
}
//________________________________________________________________________________________________________