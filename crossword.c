
// crossword.c
// Katie Schermerhorn and Courtney Kelly

#include <stdio.h>
#include <string.h>

// Functions

int main() {

// Get User Input
	char key[2] = ".";
	char words[20][16];
	int i=0, loop=1;

	printf("Anagram Crossword Puzzle Generator\n----------------------------------\n");
	printf("Enter a list of words:\n");
	while (loop) {
		fgets(words[i], 16, stdin);
		if (strcasestr(words[i], key)) {
			loop=0;
		}
		i++;
	}

// Initialize Board
	

// Generate Puzzle
	

// Display Hints 
	
}
