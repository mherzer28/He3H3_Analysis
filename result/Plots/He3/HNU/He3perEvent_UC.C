#ifdef __CLING__
#pragma cling optimize(0)
#endif
void He3perEvent_UC()
{
//=========Macro generated from canvas: ratioPlot_event2/
//=========  (Sun Jul  7 14:19:47 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot_event2 = new TCanvas("ratioPlot_event2", "",0,53,1440,847);
   ratioPlot_event2->SetHighLightColor(2);
   ratioPlot_event2->Range(0,0,1,1);
   ratioPlot_event2->SetFillColor(0);
   ratioPlot_event2->SetBorderMode(0);
   ratioPlot_event2->SetBorderSize(2);
   ratioPlot_event2->SetLogy();
   ratioPlot_event2->SetFrameBorderMode(0);
   Double_t xAxis5[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *yieldCombinedPerEventHe3_uncorrected__5 = new TH1D("yieldCombinedPerEventHe3_uncorrected__5","",3, xAxis5);
   yieldCombinedPerEventHe3_uncorrected__5->SetBinContent(1,4.292767e-08);
   yieldCombinedPerEventHe3_uncorrected__5->SetBinContent(2,1.314247e-07);
   yieldCombinedPerEventHe3_uncorrected__5->SetBinContent(3,6.93447e-08);
   yieldCombinedPerEventHe3_uncorrected__5->SetBinError(1,3.765006e-09);
   yieldCombinedPerEventHe3_uncorrected__5->SetBinError(2,6.587726e-09);
   yieldCombinedPerEventHe3_uncorrected__5->SetBinError(3,4.785239e-09);
   yieldCombinedPerEventHe3_uncorrected__5->SetEntries(3);
   yieldCombinedPerEventHe3_uncorrected__5->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#990099");
   yieldCombinedPerEventHe3_uncorrected__5->SetLineColor(ci);
   yieldCombinedPerEventHe3_uncorrected__5->SetLineWidth(2);

   ci = TColor::GetColor("#990099");
   yieldCombinedPerEventHe3_uncorrected__5->SetMarkerColor(ci);
   yieldCombinedPerEventHe3_uncorrected__5->SetMarkerStyle(8);
   yieldCombinedPerEventHe3_uncorrected__5->SetMarkerSize(1.5);
   yieldCombinedPerEventHe3_uncorrected__5->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEventHe3_uncorrected__5->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe3_uncorrected__5->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe3_uncorrected__5->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe3_uncorrected__5->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEventHe3_uncorrected__5->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe3_uncorrected__5->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe3_uncorrected__5->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe3_uncorrected__5->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe3_uncorrected__5->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe3_uncorrected__5->Draw("");
   
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
   entry=leg->AddEntry("NULL","Particle: {}^{3}He","");
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
   ratioPlot_event2->Modified();
   ratioPlot_event2->SetSelected(ratioPlot_event2);
}
