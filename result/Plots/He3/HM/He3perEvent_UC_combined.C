#ifdef __CLING__
#pragma cling optimize(0)
#endif
void He3perEvent_UC_combined()
{
//=========Macro generated from canvas: combinedCanvas/
//=========  (Fri Aug 23 10:49:08 2024) by ROOT version 6.30/01
   TCanvas *combinedCanvas = new TCanvas("combinedCanvas", "",0,53,1440,847);
   combinedCanvas->SetHighLightColor(2);
   combinedCanvas->Range(1.25,-7.7935,2.75,-6.656155);
   combinedCanvas->SetFillColor(0);
   combinedCanvas->SetBorderMode(0);
   combinedCanvas->SetBorderSize(2);
   combinedCanvas->SetLogy();
   combinedCanvas->SetFrameBorderMode(0);
   combinedCanvas->SetFrameBorderMode(0);
   Double_t xAxis12[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *yieldCombinedPerEventHe3_uncorrected0__12 = new TH1D("yieldCombinedPerEventHe3_uncorrected0__12","",3, xAxis12);
   yieldCombinedPerEventHe3_uncorrected0__12->SetBinContent(1,4.673478e-08);
   yieldCombinedPerEventHe3_uncorrected0__12->SetBinContent(2,8.308405e-08);
   yieldCombinedPerEventHe3_uncorrected0__12->SetBinContent(3,6.439014e-08);
   yieldCombinedPerEventHe3_uncorrected0__12->SetBinError(1,4.926278e-09);
   yieldCombinedPerEventHe3_uncorrected0__12->SetBinError(2,6.568371e-09);
   yieldCombinedPerEventHe3_uncorrected0__12->SetBinError(3,5.782405e-09);
   yieldCombinedPerEventHe3_uncorrected0__12->SetEntries(3);
   yieldCombinedPerEventHe3_uncorrected0__12->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   yieldCombinedPerEventHe3_uncorrected0__12->SetLineColor(ci);
   yieldCombinedPerEventHe3_uncorrected0__12->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   yieldCombinedPerEventHe3_uncorrected0__12->SetMarkerColor(ci);
   yieldCombinedPerEventHe3_uncorrected0__12->SetMarkerStyle(8);
   yieldCombinedPerEventHe3_uncorrected0__12->SetMarkerSize(1.5);
   yieldCombinedPerEventHe3_uncorrected0__12->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEventHe3_uncorrected0__12->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe3_uncorrected0__12->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe3_uncorrected0__12->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe3_uncorrected0__12->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEventHe3_uncorrected0__12->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe3_uncorrected0__12->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe3_uncorrected0__12->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe3_uncorrected0__12->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe3_uncorrected0__12->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe3_uncorrected0__12->Draw("");
   Double_t xAxis13[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *yieldCombinedPerEventHe3_uncorrected1__13 = new TH1D("yieldCombinedPerEventHe3_uncorrected1__13","",3, xAxis13);
   yieldCombinedPerEventHe3_uncorrected1__13->SetBinContent(1,3.634927e-08);
   yieldCombinedPerEventHe3_uncorrected1__13->SetBinContent(2,4.777333e-08);
   yieldCombinedPerEventHe3_uncorrected1__13->SetBinContent(3,5.192753e-08);
   yieldCombinedPerEventHe3_uncorrected1__13->SetBinError(1,4.344569e-09);
   yieldCombinedPerEventHe3_uncorrected1__13->SetBinError(2,4.980714e-09);
   yieldCombinedPerEventHe3_uncorrected1__13->SetBinError(3,5.192753e-09);
   yieldCombinedPerEventHe3_uncorrected1__13->SetEntries(3);
   yieldCombinedPerEventHe3_uncorrected1__13->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEventHe3_uncorrected1__13->SetLineColor(ci);
   yieldCombinedPerEventHe3_uncorrected1__13->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEventHe3_uncorrected1__13->SetMarkerColor(ci);
   yieldCombinedPerEventHe3_uncorrected1__13->SetMarkerStyle(8);
   yieldCombinedPerEventHe3_uncorrected1__13->SetMarkerSize(1.5);
   yieldCombinedPerEventHe3_uncorrected1__13->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEventHe3_uncorrected1__13->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe3_uncorrected1__13->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe3_uncorrected1__13->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe3_uncorrected1__13->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEventHe3_uncorrected1__13->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe3_uncorrected1__13->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe3_uncorrected1__13->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe3_uncorrected1__13->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe3_uncorrected1__13->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe3_uncorrected1__13->Draw("same");
   
   TLegend *leg = new TLegend(0.397079,0.726277,0.79694,0.875912,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("yieldCombinedPerEventHe3_uncorrected0","{}^{3}He","lep");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(8);
   entry->SetMarkerSize(1.5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("yieldCombinedPerEventHe3_uncorrected1","{}^{3}#bar{He}","lep");

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
   
   leg = new TLegend(0.514604,0.681265,0.883866,0.879562,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   entry=leg->AddEntry("NULL","Uncorrected","");
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
   combinedCanvas->Modified();
   combinedCanvas->SetSelected(combinedCanvas);
}
