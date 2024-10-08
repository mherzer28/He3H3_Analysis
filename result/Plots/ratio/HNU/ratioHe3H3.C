#ifdef __CLING__
#pragma cling optimize(0)
#endif
void ratioHe3H3()
{
//=========Macro generated from canvas: ratioPlot2/
//=========  (Mon Aug  5 13:07:06 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot2 = new TCanvas("ratioPlot2", "",0,53,1440,847);
   ratioPlot2->SetHighLightColor(2);
   ratioPlot2->Range(1.1125,-0.25,2.9875,2.25);
   ratioPlot2->SetFillColor(0);
   ratioPlot2->SetBorderMode(0);
   ratioPlot2->SetBorderSize(2);
   ratioPlot2->SetFrameBorderMode(0);
   ratioPlot2->SetFrameBorderMode(0);
   Double_t xAxis1[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *histRatio02__1 = new TH1D("histRatio02__1"," ",3, xAxis1);
   histRatio02__1->SetBinContent(1,0.21153);
   histRatio02__1->SetBinContent(2,0.5382778);
   histRatio02__1->SetBinContent(3,0.9089304);
   histRatio02__1->SetBinError(1,0.04792551);
   histRatio02__1->SetBinError(2,0.04702708);
   histRatio02__1->SetBinError(3,0.1400917);
   histRatio02__1->SetMinimum(0);
   histRatio02__1->SetMaximum(2);
   histRatio02__1->SetEntries(114.0053);
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
   TLine *line = new TLine(1.3,1,2.8,1);

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
   entry=leg->AddEntry("NULL","TRD trigger","");
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
