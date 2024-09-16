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
#include <vector>
#include "H3_readData.h"

TString trigger = "HQU"; // "HNU" or "HM" or "HNU&HQU" or "HQU"
TString resultPath = "/Users/matthias/alice/root_results/H3";
const Int_t nPtBins = 3;
TString periods16 = "deghijklop";
TString periods17 = "cefghijklmor"; //klmor + cefghij
TString periods18 = "bdefghilmnop";
const Int_t nParticles = 3;
const TString particleNames[] = {"{}^{3}H","{}^{3}#bar{H}","{}^{3}H+{}^{3}#bar{H}"};
const TString particleShortNames[] = {"H3", "AntiH3", "both"};
int particleColors[] = {kBlue, kRed, kBlack};
const Double_t H3Mass = 2.80892f;
TString Folder = "result";
TString rootFilePath = Folder;
std::vector<double> cutConf(10, 0); // Changed to vector
const double cutYTri = 0.5; //set rapidity range: -0.5 - 0.5
TString rootfile;
std::vector<std::vector<int>> tofBinsH3(3, std::vector<int>(100, 0)); // Changed to vector
std::vector<double> ptBins; // Changed to vector
//________________________________________________________________________________________________________
void H3_readData(){
    readDataH3();
}
//_________________________________________________________________________________________________________
bool Cut() {
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
//_________________________________________________________________________________________________________
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
//_________________________________________________________________________________________________________
void readDataH3(){
	if (trigger == "HNU") {
        rootfile = "/Users/matthias/alice/Master/Makros/Rootfiles/DataH3_HNU.root";
        tofBinsH3[0] = {10, 10, 10, 10, 25, 25, 25, 35, 25}; // TRD H3 TRD
        tofBinsH3[1] = {10, 10, 10, 10, 25, 25, 25, 35, 25}; // TRD Anti H3
        tofBinsH3[2] = {10, 10, 10, 10, 25, 25, 25, 35, 25}; // Both
        ptBins = {1., 1.3, 1.6}; // HNU
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
    }   
	else {
        rootfile = "/Users/matthias/alice/Master/Makros/Rootfiles/DataH3.root";
        tofBinsH3[0] = {30, 30, 30, 30, 30, 40, 25, 35, 25}; // TRD H3 HM
        tofBinsH3[1] = {30, 30, 30, 30, 30, 40, 25, 35, 25}; // TRD Anti H3
        tofBinsH3[2] = {30, 30, 30, 30, 30, 40, 25, 35, 25}; // TRD Both
        ptBins = {1.4, 1.8, 2.2, 2.6};
        cutConf = {0.15,  0.15,  2.0,    120,    2,     1,      1,       1,        0,       0};
    }
	TCanvas *c1;
	TChain *fTreeData = new TChain("treeTriHM");
	//TChain *fTreeData = new TChain("He3TriTree/treeTri");
	fTreeData->Add(resultPath + "/Analysis_merged_all.root");

	/*for (Int_t i = 0; i < periods16.Length(); i++){
		fTreeData->Add(resultPath+ "/Data/LHC16"  + periods16(i,1)+ "/AnalysisResults.root");
		}
	for (Int_t i = 0; i < periods17.Length(); i++){
		fTreeData->Add(resultPath+ "/Data/LHC17"  + periods17(i,1)+ "/AnalysisResults.root");
		}
		
	for (Int_t i = 0; i < periods18.Length(); i++){
		fTreeData->Add(resultPath+ "/Data/LHC18"  + periods18(i,1)+ "/AnalysisResults.root");
		}
	*/
	setTreeBranchH3(fTreeData);
	
	
	gStyle->SetOptFit(111);
	gStyle->SetOptStat("ne");
	TH1D * histPtH3[nParticles][nPtBins] = {0};
	for (int particle = 0; particle < nParticles; particle++){
		for (int pt = 0; pt < nPtBins; pt++){
		TString name = Form("histPtH3%02d%02d", particle, pt);
		TString title = Form("%1.2f < p_{T} < %1.2f", ptBins[pt], ptBins[pt+1]);
		histPtH3[particle][pt] = new  TH1D(name , title , tofBinsH3[particle][pt] , 5, 11);
		histPtH3[particle][pt]->GetXaxis()->SetTitle("m^{2}/z^{2} (GeV^{2}/#it{c}^{4})");
		int binWidth = histPtH3[particle][pt]->GetXaxis()->GetBinWidth(1)*1000;
		histPtH3[particle][pt]->GetYaxis()->SetTitle(Form("Counts / (%02d MeV^{2}/#it{c}^{4})", binWidth));
		histPtH3[particle][pt]->Sumw2();
		histPtH3[particle][pt]->GetXaxis()->SetRangeUser(5, 11);
		}
	}

	Long64_t nEntries = (Long64_t)fTreeData->GetEntries();
	for (Long64_t i=0; i<nEntries; i++) {
		if (i % (nEntries/2000) == 0) 
			cout << Form("\rreading data tree: %1.2f %%", 100. * i / (double) nEntries) << flush; 
		fTreeData->GetEntry(i);
		

		if (TMath::Abs(tY) > cutYTri)	continue;	// set rapidity range

		if (trigger == "HM")
		{
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
		if (tChargeTri < 0) particle = 1;
		for (int pt = 0; pt < nPtBins; pt++){
			if (tPt >= ptBins[pt] && tPt < ptBins[pt+1] && tTOFSignalTri > 0) {
				if (Cut()) {
					histPtH3[particle][pt]->Fill(tTOFSignalTri);
					histPtH3[2][pt]->Fill(tTOFSignalTri);
				}		
			}
		}
	}
	cout << endl;
	// save histos
	TFile * f = new TFile(rootfile,"recreate");
	for (int particle = 0; particle < nParticles; particle++){
		for (int pt = 0; pt < nPtBins; pt++){
			histPtH3[particle][pt]->Write(0, TObject::kOverwrite);		
		}
	}
	f->Close();
}
//_________________________________________________________________________________________________________
