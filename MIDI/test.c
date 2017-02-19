#include <linux/soundcard.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "nerth_midi.h"

int main(void){
	
	int note = 60;
	int duration = 8;
	char* device = "/dev/midi1";
	
	MIDI_TRI(device, note, 0, duration);
	MIDI_TRI(device, note, 1, duration);	
	MIDI_TRI(device, note, 2, duration);
	MIDI_TRI(device, note, 3, duration);

	return 0;
}

