#ifdef __CLING__
#pragma cling optimize(0)
#endif
void He3perEvent_HNU()
{
//=========Macro generated from canvas: ratioPlot52/
//=========  (Mon Aug  5 13:07:08 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot52 = new TCanvas("ratioPlot52", "",0,53,1440,847);
   ratioPlot52->SetHighLightColor(2);
   ratioPlot52->Range(0,0,1,1);
   ratioPlot52->SetFillColor(0);
   ratioPlot52->SetBorderMode(0);
   ratioPlot52->SetBorderSize(2);
   ratioPlot52->SetLogy();
   ratioPlot52->SetFrameBorderMode(0);
   Double_t xAxis24[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *yieldCombinedPerEventHe__24 = new TH1D("yieldCombinedPerEventHe__24","",3, xAxis24);
   yieldCombinedPerEventHe__24->SetBinContent(1,1.047244e-05);
   yieldCombinedPerEventHe__24->SetBinContent(2,2.979566e-06);
   yieldCombinedPerEventHe__24->SetBinContent(3,1.16084e-06);
   yieldCombinedPerEventHe__24->SetBinError(1,9.873701e-07);
   yieldCombinedPerEventHe__24->SetBinError(2,1.585775e-07);
   yieldCombinedPerEventHe__24->SetBinError(3,8.780232e-08);
   yieldCombinedPerEventHe__24->SetEntries(220.3386);
   yieldCombinedPerEventHe__24->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#990099");
   yieldCombinedPerEventHe__24->SetLineColor(ci);
   yieldCombinedPerEventHe__24->SetLineWidth(2);

   ci = TColor::GetColor("#990099");
   yieldCombinedPerEventHe__24->SetMarkerColor(ci);
   yieldCombinedPerEventHe__24->SetMarkerStyle(8);
   yieldCombinedPerEventHe__24->SetMarkerSize(1.5);
   yieldCombinedPerEventHe__24->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEventHe__24->GetXaxis()->SetRange(1,3);
   yieldCombinedPerEventHe__24->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__24->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe__24->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__24->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEventHe__24->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__24->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__24->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__24->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe__24->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__24->Draw("");
   
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
   entry=leg->AddEntry("NULL","TRD trigger","");
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
