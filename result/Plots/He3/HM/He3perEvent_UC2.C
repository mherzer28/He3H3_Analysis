#ifdef __CLING__
#pragma cling optimize(0)
#endif
void He3perEvent_UC2()
{
//=========Macro generated from canvas: ratioPlot_event22/
//=========  (Mon Jul 22 09:57:29 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot_event22 = new TCanvas("ratioPlot_event22", "",0,53,1440,847);
   ratioPlot_event22->SetHighLightColor(2);
   ratioPlot_event22->Range(0,0,1,1);
   ratioPlot_event22->SetFillColor(0);
   ratioPlot_event22->SetBorderMode(0);
   ratioPlot_event22->SetBorderSize(2);
   ratioPlot_event22->SetLogy();
   ratioPlot_event22->SetFrameBorderMode(0);
   Double_t xAxis11[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *yieldCombinedPerEventHe3_uncorrected2__11 = new TH1D("yieldCombinedPerEventHe3_uncorrected2__11","",3, xAxis11);
   yieldCombinedPerEventHe3_uncorrected2__11->SetBinContent(1,8.360332e-08);
   yieldCombinedPerEventHe3_uncorrected2__11->SetBinContent(2,1.308574e-07);
   yieldCombinedPerEventHe3_uncorrected2__11->SetBinContent(3,1.163177e-07);
   yieldCombinedPerEventHe3_uncorrected2__11->SetBinError(1,6.588865e-09);
   yieldCombinedPerEventHe3_uncorrected2__11->SetBinError(2,8.24324e-09);
   yieldCombinedPerEventHe3_uncorrected2__11->SetBinError(3,7.771801e-09);
   yieldCombinedPerEventHe3_uncorrected2__11->SetEntries(3);
   yieldCombinedPerEventHe3_uncorrected2__11->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#990099");
   yieldCombinedPerEventHe3_uncorrected2__11->SetLineColor(ci);
   yieldCombinedPerEventHe3_uncorrected2__11->SetLineWidth(2);

   ci = TColor::GetColor("#990099");
   yieldCombinedPerEventHe3_uncorrected2__11->SetMarkerColor(ci);
   yieldCombinedPerEventHe3_uncorrected2__11->SetMarkerStyle(8);
   yieldCombinedPerEventHe3_uncorrected2__11->SetMarkerSize(1.5);
   yieldCombinedPerEventHe3_uncorrected2__11->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEventHe3_uncorrected2__11->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe3_uncorrected2__11->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe3_uncorrected2__11->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe3_uncorrected2__11->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEventHe3_uncorrected2__11->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe3_uncorrected2__11->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe3_uncorrected2__11->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe3_uncorrected2__11->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe3_uncorrected2__11->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe3_uncorrected2__11->Draw("");
   
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
   entry=leg->AddEntry("NULL","High Multiplicity trigger","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   leg->Draw();
   ratioPlot_event22->Modified();
   ratioPlot_event22->SetSelected(ratioPlot_event22);
}
