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

#include "plot_figure_0001.C"

#include "plot_figure_0011.C"
                                        // 2mm Ti degrader 
#include "plot_figure_0201.C"
#include "plot_figure_0202.C"           //   T0
#include "plot_figure_0203.C"           //   tdip
#include "plot_figure_0204.C"           //   chi2d 
#include "plot_figure_0205.C"           //   nactv 
#include "plot_figure_0206.C"           //   momerr 

#include "plot_figure_0211.C"

#include "plot_figure_0231.C"

#include "plot_figure_0251.C"
                                        // events passing ID cuts
#include "plot_figure_0261.C"
                                        // "N-1 plots"
#include "plot_figure_0273.C"           // N-1 tdip
#include "plot_figure_0274.C"           // N-1 nactv
#include "plot_figure_0275.C"           // N-1 chi2d
#include "plot_figure_0276.C"           // N-1 momerr

                                        // 3 mm 
#include "plot_figure_0331.C"

#include "plot_figure_0351.C"
#include "plot_figure_0361.C"
                                        // 4 mm 
#include "plot_figure_0431.C"
#include "plot_figure_0451.C"
#include "plot_figure_0461.C"
                                        // 5 mm 
#include "plot_figure_0501.C"
#include "plot_figure_0502.C"
#include "plot_figure_0503.C"           //   tdip

#include "plot_figure_0531.C"
#include "plot_figure_0551.C"
#include "plot_figure_0561.C"
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
  if      (Figure ==   1) pdata = plot_figure_0001(Figure,Print);

  else if (Figure ==  11) pdata = plot_figure_0011(Figure,Print);
  
  else if (Figure == 201) pdata = plot_figure_0201(Figure,Print);       // 
  else if (Figure == 202) pdata = plot_figure_0202(Figure,Print);
  else if (Figure == 203) pdata = plot_figure_0203(Figure,Print);       // ID tdip   bpip2b0s51 vs bpip2b0s54 all tracks
  else if (Figure == 204) pdata = plot_figure_0204(Figure,Print);       // ID chi2d  bpip2b0s51 vs bpip2b0s54
  else if (Figure == 205) pdata = plot_figure_0205(Figure,Print);       // ID nactv  bpip2b0s51 vs bpip2b0s54
  else if (Figure == 206) pdata = plot_figure_0206(Figure,Print);       // ID momerr bpip2b0s51 vs bpip2b0s54

  else if (Figure == 211) pdata = plot_figure_0211(Figure,Print);       // 

  else if (Figure == 231) pdata = plot_figure_0231(Figure,Print);

  else if (Figure == 251) pdata = plot_figure_0251(Figure,Print);       // momentum, yields ST vs DEG
  else if (Figure == 261) pdata = plot_figure_0261(Figure,Print);       // momentum, yields ST vs DEG

  else if (Figure == 273) pdata = plot_figure_0273(Figure,Print);       // Track ID, tdip
  else if (Figure == 274) pdata = plot_figure_0274(Figure,Print);       // Track ID, nactv
  else if (Figure == 275) pdata = plot_figure_0275(Figure,Print);       // Track ID, chi2d
  else if (Figure == 276) pdata = plot_figure_0276(Figure,Print);       // Track ID, momerr
  
  else if (Figure == 331) pdata = plot_figure_0331(Figure,Print);

  else if (Figure == 351) pdata = plot_figure_0351(Figure,Print);       // momentum, yields ST vs DEG
  else if (Figure == 361) pdata = plot_figure_0361(Figure,Print);       // momentum, yields ST vs DEG
  
  else if (Figure == 431) pdata = plot_figure_0431(Figure,Print);
  else if (Figure == 451) pdata = plot_figure_0451(Figure,Print);       // momentum, yields ST vs DEG
  else if (Figure == 461) pdata = plot_figure_0461(Figure,Print);       // momentum, yields ST vs DEG
  
  else if (Figure == 501) pdata = plot_figure_0501(Figure,Print);
  else if (Figure == 502) pdata = plot_figure_0502(Figure,Print);
  else if (Figure == 503) pdata = plot_figure_0503(Figure,Print);       // tdip   bpip5b0s51 vs bpip5b0s54

  else if (Figure == 531) pdata = plot_figure_0531(Figure,Print);
  else if (Figure == 551) pdata = plot_figure_0551(Figure,Print);       // momentum, yields ST vs DEG
  else if (Figure == 561) pdata = plot_figure_0561(Figure,Print);       // momentum, yields ST vs DEG

  return pdata;
}
