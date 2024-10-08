#ifdef __CLING__
#pragma cling optimize(0)
#endif
void H3perEvent2()
{
//=========Macro generated from canvas: ratioPlot_event_corr12/
//=========  (Fri Aug 23 10:49:10 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot_event_corr12 = new TCanvas("ratioPlot_event_corr12", "",0,53,1440,847);
   ratioPlot_event_corr12->SetHighLightColor(2);
   ratioPlot_event_corr12->Range(0,0,1,1);
   ratioPlot_event_corr12->SetFillColor(0);
   ratioPlot_event_corr12->SetBorderMode(0);
   ratioPlot_event_corr12->SetBorderSize(2);
   ratioPlot_event_corr12->SetLogy();
   ratioPlot_event_corr12->SetFrameBorderMode(0);
   Double_t xAxis19[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *yieldCombinedPerEvent2__19 = new TH1D("yieldCombinedPerEvent2__19","",3, xAxis19);
   yieldCombinedPerEvent2__19->SetBinContent(1,1.43929e-06);
   yieldCombinedPerEvent2__19->SetBinContent(2,9.86007e-07);
   yieldCombinedPerEvent2__19->SetBinContent(3,7.003943e-07);
   yieldCombinedPerEvent2__19->SetBinError(1,1.16206e-07);
   yieldCombinedPerEvent2__19->SetBinError(2,8.59539e-08);
   yieldCombinedPerEvent2__19->SetBinError(3,9.935652e-08);
   yieldCombinedPerEvent2__19->SetEntries(317.6639);
   yieldCombinedPerEvent2__19->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#990099");
   yieldCombinedPerEvent2__19->SetLineColor(ci);
   yieldCombinedPerEvent2__19->SetLineWidth(2);

   ci = TColor::GetColor("#990099");
   yieldCombinedPerEvent2__19->SetMarkerColor(ci);
   yieldCombinedPerEvent2__19->SetMarkerStyle(8);
   yieldCombinedPerEvent2__19->SetMarkerSize(1.5);
   yieldCombinedPerEvent2__19->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEvent2__19->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEvent2__19->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEvent2__19->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEvent2__19->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEvent2__19->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEvent2__19->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEvent2__19->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEvent2__19->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEvent2__19->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEvent2__19->Draw("");
   
   TLegend *leg = new TLegend(0,0,0,0,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("NULL","Corrected","");
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
   ratioPlot_event_corr12->Modified();
   ratioPlot_event_corr12->SetSelected(ratioPlot_event_corr12);
}
