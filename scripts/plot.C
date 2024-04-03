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

stn_catalog*   catalog;           // has to be global

#include "pipenu/ana/scripts/init_pipenu_datasets.C"

#include "plot_figure_0001.C"
#include "plot_figure_0201.C"
#include "plot_figure_0202.C"

#include "plot_figure_0331.C"

#include "plot_figure_0431.C"

#include "plot_figure_0501.C"
#include "plot_figure_0502.C"

#include "plot_figure_0531.C"

// pipenu::channel*  bpip0b0(nullptr) ;
// pipenu::channel*  bpip2b0(nullptr) ;
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

  // bpip0b0 = init_channel("bpip0b0");
  
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
  
  else if (Figure == 201) pdata = plot_figure_0201(Figure,Print);
  else if (Figure == 202) pdata = plot_figure_0202(Figure,Print);

  else if (Figure == 331) pdata = plot_figure_0331(Figure,Print);
  
  else if (Figure == 431) pdata = plot_figure_0431(Figure,Print);
  
  else if (Figure == 501) pdata = plot_figure_0501(Figure,Print);
  else if (Figure == 502) pdata = plot_figure_0502(Figure,Print);

  else if (Figure == 531) pdata = plot_figure_0531(Figure,Print);
  
  return pdata;
}
