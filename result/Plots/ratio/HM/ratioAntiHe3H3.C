#ifdef __CLING__
#pragma cling optimize(0)
#endif
void ratioAntiHe3H3()
{
//=========Macro generated from canvas: ratioPlot1/
//=========  (Mon Jul  8 14:31:46 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot1 = new TCanvas("ratioPlot1", "",0,53,1440,847);
   ratioPlot1->SetHighLightColor(2);
   ratioPlot1->Range(1.25,-0.25,2.75,2.25);
   ratioPlot1->SetFillColor(0);
   ratioPlot1->SetBorderMode(0);
   ratioPlot1->SetBorderSize(2);
   ratioPlot1->SetFrameBorderMode(0);
   ratioPlot1->SetFrameBorderMode(0);
   Double_t xAxis2[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *histRatio01__2 = new TH1D("histRatio01__2"," ",3, xAxis2);
   histRatio01__2->SetBinContent(1,1.110848);
   histRatio01__2->SetBinContent(2,0.8644248);
   histRatio01__2->SetBinContent(3,0.5831165);
   histRatio01__2->SetBinError(1,0.1841767);
   histRatio01__2->SetBinError(2,0.1382381);
   histRatio01__2->SetBinError(3,0.1414222);
   histRatio01__2->SetMinimum(0);
   histRatio01__2->SetMaximum(2);
   histRatio01__2->SetEntries(89.62424);
   histRatio01__2->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   histRatio01__2->SetLineColor(ci);
   histRatio01__2->SetMarkerStyle(8);
   histRatio01__2->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   histRatio01__2->GetXaxis()->SetLabelFont(42);
   histRatio01__2->GetXaxis()->SetTitleOffset(1);
   histRatio01__2->GetXaxis()->SetTitleFont(42);
   histRatio01__2->GetYaxis()->SetTitle("#frac{{}^{3}#bar{H}}{{}^{3}#bar{He}}");
   histRatio01__2->GetYaxis()->SetLabelFont(42);
   histRatio01__2->GetYaxis()->SetTitleFont(42);
   histRatio01__2->GetZaxis()->SetLabelFont(42);
   histRatio01__2->GetZaxis()->SetTitleOffset(1);
   histRatio01__2->GetZaxis()->SetTitleFont(42);
   histRatio01__2->Draw("");
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
   ratioPlot1->Modified();
   ratioPlot1->SetSelected(ratioPlot1);
}
