#ifdef __CLING__
#pragma cling optimize(0)
#endif

#include "TFile.h"
#include "Stntuple/val/stntuple_val_functions.hh"
#include "Stntuple/val/hist_file.hh"
#include "Stntuple/val/hist_data.hh"
#include "Stntuple/val/stn_book.hh"
#include "Stntuple/val/stn_catalog.hh"

#include "pipenu/ana/Analysis.hh"

pipenu::Analysis* gPipenu; 

void figure_0405()
{
 gPipenu = new pipenu::Analysis("a");
 TCanvas *c1 = new TCanvas("c1"," ",900,750);

 TH1F * hist1 = gh1("/exp/mu2e/data/projects/pipenu/hist/tripathy/pipenu.bpipab0s51r0100.tripathy_pipenu_pipenu_ana.hist","PipenuAna","trk_158/p_2"); //158
 hist1->Rebin(5);

 hist1->Scale(gPipenu->GetChannel("bpipab0s51r0100")->NormSF());
 hist1->SetLineColor(kRed);
 hist1->SetLineStyle(1);
 hist1->SetLineWidth(2);
 hist1->SetMarkerStyle(20);
 hist1->SetMarkerSize(1.2);
 hist1->SetName("3.5 mm Ti");
 hist1->SetMarkerColorAlpha(kRed, 0.75);

 TH1F * hist2 = gh1("/exp/mu2e/data/projects/pipenu/hist/tripathy/pipenu.bpip9b0s51r0100.tripathy_pipenu_pipenu_ana.hist","PipenuAna","trk_158/p_2");
 hist2->Rebin(5);
 // hist1->GetXaxis()->SetTitle("p (MeV/c)");
 hist2->Scale( gPipenu->GetChannel("bpip9b0s51r0100")->NormSF());
 hist2->SetLineColor(kBlue);
 hist2->SetLineStyle(1);
 hist2->SetLineWidth(2);
 hist2->SetMarkerStyle(20);
 hist2->SetMarkerSize(1.2);
 hist2->SetName("3.5 mm Be");
 hist2->SetMarkerColorAlpha(kBlue, 0.75);

 //common-------------
 hist1->GetXaxis()->SetTitle("p (MeV/c)");
 hist1->GetYaxis()->SetTitle("N/ 2.5e8 POT/ 0.5 MeV/c");
 hist1->GetYaxis()->SetTitleOffset(1.25);
 hist1->GetXaxis()->SetRangeUser(40.,90.);
 hist1->GetYaxis()->SetRangeUser(10e-16,10e-12);
 hist1->SetTitle("trk_158/p_2, 3.5 mm Ti/Be deg, target stop, 67.5-70 MeV/c");

 hist1->Draw();
 hist2->Draw("sames");

 TLegend *legend = new TLegend(0.55,0.65,0.76,0.82);
 legend->AddEntry(hist1,"3.5 mm Ti in signal window: 4.342e-13","lep"); // calculated from trk_159
 legend->AddEntry(hist2,"3.5 mm Be in signal window: 1.075e-12","lep");
 legend->Draw();
 c1->SetLogy();
 c1->Modified();
 c1->Update();
 //gPad->BuildLegend();

}
