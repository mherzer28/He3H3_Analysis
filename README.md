# He3H3_Analysis
Steps:
1. H3_readData + He3_readData for reading Data from rootfiles and fill them in basic histograms
2. H3_tofHisto + He3_tofHisto for the TOF-Signal in p_t bins histograms 
3. get_rawYield for creating a root file that can be used for uncorrected ratio plots and corrections
4. For corrected ratio plots first efficiencyHM/efficiencyHNU + correction/correctionHNU and then H3He3_ratioHisto using the histRatiocorrected function
otherwise for uncorrected just the histRatio function

