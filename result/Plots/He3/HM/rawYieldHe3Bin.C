#ifdef __CLING__
#pragma cling optimize(0)
#endif
void rawYieldHe3Bin()
{
//=========Macro generated from canvas: raw/Raw Yield
//=========  (Mon Jul 22 14:05:06 2024) by ROOT version 6.30/01
   TCanvas *raw = new TCanvas("raw", "Raw Yield",0,53,800,847);
   gStyle->SetOptFit(1);
   raw->SetHighLightColor(2);
   raw->Range(0,0,1,1);
   raw->SetFillColor(0);
   raw->SetBorderMode(0);
   raw->SetBorderSize(2);
   raw->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad1histRaw0000
   TPad *pad1histRaw0000__0 = new TPad("pad1histRaw0000", "pad1",0,0.4,1,1);
   pad1histRaw0000__0->Draw();
   pad1histRaw0000__0->cd();
   pad1histRaw0000__0->Range(1.183133,0.01,2.628916,231.11);
   pad1histRaw0000__0->SetFillColor(0);
   pad1histRaw0000__0->SetBorderMode(0);
   pad1histRaw0000__0->SetBorderSize(2);
   pad1histRaw0000__0->SetLeftMargin(0.15);
   pad1histRaw0000__0->SetRightMargin(0.02);
   pad1histRaw0000__0->SetBottomMargin(0);
   pad1histRaw0000__0->SetFrameBorderMode(0);
   pad1histRaw0000__0->SetFrameBorderMode(0);
   
   THStack *hshistRaw0000 = new THStack();
   hshistRaw0000->SetName("hshistRaw0000");
   hshistRaw0000->SetTitle(" ;#it{p}_{T} (Gev/#it{c});Counts");
   hshistRaw0000->SetMinimum(0.01);
   hshistRaw0000->SetMaximum(208);
   Double_t xAxis1[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1F *hshistRaw0000_stack_1 = new TH1F("hshistRaw0000_stack_1"," ",3, xAxis1);
   hshistRaw0000_stack_1->SetMinimum(0.01);
   hshistRaw0000_stack_1->SetMaximum(208);
   hshistRaw0000_stack_1->SetDirectory(nullptr);
   hshistRaw0000_stack_1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hshistRaw0000_stack_1->SetLineColor(ci);
   hshistRaw0000_stack_1->SetLineWidth(0);
   hshistRaw0000_stack_1->GetXaxis()->SetTitle("#it{p}_{T} (Gev/#it{c})");
   hshistRaw0000_stack_1->GetXaxis()->SetLabelFont(42);
   hshistRaw0000_stack_1->GetXaxis()->SetTitleOffset(1);
   hshistRaw0000_stack_1->GetXaxis()->SetTitleFont(42);
   hshistRaw0000_stack_1->GetYaxis()->SetTitle("Counts");
   hshistRaw0000_stack_1->GetYaxis()->SetLabelFont(43);
   hshistRaw0000_stack_1->GetYaxis()->SetLabelSize(15);
   hshistRaw0000_stack_1->GetYaxis()->SetTitleSize(16);
   hshistRaw0000_stack_1->GetYaxis()->SetTitleOffset(2.5);
   hshistRaw0000_stack_1->GetYaxis()->SetTitleFont(43);
   hshistRaw0000_stack_1->GetZaxis()->SetLabelFont(42);
   hshistRaw0000_stack_1->GetZaxis()->SetTitleOffset(1);
   hshistRaw0000_stack_1->GetZaxis()->SetTitleFont(42);
   hshistRaw0000->SetHistogram(hshistRaw0000_stack_1);
   
   Double_t xAxis2[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *histRaw0000_stack_1 = new TH1D("histRaw0000_stack_1"," ",3, xAxis2);
   histRaw0000_stack_1->SetBinContent(1,90);
   histRaw0000_stack_1->SetBinContent(2,160);
   histRaw0000_stack_1->SetBinContent(3,124);
   histRaw0000_stack_1->SetBinError(1,9.486833);
   histRaw0000_stack_1->SetBinError(2,12.64911);
   histRaw0000_stack_1->SetBinError(3,11.13553);
   histRaw0000_stack_1->SetEntries(3);
   histRaw0000_stack_1->SetDirectory(nullptr);
   histRaw0000_stack_1->SetStats(0);

   ci = TColor::GetColor("#0000ff");
   histRaw0000_stack_1->SetLineColor(ci);
   histRaw0000_stack_1->SetMarkerStyle(4);
   histRaw0000_stack_1->GetXaxis()->SetTitle("#it{p}_{T} (Gev/#it{c})");
   histRaw0000_stack_1->GetXaxis()->SetLabelFont(42);
   histRaw0000_stack_1->GetXaxis()->SetTitleOffset(1);
   histRaw0000_stack_1->GetXaxis()->SetTitleFont(42);
   histRaw0000_stack_1->GetYaxis()->SetTitle("Counts");
   histRaw0000_stack_1->GetYaxis()->SetLabelFont(42);
   histRaw0000_stack_1->GetYaxis()->SetTitleFont(42);
   histRaw0000_stack_1->GetZaxis()->SetLabelFont(42);
   histRaw0000_stack_1->GetZaxis()->SetTitleOffset(1);
   histRaw0000_stack_1->GetZaxis()->SetTitleFont(42);
   hshistRaw0000->Add(histRaw0000_stack_1,"");
   Double_t xAxis3[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *histRaw0001_stack_2 = new TH1D("histRaw0001_stack_2"," ",3, xAxis3);
   histRaw0001_stack_2->SetBinContent(1,70);
   histRaw0001_stack_2->SetBinContent(2,92);
   histRaw0001_stack_2->SetBinContent(3,100);
   histRaw0001_stack_2->SetBinError(1,8.3666);
   histRaw0001_stack_2->SetBinError(2,9.591663);
   histRaw0001_stack_2->SetBinError(3,10);
   histRaw0001_stack_2->SetEntries(3);
   histRaw0001_stack_2->SetDirectory(nullptr);
   histRaw0001_stack_2->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   histRaw0001_stack_2->SetLineColor(ci);
   histRaw0001_stack_2->SetMarkerStyle(8);
   histRaw0001_stack_2->GetXaxis()->SetTitle("#it{p}_{T} (Gev/#it{c})");
   histRaw0001_stack_2->GetXaxis()->SetLabelFont(42);
   histRaw0001_stack_2->GetXaxis()->SetTitleOffset(1);
   histRaw0001_stack_2->GetXaxis()->SetTitleFont(42);
   histRaw0001_stack_2->GetYaxis()->SetTitle("Counts");
   histRaw0001_stack_2->GetYaxis()->SetLabelFont(42);
   histRaw0001_stack_2->GetYaxis()->SetTitleFont(42);
   histRaw0001_stack_2->GetZaxis()->SetLabelFont(42);
   histRaw0001_stack_2->GetZaxis()->SetTitleOffset(1);
   histRaw0001_stack_2->GetZaxis()->SetTitleFont(42);
   hshistRaw0000->Add(histRaw0001_stack_2,"");
   hshistRaw0000->Draw("nostack");
   
   TPaveText *pt = new TPaveText(0.4862406,0.94,0.5137594,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText(" ");
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
   TLegendEntry *entry=leg->AddEntry("histRaw0000","{}^{3}He","L");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   entry=leg->AddEntry("histRaw0001","{}^{3}#bar{He}","L");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   leg->Draw();
   pad1histRaw0000__0->Modified();
   raw->cd();
  
// ------------>Primitives in pad: pad2histRaw0000
   TPad *pad2histRaw0000__1 = new TPad("pad2histRaw0000", "pad2",0,0.05,1,0.4);
   pad2histRaw0000__1->Draw();
   pad2histRaw0000__1->cd();
   pad2histRaw0000__1->Range(1.183133,0.2828887,2.628916,0.9366337);
   pad2histRaw0000__1->SetFillColor(0);
   pad2histRaw0000__1->SetBorderMode(0);
   pad2histRaw0000__1->SetBorderSize(2);
   pad2histRaw0000__1->SetGridy();
   pad2histRaw0000__1->SetLeftMargin(0.15);
   pad2histRaw0000__1->SetRightMargin(0.02);
   pad2histRaw0000__1->SetTopMargin(0);
   pad2histRaw0000__1->SetBottomMargin(0.3);
   pad2histRaw0000__1->SetFrameBorderMode(0);
   pad2histRaw0000__1->SetFrameBorderMode(0);
   Double_t xAxis4[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *histRatiohistRaw0000__10 = new TH1D("histRatiohistRaw0000__10","",3, xAxis4);
   histRatiohistRaw0000__10->SetBinContent(1,0.7777778);
   histRatiohistRaw0000__10->SetBinContent(2,0.575);
   histRatiohistRaw0000__10->SetBinContent(3,0.8064516);
   histRatiohistRaw0000__10->SetBinError(1,0.1239496);
   histRatiohistRaw0000__10->SetBinError(2,0.07523401);
   histRatiohistRaw0000__10->SetBinError(3,0.1083906);
   histRatiohistRaw0000__10->SetEntries(142.2631);
   histRatiohistRaw0000__10->SetDirectory(nullptr);
   histRatiohistRaw0000__10->SetStats(0);
   histRatiohistRaw0000__10->SetMarkerStyle(8);
   histRatiohistRaw0000__10->GetXaxis()->SetTitle("#it{p}_t (GeV/c)");
   histRatiohistRaw0000__10->GetXaxis()->SetLabelFont(43);
   histRatiohistRaw0000__10->GetXaxis()->SetLabelSize(15);
   histRatiohistRaw0000__10->GetXaxis()->SetTitleSize(16);
   histRatiohistRaw0000__10->GetXaxis()->SetTitleOffset(4);
   histRatiohistRaw0000__10->GetXaxis()->SetTitleFont(43);
   histRatiohistRaw0000__10->GetYaxis()->SetTitle("{}^{3}#bar{He} / {}^{3}He");
   histRatiohistRaw0000__10->GetYaxis()->SetNdivisions(5);
   histRatiohistRaw0000__10->GetYaxis()->SetLabelFont(43);
   histRatiohistRaw0000__10->GetYaxis()->SetLabelSize(15);
   histRatiohistRaw0000__10->GetYaxis()->SetTitleSize(16);
   histRatiohistRaw0000__10->GetYaxis()->SetTitleOffset(2.5);
   histRatiohistRaw0000__10->GetYaxis()->SetTitleFont(43);
   histRatiohistRaw0000__10->GetZaxis()->SetLabelFont(42);
   histRatiohistRaw0000__10->GetZaxis()->SetTitleOffset(1);
   histRatiohistRaw0000__10->GetZaxis()->SetTitleFont(42);
   histRatiohistRaw0000__10->Draw("ep");
   pad2histRaw0000__1->Modified();
   raw->cd();
   raw->Modified();
   raw->SetSelected(raw);
}
