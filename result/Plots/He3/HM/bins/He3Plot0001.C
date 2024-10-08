#ifdef __CLING__
#pragma cling optimize(0)
#endif
void He3Plot0001()
{
//=========Macro generated from canvas: pt01/pt01
//=========  (Mon Jul 22 14:05:06 2024) by ROOT version 6.30/01
   TCanvas *pt01 = new TCanvas("pt01", "pt01",0,53,1400,847);
   gStyle->SetOptFit(1);
   pt01->SetHighLightColor(2);
   pt01->Range(1.04,-12.6,3.44,81.84425);
   pt01->SetFillColor(0);
   pt01->SetBorderMode(0);
   pt01->SetBorderSize(2);
   pt01->SetLeftMargin(0.15);
   pt01->SetTopMargin(0.0661157);
   pt01->SetBottomMargin(0.133412);
   pt01->SetFrameBorderMode(0);
   pt01->SetFrameBorderMode(0);
   
   TH1D *histTOFfit000001__2 = new TH1D("histTOFfit000001__2","",30,1.4,3.2);
   histTOFfit000001__2->SetBinContent(0,18);
   histTOFfit000001__2->SetBinContent(8,2);
   histTOFfit000001__2->SetBinContent(9,14);
   histTOFfit000001__2->SetBinContent(10,35);
   histTOFfit000001__2->SetBinContent(11,64);
   histTOFfit000001__2->SetBinContent(12,34);
   histTOFfit000001__2->SetBinContent(13,8);
   histTOFfit000001__2->SetBinContent(14,3);
   histTOFfit000001__2->SetBinContent(15,6);
   histTOFfit000001__2->SetBinContent(16,2);
   histTOFfit000001__2->SetBinContent(17,1);
   histTOFfit000001__2->SetBinContent(18,2);
   histTOFfit000001__2->SetBinContent(19,1);
   histTOFfit000001__2->SetBinContent(20,1);
   histTOFfit000001__2->SetBinContent(31,1);
   histTOFfit000001__2->SetBinError(0,4.242641);
   histTOFfit000001__2->SetBinError(8,1.414214);
   histTOFfit000001__2->SetBinError(9,3.741657);
   histTOFfit000001__2->SetBinError(10,5.91608);
   histTOFfit000001__2->SetBinError(11,8);
   histTOFfit000001__2->SetBinError(12,5.830952);
   histTOFfit000001__2->SetBinError(13,2.828427);
   histTOFfit000001__2->SetBinError(14,1.732051);
   histTOFfit000001__2->SetBinError(15,2.44949);
   histTOFfit000001__2->SetBinError(16,1.414214);
   histTOFfit000001__2->SetBinError(17,1);
   histTOFfit000001__2->SetBinError(18,1.414214);
   histTOFfit000001__2->SetBinError(19,1);
   histTOFfit000001__2->SetBinError(20,1);
   histTOFfit000001__2->SetBinError(31,1);
   histTOFfit000001__2->SetEntries(192);
   histTOFfit000001__2->SetDirectory(nullptr);
   histTOFfit000001__2->SetStats(0);
   
   TF1 *fitfunc2 = new TF1("fitfunc","gaus(0)",1.5,2.5, TF1::EAddToList::kNo);
   fitfunc2->SetFillColor(19);
   fitfunc2->SetFillStyle(0);
   fitfunc2->SetLineColor(2);
   fitfunc2->SetLineWidth(5);
   fitfunc2->SetChisquare(14.64722);
   fitfunc2->SetNDF(9);
   fitfunc2->GetXaxis()->SetLabelFont(42);
   fitfunc2->GetXaxis()->SetTitleOffset(1);
   fitfunc2->GetXaxis()->SetTitleFont(42);
   fitfunc2->GetYaxis()->SetLabelFont(42);
   fitfunc2->GetYaxis()->SetTitleFont(42);
   fitfunc2->SetParameter(0,52.55948);
   fitfunc2->SetParError(0,0);
   fitfunc2->SetParLimits(0,65,65);
   fitfunc2->SetParameter(1,2.025004);
   fitfunc2->SetParError(1,0.00550485);
   fitfunc2->SetParLimits(1,0,0);
   fitfunc2->SetParameter(2,0.06846058);
   fitfunc2->SetParError(2,0.00362033);
   fitfunc2->SetParLimits(2,0,0.9954405);
   fitfunc2->SetParent(histTOFfit000001__2);
   histTOFfit000001__2->GetListOfFunctions()->Add(fitfunc2);
   histTOFfit000001__2->SetLineWidth(5);
   histTOFfit000001__2->SetMarkerStyle(20);
   histTOFfit000001__2->SetMarkerSize(2);
   histTOFfit000001__2->GetXaxis()->SetTitle("m^{2}/z^{2} (GeV^{2}/c^{4})");
   histTOFfit000001__2->GetXaxis()->SetRange(1,30);
   histTOFfit000001__2->GetXaxis()->SetLabelFont(42);
   histTOFfit000001__2->GetXaxis()->SetLabelSize(0.05);
   histTOFfit000001__2->GetXaxis()->SetTitleSize(0.05);
   histTOFfit000001__2->GetXaxis()->SetTitleOffset(1);
   histTOFfit000001__2->GetXaxis()->SetTitleFont(42);
   histTOFfit000001__2->GetYaxis()->SetTitle("Counts / (60 MeV^{2}/c^{4})");
   histTOFfit000001__2->GetYaxis()->SetLabelFont(42);
   histTOFfit000001__2->GetYaxis()->SetLabelSize(0.05);
   histTOFfit000001__2->GetYaxis()->SetTitleSize(0.05);
   histTOFfit000001__2->GetYaxis()->SetTitleFont(42);
   histTOFfit000001__2->GetZaxis()->SetLabelFont(42);
   histTOFfit000001__2->GetZaxis()->SetTitleOffset(1);
   histTOFfit000001__2->GetZaxis()->SetTitleFont(42);
   histTOFfit000001__2->Draw("");
   
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
   entry=leg->AddEntry("NULL","1.80 < #frac{#it{p}_{T}}{(GeV/#it{c})} < 2.20 ","");
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
   entry=leg->AddEntry("histTOFfit000001","Data","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   leg->Draw();
   pt01->Modified();
   pt01->SetSelected(pt01);
}
