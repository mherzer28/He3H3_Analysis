#ifdef __CLING__
#pragma cling optimize(0)
#endif
void He3perEvent()
{
//=========Macro generated from canvas: ratioPlot52/
//=========  (Mon Jul 22 20:39:46 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot52 = new TCanvas("ratioPlot52", "",0,53,1440,847);
   ratioPlot52->SetHighLightColor(2);
   ratioPlot52->Range(0,0,1,1);
   ratioPlot52->SetFillColor(0);
   ratioPlot52->SetBorderMode(0);
   ratioPlot52->SetBorderSize(2);
   ratioPlot52->SetLogy();
   ratioPlot52->SetFrameBorderMode(0);
   Double_t xAxis11[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *yieldCombinedPerEventHe__11 = new TH1D("yieldCombinedPerEventHe__11","",3, xAxis11);
   yieldCombinedPerEventHe__11->SetBinContent(1,1.81989e-06);
   yieldCombinedPerEventHe__11->SetBinContent(2,9.22378e-07);
   yieldCombinedPerEventHe__11->SetBinContent(3,6.718704e-07);
   yieldCombinedPerEventHe__11->SetBinError(1,1.440378e-07);
   yieldCombinedPerEventHe__11->SetBinError(2,5.893153e-08);
   yieldCombinedPerEventHe__11->SetBinError(3,4.544394e-08);
   yieldCombinedPerEventHe__11->SetEntries(443.7895);
   yieldCombinedPerEventHe__11->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#990099");
   yieldCombinedPerEventHe__11->SetLineColor(ci);
   yieldCombinedPerEventHe__11->SetLineWidth(2);

   ci = TColor::GetColor("#990099");
   yieldCombinedPerEventHe__11->SetMarkerColor(ci);
   yieldCombinedPerEventHe__11->SetMarkerStyle(8);
   yieldCombinedPerEventHe__11->SetMarkerSize(1.5);
   yieldCombinedPerEventHe__11->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEventHe__11->GetXaxis()->SetRange(1,3);
   yieldCombinedPerEventHe__11->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__11->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe__11->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__11->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEventHe__11->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__11->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__11->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__11->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe__11->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__11->Draw("");
   
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
   ratioPlot52->Modified();
   ratioPlot52->SetSelected(ratioPlot52);
}
