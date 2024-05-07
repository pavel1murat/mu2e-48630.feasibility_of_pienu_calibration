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

void figure_0105()
{
 gPipenu = new pipenu::Analysis("a");
 TCanvas *c1 = new TCanvas("c1"," ",900,750);

 TH1F * hist1 = gh1("/exp/mu2e/data/projects/pipenu/hist/tripathy/pipenu.bpip0b0s21r0000_110723_pipenu_spmc_ana_1.hist","pipenu_SpmcAna","simp_706/mom");
 // hist1->Rebin(5);
 // hist1->Scale(gPipenu->GetChannel("bpipab0s51r0100")->NormSF());
 hist1->SetLineColor(kRed);
 hist1->SetLineStyle(1);
 hist1->SetLineWidth(2);
 hist1->SetMarkerStyle(20);
 hist1->SetMarkerSize(1.2);
 hist1->SetName("Pion decays off");
 hist1->SetMarkerColorAlpha(kRed, 0.75);


 TH1F * hist2 = gh1("/exp/mu2e/data/projects/pipenu/hist/tripathy/pipenu.bpip1b0s21r0000_pipenu_spmc_ana.hist","pipenu_SpmcAna","simp_706/mom");
 // hist2->Rebin(5);
 // hist1->GetXaxis()->SetTitle("p (MeV/c)");
 // hist2->Scale( gPipenu->GetChannel("bpip9b0s51r0100")->NormSF());
 hist2->SetLineColor(kBlue);
 hist2->SetLineStyle(1);
 hist2->SetLineWidth(2);
 hist2->SetMarkerStyle(20);
 hist2->SetMarkerSize(1.2);
 hist2->SetName("Pion decays on");
 hist2->SetMarkerColorAlpha(kBlue, 0.75);

 //common--------
 hist2->GetXaxis()->SetTitle("Start momenta (MeV/c)");
 hist2->GetYaxis()->SetTitle("N/ 2.5e8 POT/ 1.0 MeV/c");
 hist2->GetYaxis()->SetTitleOffset(1.15);
 hist2->GetXaxis()->SetRangeUser(0.,90.);
 hist2->SetTitle("simp_706/mom,Momentum dist. of stopped pions in ST");


 hist2->Draw();
 hist1->Draw("sames");

 TLegend *legend = new TLegend(0.55,0.65,0.76,0.82);
 legend->AddEntry(hist1,"Pion decays off","lep");
 legend->AddEntry(hist2,"Pion decays on","lep");
 legend->Draw();
 
 //gPad->BuildLegend();

}
