#ifdef __CLING__
#pragma cling optimize(0)
#endif
void H3perEvent_HNU0()
{
//=========Macro generated from canvas: ratioPlot_event_corr10/
//=========  (Mon Jul  8 14:29:28 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot_event_corr10 = new TCanvas("ratioPlot_event_corr10", "",0,53,1440,847);
   ratioPlot_event_corr10->SetHighLightColor(2);
   ratioPlot_event_corr10->Range(0,0,1,1);
   ratioPlot_event_corr10->SetFillColor(0);
   ratioPlot_event_corr10->SetBorderMode(0);
   ratioPlot_event_corr10->SetBorderSize(2);
   ratioPlot_event_corr10->SetLogy();
   ratioPlot_event_corr10->SetFrameBorderMode(0);
   Double_t xAxis17[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *yieldCombinedPerEvent0__17 = new TH1D("yieldCombinedPerEvent0__17","",3, xAxis17);
   yieldCombinedPerEvent0__17->SetBinContent(1,7.149649e-06);
   yieldCombinedPerEvent0__17->SetBinContent(2,2.582091e-06);
   yieldCombinedPerEvent0__17->SetBinContent(3,2.406558e-06);
   yieldCombinedPerEvent0__17->SetBinError(1,2.182313e-06);
   yieldCombinedPerEvent0__17->SetBinError(2,3.658591e-07);
   yieldCombinedPerEvent0__17->SetBinError(3,4.908239e-07);
   yieldCombinedPerEvent0__17->SetEntries(28.68037);
   yieldCombinedPerEvent0__17->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   yieldCombinedPerEvent0__17->SetLineColor(ci);
   yieldCombinedPerEvent0__17->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   yieldCombinedPerEvent0__17->SetMarkerColor(ci);
   yieldCombinedPerEvent0__17->SetMarkerStyle(8);
   yieldCombinedPerEvent0__17->SetMarkerSize(1.5);
   yieldCombinedPerEvent0__17->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEvent0__17->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEvent0__17->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEvent0__17->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEvent0__17->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEvent0__17->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEvent0__17->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEvent0__17->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEvent0__17->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEvent0__17->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEvent0__17->Draw("");
   
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
   entry=leg->AddEntry("NULL","TRD trigger","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   leg->Draw();
   ratioPlot_event_corr10->Modified();
   ratioPlot_event_corr10->SetSelected(ratioPlot_event_corr10);
}
