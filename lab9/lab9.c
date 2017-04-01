// WII-MAZE Skeleton code written by Jason Erbskorn 2007
// Edited for ncurses 2008 Tom Daniels
//Updated for Esplora 2013 TeamRursch185


// Headers
#include <stdio.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>

// Mathematical constants
#define PI 3.14159

// Screen geometry
// Use ROWS and COLUMNS for the screen height and width (set by system)
// MAXIMUMS
#define COLUMNS 100
#define ROWS 80

// Character definitions taken from the ASCII table
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '

// Number of samples taken to form an average for the accelerometer data
// Feel free to tweak this.  You may actually want to use the moving averages
// code you created last week 
#define NUM_SAMPLES 10  


// 2D character array which the maze is mapped into
char MAZE[COLUMNS][ROWS];


// POST: Generates a random maze structure into MAZE[][]
//You will want to use the rand() function and maybe use the output %100.  
//You will have to use the argument to the command line to determine how 
//difficult the maze is (how many maze characters are on the screen).
void generate_maze(int difficulty){
	
	for(int i = 0;i < COLUMNS;i++){
		
		for(int j = 0;j < ROWS;j++){
			
			int AppearanceChance = (rand() % 100);
			if(AppearanceChance > difficulty){
				
				MAZE[i][j] = EMPTY_SPACE;
				
			}else{
				
				MAZE[i][j] = WALL;
				
			}
			
		}
		
	}
	
}

// PRE: MAZE[][] has been initialized by generate_maze()
// POST: Draws the maze to the screen 
void draw_maze(void){
	
	for(int i = 0;i < COLUMNS;i++){
		
		for(int j = 0;j < ROWS;j++){
			
			draw_character(i, j, MAZE[i][j]);
			
		}
		
	}
	
}

// PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
void draw_character(int x, int y, char use);

// PRE: -1.0 < y_mag < 1.0
// POST: Returns tilt magnitude scaled to -1.0 -> 1.0
// You may want to reuse the pitch function written in previous labs.  
float calc_pitch(float x_mag){
	
	double pitch = asin(x_mag);
	return pitch;
	
}

// Main - Run with './explore.exe -t -a -b' piped into STDIN
void main(int argc, char* argv[])
{
	int t, i = 0,L = 0,xCoord,WL = 0;
	double x, y, z, pitch;
	int difficulty = atoi(argv[1]); 
	
	xCoord = (COLUMNS/2);
	// setup screen    
	initscr();
	refresh();

	// Generate and draw the maze, with initial avatar
	generate_maze(difficulty);
	draw_maze();
	draw_character((COLUMNS/2), 0, AVATAR);
	// Read accelerometer data to get ready for using moving averages.    
	scanf("%d, %lf, %lf, %lf", &t, &x, &y, &z);
	
	// Event loop
	do
	{
		scanf("%d, %lf, %lf, %lf", &t, &x, &y, &z);
		// Read data, update average
		
		pitch = calc_pitch(x);//calculate pitch
		
		// Is it time to move?  if so, then move avatar
		if((i % 50) == 0){
			
			if(pitch < -0.5){//Right move
				if((MAZE[xCoord + 1][L] == EMPTY_SPACE) && (xCoord < COLUMNS)){//is the space clear and is there a wall
				xCoord = xCoord + 1;//update x coord
				}
			}else if(pitch > 0.5){//Left move
				if((MAZE[xCoord - 1][L] == EMPTY_SPACE) && (xCoord > 0)){// is the space clear and is there a wall
				xCoord = xCoord - 1;//update x coord
				}
			}
			draw_character(xCoord, L, AVATAR); //Place New Avatar
		
			if(((MAZE[xCoord + 1][L]) == WALL) && ((MAZE[xCoord - 1][L]) == WALL) && ((MAZE[xCoord][L+1]) == WALL)){//is the next space a bucket
				WL = 1;//sets win variable equal to 1 meaning a loss
				break;//break game loop
			}
			
			if(MAZE[xCoord][L + 1] == EMPTY_SPACE){//is the next space below clear
				L++;//add one row
			}
		}
		i++;	//timing for the loop to execute
		
	} while(L != 81); // checks to see if its at the bottom 

	// Print the win message
	endwin();
	if(WL == 0){//check to see if its a win
		printf("YOU WIN!\n");//announce a win
	}else if(WL == 1){//check to see if its a loss
		printf("YOU LOSE");//announce a loss
	}
}



// PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
//THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
//YOU DO NOT NEED TO CHANGE THIS FUNCTION.
void draw_character(int x, int y, char use)
{
	mvaddch(y,x,use);    
	refresh();
}


