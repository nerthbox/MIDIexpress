#include <linux/soundcard.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
	char* device = "/dev/midi1";
	unsigned char note_60_on[3] = {0x90, 60, 127};
	unsigned char note_60_off[3] = {0x80, 60, 127};
	//step 1: open dev for writing
	int fd = open(device, O_WRONLY, 0);
	if (fd < 0) {
		printf("bang.c:\tError:\tcannot open %s\n", device);
		exit(1);
	}

	//step 2: write MIDI info to dev
	write(fd, note_60_on, sizeof(data));

	sleep(1);

	write(fd, note_60_off, sizeof(data));

	//step3: (optional) close dev
	close(fd);

	return 0;

} 
