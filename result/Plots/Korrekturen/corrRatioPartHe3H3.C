#ifdef __CLING__
#pragma cling optimize(0)
#endif
void corrRatioPartHe3H3()
{
//=========Macro generated from canvas: ratioPlot2/
//=========  (Sun Jun  9 16:17:52 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot2 = new TCanvas("ratioPlot2", "",0,53,1440,847);
   ratioPlot2->SetHighLightColor(2);
   ratioPlot2->Range(1.25,-0.25,2.75,2.25);
   ratioPlot2->SetFillColor(0);
   ratioPlot2->SetBorderMode(0);
   ratioPlot2->SetBorderSize(2);
   ratioPlot2->SetFrameBorderMode(0);
   ratioPlot2->SetFrameBorderMode(0);
   Double_t xAxis2[4] = {1.4, 1.8, 2.2, 2.6}; 
   
   TH1D *histRatio00__2 = new TH1D("histRatio00__2"," ",3, xAxis2);
   histRatio00__2->SetBinContent(1,0.8404196);
   histRatio00__2->SetBinContent(2,0.9759715);
   histRatio00__2->SetBinContent(3,1.129724);
   histRatio00__2->SetBinError(1,0.1286362);
   histRatio00__2->SetBinError(2,0.1441455);
   histRatio00__2->SetBinError(3,0.2293484);
   histRatio00__2->SetMinimum(0);
   histRatio00__2->SetMaximum(2);
   histRatio00__2->SetEntries(96.51943);
   histRatio00__2->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   histRatio00__2->SetLineColor(ci);
   histRatio00__2->SetMarkerStyle(8);
   histRatio00__2->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   histRatio00__2->GetXaxis()->SetLabelFont(42);
   histRatio00__2->GetXaxis()->SetTitleOffset(1);
   histRatio00__2->GetXaxis()->SetTitleFont(42);
   histRatio00__2->GetYaxis()->SetTitle("#frac{{}^{3}H}{{}^{3}He}");
   histRatio00__2->GetYaxis()->SetLabelFont(42);
   histRatio00__2->GetYaxis()->SetTitleFont(42);
   histRatio00__2->GetZaxis()->SetLabelFont(42);
   histRatio00__2->GetZaxis()->SetTitleOffset(1);
   histRatio00__2->GetZaxis()->SetTitleFont(42);
   histRatio00__2->Draw("");
   TLine *line = new TLine(1.4,1,2.6,1);

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
   entry=leg->AddEntry("NULL","High Multiplicity trigger","");
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
