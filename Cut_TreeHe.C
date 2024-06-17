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
#include "Cut_TreeHe.h"

//local:
//TString resultPath = "/Users/matthiasherzer/alice/root_results";
//TString Folder = "/Users/matthiasherzer/alice/root_results/Rootfiles/He/HM";
// ext. hard drive: 
TString resultPath = "/Volumes/MyPassport/pass2/HeTri_pass2";
TString Folder = "/Volumes/MyPassport/pass2_WorkingTree/He";
TString periods16 = "deghijklop";
TString periods17 = "cefghijklmor"; //klmor + cefghij
TString periods18 = "bdefghilmnop";  //bdefghilmnop
TString rootFilePath = Folder + "/Rootfiles/";
TString rootfile16 = Folder + "/Rootfiles/Analysis_16.root";
TString rootfile17 = Folder + "/Rootfiles/Analysis_17.root";
TString rootfile18 = Folder + "/Rootfiles/Analysis_18.root";
enum cutNames             {DcaXY, DcaZ, TPCnSigma, TofSignal, TofSignal2};
const double cutConf[7] = {0.30,  0.30, 	5.0,            0,      5};

void Cut_TreeHe(){
	readData16();
    readData17();
    readData18();
    merge();
}
//_____________________________________________________________________________________________
bool Cut(){
    if (TMath::Abs(tDcaXY) > cutConf[0]) return false;
    if (TMath::Abs(tDcaZ) > cutConf[1]) return false;
    if (TMath::Abs(tHeSigma) > cutConf[2]) return false;
    //if (tTOFSignalHe < cutConf[3] || tTOFSignalHe > cutConf[4]) return false;
    return true;
}
//_____________________________________________________________________________________________
void readData16(){
	TCanvas *c1;
	TChain *fTreeData16 = new TChain("He3TriTree/treeHe");
	TFile * f16 = new TFile(rootfile16,"recreate");

    fTreeHeHM16 = new TTree("treeHeHM", "ftreeHeHM");
	fTreeHeHM16->Branch("tRunNumber"       , &tRunNumber       , "tRunNumber/I"       );
	fTreeHeHM16->Branch("tEventId"         , &tEventId         , "tEventId/l"         );	
	fTreeHeHM16->Branch("tPt"              , &tPt              , "tPt/D"              );
	fTreeHeHM16->Branch("tCharge"       , &tCharge       , "tCharge/D"       );
	fTreeHeHM16->Branch("tE"               , &tE               , "tE/D"               );
	fTreeHeHM16->Branch("tY"               , &tY               , "tY/D"               );
	fTreeHeHM16->Branch("tEta"             , &tEta             , "tEta/D"             );
	fTreeHeHM16->Branch("tPhi"             , &tPhi             , "tPhi/D"             );
	fTreeHeHM16->Branch("tP"               , &tP               , "tP/D"               );
	fTreeHeHM16->Branch("tPx"              , &tPx              , "tPx/D"              );
	fTreeHeHM16->Branch("tPy"              , &tPy              , "tPy/D"              );
	fTreeHeHM16->Branch("tPz"              , &tPz              , "tPz/D"              );
	fTreeHeHM16->Branch("tHeSigma"        , &tHeSigma        , "tHeSigma/D"        );
	fTreeHeHM16->Branch("tHeDEdx"         , &tHeDEdx         , "tHeDEdx/D"         );
	fTreeHeHM16->Branch("tDcaXY"           , &tDcaXY           , "tDcaXY/D"           );
	fTreeHeHM16->Branch("tDcaZ"            , &tDcaZ            , "tDcaZ/D"            );
	fTreeHeHM16->Branch("tSigmaYX"         , &tSigmaYX         , "tSigmaYX/D"         );
	fTreeHeHM16->Branch("tSigmaXYZ"        , &tSigmaXYZ        , "tSigmaXYZ/D"        );
	fTreeHeHM16->Branch("tSigmaZ"          , &tSigmaZ          , "tSigmaZ/D"          );
	fTreeHeHM16->Branch("tMCtrue"          , &tMCtrue          , "tMCtrue/I"          );
	fTreeHeHM16->Branch("tTrigMB"          , &tTrigMB          , "tTrigMB/I"          );
	fTreeHeHM16->Branch("tTrigHMV0"        , &tTrigHMV0        , "tTrigHMV0/I"        );
	fTreeHeHM16->Branch("tTrigHMSPD"       , &tTrigHMSPD       , "tTrigHMSPD/I"       );
	fTreeHeHM16->Branch("tTrigHNU"         , &tTrigHNU         , "tTrigHNU/I"         );
	fTreeHeHM16->Branch("tTrigHQU"         , &tTrigHQU         , "tTrigHQU/I"         );
	fTreeHeHM16->Branch("tMagField"        , &tMagField        , "tMagField/D"        );
	fTreeHeHM16->Branch("tTRDvalid"        , &tTRDvalid        , "tTRDvalid/I"        );
	fTreeHeHM16->Branch("tTRDPid"          , &tTRDPid          , "tTRDPid/I"          );
	fTreeHeHM16->Branch("tTRDnTracklets"   , &tTRDnTracklets   , "tTRDnTracklets/I"   );
	fTreeHeHM16->Branch("tTRDPt"           , &tTRDPt           , "tTRDPt/I"           );
	fTreeHeHM16->Branch("tTRDLayerMask"    , &tTRDLayerMask    , "tTRDLayerMask/I"    );
	fTreeHeHM16->Branch("tTRDSagitta"      , &tTRDSagitta      , "tTRDSagitta/D"      );
	fTreeHeHM16->Branch("tTRDStack"        , &tTRDStack        , "tTRDStack/I"        );
	fTreeHeHM16->Branch("tTRDSector"       , &tTRDSector       , "tTRDSector/I"       );
	fTreeHeHM16->Branch("tTRDPID0"         , &tTRDPID0         , "tTRDPID0/i"         );
	fTreeHeHM16->Branch("tTRDPID1"         , &tTRDPID1         , "tTRDPID1/i"         );
	fTreeHeHM16->Branch("tTRDPID2"         , &tTRDPID2         , "tTRDPID2/i"         );
	fTreeHeHM16->Branch("tTRDPID3"         , &tTRDPID3         , "tTRDPID3/i"         );
	fTreeHeHM16->Branch("tTRDPID4"         , &tTRDPID4         , "tTRDPID4/i"         );
	fTreeHeHM16->Branch("tTRDPID5"         , &tTRDPID5         , "tTRDPID5/i"         );
	fTreeHeHM16->Branch("tnTPCcluster"     , &tnTPCcluster     , "tnTPCcluster/D"     );
	fTreeHeHM16->Branch("tnITScluster"     , &tnITScluster     , "tnITScluster/D"     );
	fTreeHeHM16->Branch("tTPCchi2"         , &tTPCchi2         , "tTPCchi2/D"         );
	fTreeHeHM16->Branch("tSPDFiredChips0"  , &tSPDFiredChips0  , "tSPDFiredChips0/D"  );
	fTreeHeHM16->Branch("tSPDFiredChips1"  , &tSPDFiredChips1  , "tSPDFiredChips1/D"  );
	fTreeHeHM16->Branch("tSPDTracklets"    , &tSPDTracklets    , "tSPDTracklets/D"    );
	fTreeHeHM16->Branch("tSPDCluster"      , &tSPDCluster      , "tSPDCluster/D"      );
	fTreeHeHM16->Branch("tV0Multiplicity"  , &tV0Multiplicity  , "tV0Multiplicity/D"  );
	fTreeHeHM16->Branch("tNTracks"         , &tNTracks         , "tNTracks/D"         );
	fTreeHeHM16->Branch("tMultV0M"         , &tMultV0M         , "tMultV0M/D"         );
	fTreeHeHM16->Branch("tMultOfV0M"       , &tMultOfV0M       , "tMultOfV0M/D"       );
	fTreeHeHM16->Branch("tMultSPDTracklet" , &tMultSPDTracklet , "tMultSPDTracklet/D" );
	fTreeHeHM16->Branch("tMultSPDCluster"  , &tMultSPDCluster  , "tMultSPDCluster/D"  );
	fTreeHeHM16->Branch("tMultRef05"       , &tMultRef05       , "tMultRef05/D"       );
	fTreeHeHM16->Branch("tMultRef08"       , &tMultRef08       , "tMultRef08/D"       );
	fTreeHeHM16->Branch("tKink"            , &tKink            , "tKink/I"            );
	fTreeHeHM16->Branch("tTPCrefit"        , &tTPCrefit        , "tTPCrefit/I"        );
	fTreeHeHM16->Branch("tITSrefit"        , &tITSrefit        , "tITSrefit/I"        );
	fTreeHeHM16->Branch("tTOFSignalHe"    , &tTOFSignalHe    , "tTOFSignalHe/D"    );
	fTreeHeHM16->Branch("tPrimary"         , &tPrimary         , "tPrimary/I"         );
	fTreeHeHM16->Branch("tWeak"            , &tWeak            , "tWeak/I"            );
	fTreeHeHM16->Branch("tMaterial"        , &tMaterial        , "tMaterial/I"        );
	fTreeHeHM16->Branch("tPdg"			 ,    &tPdg			 ,    "tPdg/I");


	for (Int_t i = 0; i < periods16.Length(); i++){
		fTreeData16->Add(resultPath + "/Data/LHC16"  + periods16(i,1)+ "/AnalysisResults.root");
		}


	setTreeBranch(fTreeData16);

	Long64_t nEntries = (Long64_t)fTreeData16->GetEntries();
	std::cout << "Number of entries: "<< nEntries << std::endl;
	Long64_t counter = 0;
	for (Long64_t i=0; i<nEntries; i++) {
		if (i % (nEntries/2000) == 0) 
			cout << Form("\rreading data tree: %1.2f %%", 100. * i / (double) nEntries) << flush; 
		fTreeData16->GetEntry(i);
		
        if (TMath::Abs(tY) > 0.5)	continue;	// set rapidity range
		

		if (!tTrigHMV0 && !tTrigHMSPD && !tTrigHNU && !tTrigHQU) continue;
        //if (!tTrigHMV0 && !tTrigHMSPD) continue;

        //if (!tTrigHNU && !tTrigHQU) continue;	//Nuclei Trigger  
        if (Cut())
        {
			counter++;
            fTreeHeHM16->Fill();
        }
	}
	std::cout << "Number of filled in entries" << counter << std::endl;
	cout << endl;
	fTreeHeHM16->Write(0, TObject::kOverwrite);
	f16->Close();
}	
//___________________________________________________________________________________________
void readData17(){
	TCanvas *c2;
	TChain *fTreeData17 = new TChain("He3TriTree/treeHe");
	TFile * f17 = new TFile(rootfile17,"recreate");

    fTreeHeHM17 = new TTree("treeHeHM", "ftreeHeHM");
	fTreeHeHM17->Branch("tRunNumber"       , &tRunNumber       , "tRunNumber/I"       );
	fTreeHeHM17->Branch("tEventId"         , &tEventId         , "tEventId/l"         );	
	fTreeHeHM17->Branch("tPt"              , &tPt              , "tPt/D"              );
	fTreeHeHM17->Branch("tCharge"       , &tCharge       , "tCharge/D"       );
	fTreeHeHM17->Branch("tE"               , &tE               , "tE/D"               );
	fTreeHeHM17->Branch("tY"               , &tY               , "tY/D"               );
	fTreeHeHM17->Branch("tEta"             , &tEta             , "tEta/D"             );
	fTreeHeHM17->Branch("tPhi"             , &tPhi             , "tPhi/D"             );
	fTreeHeHM17->Branch("tP"               , &tP               , "tP/D"               );
	fTreeHeHM17->Branch("tPx"              , &tPx              , "tPx/D"              );
	fTreeHeHM17->Branch("tPy"              , &tPy              , "tPy/D"              );
	fTreeHeHM17->Branch("tPz"              , &tPz              , "tPz/D"              );
	fTreeHeHM17->Branch("tHeSigma"        , &tHeSigma        , "tHeSigma/D"        );
	fTreeHeHM17->Branch("tHeDEdx"         , &tHeDEdx         , "tHeDEdx/D"         );
	fTreeHeHM17->Branch("tDcaXY"           , &tDcaXY           , "tDcaXY/D"           );
	fTreeHeHM17->Branch("tDcaZ"            , &tDcaZ            , "tDcaZ/D"            );
	fTreeHeHM17->Branch("tSigmaYX"         , &tSigmaYX         , "tSigmaYX/D"         );
	fTreeHeHM17->Branch("tSigmaXYZ"        , &tSigmaXYZ        , "tSigmaXYZ/D"        );
	fTreeHeHM17->Branch("tSigmaZ"          , &tSigmaZ          , "tSigmaZ/D"          );
	fTreeHeHM17->Branch("tMCtrue"          , &tMCtrue          , "tMCtrue/I"          );
	fTreeHeHM17->Branch("tTrigMB"          , &tTrigMB          , "tTrigMB/I"          );
	fTreeHeHM17->Branch("tTrigHMV0"        , &tTrigHMV0        , "tTrigHMV0/I"        );
	fTreeHeHM17->Branch("tTrigHMSPD"       , &tTrigHMSPD       , "tTrigHMSPD/I"       );
	fTreeHeHM17->Branch("tTrigHNU"         , &tTrigHNU         , "tTrigHNU/I"         );
	fTreeHeHM17->Branch("tTrigHQU"         , &tTrigHQU         , "tTrigHQU/I"         );
	fTreeHeHM17->Branch("tMagField"        , &tMagField        , "tMagField/D"        );
	fTreeHeHM17->Branch("tTRDvalid"        , &tTRDvalid        , "tTRDvalid/I"        );
	fTreeHeHM17->Branch("tTRDPid"          , &tTRDPid          , "tTRDPid/I"          );
	fTreeHeHM17->Branch("tTRDnTracklets"   , &tTRDnTracklets   , "tTRDnTracklets/I"   );
	fTreeHeHM17->Branch("tTRDPt"           , &tTRDPt           , "tTRDPt/I"           );
	fTreeHeHM17->Branch("tTRDLayerMask"    , &tTRDLayerMask    , "tTRDLayerMask/I"    );
	fTreeHeHM17->Branch("tTRDSagitta"      , &tTRDSagitta      , "tTRDSagitta/D"      );
	fTreeHeHM17->Branch("tTRDStack"        , &tTRDStack        , "tTRDStack/I"        );
	fTreeHeHM17->Branch("tTRDSector"       , &tTRDSector       , "tTRDSector/I"       );
	fTreeHeHM17->Branch("tTRDPID0"         , &tTRDPID0         , "tTRDPID0/i"         );
	fTreeHeHM17->Branch("tTRDPID1"         , &tTRDPID1         , "tTRDPID1/i"         );
	fTreeHeHM17->Branch("tTRDPID2"         , &tTRDPID2         , "tTRDPID2/i"         );
	fTreeHeHM17->Branch("tTRDPID3"         , &tTRDPID3         , "tTRDPID3/i"         );
	fTreeHeHM17->Branch("tTRDPID4"         , &tTRDPID4         , "tTRDPID4/i"         );
	fTreeHeHM17->Branch("tTRDPID5"         , &tTRDPID5         , "tTRDPID5/i"         );
	fTreeHeHM17->Branch("tnTPCcluster"     , &tnTPCcluster     , "tnTPCcluster/D"     );
	fTreeHeHM17->Branch("tnITScluster"     , &tnITScluster     , "tnITScluster/D"     );
	fTreeHeHM17->Branch("tTPCchi2"         , &tTPCchi2         , "tTPCchi2/D"         );
	fTreeHeHM17->Branch("tSPDFiredChips0"  , &tSPDFiredChips0  , "tSPDFiredChips0/D"  );
	fTreeHeHM17->Branch("tSPDFiredChips1"  , &tSPDFiredChips1  , "tSPDFiredChips1/D"  );
	fTreeHeHM17->Branch("tSPDTracklets"    , &tSPDTracklets    , "tSPDTracklets/D"    );
	fTreeHeHM17->Branch("tSPDCluster"      , &tSPDCluster      , "tSPDCluster/D"      );
	fTreeHeHM17->Branch("tV0Multiplicity"  , &tV0Multiplicity  , "tV0Multiplicity/D"  );
	fTreeHeHM17->Branch("tNTracks"         , &tNTracks         , "tNTracks/D"         );
	fTreeHeHM17->Branch("tMultV0M"         , &tMultV0M         , "tMultV0M/D"         );
	fTreeHeHM17->Branch("tMultOfV0M"       , &tMultOfV0M       , "tMultOfV0M/D"       );
	fTreeHeHM17->Branch("tMultSPDTracklet" , &tMultSPDTracklet , "tMultSPDTracklet/D" );
	fTreeHeHM17->Branch("tMultSPDCluster"  , &tMultSPDCluster  , "tMultSPDCluster/D"  );
	fTreeHeHM17->Branch("tMultRef05"       , &tMultRef05       , "tMultRef05/D"       );
	fTreeHeHM17->Branch("tMultRef08"       , &tMultRef08       , "tMultRef08/D"       );
	fTreeHeHM17->Branch("tKink"            , &tKink            , "tKink/I"            );
	fTreeHeHM17->Branch("tTPCrefit"        , &tTPCrefit        , "tTPCrefit/I"        );
	fTreeHeHM17->Branch("tITSrefit"        , &tITSrefit        , "tITSrefit/I"        );
	fTreeHeHM17->Branch("tTOFSignalHe"    , &tTOFSignalHe    , "tTOFSignalHe/D"    );
	fTreeHeHM17->Branch("tPrimary"         , &tPrimary         , "tPrimary/I"         );
	fTreeHeHM17->Branch("tWeak"            , &tWeak            , "tWeak/I"            );
	fTreeHeHM17->Branch("tMaterial"        , &tMaterial        , "tMaterial/I"        );
	fTreeHeHM17->Branch("tPdg"			 ,    &tPdg			 ,    "tPdg/I");

	for (Int_t i = 0; i < periods17.Length(); i++){
		fTreeData17->Add(resultPath + "/Data/LHC17"  + periods17(i,1)+ "/AnalysisResults.root");
		}


	setTreeBranch(fTreeData17);

	Long64_t nEntries = (Long64_t)fTreeData17->GetEntries();
	std::cout << "Number of entries: "<< nEntries << std::endl;
	Long64_t counter = 0;
	for (Long64_t i=0; i<nEntries; i++) {
		if (i % (nEntries/2000) == 0) 
			cout << Form("\rreading data tree: %1.2f %%", 100. * i / (double) nEntries) << flush; 
		fTreeData17->GetEntry(i);
		

		
        if (TMath::Abs(tY) > 0.5)	continue;	// set rapidity range
		
        if (!tTrigHMV0 && !tTrigHMSPD && !tTrigHNU && !tTrigHQU) continue;
		//if (!tTrigHMV0 && !tTrigHMSPD) continue;
        //if (!tTrigHNU && !tTrigHQU) continue;	//Nuclei Trigger  
        if (Cut())
        {
			counter++;
            fTreeHeHM17->Fill();
        }
        

	}
	std::cout << "Number of filled in entries" << counter << std::endl;
	cout << endl;
	fTreeHeHM17->Write(0, TObject::kOverwrite);
	f17->Close();
}	
//________________________________________________________________________________________________________________________
void readData18(){
	TCanvas *c3;
	TChain *fTreeData18 = new TChain("He3TriTree/treeHe");
    TFile * f18 = new TFile(rootfile18,"recreate");

    fTreeHeHM18 = new TTree("treeHeHM", "ftreeHeHM");
	fTreeHeHM18->Branch("tRunNumber"       , &tRunNumber       , "tRunNumber/I"       );
	fTreeHeHM18->Branch("tEventId"         , &tEventId         , "tEventId/l"         );	
	fTreeHeHM18->Branch("tPt"              , &tPt              , "tPt/D"              );
	fTreeHeHM18->Branch("tCharge"       , &tCharge       , "tCharge/D"       );
	fTreeHeHM18->Branch("tE"               , &tE               , "tE/D"               );
	fTreeHeHM18->Branch("tY"               , &tY               , "tY/D"               );
	fTreeHeHM18->Branch("tEta"             , &tEta             , "tEta/D"             );
	fTreeHeHM18->Branch("tPhi"             , &tPhi             , "tPhi/D"             );
	fTreeHeHM18->Branch("tP"               , &tP               , "tP/D"               );
	fTreeHeHM18->Branch("tPx"              , &tPx              , "tPx/D"              );
	fTreeHeHM18->Branch("tPy"              , &tPy              , "tPy/D"              );
	fTreeHeHM18->Branch("tPz"              , &tPz              , "tPz/D"              );
	fTreeHeHM18->Branch("tHeSigma"        , &tHeSigma        , "tHeSigma/D"        );
	fTreeHeHM18->Branch("tHeDEdx"         , &tHeDEdx         , "tHeDEdx/D"         );
	fTreeHeHM18->Branch("tDcaXY"           , &tDcaXY           , "tDcaXY/D"           );
	fTreeHeHM18->Branch("tDcaZ"            , &tDcaZ            , "tDcaZ/D"            );
	fTreeHeHM18->Branch("tSigmaYX"         , &tSigmaYX         , "tSigmaYX/D"         );
	fTreeHeHM18->Branch("tSigmaXYZ"        , &tSigmaXYZ        , "tSigmaXYZ/D"        );
	fTreeHeHM18->Branch("tSigmaZ"          , &tSigmaZ          , "tSigmaZ/D"          );
	fTreeHeHM18->Branch("tMCtrue"          , &tMCtrue          , "tMCtrue/I"          );
	fTreeHeHM18->Branch("tTrigMB"          , &tTrigMB          , "tTrigMB/I"          );
	fTreeHeHM18->Branch("tTrigHMV0"        , &tTrigHMV0        , "tTrigHMV0/I"        );
	fTreeHeHM18->Branch("tTrigHMSPD"       , &tTrigHMSPD       , "tTrigHMSPD/I"       );
	fTreeHeHM18->Branch("tTrigHNU"         , &tTrigHNU         , "tTrigHNU/I"         );
	fTreeHeHM18->Branch("tTrigHQU"         , &tTrigHQU         , "tTrigHQU/I"         );
	fTreeHeHM18->Branch("tMagField"        , &tMagField        , "tMagField/D"        );
	fTreeHeHM18->Branch("tTRDvalid"        , &tTRDvalid        , "tTRDvalid/I"        );
	fTreeHeHM18->Branch("tTRDPid"          , &tTRDPid          , "tTRDPid/I"          );
	fTreeHeHM18->Branch("tTRDnTracklets"   , &tTRDnTracklets   , "tTRDnTracklets/I"   );
	fTreeHeHM18->Branch("tTRDPt"           , &tTRDPt           , "tTRDPt/I"           );
	fTreeHeHM18->Branch("tTRDLayerMask"    , &tTRDLayerMask    , "tTRDLayerMask/I"    );
	fTreeHeHM18->Branch("tTRDSagitta"      , &tTRDSagitta      , "tTRDSagitta/D"      );
	fTreeHeHM18->Branch("tTRDStack"        , &tTRDStack        , "tTRDStack/I"        );
	fTreeHeHM18->Branch("tTRDSector"       , &tTRDSector       , "tTRDSector/I"       );
	fTreeHeHM18->Branch("tTRDPID0"         , &tTRDPID0         , "tTRDPID0/i"         );
	fTreeHeHM18->Branch("tTRDPID1"         , &tTRDPID1         , "tTRDPID1/i"         );
	fTreeHeHM18->Branch("tTRDPID2"         , &tTRDPID2         , "tTRDPID2/i"         );
	fTreeHeHM18->Branch("tTRDPID3"         , &tTRDPID3         , "tTRDPID3/i"         );
	fTreeHeHM18->Branch("tTRDPID4"         , &tTRDPID4         , "tTRDPID4/i"         );
	fTreeHeHM18->Branch("tTRDPID5"         , &tTRDPID5         , "tTRDPID5/i"         );
	fTreeHeHM18->Branch("tnTPCcluster"     , &tnTPCcluster     , "tnTPCcluster/D"     );
	fTreeHeHM18->Branch("tnITScluster"     , &tnITScluster     , "tnITScluster/D"     );
	fTreeHeHM18->Branch("tTPCchi2"         , &tTPCchi2         , "tTPCchi2/D"         );
	fTreeHeHM18->Branch("tSPDFiredChips0"  , &tSPDFiredChips0  , "tSPDFiredChips0/D"  );
	fTreeHeHM18->Branch("tSPDFiredChips1"  , &tSPDFiredChips1  , "tSPDFiredChips1/D"  );
	fTreeHeHM18->Branch("tSPDTracklets"    , &tSPDTracklets    , "tSPDTracklets/D"    );
	fTreeHeHM18->Branch("tSPDCluster"      , &tSPDCluster      , "tSPDCluster/D"      );
	fTreeHeHM18->Branch("tV0Multiplicity"  , &tV0Multiplicity  , "tV0Multiplicity/D"  );
	fTreeHeHM18->Branch("tNTracks"         , &tNTracks         , "tNTracks/D"         );
	fTreeHeHM18->Branch("tMultV0M"         , &tMultV0M         , "tMultV0M/D"         );
	fTreeHeHM18->Branch("tMultOfV0M"       , &tMultOfV0M       , "tMultOfV0M/D"       );
	fTreeHeHM18->Branch("tMultSPDTracklet" , &tMultSPDTracklet , "tMultSPDTracklet/D" );
	fTreeHeHM18->Branch("tMultSPDCluster"  , &tMultSPDCluster  , "tMultSPDCluster/D"  );
	fTreeHeHM18->Branch("tMultRef05"       , &tMultRef05       , "tMultRef05/D"       );
	fTreeHeHM18->Branch("tMultRef08"       , &tMultRef08       , "tMultRef08/D"       );
	fTreeHeHM18->Branch("tKink"            , &tKink            , "tKink/I"            );
	fTreeHeHM18->Branch("tTPCrefit"        , &tTPCrefit        , "tTPCrefit/I"        );
	fTreeHeHM18->Branch("tITSrefit"        , &tITSrefit        , "tITSrefit/I"        );
	fTreeHeHM18->Branch("tTOFSignalHe"    , &tTOFSignalHe   , "tTOFSignalHe/D"    );
	fTreeHeHM18->Branch("tPrimary"         , &tPrimary         , "tPrimary/I"         );
	fTreeHeHM18->Branch("tWeak"            , &tWeak            , "tWeak/I"            );
	fTreeHeHM18->Branch("tMaterial"        , &tMaterial        , "tMaterial/I"        );
	fTreeHeHM18->Branch("tPdg"			 , &tPdg			 , "tPdg/I");

	for (Int_t i = 0; i < periods18.Length(); i++){
		fTreeData18->Add(resultPath + "/Data/LHC18"  + periods18(i,1)+ "/AnalysisResults.root");
		}
	setTreeBranch(fTreeData18);

	Int_t nEntries = (Int_t)fTreeData18->GetEntries();
	std::cout << "Number of entries: "<< nEntries << std::endl;
	Long64_t counter = 0;
	for (Int_t i=0; i<nEntries; i++) {
		if (i % (nEntries/2000) == 0) 
			cout << Form("\rreading data tree: %1.2f %%", 100. * i / (double) nEntries) << flush; 
		fTreeData18->GetEntry(i);
		

		if (TMath::Abs(tY) > 0.5)	continue;	// set rapidity range
		if (!tTrigHMV0 && !tTrigHMSPD && !tTrigHNU && !tTrigHQU) continue;
		//if (!tTrigHMV0 && !tTrigHMSPD) continue;  
        //if (!tTrigHNU && !tTrigHQU) continue;	//Nuclei Trigger
        if (Cut())
        {
			counter++;
            fTreeHeHM18->Fill();
        }
        
	}
	std::cout << "Number of filled in entries" << counter << std::endl;
	cout << endl;
	fTreeHeHM18->Write(0, TObject::kOverwrite);
	f18->Close();
}
//_____________________________________________________________________________________________
void merge(){
    //ext. hard drive:
    gSystem->Exec("hadd -f '/Volumes/MyPassport/pass2_WorkingTree/He/Rootfiles/Analysis_merged.root' '/Volumes/MyPassport/pass2_WorkingTree/He/Rootfiles/Analysis_17.root' '/Volumes/MyPassport/pass2_WorkingTree/He/Rootfiles/Analysis_18.root'");
    //gSystem->Exec("rm -r '/Volumes/MyPassport/pass2_WorkingTree/He/Rootfiles/Analysis_17.root' '/Volumes/MyPassport/pass2_WorkingTree/He/Rootfiles/Analysis_18.root'");
    //local: 
    //gSystem->Exec("hadd -f '/Users/matthias/alice/root_results/He/Analysis_merged.root' '/Users/matthias/alice/root_results/He/Analysis_16.root' '/Users/matthiasherzer/alice/root_results/Rootfiles/He/HM/Analysis_17.root''/Users/matthiasherzer/alice/root_results/Rootfiles/He/HM/Analysis_18.root'");
    //gSystem->Exec("rm -r /Users/matthiasherzer/alice/root_results/Rootfiles/Analysis_17.root /Users/matthiasherzer/alice/root_results/Rootfiles/Analysis_18.root");

}
//_____________________________________________________________________________________________
void setTreeBranch(TTree *fTree) {
	fTree->SetBranchAddress("tRunNumber"       , &tRunNumber       );
	fTree->SetBranchAddress("tEventId"         , &tEventId         );	
	fTree->SetBranchAddress("tPt"              , &tPt              );
	fTree->SetBranchAddress("tCharge"       , &tCharge         );
	fTree->SetBranchAddress("tE"               , &tE               );
	fTree->SetBranchAddress("tY"               , &tY               );
	fTree->SetBranchAddress("tEta"             , &tEta             );
	fTree->SetBranchAddress("tPhi"             , &tPhi             );
	fTree->SetBranchAddress("tP"               , &tP               );
	fTree->SetBranchAddress("tPx"              , &tPx              );
	fTree->SetBranchAddress("tPy"              , &tPy              );
	fTree->SetBranchAddress("tPz"              , &tPz              );
	fTree->SetBranchAddress("tHeSigma"        , &tHeSigma           );
	fTree->SetBranchAddress("tHeDEdx"         , &tHeDEdx            );
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
	fTree->SetBranchAddress("tTOFSignalHe"    , &tTOFSignalHe    );
	fTree->SetBranchAddress("tPrimary"         , &tPrimary         );
	fTree->SetBranchAddress("tWeak"            , &tWeak            );
	fTree->SetBranchAddress("tMaterial"        , &tMaterial        );
	fTree->SetBranchAddress("tPdg"			 , &tPdg		);	
    }