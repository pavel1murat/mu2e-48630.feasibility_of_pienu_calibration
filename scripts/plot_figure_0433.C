//-----------------------------------------------------------------------------
// 4 mm DEG: trk_178/p_2 vs trk_158/p_2 for DIF (loose vs  tight ID)
//-----------------------------------------------------------------------------
plot_data_t* plot_figure_0433(int Figure, int Print) {
    
  const char* bpip4b0s51  = "pipenu.bpip4b0s51r0100";
  const char* bpip4b0s54  = "pipenu.bpip4b0s54r0100";
  const char* bmup4b0s54  = "pipenu.bmup4b0s54r0100";

  const char* book        = "pipenu";
  const char* ana_job     = "murat_pipenu_ana.0000";
  const char* ana_module  = "PipenuAna";
  // const char* hist_name   = "trk_178/p_2";
  
  plot_data_t* pdata      = new plot_data_t(2);
  plot_data_t& p          = *pdata;
//-----------------------------------------------------------------------------
// 100000: the number of generated pi+ --> e+ nu events in each sample
// 2.5e8 : the number of POT generated to get the pion stops
// 1.23e-4 : BR(pi --> e nu)
//------------------------------------------------------------------------------
  p.hd[0]              = hist_data_t(catalog,book,bmup4b0s54,ana_job,ana_module,"trk_106/p_2");
  p.hd[0].fRebin       = 5;
  p.hd[0].fLabel       = "DIF, loose cuts";
  p.hd[0].fLineColor   = kGreen+3;
  p.hd[0].fMarkerColor = kGreen+3;
  p.hd[0].fMarkerStyle = 24;
  p.hd[0].fLumiSF      = gPipenu->GetChannel("bmup4b0s54r0100")->NormSF();
//-----------------------------------------------------------------------------
// no need to weigh the DIF histogram with the pion survival prob
//-----------------------------------------------------------------------------
  p.hd[1]              = hist_data_t(catalog,book,bmup4b0s54,ana_job,ana_module,"trk_126/p_2");
  p.hd[1].fRebin       = 5;
  p.hd[1].fLabel       = "DIF, tight cuts";
  p.hd[1].fMarkerColor = kGreen+3;
  p.hd[1].fLineColor   = kGreen+3;
  p.hd[1].fMarkerStyle = 20;
  p.hd[1].fMarkerSize  = 1.0;
  p.hd[1].fLumiSF      = gPipenu->GetChannel("bmup4b0s54r0100")->NormSF();
    
  p.fXMin              = 40.;
  p.fXMax              = 90.;
  p.fYMin              = 1e-15;
  p.fYMax              = 1e-10;
  p.fCanvasName        = Form("Figure_%04i",Figure);
  p.fName              = Form("figure_%05i",Figure);
  p.fLabel             = "4 mm Ti";
  p.fYLogScale         = 1;

  p.fStatBoxYMax       = 0.90;
  p.fStatBoxYMin       = 0.75;
  p.fLegendXMin        = 0.50; p.fLegendXMax  = 0.70; p.fLegendYMin  = 0.70; p.fLegendYMax  = 0.80; 
    
  plot_hist_1d(&p,-1);

  p.fCanvas->Modified();
  p.fCanvas->Update();

  // TArrow* arr = new TArrow(200,100,200,20,0.015);
  // arr->Draw();

  printf(" plot.C p.fOutputFn = %s\n",p.fOutputFn.Data());
    
  if (Print == 1) p.print() ;

  return pdata;
}
