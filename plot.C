{
	gROOT->Reset();
	gROOT->SetStyle("Plain");

	// Draw histo filled by G4 simulation
	//

	TFile f("Co60.root");

	TCanvas* c1 = new TCanvas("c1","", 600, 600);

	TNtuple* ntuple = (TNtuple*)f.Get("Edep");
	gPad->SetLogx();
	ntuple->Draw("Edep");
}