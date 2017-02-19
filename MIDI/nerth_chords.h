#ifndef  _nerth_chords_h
#define  _nerth_chords_h
#include <linux/soundcard.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int MIDI_BANG(char* device, int note,float duration);
int MIDI_TRI(char* device, int root, int type, float duration);

#endif
