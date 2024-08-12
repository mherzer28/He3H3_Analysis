#ifdef __CLING__
#pragma cling optimize(0)
#endif
void ratiocorryield_He3_HNU()
{
//=========Macro generated from canvas: CorrYieldHe/He corr yield bin counting
//=========  (Tue Jul 30 15:50:55 2024) by ROOT version 6.30/01
   TCanvas *CorrYieldHe = new TCanvas("CorrYieldHe", "He corr yield bin counting",0,53,1440,847);
   gStyle->SetOptStat(0);
   CorrYieldHe->SetHighLightColor(2);
   CorrYieldHe->Range(0,0,1,1);
   CorrYieldHe->SetFillColor(0);
   CorrYieldHe->SetBorderMode(0);
   CorrYieldHe->SetBorderSize(2);
   CorrYieldHe->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad1hCorrHe0
   TPad *pad1hCorrHe0__2 = new TPad("pad1hCorrHe0", "pad1",0,0.4,1,1);
   pad1hCorrHe0__2->Draw();
   pad1hCorrHe0__2->cd();
   pad1hCorrHe0__2->Range(1.028916,0.01,2.836145,29009.91);
   pad1hCorrHe0__2->SetFillColor(0);
   pad1hCorrHe0__2->SetBorderMode(0);
   pad1hCorrHe0__2->SetBorderSize(2);
   pad1hCorrHe0__2->SetLeftMargin(0.15);
   pad1hCorrHe0__2->SetRightMargin(0.02);
   pad1hCorrHe0__2->SetBottomMargin(0);
   pad1hCorrHe0__2->SetFrameBorderMode(0);
   pad1hCorrHe0__2->SetFrameBorderMode(0);
   
   THStack *hshCorrHe0 = new THStack();
   hshCorrHe0->SetName("hshCorrHe0");
   hshCorrHe0->SetTitle("{}^{3}He;#it{p}_{T} (Gev/#it{c});Counts");
   hshCorrHe0->SetMinimum(0.01);
   hshCorrHe0->SetMaximum(26108.92);
   Double_t xAxis5[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1F *hshCorrHe0_stack_2 = new TH1F("hshCorrHe0_stack_2","{}^{3}He",3, xAxis5);
   hshCorrHe0_stack_2->SetMinimum(0.01);
   hshCorrHe0_stack_2->SetMaximum(26108.92);
   hshCorrHe0_stack_2->SetDirectory(nullptr);
   hshCorrHe0_stack_2->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hshCorrHe0_stack_2->SetLineColor(ci);
   hshCorrHe0_stack_2->SetLineWidth(0);
   hshCorrHe0_stack_2->GetXaxis()->SetTitle("#it{p}_{T} (Gev/#it{c})");
   hshCorrHe0_stack_2->GetXaxis()->SetLabelFont(42);
   hshCorrHe0_stack_2->GetXaxis()->SetTitleOffset(1);
   hshCorrHe0_stack_2->GetXaxis()->SetTitleFont(42);
   hshCorrHe0_stack_2->GetYaxis()->SetTitle("Counts");
   hshCorrHe0_stack_2->GetYaxis()->SetLabelFont(43);
   hshCorrHe0_stack_2->GetYaxis()->SetLabelSize(15);
   hshCorrHe0_stack_2->GetYaxis()->SetTitleSize(16);
   hshCorrHe0_stack_2->GetYaxis()->SetTitleOffset(1);
   hshCorrHe0_stack_2->GetYaxis()->SetTitleFont(43);
   hshCorrHe0_stack_2->GetZaxis()->SetLabelFont(42);
   hshCorrHe0_stack_2->GetZaxis()->SetTitleOffset(1);
   hshCorrHe0_stack_2->GetZaxis()->SetTitleFont(42);
   hshCorrHe0->SetHistogram(hshCorrHe0_stack_2);
   
   Double_t xAxis6[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *hCorrHe0_stack_1 = new TH1D("hCorrHe0_stack_1","{}^{3}He",3, xAxis6);
   hCorrHe0_stack_1->SetBinContent(1,20083.78);
   hCorrHe0_stack_1->SetBinContent(2,5427.703);
   hCorrHe0_stack_1->SetBinContent(3,2189.172);
   hCorrHe0_stack_1->SetBinError(1,2528.987);
   hCorrHe0_stack_1->SetBinError(2,406.4444);
   hCorrHe0_stack_1->SetBinError(3,237.2903);
   hCorrHe0_stack_1->SetEntries(115.958);
   hCorrHe0_stack_1->SetStats(0);

   ci = TColor::GetColor("#0000ff");
   hCorrHe0_stack_1->SetLineColor(ci);
   hCorrHe0_stack_1->GetXaxis()->SetTitle("#it{p}_{T} (Gev/#it{c})");
   hCorrHe0_stack_1->GetXaxis()->SetLabelFont(42);
   hCorrHe0_stack_1->GetXaxis()->SetTitleOffset(1);
   hCorrHe0_stack_1->GetXaxis()->SetTitleFont(42);
   hCorrHe0_stack_1->GetYaxis()->SetTitle("Counts");
   hCorrHe0_stack_1->GetYaxis()->SetLabelFont(42);
   hCorrHe0_stack_1->GetYaxis()->SetTitleFont(42);
   hCorrHe0_stack_1->GetZaxis()->SetLabelFont(42);
   hCorrHe0_stack_1->GetZaxis()->SetTitleOffset(1);
   hCorrHe0_stack_1->GetZaxis()->SetTitleFont(42);
   hshCorrHe0->Add(hCorrHe0_stack_1,"");
   Double_t xAxis7[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *hCorrHe1_stack_2 = new TH1D("hCorrHe1_stack_2","{}^{3}#bar{He}",3, xAxis7);
   hCorrHe1_stack_2->SetBinContent(1,11630.41);
   hCorrHe1_stack_2->SetBinContent(2,3595.463);
   hCorrHe1_stack_2->SetBinContent(3,1326.259);
   hCorrHe1_stack_2->SetBinError(1,1595.285);
   hCorrHe1_stack_2->SetBinError(2,255.7775);
   hCorrHe1_stack_2->SetBinError(3,119.9752);
   hCorrHe1_stack_2->SetEntries(104.3806);
   hCorrHe1_stack_2->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   hCorrHe1_stack_2->SetLineColor(ci);
   hCorrHe1_stack_2->GetXaxis()->SetTitle("#it{p}_{T} (Gev/#it{c})");
   hCorrHe1_stack_2->GetXaxis()->SetLabelFont(42);
   hCorrHe1_stack_2->GetXaxis()->SetTitleOffset(1);
   hCorrHe1_stack_2->GetXaxis()->SetTitleFont(42);
   hCorrHe1_stack_2->GetYaxis()->SetTitle("Counts");
   hCorrHe1_stack_2->GetYaxis()->SetLabelFont(42);
   hCorrHe1_stack_2->GetYaxis()->SetTitleFont(42);
   hCorrHe1_stack_2->GetZaxis()->SetLabelFont(42);
   hCorrHe1_stack_2->GetZaxis()->SetTitleOffset(1);
   hCorrHe1_stack_2->GetZaxis()->SetTitleFont(42);
   hshCorrHe0->Add(hCorrHe1_stack_2,"");
   hshCorrHe0->Draw("nostack");
   
   TPaveText *pt = new TPaveText(0.4743533,0.94,0.5256467,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("{}^{3}He");
   pt->Draw();
   
   TLegend *leg = new TLegend(0.75,0.75,0.95,0.9,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(43);
   leg->SetTextSize(18);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("hCorrHe0","{}^{3}He","L");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   entry=leg->AddEntry("hCorrHe1","{}^{3}#bar{He}","L");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   leg->Draw();
   pad1hCorrHe0__2->Modified();
   CorrYieldHe->cd();
  
// ------------>Primitives in pad: pad2hCorrHe0
   TPad *pad2hCorrHe0__3 = new TPad("pad2hCorrHe0", "pad2",0,0.05,1,0.4);
   pad2hCorrHe0__3->Draw();
   pad2hCorrHe0__3->cd();
   pad2hCorrHe0__3->Range(1.028916,0.3356359,2.836145,0.7444765);
   pad2hCorrHe0__3->SetFillColor(0);
   pad2hCorrHe0__3->SetBorderMode(0);
   pad2hCorrHe0__3->SetBorderSize(2);
   pad2hCorrHe0__3->SetGridy();
   pad2hCorrHe0__3->SetLeftMargin(0.15);
   pad2hCorrHe0__3->SetRightMargin(0.02);
   pad2hCorrHe0__3->SetTopMargin(0);
   pad2hCorrHe0__3->SetBottomMargin(0.3);
   pad2hCorrHe0__3->SetFrameBorderMode(0);
   pad2hCorrHe0__3->SetFrameBorderMode(0);
   Double_t xAxis8[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *histRatiohCorrHe0__2 = new TH1D("histRatiohCorrHe0__2","",3, xAxis8);
   histRatiohCorrHe0__2->SetBinContent(1,0.5790947);
   histRatiohCorrHe0__2->SetBinContent(2,0.6624281);
   histRatiohCorrHe0__2->SetBinContent(3,0.6058265);
   histRatiohCorrHe0__2->SetBinError(1,0.1078276);
   histRatiohCorrHe0__2->SetBinError(2,0.06842039);
   histRatiohCorrHe0__2->SetBinError(3,0.08553157);
   histRatiohCorrHe0__2->SetEntries(144.4603);
   histRatiohCorrHe0__2->SetStats(0);
   histRatiohCorrHe0__2->GetXaxis()->SetTitle("#it{p}_{T} (Gev/#it{c})");
   histRatiohCorrHe0__2->GetXaxis()->SetLabelFont(43);
   histRatiohCorrHe0__2->GetXaxis()->SetLabelSize(15);
   histRatiohCorrHe0__2->GetXaxis()->SetTitleSize(16);
   histRatiohCorrHe0__2->GetXaxis()->SetTitleOffset(4);
   histRatiohCorrHe0__2->GetXaxis()->SetTitleFont(43);
   histRatiohCorrHe0__2->GetYaxis()->SetTitle("{}^{3}#bar{He} / {}^{3}He");
   histRatiohCorrHe0__2->GetYaxis()->SetNdivisions(5);
   histRatiohCorrHe0__2->GetYaxis()->SetLabelFont(43);
   histRatiohCorrHe0__2->GetYaxis()->SetLabelSize(15);
   histRatiohCorrHe0__2->GetYaxis()->SetTitleSize(16);
   histRatiohCorrHe0__2->GetYaxis()->SetTitleOffset(1);
   histRatiohCorrHe0__2->GetYaxis()->SetTitleFont(43);
   histRatiohCorrHe0__2->GetZaxis()->SetLabelFont(42);
   histRatiohCorrHe0__2->GetZaxis()->SetTitleOffset(1);
   histRatiohCorrHe0__2->GetZaxis()->SetTitleFont(42);
   histRatiohCorrHe0__2->Draw("ep");
   pad2hCorrHe0__3->Modified();
   CorrYieldHe->cd();
   CorrYieldHe->Modified();
   CorrYieldHe->SetSelected(CorrYieldHe);
}
