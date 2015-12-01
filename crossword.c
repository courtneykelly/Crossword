
// crossword.c
// Katie Schermerhorn and Courtney Kelly

#include <stdio.h>
#include <string.h>

int userInput( char [][17] );
void initializeBoard( char [][15] );
void sortWords( char [][17] , int);
int compare(char * a, char * b);

int main() {

// Get User Input
	char words[20][17];
	int i;

	i = userInput(words);

// Initialize Board
	char board[15][15]= {0};
	initializeBoard(board);
	
// Sort Words
	sortWords(words,i);
	int n;
	for (n=0; n<i; n++) {
	  printf("%s\n",words[n]);
	}

// Generate Puzzle


// Display Hints 
	
}
int userInput( char words[20][17] ) {
	char key[2] = ".";
	int  i=0, loop=1;

        printf("Anagram Crossword Puzzle Generator\n----------------------------------\n");
        printf("Enter a list of words:\n");
	while (loop) {
		fscanf(stdin, "%s", words[i]);
		if (strcasestr(words[i], key) || i>18) {
                        loop=0;
                }
		i++;
        }

	return i;
}
void initializeBoard(char board[15][15]) {
	int row, col;
	char key = '.';
	for (row=0; row<15; row++) {
		for (col=0; col<15; col++) {
			board[row][col] = key;
			printf("%c", board[row][col]);
		}
       		  printf("\n");
	}
}
void sortWords(char words[20][17],int i) {
	
	qsort(words[0], i, 17, compare);
}
int compare(char * a, char * b) {
	if (strlen(a) > strlen(b)) return -1;
	if (strlen(a) == strlen(b)) return 0;
  	if (strlen(a) < strlen(b)) return 1;
}
