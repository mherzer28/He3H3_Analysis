#ifdef __CLING__
#pragma cling optimize(0)
#endif
void rawYieldH3BinCounting()
{
//=========Macro generated from canvas: rawBin/raw yield bin counting
//=========  (Mon Jul 22 15:37:55 2024) by ROOT version 6.30/01
   TCanvas *rawBin = new TCanvas("rawBin", "raw yield bin counting",0,53,1200,847);
   gStyle->SetOptFit(1);
   rawBin->SetHighLightColor(2);
   rawBin->Range(0,0,1,1);
   rawBin->SetFillColor(0);
   rawBin->SetBorderMode(0);
   rawBin->SetBorderSize(2);
   rawBin->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad1histRaw00
   TPad *pad1histRaw00__0 = new TPad("pad1histRaw00", "pad1",0,0.4,1,1);
   pad1histRaw00__0->Draw();
   pad1histRaw00__0->cd();
   pad1histRaw00__0->Range(1.028916,0.01,2.836145,206.8476);
   pad1histRaw00__0->SetFillColor(0);
   pad1histRaw00__0->SetBorderMode(0);
   pad1histRaw00__0->SetBorderSize(2);
   pad1histRaw00__0->SetLeftMargin(0.15);
   pad1histRaw00__0->SetRightMargin(0.02);
   pad1histRaw00__0->SetBottomMargin(0);
   pad1histRaw00__0->SetFrameBorderMode(0);
   pad1histRaw00__0->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle(" ; #it{p}_{T} (GeV/#it{c}); Counts");
   hs->SetMinimum(0.01);
   hs->SetMaximum(186.1639);
   Double_t xAxis1[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1F *hs_stack_1 = new TH1F("hs_stack_1"," ",3, xAxis1);
   hs_stack_1->SetMinimum(0.01);
   hs_stack_1->SetMaximum(186.1639);
   hs_stack_1->SetDirectory(nullptr);
   hs_stack_1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hs_stack_1->SetLineColor(ci);
   hs_stack_1->SetLineWidth(0);
   hs_stack_1->GetXaxis()->SetTitle(" #it{p}_{T} (GeV/#it{c})");
   hs_stack_1->GetXaxis()->SetLabelFont(42);
   hs_stack_1->GetXaxis()->SetTitleOffset(1);
   hs_stack_1->GetXaxis()->SetTitleFont(42);
   hs_stack_1->GetYaxis()->SetTitle(" Counts");
   hs_stack_1->GetYaxis()->SetLabelFont(43);
   hs_stack_1->GetYaxis()->SetLabelSize(15);
   hs_stack_1->GetYaxis()->SetTitleSize(16);
   hs_stack_1->GetYaxis()->SetTitleOffset(2.5);
   hs_stack_1->GetYaxis()->SetTitleFont(43);
   hs_stack_1->GetZaxis()->SetLabelFont(42);
   hs_stack_1->GetZaxis()->SetTitleOffset(1);
   hs_stack_1->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_1);
   
   Double_t xAxis2[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *histRaw00_stack_1 = new TH1D("histRaw00_stack_1","",3, xAxis2);
   histRaw00_stack_1->SetBinContent(1,16.84034);
   histRaw00_stack_1->SetBinContent(2,61.35075);
   histRaw00_stack_1->SetBinContent(3,77.11884);
   histRaw00_stack_1->SetBinError(1,4.795832);
   histRaw00_stack_1->SetBinError(2,8.42615);
   histRaw00_stack_1->SetBinError(3,15.55635);
   histRaw00_stack_1->SetEntries(3);
   histRaw00_stack_1->SetDirectory(nullptr);
   histRaw00_stack_1->SetStats(0);

   ci = TColor::GetColor("#0000ff");
   histRaw00_stack_1->SetLineColor(ci);
   histRaw00_stack_1->SetMarkerStyle(4);
   histRaw00_stack_1->GetXaxis()->SetLabelFont(42);
   histRaw00_stack_1->GetXaxis()->SetTitleOffset(1);
   histRaw00_stack_1->GetXaxis()->SetTitleFont(42);
   histRaw00_stack_1->GetYaxis()->SetLabelFont(42);
   histRaw00_stack_1->GetYaxis()->SetTitleFont(42);
   histRaw00_stack_1->GetZaxis()->SetLabelFont(42);
   histRaw00_stack_1->GetZaxis()->SetTitleOffset(1);
   histRaw00_stack_1->GetZaxis()->SetTitleFont(42);
   hs->Add(histRaw00_stack_1,"");
   Double_t xAxis3[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *histRaw01_stack_2 = new TH1D("histRaw01_stack_2","",3, xAxis3);
   histRaw01_stack_2->SetBinContent(1,8.497763);
   histRaw01_stack_2->SetBinContent(2,143.203);
   histRaw01_stack_2->SetBinContent(3,123.5176);
   histRaw01_stack_2->SetBinError(1,3.464102);
   histRaw01_stack_2->SetBinError(2,12.4499);
   histRaw01_stack_2->SetBinError(3,21.72556);
   histRaw01_stack_2->SetEntries(3);
   histRaw01_stack_2->SetDirectory(nullptr);
   histRaw01_stack_2->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   histRaw01_stack_2->SetLineColor(ci);
   histRaw01_stack_2->SetMarkerStyle(8);
   histRaw01_stack_2->GetXaxis()->SetLabelFont(42);
   histRaw01_stack_2->GetXaxis()->SetTitleOffset(1);
   histRaw01_stack_2->GetXaxis()->SetTitleFont(42);
   histRaw01_stack_2->GetYaxis()->SetLabelFont(42);
   histRaw01_stack_2->GetYaxis()->SetTitleFont(42);
   histRaw01_stack_2->GetZaxis()->SetLabelFont(42);
   histRaw01_stack_2->GetZaxis()->SetTitleOffset(1);
   histRaw01_stack_2->GetZaxis()->SetTitleFont(42);
   hs->Add(histRaw01_stack_2,"");
   hs->Draw("nostack");
   
   TPaveText *pt = new TPaveText(0.4874958,0.94,0.5125042,0.995,"blNDC");
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
   TLegendEntry *entry=leg->AddEntry("histRaw00","{}^{3}H","L");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   entry=leg->AddEntry("histRaw01","{}^{3}#bar{H}","L");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   leg->Draw();
   pad1histRaw00__0->Modified();
   rawBin->cd();
  
// ------------>Primitives in pad: pad2histRaw00
   TPad *pad2histRaw00__1 = new TPad("pad2histRaw00", "pad2",0,0.05,1,0.4);
   pad2histRaw00__1->Draw();
   pad2histRaw00__1->cd();
   pad2histRaw00__1->Range(1.028916,-1.031617,2.836145,2.842727);
   pad2histRaw00__1->SetFillColor(0);
   pad2histRaw00__1->SetBorderMode(0);
   pad2histRaw00__1->SetBorderSize(2);
   pad2histRaw00__1->SetGridy();
   pad2histRaw00__1->SetLeftMargin(0.15);
   pad2histRaw00__1->SetRightMargin(0.02);
   pad2histRaw00__1->SetTopMargin(0);
   pad2histRaw00__1->SetBottomMargin(0.3);
   pad2histRaw00__1->SetFrameBorderMode(0);
   pad2histRaw00__1->SetFrameBorderMode(0);
   Double_t xAxis4[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *histRatiohistRaw00__10 = new TH1D("histRatiohistRaw00__10","",3, xAxis4);
   histRatiohistRaw00__10->SetBinContent(1,0.5046076);
   histRatiohistRaw00__10->SetBinContent(2,2.334168);
   histRatiohistRaw00__10->SetBinContent(3,1.601652);
   histRatiohistRaw00__10->SetBinError(1,0.2509267);
   histRatiohistRaw00__10->SetBinError(2,0.3794133);
   histRatiohistRaw00__10->SetBinError(3,0.4286569);
   histRatiohistRaw00__10->SetEntries(50.47132);
   histRatiohistRaw00__10->SetDirectory(nullptr);
   histRatiohistRaw00__10->SetStats(0);
   histRatiohistRaw00__10->SetMarkerStyle(8);
   histRatiohistRaw00__10->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   histRatiohistRaw00__10->GetXaxis()->SetLabelFont(43);
   histRatiohistRaw00__10->GetXaxis()->SetLabelSize(25);
   histRatiohistRaw00__10->GetXaxis()->SetTitleSize(22);
   histRatiohistRaw00__10->GetXaxis()->SetTitleOffset(4);
   histRatiohistRaw00__10->GetXaxis()->SetTitleFont(43);
   histRatiohistRaw00__10->GetYaxis()->SetTitle("{}^{3}#bar{H} / {}^{3}H");
   histRatiohistRaw00__10->GetYaxis()->SetNdivisions(5);
   histRatiohistRaw00__10->GetYaxis()->SetLabelFont(43);
   histRatiohistRaw00__10->GetYaxis()->SetLabelSize(15);
   histRatiohistRaw00__10->GetYaxis()->SetTitleSize(16);
   histRatiohistRaw00__10->GetYaxis()->SetTitleOffset(2.5);
   histRatiohistRaw00__10->GetYaxis()->SetTitleFont(43);
   histRatiohistRaw00__10->GetZaxis()->SetLabelFont(42);
   histRatiohistRaw00__10->GetZaxis()->SetTitleOffset(1);
   histRatiohistRaw00__10->GetZaxis()->SetTitleFont(42);
   histRatiohistRaw00__10->Draw("ep");
   pad2histRaw00__1->Modified();
   rawBin->cd();
   rawBin->Modified();
   rawBin->SetSelected(rawBin);
}
