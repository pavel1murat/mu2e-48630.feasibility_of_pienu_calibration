//-----------------------------------------------------------------------------
// distributions of the muon decay time
// BMUP*B0S24 and s25 datasets
// this is bmup5b0
//-----------------------------------------------------------------------------
#include "Stntuple/val/stn_dataset.hh"

plot_data_t* plot_figure_3432(int Figure, int Print) {
    
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
  p.hd[0]              = hist_data_t(catalog,"pipenu",bmup5b0s24,ana_job,"murat_SpmcAna","simp_232/stime");
  p.hd[0].fRebin       = 1;
  p.hd[0].fLabel       = "forced decay within T_{0} < 150 ns";
  p.hd[0].fLineColor   = kBlue+2;
  p.hd[0].fMarkerColor = kBlue+2;
  p.hd[0].fMarkerStyle = 21;
  p.hd[0].fMarkerSize  = 1.0;
  // p.hd[1].fLumiSF      = (84785./100000.)*BR_pienu/NPOT_pienu;
    
  p.hd[1]              = hist_data_t(catalog,"pipenu",bmup5b0s25,ana_job,"murat_SpmcAna","simp_232/stime");
  p.hd[1].fRebin       = 1;
  p.hd[1].fLabel       = "default simulation";
  p.hd[1].fLineColor   = kGreen+3;
  p.hd[1].fMarkerColor = kGreen+3;
  p.hd[1].fMarkerStyle = 22;
  p.hd[1].fMarkerSize  = 1.2;
  p.hd[1].fScale       = 2;  // normalize to the integral
  //  p.hd[2].fLumiSF      = (50340./100000.)*BR_pienu/NPOT_pienu;
     
  p.fXMin              = 0.;
  p.fXMax              = 2000.;
  // p.fYMin              = 10;
  // p.fYMax              = 1e7;
  p.fXAxisTitle        = "T, ns";
  p.fCanvasName        = Form("Figure_%04i",Figure);
  p.fName              = Form("figure_%05i",Figure);
  p.fLabel             = "#mu^{+} decay time; 5 mm Ti degrader; p(e^{+} > 60 MeV/c";
  p.fYLogScale         = 1;

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
