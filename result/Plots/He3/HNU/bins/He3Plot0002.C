#ifdef __CLING__
#pragma cling optimize(0)
#endif
void He3Plot0002()
{
//=========Macro generated from canvas: pt02/pt02
//=========  (Fri Aug 23 16:17:38 2024) by ROOT version 6.30/01
   TCanvas *pt02 = new TCanvas("pt02", "pt02",0,53,1400,847);
   gStyle->SetOptFit(1);
   pt02->SetHighLightColor(2);
   pt02->Range(1.04,-7.160311,3.44,46.51036);
   pt02->SetFillColor(0);
   pt02->SetBorderMode(0);
   pt02->SetBorderSize(2);
   pt02->SetLeftMargin(0.15);
   pt02->SetTopMargin(0.0661157);
   pt02->SetBottomMargin(0.133412);
   pt02->SetFrameBorderMode(0);
   pt02->SetFrameBorderMode(0);
   
   TH1D *histTOFfit000002__3 = new TH1D("histTOFfit000002__3","",25,1.4,3.2);
   histTOFfit000002__3->SetBinContent(5,1);
   histTOFfit000002__3->SetBinContent(7,7);
   histTOFfit000002__3->SetBinContent(8,26);
   histTOFfit000002__3->SetBinContent(9,35);
   histTOFfit000002__3->SetBinContent(10,11);
   histTOFfit000002__3->SetBinContent(11,7);
   histTOFfit000002__3->SetBinContent(12,1);
   histTOFfit000002__3->SetBinError(5,1);
   histTOFfit000002__3->SetBinError(7,2.645751);
   histTOFfit000002__3->SetBinError(8,5.09902);
   histTOFfit000002__3->SetBinError(9,5.91608);
   histTOFfit000002__3->SetBinError(10,3.316625);
   histTOFfit000002__3->SetBinError(11,2.645751);
   histTOFfit000002__3->SetBinError(12,1);
   histTOFfit000002__3->SetEntries(88);
   histTOFfit000002__3->SetDirectory(nullptr);
   histTOFfit000002__3->SetStats(0);
   
   TF1 *fitfunc3 = new TF1("fitfunc","gaus(0)",1.5,2.5, TF1::EAddToList::kNo);
   fitfunc3->SetFillColor(19);
   fitfunc3->SetFillStyle(0);
   fitfunc3->SetLineColor(2);
   fitfunc3->SetLineWidth(5);
   fitfunc3->SetChisquare(6.081375);
   fitfunc3->SetNDF(5);
   fitfunc3->GetXaxis()->SetLabelFont(42);
   fitfunc3->GetXaxis()->SetTitleOffset(1);
   fitfunc3->GetXaxis()->SetTitleFont(42);
   fitfunc3->GetYaxis()->SetLabelFont(42);
   fitfunc3->GetYaxis()->SetTitleFont(42);
   fitfunc3->SetParameter(0,32.84912);
   fitfunc3->SetParError(0,0);
   fitfunc3->SetParLimits(0,35,35);
   fitfunc3->SetParameter(1,1.991412);
   fitfunc3->SetParError(1,0.008475908);
   fitfunc3->SetParLimits(1,0,0);
   fitfunc3->SetParameter(2,0.07299682);
   fitfunc3->SetParError(2,0.00694279);
   fitfunc3->SetParLimits(2,0,0.8234015);
   fitfunc3->SetParent(histTOFfit000002__3);
   histTOFfit000002__3->GetListOfFunctions()->Add(fitfunc3);
   histTOFfit000002__3->SetLineWidth(5);
   histTOFfit000002__3->SetMarkerStyle(20);
   histTOFfit000002__3->SetMarkerSize(2);
   histTOFfit000002__3->GetXaxis()->SetTitle("m^{2}/z^{2} (GeV^{2}/c^{4})");
   histTOFfit000002__3->GetXaxis()->SetRange(1,25);
   histTOFfit000002__3->GetXaxis()->SetLabelFont(42);
   histTOFfit000002__3->GetXaxis()->SetLabelSize(0.05);
   histTOFfit000002__3->GetXaxis()->SetTitleSize(0.05);
   histTOFfit000002__3->GetXaxis()->SetTitleOffset(1);
   histTOFfit000002__3->GetXaxis()->SetTitleFont(42);
   histTOFfit000002__3->GetYaxis()->SetTitle("Counts / (72 MeV^{2}/c^{4})");
   histTOFfit000002__3->GetYaxis()->SetLabelFont(42);
   histTOFfit000002__3->GetYaxis()->SetLabelSize(0.05);
   histTOFfit000002__3->GetYaxis()->SetTitleSize(0.05);
   histTOFfit000002__3->GetYaxis()->SetTitleFont(42);
   histTOFfit000002__3->GetZaxis()->SetLabelFont(42);
   histTOFfit000002__3->GetZaxis()->SetTitleOffset(1);
   histTOFfit000002__3->GetZaxis()->SetTitleFont(42);
   histTOFfit000002__3->Draw("");
   
   TLegend *leg = new TLegend(0.537196,0.583235,0.927039,0.903188,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.042);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
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
   entry=leg->AddEntry("NULL","Particle: {}^{3}He","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","2.30 < #frac{#it{p}_{T}}{(GeV/#it{c})} < 2.80 ","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","TRD HNU trigger","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   leg = new TLegend(0.213504,0.701511,0.532847,0.845088,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(43);
   leg->SetTextSize(30);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   entry=leg->AddEntry("fitfunc","Fit","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   entry=leg->AddEntry("histTOFfit000002","Data","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   leg->Draw();
   pt02->Modified();
   pt02->SetSelected(pt02);
}
