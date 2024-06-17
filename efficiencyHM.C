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
#include "efficiencyHM.h"

enum cutNames             {DcaXY, DcaZ, TriTPCnSigma, TPCnCls, TPCchi2, TPCrefit, Kink, TRDnTracklets, ITSnCluster, ITSrefit};
const double cutConf[10] = {0.15,  0.15, 	2.0, 		120,      2,       1,        1,         1,           1,           0};
const double cutYTri = 0.5; //set rapidity range: -0.5 - 0.5
const double cutConfHe[8] = {0.15,  0.15, 3.0,         70,      2,       1,        1	,		1};
TString periods16 = "deghijklop";
TString periods17 = "cefghijklmor";
TString periods18 = "bdefghilmnop";
TString resultPath = "/Users/matthias/alice/root_results/MC";
TString resultfile = "/Users/matthias/alice/Master/Makros/result/correction/correction.root";
//_________________________________________________________________________________________________________
void efficiencyHM(){
    HeTriEff();
	HeEff();
}
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
//___________________________________________________________________________
void setTreeBranchGenH3(TTree *fTree){
	fTree->SetBranchAddress("tGenCharge"  , &tGenCharge );
	fTree->SetBranchAddress("tGenPt"      , &tGenPt     );
	fTree->SetBranchAddress("tGenY"       , &tGenY      );
	fTree->SetBranchAddress("tGenPrimary" , &tGenPrimary);
	fTree->SetBranchAddress("pdgCode"     , &pdgCode    );
	fTree->SetBranchAddress("tMagField"   , &tMagField  );
	fTree->SetBranchAddress("tTrigMB"     , &tTrigMB    );
	fTree->SetBranchAddress("tTrigHMV0"   , &tTrigHMV0  );
	fTree->SetBranchAddress("tTrigHMSPD"  , &tTrigHMSPD );
	fTree->SetBranchAddress("tTrigHNU"    , &tTrigHNU   );
	fTree->SetBranchAddress("tTrigHQU"    , &tTrigHQU   );
}
//_________________________________________________________________________________________________________
void setTreeBranchHe(TTree *fTree) {
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
//___________________________________________________________________________
void setTreeBranchGenHe(TTree *fTree){
	fTree->SetBranchAddress("tGenCharge"  , &tGenCharge );
	fTree->SetBranchAddress("tGenPt"      , &tGenPt     );
	fTree->SetBranchAddress("tGenY"       , &tGenY      );
	fTree->SetBranchAddress("tGenPrimary" , &tGenPrimary);
	fTree->SetBranchAddress("pdgCode"     , &pdgCode    );
	fTree->SetBranchAddress("tMagField"   , &tMagField  );
	fTree->SetBranchAddress("tTrigMB"     , &tTrigMB    );
	fTree->SetBranchAddress("tTrigHMV0"   , &tTrigHMV0  );
	fTree->SetBranchAddress("tTrigHMSPD"  , &tTrigHMSPD );
	fTree->SetBranchAddress("tTrigHNU"    , &tTrigHNU   );
	fTree->SetBranchAddress("tTrigHQU"    , &tTrigHQU   );
}
//___________________________________________________________________________
void HeTriEff(){
TFile * f = new TFile(resultfile,"recreate");
TChain *fTreeDataGenH3= new TChain("He3TriTree/treeGenTri");
for (Int_t i = 0; i < periods16.Length(); i++){
  fTreeDataGenH3->Add(resultPath+ "/LHC16"  + periods16(i,1)+ "/AnalysisResults.root");
  }
for (Int_t i = 0; i < periods17.Length(); i++){
  fTreeDataGenH3->Add(resultPath+ "/LHC17"  + periods17(i,1)+ "/AnalysisResults.root");
  }
for (Int_t i = 0; i < periods18.Length(); i++){
  fTreeDataGenH3->Add(resultPath+ "/LHC18"  + periods18(i,1)+ "/AnalysisResults.root");
  }

setTreeBranchGenH3(fTreeDataGenH3);
TH1D* hGen = new TH1D("hGen", "Generated;#it{p}_{T} (GeV/#it{c});Counts", 100, 0 ,10);
hGen->SetStats(0);
hGen->Sumw2();
TH1D* hGenAnti = new TH1D("hGenAnti", "Generated;#it{p}_{T} (GeV/#it{c});Counts", 100, 0 ,10);
hGenAnti->SetStats(0);
hGenAnti->Sumw2();
TH1D* hGenComb = new TH1D("hGenComb", "Generated;#it{p}_{T} (GeV/#it{c});Counts", 100, 0 ,10);
hGenComb->SetStats(0);
hGenComb->Sumw2();
Int_t nEntries = (Int_t)fTreeDataGenH3->GetEntries();
	for (Int_t i=0; i<nEntries; i++) {
		if (i % (nEntries/2000) == 0) 
			cout << Form("\rreading data tree: %1.2f %%", 100. * i / (double) nEntries) << flush; 
		fTreeDataGenH3->GetEntry(i);
		

		if (TMath::Abs(tGenY) > cutYTri)	continue;	// set rapidity range

		if (!tTrigHMV0 && !tTrigHMSPD) continue;	

		int particle = 0;
		if (tGenCharge < 0) particle = 1;
        if (tGenPrimary > 0){
            hGenComb->Fill(tGenPt);
		    if (particle == 0){
                hGen->Fill(tGenPt);
            }
            else if (particle == 1){
                hGenAnti->Fill(tGenPt);
            }
		}		
	}
	cout << endl;
hGen->Write(0, TObject::kOverwrite);
hGenAnti->Write(0, TObject::kOverwrite);
hGenComb->Write(0, TObject::kOverwrite);

TChain *fTreeDataH3= new TChain("He3TriTree/treeTri");
for (Int_t i = 0; i < periods16.Length(); i++){
  fTreeDataH3->Add(resultPath+ "/LHC16"  + periods16(i,1)+ "/AnalysisResults.root");
  }
for (Int_t i = 0; i < periods17.Length(); i++){
  fTreeDataH3->Add(resultPath+ "/LHC17"  + periods17(i,1)+ "/AnalysisResults.root");
  }
for (Int_t i = 0; i < periods18.Length(); i++){
  fTreeDataH3->Add(resultPath+ "/LHC18"  + periods18(i,1)+ "/AnalysisResults.root");
}
setTreeBranchH3(fTreeDataH3);
TH1D* hRec = new TH1D("hRec", "Reconstructed;#it{p}_{T} (GeV/#it{c});Counts", 100, 0 ,10);
hRec->SetStats(0);
hRec->Sumw2();
TH1D* hRecAnti = new TH1D("hRecAnti", "Reconstructed;#it{p}_{T} (GeV/#it{c});Counts", 100, 0 ,10);
hRecAnti->SetStats(0);
hRecAnti->Sumw2();
TH1D* hRecComb = new TH1D("hRecComb", "Reconstructed;#it{p}_{T} (GeV/#it{c});Counts", 100, 0 ,10);
hRecComb->SetStats(0);
hRecComb->Sumw2();
int mode = 1;
Int_t nEntriesRec = (Int_t)fTreeDataH3->GetEntries();
	for (Int_t i=0; i<nEntriesRec; i++) {
		if (i % (nEntriesRec/2000) == 0) 
			cout << Form("\rreading data tree: %1.2f %%", 100. * i / (double) nEntriesRec) << flush; 
		fTreeDataH3->GetEntry(i);
		

		if (TMath::Abs(tY) > cutYTri)	continue;	// set rapidity range

		if (!tTrigHMV0 && !tTrigHMSPD) continue;	

		int particle = 0;
		if (tChargeTri < 0) particle = 1;
        if (tTOFSignalTri > 7.04 && tTOFSignalTri < 8.91 && tMCtrue > 0 && tPrimary > 0){
		    if (Cut(mode)) {
                hRecComb->Fill(tPt);
			    if (particle == 0){
                    hRec->Fill(tPt);
                }
                else if (particle == 1){
                    hRecAnti->Fill(tPt);
                }
		    }		
        }
	}
	cout << endl;
hRec->Write(0, TObject::kOverwrite);
hRecAnti->Write(0, TObject::kOverwrite);
hRecComb->Write(0, TObject::kOverwrite);

TH1D* hEff = (TH1D*) hRec->Clone("hEff");
hEff->SetTitle("acceptance x efficiency;#it{p}_{T} (GeV/#it{c});acc x eff");
hEff->Divide(hGen);
hEff->Write(0, TObject::kOverwrite);
TH1D* hEffAnti = (TH1D*) hRecAnti->Clone("hEffAnti");
hEffAnti->SetTitle("acceptance x efficiency;#it{p}_{T} (GeV/#it{c});acc x eff");
hEffAnti->Divide(hGenAnti);
hEffAnti->Write(0, TObject::kOverwrite);

TCanvas *c = new TCanvas("c", "H3", 1920, 1080);
c->Divide(3);
c->cd(1);
gPad->SetLeftMargin(0.18);
hGen->Draw();
TLegend *legend1 = new TLegend(0.4474743,0.6709248,0.8158938,0.7531743,NULL,"brNDC");
	legend1->SetBorderSize(0);
	legend1->SetFillStyle(0);
	//legend1->AddEntry(yieldCombined[2], "#frac{{}^{3}H}{{}^{3}He}", "lep");
	legend1->AddEntry((TObject*)0, "This work ", "");
	legend1->AddEntry((TObject*)0, "ALICE pp #sqrt{s} = 13 TeV ", "");
	legend1->AddEntry((TObject*)0, "Particle: {}^{3}H", "");
	legend1->AddEntry((TObject*)0, "High-multiplicity trigger", "");
	legend1->SetEntrySeparation(0.1);
	legend1->SetTextFont(43);
	legend1->SetTextSize(16);
	legend1->Draw();
c->cd(2);
gPad->SetLeftMargin(0.18);
hRec->Draw();
c->cd(3);
gPad->SetLeftMargin(0.18);
hEff->Draw();
c->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/accxeff/accxeffH3.pdf");
c->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/accxeff/accxeffH3.root");
TCanvas *c12 = new TCanvas("c12", "H3", 1600, 1600);
c12->cd();
c12->SetLeftMargin(0.15);
c12->SetBottomMargin(0.15);
hEff->SetTitle("");
hEff->SetLineWidth(5);
hEff->SetMarkerStyle(20);
hEff->SetLineColor(kBlack);
hEff->GetYaxis()->SetLabelFont(42);
hEff->GetYaxis()->SetLabelSize(0.05);
hEff->GetYaxis()->SetTitleSize(0.05);
hEff->GetYaxis()->SetTitleFont(42);
hEff->GetXaxis()->SetLabelFont(42);
hEff->GetXaxis()->SetLabelSize(0.05);
hEff->GetXaxis()->SetTitleOffset(1);
hEff->GetXaxis()->SetTitleFont(42);
hEff->GetXaxis()->SetTitleSize(0.05);
hEff->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
hEff->Draw();
TLegend *legend12 = new TLegend(0.521625,0.664271,0.901048,0.873717,NULL,"brNDC");
legend12->SetBorderSize(0);
legend12->SetFillStyle(0);
//legend1->AddEntry(yieldCombined[2], "#frac{{}^{3}H}{{}^{3}He}", "lep");
legend12->AddEntry((TObject*)0, "This work ", "");
legend12->AddEntry((TObject*)0, "ALICE pp #sqrt{s} = 13 TeV ", "");
legend12->AddEntry((TObject*)0, "Particle: {}^{3}H", "");
legend12->AddEntry((TObject*)0, "High-multiplicity trigger", "");
legend12->SetEntrySeparation(.1);
legend12->SetFillStyle(0);
legend12->SetTextFont(42);
legend12->SetTextSize(0.042);
legend12->Draw();
c12->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/accxeff/accxeffH3_2.root");
c12->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/accxeff/accxeffH3_2.pdf");
TCanvas *c2 = new TCanvas("c2", "Anti-H3", 1920, 1080);
c2->cd();
c2->Divide(3);
c2->cd(1);
gPad->SetLeftMargin(0.18);
hGenAnti->Draw();
TLegend *legend2 = new TLegend(0.52281,0.672544,0.902372,0.872796,NULL,"brNDC");
	legend2->SetEntrySeparation(.1);
	legend2->SetBorderSize(0);
	legend2->SetFillStyle(0);
	//legend2->AddEntry(yieldCombined[2], "#frac{{}^{3}H}{{}^{3}He}", "lep");
	legend2->AddEntry((TObject*)0, "This work ", "");
	legend2->AddEntry((TObject*)0, "ALICE pp #sqrt{s} = 13 TeV ", "");
	legend2->AddEntry((TObject*)0, "Particle: {}^{3}#bar{H}", "");
	legend2->AddEntry((TObject*)0, "High-multiplicity trigger", "");
	legend2->SetTextFont(43);
	legend2->SetTextSize(16);
	legend2->Draw();
c2->cd(2);
gPad->SetLeftMargin(0.18);
hRecAnti->Draw();
c2->cd(3);
gPad->SetLeftMargin(0.18);
hEffAnti->Draw();
c2->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/accxeff/accxeffH3_Anti.pdf");
c2->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/accxeff/accxeffH3_Anti.root");
TCanvas *c22 = new TCanvas("c22", "Anti-H3", 1600, 1600);
c22->cd();
c22->SetLeftMargin(0.15);
c22->SetBottomMargin(0.15);
hEffAnti->Draw();
hEffAnti->SetLineWidth(5);
hEffAnti->SetMarkerStyle(20);
hEffAnti->SetLineColor(kBlack);
hEffAnti->GetYaxis()->SetLabelFont(42);
hEffAnti->GetYaxis()->SetLabelSize(0.05);
hEffAnti->GetYaxis()->SetTitleSize(0.05);
hEffAnti->GetYaxis()->SetTitleFont(42);
hEffAnti->GetXaxis()->SetLabelFont(42);
hEffAnti->GetXaxis()->SetLabelSize(0.05);
hEffAnti->GetXaxis()->SetTitleOffset(1);
hEffAnti->GetXaxis()->SetTitleFont(42);
hEffAnti->GetXaxis()->SetTitleSize(0.05);
hEffAnti->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
hEffAnti->SetTitle("");
TLegend *legend22 = new TLegend(0.521625,0.664271,0.901048,0.873717,NULL,"brNDC");
legend22->SetEntrySeparation(.1);
legend22->SetBorderSize(0);
legend22->SetFillStyle(0);
//legend2->AddEntry(yieldCombined[2], "#frac{{}^{3}H}{{}^{3}He}", "lep");
legend22->AddEntry((TObject*)0, "This work", "");
legend22->AddEntry((TObject*)0, "ALICE pp #sqrt{s} = 13 TeV ", "");
legend22->AddEntry((TObject*)0, "Particle: {}^{3}#bar{H}", "");
legend22->AddEntry((TObject*)0, "High-multiplicity trigger", "");
legend22->SetEntrySeparation(.1);
legend22->SetFillStyle(0);
legend22->SetTextFont(42);
legend22->SetTextSize(0.042);
legend22->Draw();
c22->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/accxeff/accxeffH3_Anti_2.root");
c22->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/accxeff/accxeffH3_Anti_2.pdf");
//___________________________________________________________________________________________________________
//Helium 3:
TChain *fTreeDataGenHe= new TChain("He3TriTree/treeGenHe");
for (Int_t i = 0; i < periods16.Length(); i++){
  fTreeDataGenHe->Add(resultPath+ "/LHC16"  + periods16(i,1)+ "/AnalysisResults.root");
  }
for (Int_t i = 0; i < periods17.Length(); i++){
  fTreeDataGenHe->Add(resultPath+ "/LHC17"  + periods17(i,1)+ "/AnalysisResults.root");
  }
for (Int_t i = 0; i < periods18.Length(); i++){
  fTreeDataGenHe->Add(resultPath+ "/LHC18"  + periods18(i,1)+ "/AnalysisResults.root");
  }

setTreeBranchGenHe(fTreeDataGenHe);
TH1D* hGenHe = new TH1D("hGenHe", "Generated;#it{p}_{T} (GeV/#it{c});Counts", 100, 0 ,10);
hGenHe->SetStats(0);
hGenHe->Sumw2();
TH1D* hGenHeAnti = new TH1D("hGenHeAnti", "Generated;#it{p}_{T} (GeV/#it{c});Counts", 100, 0 ,10);
hGenHeAnti->SetStats(0);
hGenHeAnti->Sumw2();
TH1D* hGenHeComb = new TH1D("hGenHeComb", "Generated;#it{p}_{T} (GeV/#it{c});Counts", 100, 0 ,10);
hGenHeComb->SetStats(0);
hGenHeComb->Sumw2();
int modeHe = 2;
Int_t nEntriesHe = (Int_t)fTreeDataGenHe->GetEntries();
	for (Int_t i=0; i<nEntriesHe; i++) {
		if (i % (nEntriesHe/2000) == 0) 
			cout << Form("\rreading data tree: %1.2f %%", 100. * i / (double) nEntriesHe) << flush; 
		fTreeDataGenHe->GetEntry(i);
		

		if (TMath::Abs(tGenY) > cutYTri)	continue;	// set rapidity range

		if (!tTrigHMV0 && !tTrigHMSPD) continue;	

		int particle = 0;
		if (tGenCharge < 0) particle = 1;
        if (tGenPrimary > 0){
            hGenHeComb->Fill(tGenPt);
		    if (particle == 0){
                hGenHe->Fill(tGenPt);
            }
            else if (particle == 1){
                hGenHeAnti->Fill(tGenPt);
            }
		}		
	}
	cout << endl;
hGenHe->Write(0, TObject::kOverwrite);
hGenHeAnti->Write(0, TObject::kOverwrite);
hGenHeComb->Write(0, TObject::kOverwrite);

TChain *fTreeDataHe= new TChain("He3TriTree/treeHe");
for (Int_t i = 0; i < periods16.Length(); i++){
  fTreeDataHe->Add(resultPath+ "/LHC16"  + periods16(i,1)+ "/AnalysisResults.root");
  }
for (Int_t i = 0; i < periods17.Length(); i++){
  fTreeDataHe->Add(resultPath+ "/LHC17"  + periods17(i,1)+ "/AnalysisResults.root");
  }
for (Int_t i = 0; i < periods18.Length(); i++){
  fTreeDataHe->Add(resultPath+ "/LHC18"  + periods18(i,1)+ "/AnalysisResults.root");
}
setTreeBranchHe(fTreeDataHe);
TH1D* hRecHe = new TH1D("hRecHe", "Reconstructed;#it{p}_{T} (GeV/#it{c});Counts", 100, 0 ,10);
hRecHe->SetStats(0);
hRecHe->Sumw2();
TH1D* hRecHeAnti = new TH1D("hRecHeAnti", "Reconstructed;#it{p}_{T} (GeV/#it{c});Counts", 100, 0 ,10);
hRecHeAnti->SetStats(0);
hRecHeAnti->Sumw2();
TH1D* hRecHeComb = new TH1D("hRecHeComb", "Reconstructed;#it{p}_{T} (GeV/#it{c});Counts", 100, 0 ,10);
hRecHeComb->SetStats(0);
hRecHeComb->Sumw2();
Int_t nEntriesRecHe = (Int_t)fTreeDataHe->GetEntries();
	for (Int_t i=0; i<nEntriesRecHe; i++) {
		if (i % (nEntriesRecHe/2000) == 0) 
			cout << Form("\rreading data tree: %1.2f %%", 100. * i / (double) nEntriesRecHe) << flush; 
		fTreeDataHe->GetEntry(i);
		

		if (TMath::Abs(tY) > cutYTri)	continue;	// set rapidity range

		if (!tTrigHMV0 && !tTrigHMSPD) continue;	

		int particle = 0;
		if (tCharge < 0) particle = 1;
        if (tTOFSignalHe > 1.75 && tTOFSignalHe < 2.39 && tMCtrue > 0 && tPrimary > 0){
		    if (Cut(modeHe)) {
                hRecHeComb->Fill(tPt);
			    if (particle == 0){
                    hRecHe->Fill(tPt);
                }
                else if (particle == 1){
                    hRecHeAnti->Fill(tPt);
                }
		    }		
        }
	}
	cout << endl;
hRecHe->Write(0, TObject::kOverwrite);
hRecHeAnti->Write(0, TObject::kOverwrite);
hRecHeComb->Write(0, TObject::kOverwrite);

TH1D* hEffHe = (TH1D*) hRecHe->Clone("hEffHe");
hEffHe->SetTitle("acceptance x efficiency;#it{p}_{T} (GeV/#it{c});acc x eff");
hEffHe->Divide(hGenHe);
hEffHe->Write(0, TObject::kOverwrite);
TH1D* hEffHeAnti = (TH1D*) hRecHeAnti->Clone("hEffHeAnti");
hEffHeAnti->SetTitle("acceptance x efficiency;#it{p}_{T} (GeV/#it{c});acc x eff");
hEffHeAnti->Divide(hGenHeAnti);
hEffHeAnti->Write(0, TObject::kOverwrite);

TCanvas *c3 = new TCanvas("c3", "He", 1920, 1080);
c3->Divide(3);
c3->cd(1);
gPad->SetLeftMargin(0.18);
hGenHe->Draw();
TLegend *legend3 = new TLegend(0.52281,0.672544,0.902372,0.872796,NULL,"brNDC");
	legend3->SetEntrySeparation(.1);
	legend3->SetBorderSize(0);
	legend3->SetFillStyle(0);
	//legend2->AddEntry(yieldCombined[2], "#frac{{}^{3}H}{{}^{3}He}", "lep");
	legend3->AddEntry((TObject*)0, "This work ", "");
	legend3->AddEntry((TObject*)0, "ALICE pp #sqrt{s} = 13 TeV", "");
	legend3->AddEntry((TObject*)0, "Particle: {}^{3}He", "");
	legend3->AddEntry((TObject*)0, "High-multiplicity trigger", "");
	legend3->SetTextFont(43);
	legend3->SetTextSize(16);
	legend3->Draw();
c3->cd(2);
gPad->SetLeftMargin(0.18);
hRecHe->Draw();
c3->cd(3);
gPad->SetLeftMargin(0.18);
hEffHe->Draw();
c3->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/accxeff/accxeffHe.pdf");
c3->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/accxeff/accxeffHe.root");
TCanvas *c32 = new TCanvas("c32", "He", 1600, 1600);
c32->cd();
c32->SetLeftMargin(0.15);
c32->SetBottomMargin(0.15);
hEffHe->SetLineWidth(5);
hEffHe->SetMarkerStyle(20);
hEffHe->SetLineColor(kBlack);
hEffHe->GetYaxis()->SetLabelFont(42);
hEffHe->GetYaxis()->SetLabelSize(0.05);
hEffHe->GetYaxis()->SetTitleSize(0.05);
hEffHe->GetYaxis()->SetTitleFont(42);
hEffHe->GetXaxis()->SetLabelFont(42);
hEffHe->GetXaxis()->SetLabelSize(0.05);
hEffHe->GetXaxis()->SetTitleOffset(1);
hEffHe->GetXaxis()->SetTitleFont(42);
hEffHe->GetXaxis()->SetTitleSize(0.05);
hEffHe->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
hEffHe->SetTitle("");
hEffHe->Draw();
TLegend *legend32 = new TLegend(0.521625,0.664271,0.901048,0.873717,NULL,"brNDC");
	legend32->SetEntrySeparation(.1);
	legend32->SetBorderSize(0);
	legend32->SetFillStyle(0);
	//legend2->AddEntry(yieldCombined[2], "#frac{{}^{3}H}{{}^{3}He}", "lep");
	legend32->AddEntry((TObject*)0, "This work ", "");
	legend32->AddEntry((TObject*)0, "ALICE pp #sqrt{s} = 13 TeV", "");
	legend32->AddEntry((TObject*)0, "Particle: {}^{3}He", "");
	legend32->AddEntry((TObject*)0, "High-multiplicity trigger", "");
	legend32->SetTextFont(42);
	legend32->SetTextSize(0.042);
	legend32->Draw();
c32->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/accxeff/accxeffHe_2.root");
c32->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/accxeff/accxeffHe_2.pdf");
TCanvas *c4 = new TCanvas("c4", "Anti-He", 1920, 1080);
c4->Divide(3);
c4->cd(1);
gPad->SetLeftMargin(0.18);
hGenHeAnti->Draw();
TLegend *legend4 = new TLegend(0.52281,0.672544,0.902372,0.872796,NULL,"brNDC");
	legend4->SetEntrySeparation(.1);
	legend4->SetBorderSize(0);
	legend4->SetFillStyle(0);
	//legend2->AddEntry(yieldCombined[2], "#frac{{}^{3}H}{{}^{3}He}", "lep");
	legend4->AddEntry((TObject*)0, "This work ", "");
	legend4->AddEntry((TObject*)0, "ALICE pp #sqrt{s} = 13 TeV", "");
	legend4->AddEntry((TObject*)0, "Particle: {}^{3}#bar{He}", "");
	legend4->AddEntry((TObject*)0, "High-multiplicity trigger", "");
	legend4->SetTextFont(43);
	legend4->SetTextSize(16);
	legend4->Draw();
c4->cd(2);
gPad->SetLeftMargin(0.18);
hRecHeAnti->Draw();
c4->cd(3);
gPad->SetLeftMargin(0.18);
hEffHeAnti->Draw();
c4->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/accxeff/accxeffHeAnti.pdf");
c4->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/accxeff/accxeffHeAnti.root");
TCanvas *c42 = new TCanvas("c42", "Anti-He", 1600, 1600);
c42->cd();
c42->SetLeftMargin(0.15);
c42->SetBottomMargin(0.15);
hEffHeAnti->Draw();
hEffHeAnti->SetLineWidth(5);
hEffHeAnti->SetMarkerStyle(20);
hEffHeAnti->SetLineColor(kBlack);
hEffHeAnti->GetYaxis()->SetLabelFont(42);
hEffHeAnti->GetYaxis()->SetLabelSize(0.05);
hEffHeAnti->GetYaxis()->SetTitleSize(0.05);
hEffHeAnti->GetYaxis()->SetTitleFont(42);
hEffHeAnti->GetXaxis()->SetLabelFont(42);
hEffHeAnti->GetXaxis()->SetLabelSize(0.05);
hEffHeAnti->GetXaxis()->SetTitleOffset(1);
hEffHeAnti->GetXaxis()->SetTitleFont(42);
hEffHeAnti->GetXaxis()->SetTitleSize(0.05);
hEffHeAnti->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
hEffHeAnti->SetTitle("");
TLegend *legend42 = new TLegend(0.521625,0.664271,0.901048,0.873717,NULL,"brNDC");
	legend42->SetEntrySeparation(.1);
	legend42->SetBorderSize(0);
	legend42->SetFillStyle(0);
	//legend2->AddEntry(yieldCombined[2], "#frac{{}^{3}H}{{}^{3}He}", "lep");
	legend42->AddEntry((TObject*)0, "This work ", "");
	legend42->AddEntry((TObject*)0, "ALICE pp #sqrt{s} = 13 TeV ", "");
	legend42->AddEntry((TObject*)0, "Particle: {}^{3}#bar{He}", "");
	legend42->AddEntry((TObject*)0, "High-multiplicity trigger", "");
	legend42->SetTextFont(42);
	legend42->SetTextSize(0.042);
	legend42->Draw();
c42->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/accxeff/accxeffHeAnti_2.root");
c42->SaveAs("/Users/matthias/alice/Master/Makros/result/Plots/accxeff/accxeffHeAnti_2.pdf");
f->Close();
}
//_________________________________________________________________________________________________________
