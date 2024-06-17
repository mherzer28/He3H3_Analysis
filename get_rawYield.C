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
#include "get_rawYield.h"

TString rootfile = "/Users/matthias/alice/Master/Makros/Rootfiles/DataH3.root";
TString rootfile_He = "/Users/matthias/alice/Master/Makros/Rootfiles/Data.root";
const Int_t nParticles = 3;

void get_rawYield(){
	get_rawH3();
	get_rawHe();
}
void get_rawH3(){
	TFile *f = TFile::Open(rootfile, "UPDATE");
	TH1D* rawyieldH3[nParticles] = {0};
	for (int particle = 0; particle < nParticles; particle++){
		rawyieldH3[particle] = (TH1D*) f->Get(Form("histRaw%02d", particle));
	}
	TFile *f2 = TFile::Open("/Users/matthias/alice/Master/Makros/result/correction/correctionYield.root", "recreate");
	for (int particle = 0; particle < nParticles; particle++){
		rawyieldH3[particle]->Write(0, TObject::kOverwrite);
	}
}
void get_rawHe(){
	TFile *f = TFile::Open(rootfile_He, "UPDATE");
	TH1D* rawyieldHe3[nParticles] = {0};
	for (int particle = 0; particle < nParticles; particle++){
		rawyieldHe3[particle] = (TH1D*) f->Get(Form("histRaw%02d%02d",0, particle));
	}
	TFile *f2 = TFile::Open("/Users/matthias/alice/Master/Makros/result/correction/correctionYieldHe.root", "recreate");
	for (int particle = 0; particle < nParticles; particle++){
		rawyieldHe3[particle]->Write(0, TObject::kOverwrite);
	}
}