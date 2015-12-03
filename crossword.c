
// crossword.c
// Katie Schermerhorn and Courtney Kelly

#include <stdio.h>
#include <string.h>
#define place_success 1
#define place_failure 0

int userInput( char [][16] );
void initializeBoard( char [][15] );
void sortWords( char [][16] , int);
int compare(char * a, char * b);
void initialPlace(char [][16], char [][15]);
int placeWord(char [], char [][15]);
int can_place_word_horiz(char [], char [][15], int, int, int, int);
int can_place_word_vert(char [], char [][15], int, int, int, int);

int main() {

// Get User Input
	char words[21][16];
	int i;

	i = userInput(words);

// Initialize Board
	char board[15][15]= {0};
	initializeBoard(board);
	
// Sort Words
	sortWords(words,i);
	int row,col;
	

// Generate Puzzle
	initialPlace(words,board);
   
        for (row=0; row<15; row++) {
	    for (col=0; col<15; col++) {
		 printf("%c", board[row][col]);
		}
       		  printf("\n");
	}

	int n;

	for(n=1; n<(i-1); n++) {
	  	if(placeWord(words[n], board)) {
	   		printf("SUCCESS!");
		}
		else {
			printf("FAILURE!");
		}
	}






// Display Hints 
	
}
int userInput( char words[21][16] ) {
	char key[2] = ".";
	int  i=0, loop=1;

        printf("Anagram Crossword Puzzle Generator\n----------------------------------\n");
        printf("Enter a list of words:\n");
	while (loop) {
		fscanf(stdin, "%s", words[i]);
		if (strcasestr(words[i], key) || i>19) {
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
		}
	}
}
void sortWords(char words[21][16],int i) {
	
	qsort(words[0], i, 16, compare);
}
int compare(char * a, char * b) {
	if (strlen(a) > strlen(b)) return -1;
	if (strlen(a) == strlen(b)) return 0;
  	if (strlen(a) < strlen(b)) return 1;
}
void initialPlace(char words[21][16], char board[15][15]) {

  	int length = strlen(words[0]);
  	int startPoint = (15 - length)/2;
  	int n=0, i;

  	for (i=startPoint;i<(startPoint+length);i++){
    		board[7][i] = words[0][n];
    		n++;
  	}
}
 int placeWord(char * word, char board[15][15]) {

   	int row,col,i;
   	int length= strlen(word);

   	for (i=0; i<length; i++) {
     		for(row=0; row<15; row++){
       			for(col=0; col<15; col++){
	 			if (board[row][col]==word[i]) {
					printf("%c", word[i]);
	   				if (can_place_word_horiz(word, board, row, col, i, length)) {
	   					return place_success;
	   				}
					else if (can_place_word_vert(word, board, row, col, i, length)) {
	 					return place_success;
					}
				}
       			}
     		}
   	}
     	return place_failure;
 }
int can_place_word_horiz(char * word, char board[15][15], int row, int col, int i, int length) {

  	char key= '.';
	int n,k;

	// Checking against width of board
		if ((length-i) > (15-col) || ((col-i+1)< 0)) {
			return place_failure;
		}
	// Checking immedietly above through immedietly below the potential place for the word
		for (n=(row-1); n<=(row+1); n++) {
			for (k=(col-i+1); k<=(col+(length-i)); k++) {
				if (k==col) {
					// disregards column bc letters can be there
				}
				else if (board[n][k] != key) {
					return place_failure;
				}
			}
		}
	// Checking the endpoints of the word
		if ((board[row][col-i] != key) || (board[row][col+(length-i)+1] != key)) {
			return place_failure;
		}
	return place_success;
}
int can_place_word_vert(char * word, char board[15][15], int row, int col, int i, int length) {

	char key= '.';
        int n,k;
	
	// Checking against height of the board
		if ((length-i) > (15-row) || ((row-i+1)< 0)) {
                        return place_failure;
                }
	// Checking immediently to the left through immedietly to the right of potenital place for word
		for (n=(col-1); n<=(col+1); n++) {
                        for (k=(row-i+1); k<=(row+(length-i)); k++) {
                                if (k==row) {
                                        // disregards column bc letters can be there
                                }
                                else if (board[k][n] != key) {
					return place_failure;
				}
			}
		}
	// Checking the enpoints of the word
		if ((board[row-i][col] != key) || (board[row+(length-i+1)][col] != key)) {
                        return place_failure;
                }
        return place_success;
}
