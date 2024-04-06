//-----------------------------------------------------------------------------
// bpip*b0s21 datasets - pion stop distributions over the ST foils
// just sum over the individual weights
//-----------------------------------------------------------------------------
plot_data_t* plot_figure_0009(int Figure, int Print) {
    
  const char* bpip0b0  = "pipenu.bpip0b0s21r0000";
  const char* bpip2b0  = "pipenu.bpip2b0s21r0000";
  const char* bpip3b0  = "pipenu.bpip3b0s21r0000";
  const char* bpip4b0  = "pipenu.bpip4b0s21r0000";
  const char* bpip5b0  = "pipenu.bpip5b0s21r0000";

  const char* book       = "pipenu";
  const char* ana_job    = "murat_spmc_ana.0000";
  const char* ana_module = "murat_SpmcAna";
  const char* hist_name  = "simp_216/vid1";

  plot_data_t* pdata = new plot_data_t(5);
  plot_data_t& p     = *pdata;
//-----------------------------------------------------------------------------
// 100000: the number of generated pi+ --> e+ nu events in each sample
// 2.5e8 : the number of POT generated to get the pion stops
// 1.23e-4 : BR(pi --> e nu)
//------------------------------------------------------------------------------
  p.hd[0]              = hist_data_t(catalog,book,bpip0b0,ana_job,ana_module,hist_name);
  p.hd[0].fRebin       = 1;
  p.hd[0].fNewName     = "bpip0s21r000:vid1";
  p.hd[0].fLabel       = "no degrader";
  p.hd[0].fMarkerColor = kRed+1;
  p.hd[0].fMarkerStyle = 20;
  // p.hd[0].fLumiSF      = (312616./100000);

  p.hd[1]              = hist_data_t(catalog,book,bpip2b0,ana_job,ana_module,hist_name);
  p.hd[1].fRebin       = 1;
  p.hd[1].fLabel       = "2 mm Ti";
  p.hd[1].fMarkerColor = kBlue;
  p.hd[1].fMarkerStyle = 21;
  p.hd[1].fMarkerSize  = 0.8;
  // p.hd[1].fLumiSF      = (84785./100000.);
    
  p.hd[2]              = hist_data_t(catalog,book,bpip3b0,ana_job,ana_module,hist_name);
  p.hd[2].fRebin       = 1;
  p.hd[2].fLabel       = "3 mm Ti";
  p.hd[2].fLineColor   = kGreen+2;
  p.hd[2].fMarkerColor = kGreen+2;
  p.hd[2].fMarkerStyle = 22;
  p.hd[2].fMarkerSize  = 0.8;
  // p.hd[2].fLumiSF      = (50340./100000.);
    
  p.hd[3]              = hist_data_t(catalog,book,bpip4b0,ana_job,ana_module,hist_name);
  p.hd[3].fRebin       = 1;
  p.hd[3].fLabel       = "4 mm Ti";
  p.hd[3].fMarkerColor = kBlack;
  p.hd[3].fMarkerStyle = 23;
  p.hd[3].fMarkerSize  = 0.8;
  // p.hd[3].fLumiSF      = (31681./100000.);
    
  p.hd[4]              = hist_data_t(catalog,book,bpip5b0,ana_job,ana_module,hist_name);
  p.hd[4].fRebin       = 1;
  p.hd[4].fLabel       = "5 mm Ti";
  p.hd[4].fMarkerColor = kBlack;
  p.hd[4].fMarkerStyle = 24;
  p.hd[4].fMarkerSize  = 0.8;
  // p.hd[4].fLumiSF      = (17225./100000.);
    
  p.fXMin              = 2970;
  p.fXMax              = 3050;
  p.fYMin              = 0;
  p.fYMax              = 15;
  p.fXAxisTitle        = "ST foil number";
  p.fCanvasName        = Form("Figure_%05i",Figure);
  p.fName              = Form("figure_%05i",Figure);
  p.fTitle             = "ST foil number";
  p.fLabel             = "ST foil number for #pi^{+} stops, N(POT)=2.5#times10^{8}";
  p.fYLogScale         = 0;

  p.fStatBoxYMax = 0.90;
  p.fStatBoxYMin = 0.75;

  p.fLegendXMin  = 0.15; p.fLegendXMax  = 0.35; p.fLegendYMin  = 0.6; p.fLegendYMax  = 0.8; 
    

  plot_hist_1d(&p,-1);

  p.fCanvas->Modified();
  p.fCanvas->Update();

  // TArrow* arr = new TArrow(200,100,200,20,0.015);
  // arr->Draw();

  printf(" plot.C p.fOutputFn = %s\n",p.fOutputFn.Data());
    
  if (Print == 1) p.print() ;

  return pdata;
}
