#include <linux/soundcard.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "nerth_chords.h"

int main(int argc, char *argv[]){
	
	int note = atoi(argv[1]);
	float duration = atof(argv[2]);
	char* device = "/dev/midi1";
	
	MIDI_TRI(device, note, 2, duration);

	return 0;
}

