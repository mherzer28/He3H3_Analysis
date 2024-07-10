#ifdef __CLING__
#pragma cling optimize(0)
#endif
void H3perEvent_HNU()
{
//=========Macro generated from canvas: ratioPlot4/
//=========  (Mon Jul  8 09:42:56 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot4 = new TCanvas("ratioPlot4", "",0,53,1440,847);
   ratioPlot4->SetHighLightColor(2);
   ratioPlot4->Range(0,0,1,1);
   ratioPlot4->SetFillColor(0);
   ratioPlot4->SetBorderMode(0);
   ratioPlot4->SetBorderSize(2);
   ratioPlot4->SetLogy();
   ratioPlot4->SetFrameBorderMode(0);
   Double_t xAxis17[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *yieldCombinedPerEvent__17 = new TH1D("yieldCombinedPerEvent__17","",3, xAxis17);
   yieldCombinedPerEvent__17->SetBinContent(1,8.484495e-06);
   yieldCombinedPerEvent__17->SetBinContent(2,4.305672e-06);
   yieldCombinedPerEvent__17->SetBinContent(3,3.740077e-06);
   yieldCombinedPerEvent__17->SetBinError(1,2.250901e-06);
   yieldCombinedPerEvent__17->SetBinError(2,3.969359e-07);
   yieldCombinedPerEvent__17->SetBinError(3,5.358082e-07);
   yieldCombinedPerEvent__17->SetEntries(80.26267);
   yieldCombinedPerEvent__17->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#990099");
   yieldCombinedPerEvent__17->SetLineColor(ci);
   yieldCombinedPerEvent__17->SetLineWidth(2);

   ci = TColor::GetColor("#990099");
   yieldCombinedPerEvent__17->SetMarkerColor(ci);
   yieldCombinedPerEvent__17->SetMarkerStyle(8);
   yieldCombinedPerEvent__17->SetMarkerSize(1.5);
   yieldCombinedPerEvent__17->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEvent__17->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEvent__17->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEvent__17->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEvent__17->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEvent__17->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEvent__17->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEvent__17->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEvent__17->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEvent__17->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEvent__17->Draw("");
   
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
   ratioPlot4->Modified();
   ratioPlot4->SetSelected(ratioPlot4);
}
