#ifdef __CLING__
#pragma cling optimize(0)
#endif
void He3Plot0202()
{
//=========Macro generated from canvas: pt22/pt22
//=========  (Mon Jul 22 14:05:06 2024) by ROOT version 6.30/01
   TCanvas *pt22 = new TCanvas("pt22", "pt22",0,53,1400,847);
   gStyle->SetOptFit(1);
   pt22->SetHighLightColor(2);
   pt22->Range(1.04,-13.89957,3.44,90.28574);
   pt22->SetFillColor(0);
   pt22->SetBorderMode(0);
   pt22->SetBorderSize(2);
   pt22->SetLeftMargin(0.15);
   pt22->SetTopMargin(0.0661157);
   pt22->SetBottomMargin(0.133412);
   pt22->SetFrameBorderMode(0);
   pt22->SetFrameBorderMode(0);
   
   TH1D *histTOFfit000202__9 = new TH1D("histTOFfit000202__9","",30,1.4,3.2);
   histTOFfit000202__9->SetBinContent(0,30);
   histTOFfit000202__9->SetBinContent(2,1);
   histTOFfit000202__9->SetBinContent(5,1);
   histTOFfit000202__9->SetBinContent(6,2);
   histTOFfit000202__9->SetBinContent(7,1);
   histTOFfit000202__9->SetBinContent(8,8);
   histTOFfit000202__9->SetBinContent(9,36);
   histTOFfit000202__9->SetBinContent(10,64);
   histTOFfit000202__9->SetBinContent(11,71);
   histTOFfit000202__9->SetBinContent(12,24);
   histTOFfit000202__9->SetBinContent(13,13);
   histTOFfit000202__9->SetBinContent(14,7);
   histTOFfit000202__9->SetBinContent(15,6);
   histTOFfit000202__9->SetBinContent(16,2);
   histTOFfit000202__9->SetBinContent(17,1);
   histTOFfit000202__9->SetBinContent(18,2);
   histTOFfit000202__9->SetBinContent(19,1);
   histTOFfit000202__9->SetBinContent(20,1);
   histTOFfit000202__9->SetBinContent(22,1);
   histTOFfit000202__9->SetBinContent(31,3);
   histTOFfit000202__9->SetBinError(0,5.477226);
   histTOFfit000202__9->SetBinError(2,1);
   histTOFfit000202__9->SetBinError(5,1);
   histTOFfit000202__9->SetBinError(6,1.414214);
   histTOFfit000202__9->SetBinError(7,1);
   histTOFfit000202__9->SetBinError(8,2.828427);
   histTOFfit000202__9->SetBinError(9,6);
   histTOFfit000202__9->SetBinError(10,8);
   histTOFfit000202__9->SetBinError(11,8.42615);
   histTOFfit000202__9->SetBinError(12,4.898979);
   histTOFfit000202__9->SetBinError(13,3.605551);
   histTOFfit000202__9->SetBinError(14,2.645751);
   histTOFfit000202__9->SetBinError(15,2.44949);
   histTOFfit000202__9->SetBinError(16,1.414214);
   histTOFfit000202__9->SetBinError(17,1);
   histTOFfit000202__9->SetBinError(18,1.414214);
   histTOFfit000202__9->SetBinError(19,1);
   histTOFfit000202__9->SetBinError(20,1);
   histTOFfit000202__9->SetBinError(22,1);
   histTOFfit000202__9->SetBinError(31,1.732051);
   histTOFfit000202__9->SetEntries(275);
   histTOFfit000202__9->SetDirectory(nullptr);
   histTOFfit000202__9->SetStats(0);
   
   TF1 *fitfunc9 = new TF1("fitfunc","gaus(0)",1.5,2.5, TF1::EAddToList::kNo);
   fitfunc9->SetFillColor(19);
   fitfunc9->SetFillStyle(0);
   fitfunc9->SetLineColor(2);
   fitfunc9->SetLineWidth(5);
   fitfunc9->SetChisquare(24.13203);
   fitfunc9->SetNDF(11);
   fitfunc9->GetXaxis()->SetLabelFont(42);
   fitfunc9->GetXaxis()->SetTitleOffset(1);
   fitfunc9->GetXaxis()->SetTitleFont(42);
   fitfunc9->GetYaxis()->SetLabelFont(42);
   fitfunc9->GetYaxis()->SetTitleFont(42);
   fitfunc9->SetParameter(0,68.91176);
   fitfunc9->SetParError(0,6.49571);
   fitfunc9->SetParLimits(0,0,0);
   fitfunc9->SetParameter(1,1.998527);
   fitfunc9->SetParError(1,0.005487882);
   fitfunc9->SetParLimits(1,0,0);
   fitfunc9->SetParameter(2,0.07428675);
   fitfunc9->SetParError(2,0.004818077);
   fitfunc9->SetParLimits(2,0,1.091958);
   fitfunc9->SetParent(histTOFfit000202__9);
   histTOFfit000202__9->GetListOfFunctions()->Add(fitfunc9);
   histTOFfit000202__9->SetLineWidth(5);
   histTOFfit000202__9->SetMarkerStyle(20);
   histTOFfit000202__9->SetMarkerSize(2);
   histTOFfit000202__9->GetXaxis()->SetTitle("m^{2}/z^{2} (GeV^{2}/c^{4})");
   histTOFfit000202__9->GetXaxis()->SetRange(1,30);
   histTOFfit000202__9->GetXaxis()->SetLabelFont(42);
   histTOFfit000202__9->GetXaxis()->SetLabelSize(0.05);
   histTOFfit000202__9->GetXaxis()->SetTitleSize(0.05);
   histTOFfit000202__9->GetXaxis()->SetTitleOffset(1);
   histTOFfit000202__9->GetXaxis()->SetTitleFont(42);
   histTOFfit000202__9->GetYaxis()->SetTitle("Counts / (60 MeV^{2}/c^{4})");
   histTOFfit000202__9->GetYaxis()->SetLabelFont(42);
   histTOFfit000202__9->GetYaxis()->SetLabelSize(0.05);
   histTOFfit000202__9->GetYaxis()->SetTitleSize(0.05);
   histTOFfit000202__9->GetYaxis()->SetTitleFont(42);
   histTOFfit000202__9->GetZaxis()->SetLabelFont(42);
   histTOFfit000202__9->GetZaxis()->SetTitleOffset(1);
   histTOFfit000202__9->GetZaxis()->SetTitleFont(42);
   histTOFfit000202__9->Draw("");
   
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
   entry=leg->AddEntry("NULL","Particle: {}^{3}He + {}^{3}#barHe","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","2.20 < #frac{#it{p}_{T}}{(GeV/#it{c})} < 2.60 ","");
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
   entry=leg->AddEntry("histTOFfit000202","Data","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   leg->Draw();
   pt22->Modified();
   pt22->SetSelected(pt22);
}
