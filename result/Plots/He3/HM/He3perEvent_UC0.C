#ifdef __CLING__
#pragma cling optimize(0)
#endif
void He3perEvent_UC0()
{
//=========Macro generated from canvas: ratioPlot_event20/
//=========  (Mon Jul  8 14:31:46 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot_event20 = new TCanvas("ratioPlot_event20", "",0,53,1440,847);
   ratioPlot_event20->SetHighLightColor(2);
   ratioPlot_event20->Range(0,0,1,1);
   ratioPlot_event20->SetFillColor(0);
   ratioPlot_event20->SetBorderMode(0);
   ratioPlot_event20->SetBorderSize(2);
   ratioPlot_event20->SetLogy();
   ratioPlot_event20->SetFrameBorderMode(0);
   Double_t xAxis9[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *yieldCombinedPerEventHe3_uncorrected0__9 = new TH1D("yieldCombinedPerEventHe3_uncorrected0__9","",3, xAxis9);
   yieldCombinedPerEventHe3_uncorrected0__9->SetBinContent(1,9.209498e-08);
   yieldCombinedPerEventHe3_uncorrected0__9->SetBinContent(2,1.637244e-07);
   yieldCombinedPerEventHe3_uncorrected0__9->SetBinContent(3,1.268864e-07);
   yieldCombinedPerEventHe3_uncorrected0__9->SetBinError(1,9.707663e-09);
   yieldCombinedPerEventHe3_uncorrected0__9->SetBinError(2,1.294355e-08);
   yieldCombinedPerEventHe3_uncorrected0__9->SetBinError(3,1.139474e-08);
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
   entry=leg->AddEntry("NULL","High Multiplicity trigger","");
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
