#ifdef __CLING__
#pragma cling optimize(0)
#endif
void He3perEvent()
{
//=========Macro generated from canvas: ratioPlot5/
//=========  (Sun Jun  9 16:17:53 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot5 = new TCanvas("ratioPlot5", "",0,53,1440,847);
   ratioPlot5->SetHighLightColor(2);
   ratioPlot5->Range(0,0,1,1);
   ratioPlot5->SetFillColor(0);
   ratioPlot5->SetBorderMode(0);
   ratioPlot5->SetBorderSize(2);
   ratioPlot5->SetLogy();
   ratioPlot5->SetFrameBorderMode(0);
   Double_t xAxis5[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *yieldCombinedPerEventHe__5 = new TH1D("yieldCombinedPerEventHe__5","",3, xAxis5);
   yieldCombinedPerEventHe__5->SetBinContent(1,3.541383e-06);
   yieldCombinedPerEventHe__5->SetBinContent(2,1.817627e-06);
   yieldCombinedPerEventHe__5->SetBinContent(3,1.32398e-06);
   yieldCombinedPerEventHe__5->SetBinError(1,2.820142e-07);
   yieldCombinedPerEventHe__5->SetBinError(2,1.161298e-07);
   yieldCombinedPerEventHe__5->SetBinError(3,8.955127e-08);
   yieldCombinedPerEventHe__5->SetEntries(442.286);
   yieldCombinedPerEventHe__5->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   yieldCombinedPerEventHe__5->SetLineColor(ci);
   yieldCombinedPerEventHe__5->SetMarkerStyle(8);
   yieldCombinedPerEventHe__5->SetMarkerSize(1.5);
   yieldCombinedPerEventHe__5->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEventHe__5->GetXaxis()->SetRange(1,3);
   yieldCombinedPerEventHe__5->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__5->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe__5->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__5->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEventHe__5->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__5->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__5->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__5->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe__5->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__5->Draw("");
   
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
   ratioPlot5->Modified();
   ratioPlot5->SetSelected(ratioPlot5);
}
