#ifdef __CLING__
#pragma cling optimize(0)
#endif
void H3perEvent0()
{
//=========Macro generated from canvas: ratioPlot_event10/
//=========  (Mon Jul  8 14:29:27 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot_event10 = new TCanvas("ratioPlot_event10", "",0,53,1440,847);
   ratioPlot_event10->SetHighLightColor(2);
   ratioPlot_event10->Range(0,0,1,1);
   ratioPlot_event10->SetFillColor(0);
   ratioPlot_event10->SetBorderMode(0);
   ratioPlot_event10->SetBorderSize(2);
   ratioPlot_event10->SetLogy();
   ratioPlot_event10->SetFrameBorderMode(0);
   Double_t xAxis4[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *yieldCombinedPerEventH3_uncorrected0__4 = new TH1D("yieldCombinedPerEventH3_uncorrected0__4","",3, xAxis4);
   yieldCombinedPerEventH3_uncorrected0__4->SetBinContent(1,5.560897e-09);
   yieldCombinedPerEventH3_uncorrected0__4->SetBinContent(2,2.02588e-08);
   yieldCombinedPerEventH3_uncorrected0__4->SetBinContent(3,2.546449e-08);
   yieldCombinedPerEventH3_uncorrected0__4->SetBinError(1,1.583645e-09);
   yieldCombinedPerEventH3_uncorrected0__4->SetBinError(2,2.782423e-09);
   yieldCombinedPerEventH3_uncorrected0__4->SetBinError(3,5.136906e-09);
   yieldCombinedPerEventH3_uncorrected0__4->SetEntries(3);
   yieldCombinedPerEventH3_uncorrected0__4->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   yieldCombinedPerEventH3_uncorrected0__4->SetLineColor(ci);
   yieldCombinedPerEventH3_uncorrected0__4->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   yieldCombinedPerEventH3_uncorrected0__4->SetMarkerColor(ci);
   yieldCombinedPerEventH3_uncorrected0__4->SetMarkerStyle(8);
   yieldCombinedPerEventH3_uncorrected0__4->SetMarkerSize(1.5);
   yieldCombinedPerEventH3_uncorrected0__4->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEventH3_uncorrected0__4->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEventH3_uncorrected0__4->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEventH3_uncorrected0__4->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEventH3_uncorrected0__4->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEventH3_uncorrected0__4->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEventH3_uncorrected0__4->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEventH3_uncorrected0__4->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEventH3_uncorrected0__4->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEventH3_uncorrected0__4->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEventH3_uncorrected0__4->Draw("");
   
   TLegend *leg = new TLegend(0,0,0,0,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("NULL","Uncorrected","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("NULL","ALICE pp #sqrt{s} = 13 TeV, |y| < 0.5","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("NULL","Particle: {}^{3}H","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("NULL","TRD trigger","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   leg->Draw();
   ratioPlot_event10->Modified();
   ratioPlot_event10->SetSelected(ratioPlot_event10);
}
