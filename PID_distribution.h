Int_t					tTrigMB;			// trigger info
Int_t					tTrigHMV0;
Int_t					tTrigHMSPD;
Int_t					tTrigHNU;
Int_t					tTrigHQU;
Int_t					tTRDvalid;		// has valid TRD track
Int_t					tTRDtrigHNU;	// HNU fired by track
Int_t					tTRDtrigHQU;	// HQU fired by track
Int_t					tTRDPid;
Int_t					tTRDnTracklets;
Int_t					tTRDPt;
Int_t					tTRDLayerMask;
Double_t				tTRDSagitta;	
Double_t				tnTPCcluster;
Double_t				tTPCchi2;
Double_t 				tCharge;
Double_t 				tChargeTri;		
Int_t		 		    tKink;
Int_t				    tTPCrefit;
Double_t				tPt;				// He3 track parameter
Double_t				tY;
Double_t				tEta;
Double_t				tPhi;
Double_t				tP;					// PID parameter 
Double_t				tHeDEdx;
Double_t				tTriDedx;
Double_t				tHeSigma;
Double_t				tTriSigma;
Double_t				tTOFSignalHe;
Double_t				tTOFSignalTri;
Double_t				tDcaXY;				// impact parameters
Double_t				tDcaZ;
Double_t				tSigmaYX;
Double_t				tSigmaXYZ;
Double_t				tSigmaZ;

Int_t 					tRunNumber;
Int_t					tMCtrue;			// MC info
Int_t					tPrimary;
Int_t					tWeak;
Int_t					tMaterial;
Int_t					tHypertriton;

Double_t				tSPDFiredChips0;	// multiplicity triggers
Double_t				tSPDFiredChips1;
Double_t 				tSPDTracklets;
Double_t 				tSPDCluster;
Double_t				tV0Multiplicity;
Double_t				tNTracks;

Double_t 				tMultV0M;			// multiplicity estimators
Double_t 				tMultOfV0M;			
Double_t 				tMultSPDTracklet;	
Double_t 				tMultSPDCluster;	
Double_t 				tMultRef05;			
Double_t 				tMultRef08;	

ULong64_t               tEventId;
Double_t                tE;
Double_t                tPx;
Double_t                tPy;
Double_t                tPz;
Double_t                tMagField;
Int_t                   tTRDStack;
Int_t                   tTRDSector;
UInt_t                   tTRDPID0;
UInt_t                   tTRDPID1;
UInt_t                   tTRDPID2;
UInt_t                   tTRDPID3;
UInt_t                   tTRDPID4;
UInt_t                   tTRDPID5;
Double_t                tnITScluster;
Int_t                   tITSrefit;
Int_t                   tPdg;

Double_t        tGenCharge;
Double_t        tGenPt;        // He3 track parameter
Double_t        tGenY;
Int_t           tGenPrimary;
Int_t          pdgCode;

void setTreeBranchHe3(TTree *fTree);
void PID_MC();
void plot();
