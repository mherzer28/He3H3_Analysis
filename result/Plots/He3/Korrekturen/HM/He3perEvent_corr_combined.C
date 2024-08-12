#ifdef __CLING__
#pragma cling optimize(0)
#endif
void He3perEvent_corr_combined()
{
//=========Macro generated from canvas: combinedCanvasCorr/
//=========  (Mon Jul 22 20:39:46 2024) by ROOT version 6.30/01
   TCanvas *combinedCanvasCorr = new TCanvas("combinedCanvasCorr", "",0,53,1440,847);
   combinedCanvasCorr->SetHighLightColor(2);
   combinedCanvasCorr->Range(1.25,-6.970551,2.75,-5.534956);
   combinedCanvasCorr->SetFillColor(0);
   combinedCanvasCorr->SetBorderMode(0);
   combinedCanvasCorr->SetBorderSize(2);
   combinedCanvasCorr->SetLogy();
   combinedCanvasCorr->SetFrameBorderMode(0);
   combinedCanvasCorr->SetFrameBorderMode(0);
   Double_t xAxis12[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *yieldCombinedPerEventHe__12 = new TH1D("yieldCombinedPerEventHe__12","",3, xAxis12);
   yieldCombinedPerEventHe__12->SetBinContent(1,1.000193e-06);
   yieldCombinedPerEventHe__12->SetBinContent(2,5.234725e-07);
   yieldCombinedPerEventHe__12->SetBinContent(3,3.273803e-07);
   yieldCombinedPerEventHe__12->SetBinError(1,1.06267e-07);
   yieldCombinedPerEventHe__12->SetBinError(2,4.159919e-08);
   yieldCombinedPerEventHe__12->SetBinError(3,2.950211e-08);
   yieldCombinedPerEventHe__12->SetEntries(246.6161);
   yieldCombinedPerEventHe__12->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   yieldCombinedPerEventHe__12->SetLineColor(ci);
   yieldCombinedPerEventHe__12->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   yieldCombinedPerEventHe__12->SetMarkerColor(ci);
   yieldCombinedPerEventHe__12->SetMarkerStyle(8);
   yieldCombinedPerEventHe__12->SetMarkerSize(1.5);
   yieldCombinedPerEventHe__12->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEventHe__12->GetXaxis()->SetRange(1,3);
   yieldCombinedPerEventHe__12->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__12->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe__12->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__12->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEventHe__12->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__12->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__12->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__12->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe__12->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__12->Draw("");
   Double_t xAxis13[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *yieldCombinedPerEventHe__13 = new TH1D("yieldCombinedPerEventHe__13","",3, xAxis13);
   yieldCombinedPerEventHe__13->SetBinContent(1,8.196962e-07);
   yieldCombinedPerEventHe__13->SetBinContent(2,3.989054e-07);
   yieldCombinedPerEventHe__13->SetBinContent(3,3.444901e-07);
   yieldCombinedPerEventHe__13->SetBinError(1,9.72327e-08);
   yieldCombinedPerEventHe__13->SetBinError(2,4.174247e-08);
   yieldCombinedPerEventHe__13->SetBinError(3,3.456555e-08);
   yieldCombinedPerEventHe__13->SetEntries(197.1734);
   yieldCombinedPerEventHe__13->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEventHe__13->SetLineColor(ci);
   yieldCombinedPerEventHe__13->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEventHe__13->SetMarkerColor(ci);
   yieldCombinedPerEventHe__13->SetMarkerStyle(8);
   yieldCombinedPerEventHe__13->SetMarkerSize(1.5);
   yieldCombinedPerEventHe__13->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEventHe__13->GetXaxis()->SetRange(1,3);
   yieldCombinedPerEventHe__13->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__13->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe__13->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__13->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEventHe__13->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__13->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__13->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__13->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe__13->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__13->Draw("same");
   
   TLegend *leg = new TLegend(0.397079,0.726277,0.79694,0.875912,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("yieldCombinedPerEventHe","{}^{3}He","lep");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(8);
   entry->SetMarkerSize(1.5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("yieldCombinedPerEventHe","{}^{3}#bar{He}","lep");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(8);
   entry->SetMarkerSize(1.5);
   entry->SetTextFont(42);
   leg->Draw();
   
   leg = new TLegend(0.527121,0.681265,0.896384,0.879562,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   entry=leg->AddEntry("NULL","Corrected","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","ALICE pp #sqrt{s} = 13 TeV, |y| < 0.5","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","High Multiplicity trigger","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   combinedCanvasCorr->Modified();
   combinedCanvasCorr->SetSelected(combinedCanvasCorr);
}
