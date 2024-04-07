//-----------------------------------------------------------------------------
// tight ID, 5mm DEG: trk_178/p_2 for STT, DEG and DIF
//-----------------------------------------------------------------------------
plot_data_t* plot_figure_0532(int Figure, int Print) {
    
  const char* bpip5b0s51  = "pipenu.bpip5b0s51r0100";
  const char* bpip5b0s54  = "pipenu.bpip5b0s54r0100";
  const char* bmup5b0s54  = "pipenu.bmup5b0s54r0100";

  const char* book        = "pipenu";
  const char* ana_job     = "murat_pipenu_ana.0000";
  const char* ana_module  = "PipenuAna";
  const char* hist_name   = "trk_178/p_2";
  
  plot_data_t* pdata      = new plot_data_t(3);
  plot_data_t& p          = *pdata;
//-----------------------------------------------------------------------------
// 100000: the number of generated pi+ --> e+ nu events in each sample
// 2.5e8 : the number of POT generated to get the pion stops
// 1.23e-4 : BR(pi --> e nu)
//------------------------------------------------------------------------------
  p.hd[0]              = hist_data_t(catalog,book,bpip5b0s51,ana_job,ana_module,hist_name);

  p.hd[0].fRebin       = 5;
  p.hd[0].fXAxisTitle  = "T0, ns";
  p.hd[0].fLabel       = "ST";
  p.hd[0].fMarkerColor = kRed+1;
  p.hd[0].fMarkerStyle = 20;
  p.hd[0].fLumiSF      = gPipenu->GetChannel("bpip5b0s51r0100")->NormSF();

  p.hd[1]              = hist_data_t(catalog,book,bpip5b0s54,ana_job,ana_module,hist_name);
  p.hd[1].fRebin       = 5;
  p.hd[1].fLabel       = "Degrader";
  p.hd[1].fMarkerColor = kBlue;
  p.hd[1].fMarkerStyle = 21;
  p.hd[1].fMarkerSize  = 0.8;
  p.hd[1].fLumiSF      = gPipenu->GetChannel("bpip5b0s54r0100")->NormSF();
//-----------------------------------------------------------------------------
// no need to weigh the DIF histogram with the pion survival prob
//-----------------------------------------------------------------------------
  p.hd[2]              = hist_data_t(catalog,book,bmup5b0s54,ana_job,ana_module,"trk_128/p_2");
  p.hd[2].fRebin       = 5;
  p.hd[2].fLabel       = "DIF";
  p.hd[2].fMarkerColor = kGreen+3;
  p.hd[2].fLineColor   = kGreen+3;
  p.hd[2].fMarkerStyle = 22;
  p.hd[2].fMarkerSize  = 0.8;
  p.hd[2].fLumiSF      = gPipenu->GetChannel("bmup5b0s54r0100")->NormSF();
    
  p.fXMin              = 55.;
  p.fXMax              = 80.;
  p.fYMin              = 1e-15;
  p.fYMax              = 1e-9;
  p.fCanvasName        = Form("Figure_%04i",Figure);
  p.fName              = Form("figure_%05i",Figure);
  p.fLabel             = "5 mm Ti.";
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
