#ifdef __CLING__
#pragma cling optimize(0)
#endif
void He3perEvent_UC1()
{
//=========Macro generated from canvas: ratioPlot_event21/
//=========  (Mon Aug  5 13:07:07 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot_event21 = new TCanvas("ratioPlot_event21", "",0,53,1440,847);
   ratioPlot_event21->SetHighLightColor(2);
   ratioPlot_event21->Range(0,0,1,1);
   ratioPlot_event21->SetFillColor(0);
   ratioPlot_event21->SetBorderMode(0);
   ratioPlot_event21->SetBorderSize(2);
   ratioPlot_event21->SetLogy();
   ratioPlot_event21->SetFrameBorderMode(0);
   Double_t xAxis10[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *yieldCombinedPerEventHe3_uncorrected1__10 = new TH1D("yieldCombinedPerEventHe3_uncorrected1__10","",3, xAxis10);
   yieldCombinedPerEventHe3_uncorrected1__10->SetBinContent(1,1.948256e-08);
   yieldCombinedPerEventHe3_uncorrected1__10->SetBinContent(2,6.769364e-08);
   yieldCombinedPerEventHe3_uncorrected1__10->SetBinContent(3,4.094639e-08);
   yieldCombinedPerEventHe3_uncorrected1__10->SetBinError(1,2.536413e-09);
   yieldCombinedPerEventHe3_uncorrected1__10->SetBinError(2,4.727929e-09);
   yieldCombinedPerEventHe3_uncorrected1__10->SetBinError(3,3.677095e-09);
   yieldCombinedPerEventHe3_uncorrected1__10->SetEntries(3);
   yieldCombinedPerEventHe3_uncorrected1__10->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEventHe3_uncorrected1__10->SetLineColor(ci);
   yieldCombinedPerEventHe3_uncorrected1__10->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEventHe3_uncorrected1__10->SetMarkerColor(ci);
   yieldCombinedPerEventHe3_uncorrected1__10->SetMarkerStyle(8);
   yieldCombinedPerEventHe3_uncorrected1__10->SetMarkerSize(1.5);
   yieldCombinedPerEventHe3_uncorrected1__10->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEventHe3_uncorrected1__10->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe3_uncorrected1__10->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe3_uncorrected1__10->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe3_uncorrected1__10->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEventHe3_uncorrected1__10->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe3_uncorrected1__10->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe3_uncorrected1__10->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe3_uncorrected1__10->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe3_uncorrected1__10->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe3_uncorrected1__10->Draw("");
   
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
   ratioPlot_event21->Modified();
   ratioPlot_event21->SetSelected(ratioPlot_event21);
}
