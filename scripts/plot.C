///////////////////////////////////////////////////////////////////////////////
// HistDir and FiguresDir have to be defined before init_local_files.C
// always print in .eps, convert to .png or .pdf in GNUMakefile
//
///////////////////////////////////////////////////////////////////////////////
const char* Mu2eNotesDir        = "/exp/mu2e/data/projects/pipenu/notes";         // mu2egpvm*
const char* Mu2eHistDir         = "/exp/mu2e/data/projects/pipenu/hist";      // mu2egpvm*

const char* NoteRepo            = "mu2e-xxxxx.feasibility_of_pienu_calibration";

char  FiguresDir    [500] = "";
char  pipenu_HistDir[500] = "";

double BR_pienu   = 1.23e-4;
double NPOT_pienu = 2.5e8;          // 500(s1 jobs)x500,000(events per s1 job)


#include <stdio.h>
#include <string.h>
#include "Stntuple/val/stn_catalog.hh"
#include "Stntuple/scripts/plot_hist_1D.C"
#include "Stntuple/scripts/plot_hist_2D.C"
#include "pipenu/ana/Analysis.hh"

stn_catalog*      catalog;           // has to be global
pipenu::Analysis* gPipenu;           // same

#include "pipenu/ana/scripts/init_pipenu_datasets.C"

#include "plot_figure_0001.C"           // all ST tracks, weighted momentum
#include "plot_figure_0002.C"           // all ST tracks, weighted T0
#include "plot_figure_0009.C"           // weighted foil number, ST datasets

#include "plot_figure_0011.C"           // good ST tracks, weighted T0
#include "plot_figure_0012.C"           // good ST tracks, weighted T0

#include "plot_figure_0031.C"           // trk_158/p_2 NO_DEG
#include "plot_figure_0032.C"           // trk_178/p_2 NO_DEG

#include "plot_figure_0041.C"           // good degrader tracks, weighted momentum

                                        // 2mm Ti degrader 
#include "plot_figure_0201.C"
#include "plot_figure_0202.C"           //   T0
#include "plot_figure_0203.C"           //   tdip
#include "plot_figure_0204.C"           //   chi2d 
#include "plot_figure_0205.C"           //   nactv 
#include "plot_figure_0206.C"           //   momerr 

#include "plot_figure_0211.C"

#include "plot_figure_0231.C"           // trk_158/p_2 2mm (loose ID)
#include "plot_figure_0232.C"           // trk_178/p_2 2mm (tight ID)
#include "plot_figure_0233.C"           // 2mm DIF trk mom loose ID vs tight ID)

#include "plot_figure_0251.C"           // STT vs DEG: all  tracks, mom
                                        // -------------- events passing the ID cuts
#include "plot_figure_0261.C"           // STT vs DEG: good tracks, mom
#include "plot_figure_0262.C"           // STT vs DEG: good tracks, TO

                                        // track ID, "N-1" plots
#include "plot_figure_0273.C"           // N-1 tdip
#include "plot_figure_0274.C"           // N-1 nactv
#include "plot_figure_0275.C"           // N-1 chi2d
#include "plot_figure_0276.C"           // N-1 momerr
#include "plot_figure_0277.C"           // N-1 d0

#include "plot_figure_0284.C"           // N-1 momerr
#include "plot_figure_0287.C"           // N-1 momerr

                                        // 3 mm 
#include "plot_figure_0331.C"           // trk_158/p_2  loose ID
#include "plot_figure_0332.C"           // trk_178/p_2  tight ID
#include "plot_figure_0333.C"           // DIF: tight ID vsl loose ID

#include "plot_figure_0351.C"
                                        // -------- yields, tracks passing the ID cuts
#include "plot_figure_0361.C"
#include "plot_figure_0362.C"
                                        // 4 mm 
#include "plot_figure_0431.C"           // trk_158/p_2  loose ID
#include "plot_figure_0432.C"           // trk_178/p_2  tight ID
#include "plot_figure_0433.C"           // DIF: tight ID vsl loose ID

#include "plot_figure_0451.C"

                                        // -------- yields, tracks passing the ID cuts
#include "plot_figure_0461.C"
#include "plot_figure_0462.C"

#include "plot_figure_0484.C"           // track ID , track D0
#include "plot_figure_0487.C"           // track ID , track D0

                                        // ---------------------- 5 mm 
#include "plot_figure_0501.C"
#include "plot_figure_0502.C"
#include "plot_figure_0503.C"           //   tdip

#include "plot_figure_0531.C"           // trk_158/p_2  tight ID
#include "plot_figure_0532.C"           // trk_178/p_2  tight ID
#include "plot_figure_0533.C"           // DIF: tight ID vsl loose ID

#include "plot_figure_0551.C"

                                        // yields, good tracks
#include "plot_figure_0561.C"
#include "plot_figure_0562.C"
                                        // pion stop distributions, bpip*b0s21 and bpip*b0s24
