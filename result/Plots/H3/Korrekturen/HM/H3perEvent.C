#ifdef __CLING__
#pragma cling optimize(0)
#endif
void H3perEvent()
{
//=========Macro generated from canvas: ratioPlot4/
//=========  (Sun Jul  7 14:19:21 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot4 = new TCanvas("ratioPlot4", "",0,53,1440,847);
   ratioPlot4->SetHighLightColor(2);
   ratioPlot4->Range(0,0,1,1);
   ratioPlot4->SetFillColor(0);
   ratioPlot4->SetBorderMode(0);
   ratioPlot4->SetBorderSize(2);
   ratioPlot4->SetLogy();
   ratioPlot4->SetFrameBorderMode(0);
   Double_t xAxis9[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *yieldCombinedPerEvent__9 = new TH1D("yieldCombinedPerEvent__9","",3, xAxis9);
   yieldCombinedPerEvent__9->SetBinContent(1,1.43929e-06);
   yieldCombinedPerEvent__9->SetBinContent(2,9.86007e-07);
   yieldCombinedPerEvent__9->SetBinContent(3,7.003943e-07);
   yieldCombinedPerEvent__9->SetBinError(1,1.16206e-07);
   yieldCombinedPerEvent__9->SetBinError(2,8.59539e-08);
   yieldCombinedPerEvent__9->SetBinError(3,9.935652e-08);
   yieldCombinedPerEvent__9->SetEntries(317.6639);
   yieldCombinedPerEvent__9->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#990099");
   yieldCombinedPerEvent__9->SetLineColor(ci);
   yieldCombinedPerEvent__9->SetLineWidth(2);

   ci = TColor::GetColor("#990099");
   yieldCombinedPerEvent__9->SetMarkerColor(ci);
   yieldCombinedPerEvent__9->SetMarkerStyle(8);
   yieldCombinedPerEvent__9->SetMarkerSize(1.5);
   yieldCombinedPerEvent__9->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEvent__9->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEvent__9->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEvent__9->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEvent__9->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEvent__9->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEvent__9->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEvent__9->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEvent__9->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEvent__9->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEvent__9->Draw("");
   
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
   ratioPlot4->Modified();
   ratioPlot4->SetSelected(ratioPlot4);
}
