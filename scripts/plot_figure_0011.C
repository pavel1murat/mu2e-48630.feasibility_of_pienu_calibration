//-----------------------------------------------------------------------------
// Degrader: BPIP*B0S54 datasets - momentum distributions , normalized
//-----------------------------------------------------------------------------
plot_data_t* plot_figure_0011(int Figure, int Print) {
    
  const char* bpip0b0s54  = "pipenu.bpip0b0s54r0100";
  const char* bpip2b0s54  = "pipenu.bpip2b0s54r0100";
  const char* bpip3b0s54  = "pipenu.bpip3b0s54r0100";
  const char* bpip4b0s54  = "pipenu.bpip4b0s54r0100";
  const char* bpip5b0s54  = "pipenu.bpip5b0s54r0100";

  const char* ana_job = "murat_pipenu_ana.0000";

  plot_data_t* pdata = new plot_data_t(4);
  plot_data_t& p     = *pdata;
//-----------------------------------------------------------------------------
// 100000: the number of generated pi+ --> e+ nu events in each sample
// 2.5e8 : the number of POT generated to get the pion stops
// 1.23e-4 : BR(pi --> e nu)
//------------------------------------------------------------------------------
  p.hd[0]              = hist_data_t(catalog,"pipenu",bpip2b0s54,ana_job,"PipenuAna","trk_151/p_2");
  p.hd[0].fRebin       = 5;
  p.hd[0].fXAxisTitle  = "track momentum, MeV/c";
  p.hd[0].fLabel       = "2 mm Ti";
  p.hd[0].fLineColor   = kRed+1;
  p.hd[0].fMarkerColor = kRed+1;
  p.hd[0].fMarkerStyle = 20;
  p.hd[0].fLumiSF      = (448131./100000)*BR_pienu/NPOT_pienu;

  p.hd[1]              = hist_data_t(catalog,"pipenu",bpip3b0s54,ana_job,"PipenuAna","trk_151/p_2");
  p.hd[1].fRebin       = 5;
  p.hd[1].fLabel       = "3 mm Ti";
  p.hd[2].fLineColor   = kBlue;
  p.hd[1].fMarkerColor = kBlue;
  p.hd[1].fMarkerStyle = 21;
  p.hd[1].fMarkerSize  = 0.8;
  p.hd[1].fLumiSF      = (532767./100000.)*BR_pienu/NPOT_pienu;
    
  p.hd[2]              = hist_data_t(catalog,"pipenu",bpip4b0s54,ana_job,"PipenuAna","trk_151/p_2");
  p.hd[2].fRebin       = 5;
  p.hd[2].fLabel       = "4 mm Ti";
  p.hd[2].fLineColor   = kGreen+3;
  p.hd[2].fMarkerColor = kGreen+3;
  p.hd[2].fMarkerStyle = 22;
  p.hd[2].fMarkerSize  = 0.8;
  p.hd[2].fLumiSF      = (583855./100000.)*BR_pienu/NPOT_pienu;
    
  p.hd[3]              = hist_data_t(catalog,"pipenu",bpip5b0s54,ana_job,"PipenuAna","trk_151/p_2");
  p.hd[3].fRebin       = 5;
  p.hd[3].fLabel       = "5 mm Ti";
  p.hd[3].fMarkerColor = kBlack;
  p.hd[3].fMarkerStyle = 24;
  p.hd[3].fMarkerSize  = 0.8;
  p.hd[3].fLumiSF      = (617324./100000.)*BR_pienu/NPOT_pienu;
    
  p.fXMin              = 55.;
  p.fXMax              = 80.;
  p.fYMin              = 1e-16;
  p.fYMax              = 5e-12;
  p.fCanvasName  = Form("Figure_%04i",Figure);
  p.fName        = Form("figure_%05i",Figure);
  p.fLabel       = "";
  //  p.fYLogScale   = 1;

  p.fStatBoxYMax = 0.90;
  p.fStatBoxYMin = 0.75;

  p.fLegendXMin  = 0.35; p.fLegendXMax  = 0.55; p.fLegendYMin  = 0.7; p.fLegendYMax  = 0.85; 
    

  plot_hist_1d(&p,-1);

  p.fCanvas->Modified();
  p.fCanvas->Update();

  // TArrow* arr = new TArrow(200,100,200,20,0.015);
  // arr->Draw();

  printf(" plot.C p.fOutputFn = %s\n",p.fOutputFn.Data());
    
  if (Print == 1) p.print() ;

  return pdata;
}