#include "plot_figure_2002.C"
#include "plot_figure_2402.C"          
                                        // muon decay Z distributions, bmup*b0s24 and bmup*b0s25
#include "plot_figure_3401.C"           // bmu0pb0
#include "plot_figure_3412.C"           // bmu0pb0s24 vs s25
#include "plot_figure_3422.C"           // bmu0pb0s24 vs s25  p(e+) > 55 MeV/c
#include "plot_figure_3432.C"           // bmu0pb0s24 vs s25  p(e+) > 60 MeV/c
#include "plot_figure_3451.C"           // bmu5pb0
#include "plot_figure_3501.C"           // bmup9b0 plots with different decay constraints
#include "plot_figure_3701.C"           // bmu5pb0
//-----------------------------------------------------------------------------
// real [machine-dependent] values of Mu2eNotesDir and Mu2eHistDir 
// should be defined in .rootrc
// it is assumed that the note has been checed out into $mu2e.NotesDir/$NoteRepo
// and all needed histograms are located in $mu2e.HistDir/su2020
//-----------------------------------------------------------------------------
void init() {
  
  stn_book* book;

  const char* notes_dir = gEnv->GetValue("mu2e.pipenu.NotesDir",Mu2eNotesDir);
  sprintf(FiguresDir,"%s/%s/figures",notes_dir,NoteRepo);
  gEnv->SetValue("FiguresDir",FiguresDir);

  const char* hist_dir = gEnv->GetValue("mu2e.pipenu.HistDir",Mu2eHistDir);
  sprintf(pipenu_HistDir,"%s",hist_dir);

  catalog = new stn_catalog("my");
  
  book = new stn_book("pipenu",pipenu_HistDir);
  init_pipenu_datasets(book);
  catalog->AddBook(book);

  gPipenu = new pipenu::Analysis("a");
  
  printf(" after init_local\n");
}

