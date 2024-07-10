#include <iostream>
#include <fstream>
#include <cstdlib>
#include "TROOT.h"
#include "TH1D.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TF1.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TLegend.h"
#include "THStack.h"
#include "TPaveText.h"
#include "TCanvas.h"
#include "TObject.h"
#include "Cut_Tree.h"

//local:
//TString resultPath = "/Users/matthiasherzer/alice/root_results";
//TString Folder = "/Users/matthiasherzer/alice/root_results";
// ext. hard drive: 
TString resultPath = "/Volumes/MyPassport/pass2/HeTri_pass2";
TString Folder = "/Volumes/MyPassport/pass2_WorkingTree";
TString periods16 = "deghijklop";
TString periods17 = "cefghijklmor"; //klmor + cefghij
TString periods18 = "bdefghilmnop";  //bdefghilmnop
TString rootFilePath = Folder + "/Rootfiles/";
TString rootfile16 = Folder + "/Rootfiles/Analysis_16.root";
TString rootfile17 = Folder + "/Rootfiles/Analysis_17.root";
TString rootfile18 = Folder + "/Rootfiles/Analysis_18.root";
TString rootfile182 = Folder + "/Rootfiles/Analysis_182.root";
TString rootfile_merged = Folder + "/Rootfiles/Analysis_mergedHMHNU.root";
enum cutNames             {DcaXY, DcaZ, TriTPCnSigma, TofSignal, TofSignal2};
const double cutConf[7] = {0.30,  0.30, 	5.0,            4,      12};

