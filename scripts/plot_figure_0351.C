//-----------------------------------------------------------------------------
// PTRK
// BPIP3B0 YIELDS: ST vs degrader
//-----------------------------------------------------------------------------
plot_data_t* plot_figure_0351(int Figure, int Print) {
    
  const char* bpip3b0s51  = "pipenu.bpip3b0s51r0100";
  const char* bpip3b0s54  = "pipenu.bpip3b0s54r0100";

  const char* ana_job = "murat_pipenu_ana.0000";

  plot_data_t* pdata = new plot_data_t(2);
  plot_data_t& p     = *pdata;
//-----------------------------------------------------------------------------
// 100000: the number of generated pi+ --> e+ nu events in each sample
// 2.5e8 : the number of POT generated to get the pion stops
// 1.23e-4 : BR(pi --> e nu)
//------------------------------------------------------------------------------
  p.hd[0]              = hist_data_t(catalog,"pipenu",bpip3b0s51,ana_job,"PipenuAna","trk_150/p_2");

  p.hd[0].fRebin       = 2;
  p.hd[0].fXAxisTitle  = "T0, ns";
  p.hd[0].fLabel       = "pion stops in the ST";
  p.hd[0].fMarkerColor = kRed+1;
  p.hd[0].fMarkerStyle = 20;
  p.hd[0].fLumiSF      = (50340./100000)*BR_pienu/NPOT_pienu;

  p.hd[1]              = hist_data_t(catalog,"pipenu",bpip3b0s54,ana_job,"PipenuAna","trk_150/p_2");
  p.hd[1].fRebin       = 2;
  p.hd[1].fXAxisTitle  = "T0, ns";
  p.hd[1].fLabel       = "pion stops in the degrader";
  p.hd[1].fMarkerColor = kBlue;
  p.hd[1].fMarkerStyle = 21;
  p.hd[1].fMarkerSize  = 0.8;
  p.hd[1].fLumiSF      = (532767./100000.)*BR_pienu/NPOT_pienu;
    
  p.fXMin              = 55.;
  p.fXMax              = 80.;
  p.fYMin              = 1e-16;
  p.fYMax              = 12e-12;
  p.fCanvasName        = Form("Figure_%04i",Figure);
  p.fName              = Form("figure_%05i",Figure);
  p.fLabel             = "Degrader: 3 mm Ti";
  p.fYLogScale   = 0;

  p.fStatBoxYMax = 0.90;
  p.fStatBoxYMin = 0.75;

  p.fLegendXMin  = 0.35; p.fLegendXMax  = 0.65; p.fLegendYMin  = 0.75; p.fLegendYMax  = 0.85; 
    

  plot_hist_1d(&p,-1);

  p.fCanvas->Modified();
  p.fCanvas->Update();

  // TArrow* arr = new TArrow(200,100,200,20,0.015);
  // arr->Draw();

  printf(" plot.C p.fOutputFn = %s\n",p.fOutputFn.Data());
    
  if (Print == 1) p.print() ;

  return pdata;
}
