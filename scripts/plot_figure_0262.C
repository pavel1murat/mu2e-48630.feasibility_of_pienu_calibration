//-----------------------------------------------------------------------------
// ST vs degrader yields for bpip2b0 - tracks with fIDWord[0] = 0 : trk_151/t0
//-----------------------------------------------------------------------------
plot_data_t* plot_figure_0262(int Figure, int Print) {
    
  const char* bpip2b0s51  = "pipenu.bpip2b0s51r0100";
  const char* bpip2b0s54  = "pipenu.bpip2b0s54r0100";

  const char* book        = "pipenu";
  const char* ana_job     = "murat_pipenu_ana.0000";
  const char* ana_module  = "PipenuAna";
  const char* hist_name   = "trk_151/t0";

  plot_data_t* pdata = new plot_data_t(2);
  plot_data_t& p     = *pdata;
//-----------------------------------------------------------------------------
// 100000: the number of generated pi+ --> e+ nu events in each sample
// 2.5e8 : the number of POT generated to get the pion stops
// 1.23e-4 : BR(pi --> e nu)
//------------------------------------------------------------------------------
  p.hd[0]              = hist_data_t(catalog,book,bpip2b0s51,ana_job,ana_module,hist_name);

  p.hd[0].fRebin       = 2;
  p.hd[0].fLabel       = "pion stops in the ST";
  p.hd[0].fMarkerColor = kRed+1;
  p.hd[0].fMarkerStyle = 20;
  p.hd[0].fLumiSF      = gPipenu->GetChannel("bpip2b0s51r0100")->NormSF();

  p.hd[1]              = hist_data_t(catalog,book,bpip2b0s54,ana_job,ana_module,hist_name);
  p.hd[1].fRebin       = 2;
  p.hd[1].fLabel       = "pion stops in the degrader";
  p.hd[1].fMarkerColor = kBlue;
  p.hd[1].fMarkerStyle = 21;
  p.hd[1].fMarkerSize  = 1.0;
  p.hd[1].fLumiSF      = gPipenu->GetChannel("bpip2b0s54r0100")->NormSF();
    
  p.fXMin              = 0.;
  p.fXMax              = 800.;
  p.fYMin              = 1.e-15;
  p.fYMax              = 1.e-10;
  p.fCanvasName        = Form("Figure_%04i",Figure);
  p.fName              = Form("figure_%05i",Figure);

  p.fXAxisTitle        = "track T0, ns";
  p.fLabel             = "#pi^{+} #rightarrow e{+} #nu , 2 mm Ti degrader, events with tracks passing ID cuts";
  p.fYLogScale         = 1;

  p.fStatBoxYMax       = 0.90;
  p.fStatBoxYMin       = 0.75;

  p.fLegendXMin  = 0.35; p.fLegendXMax  = 0.65; p.fLegendYMin  = 0.75; p.fLegendYMax  = 0.85; 
    
  plot_hist_1d(&p,-1);

  p.fCanvas->Modified();
  p.fCanvas->Update();

  // TArrow* arr = new TArrow(200,100,200,20,0.015);
  // arr->Draw();

  if (gDebug > 0) printf(" plot.C p.fOutputFn = %s\n",p.fOutputFn.Data());
    
  if (Print == 1) p.print() ;

  return pdata;
}
