#ifdef __CLING__
#pragma cling optimize(0)
#endif
void corrRatioPartHe3H3_HNU()
{
//=========Macro generated from canvas: ratioPlot22/
//=========  (Mon Aug  5 13:07:07 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot22 = new TCanvas("ratioPlot22", "",0,53,1440,847);
   ratioPlot22->SetHighLightColor(2);
   ratioPlot22->Range(1.1125,-0.25,2.9875,2.25);
   ratioPlot22->SetFillColor(0);
   ratioPlot22->SetBorderMode(0);
   ratioPlot22->SetBorderSize(2);
   ratioPlot22->SetFrameBorderMode(0);
   ratioPlot22->SetFrameBorderMode(0);
   Double_t xAxis15[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *histRatio00__15 = new TH1D("histRatio00__15"," ",3, xAxis15);
   histRatio00__15->SetBinContent(1,5.868681);
   histRatio00__15->SetBinContent(2,26.48511);
   histRatio00__15->SetBinContent(3,116.2268);
   histRatio00__15->SetBinError(1,2.366186);
   histRatio00__15->SetBinError(2,5.707815);
   histRatio00__15->SetBinError(3,33.54788);
   histRatio00__15->SetMinimum(0);
   histRatio00__15->SetMaximum(2);
   histRatio00__15->SetEntries(18.97171);
   histRatio00__15->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   histRatio00__15->SetLineColor(ci);
   histRatio00__15->SetMarkerStyle(8);
   histRatio00__15->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   histRatio00__15->GetXaxis()->SetLabelFont(42);
   histRatio00__15->GetXaxis()->SetTitleOffset(1);
   histRatio00__15->GetXaxis()->SetTitleFont(42);
   histRatio00__15->GetYaxis()->SetTitle("#frac{{}^{3}H}{{}^{3}He}");
   histRatio00__15->GetYaxis()->SetLabelFont(42);
   histRatio00__15->GetYaxis()->SetTitleFont(42);
   histRatio00__15->GetZaxis()->SetLabelFont(42);
   histRatio00__15->GetZaxis()->SetTitleOffset(1);
   histRatio00__15->GetZaxis()->SetTitleFont(42);
   histRatio00__15->Draw("");
   TLine *line = new TLine(1.3,1,2.8,1);

   ci = TColor::GetColor("#666666");
   line->SetLineColor(ci);
   line->SetLineStyle(3);
   line->SetLineWidth(3);
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
   ratioPlot22->Modified();
   ratioPlot22->SetSelected(ratioPlot22);
}
