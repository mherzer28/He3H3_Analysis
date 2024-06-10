#ifdef __CLING__
#pragma cling optimize(0)
#endif
void H3perEvent()
{
//=========Macro generated from canvas: ratioPlot4/
//=========  (Sun Jun  9 16:17:53 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot4 = new TCanvas("ratioPlot4", "",0,53,1440,847);
   ratioPlot4->SetHighLightColor(2);
   ratioPlot4->Range(0,0,1,1);
   ratioPlot4->SetFillColor(0);
   ratioPlot4->SetBorderMode(0);
   ratioPlot4->SetBorderSize(2);
   ratioPlot4->SetLogy();
   ratioPlot4->SetFrameBorderMode(0);
   Double_t xAxis4[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *yieldCombinedPerEvent__4 = new TH1D("yieldCombinedPerEvent__4","",3, xAxis4);
   yieldCombinedPerEvent__4->SetBinContent(1,2.826578e-06);
   yieldCombinedPerEvent__4->SetBinContent(2,1.943013e-06);
   yieldCombinedPerEvent__4->SetBinContent(3,1.380188e-06);
   yieldCombinedPerEvent__4->SetBinError(1,2.282569e-07);
   yieldCombinedPerEvent__4->SetBinError(2,1.693797e-07);
   yieldCombinedPerEvent__4->SetBinError(3,1.957907e-07);
   yieldCombinedPerEvent__4->SetEntries(317.5527);
   yieldCombinedPerEvent__4->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEvent__4->SetLineColor(ci);
   yieldCombinedPerEvent__4->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   yieldCombinedPerEvent__4->SetMarkerColor(ci);
   yieldCombinedPerEvent__4->SetMarkerStyle(8);
   yieldCombinedPerEvent__4->SetMarkerSize(1.5);
   yieldCombinedPerEvent__4->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   yieldCombinedPerEvent__4->GetXaxis()->SetRange(1,3);
   yieldCombinedPerEvent__4->GetXaxis()->SetLabelFont(42);
   yieldCombinedPerEvent__4->GetXaxis()->SetTitleOffset(1);
   yieldCombinedPerEvent__4->GetXaxis()->SetTitleFont(42);
   yieldCombinedPerEvent__4->GetYaxis()->SetTitle("1/N_{evt} d^{2}N/(dy d#it{p}_{t}) (GeV/#it{c})^{-1}");
   yieldCombinedPerEvent__4->GetYaxis()->SetLabelFont(42);
   yieldCombinedPerEvent__4->GetYaxis()->SetTitleFont(42);
   yieldCombinedPerEvent__4->GetZaxis()->SetLabelFont(42);
   yieldCombinedPerEvent__4->GetZaxis()->SetTitleOffset(1);
   yieldCombinedPerEvent__4->GetZaxis()->SetTitleFont(42);
   yieldCombinedPerEvent__4->Draw("E");
   
   Double_t Graph0_fx1001[3] = { 1.25, 1.75, 2.25 };
   Double_t Graph0_fy1001[3] = { 1.0374e-06, 1.1954e-06, 8.4629e-07 };
   Double_t Graph0_fex1001[3] = { 0.25, 0.25, 0.25 };
   Double_t Graph0_fey1001[3] = { 1.5696e-07, 6.8876e-08, 6.407e-08 };
   TGraphErrors *gre = new TGraphErrors(3,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(8);
   gre->SetMarkerSize(1.5);
   gre->Draw("p ");
   
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
