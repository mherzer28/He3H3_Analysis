#ifdef __CLING__
#pragma cling optimize(0)
#endif
void H3perEvent_corr_combined()
{
//=========Macro generated from canvas: combinedCanvasCorrH3/
//=========  (Mon Aug  5 13:07:08 2024) by ROOT version 6.30/01
   TCanvas *combinedCanvasCorrH3 = new TCanvas("combinedCanvasCorrH3", "",0,53,1440,847);
   combinedCanvasCorrH3->SetHighLightColor(2);
   combinedCanvasCorrH3->Range(1.1125,-5.073762,2.9875,-3.541935);
   combinedCanvasCorrH3->SetFillColor(0);
   combinedCanvasCorrH3->SetBorderMode(0);
   combinedCanvasCorrH3->SetBorderSize(2);
   combinedCanvasCorrH3->SetLogy();
   combinedCanvasCorrH3->SetFrameBorderMode(0);
   combinedCanvasCorrH3->SetFrameBorderMode(0);
   Double_t xAxis20[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *yieldCombinedPerEvent0__20 = new TH1D("yieldCombinedPerEvent0__20","",3, xAxis20);
   yieldCombinedPerEvent0__20->SetBinContent(1,3.892064e-05);
   yieldCombinedPerEvent0__20->SetBinContent(2,4.74692e-05);
   yieldCombinedPerEvent0__20->SetBinContent(3,8.401954e-05);
   yieldCombinedPerEvent0__20->SetBinError(1,1.490741e-05);
   yieldCombinedPerEvent0__20->SetBinError(2,9.592676e-06);
   yieldCombinedPerEvent0__20->SetBinError(3,2.247658e-05);
   yieldCombinedPerEvent0__20->SetEntries(35.43775);
   yieldCombinedPerEvent0__20->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   yieldCombinedPerEvent0__20->SetLineColor(ci);
   yieldCombinedPerEvent0__20->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   yieldCombinedPerEvent0__20->SetMarkerColor(ci);
   yieldCombinedPerEvent0__20->SetMarkerStyle(8);
   yieldCombinedPerEvent0__20->SetMarkerSize(1.5);
   yieldCombinedPerEvent0__20->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEvent0__20->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEvent0__20->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEvent0__20->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEvent0__20->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEvent0__20->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEvent0__20->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEvent0__20->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEvent0__20->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEvent0__20->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEvent0__20->Draw("");
   Double_t xAxis21[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *yieldCombinedPerEvent1__21 = new TH1D("yieldCombinedPerEvent1__21","",3, xAxis21);
   yieldCombinedPerEvent1__21->SetBinContent(1,3.896665e-06);
   yieldCombinedPerEvent1__21->SetBinContent(2,1.65184e-05);
   yieldCombinedPerEvent1__21->SetBinContent(3,2.333844e-05);
   yieldCombinedPerEvent1__21->SetBinError(1,1.649494e-06);
   yieldCombinedPerEvent1__21->SetBinError(2,1.72018e-06);
   yieldCombinedPerEvent1__21->SetBinError(3,4.446527e-06);
   yieldCombinedPerEvent1__21->SetEntries(75.21649);
   yieldCombinedPerEvent1__21->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEvent1__21->SetLineColor(ci);
   yieldCombinedPerEvent1__21->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEvent1__21->SetMarkerColor(ci);
   yieldCombinedPerEvent1__21->SetMarkerStyle(8);
   yieldCombinedPerEvent1__21->SetMarkerSize(1.5);
   yieldCombinedPerEvent1__21->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEvent1__21->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEvent1__21->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEvent1__21->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEvent1__21->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEvent1__21->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEvent1__21->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEvent1__21->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEvent1__21->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEvent1__21->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEvent1__21->Draw("same");
   
   TLegend *leg = new TLegend(0.397079,0.726277,0.79694,0.875912,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("yieldCombinedPerEvent0","{}^{3}H","lep");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(8);
   entry->SetMarkerSize(1.5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("yieldCombinedPerEvent1","{}^{3}#bar{H}","lep");

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
   entry=leg->AddEntry("NULL","TRD trigger","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   combinedCanvasCorrH3->Modified();
   combinedCanvasCorrH3->SetSelected(combinedCanvasCorrH3);
}
