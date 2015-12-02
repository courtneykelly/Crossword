
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
int can_place_word(char [], char [][15], int, int, int);

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

	for(n=1; n<i; n++) {
	  if(placeWord(words[n], board)) {
	    //print word on board
	    printf("yes");
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
	   				//if(can_place_word(word,board,row,col,i)){
	   					return place_success;
	   				//}
	 			}
       			}
     		}
   	}
     	return place_failure;
 }
int can_place_word(char * word, char board[16][16], int row, int col, int i) {

  	char key= '.';
  	//Ensure length of word does not exceed length/width of board
  	// horizontal
     		// second half of word
  			int n;
        		for (n=col; n<=(length-i); n++) {
            			if (board[row][n]==key) {
         			}
			}
		// first half of word
		// above word row-1
		// below word row+1
	// vertical
		// second half of the word 
		// first half of the word
		// left of word col-l
		// right of word col+1
}

