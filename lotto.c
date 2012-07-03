#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>

void die(const char *message) {
		if(errno) {
			perror(message);
		} else {
			printf("ERROR: %s\n", message);
		}
		exit(1);
}

int duplicate(int *selected, int size,	int number) {
	int i = 0;
	for(i = 0; i < size; i++) {
		//printf("Check number %d, %d = %d\n", i, selected[i], number);
		if(selected[i] == number) {
			return 1;
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	//get a seed of the current time.
	unsigned int iseed = (unsigned int)time(NULL);
	//add seed to the random number generator
	srand(iseed);
	
	if(argc < 4) die("Useage: lotto.bin/powerball.bin <lowest possible number> <highest possible number> <number of picks> {optional:number of games, default: 1}");
	
	char *game_name = argv[0];

	int min = atoi(argv[1]);
	//if char did not convert to int exit.
	if(!min) die("Min number not set");

	int max = atoi(argv[2]);
	if(!max) die("Max number not set");

	int picks = atoi(argv[3]);
	if(!picks) die("number of picks not set");

	int selected[picks];
	memset(selected, 0, picks * sizeof(int));
	
	int repeat = 1;
	if(argv[4]) {
		repeat = atoi(argv[4]);
		if(!repeat) die("repeat could not be set");
	}

	int i = 0;
	int j = 0;
	for(j = 0; j < repeat; j++) {
		printf("Game %*d: ", 4, j+1);
		for(i = 0; i < picks; i++) {
			int selection = rand() % max + min;
			if(duplicate(selected, picks, selection) == 0) {
				selected[i] = selection;
				printf("%*d", 4, selected[i]);
			} else {
				i--;
			}
		}
		if(strcmp("./powerball.bin", game_name) == 0) {
			int selection = rand() % max + min;
			printf("    powerball%*d", 4, selection);
		}
		printf("\n");
	}
	
	return 0;
}

