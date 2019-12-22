#include <stdio.h>

#define MAXMAZESIZE 20

#define NORTH	1
#define WEST	2
#define SOUTH	3
#define EAST	4

char maze[MAXMAZESIZE + 2][MAXMAZESIZE + 2];
int direction, posx, posy;
int sizex, sizey;

void read_maze(void)
{
	int r, x, y;
	printf("Please enter maze size: ");
	r = scanf("%d%d", &sizex, &sizey);
	if (r != 2 || sizex > MAXMAZESIZE || sizey > MAXMAZESIZE || sizex < 2 || sizey < 2) {
		printf("Invalid maze size\n");
		exit(1);
	}
	/* discard rest of line */
	while (getchar() == '\n');

	printf("Please input the maze.\n");
	for (y = 1; y <= sizey; y++){
		for (x = 1; x <= sizex; x++){
			maze[x][y] = getchar();
			if (maze[x][y] != '*' && maze[x][y] != ' '){
				printf("Invalid character in maze(%c)\n", maze[x][y]);
				exit(1);
			}
		}
		getchar(); /* ignore the end-of-line character */
	}
	/* initialize the path all around the maze */
	for (y = 0; y < sizey + 2; y++)
		maze[0][y] = maze[sizex + 1][y] = ' ';
	for (x = 1; x <= sizex; x++)
		maze[x][0] = maze[x][sizey + 1] = ' ';
}

void read_starting_point(void){
	int r;
	printf("Please enter starting point: ");
	r = scanf("%d%d", &posx, &posy);
	if (r != 2 || posx < 1 || posx > sizex || posy < 1 || posy > sizey || maze[posx][posy] != ' ' || (posx != sizex && posx != 1 && posy != sizey && posy != 1)){
		printf("Invalid starting point.\n");
		exit(1);
	}

	/* compute initial direction */
	if (posx == 1)
		direction = EAST;
	else if (posx == sizex)
		direction = WEST;
	else if (posy == 1)
		direction = SOUTH;
	else
		direction = NORTH;
}

void turn_left(void){
	if (direction == NORTH)
		direction = WEST;
	else if (direction == WEST)
		direction = SOUTH;
	else if (direction == SOUTH)
		direction = EAST;
	else/* direction == EAST */
		direction = NORTH;
}

void turn_right(void){
	if (direction == NORTH)
		direction = EAST;
	else if (direction == EAST)
		direction = SOUTH;
	else if (direction == SOUTH)
		direction = WEST;
	else /* direction == WEST */
		direction = NORTH;
}

/* return true if we are facing a wall, false otherwise */
int facing_wall(void){
	if (direction == NORTH)
		return maze[posx][posy - 1] == '*';
	else if (direction == WEST)
		return maze[posx - 1][posy] == '*';
	else if (direction == SOUTH)
		return maze[posx][posy + 1] == '*';
	else /* direction == EAST */
		return maze[posx + 1][posy] == '*';
}

/* return true if we are outside maze, false otherwise */
int outside_maze(void){
	return posx == 0 || posx == sizex + 1 || posy == 0 || posy == sizey + 1;
}

/* move one step from current position in current direction */
int step_forward(void){
	if (direction == NORTH)
		posy--;
	else if (direction == WEST)
		posx--;
	else if (direction == SOUTH)
		posy++;
	else /* direction == EAST */
		posx++;
}

void print_position(void){
	printf("(%d %d) ", posx, posy);
}

main(void){
	read_maze();
	read_starting_point();
	print_position();
	while (!outside_maze()){
		turn_right();
		while (facing_wall())
			turn_left();
		step_forward();
		print_position();
	}
	putchar('\n');
}
