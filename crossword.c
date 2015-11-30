
// crossword.c
// Katie Schermerhorn and Courtney Kelly

#include <stdio.h>
#include <string.h>

void userInput( char [][16] );
void initializeBoard( char [][14] );

int main() {

// Get User Input
	char words[20][16];
	userInput(words);

// Initialize Board
	char board[14][14]= {0};
	initializeBoard(board);

// Generate Puzzle


// Display Hints 
	
}
void userInput( char words[20][16] ) {
	char key[2] = ".";
	int i=0, loop=1;

        printf("Anagram Crossword Puzzle Generator\n----------------------------------\n");
        printf("Enter a list of words:\n");
        while (loop) {
                fgets(words[i], 16, stdin);
                if (strcasestr(words[i], key) || i>18) {
                        loop=0;
                }
                i++;
        }
}
void initializeBoard(char board[14][14]) {
	int row, col;
	char key = '.';
	for (row=0; row<15; row++) {
		for (col=0; col<15; col++) {
			board[row][col] = key;
			printf("%c", board[row][col]);
		}
	}
}
	
