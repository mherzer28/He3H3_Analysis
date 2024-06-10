#ifdef __CLING__
#pragma cling optimize(0)
#endif
void ratioNorHe3H3()
{
//=========Macro generated from canvas: ratioPlot0/
//=========  (Sat Jun  8 18:17:10 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot0 = new TCanvas("ratioPlot0", "",0,53,1440,847);
   ratioPlot0->SetHighLightColor(2);
   ratioPlot0->Range(1.25,-0.25,2.75,2.25);
   ratioPlot0->SetFillColor(0);
   ratioPlot0->SetBorderMode(0);
   ratioPlot0->SetBorderSize(2);
   ratioPlot0->SetFrameBorderMode(0);
   ratioPlot0->SetFrameBorderMode(0);
   Double_t xAxis3[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *histRatio00__3 = new TH1D("histRatio00__3"," ",3, xAxis3);
   histRatio00__3->SetBinContent(1,1.009678);
   histRatio00__3->SetBinContent(2,0.4618783);
   histRatio00__3->SetBinContent(3,0.4884214);
   histRatio00__3->SetBinError(1,0.1534583);
   histRatio00__3->SetBinError(2,0.06793064);
   histRatio00__3->SetBinError(3,0.09896081);
   histRatio00__3->SetMinimum(0);
   histRatio00__3->SetMaximum(2);
   histRatio00__3->SetEntries(101.2063);
   histRatio00__3->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   histRatio00__3->SetLineColor(ci);
   histRatio00__3->SetMarkerStyle(8);
   histRatio00__3->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   histRatio00__3->GetXaxis()->SetLabelFont(42);
   histRatio00__3->GetXaxis()->SetTitleOffset(1);
   histRatio00__3->GetXaxis()->SetTitleFont(42);
   histRatio00__3->GetYaxis()->SetTitle("#frac{{}^{3}H}{{}^{3}He}");
   histRatio00__3->GetYaxis()->SetLabelFont(42);
   histRatio00__3->GetYaxis()->SetTitleFont(42);
   histRatio00__3->GetZaxis()->SetLabelFont(42);
   histRatio00__3->GetZaxis()->SetTitleOffset(1);
   histRatio00__3->GetZaxis()->SetTitleFont(42);
   histRatio00__3->Draw("");
   TLine *line = new TLine(1.4,1,2.6,1);

   ci = TColor::GetColor("#666666");
   line->SetLineColor(ci);
   line->SetLineStyle(3);
   line->SetLineWidth(3);
   line->Draw();
   
   TLegend *leg = new TLegend(0.1,0.7,0.48,0.9,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("NULL","This work","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","ALICE pp #sqrt{s} = 13 TeV","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","High-multiplicity trigger","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.4861752,0.94,0.5138248,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText(" ");
   pt->Draw();
   ratioPlot0->Modified();
   ratioPlot0->SetSelected(ratioPlot0);
}
