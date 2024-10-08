void fit();
void histoHe3();
void plotRatio(TPad* pad, TH1D* h[2], Bool_t log = kFALSE, double dist = 2.5);
Double_t IntegralError(TF1* fit, Double_t lo, Double_t hi, Double_t* params, const TMatrixDSym& covMatrix);
TLegend* legendParticle(TH1D* h[3], int partMode=0);
void setYaxis(TAxis *axis,double dist);