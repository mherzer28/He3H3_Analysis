#ifdef __CLING__
#pragma cling optimize(0)
#endif
void He3perEvent_UC0()
{
//=========Macro generated from canvas: ratioPlot_event20/
//=========  (Mon Aug  5 13:07:07 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot_event20 = new TCanvas("ratioPlot_event20", "",0,53,1440,847);
   ratioPlot_event20->SetHighLightColor(2);
   ratioPlot_event20->Range(0,0,1,1);
   ratioPlot_event20->SetFillColor(0);
   ratioPlot_event20->SetBorderMode(0);
   ratioPlot_event20->SetBorderSize(2);
   ratioPlot_event20->SetLogy();
   ratioPlot_event20->SetFrameBorderMode(0);
   Double_t xAxis9[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *yieldCombinedPerEventHe3_uncorrected0__9 = new TH1D("yieldCombinedPerEventHe3_uncorrected0__9","",3, xAxis9);
   yieldCombinedPerEventHe3_uncorrected0__9->SetBinContent(1,2.476596e-08);
   yieldCombinedPerEventHe3_uncorrected0__9->SetBinContent(2,6.208002e-08);
   yieldCombinedPerEventHe3_uncorrected0__9->SetBinContent(3,2.872852e-08);
   yieldCombinedPerEventHe3_uncorrected0__9->SetBinError(1,2.859727e-09);
   yieldCombinedPerEventHe3_uncorrected0__9->SetBinError(2,4.527651e-09);
   yieldCombinedPerEventHe3_uncorrected0__9->SetBinError(3,3.08002e-09);
   yieldCombinedPerEventHe3_uncorrected0__9->SetEntries(3);
   yieldCombinedPerEventHe3_uncorrected0__9->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   yieldCombinedPerEventHe3_uncorrected0__9->SetLineColor(ci);
   yieldCombinedPerEventHe3_uncorrected0__9->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   yieldCombinedPerEventHe3_uncorrected0__9->SetMarkerColor(ci);
   yieldCombinedPerEventHe3_uncorrected0__9->SetMarkerStyle(8);
   yieldCombinedPerEventHe3_uncorrected0__9->SetMarkerSize(1.5);
   yieldCombinedPerEventHe3_uncorrected0__9->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEventHe3_uncorrected0__9->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe3_uncorrected0__9->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe3_uncorrected0__9->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe3_uncorrected0__9->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEventHe3_uncorrected0__9->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe3_uncorrected0__9->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe3_uncorrected0__9->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEventHe3_uncorrected0__9->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEventHe3_uncorrected0__9->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEventHe3_uncorrected0__9->Draw("");
   
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
   ratioPlot_event20->Modified();
   ratioPlot_event20->SetSelected(ratioPlot_event20);
}
