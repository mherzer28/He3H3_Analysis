#ifdef __CLING__
#pragma cling optimize(0)
#endif
void corrRatioAntiPartHe3H3_HNU()
{
//=========Macro generated from canvas: ratioPlot3/
//=========  (Mon Jul  8 14:29:28 2024) by ROOT version 6.30/01
   TCanvas *ratioPlot3 = new TCanvas("ratioPlot3", "",0,53,1440,847);
   ratioPlot3->SetHighLightColor(2);
   ratioPlot3->Range(1.1125,-0.25,2.9875,2.25);
   ratioPlot3->SetFillColor(0);
   ratioPlot3->SetBorderMode(0);
   ratioPlot3->SetBorderSize(2);
   ratioPlot3->SetFrameBorderMode(0);
   ratioPlot3->SetFrameBorderMode(0);
   Double_t xAxis16[4] = {1.3, 1.8, 2.3, 2.8}; 
   
   TH1D *histRatio01__16 = new TH1D("histRatio01__16"," ",3, xAxis16);
   histRatio01__16->SetBinContent(1,0.3826661);
   histRatio01__16->SetBinContent(2,1.340886);
   histRatio01__16->SetBinContent(3,2.438769);
   histRatio01__16->SetBinError(1,0.1664894);
   histRatio01__16->SetBinError(2,0.1532011);
   histRatio01__16->SetBinError(3,0.4508651);
   histRatio01__16->SetMinimum(0);
   histRatio01__16->SetMaximum(2);
   histRatio01__16->SetEntries(68.08273);
   histRatio01__16->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   histRatio01__16->SetLineColor(ci);
   histRatio01__16->SetMarkerStyle(8);
   histRatio01__16->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c})");
   histRatio01__16->GetXaxis()->SetLabelFont(42);
   histRatio01__16->GetXaxis()->SetTitleOffset(1);
   histRatio01__16->GetXaxis()->SetTitleFont(42);
   histRatio01__16->GetYaxis()->SetTitle("#frac{{}^{3}#bar{H}}{{}^{3}#bar{He}}");
   histRatio01__16->GetYaxis()->SetLabelFont(42);
   histRatio01__16->GetYaxis()->SetTitleFont(42);
   histRatio01__16->GetZaxis()->SetLabelFont(42);
   histRatio01__16->GetZaxis()->SetTitleOffset(1);
   histRatio01__16->GetZaxis()->SetTitleFont(42);
   histRatio01__16->Draw("");
   TLine *line = new TLine(1.3,1,2.8,1);

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
   ratioPlot3->Modified();
   ratioPlot3->SetSelected(ratioPlot3);
}
