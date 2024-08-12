#ifdef __CLING__
#pragma cling optimize(0)
#endif
void He3perEvent_corr_combined()
{
//=========Macro generated from canvas: combinedCanvasCorr/
//=========  (Mon Aug  5 13:07:08 2024) by ROOT version 6.30/01
   TCanvas *combinedCanvasCorr = new TCanvas("combinedCanvasCorr", "",0,53,1440,847);
   combinedCanvasCorr->SetHighLightColor(2);
   combinedCanvasCorr->Range(1.1125,-6.697092,2.9875,-4.643993);
   combinedCanvasCorr->SetFillColor(0);
   combinedCanvasCorr->SetBorderMode(0);
   combinedCanvasCorr->SetBorderSize(2);
   combinedCanvasCorr->SetLogy();
   combinedCanvasCorr->SetFrameBorderMode(0);
   combinedCanvasCorr->SetFrameBorderMode(0);
   Double_t xAxis25[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *yieldCombinedPerEventHe__25 = new TH1D("yieldCombinedPerEventHe__25","",3, xAxis25);
   yieldCombinedPerEventHe__25->SetBinContent(1,6.631923e-06);
   yieldCombinedPerEventHe__25->SetBinContent(2,1.792297e-06);
   yieldCombinedPerEventHe__25->SetBinContent(3,7.228928e-07);
   yieldCombinedPerEventHe__25->SetBinError(1,8.351039e-07);
   yieldCombinedPerEventHe__25->SetBinError(2,1.342132e-07);
   yieldCombinedPerEventHe__25->SetBinError(3,7.835631e-08);
   yieldCombinedPerEventHe__25->SetEntries(115.958);
   yieldCombinedPerEventHe__25->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   yieldCombinedPerEventHe__25->SetLineColor(ci);
   yieldCombinedPerEventHe__25->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   yieldCombinedPerEventHe__25->SetMarkerColor(ci);
   yieldCombinedPerEventHe__25->SetMarkerStyle(8);
   yieldCombinedPerEventHe__25->SetMarkerSize(1.5);
   yieldCombinedPerEventHe__25->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEventHe__25->GetXaxis()->SetRange(1,3);
   yieldCombinedPerEventHe__25->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__25->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe__25->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__25->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEventHe__25->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__25->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__25->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__25->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe__25->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__25->Draw("");
   Double_t xAxis26[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *yieldCombinedPerEventHe__26 = new TH1D("yieldCombinedPerEventHe__26","",3, xAxis26);
   yieldCombinedPerEventHe__26->SetBinContent(1,3.840512e-06);
   yieldCombinedPerEventHe__26->SetBinContent(2,1.187268e-06);
   yieldCombinedPerEventHe__26->SetBinContent(3,4.379476e-07);
   yieldCombinedPerEventHe__26->SetBinError(1,5.267838e-07);
   yieldCombinedPerEventHe__26->SetBinError(2,8.4461e-08);
   yieldCombinedPerEventHe__26->SetBinError(3,3.961736e-08);
   yieldCombinedPerEventHe__26->SetEntries(104.3806);
   yieldCombinedPerEventHe__26->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEventHe__26->SetLineColor(ci);
   yieldCombinedPerEventHe__26->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEventHe__26->SetMarkerColor(ci);
   yieldCombinedPerEventHe__26->SetMarkerStyle(8);
   yieldCombinedPerEventHe__26->SetMarkerSize(1.5);
   yieldCombinedPerEventHe__26->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEventHe__26->GetXaxis()->SetRange(1,3);
   yieldCombinedPerEventHe__26->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__26->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe__26->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__26->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEventHe__26->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__26->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__26->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe__26->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe__26->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe__26->Draw("same");
   
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
   entry=leg->AddEntry("NULL","TRD trigger","");
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
