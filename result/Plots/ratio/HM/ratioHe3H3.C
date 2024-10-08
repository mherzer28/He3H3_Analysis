#ifdef __CLING__
#pragma cling optimize(0)
#endif
void ratioHe3H3()
{
//=========Macro generated from canvas: ratioPlot2/
//=========  (Fri Aug 23 10:49:08 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot2 = new TCanvas("ratioPlot2", "",0,53,1440,847);
   ratioPlot2->SetHighLightColor(2);
   ratioPlot2->Range(1.25,-0.25,2.75,2.25);
   ratioPlot2->SetFillColor(0);
   ratioPlot2->SetBorderMode(0);
   ratioPlot2->SetBorderSize(2);
   ratioPlot2->SetFrameBorderMode(0);
   ratioPlot2->SetFrameBorderMode(0);
   Double_t xAxis1[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *histRatio02__1 = new TH1D("histRatio02__1"," ",3, xAxis1);
   histRatio02__1->SetBinContent(1,1.113154);
   histRatio02__1->SetBinContent(2,0.6369067);
   histRatio02__1->SetBinContent(3,0.6259997);
   histRatio02__1->SetBinError(1,0.1222667);
   histRatio02__1->SetBinError(2,0.06642812);
   histRatio02__1->SetBinError(3,0.08791131);
   histRatio02__1->SetMinimum(0);
   histRatio02__1->SetMaximum(2);
   histRatio02__1->SetEntries(208.4021);
   histRatio02__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#990099");
   histRatio02__1->SetLineColor(ci);
   histRatio02__1->SetMarkerStyle(8);
   histRatio02__1->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   histRatio02__1->GetXaxis()->SetLabelFont(42);
   histRatio02__1->GetXaxis()->SetTitleOffset(1);
   histRatio02__1->GetXaxis()->SetTitleFont(42);
   histRatio02__1->GetYaxis()->SetTitle("#frac{{}^{3}H}{{}^{3}He}");
   histRatio02__1->GetYaxis()->SetLabelFont(42);
   histRatio02__1->GetYaxis()->SetTitleFont(42);
   histRatio02__1->GetZaxis()->SetLabelFont(42);
   histRatio02__1->GetZaxis()->SetTitleOffset(1);
   histRatio02__1->GetZaxis()->SetTitleFont(42);
   histRatio02__1->Draw("");
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
   ratioPlot2->Modified();
   ratioPlot2->SetSelected(ratioPlot2);
}
