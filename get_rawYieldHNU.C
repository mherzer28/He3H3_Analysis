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
#include "get_rawYieldHNU.h"

TString rootfile_HNUHQU = "/Users/matthias/alice/Master/Makros/Rootfiles/DataH3_HNUHQU.root";
TString rootfile_He_HNUHQU = "/Users/matthias/alice/Master/Makros/Rootfiles/DataHe3_HNUHQU.root";
TString rootfile_HNU = "/Users/matthias/alice/Master/Makros/Rootfiles/DataH3_HNU.root";
TString rootfile_He_HNU = "/Users/matthias/alice/Master/Makros/Rootfiles/DataHe3_HNU.root";
TString rootfile_HQU = "/Users/matthias/alice/Master/Makros/Rootfiles/DataH3_HQU.root";
TString rootfile_He_HQU = "/Users/matthias/alice/Master/Makros/Rootfiles/DataHe3_HQU.root";
TFile *f;
TFile *f2;
TFile *fHe;
TFile *f2He;
TString trigger = "HNU"; // HNU, HQU or HNUHQU
const Int_t nParticles = 3;

void get_rawYieldHNU(){
    get_rawH3HNU();
    get_rawHeHNU();
}

void get_rawH3HNU(){
    if (trigger == "HNU")
    {
        f = TFile::Open(rootfile_HNU, "UPDATE");
    }
    if (trigger == "HQU")
    {
        f = TFile::Open(rootfile_HQU, "UPDATE");
    }
    if (trigger == "HNUHQU")
    {
        f = TFile::Open(rootfile_HNUHQU, "UPDATE");
    }
    
    if (!f || f->IsZombie()) {
        std::cerr << "Error opening file: " << rootfile_HNU << std::endl;
        return;
    }
    
    TH1D* rawyieldH3HNU[nParticles] = {0};
    for (int particle = 0; particle < nParticles; particle++){
        rawyieldH3HNU[particle] = (TH1D*) f->Get(Form("histRaw%02d", particle));
        if (!rawyieldH3HNU[particle]) {
            std::cerr << "Error retrieving histogram for H3 particle " << particle << std::endl;
            continue;
        }
    }
    if (trigger == "HNU")
    {
        f2 = TFile::Open("/Users/matthias/alice/Master/Makros/result/correction/correctionYield_HNU.root", "RECREATE");
    }
    if (trigger == "HQU")
    {
        f2 = TFile::Open("/Users/matthias/alice/Master/Makros/result/correction/correctionYield_HQU.root", "RECREATE");
    }
    if (trigger == "HNUHQU")
    {
        f2 = TFile::Open("/Users/matthias/alice/Master/Makros/result/correction/correctionYield_HNUHQU.root", "RECREATE");
    }
    
    if (!f2 || f2->IsZombie()) {
        std::cerr << "Error creating output file" << std::endl;
        f->Close();
        return;
    }
    
    for (int particle = 0; particle < nParticles; particle++){
        if (rawyieldH3HNU[particle]) {
            rawyieldH3HNU[particle]->Write(0, TObject::kOverwrite);
        }
    }
    f->Close();
    f2->Close();
}

void get_rawHeHNU(){
       if (trigger == "HNU")
    {
        fHe = TFile::Open(rootfile_He_HNU, "UPDATE");
    }
    if (trigger == "HQU")
    {
        fHe = TFile::Open(rootfile_He_HQU, "UPDATE");
    }
    if (trigger == "HNUHQU")
    {
        fHe = TFile::Open(rootfile_He_HNUHQU, "UPDATE");
    }
    
    if (!fHe || fHe->IsZombie()) {
        std::cerr << "Error opening file: " << rootfile_He_HNU << std::endl;
        return;
    }
    
    TH1D* rawyieldHe3HNU[nParticles] = {0};
    for (int particle = 0; particle < nParticles; particle++){
        rawyieldHe3HNU[particle] = (TH1D*) fHe->Get(Form("histRaw%02d%02d",0, particle));
        if (!rawyieldHe3HNU[particle]) {
            std::cerr << "Error retrieving histogram for He3 particle " << particle << std::endl;
            continue;
        }
    }
    if (trigger == "HNU")
    {
        f2He = TFile::Open("/Users/matthias/alice/Master/Makros/result/correction/correctionYieldHe_HNU.root", "RECREATE");
    }
    if (trigger == "HQU")
    {
        f2He = TFile::Open("/Users/matthias/alice/Master/Makros/result/correction/correctionYieldHe_HQU.root", "RECREATE");
    }
    if(trigger == "HNUHQU")
    {
        f2He = TFile::Open("/Users/matthias/alice/Master/Makros/result/correction/correctionYieldHe_HNUHQU.root", "RECREATE");
    }

    if (!f2He || f2He->IsZombie()) {
        std::cerr << "Error creating output file" << std::endl;
        fHe->Close();
        return;
    }
    
    for (int particle = 0; particle < nParticles; particle++){
        if (rawyieldHe3HNU[particle]) {
            rawyieldHe3HNU[particle]->Write(0, TObject::kOverwrite);
        }
    }
    fHe->Close();
    f2He->Close();
}
