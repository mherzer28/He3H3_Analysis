#ifdef __CLING__
#pragma cling optimize(0)
#endif
void corrRatioHe3H3_HNU()
{
//=========Macro generated from canvas: ratioPlot/
//=========  (Mon Aug  5 13:07:07 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot = new TCanvas("ratioPlot", "",0,53,1440,847);
   ratioPlot->SetHighLightColor(2);
   ratioPlot->Range(1.1125,-0.25,2.9875,2.25);
   ratioPlot->SetFillColor(0);
   ratioPlot->SetBorderMode(0);
   ratioPlot->SetBorderSize(2);
   ratioPlot->SetFrameBorderMode(0);
   ratioPlot->SetFrameBorderMode(0);
   Double_t xAxis14[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *histRatio02__14 = new TH1D("histRatio02__14"," ",3, xAxis14);
   histRatio02__14->SetBinContent(1,4.088572);
   histRatio02__14->SetBinContent(2,21.47548);
   histRatio02__14->SetBinContent(3,92.48298);
   histRatio02__14->SetBinError(1,1.483148);
   histRatio02__14->SetBinError(2,3.46479);
   histRatio02__14->SetBinError(3,20.94049);
   histRatio02__14->SetMinimum(0);
   histRatio02__14->SetMaximum(2);
   histRatio02__14->SetEntries(30.78162);
   histRatio02__14->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#990099");
   histRatio02__14->SetLineColor(ci);
   histRatio02__14->SetMarkerStyle(8);
   histRatio02__14->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   histRatio02__14->GetXaxis()->SetLabelFont(42);
   histRatio02__14->GetXaxis()->SetTitleOffset(1);
   histRatio02__14->GetXaxis()->SetTitleFont(42);
   histRatio02__14->GetYaxis()->SetTitle("#frac{{}^{3}H}{{}^{3}He}");
   histRatio02__14->GetYaxis()->SetLabelFont(42);
   histRatio02__14->GetYaxis()->SetTitleFont(42);
   histRatio02__14->GetZaxis()->SetLabelFont(42);
   histRatio02__14->GetZaxis()->SetTitleOffset(1);
   histRatio02__14->GetZaxis()->SetTitleFont(42);
   histRatio02__14->Draw("");
   TLine *line = new TLine(1.4,1,2.6,1);

   ci = TColor::GetColor("#666666");
   line->SetLineColor(ci);
   line->SetLineStyle(3);
   line->Draw();
   
   TLegend *leg = new TLegend(0.0748175,0.672544,0.444343,0.871537,NULL,"brNDC");
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
   ratioPlot->Modified();
   ratioPlot->SetSelected(ratioPlot);
}
