#ifdef __CLING__
#pragma cling optimize(0)
#endif
void H3perEvent1()
{
//=========Macro generated from canvas: ratioPlot_event11/
//=========  (Mon Jul  8 14:31:46 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot_event11 = new TCanvas("ratioPlot_event11", "",0,53,1440,847);
   ratioPlot_event11->SetHighLightColor(2);
   ratioPlot_event11->Range(0,0,1,1);
   ratioPlot_event11->SetFillColor(0);
   ratioPlot_event11->SetBorderMode(0);
   ratioPlot_event11->SetBorderSize(2);
   ratioPlot_event11->SetLogy();
   ratioPlot_event11->SetFrameBorderMode(0);
   Double_t xAxis5[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *yieldCombinedPerEventH3_uncorrected1__5 = new TH1D("yieldCombinedPerEventH3_uncorrected1__5","",3, xAxis5);
   yieldCombinedPerEventH3_uncorrected1__5->SetBinContent(1,8.184283e-08);
   yieldCombinedPerEventH3_uncorrected1__5->SetBinContent(2,8.137827e-08);
   yieldCombinedPerEventH3_uncorrected1__5->SetBinContent(3,5.9669e-08);
   yieldCombinedPerEventH3_uncorrected1__5->SetBinError(1,9.544497e-09);
   yieldCombinedPerEventH3_uncorrected1__5->SetBinError(2,9.868131e-09);
   yieldCombinedPerEventH3_uncorrected1__5->SetBinError(3,1.318401e-08);
   yieldCombinedPerEventH3_uncorrected1__5->SetEntries(3);
   yieldCombinedPerEventH3_uncorrected1__5->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEventH3_uncorrected1__5->SetLineColor(ci);
   yieldCombinedPerEventH3_uncorrected1__5->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEventH3_uncorrected1__5->SetMarkerColor(ci);
   yieldCombinedPerEventH3_uncorrected1__5->SetMarkerStyle(8);
   yieldCombinedPerEventH3_uncorrected1__5->SetMarkerSize(1.5);
   yieldCombinedPerEventH3_uncorrected1__5->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEventH3_uncorrected1__5->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEventH3_uncorrected1__5->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEventH3_uncorrected1__5->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEventH3_uncorrected1__5->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEventH3_uncorrected1__5->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEventH3_uncorrected1__5->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEventH3_uncorrected1__5->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEventH3_uncorrected1__5->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEventH3_uncorrected1__5->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEventH3_uncorrected1__5->Draw("");
   
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
   entry=leg->AddEntry("NULL","High Multiplicity trigger","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   leg->Draw();
   ratioPlot_event11->Modified();
   ratioPlot_event11->SetSelected(ratioPlot_event11);
}
