//-----------------------------------------------------------------------------
// distributions of the muon decay Z with different time constraints
// BMUP9B0S24,35 etc datasets
//-----------------------------------------------------------------------------
#include "Stntuple/val/stn_dataset.hh"

plot_data_t* plot_figure_3501(int Figure, int Print) {
    
  const char* bmup9b0s24  = "pipenu.bmup9b0s24r0000";
  const char* bmup9b0s25  = "pipenu.bmup9b0s25r0000";
  const char* bmup9b0s26  = "pipenu.bmup9b0s26r0000";
  const char* bmup9b0s27  = "pipenu.bmup9b0s27r0000";
  const char* bmup9b0s28  = "pipenu.bmup9b0s28r0000";
  const char* bmup9b0s29  = "pipenu.bmup9b0s29r0000";

  const char* ana_module  = "murat_SpmcAna";
  const char* ana_job     = "murat_spmc_ana.0000";

  plot_data_t* pdata  = new plot_data_t(6);
  plot_data_t& p      = *pdata;
//-----------------------------------------------------------------------------
// 100000: the number of generated pi+ --> e+ nu events in each sample
// 2.5e8 : the number of POT generated to get the pion stops
// 1.23e-4 : BR(pi --> e nu)
//------------------------------------------------------------------------------
  p.hd[0]              = hist_data_t(catalog,"pipenu",bmup9b0s25,ana_job,ana_module,"simp_212/zstart");
  p.hd[0].fRebin       = 1;
  p.hd[0].fLabel       = "forced decay within T_{0} < 50 ns";
  p.hd[0].fLineColor   = kBlue+2;
  p.hd[0].fMarkerColor = kBlue+2;
  p.hd[0].fMarkerStyle = 21;
  p.hd[0].fMarkerSize  = 1.0;
  // p.hd[1].fLumiSF      = (84785./100000.)*BR_pienu/NPOT_pienu;
    
  p.hd[1]              = hist_data_t(catalog,"pipenu",bmup9b0s24,ana_job,ana_module,"simp_212/zstart");
  p.hd[1].fRebin       = 1;
  p.hd[1].fLabel       = "default simulation";
  p.hd[1].fLineColor   = kRed+2;
  p.hd[1].fMarkerColor = kRed+2;
  p.hd[1].fMarkerStyle = 22;
  p.hd[1].fMarkerSize  = 1.2;
  //  p.hd[2].fLumiSF      = (50340./100000.)*BR_pienu/NPOT_pienu;
     
  p.hd[2]              = hist_data_t(catalog,"pipenu",bmup9b0s29,ana_job,ana_module,"simp_212/zstart");
  p.hd[2].fRebin       = 1;
  p.hd[2].fLabel       = "T_{max} = 300 ns";
  p.hd[2].fLineColor   = kGreen+3;
  p.hd[2].fMarkerColor = kGreen+3;
  p.hd[2].fMarkerStyle = 26;
  p.hd[2].fMarkerSize  = 1.2;
  //  p.hd[2].fLumiSF      = (50340./100000.)*BR_pienu/NPOT_pienu;
     
  p.hd[3]              = hist_data_t(catalog,"pipenu",bmup9b0s28,ana_job,ana_module,"simp_212/zstart");
  p.hd[3].fRebin       = 1;
  p.hd[3].fLabel       = "T_{max} = 200 ns";
  p.hd[3].fLineColor   = kBlue+2;
  p.hd[3].fMarkerColor = kBlue+2;
  p.hd[3].fMarkerStyle = 25;
  p.hd[3].fMarkerSize  = 1.0;
  //  p.hd[2].fLumiSF      = (50340./100000.)*BR_pienu/NPOT_pienu;
     
  p.hd[4]              = hist_data_t(catalog,"pipenu",bmup9b0s27,ana_job,ana_module,"simp_212/zstart");
  p.hd[4].fRebin       = 1;
  p.hd[4].fLabel       = "T_{max} = 150 ns";
  p.hd[4].fLineColor   = kRed+2;
  p.hd[4].fMarkerColor = kRed+2;
  p.hd[4].fMarkerStyle = 20;
  p.hd[4].fMarkerSize  = 1.0;
  //  p.hd[2].fLumiSF      = (50340./100000.)*BR_pienu/NPOT_pienu;

  p.hd[5]              = hist_data_t(catalog,"pipenu",bmup9b0s26,ana_job,ana_module,"simp_212/zstart");
  p.hd[5].fRebin       = 1;
  p.hd[5].fLabel       = "T_{max} = 100 ns";
  p.hd[5].fLineColor   = kGreen+3;
  p.hd[5].fMarkerColor = kGreen+3;
  p.hd[5].fMarkerStyle = 23;
  p.hd[5].fMarkerSize  = 1.2;
  //  p.hd[2].fLumiSF      = (50340./100000.)*BR_pienu/NPOT_pienu;
     
    
  p.fXMin              =  2000.;
  p.fXMax              = 20000.;
  p.fYMin              = 10;
  p.fYMax              = 1e3;
  p.fXAxisTitle        = "Z, mm";
  p.fCanvasName        = Form("Figure_%04i",Figure);
  p.fName              = Form("figure_%05i",Figure);
  p.fLabel             = "#mu^{+} decay vertex Z; no degrader";
  p.fYLogScale         = 1;

  p.fStatBoxYMax       = 0.90;
  p.fStatBoxYMin       = 0.77;

  p.fLegendXMin        = 0.35; p.fLegendXMax  = 0.65; p.fLegendYMin  = 0.75; p.fLegendYMax  = 0.85; 
    

  plot_hist_1d(&p,-1);

  p.fCanvas->Modified();
  p.fCanvas->Update();

  // TArrow* arr = new TArrow(200,100,200,20,0.015);
  // arr->Draw();

  printf(" plot.C p.fOutputFn = %s\n",p.fOutputFn.Data());
    
  if (Print == 1) p.print() ;

  return pdata;
}
