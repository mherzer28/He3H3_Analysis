#ifdef __CLING__
#pragma cling optimize(0)
#endif
void He3Plot0100()
{
//=========Macro generated from canvas: pt10/pt10
//=========  (Fri Aug 23 16:17:38 2024) by ROOT version 6.30/01
   TCanvas *pt10 = new TCanvas("pt10", "pt10",0,53,1400,847);
   gStyle->SetOptFit(1);
   pt10->SetHighLightColor(2);
   pt10->Range(1.04,-2.90597,3.44,18.87596);
   pt10->SetFillColor(0);
   pt10->SetBorderMode(0);
   pt10->SetBorderSize(2);
   pt10->SetLeftMargin(0.15);
   pt10->SetTopMargin(0.0661157);
   pt10->SetBottomMargin(0.133412);
   pt10->SetFrameBorderMode(0);
   pt10->SetFrameBorderMode(0);
   
   TH1D *histTOFfit000100__4 = new TH1D("histTOFfit000100__4","",25,1.4,3.2);
   histTOFfit000100__4->SetBinContent(7,2);
   histTOFfit000100__4->SetBinContent(8,1);
   histTOFfit000100__4->SetBinContent(9,13);
   histTOFfit000100__4->SetBinContent(10,13);
   histTOFfit000100__4->SetBinContent(11,11);
   histTOFfit000100__4->SetBinContent(12,7);
   histTOFfit000100__4->SetBinContent(13,5);
   histTOFfit000100__4->SetBinContent(14,3);
   histTOFfit000100__4->SetBinContent(15,4);
   histTOFfit000100__4->SetBinContent(19,1);
   histTOFfit000100__4->SetBinContent(24,1);
   histTOFfit000100__4->SetBinError(7,1.414214);
   histTOFfit000100__4->SetBinError(8,1);
   histTOFfit000100__4->SetBinError(9,3.605551);
   histTOFfit000100__4->SetBinError(10,3.605551);
   histTOFfit000100__4->SetBinError(11,3.316625);
   histTOFfit000100__4->SetBinError(12,2.645751);
   histTOFfit000100__4->SetBinError(13,2.236068);
   histTOFfit000100__4->SetBinError(14,1.732051);
   histTOFfit000100__4->SetBinError(15,2);
   histTOFfit000100__4->SetBinError(19,1);
   histTOFfit000100__4->SetBinError(24,1);
   histTOFfit000100__4->SetEntries(61);
   histTOFfit000100__4->SetDirectory(nullptr);
   histTOFfit000100__4->SetStats(0);
   
   TF1 *fitfunc4 = new TF1("fitfunc","gaus(0)",1.5,2.5, TF1::EAddToList::kNo);
   fitfunc4->SetFillColor(19);
   fitfunc4->SetFillStyle(0);
   fitfunc4->SetLineColor(2);
   fitfunc4->SetLineWidth(5);
   fitfunc4->SetChisquare(11.82869);
   fitfunc4->SetNDF(8);
   fitfunc4->GetXaxis()->SetLabelFont(42);
   fitfunc4->GetXaxis()->SetTitleOffset(1);
   fitfunc4->GetXaxis()->SetTitleFont(42);
   fitfunc4->GetYaxis()->SetLabelFont(42);
   fitfunc4->GetYaxis()->SetTitleFont(42);
   fitfunc4->SetParameter(0,12.55464);
   fitfunc4->SetParError(0,0);
   fitfunc4->SetParLimits(0,13,13);
   fitfunc4->SetParameter(1,2.146237);
   fitfunc4->SetParError(1,0);
   fitfunc4->SetParLimits(1,2.11,2.11);
   fitfunc4->SetParameter(2,0.113356);
   fitfunc4->SetParError(2,0.01122739);
   fitfunc4->SetParLimits(2,0,1.399511);
   fitfunc4->SetParent(histTOFfit000100__4);
   histTOFfit000100__4->GetListOfFunctions()->Add(fitfunc4);
   histTOFfit000100__4->SetLineWidth(5);
   histTOFfit000100__4->SetMarkerStyle(20);
   histTOFfit000100__4->SetMarkerSize(2);
   histTOFfit000100__4->GetXaxis()->SetTitle("m^{2}/z^{2} (GeV^{2}/c^{4})");
   histTOFfit000100__4->GetXaxis()->SetRange(1,25);
   histTOFfit000100__4->GetXaxis()->SetLabelFont(42);
   histTOFfit000100__4->GetXaxis()->SetLabelSize(0.05);
   histTOFfit000100__4->GetXaxis()->SetTitleSize(0.05);
   histTOFfit000100__4->GetXaxis()->SetTitleOffset(1);
   histTOFfit000100__4->GetXaxis()->SetTitleFont(42);
   histTOFfit000100__4->GetYaxis()->SetTitle("Counts / (72 MeV^{2}/c^{4})");
   histTOFfit000100__4->GetYaxis()->SetLabelFont(42);
   histTOFfit000100__4->GetYaxis()->SetLabelSize(0.05);
   histTOFfit000100__4->GetYaxis()->SetTitleSize(0.05);
   histTOFfit000100__4->GetYaxis()->SetTitleFont(42);
   histTOFfit000100__4->GetZaxis()->SetLabelFont(42);
   histTOFfit000100__4->GetZaxis()->SetTitleOffset(1);
   histTOFfit000100__4->GetZaxis()->SetTitleFont(42);
   histTOFfit000100__4->Draw("");
   
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
   entry=leg->AddEntry("NULL","Particle: {}^{3}#barHe","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","1.30 < #frac{#it{p}_{T}}{(GeV/#it{c})} < 1.80 ","");
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
   entry=leg->AddEntry("histTOFfit000100","Data","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   leg->Draw();
   pt10->Modified();
   pt10->SetSelected(pt10);
}
