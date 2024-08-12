#ifdef __CLING__
#pragma cling optimize(0)
#endif
void H3perEvent_UC_combined()
{
//=========Macro generated from canvas: combinedCanvasH3/
//=========  (Mon Jul 22 09:57:29 2024) by ROOT version 6.30/01
   TCanvas *combinedCanvasH3 = new TCanvas("combinedCanvasH3", "",0,53,1440,847);
   combinedCanvasH3->SetHighLightColor(2);
   combinedCanvasH3->Range(1.25,-8.001646,2.75,-6.889827);
   combinedCanvasH3->SetFillColor(0);
   combinedCanvasH3->SetBorderMode(0);
   combinedCanvasH3->SetBorderSize(2);
   combinedCanvasH3->SetLogy();
   combinedCanvasH3->SetFrameBorderMode(0);
   combinedCanvasH3->SetFrameBorderMode(0);
   Double_t xAxis7[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *yieldCombinedPerEventH3_uncorrected0__7 = new TH1D("yieldCombinedPerEventH3_uncorrected0__7","",3, xAxis7);
   yieldCombinedPerEventH3_uncorrected0__7->SetBinContent(1,4.746252e-08);
   yieldCombinedPerEventH3_uncorrected0__7->SetBinContent(2,3.837472e-08);
   yieldCombinedPerEventH3_uncorrected0__7->SetBinContent(3,3.144952e-08);
   yieldCombinedPerEventH3_uncorrected0__7->SetBinError(1,5.192753e-09);
   yieldCombinedPerEventH3_uncorrected0__7->SetBinError(2,4.759237e-09);
   yieldCombinedPerEventH3_uncorrected0__7->SetBinError(3,5.712028e-09);
   yieldCombinedPerEventH3_uncorrected0__7->SetEntries(3);
   yieldCombinedPerEventH3_uncorrected0__7->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   yieldCombinedPerEventH3_uncorrected0__7->SetLineColor(ci);
   yieldCombinedPerEventH3_uncorrected0__7->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   yieldCombinedPerEventH3_uncorrected0__7->SetMarkerColor(ci);
   yieldCombinedPerEventH3_uncorrected0__7->SetMarkerStyle(8);
   yieldCombinedPerEventH3_uncorrected0__7->SetMarkerSize(1.5);
   yieldCombinedPerEventH3_uncorrected0__7->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEventH3_uncorrected0__7->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEventH3_uncorrected0__7->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEventH3_uncorrected0__7->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEventH3_uncorrected0__7->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEventH3_uncorrected0__7->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEventH3_uncorrected0__7->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEventH3_uncorrected0__7->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEventH3_uncorrected0__7->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEventH3_uncorrected0__7->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEventH3_uncorrected0__7->Draw("");
   Double_t xAxis8[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *yieldCombinedPerEventH3_uncorrected1__8 = new TH1D("yieldCombinedPerEventH3_uncorrected1__8","",3, xAxis8);
   yieldCombinedPerEventH3_uncorrected1__8->SetBinContent(1,4.153219e-08);
   yieldCombinedPerEventH3_uncorrected1__8->SetBinContent(2,4.129645e-08);
   yieldCombinedPerEventH3_uncorrected1__8->SetBinContent(3,3.02798e-08);
   yieldCombinedPerEventH3_uncorrected1__8->SetBinError(1,4.843478e-09);
   yieldCombinedPerEventH3_uncorrected1__8->SetBinError(2,5.00771e-09);
   yieldCombinedPerEventH3_uncorrected1__8->SetBinError(3,6.690394e-09);
   yieldCombinedPerEventH3_uncorrected1__8->SetEntries(3);
   yieldCombinedPerEventH3_uncorrected1__8->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEventH3_uncorrected1__8->SetLineColor(ci);
   yieldCombinedPerEventH3_uncorrected1__8->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEventH3_uncorrected1__8->SetMarkerColor(ci);
   yieldCombinedPerEventH3_uncorrected1__8->SetMarkerStyle(8);
   yieldCombinedPerEventH3_uncorrected1__8->SetMarkerSize(1.5);
   yieldCombinedPerEventH3_uncorrected1__8->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEventH3_uncorrected1__8->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEventH3_uncorrected1__8->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEventH3_uncorrected1__8->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEventH3_uncorrected1__8->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEventH3_uncorrected1__8->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEventH3_uncorrected1__8->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEventH3_uncorrected1__8->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEventH3_uncorrected1__8->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEventH3_uncorrected1__8->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEventH3_uncorrected1__8->Draw("same");
   
   TLegend *leg = new TLegend(0.397079,0.726277,0.79694,0.875912,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("yieldCombinedPerEventH3_uncorrected0","{}^{3}H","lep");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(8);
   entry->SetMarkerSize(1.5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("yieldCombinedPerEventH3_uncorrected1","{}^{3}#bar{H}","lep");

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
   
   leg = new TLegend(0.514604,0.681265,0.883866,0.879562,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   entry=leg->AddEntry("NULL","Uncorrected","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","ALICE pp #sqrt{s} = 13 TeV, |y| < 0.5","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","High Multiplicity trigger","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   combinedCanvasH3->Modified();
   combinedCanvasH3->SetSelected(combinedCanvasH3);
}
