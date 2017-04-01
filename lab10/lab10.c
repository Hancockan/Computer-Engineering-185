// Lab 10 ExTalker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 1   // set to 0 to disable debug output

// reads words from the file
// into wl and trims the whitespace off of the end
int readWords(char* wl[MAXWORDS], char* filename); 

//modifies s to trim white space off the right side
void trimws(char* s) ;

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	char sentence[1000][1000];
	char currentWord[100][100];
	int sentenceLength = 0;
	int characterNumber = 0;
	int sentenceWordNum = 0;
	int wordLength = 0;
	int wordLength2 = 0;
	int wordCount;
	int wordNumber = 0;
	int timer = 0;
	int spaceOrNot = 0;
	int WordIncrement = 0;
	int rows = 1, cols = 0;
	int i, b1, b2, b3, b4, b5, b6, t, j1, j2, j3, j4, j5 = 0, j6, w;
	wordCount = readWords(wordlist, argv[1]);

	if (DEBUG) {
		printf("Read %d words from %s \n",wordCount, argv[1]);
		for (i = 0; i< wordCount; i++) {
			printf("%s,", wordlist[i]);

			}
		printf("\n");
		}
	scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4, &b5, &b6, &j1, &j2, &j3, &j4, &j5, &j6);
	initscr();
	refresh();
	//printf("\n%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", t, b1, b2, b3, b4, b5, b6, j1, j2, j3, j4, j5, j6);
	while(b5 == 0){
	scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4, &b5, &b6, &j1, &j2, &j3, &j4, &j5, &j6);
	//printf("\n%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", t, b1, b2, b3, b4, b5, b6, j1, j2, j3, j4, j5, j6);
	
		while(WordIncrement < wordCount){
		
			cols += 16;
		
			mvprintw(rows, cols, wordlist[WordIncrement]);
			refresh();
		
			if(cols > 76){
				cols = 0;
				rows+=2;
				}	
		
			WordIncrement++;
			mvprintw(rows, cols -1, " ");
			refresh();
			}
				
			
			
			//printf("\n%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", t, b1, b2, b3, b4, b5, b6, j1, j2, j3, j4, j5, j6);
	
		if((timer > 70) && (j2 == 1) && (rows > 2)){
				rows = rows - 2;
				mvprintw(rows, cols - 1, " ");
				refresh();
				timer = 0;
			}
			
		if((timer > 70) && (j1 == 1) && (rows < ((wordCount / 5) * 2))){
			rows = rows + 2;
			mvprintw(rows, cols - 1, " ");
			refresh();
			timer = 0;
			}
			
		if((timer > 70) && (j4 == 1) && (cols < 70)){
			cols = cols + 16;
			mvprintw(rows, cols - 1, " ");
			refresh();
			timer = 0;
			}
			
		if((timer > 70) && (j3 == 1) && (cols > 16)){
			cols = cols - 16;
			mvprintw(rows, cols - 1, " ");
			refresh();
			timer = 0;
			}
			
		if((b3 == 1) && (timer > 70)){
			wordNumber = (5 * ((rows - 1) / 2) + (cols / 16) - 1);
			if(wordNumber > 75){
				wordNumber = 75;
			}
			strcpy(currentWord, wordlist[wordNumber]);
			strcpy(sentence[sentenceWordNum], currentWord);

			wordLength = strlen(currentWord);
			
			mvprintw(50, 0 + characterNumber, currentWord);
			characterNumber = characterNumber + wordLength;
			
			sentenceWordNum++;
			
			refresh();
			timer = 0;
		}
		
		if((b2 == 1) && (timer > 70)){
			wordNumber = (5 * ((rows - 1) / 2) + (cols / 16) - 1);
			if(wordNumber > 75){
				wordNumber = 75;
			}
			strcpy(currentWord, wordlist[wordNumber]);
			strcpy(sentence[sentenceWordNum + 1], currentWord);
			stpcpy(sentence[sentenceWordNum], " ");
			
			wordLength = strlen(currentWord);
			
			mvprintw(50, 0 + characterNumber, " ");
			refresh();
			mvprintw(50, 0 + characterNumber + 1, currentWord);
			characterNumber = characterNumber + wordLength + 1;
			
			sentenceWordNum+=2;;
			
			refresh();
			timer = 0;
		}
		
		if((b1 == 1) && (timer > 70)){
			sentenceWordNum--;
			//stpcpy(sentence[sentenceWordNum], "");
			//int wordlength3 = strlen(sentence[sentenceWordNum - 3]);
			wordLength2 = strlen(sentence[sentenceWordNum - 2]);
			wordLength = strlen(sentence[sentenceWordNum + 1]);
			if(strcmp(" ", sentence[sentenceWordNum - 1]) != 0){// no space
				mvprintw(50, characterNumber - wordLength, "           ");
				mvprintw(50, (characterNumber - wordLength - wordLength2), sentence[sentenceWordNum - 1]);
				characterNumber = characterNumber - wordLength;
			}
			if(strcmp(" ", sentence[sentenceWordNum - 1]) == 0){
				
				
				
				
				for(wordLength;wordLength > 0;wordLength--){
					mvprintw(50, characterNumber - wordLength, " ");
					refresh();
					characterNumber--;
				}
				/*
				//mvprintw(50, characterNumber - wordLength - 1, "           ");
				char currentWord2[100] = "";
				strcpy(currentWord2, sentence[sentenceWordNum - 2]);
				
				mvprintw(50, characterNumber - (wordLength + wordLength2), "          ");
				//mvprintw(50, (characterNumber - (wordLength + wordLength2)), sentence[sentenceWordNum - 2]);
				characterNumber = characterNumber - wordLength - 1;
				*/
				
				
			}
			
			timer = 0;
			refresh();
		}
			
		timer++;
		refresh();
		}
	endwin();
}

void trimws(char* s) {
        int len = strlen(s) ;
        int x;
        if (len ==0) return;
        x = len-1;
        while (isspace(s[x]) && (x>=0)) {
                s[x] = '\0';
                x--;
                }
        }



int readWords(char* wl[MAXWORDS], char* filename) {
	int numread =0;
	char line[WORDLEN];
	char *p;
	FILE* fp = fopen(filename,"r");
	if(fp == NULL)
	{
		perror("fopen()");
		return 0;
	}
	while (!feof(fp)) {
		p  =fgets(line, WORDLEN, fp);
		if (!feof(fp) && p !=NULL) {
			trimws(line);
			wl[numread] = (char *)  malloc(strlen(line)+1);
			strcpy(wl[numread], line);
			numread++;
			}
		} 
	fclose(fp);
	return numread;	
	}