void Cut_Tree(){
	readDataH316();
    readDataH317();
    readDataH318();
	readDataH318_2();
    merge();
    //hadd();
}
//_____________________________________________________________________________________________
bool Cut(){
    if (TMath::Abs(tDcaXY) > cutConf[0]) return false;
    if (TMath::Abs(tDcaZ) > cutConf[1]) return false;
    if (TMath::Abs(tTriSigma) > cutConf[2]) return false;
    if (tTOFSignalTri < cutConf[3] || tTOFSignalTri > cutConf[4]) return false;
    return true;
}
//_____________________________________________________________________________________________
void readDataH317(){
	TCanvas *c1;

	TChain *fTreeData17 = new TChain("He3TriTree/treeTri");
    TFile * f17 = new TFile(rootfile17,"recreate");

    fTreeTriHM17 = new TTree("treeTriHM", "ftreeTriHM");
	fTreeTriHM17->Branch("tRunNumber"       , &tRunNumber       , "tRunNumber/I"       );
	fTreeTriHM17->Branch("tEventId"         , &tEventId         , "tEventId/l"         );	
	fTreeTriHM17->Branch("tPt"              , &tPt              , "tPt/D"              );
	fTreeTriHM17->Branch("tChargeTri"       , &tChargeTri       , "tCharge/D"          );
	fTreeTriHM17->Branch("tE"               , &tE               , "tE/D"               );
	fTreeTriHM17->Branch("tY"               , &tY               , "tY/D"               );
	fTreeTriHM17->Branch("tEta"             , &tEta             , "tEta/D"             );
	fTreeTriHM17->Branch("tPhi"             , &tPhi             , "tPhi/D"             );
	fTreeTriHM17->Branch("tP"               , &tP               , "tP/D"               );
	fTreeTriHM17->Branch("tPx"              , &tPx              , "tPx/D"              );
	fTreeTriHM17->Branch("tPy"              , &tPy              , "tPy/D"              );
	fTreeTriHM17->Branch("tPz"              , &tPz              , "tPz/D"              );
	fTreeTriHM17->Branch("tTriSigma"        , &tTriSigma        , "tSigma/D"           );
	fTreeTriHM17->Branch("tTriDedx"         , &tTriDedx         , "tDedx/D"            );
	fTreeTriHM17->Branch("tDcaXY"           , &tDcaXY           , "tDcaXY/D"           );
	fTreeTriHM17->Branch("tDcaZ"            , &tDcaZ            , "tDcaZ/D"            );
	fTreeTriHM17->Branch("tSigmaYX"         , &tSigmaYX         , "tSigmaYX/D"         );
	fTreeTriHM17->Branch("tSigmaXYZ"        , &tSigmaXYZ        , "tSigmaXYZ/D"          );
	fTreeTriHM17->Branch("tSigmaZ"          , &tSigmaZ          , "tSigmaZ/D"            );
	fTreeTriHM17->Branch("tMCtrue"          , &tMCtrue          , "tMCtrue/I"          );
	fTreeTriHM17->Branch("tTrigMB"          , &tTrigMB          , "tTrigMB/I"          );
	fTreeTriHM17->Branch("tTrigHMV0"        , &tTrigHMV0        , "tTrigHMV0/I"        );
	fTreeTriHM17->Branch("tTrigHMSPD"       , &tTrigHMSPD       , "tTrigHMSPD/I"       );
	fTreeTriHM17->Branch("tTrigHNU"         , &tTrigHNU         , "tTrigHNU/I"         );
	fTreeTriHM17->Branch("tTrigHQU"         , &tTrigHQU         , "tTrigHQU/I"         );
	fTreeTriHM17->Branch("tMagField"        , &tMagField        , "tMagField/D"        );
	fTreeTriHM17->Branch("tTRDvalid"        , &tTRDvalid        , "tTRDvalid/I"        );
	fTreeTriHM17->Branch("tTRDPid"          , &tTRDPid          , "tTRDPid/I"          );
	fTreeTriHM17->Branch("tTRDnTracklets"   , &tTRDnTracklets   , "tTRDnTracklets/I"   );
	fTreeTriHM17->Branch("tTRDPt"           , &tTRDPt           , "tTRDPt/I"           );
	fTreeTriHM17->Branch("tTRDLayerMask"    , &tTRDLayerMask    , "tTRDLayerMask/I"    );
	fTreeTriHM17->Branch("tTRDSagitta"      , &tTRDSagitta      , "tTRDSagitta/D"      );
	fTreeTriHM17->Branch("tTRDStack"        , &tTRDStack        , "tTRDStack/I"        );
	fTreeTriHM17->Branch("tTRDSector"       , &tTRDSector       , "tTRDSector/I"       );
	fTreeTriHM17->Branch("tTRDPID0"         , &tTRDPID0         , "tTRDPID0/i"         );
	fTreeTriHM17->Branch("tTRDPID1"         , &tTRDPID1         , "tTRDPID1/i"         );
	fTreeTriHM17->Branch("tTRDPID2"         , &tTRDPID2         , "tTRDPID2/i"         );
	fTreeTriHM17->Branch("tTRDPID3"         , &tTRDPID3         , "tTRDPID3/i"         );
	fTreeTriHM17->Branch("tTRDPID4"         , &tTRDPID4         , "tTRDPID4/i"         );
	fTreeTriHM17->Branch("tTRDPID5"         , &tTRDPID5         , "tTRDPID5/i"         );
	fTreeTriHM17->Branch("tnTPCcluster"     , &tnTPCcluster     , "tnTPCcluster/D"     );
	fTreeTriHM17->Branch("tnITScluster"     , &tnITScluster     , "tnITScluster/D"     );
	fTreeTriHM17->Branch("tTPCchi2"         , &tTPCchi2         , "tTPCchi2/D"         );
	fTreeTriHM17->Branch("tSPDFiredChips0"  , &tSPDFiredChips0  , "tSPDFiredChips0/D"  );
	fTreeTriHM17->Branch("tSPDFiredChips1"  , &tSPDFiredChips1  , "tSPDFiredChips1/D"  );
	fTreeTriHM17->Branch("tSPDTracklets"    , &tSPDTracklets    , "tSPDTracklets/D"    );
	fTreeTriHM17->Branch("tSPDCluster"      , &tSPDCluster      , "tSPDCluster/D"      );
	fTreeTriHM17->Branch("tV0Multiplicity"  , &tV0Multiplicity  , "tV0Multiplicity/D"  );
	fTreeTriHM17->Branch("tNTracks"         , &tNTracks         , "tNTracks/D"         );
	fTreeTriHM17->Branch("tMultV0M"         , &tMultV0M         , "tMultV0M/D"         );
	fTreeTriHM17->Branch("tMultOfV0M"       , &tMultOfV0M       , "tMultOfV0M/D"       );
	fTreeTriHM17->Branch("tMultSPDTracklet" , &tMultSPDTracklet , "tMultSPDTracklet/D" );
	fTreeTriHM17->Branch("tMultSPDCluster"  , &tMultSPDCluster  , "tMultSPDCluster/D"  );
	fTreeTriHM17->Branch("tMultRef05"       , &tMultRef05       , "tMultRef05/D"       );
	fTreeTriHM17->Branch("tMultRef08"       , &tMultRef08       , "tMultRef08/D"       );
	fTreeTriHM17->Branch("tKink"            , &tKink            , "tKink/I"            );
	fTreeTriHM17->Branch("tTPCrefit"        , &tTPCrefit        , "tTPCrefit/I"        );
	fTreeTriHM17->Branch("tITSrefit"        , &tITSrefit        , "tITSrefit/I"        );
	fTreeTriHM17->Branch("tTOFSignalTri"    , &tTOFSignalTri    , "tTOFSignalTri/D"    );
	fTreeTriHM17->Branch("tPrimary"         , &tPrimary         , "tPrimary/I"         );
	fTreeTriHM17->Branch("tWeak"            , &tWeak            , "tWeak/I"            );
	fTreeTriHM17->Branch("tMaterial"        , &tMaterial        , "tMaterial/I"        );
	fTreeTriHM17->Branch("tPdg"			 , &tPdg			 , "tPdg/I");

	for (Int_t i = 0; i < periods17.Length(); i++){
		fTreeData17->Add(resultPath+ "/Data/LHC17"  + periods17(i,1)+ "/AnalysisResults.root");
		}
	setTreeBranchH3(fTreeData17);
	
	Long64_t nEntries = (Long64_t)fTreeData17->GetEntries();
	std::cout << "Number of entries: "<< nEntries << std::endl;
	Long64_t counter = 0;
	for (Long64_t i=0; i<nEntries; i++) {
		if (i % (nEntries/2000) == 0) 
			cout << Form("\rreading data tree: %1.2f %%", 100. * i / (double) nEntries) << flush; 
		fTreeData17->GetEntry(i);
		

		if (TMath::Abs(tY) > 0.5)	continue;	// set rapidity range

		if (!tTrigHMV0 && !tTrigHMSPD && !tTrigHNU && !tTrigHQU) continue;
		

        if (Cut()){
            fTreeTriHM17->Fill();
        }
        

	}
	std::cout << "Number of filled in entries" << counter << std::endl;
	cout << endl;
	fTreeTriHM17->Write(0, TObject::kOverwrite);
	f17->Close();
}	
//________________________________________________________________________________________________________________________
void readDataH316(){
	TCanvas *c2;

	TChain *fTreeData16 = new TChain("He3TriTree/treeTri");
    TFile * f16 = new TFile(rootfile16,"recreate");

    fTreeTriHM16 = new TTree("treeTriHM", "ftreeTriHM");
	fTreeTriHM16->Branch("tRunNumber"       , &tRunNumber       , "tRunNumber/I"       );
	fTreeTriHM16->Branch("tEventId"         , &tEventId         , "tEventId/l"         );	
	fTreeTriHM16->Branch("tPt"              , &tPt              , "tPt/D"              );
	fTreeTriHM16->Branch("tChargeTri"       , &tChargeTri       , "tCharge/D"          );
	fTreeTriHM16->Branch("tE"               , &tE               , "tE/D"               );
	fTreeTriHM16->Branch("tY"               , &tY               , "tY/D"               );
	fTreeTriHM16->Branch("tEta"             , &tEta             , "tEta/D"             );
	fTreeTriHM16->Branch("tPhi"             , &tPhi             , "tPhi/D"             );
	fTreeTriHM16->Branch("tP"               , &tP               , "tP/D"               );
	fTreeTriHM16->Branch("tPx"              , &tPx              , "tPx/D"              );
	fTreeTriHM16->Branch("tPy"              , &tPy              , "tPy/D"              );
	fTreeTriHM16->Branch("tPz"              , &tPz              , "tPz/D"              );
	fTreeTriHM16->Branch("tTriSigma"        , &tTriSigma        , "tSigma/D"           );
	fTreeTriHM16->Branch("tTriDedx"         , &tTriDedx         , "tDedx/D"            );
	fTreeTriHM16->Branch("tDcaXY"           , &tDcaXY           , "tDcaXY/D"           );
	fTreeTriHM16->Branch("tDcaZ"            , &tDcaZ            , "tDcaZ/D"            );
	fTreeTriHM16->Branch("tSigmaYX"         , &tSigmaYX         , "tSigmaYX/D"         );
	fTreeTriHM16->Branch("tSigmaXYZ"        , &tSigmaXYZ        , "tSigmaXYZ/D"          );
	fTreeTriHM16->Branch("tSigmaZ"          , &tSigmaZ          , "tSigmaZ/D"            );
	fTreeTriHM16->Branch("tMCtrue"          , &tMCtrue          , "tMCtrue/I"          );
	fTreeTriHM16->Branch("tTrigMB"          , &tTrigMB          , "tTrigMB/I"          );
	fTreeTriHM16->Branch("tTrigHMV0"        , &tTrigHMV0        , "tTrigHMV0/I"        );
	fTreeTriHM16->Branch("tTrigHMSPD"       , &tTrigHMSPD       , "tTrigHMSPD/I"       );
	fTreeTriHM16->Branch("tTrigHNU"         , &tTrigHNU         , "tTrigHNU/I"         );
	fTreeTriHM16->Branch("tTrigHQU"         , &tTrigHQU         , "tTrigHQU/I"         );
	fTreeTriHM16->Branch("tMagField"        , &tMagField        , "tMagField/D"        );
	fTreeTriHM16->Branch("tTRDvalid"        , &tTRDvalid        , "tTRDvalid/I"        );
	fTreeTriHM16->Branch("tTRDPid"          , &tTRDPid          , "tTRDPid/I"          );
	fTreeTriHM16->Branch("tTRDnTracklets"   , &tTRDnTracklets   , "tTRDnTracklets/I"   );
	fTreeTriHM16->Branch("tTRDPt"           , &tTRDPt           , "tTRDPt/I"           );
	fTreeTriHM16->Branch("tTRDLayerMask"    , &tTRDLayerMask    , "tTRDLayerMask/I"    );
	fTreeTriHM16->Branch("tTRDSagitta"      , &tTRDSagitta      , "tTRDSagitta/D"      );
	fTreeTriHM16->Branch("tTRDStack"        , &tTRDStack        , "tTRDStack/I"        );
	fTreeTriHM16->Branch("tTRDSector"       , &tTRDSector       , "tTRDSector/I"       );
	fTreeTriHM16->Branch("tTRDPID0"         , &tTRDPID0         , "tTRDPID0/i"         );
	fTreeTriHM16->Branch("tTRDPID1"         , &tTRDPID1         , "tTRDPID1/i"         );
	fTreeTriHM16->Branch("tTRDPID2"         , &tTRDPID2         , "tTRDPID2/i"         );
	fTreeTriHM16->Branch("tTRDPID3"         , &tTRDPID3         , "tTRDPID3/i"         );
	fTreeTriHM16->Branch("tTRDPID4"         , &tTRDPID4         , "tTRDPID4/i"         );
	fTreeTriHM16->Branch("tTRDPID5"         , &tTRDPID5         , "tTRDPID5/i"         );
	fTreeTriHM16->Branch("tnTPCcluster"     , &tnTPCcluster     , "tnTPCcluster/D"     );
	fTreeTriHM16->Branch("tnITScluster"     , &tnITScluster     , "tnITScluster/D"     );
	fTreeTriHM16->Branch("tTPCchi2"         , &tTPCchi2         , "tTPCchi2/D"         );
	fTreeTriHM16->Branch("tSPDFiredChips0"  , &tSPDFiredChips0  , "tSPDFiredChips0/D"  );
	fTreeTriHM16->Branch("tSPDFiredChips1"  , &tSPDFiredChips1  , "tSPDFiredChips1/D"  );
	fTreeTriHM16->Branch("tSPDTracklets"    , &tSPDTracklets    , "tSPDTracklets/D"    );
	fTreeTriHM16->Branch("tSPDCluster"      , &tSPDCluster      , "tSPDCluster/D"      );
	fTreeTriHM16->Branch("tV0Multiplicity"  , &tV0Multiplicity  , "tV0Multiplicity/D"  );
	fTreeTriHM16->Branch("tNTracks"         , &tNTracks         , "tNTracks/D"         );
	fTreeTriHM16->Branch("tMultV0M"         , &tMultV0M         , "tMultV0M/D"         );
	fTreeTriHM16->Branch("tMultOfV0M"       , &tMultOfV0M       , "tMultOfV0M/D"       );
	fTreeTriHM16->Branch("tMultSPDTracklet" , &tMultSPDTracklet , "tMultSPDTracklet/D" );
	fTreeTriHM16->Branch("tMultSPDCluster"  , &tMultSPDCluster  , "tMultSPDCluster/D"  );
	fTreeTriHM16->Branch("tMultRef05"       , &tMultRef05       , "tMultRef05/D"       );
	fTreeTriHM16->Branch("tMultRef08"       , &tMultRef08       , "tMultRef08/D"       );
	fTreeTriHM16->Branch("tKink"            , &tKink            , "tKink/I"            );
	fTreeTriHM16->Branch("tTPCrefit"        , &tTPCrefit        , "tTPCrefit/I"        );
	fTreeTriHM16->Branch("tITSrefit"        , &tITSrefit        , "tITSrefit/I"        );
	fTreeTriHM16->Branch("tTOFSignalTri"    , &tTOFSignalTri    , "tTOFSignalTri/D"    );
	fTreeTriHM16->Branch("tPrimary"         , &tPrimary         , "tPrimary/I"         );
	fTreeTriHM16->Branch("tWeak"            , &tWeak            , "tWeak/I"            );
	fTreeTriHM16->Branch("tMaterial"        , &tMaterial        , "tMaterial/I"        );
	fTreeTriHM16->Branch("tPdg"			 , &tPdg			 , "tPdg/I");

	for (Int_t i = 0; i < periods16.Length(); i++){
		fTreeData16->Add(resultPath+ "/Data/LHC16"  + periods16(i,1)+ "/AnalysisResults.root");
		}
	setTreeBranchH3(fTreeData16);


	Long64_t nEntries = (Long64_t)fTreeData16->GetEntries();
	std::cout << "Number of entries: "<< nEntries << std::endl;
	Long64_t counter = 0;
	for (Long64_t i=0; i<nEntries; i++) {
		if (i % (nEntries/2000) == 0) 
			cout << Form("\rreading data tree: %1.2f %%", 100. * i / (double) nEntries) << flush; 
		fTreeData16->GetEntry(i);
		

		if (TMath::Abs(tY) > 0.5)	continue;	// set rapidity range

		if (!tTrigHMV0 && !tTrigHMSPD && !tTrigHNU && !tTrigHQU) continue;


        if (Cut()){
            fTreeTriHM16->Fill();
        }
        

	}
	std::cout << "Number of filled in entries" << counter << std::endl;
	cout << endl;
	fTreeTriHM16->Write(0, TObject::kOverwrite);
	f16->Close();
}	
//________________________________________________________________________________________________________________________
void readDataH318(){
	TCanvas *c2;
	TChain *fTreeData18 = new TChain("He3TriTree/treeTri");
    TFile * f18 = new TFile(rootfile18,"recreate");

    fTreeTriHM18 = new TTree("treeTriHM", "ftreeTriHM");
	fTreeTriHM18->Branch("tRunNumber"       , &tRunNumber       , "tRunNumber/I"       );
	fTreeTriHM18->Branch("tEventId"         , &tEventId         , "tEventId/l"         );	
	fTreeTriHM18->Branch("tPt"              , &tPt              , "tPt/D"              );
	fTreeTriHM18->Branch("tChargeTri"       , &tChargeTri       , "tCharge/D"          );
	fTreeTriHM18->Branch("tE"               , &tE               , "tE/D"               );
	fTreeTriHM18->Branch("tY"               , &tY               , "tY/D"               );
	fTreeTriHM18->Branch("tEta"             , &tEta             , "tEta/D"             );
	fTreeTriHM18->Branch("tPhi"             , &tPhi             , "tPhi/D"             );
	fTreeTriHM18->Branch("tP"               , &tP               , "tP/D"               );
	fTreeTriHM18->Branch("tPx"              , &tPx              , "tPx/D"              );
	fTreeTriHM18->Branch("tPy"              , &tPy              , "tPy/D"              );
	fTreeTriHM18->Branch("tPz"              , &tPz              , "tPz/D"              );
	fTreeTriHM18->Branch("tTriSigma"        , &tTriSigma        , "tSigma/D"           );
	fTreeTriHM18->Branch("tTriDedx"         , &tTriDedx         , "tDedx/D"            );
	fTreeTriHM18->Branch("tDcaXY"           , &tDcaXY           , "tDcaXY/D"           );
	fTreeTriHM18->Branch("tDcaZ"            , &tDcaZ            , "tDcaZ/D"            );
	fTreeTriHM18->Branch("tSigmaYX"         , &tSigmaYX         , "tSigmaYX/D"         );
	fTreeTriHM18->Branch("tSigmaXYZ"        , &tSigmaXYZ        , "tSigmaXYZ/D"          );
	fTreeTriHM18->Branch("tSigmaZ"          , &tSigmaZ          , "tSigmaZ/D"            );
	fTreeTriHM18->Branch("tMCtrue"          , &tMCtrue          , "tMCtrue/I"          );
	fTreeTriHM18->Branch("tTrigMB"          , &tTrigMB          , "tTrigMB/I"          );
	fTreeTriHM18->Branch("tTrigHMV0"        , &tTrigHMV0        , "tTrigHMV0/I"        );
	fTreeTriHM18->Branch("tTrigHMSPD"       , &tTrigHMSPD       , "tTrigHMSPD/I"       );
	fTreeTriHM18->Branch("tTrigHNU"         , &tTrigHNU         , "tTrigHNU/I"         );
	fTreeTriHM18->Branch("tTrigHQU"         , &tTrigHQU         , "tTrigHQU/I"         );
	fTreeTriHM18->Branch("tMagField"        , &tMagField        , "tMagField/D"        );
	fTreeTriHM18->Branch("tTRDvalid"        , &tTRDvalid        , "tTRDvalid/I"        );
	fTreeTriHM18->Branch("tTRDPid"          , &tTRDPid          , "tTRDPid/I"          );
	fTreeTriHM18->Branch("tTRDnTracklets"   , &tTRDnTracklets   , "tTRDnTracklets/I"   );
	fTreeTriHM18->Branch("tTRDPt"           , &tTRDPt           , "tTRDPt/I"           );
	fTreeTriHM18->Branch("tTRDLayerMask"    , &tTRDLayerMask    , "tTRDLayerMask/I"    );
	fTreeTriHM18->Branch("tTRDSagitta"      , &tTRDSagitta      , "tTRDSagitta/D"      );
	fTreeTriHM18->Branch("tTRDStack"        , &tTRDStack        , "tTRDStack/I"        );
	fTreeTriHM18->Branch("tTRDSector"       , &tTRDSector       , "tTRDSector/I"       );
	fTreeTriHM18->Branch("tTRDPID0"         , &tTRDPID0         , "tTRDPID0/i"         );
	fTreeTriHM18->Branch("tTRDPID1"         , &tTRDPID1         , "tTRDPID1/i"         );
	fTreeTriHM18->Branch("tTRDPID2"         , &tTRDPID2         , "tTRDPID2/i"         );
	fTreeTriHM18->Branch("tTRDPID3"         , &tTRDPID3         , "tTRDPID3/i"         );
	fTreeTriHM18->Branch("tTRDPID4"         , &tTRDPID4         , "tTRDPID4/i"         );
	fTreeTriHM18->Branch("tTRDPID5"         , &tTRDPID5         , "tTRDPID5/i"         );
	fTreeTriHM18->Branch("tnTPCcluster"     , &tnTPCcluster     , "tnTPCcluster/D"     );
	fTreeTriHM18->Branch("tnITScluster"     , &tnITScluster     , "tnITScluster/D"     );
	fTreeTriHM18->Branch("tTPCchi2"         , &tTPCchi2         , "tTPCchi2/D"         );
	fTreeTriHM18->Branch("tSPDFiredChips0"  , &tSPDFiredChips0  , "tSPDFiredChips0/D"  );
	fTreeTriHM18->Branch("tSPDFiredChips1"  , &tSPDFiredChips1  , "tSPDFiredChips1/D"  );
	fTreeTriHM18->Branch("tSPDTracklets"    , &tSPDTracklets    , "tSPDTracklets/D"    );
	fTreeTriHM18->Branch("tSPDCluster"      , &tSPDCluster      , "tSPDCluster/D"      );
	fTreeTriHM18->Branch("tV0Multiplicity"  , &tV0Multiplicity  , "tV0Multiplicity/D"  );
	fTreeTriHM18->Branch("tNTracks"         , &tNTracks         , "tNTracks/D"         );
	fTreeTriHM18->Branch("tMultV0M"         , &tMultV0M         , "tMultV0M/D"         );
	fTreeTriHM18->Branch("tMultOfV0M"       , &tMultOfV0M       , "tMultOfV0M/D"       );
	fTreeTriHM18->Branch("tMultSPDTracklet" , &tMultSPDTracklet , "tMultSPDTracklet/D" );
	fTreeTriHM18->Branch("tMultSPDCluster"  , &tMultSPDCluster  , "tMultSPDCluster/D"  );
	fTreeTriHM18->Branch("tMultRef05"       , &tMultRef05       , "tMultRef05/D"       );
	fTreeTriHM18->Branch("tMultRef08"       , &tMultRef08       , "tMultRef08/D"       );
	fTreeTriHM18->Branch("tKink"            , &tKink            , "tKink/I"            );
	fTreeTriHM18->Branch("tTPCrefit"        , &tTPCrefit        , "tTPCrefit/I"        );
	fTreeTriHM18->Branch("tITSrefit"        , &tITSrefit        , "tITSrefit/I"        );
	fTreeTriHM18->Branch("tTOFSignalTri"    , &tTOFSignalTri    , "tTOFSignalTri/D"    );
	fTreeTriHM18->Branch("tPrimary"         , &tPrimary         , "tPrimary/I"         );
	fTreeTriHM18->Branch("tWeak"            , &tWeak            , "tWeak/I"            );
	fTreeTriHM18->Branch("tMaterial"        , &tMaterial        , "tMaterial/I"        );
	fTreeTriHM18->Branch("tPdg"			 , &tPdg			 , "tPdg/I");


	for (Int_t i = 0; i < 8; i++){
		fTreeData18->Add(resultPath+ "/Data/LHC18"  + periods18(i,1)+ "/AnalysisResults.root");
		}
	
	setTreeBranchH3(fTreeData18);

	Long64_t nEntries = (Long64_t)fTreeData18->GetEntries();
	std::cout << "Number of entries: "<< nEntries << std::endl;
	Long64_t counter = 0;
	for (Long64_t i=0; i<nEntries; i++) {
		if (i % (nEntries/2000) == 0) 
			cout << Form("\rreading data tree: %1.2f %%", 100. * i / (double) nEntries) << flush; 
		fTreeData18->GetEntry(i);
		

		if (TMath::Abs(tY) > 0.5)	continue;	// set rapidity range
		
        if (!tTrigHMV0 && !tTrigHMSPD && !tTrigHNU && !tTrigHQU) continue;

        
        if (Cut()){
            fTreeTriHM18->Fill();
        }
        
	}
	std::cout << "Number of filled in entries" << counter << std::endl;
	cout << endl;
	fTreeTriHM18->Write(0, TObject::kOverwrite);
	f18->Close();
}
//_____________________________________________________________________________________________
void readDataH318_2(){
	TCanvas *c2;
	TChain *fTreeData182 = new TChain("He3TriTree/treeTri");
    TFile * f182 = new TFile(rootfile182,"recreate");

    fTreeTriHM182 = new TTree("treeTriHM", "ftreeTriHM");
	fTreeTriHM182->Branch("tRunNumber"       , &tRunNumber       , "tRunNumber/I"       );
	fTreeTriHM182->Branch("tEventId"         , &tEventId         , "tEventId/l"         );	
	fTreeTriHM182->Branch("tPt"              , &tPt              , "tPt/D"              );
	fTreeTriHM182->Branch("tChargeTri"       , &tChargeTri       , "tCharge/D"          );
	fTreeTriHM182->Branch("tE"               , &tE               , "tE/D"               );
	fTreeTriHM182->Branch("tY"               , &tY               , "tY/D"               );
	fTreeTriHM182->Branch("tEta"             , &tEta             , "tEta/D"             );
	fTreeTriHM182->Branch("tPhi"             , &tPhi             , "tPhi/D"             );
	fTreeTriHM182->Branch("tP"               , &tP               , "tP/D"               );
	fTreeTriHM182->Branch("tPx"              , &tPx              , "tPx/D"              );
	fTreeTriHM182->Branch("tPy"              , &tPy              , "tPy/D"              );
	fTreeTriHM182->Branch("tPz"              , &tPz              , "tPz/D"              );
	fTreeTriHM182->Branch("tTriSigma"        , &tTriSigma        , "tSigma/D"           );
	fTreeTriHM182->Branch("tTriDedx"         , &tTriDedx         , "tDedx/D"            );
	fTreeTriHM182->Branch("tDcaXY"           , &tDcaXY           , "tDcaXY/D"           );
	fTreeTriHM182->Branch("tDcaZ"            , &tDcaZ            , "tDcaZ/D"            );
	fTreeTriHM182->Branch("tSigmaYX"         , &tSigmaYX         , "tSigmaYX/D"         );
	fTreeTriHM182->Branch("tSigmaXYZ"        , &tSigmaXYZ        , "tSigmaXYZ/D"          );
	fTreeTriHM182->Branch("tSigmaZ"          , &tSigmaZ          , "tSigmaZ/D"            );
	fTreeTriHM182->Branch("tMCtrue"          , &tMCtrue          , "tMCtrue/I"          );
	fTreeTriHM182->Branch("tTrigMB"          , &tTrigMB          , "tTrigMB/I"          );
	fTreeTriHM182->Branch("tTrigHMV0"        , &tTrigHMV0        , "tTrigHMV0/I"        );
	fTreeTriHM182->Branch("tTrigHMSPD"       , &tTrigHMSPD       , "tTrigHMSPD/I"       );
	fTreeTriHM182->Branch("tTrigHNU"         , &tTrigHNU         , "tTrigHNU/I"         );
	fTreeTriHM182->Branch("tTrigHQU"         , &tTrigHQU         , "tTrigHQU/I"         );
	fTreeTriHM182->Branch("tMagField"        , &tMagField        , "tMagField/D"        );
	fTreeTriHM182->Branch("tTRDvalid"        , &tTRDvalid        , "tTRDvalid/I"        );
	fTreeTriHM182->Branch("tTRDPid"          , &tTRDPid          , "tTRDPid/I"          );
	fTreeTriHM182->Branch("tTRDnTracklets"   , &tTRDnTracklets   , "tTRDnTracklets/I"   );
	fTreeTriHM182->Branch("tTRDPt"           , &tTRDPt           , "tTRDPt/I"           );
	fTreeTriHM182->Branch("tTRDLayerMask"    , &tTRDLayerMask    , "tTRDLayerMask/I"    );
	fTreeTriHM182->Branch("tTRDSagitta"      , &tTRDSagitta      , "tTRDSagitta/D"      );
	fTreeTriHM182->Branch("tTRDStack"        , &tTRDStack        , "tTRDStack/I"        );
	fTreeTriHM182->Branch("tTRDSector"       , &tTRDSector       , "tTRDSector/I"       );
	fTreeTriHM182->Branch("tTRDPID0"         , &tTRDPID0         , "tTRDPID0/i"         );
	fTreeTriHM182->Branch("tTRDPID1"         , &tTRDPID1         , "tTRDPID1/i"         );
	fTreeTriHM182->Branch("tTRDPID2"         , &tTRDPID2         , "tTRDPID2/i"         );
	fTreeTriHM182->Branch("tTRDPID3"         , &tTRDPID3         , "tTRDPID3/i"         );
	fTreeTriHM182->Branch("tTRDPID4"         , &tTRDPID4         , "tTRDPID4/i"         );
	fTreeTriHM182->Branch("tTRDPID5"         , &tTRDPID5         , "tTRDPID5/i"         );
	fTreeTriHM182->Branch("tnTPCcluster"     , &tnTPCcluster     , "tnTPCcluster/D"     );
	fTreeTriHM182->Branch("tnITScluster"     , &tnITScluster     , "tnITScluster/D"     );
	fTreeTriHM182->Branch("tTPCchi2"         , &tTPCchi2         , "tTPCchi2/D"         );
	fTreeTriHM182->Branch("tSPDFiredChips0"  , &tSPDFiredChips0  , "tSPDFiredChips0/D"  );
	fTreeTriHM182->Branch("tSPDFiredChips1"  , &tSPDFiredChips1  , "tSPDFiredChips1/D"  );
	fTreeTriHM182->Branch("tSPDTracklets"    , &tSPDTracklets    , "tSPDTracklets/D"    );
	fTreeTriHM182->Branch("tSPDCluster"      , &tSPDCluster      , "tSPDCluster/D"      );
	fTreeTriHM182->Branch("tV0Multiplicity"  , &tV0Multiplicity  , "tV0Multiplicity/D"  );
	fTreeTriHM182->Branch("tNTracks"         , &tNTracks         , "tNTracks/D"         );
	fTreeTriHM182->Branch("tMultV0M"         , &tMultV0M         , "tMultV0M/D"         );
	fTreeTriHM182->Branch("tMultOfV0M"       , &tMultOfV0M       , "tMultOfV0M/D"       );
	fTreeTriHM182->Branch("tMultSPDTracklet" , &tMultSPDTracklet , "tMultSPDTracklet/D" );
	fTreeTriHM182->Branch("tMultSPDCluster"  , &tMultSPDCluster  , "tMultSPDCluster/D"  );
	fTreeTriHM182->Branch("tMultRef05"       , &tMultRef05       , "tMultRef05/D"       );
	fTreeTriHM182->Branch("tMultRef08"       , &tMultRef08       , "tMultRef08/D"       );
	fTreeTriHM182->Branch("tKink"            , &tKink            , "tKink/I"            );
	fTreeTriHM182->Branch("tTPCrefit"        , &tTPCrefit        , "tTPCrefit/I"        );
	fTreeTriHM182->Branch("tITSrefit"        , &tITSrefit        , "tITSrefit/I"        );
	fTreeTriHM182->Branch("tTOFSignalTri"    , &tTOFSignalTri    , "tTOFSignalTri/D"    );
	fTreeTriHM182->Branch("tPrimary"         , &tPrimary         , "tPrimary/I"         );
	fTreeTriHM182->Branch("tWeak"            , &tWeak            , "tWeak/I"            );
	fTreeTriHM182->Branch("tMaterial"        , &tMaterial        , "tMaterial/I"        );
	fTreeTriHM182->Branch("tPdg"			 , &tPdg			 , "tPdg/I");

	for (Int_t i = 8; i < periods18.Length(); i++){
		fTreeData182->Add(resultPath+ "/Data/LHC18"  + periods18(i,1)+ "/AnalysisResults.root");
		}
	
	setTreeBranchH3(fTreeData182);

	Long64_t nEntries = (Long64_t)fTreeData182->GetEntries();
	std::cout << "Number of entries: "<< nEntries << std::endl;
	Long64_t counter = 0;	
	for (Long64_t i=0; i<nEntries; i++) {
		if (i % (nEntries/2000) == 0) 
			cout << Form("\rreading data tree: %1.2f %%", 100. * i / (double) nEntries) << flush; 
		fTreeData182->GetEntry(i);
		

		if (TMath::Abs(tY) > 0.5)	continue;	// set rapidity range
		
        if (!tTrigHMV0 && !tTrigHMSPD && !tTrigHNU && !tTrigHQU) continue;

        
        if (Cut()){
            fTreeTriHM182->Fill();
        }
        
	}
	std::cout << "Number of filled in entries" << counter << std::endl;
	cout << endl;
	fTreeTriHM182->Write(0, TObject::kOverwrite);
	f182->Close();
}
//______________________________________________________________________________________________
void merge(){
    //ext. hard drive:
    gSystem->Exec("hadd -f '/Volumes/MyPassport/pass2_WorkingTree/Rootfiles/Analysis_mergedHMHNU.root' '/Volumes/MyPassport/pass2_WorkingTree/Rootfiles/Analysis_16.root' '/Volumes/MyPassport/pass2_WorkingTree/Rootfiles/Analysis_17.root' '/Volumes/MyPassport/pass2_WorkingTree/Rootfiles/Analysis_18.root' '/Volumes/MyPassport/pass2_WorkingTree/Rootfiles/Analysis_182.root'");
    //gSystem->Exec("rm -r '/Volumes/MyPassport/pass2_WorkingTree/Rootfiles/Analysis_17.root' '/Volumes/MyPassport/pass2_WorkingTree/Rootfiles/Analysis_18.root'");
    //local: 
    //gSystem->Exec("hadd -f /Users/matthiasherzer/alice/root_results/Rootfiles/Analysis_merged.root /Users/matthiasherzer/alice/root_results/Rootfiles/Analysis_17.root /Users/matthiasherzer/alice/root_results/Rootfiles/Analysis_18.root");
    //gSystem->Exec("rm -r /Users/matthiasherzer/alice/root_results/Rootfiles/Analysis_17.root /Users/matthiasherzer/alice/root_results/Rootfiles/Analysis_18.root");

}
//_____________________________________________________________________________________________
void setTreeBranchH3(TTree *fTree) {
	fTree->SetBranchAddress("tRunNumber"       , &tRunNumber        );
	fTree->SetBranchAddress("tEventId"         , &tEventId          );	
	fTree->SetBranchAddress("tPt"              , &tPt               );
	fTree->SetBranchAddress("tChargeTri"       , &tChargeTri        );
	fTree->SetBranchAddress("tE"               , &tE                );
	fTree->SetBranchAddress("tY"               , &tY                );
	fTree->SetBranchAddress("tEta"             , &tEta              );
	fTree->SetBranchAddress("tPhi"             , &tPhi              );
	fTree->SetBranchAddress("tP"               , &tP                );
	fTree->SetBranchAddress("tPx"              , &tPx               );
	fTree->SetBranchAddress("tPy"              , &tPy               );
	fTree->SetBranchAddress("tPz"              , &tPz               );
	fTree->SetBranchAddress("tTriSigma"        , &tTriSigma         );
	fTree->SetBranchAddress("tTriDedx"         , &tTriDedx          );
	fTree->SetBranchAddress("tDcaXY"           , &tDcaXY            );
	fTree->SetBranchAddress("tDcaZ"            , &tDcaZ             );
	fTree->SetBranchAddress("tSigmaYX"         , &tSigmaYX          );
	fTree->SetBranchAddress("tSigmaXYZ"        , &tSigmaXYZ           );
	fTree->SetBranchAddress("tSigmaZ"          , &tSigmaZ             );
	fTree->SetBranchAddress("tMCtrue"          , &tMCtrue           );
	fTree->SetBranchAddress("tTrigMB"          , &tTrigMB           );
	fTree->SetBranchAddress("tTrigHMV0"        , &tTrigHMV0         );
	fTree->SetBranchAddress("tTrigHMSPD"       , &tTrigHMSPD        );
	fTree->SetBranchAddress("tTrigHNU"         , &tTrigHNU          );
	fTree->SetBranchAddress("tTrigHQU"         , &tTrigHQU          );
	fTree->SetBranchAddress("tMagField"        , &tMagField         );
	fTree->SetBranchAddress("tTRDvalid"        , &tTRDvalid         );
	fTree->SetBranchAddress("tTRDPid"          , &tTRDPid           );
	fTree->SetBranchAddress("tTRDnTracklets"   , &tTRDnTracklets    );
	fTree->SetBranchAddress("tTRDPt"           , &tTRDPt            );
	fTree->SetBranchAddress("tTRDLayerMask"    , &tTRDLayerMask     );
	fTree->SetBranchAddress("tTRDSagitta"      , &tTRDSagitta       );
	fTree->SetBranchAddress("tTRDStack"        , &tTRDStack         );
	fTree->SetBranchAddress("tTRDSector"       , &tTRDSector        );
	fTree->SetBranchAddress("tTRDPID0"         , &tTRDPID0          );
	fTree->SetBranchAddress("tTRDPID1"         , &tTRDPID1          );
	fTree->SetBranchAddress("tTRDPID2"         , &tTRDPID2          );
	fTree->SetBranchAddress("tTRDPID3"         , &tTRDPID3          );
	fTree->SetBranchAddress("tTRDPID4"         , &tTRDPID4          );
	fTree->SetBranchAddress("tTRDPID5"         , &tTRDPID5          );
	fTree->SetBranchAddress("tnTPCcluster"     , &tnTPCcluster      );
	fTree->SetBranchAddress("tnITScluster"     , &tnITScluster      );
	fTree->SetBranchAddress("tTPCchi2"         , &tTPCchi2          );
	fTree->SetBranchAddress("tSPDFiredChips0"  , &tSPDFiredChips0   );
	fTree->SetBranchAddress("tSPDFiredChips1"  , &tSPDFiredChips1   );
	fTree->SetBranchAddress("tSPDTracklets"    , &tSPDTracklets     );
	fTree->SetBranchAddress("tSPDCluster"      , &tSPDCluster       );
	fTree->SetBranchAddress("tV0Multiplicity"  , &tV0Multiplicity   );
	fTree->SetBranchAddress("tNTracks"         , &tNTracks          );
	fTree->SetBranchAddress("tMultV0M"         , &tMultV0M          );
	fTree->SetBranchAddress("tMultOfV0M"       , &tMultOfV0M        );
	fTree->SetBranchAddress("tMultSPDTracklet" , &tMultSPDTracklet  );
	fTree->SetBranchAddress("tMultSPDCluster"  , &tMultSPDCluster   );
	fTree->SetBranchAddress("tMultRef05"       , &tMultRef05        );
	fTree->SetBranchAddress("tMultRef08"       , &tMultRef08        );
	fTree->SetBranchAddress("tKink"            , &tKink             );
	fTree->SetBranchAddress("tTPCrefit"        , &tTPCrefit         );
	fTree->SetBranchAddress("tITSrefit"        , &tITSrefit         );
	fTree->SetBranchAddress("tTOFSignalTri"    , &tTOFSignalTri     );
	fTree->SetBranchAddress("tPrimary"         , &tPrimary          );
	fTree->SetBranchAddress("tWeak"            , &tWeak             );
	fTree->SetBranchAddress("tMaterial"        , &tMaterial         );
	fTree->SetBranchAddress("tPdg"			 , &tPdg			 	);
    }
void hadd(){
 system("/bin/bash -c ./hadden2.sh");
}