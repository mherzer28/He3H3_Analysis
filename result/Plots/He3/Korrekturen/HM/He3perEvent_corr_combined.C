#ifdef __CLING__
#pragma cling optimize(0)
#endif
void He3perEvent_corr_combined()
{
//=========Macro generated from canvas: combinedCanvasCorr/
//=========  (Mon Jul  8 14:31:48 2024) by ROOT version 6.30/01
   TCanvas *combinedCanvasCorr = new TCanvas("combinedCanvasCorr", "",0,53,1440,847);
   combinedCanvasCorr->SetHighLightColor(2);
   combinedCanvasCorr->Range(1.25,1.460163e-07,2.75,1.260344e-06);
   combinedCanvasCorr->SetFillColor(0);
   combinedCanvasCorr->SetBorderMode(0);
   combinedCanvasCorr->SetBorderSize(2);
   combinedCanvasCorr->SetFrameBorderMode(0);
   combinedCanvasCorr->SetFrameBorderMode(0);
   Double_t xAxis25[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *yieldCombinedPerEventHe__25 = new TH1D("yieldCombinedPerEventHe__25","",3, xAxis25);
   yieldCombinedPerEventHe__25->SetBinContent(1,1.000193e-06);
   yieldCombinedPerEventHe__25->SetBinContent(2,5.234725e-07);
   yieldCombinedPerEventHe__25->SetBinContent(3,3.273803e-07);
   yieldCombinedPerEventHe__25->SetBinError(1,1.06267e-07);
   yieldCombinedPerEventHe__25->SetBinError(2,4.159919e-08);
   yieldCombinedPerEventHe__25->SetBinError(3,2.950211e-08);
   yieldCombinedPerEventHe__25->SetEntries(246.6161);
   yieldCombinedPerEventHe__25->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   yieldCombinedPerEventHe__25->SetLineColor(ci);
   yieldCombinedPerEventHe__25->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   yieldCombinedPerEventHe__25->SetMarkerColor(ci);
   yieldCombinedPerEventHe__25->SetMarkerStyle(8);
   yieldCombinedPerEventHe__25->SetMarkerSize(1.5);
   yieldCombinedPerEventHe__25->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEventHe__25->GetXaxis()->SetRange(1,3);
   yieldCombinedPerEventHe__25->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__25->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe__25->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__25->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEventHe__25->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__25->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__25->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__25->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe__25->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__25->Draw("");
   Double_t xAxis26[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *yieldCombinedPerEventHe__26 = new TH1D("yieldCombinedPerEventHe__26","",3, xAxis26);
   yieldCombinedPerEventHe__26->SetBinContent(1,8.196962e-07);
   yieldCombinedPerEventHe__26->SetBinContent(2,3.989054e-07);
   yieldCombinedPerEventHe__26->SetBinContent(3,3.444901e-07);
   yieldCombinedPerEventHe__26->SetBinError(1,9.72327e-08);
   yieldCombinedPerEventHe__26->SetBinError(2,4.174247e-08);
   yieldCombinedPerEventHe__26->SetBinError(3,3.456555e-08);
   yieldCombinedPerEventHe__26->SetEntries(197.1734);
   yieldCombinedPerEventHe__26->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEventHe__26->SetLineColor(ci);
   yieldCombinedPerEventHe__26->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEventHe__26->SetMarkerColor(ci);
   yieldCombinedPerEventHe__26->SetMarkerStyle(8);
   yieldCombinedPerEventHe__26->SetMarkerSize(1.5);
   yieldCombinedPerEventHe__26->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEventHe__26->GetXaxis()->SetRange(1,3);
   yieldCombinedPerEventHe__26->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__26->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe__26->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__26->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEventHe__26->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__26->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__26->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__26->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe__26->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__26->Draw("same");
   
   TLegend *leg = new TLegend(0.5,0.75,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("yieldCombinedPerEventHe","{}^{3}He","lep");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(8);
   entry->SetMarkerSize(1.5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("yieldCombinedPerEventHe","{}^{3}#bar{He}","lep");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(8);
   entry->SetMarkerSize(1.5);
   entry->SetTextFont(42);
   leg->Draw();
   combinedCanvasCorr->Modified();
   combinedCanvasCorr->SetSelected(combinedCanvasCorr);
}
