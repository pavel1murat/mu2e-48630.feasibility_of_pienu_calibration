//


//-----------------------------------------------------------------------------
pipenu::channel* init_channel(const char* Name) {
  pipenu::channel* ch = new pipenu::channel();

  ch->fName = Name;

  return ch;
}
