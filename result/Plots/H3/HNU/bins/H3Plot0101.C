#ifdef __CLING__
#pragma cling optimize(0)
#endif
void H3Plot0101()
{
//=========Macro generated from canvas: pt11/pt11
//=========  (Fri Aug 16 09:01:09 2024) by ROOT version 6.30/01
   TCanvas *pt11 = new TCanvas("pt11", "pt11",0,53,1400,847);
   gStyle->SetOptFit(1);
   pt11->SetHighLightColor(2);
   pt11->Range(3.8,-2.490148,11.8,16.17495);
   pt11->SetFillColor(0);
   pt11->SetBorderMode(0);
   pt11->SetBorderSize(2);
   pt11->SetLeftMargin(0.15);
   pt11->SetTopMargin(0.0661157);
   pt11->SetBottomMargin(0.133412);
   pt11->SetFrameBorderMode(0);
   pt11->SetFrameBorderMode(0);
   
   TH1D *histTOFfit0101__5 = new TH1D("histTOFfit0101__5","",15,5,11);
   histTOFfit0101__5->SetBinContent(0,2);
   histTOFfit0101__5->SetBinContent(8,2);
   histTOFfit0101__5->SetBinContent(16,1);
   histTOFfit0101__5->SetBinError(0,1.414214);
   histTOFfit0101__5->SetBinError(8,1.414214);
   histTOFfit0101__5->SetBinError(16,1);
   histTOFfit0101__5->SetEntries(5);
   histTOFfit0101__5->SetDirectory(nullptr);
   histTOFfit0101__5->SetStats(0);
   
   TF1 *fitfunc5 = new TF1("fitfunc","gaus(0)+expo(3)",5,11, TF1::EAddToList::kNo);
   fitfunc5->SetFillColor(19);
   fitfunc5->SetFillStyle(0);
   fitfunc5->SetLineColor(2);
   fitfunc5->SetLineWidth(5);
   fitfunc5->SetChisquare(3.321048e-13);
   fitfunc5->SetNDF(0);
   fitfunc5->GetXaxis()->SetLabelFont(42);
   fitfunc5->GetXaxis()->SetTitleOffset(1);
   fitfunc5->GetXaxis()->SetTitleFont(42);
   fitfunc5->GetYaxis()->SetLabelFont(42);
   fitfunc5->GetYaxis()->SetTitleFont(42);
   fitfunc5->SetParameter(0,15.52993);
   fitfunc5->SetParError(0,171.014);
   fitfunc5->SetParLimits(0,0,0);
   fitfunc5->SetParameter(1,7.477756);
   fitfunc5->SetParError(1,1.159723);
   fitfunc5->SetParLimits(1,0,0);
   fitfunc5->SetParameter(2,0.2372664);
   fitfunc5->SetParError(2,0.521319);
   fitfunc5->SetParLimits(2,0,0);
   fitfunc5->SetParameter(3,-0.2371225);
   fitfunc5->SetParError(3,25.93577);
   fitfunc5->SetParLimits(3,0,0);
   fitfunc5->SetParameter(4,-0.02964031);
   fitfunc5->SetParError(4,3.241972);
   fitfunc5->SetParLimits(4,0,0);
   fitfunc5->SetParent(histTOFfit0101__5);
   histTOFfit0101__5->GetListOfFunctions()->Add(fitfunc5);
   histTOFfit0101__5->SetLineWidth(5);
   histTOFfit0101__5->SetMarkerStyle(20);
   histTOFfit0101__5->SetMarkerSize(2);
   histTOFfit0101__5->GetXaxis()->SetTitle("m^{2}/z^{2} (GeV^{2}/#it{c}^{4})");
   histTOFfit0101__5->GetXaxis()->SetRange(1,15);
   histTOFfit0101__5->GetXaxis()->SetLabelFont(42);
   histTOFfit0101__5->GetXaxis()->SetLabelSize(0.05);
   histTOFfit0101__5->GetXaxis()->SetTitleSize(0.05);
   histTOFfit0101__5->GetXaxis()->SetTitleOffset(1);
   histTOFfit0101__5->GetXaxis()->SetTitleFont(42);
   histTOFfit0101__5->GetYaxis()->SetTitle("Counts / (400 MeV^{2}/#it{c}^{4})");
   histTOFfit0101__5->GetYaxis()->SetLabelFont(42);
   histTOFfit0101__5->GetYaxis()->SetLabelSize(0.05);
   histTOFfit0101__5->GetYaxis()->SetTitleSize(0.05);
   histTOFfit0101__5->GetYaxis()->SetTitleFont(42);
   histTOFfit0101__5->GetZaxis()->SetLabelFont(42);
   histTOFfit0101__5->GetZaxis()->SetTitleOffset(1);
   histTOFfit0101__5->GetZaxis()->SetTitleFont(42);
   histTOFfit0101__5->Draw("");
   
   TLegend *leg = new TLegend(0.532765,0.586242,0.922674,0.905549,NULL,"brNDC");
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
   entry=leg->AddEntry("NULL","Particle: {}^{3}#barH","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","1.80 < #frac{#it{p}_{T}}{(GeV/#it{c})} < 2.30 ","");
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
   entry=leg->AddEntry("histTOFfit0101","Data","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   leg->Draw();
   pt11->Modified();
   pt11->SetSelected(pt11);
}
