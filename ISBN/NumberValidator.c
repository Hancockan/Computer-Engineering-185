#include <stdio.h>
#include <string.h>

void scanISBN(int BookNumbers[10]);
int isValidISBN(int BookNumbers[10]);


int BookNumbers[10];
char Number[50] = "";

int main(){

int ArrayElements = 0;
int k = 0,m = 0;

scanf("%d", &ArrayElements);

scanISBN(BookNumbers);

for(k = 0;k < 10;k++){
	
	Number[50] = BookNumbers[k];
	
	
	printf("%s", Number);
	
	}

}

void scanISBN(int BookNumbers[10]){
	
	int i = 0;
	
	for(i = 0;i < 10;i++){
			
		scanf("%d", &(BookNumbers[i]));
		
	}

}

int isValidISBN(int BookNumbers[10]){
	

	
}

