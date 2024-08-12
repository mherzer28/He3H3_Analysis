#ifdef __CLING__
#pragma cling optimize(0)
#endif
void H3perEvent_corr_combined()
{
//=========Macro generated from canvas: combinedCanvasCorrH3/
//=========  (Mon Jul 22 20:39:46 2024) by ROOT version 6.30/01
   TCanvas *combinedCanvasCorrH3 = new TCanvas("combinedCanvasCorrH3", "",0,53,1440,847);
   combinedCanvasCorrH3->SetHighLightColor(2);
   combinedCanvasCorrH3->Range(1.25,-6.953985,2.75,-5.616206);
   combinedCanvasCorrH3->SetFillColor(0);
   combinedCanvasCorrH3->SetBorderMode(0);
   combinedCanvasCorrH3->SetBorderSize(2);
   combinedCanvasCorrH3->SetLogy();
   combinedCanvasCorrH3->SetFrameBorderMode(0);
   combinedCanvasCorrH3->SetFrameBorderMode(0);
   Double_t xAxis7[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *yieldCombinedPerEvent0__7 = new TH1D("yieldCombinedPerEvent0__7","",3, xAxis7);
   yieldCombinedPerEvent0__7->SetBinContent(1,8.454889e-07);
   yieldCombinedPerEvent0__7->SetBinContent(2,5.108943e-07);
   yieldCombinedPerEvent0__7->SetBinContent(3,3.698493e-07);
   yieldCombinedPerEvent0__7->SetBinError(1,9.30828e-08);
   yieldCombinedPerEvent0__7->SetBinError(2,6.360276e-08);
   yieldCombinedPerEvent0__7->SetBinError(3,6.728142e-08);
   yieldCombinedPerEvent0__7->SetEntries(172.8818);
   yieldCombinedPerEvent0__7->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   yieldCombinedPerEvent0__7->SetLineColor(ci);
   yieldCombinedPerEvent0__7->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   yieldCombinedPerEvent0__7->SetMarkerColor(ci);
   yieldCombinedPerEvent0__7->SetMarkerStyle(8);
   yieldCombinedPerEvent0__7->SetMarkerSize(1.5);
   yieldCombinedPerEvent0__7->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEvent0__7->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEvent0__7->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEvent0__7->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEvent0__7->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEvent0__7->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEvent0__7->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEvent0__7->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEvent0__7->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEvent0__7->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEvent0__7->Draw("");
   Double_t xAxis8[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *yieldCombinedPerEvent1__8 = new TH1D("yieldCombinedPerEvent1__8","",3, xAxis8);
   yieldCombinedPerEvent1__8->SetBinContent(1,5.938013e-07);
   yieldCombinedPerEvent1__8->SetBinContent(2,4.751127e-07);
   yieldCombinedPerEvent1__8->SetBinContent(3,3.305449e-07);
   yieldCombinedPerEvent1__8->SetBinError(1,6.956605e-08);
   yieldCombinedPerEvent1__8->SetBinError(2,5.781662e-08);
   yieldCombinedPerEvent1__8->SetBinError(3,7.310901e-08);
   yieldCombinedPerEvent1__8->SetEntries(144.7821);
   yieldCombinedPerEvent1__8->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEvent1__8->SetLineColor(ci);
   yieldCombinedPerEvent1__8->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEvent1__8->SetMarkerColor(ci);
   yieldCombinedPerEvent1__8->SetMarkerStyle(8);
   yieldCombinedPerEvent1__8->SetMarkerSize(1.5);
   yieldCombinedPerEvent1__8->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEvent1__8->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEvent1__8->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEvent1__8->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEvent1__8->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEvent1__8->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEvent1__8->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEvent1__8->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEvent1__8->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEvent1__8->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEvent1__8->Draw("same");
   
   TLegend *leg = new TLegend(0.397079,0.726277,0.79694,0.875912,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("yieldCombinedPerEvent0","{}^{3}H","lep");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(8);
   entry->SetMarkerSize(1.5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("yieldCombinedPerEvent1","{}^{3}#bar{H}","lep");

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
   entry=leg->AddEntry("NULL","Corrected","");
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
   combinedCanvasCorrH3->Modified();
   combinedCanvasCorrH3->SetSelected(combinedCanvasCorrH3);
}
