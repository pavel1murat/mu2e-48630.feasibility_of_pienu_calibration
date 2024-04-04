//-----------------------------------------------------------------------------
// BPIP*B0S51 datasets - momentum distributions , normalized
//-----------------------------------------------------------------------------
plot_data_t* plot_figure_0001(int Figure, int Print) {
    
  const char* bpip0b0  = "pipenu.bpip0b0s51r0100";
  const char* bpip2b0  = "pipenu.bpip2b0s51r0100";
  const char* bpip3b0  = "pipenu.bpip3b0s51r0100";
  const char* bpip4b0  = "pipenu.bpip4b0s51r0100";
  const char* bpip5b0  = "pipenu.bpip5b0s51r0100";

  const char* ana_job = "murat_pipenu_ana.0000";

  plot_data_t* pdata = new plot_data_t(5);
  plot_data_t& p     = *pdata;
//-----------------------------------------------------------------------------
// 100000: the number of generated pi+ --> e+ nu events in each sample
// 2.5e8 : the number of POT generated to get the pion stops
// 1.23e-4 : BR(pi --> e nu)
//------------------------------------------------------------------------------
  p.hd[0]              = hist_data_t(catalog,"pipenu",bpip0b0,ana_job,"PipenuAna","trk_150/t0");
  // p.hd[0]              = bpip0b0->GetHistData(catalog,"pipenu",bpip0b0,ana_job,"PipenuAna","trk_150/t0");
  p.hd[0].fRebin       = 1;
  p.hd[0].fXAxisTitle  = "T0, ns";
  p.hd[0].fXMin        = -10.;
  p.hd[0].fXMax        = 10.;
  p.hd[0].fLabel       = "no degrader";
  p.hd[0].fYLogScale   = 0;
  p.hd[0].fMarkerColor = kRed+1;
  p.hd[0].fMarkerStyle = 20;
  p.hd[0].fLumiSF      = (312616./100000)*BR_pienu/NPOT_pienu;

  p.hd[1]              = hist_data_t(catalog,"pipenu",bpip2b0,ana_job,"PipenuAna","trk_150/t0");
  p.hd[1].fRebin       = 1;
  p.hd[1].fXAxisTitle  = "T0, ns";
  p.hd[1].fXMin        = -10.;
  p.hd[1].fXMax        = 10.;
  p.hd[1].fLabel       = "2 mm Ti";
  p.hd[1].fYLogScale   = 0;
  p.hd[1].fMarkerColor = kBlue;
  p.hd[1].fMarkerStyle = 21;
  p.hd[1].fMarkerSize  = 0.8;
  p.hd[1].fLumiSF      = (84785./100000.)*BR_pienu/NPOT_pienu;
    
  p.hd[2]              = hist_data_t(catalog,"pipenu",bpip3b0,ana_job,"PipenuAna","trk_150/t0");
  p.hd[2].fRebin       = 1;
  p.hd[2].fXAxisTitle  = "T0, ns";
  p.hd[2].fXMin        = -10.;
  p.hd[2].fXMax        = 10.;
  p.hd[2].fLabel       = "3 mm Ti";
  p.hd[2].fYLogScale   = 0;
  p.hd[2].fMarkerColor = kGreen;
  p.hd[2].fMarkerStyle = 22;
  p.hd[2].fMarkerSize  = 0.8;
  p.hd[2].fLumiSF      = (50340./100000.)*BR_pienu/NPOT_pienu;
    
  p.hd[3]              = hist_data_t(catalog,"pipenu",bpip4b0,ana_job,"PipenuAna","trk_150/t0");
  p.hd[3].fRebin       = 1;
  p.hd[3].fXAxisTitle  = "T0, ns";
  p.hd[3].fXMin        = -10.;
  p.hd[3].fXMax        = 10.;
  p.hd[3].fLabel       = "4 mm Ti";
  p.hd[3].fYLogScale   = 0;
  p.hd[3].fMarkerColor = kBlack;
  p.hd[3].fMarkerStyle = 23;
  p.hd[3].fMarkerSize  = 0.8;
  p.hd[3].fLumiSF      = (31681./100000.)*BR_pienu/NPOT_pienu;
    
  p.hd[4]              = hist_data_t(catalog,"pipenu",bpip5b0,ana_job,"PipenuAna","trk_150/t0");
  p.hd[4].fRebin       = 1;
  p.hd[4].fXAxisTitle  = "T0, ns";
  p.hd[4].fXMin        = -10.;
  p.hd[4].fXMax        = 10.;
  p.hd[4].fLabel       = "5 mm Ti";
  p.hd[4].fYLogScale   = 0;
  p.hd[4].fMarkerColor = kBlack;
  p.hd[4].fMarkerStyle = 24;
  p.hd[4].fMarkerSize  = 0.8;
  p.hd[4].fLumiSF      = (17225./100000.)*BR_pienu/NPOT_pienu;
    
  p.fXMin              = 0.;
  p.fXMax              = 1000.;
  p.fYMin              = 1e-16;
  p.fYMax              = 3e-11;
  p.fCanvasName  = Form("Figure_%04i",Figure);
  p.fName        = Form("figure_%05i",Figure);
  p.fLabel       = "";
  p.fYLogScale   = 1;

  p.fStatBoxYMax = 0.90;
  p.fStatBoxYMin = 0.75;

  p.fLegendXMin  = 0.45; p.fLegendXMax  = 0.65; p.fLegendYMin  = 0.6; p.fLegendYMax  = 0.8; 
    

  plot_hist_1d(&p,-1);

  p.fCanvas->Modified();
  p.fCanvas->Update();

  // TArrow* arr = new TArrow(200,100,200,20,0.015);
  // arr->Draw();

  printf(" plot.C p.fOutputFn = %s\n",p.fOutputFn.Data());
    
  if (Print == 1) p.print() ;

  return pdata;
}
