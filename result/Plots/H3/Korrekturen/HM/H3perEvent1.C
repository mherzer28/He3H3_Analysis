#ifdef __CLING__
#pragma cling optimize(0)
#endif
void H3perEvent1()
{
//=========Macro generated from canvas: ratioPlot_event_corr11/
//=========  (Mon Jul  8 14:31:47 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot_event_corr11 = new TCanvas("ratioPlot_event_corr11", "",0,53,1440,847);
   ratioPlot_event_corr11->SetHighLightColor(2);
   ratioPlot_event_corr11->Range(0,0,1,1);
   ratioPlot_event_corr11->SetFillColor(0);
   ratioPlot_event_corr11->SetBorderMode(0);
   ratioPlot_event_corr11->SetBorderSize(2);
   ratioPlot_event_corr11->SetLogy();
   ratioPlot_event_corr11->SetFrameBorderMode(0);
   Double_t xAxis18[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *yieldCombinedPerEvent1__18 = new TH1D("yieldCombinedPerEvent1__18","",3, xAxis18);
   yieldCombinedPerEvent1__18->SetBinContent(1,5.938013e-07);
   yieldCombinedPerEvent1__18->SetBinContent(2,4.751127e-07);
   yieldCombinedPerEvent1__18->SetBinContent(3,3.305449e-07);
   yieldCombinedPerEvent1__18->SetBinError(1,6.956605e-08);
   yieldCombinedPerEvent1__18->SetBinError(2,5.781662e-08);
   yieldCombinedPerEvent1__18->SetBinError(3,7.310901e-08);
   yieldCombinedPerEvent1__18->SetEntries(144.7821);
   yieldCombinedPerEvent1__18->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEvent1__18->SetLineColor(ci);
   yieldCombinedPerEvent1__18->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEvent1__18->SetMarkerColor(ci);
   yieldCombinedPerEvent1__18->SetMarkerStyle(8);
   yieldCombinedPerEvent1__18->SetMarkerSize(1.5);
   yieldCombinedPerEvent1__18->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEvent1__18->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEvent1__18->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEvent1__18->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEvent1__18->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEvent1__18->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEvent1__18->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEvent1__18->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEvent1__18->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEvent1__18->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEvent1__18->Draw("");
   
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
   ratioPlot_event_corr11->Modified();
   ratioPlot_event_corr11->SetSelected(ratioPlot_event_corr11);
}
