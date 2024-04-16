//-----------------------------------------------------------------------------
// distributions of the muon decay Z : 
// BMUP*B0S24 and s25 datasets
// this is bmup0b0
//-----------------------------------------------------------------------------
#include "Stntuple/val/stn_dataset.hh"

plot_data_t* plot_figure_3701(int Figure, int Print) {
    
  const char* bmup0b0s24  = "pipenu.bmup0b0s24r0000";
  const char* bmup0b0s25  = "pipenu.bmup0b0s25r0000";
  const char* bmup5b0s24  = "pipenu.bmup5b0s24r0000";
  const char* bmup5b0s25  = "pipenu.bmup5b0s25r0000";

  const char* ana_module  = "murat_SpmcAna";
  const char* ana_job     = "murat_spmc_ana.0000";

  plot_data_t* pdata  = new plot_data_t(2);
  plot_data_t& p      = *pdata;
//-----------------------------------------------------------------------------
// 100000: the number of generated pi+ --> e+ nu events in each sample
// 2.5e8 : the number of POT generated to get the pion stops
// 1.23e-4 : BR(pi --> e nu)
//------------------------------------------------------------------------------
  stn_dataset_t* ds024 = catalog->FindBook("pipenu")->FindDataset("pipenu.bmup0b0s24r0000");
  TH2F* h2_024         = gh2(ds024->FindHistFile("",ana_job)->GetName(),ana_module,"simp_204/xe_vs_ze");
  TH1D* hpx_024           = h2_024->ProjectionX("hpx_024");

  stn_dataset_t* ds025 = catalog->FindBook("pipenu")->FindDataset("pipenu.bmup0b0s25r0000");
  TH2F* h2_025         = gh2(ds025->FindHistFile("",ana_job)->GetName(),ana_module,"simp_204/xe_vs_ze");
  TH1D* hpx_025        = h2_025->ProjectionX("hpx_025");

  TH1D* h1             = (TH1D*) hpx_024->Clone("h1");
  h1->Reset();
//-----------------------------------------------------------------------------
// here comes the rescaling 
//-----------------------------------------------------------------------------
  h1->Divide(hpx_024,hpx_025,10./1.6);
  
  for (int i=1; i<=h1->GetNbinsX(); i++) {
    double n1 = hpx_024->GetBinContent(i);
    double n2 = hpx_025->GetBinContent(i);
    double err = (n1*10./1.6)/(n2+1.e-12)*sqrt(1/(n1+1.e-12) +1./(n2+1.e-12));
    h1->SetBinError(i,err);
  }

  p.hd[0]              = hist_data_t(h1,ana_job,ana_module);
  p.hd[0].fRebin       = 1;
  p.hd[0].fLabel       = "no degrader";
  p.hd[0].fLineColor   = kBlue+2;
  p.hd[0].fMarkerColor = kBlue+2;
  p.hd[0].fMarkerStyle = 21;
  p.hd[0].fMarkerSize  = 1.0;
  // p.hd[1].fLumiSF      = (84785./100000.)*BR_pienu/NPOT_pienu;
    
  stn_dataset_t* ds524 = catalog->FindBook("pipenu")->FindDataset("pipenu.bmup5b0s24r0000");
  TH2F* h2_524         = gh2(ds524->FindHistFile("",ana_job)->GetName(),ana_module,"simp_204/xe_vs_ze");
  TH1D* hpx_524        = h2_524->ProjectionX("hpx_524");

  stn_dataset_t* ds525 = catalog->FindBook("pipenu")->FindDataset("pipenu.bmup5b0s25r0000");
  TH2F* h2_525         = gh2(ds525->FindHistFile("",ana_job)->GetName(),ana_module,"simp_204/xe_vs_ze");
  TH1D* hpx_525        = h2_525->ProjectionX("hpx_525");

  TH1D* h2             = (TH1D*) hpx_524->Clone("h2");
  h2->Divide(hpx_524,hpx_525,10./1.6);

  for (int i=1; i<=h2->GetNbinsX(); i++) {
    double n1 = hpx_524->GetBinContent(i);
    double n2 = hpx_525->GetBinContent(i);
    double err = (n1*10./1.6)/(n2+1.e-12)*sqrt(1/(n1+1.e-12) +1./(n2+1.e-12));
    h2->SetBinError(i,err);
  }

  p.hd[1]              = hist_data_t(h2,ana_job,ana_module);
  p.hd[1].fRebin       = 1;
  p.hd[1].fLabel       = "5 mm Ti degrader";
  p.hd[1].fLineColor   = kGreen+3;
  p.hd[1].fMarkerColor = kGreen+3;
  p.hd[1].fMarkerStyle = 22;
  p.hd[1].fMarkerSize  = 1.2;
  //  p.hd[2].fLumiSF      = (50340./100000.)*BR_pienu/NPOT_pienu;
     
  p.fXMin              = 4000.;
  p.fXMax              = 12000.;
  p.fYMin              = 0;
  p.fYMax              = 30;
  p.fXAxisTitle        = "Z, mm";
  p.fCanvasName        = Form("Figure_%04i",Figure);
  p.fName              = Form("figure_%05i",Figure);
  p.fLabel             = "#mu^{+} decay vertex Z; scale factor";
  p.fYLogScale         = 0;

  p.fStatBoxYMax       = 0.90;
  p.fStatBoxYMin       = 0.75;

  p.fLegendXMin        = 0.45; p.fLegendXMax  = 0.65; p.fLegendYMin  = 0.75; p.fLegendYMax  = 0.85; 
    

  plot_hist_1d(&p,-1);

  p.fCanvas->Modified();
  p.fCanvas->Update();

  // TArrow* arr = new TArrow(200,100,200,20,0.015);
  // arr->Draw();

  printf(" plot.C p.fOutputFn = %s\n",p.fOutputFn.Data());
    
  if (Print == 1) p.print() ;

  return pdata;
}
