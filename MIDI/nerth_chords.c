#include <linux/soundcard.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "nerth_chords.h"

int MIDI_BANG(char* device, int note, float duration){
	unsigned char data_0[3] = {0x90, note, 127};
	unsigned char data_1[3] = {0x80, note, 127};

	int fd = open(device, O_WRONLY, 0);
	if (fd < 0){
		printf("Device %s:\tError:\tcannot open MIDI stream\n", device);
		exit(1);
	}

	write(fd, data_0, sizeof(data_0));
	sleep(duration);
	write(fd, data_1, sizeof(data_1));

	close(fd);

	return 0;
}

int MIDI_TRI(char* device, int root, int type, float duration){

	unsigned char data_root[3] = {0x90, root, 127};
	unsigned char data_third[3] = {0x90, root, 127};
	unsigned char data_fifth[3] = {0x90, root, 127}; 
	
	switch(type) {
		
	case 0 :
		data_third[1] = root + 4;
		data_fifth[1] = root + 7;
		break;
	case 1 :
		data_third[1] = root + 4;
		data_fifth[1] = root + 8;
		break;

	case 2 : 
		data_third[1] = root + 3;
		data_fifth[1] = root + 7;
		break;

	case 3 :
		data_third[1] = root + 3;
		data_fifth[1] = root + 6;
		break;

	default : 
		printf("Error:\ttype is not a valid\n");
		exit(1);
	}

	int fd = open(device, O_WRONLY, 0);
	if (fd < 0){
		printf("Device %s:\tError:\tcannot open MIDI stream\n", device);
		exit(1);
	}

	write(fd, data_root, sizeof(data_root));
	write(fd, data_third, sizeof(data_third));
	write(fd, data_fifth, sizeof(data_fifth));

	sleep(duration);

	data_root[0] = 0x80;
	data_third[0] = 0x80;
	data_fifth[0] = 0x80;

	write(fd, data_root, sizeof(data_root));
	write(fd, data_third, sizeof(data_third));
	write(fd, data_fifth, sizeof(data_fifth));

	close(fd);

	return 0;
}


