#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>

typedef struct{
	int i;
	int velocity;
}game_stat;

typedef struct{
	int x,y;
	char key;
}ring;

typedef struct{
	int size;
	ring* body;
}snake;

// global variables
int rows,cols;
game_stat stat;



int is_barrer(int x,int y){
	if(x==0 || x==cols || y==rows-1 || y==0)
		return 1;
	return 0;
}
#include "snake_movement.c"

void print_matrix(snake cobra){
	int i,j;
	int r,is_space=-1;

	system("clear");
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			is_space=1;
			if(i==rows-1 || i==0 || j==0){
				is_space=0;
				printf("#");
			}

			for(r=0;r<cobra.size;r++)
				if(cobra.body[r].x==j && cobra.body[r].y==i){
					printf("%c",cobra.body[r].key);
					is_space=0;
					}
			if(is_space==1)printf(" ");

		}
		printf("#\n");
	}
	printf("Itaration # %d\n",stat.i);
}

void init_snake(snake *cobra){
	// default size = 6
	int def_size=6,i;
	cobra->size=6;
	cobra->body=malloc(sizeof(ring)*def_size);
	for(i=0;i<def_size;i++){
		cobra->body[i].x=3+i;
		cobra->body[i].y=3;
		if(i==0)
			cobra->body[i].key='@';
		else cobra->body[i].key='~';
	}
}

int main(int argc,char **argv){
	snake cobra;
	int i;
	struct winsize w;

	stat.i=0;
	if(argc>1)
		stat.velocity=atoi(argv[1]);

	else stat.velocity=1;
	ioctl(0, TIOCGWINSZ, &w);
	rows=w.ws_row-5;
	cols=w.ws_col-1;

	init_snake(&cobra);

	stat.i=0;
	while(1){
		print_matrix(cobra);
		sleep(stat.velocity);
		if(stat.i<2)
			go_left(cobra);
		else if(stat.i<4)
			go_right(cobra);
		else if(stat.i<10)
			go_up(cobra);
		else if(stat.i<18)
			go_right(cobra);
		else go_bottom(cobra);
		stat.i++;
	}

return 0;
}
