//-----------------------------------------------------------------------------
// distributions of the pion stop time (simp_216/etime)
// BPIP*B0S51 datasets - momentum distributions , normalized
//-----------------------------------------------------------------------------
plot_data_t* plot_figure_2002(int Figure, int Print) {
    
  const char* bpip0b0s21  = "pipenu.bpip0b0s21r0000";
  const char* bpip2b0s21  = "pipenu.bpip2b0s21r0000";
  const char* bpip3b0s21  = "pipenu.bpip3b0s21r0000";
  const char* bpip4b0s21  = "pipenu.bpip4b0s21r0000";
  const char* bpip5b0s21  = "pipenu.bpip5b0s21r0000";

  const char* ana_module  = "murat_SpmcAna";
  const char* ana_job     = "murat_spmc_ana.0000";

  plot_data_t* pdata  = new plot_data_t(5);
  plot_data_t& p      = *pdata;
//-----------------------------------------------------------------------------
// 100000: the number of generated pi+ --> e+ nu events in each sample
// 2.5e8 : the number of POT generated to get the pion stops
// 1.23e-4 : BR(pi --> e nu)
//------------------------------------------------------------------------------
  p.hd[0]              = hist_data_t(catalog,"pipenu",bpip0b0s21,ana_job,ana_module,"simp_216/etime");
  p.hd[0].fRebin       = 1;
  p.hd[0].fLabel       = "no degrader";
  p.hd[0].fMarkerColor = kRed+1;
  p.hd[0].fMarkerStyle = 20;
  // p.hd[0].fLumiSF      = (312616./100000)*BR_pienu/NPOT_pienu;

  p.hd[1]              = hist_data_t(catalog,"pipenu",bpip2b0s21,ana_job,ana_module,"simp_216/etime");
  p.hd[1].fRebin       = 1;
  p.hd[1].fLabel       = "2 mm Ti";
  p.hd[1].fLineColor   = kBlue+2;
  p.hd[1].fMarkerColor = kBlue+2;
  p.hd[1].fMarkerStyle = 21;
  p.hd[1].fMarkerSize  = 1.0;
  // p.hd[1].fLumiSF      = (84785./100000.)*BR_pienu/NPOT_pienu;
    
  p.hd[2]              = hist_data_t(catalog,"pipenu",bpip3b0s21,ana_job,ana_module,"simp_216/etime");
  p.hd[2].fRebin       = 1;
  p.hd[2].fLabel       = "3 mm Ti";
  p.hd[2].fLineColor   = kGreen+3;
  p.hd[2].fMarkerColor = kGreen+3;
  p.hd[2].fMarkerStyle = 22;
  p.hd[2].fMarkerSize  = 1.2;
  //  p.hd[2].fLumiSF      = (50340./100000.)*BR_pienu/NPOT_pienu;
    
  p.hd[3]              = hist_data_t(catalog,"pipenu",bpip4b0s21,ana_job,ana_module,"simp_216/etime");
  p.hd[3].fRebin       = 1;
  p.hd[3].fLabel       = "4 mm Ti";
  p.hd[3].fMarkerColor = kBlack;
  p.hd[3].fMarkerStyle = 26;
  p.hd[3].fMarkerSize  = 1.2;
  // p.hd[3].fLumiSF      = (31681./100000.)*BR_pienu/NPOT_pienu;
    
  p.hd[4]              = hist_data_t(catalog,"pipenu",bpip5b0s21,ana_job,ana_module,"simp_216/etime");
  p.hd[4].fRebin       = 1;
  p.hd[4].fLabel       = "5 mm Ti";
  p.hd[4].fLineColor   = kRed+2;
  p.hd[4].fMarkerColor = kRed+2;
  p.hd[4].fMarkerStyle = 24;
  p.hd[4].fMarkerSize  = 1.0;
  //p.hd[4].fLumiSF      = (17225./100000.)*BR_pienu/NPOT_pienu;
    
  p.fXMin              = 0.;
  p.fXMax              = 800.;
  p.fYMin              = 1e-7;
  p.fYMax              = 1e4;
  p.fXAxisTitle        = "time, ns";
  p.fCanvasName        = Form("Figure_%04i",Figure);
  p.fName              = Form("figure_%05i",Figure);
  p.fLabel             = "#pi^{+} stop time, ns";
  p.fYLogScale         = 1;

  p.fStatBoxYMax       = 0.90;
  p.fStatBoxYMin       = 0.75;

  p.fLegendXMin        = 0.45; p.fLegendXMax  = 0.65; p.fLegendYMin  = 0.6; p.fLegendYMax  = 0.8; 
    

  plot_hist_1d(&p,-1);

  p.fCanvas->Modified();
  p.fCanvas->Update();

  // TArrow* arr = new TArrow(200,100,200,20,0.015);
  // arr->Draw();

  printf(" plot.C p.fOutputFn = %s\n",p.fOutputFn.Data());
    
  if (Print == 1) p.print() ;

  return pdata;
}
