#ifdef __CLING__
#pragma cling optimize(0)
#endif
void H3perEvent()
{
//=========Macro generated from canvas: ratioPlot_event1/
//=========  (Sun Jul  7 14:19:20 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot_event1 = new TCanvas("ratioPlot_event1", "",0,53,1440,847);
   ratioPlot_event1->SetHighLightColor(2);
   ratioPlot_event1->Range(0,0,1,1);
   ratioPlot_event1->SetFillColor(0);
   ratioPlot_event1->SetBorderMode(0);
   ratioPlot_event1->SetBorderSize(2);
   ratioPlot_event1->SetLogy();
   ratioPlot_event1->SetFrameBorderMode(0);
   Double_t xAxis4[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *yieldCombinedPerEventH3_uncorrected__4 = new TH1D("yieldCombinedPerEventH3_uncorrected__4","",3, xAxis4);
   yieldCombinedPerEventH3_uncorrected__4->SetBinContent(1,1.833896e-07);
   yieldCombinedPerEventH3_uncorrected__4->SetBinContent(2,1.642365e-07);
   yieldCombinedPerEventH3_uncorrected__4->SetBinContent(3,1.43488e-07);
   yieldCombinedPerEventH3_uncorrected__4->SetBinError(1,1.403047e-08);
   yieldCombinedPerEventH3_uncorrected__4->SetBinError(2,1.365222e-08);
   yieldCombinedPerEventH3_uncorrected__4->SetBinError(3,1.772369e-08);
   yieldCombinedPerEventH3_uncorrected__4->SetEntries(3);
   yieldCombinedPerEventH3_uncorrected__4->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#990099");
   yieldCombinedPerEventH3_uncorrected__4->SetLineColor(ci);
   yieldCombinedPerEventH3_uncorrected__4->SetLineWidth(2);

   ci = TColor::GetColor("#990099");
   yieldCombinedPerEventH3_uncorrected__4->SetMarkerColor(ci);
   yieldCombinedPerEventH3_uncorrected__4->SetMarkerStyle(8);
   yieldCombinedPerEventH3_uncorrected__4->SetMarkerSize(1.5);
   yieldCombinedPerEventH3_uncorrected__4->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEventH3_uncorrected__4->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEventH3_uncorrected__4->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEventH3_uncorrected__4->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEventH3_uncorrected__4->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEventH3_uncorrected__4->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEventH3_uncorrected__4->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEventH3_uncorrected__4->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEventH3_uncorrected__4->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEventH3_uncorrected__4->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEventH3_uncorrected__4->Draw("");
   
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
   ratioPlot_event1->Modified();
   ratioPlot_event1->SetSelected(ratioPlot_event1);
}