//-----------------------------------------------------------------------------
plot_data_t* plot(int Figure, int Print = 0) {
  plot_data_t* pdata;

  init();
//-----------------------------------------------------------------------------
// fig    1: 
//-----------------------------------------------------------------------------
  if      (Figure ==    1) pdata = plot_figure_0001(Figure,Print);  // all STT tracks, reconstructed momentum
  if      (Figure ==    2) pdata = plot_figure_0002(Figure,Print);  // all STT tracks, reconstructed T0
  if      (Figure ==    9) pdata = plot_figure_0009(Figure,Print);  // bpip?s21r0000 (STT) datasets: weighted foil number

  else if (Figure ==   11) pdata = plot_figure_0011(Figure,Print);  // good STT tracks, reconstructed mom
  else if (Figure ==   12) pdata = plot_figure_0012(Figure,Print);  // good STT tracks, reconstructed T0
  
  else if (Figure ==   31) pdata = plot_figure_0031(Figure,Print);  // trk_158/p_2
  else if (Figure ==   32) pdata = plot_figure_0032(Figure,Print);  // trk_178/p_2: tight ID, NO_DEG, money plot

  else if (Figure ==   41) pdata = plot_figure_0041(Figure,Print);  // good DEG tracks, reconstructed mom
//-----------------------------------------------------------------------------
// 3mm Ti
//-----------------------------------------------------------------------------
  else if (Figure ==  201) pdata = plot_figure_0201(Figure,Print);  // 
  else if (Figure ==  202) pdata = plot_figure_0202(Figure,Print);
  else if (Figure ==  203) pdata = plot_figure_0203(Figure,Print);  // ID tdip   bpip2b0s51 vs bpip2b0s54 all tracks
  else if (Figure ==  204) pdata = plot_figure_0204(Figure,Print);  // ID chi2d  bpip2b0s51 vs bpip2b0s54
  else if (Figure ==  205) pdata = plot_figure_0205(Figure,Print);  // ID nactv  bpip2b0s51 vs bpip2b0s54
  else if (Figure ==  206) pdata = plot_figure_0206(Figure,Print);  // ID momerr bpip2b0s51 vs bpip2b0s54

  else if (Figure ==  211) pdata = plot_figure_0211(Figure,Print);  // 

  else if (Figure ==  231) pdata = plot_figure_0231(Figure,Print);  // trk_158/p_2
  else if (Figure ==  232) pdata = plot_figure_0232(Figure,Print);  // trk_178/p_2: tight ID, 4mm, money plot
  else if (Figure ==  233) pdata = plot_figure_0233(Figure,Print);  // DIF, tight ID vs loose ID

  else if (Figure ==  251) pdata = plot_figure_0251(Figure,Print);  // STT vs DEG yield: all  tracks, momentum
  
  else if (Figure ==  261) pdata = plot_figure_0261(Figure,Print);  // STT vs DEG yield: good tracks, momentum, 
  else if (Figure ==  262) pdata = plot_figure_0262(Figure,Print);  // STT vs DEG yield: good tracks, T0      , 

  else if (Figure ==  273) pdata = plot_figure_0273(Figure,Print);  // Track ID, tdip
  else if (Figure ==  274) pdata = plot_figure_0274(Figure,Print);  // Track ID, nactv
  else if (Figure ==  275) pdata = plot_figure_0275(Figure,Print);  // Track ID, chi2d
  else if (Figure ==  276) pdata = plot_figure_0276(Figure,Print);  // Track ID, momerr
  else if (Figure ==  277) pdata = plot_figure_0277(Figure,Print);  // Track ID, d0

  else if (Figure ==  284) pdata = plot_figure_0284(Figure,Print);  // Track ID, trk_125/nactv 
  else if (Figure ==  287) pdata = plot_figure_0287(Figure,Print);  // track D0, trk_125/d0
//-----------------------------------------------------------------------------
// 3mm Ti
//-----------------------------------------------------------------------------
  else if (Figure ==  331) pdata = plot_figure_0331(Figure,Print);
  else if (Figure ==  332) pdata = plot_figure_0332(Figure,Print);  // tight ID, 4mm, money plot
  else if (Figure ==  333) pdata = plot_figure_0333(Figure,Print);  // DIF, tight ID vs loose ID

  else if (Figure ==  351) pdata = plot_figure_0351(Figure,Print);  // momentum, yields ST vs DEG
  
  else if (Figure ==  361) pdata = plot_figure_0361(Figure,Print);  // momentum, yields ST vs DEG
  else if (Figure ==  362) pdata = plot_figure_0362(Figure,Print);  // T0      , yields ST vs DEG
  
  else if (Figure ==  431) pdata = plot_figure_0431(Figure,Print);
  else if (Figure ==  432) pdata = plot_figure_0432(Figure,Print);  // tight ID, 4mm, money plot
  else if (Figure ==  433) pdata = plot_figure_0433(Figure,Print);  // DIF, tight ID vs loose ID

  else if (Figure ==  451) pdata = plot_figure_0451(Figure,Print);       // momentum, yields ST vs DEG

  else if (Figure ==  461) pdata = plot_figure_0461(Figure,Print);       // momentum, yields ST vs DEG
  else if (Figure ==  462) pdata = plot_figure_0462(Figure,Print);       // T0      , yields ST vs DEG

  else if (Figure ==  484) pdata = plot_figure_0484(Figure,Print);       // track ID, Nactive
  else if (Figure ==  487) pdata = plot_figure_0487(Figure,Print);       // track ID, d0
  
  else if (Figure ==  501) pdata = plot_figure_0501(Figure,Print);
  else if (Figure ==  502) pdata = plot_figure_0502(Figure,Print);
  else if (Figure ==  503) pdata = plot_figure_0503(Figure,Print);       // tdip   bpip5b0s51 vs bpip5b0s54

  else if (Figure ==  531) pdata = plot_figure_0531(Figure,Print);
  else if (Figure ==  532) pdata = plot_figure_0532(Figure,Print);  // money plot, tight ID
  else if (Figure ==  533) pdata = plot_figure_0533(Figure,Print);  // DIF, tight ID vs loose ID
  
  else if (Figure ==  551) pdata = plot_figure_0551(Figure,Print);       // momentum, yields ST vs DEG, all  tracks

  else if (Figure ==  561) pdata = plot_figure_0561(Figure,Print);       // momentum, yields ST vs DEG, good tracks
  else if (Figure ==  562) pdata = plot_figure_0562(Figure,Print);       // T0      , yields ST vs DEG, good tracks
//------------------------------------------------------------------------------
// MC pion stops pion BPIP*S21 datasets:
//-----------------------------------------------------------------------------
  if      (Figure == 2002) pdata = plot_figure_2002(Figure,Print);       // pi+ tstop, ST
  if      (Figure == 2402) pdata = plot_figure_2402(Figure,Print);       // pi+ tstop, degrader
//------------------------------------------------------------------------------
// muon decay reweighting MC 
//-----------------------------------------------------------------------------
  if      (Figure == 3401) pdata = plot_figure_3401(Figure,Print);       // bmup0b0 mu+ decay Z
  if      (Figure == 3412) pdata = plot_figure_3412(Figure,Print);       // bmup0b0s24 vs s25 mu+ decay time
  if      (Figure == 3422) pdata = plot_figure_3422(Figure,Print);       // bmup0b0s24 vs s25 mu+ decay time p> 55
  if      (Figure == 3432) pdata = plot_figure_3432(Figure,Print);       // bmup0b0s24 vs s25 mu+ decay time p > 60
  if      (Figure == 3451) pdata = plot_figure_3451(Figure,Print);       // bmup5b0 mu+ decay Z
  if      (Figure == 3501) pdata = plot_figure_3501(Figure,Print);       // bmup9b9s2? mu+ decay Z
  if      (Figure == 3701) pdata = plot_figure_3701(Figure,Print);       // ratios


  return pdata;
}
