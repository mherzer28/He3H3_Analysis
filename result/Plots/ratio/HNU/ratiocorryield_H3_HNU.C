#ifdef __CLING__
#pragma cling optimize(0)
#endif
void ratiocorryield_H3_HNU()
{
//=========Macro generated from canvas: CorrYield/corr yield bin counting
//=========  (Tue Jun 18 12:56:29 2024) by ROOT version 6.30/01
   TCanvas *CorrYield = new TCanvas("CorrYield", "corr yield bin counting",0,53,1440,847);
   gStyle->SetOptStat(0);
   CorrYield->SetHighLightColor(2);
   CorrYield->Range(0,0,1,1);
   CorrYield->SetFillColor(0);
   CorrYield->SetBorderMode(0);
   CorrYield->SetBorderSize(2);
   CorrYield->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad1hCorr0
   TPad *pad1hCorr0__0 = new TPad("pad1hCorr0", "pad1",0,0.4,1,1);
   pad1hCorr0__0->Draw();
   pad1hCorr0__0->cd();
   pad1hCorr0__0->Range(1.028916,0.01,2.836145,31274.59);
   pad1hCorr0__0->SetFillColor(0);
   pad1hCorr0__0->SetBorderMode(0);
   pad1hCorr0__0->SetBorderSize(2);
   pad1hCorr0__0->SetLeftMargin(0.15);
   pad1hCorr0__0->SetRightMargin(0.02);
   pad1hCorr0__0->SetBottomMargin(0);
   pad1hCorr0__0->SetFrameBorderMode(0);
   pad1hCorr0__0->SetFrameBorderMode(0);
   
   THStack *hshCorr0 = new THStack();
   hshCorr0->SetName("hshCorr0");
   hshCorr0->SetTitle("{}^{3}H;#it{p}_{T} (Gev/#it{c});Counts");
   hshCorr0->SetMinimum(0.01);
   hshCorr0->SetMaximum(28147.13);
   Double_t xAxis1[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1F *hshCorr0_stack_1 = new TH1F("hshCorr0_stack_1","{}^{3}H",3, xAxis1);
   hshCorr0_stack_1->SetMinimum(0.01);
   hshCorr0_stack_1->SetMaximum(28147.13);
   hshCorr0_stack_1->SetDirectory(nullptr);
   hshCorr0_stack_1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hshCorr0_stack_1->SetLineColor(ci);
   hshCorr0_stack_1->SetLineWidth(0);
   hshCorr0_stack_1->GetXaxis()->SetTitle("#it{p}_{T} (Gev/#it{c})");
   hshCorr0_stack_1->GetXaxis()->SetLabelFont(42);
   hshCorr0_stack_1->GetXaxis()->SetTitleOffset(1);
   hshCorr0_stack_1->GetXaxis()->SetTitleFont(42);
   hshCorr0_stack_1->GetYaxis()->SetTitle("Counts");
   hshCorr0_stack_1->GetYaxis()->SetLabelFont(43);
   hshCorr0_stack_1->GetYaxis()->SetLabelSize(15);
   hshCorr0_stack_1->GetYaxis()->SetTitleSize(16);
   hshCorr0_stack_1->GetYaxis()->SetTitleOffset(1);
   hshCorr0_stack_1->GetYaxis()->SetTitleFont(43);
   hshCorr0_stack_1->GetZaxis()->SetLabelFont(42);
   hshCorr0_stack_1->GetZaxis()->SetTitleOffset(1);
   hshCorr0_stack_1->GetZaxis()->SetTitleFont(42);
   hshCorr0->SetHistogram(hshCorr0_stack_1);
   
   Double_t xAxis2[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *hCorr0_stack_1 = new TH1D("hCorr0_stack_1","{}^{3}H",3, xAxis2);
   hCorr0_stack_1->SetBinContent(1,21651.64);
   hCorr0_stack_1->SetBinContent(2,7819.474);
   hCorr0_stack_1->SetBinContent(3,7287.9);
   hCorr0_stack_1->SetBinError(1,6608.808);
   hCorr0_stack_1->SetBinError(2,1107.949);
   hCorr0_stack_1->SetBinError(3,1486.387);
   hCorr0_stack_1->SetEntries(28.68037);
   hCorr0_stack_1->SetStats(0);

   ci = TColor::GetColor("#0000ff");
   hCorr0_stack_1->SetLineColor(ci);
   hCorr0_stack_1->GetXaxis()->SetTitle("#it{p}_{T} (Gev/#it{c})");
   hCorr0_stack_1->GetXaxis()->SetLabelFont(42);
   hCorr0_stack_1->GetXaxis()->SetTitleOffset(1);
   hCorr0_stack_1->GetXaxis()->SetTitleFont(42);
   hCorr0_stack_1->GetYaxis()->SetTitle("Counts");
   hCorr0_stack_1->GetYaxis()->SetLabelFont(42);
   hCorr0_stack_1->GetYaxis()->SetTitleFont(42);
   hCorr0_stack_1->GetZaxis()->SetLabelFont(42);
   hCorr0_stack_1->GetZaxis()->SetTitleOffset(1);
   hCorr0_stack_1->GetZaxis()->SetTitleFont(42);
   hshCorr0->Add(hCorr0_stack_1,"");
   Double_t xAxis3[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *hCorr1_stack_2 = new TH1D("hCorr1_stack_2","{}^{3}#bar{H}",3, xAxis3);
   hCorr1_stack_2->SetBinContent(1,4042.381);
   hCorr1_stack_2->SetBinContent(2,5219.606);
   hCorr1_stack_2->SetBinContent(3,4038.362);
   hCorr1_stack_2->SetBinError(1,1669.888);
   hCorr1_stack_2->SetBinError(2,466.2597);
   hCorr1_stack_2->SetBinError(3,650.794);
   hCorr1_stack_2->SetEntries(51.58231);
   hCorr1_stack_2->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   hCorr1_stack_2->SetLineColor(ci);
   hCorr1_stack_2->GetXaxis()->SetTitle("#it{p}_{T} (Gev/#it{c})");
   hCorr1_stack_2->GetXaxis()->SetLabelFont(42);
   hCorr1_stack_2->GetXaxis()->SetTitleOffset(1);
   hCorr1_stack_2->GetXaxis()->SetTitleFont(42);
   hCorr1_stack_2->GetYaxis()->SetTitle("Counts");
   hCorr1_stack_2->GetYaxis()->SetLabelFont(42);
   hCorr1_stack_2->GetYaxis()->SetTitleFont(42);
   hCorr1_stack_2->GetZaxis()->SetLabelFont(42);
   hCorr1_stack_2->GetZaxis()->SetTitleOffset(1);
   hCorr1_stack_2->GetZaxis()->SetTitleFont(42);
   hshCorr0->Add(hCorr1_stack_2,"");
   hshCorr0->Draw("nostack");
   
   TPaveText *pt = new TPaveText(0.4788734,0.94,0.5211266,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("{}^{3}H");
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
   TLegendEntry *entry=leg->AddEntry("hCorr0","{}^{3}H","L");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   entry=leg->AddEntry("hCorr1","{}^{3}#bar{H}","L");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   leg->Draw();
   pad1hCorr0__0->Modified();
   CorrYield->cd();
  
// ------------>Primitives in pad: pad2hCorr0
   TPad *pad2hCorr0__1 = new TPad("pad2hCorr0", "pad2",0,0.05,1,0.4);
   pad2hCorr0__1->Draw();
   pad2hCorr0__1->cd();
   pad2hCorr0__1->Range(1.028916,-0.2689437,2.836145,0.8154687);
   pad2hCorr0__1->SetFillColor(0);
   pad2hCorr0__1->SetBorderMode(0);
   pad2hCorr0__1->SetBorderSize(2);
   pad2hCorr0__1->SetGridy();
   pad2hCorr0__1->SetLeftMargin(0.15);
   pad2hCorr0__1->SetRightMargin(0.02);
   pad2hCorr0__1->SetTopMargin(0);
   pad2hCorr0__1->SetBottomMargin(0.3);
   pad2hCorr0__1->SetFrameBorderMode(0);
   pad2hCorr0__1->SetFrameBorderMode(0);
   Double_t xAxis4[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *histRatiohCorr0__1 = new TH1D("histRatiohCorr0__1","",3, xAxis4);
   histRatiohCorr0__1->SetBinContent(1,0.1867009);
   histRatiohCorr0__1->SetBinContent(2,0.6675137);
   histRatiohCorr0__1->SetBinContent(3,0.5541187);
   histRatiohCorr0__1->SetBinError(1,0.0958951);
   histRatiohCorr0__1->SetBinError(2,0.1118079);
   histRatiohCorr0__1->SetBinError(3,0.1440357);
   histRatiohCorr0__1->SetEntries(46.73081);
   histRatiohCorr0__1->SetStats(0);
   histRatiohCorr0__1->GetXaxis()->SetTitle("#it{p}_{T} (Gev/#it{c})");
   histRatiohCorr0__1->GetXaxis()->SetLabelFont(43);
   histRatiohCorr0__1->GetXaxis()->SetLabelSize(15);
   histRatiohCorr0__1->GetXaxis()->SetTitleSize(16);
   histRatiohCorr0__1->GetXaxis()->SetTitleOffset(4);
   histRatiohCorr0__1->GetXaxis()->SetTitleFont(43);
   histRatiohCorr0__1->GetYaxis()->SetTitle("{}^{3}#bar{H} / {}^{3}H");
   histRatiohCorr0__1->GetYaxis()->SetNdivisions(5);
   histRatiohCorr0__1->GetYaxis()->SetLabelFont(43);
   histRatiohCorr0__1->GetYaxis()->SetLabelSize(15);
   histRatiohCorr0__1->GetYaxis()->SetTitleSize(16);
   histRatiohCorr0__1->GetYaxis()->SetTitleOffset(1);
   histRatiohCorr0__1->GetYaxis()->SetTitleFont(43);
   histRatiohCorr0__1->GetZaxis()->SetLabelFont(42);
   histRatiohCorr0__1->GetZaxis()->SetTitleOffset(1);
   histRatiohCorr0__1->GetZaxis()->SetTitleFont(42);
   histRatiohCorr0__1->Draw("ep");
   pad2hCorr0__1->Modified();
   CorrYield->cd();
   CorrYield->Modified();
   CorrYield->SetSelected(CorrYield);
}
