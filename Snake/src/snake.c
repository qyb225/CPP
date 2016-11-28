#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SNAKE_MAX_LENGTH 65
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define SNAKE_FOOD '$'
#define SNAKE_CELL ' '
#define WALL_CELL '+'
#define OVER "GAME OVER!"
#define SIZE 21

void snakeMove(int,int);
void put_money(void);
void output(void);
void gameover(void);
void gamestart(void);
void win(void);
char ai(int y,int x);
void wChoose(void);

char map[SIZE][SIZE] = 
	{"********************",
	"*XXXXH             *",
	"*                  *",
	"*                  *",
	"*                  *",
	"*                  *",
	"*                  *",
	"*                  *",
	"*                  *",
	"*                  *",
	"*                  *",
	"*                  *",
	"*                  *",
	"*                  *",
	"*                  *",
	"*                  *",
	"*                  *",
	"*                  *",
	"*                  *",
	"********************"
	};
	
int snakeX[SNAKE_MAX_LENGTH] = {1,2,3,4,5};
int snakeY[SNAKE_MAX_LENGTH] = {1,1,1,1,1};
int snakeLength = 5;
int eat = 0;
int foodX,foodY;
int choose = 0;
int score = 0;

int main(void) {
	char mLetter,p,q;
	int x,y;
	if (choose == 0) {
	printf("\n\nYou can choose two different mode:\n");
	printf("\n1.Play now!\n");
	printf("\n2.AI\n\n");
	scanf("%d",&choose);
	scanf("%c",&q);
	}
	if (choose == 3) {
		choose = 0;
		main();
		wChoose();
	}
	put_money();
	gamestart();
	output();
	if (choose == 1) {
		scanf("%c",&mLetter);
		scanf("%c",&p);
	}
	else if (choose == 2) {
		mLetter = ai(snakeY[snakeLength - 1],snakeX[snakeLength - 1]);
	}
	
	switch(mLetter) {
		case 'w' :
			y = -1;
			x = 0;
			break;
			case 'W' :
			y = -1;
			x = 0;
			break;
		case 's' :
			y = 1;
			x = 0;
			break;
			case 'S' :
			y = 1;
			x = 0;
			break;
		case 'a' :
			y = 0;
			x = -1;
			break;
			case 'A' :
			y = 0;
			x = -1;
			break;
		case 'd' :
			y = 0;
			x = 1;
			break;
			case 'D' :
			y = 0;
			x = 1;
			break;
		default:
			x = 0;
			y = 0;
			break;
	}	
					
	snakeMove(y,x);
	
	return 0;
}

void snakeMove(int dy,int dx) {
	int judge = 0,i,j;
	
	if (map[snakeY[snakeLength-1] + dy][snakeX[snakeLength-1] + dx] == SNAKE_CELL) {
		map[snakeY[0]][snakeX[0]] = SNAKE_CELL;
		map[snakeY[snakeLength-1]][snakeX[snakeLength-1]] = SNAKE_BODY;
		for (i = 0; i < snakeLength - 1; i++) {
			snakeY[i] = snakeY[i+1];
			snakeX[i] = snakeX[i+1];
		}
		snakeY[snakeLength - 1] += dy;
		snakeX[snakeLength - 1] += dx;
		map[snakeY[snakeLength-1]][snakeX[snakeLength-1]] = SNAKE_HEAD;
	}
	else if (map[snakeY[snakeLength-1] + dy][snakeX[snakeLength-1] + dx] == SNAKE_FOOD) {
		snakeLength += 1;
		if (snakeLength > SNAKE_MAX_LENGTH) {
			win();
		}
		else {
			snakeY[snakeLength - 1] = snakeY[snakeLength - 2] + dy;
			snakeX[snakeLength - 1] = snakeX[snakeLength - 2] + dx;
			map[snakeY[snakeLength - 2]][snakeX[snakeLength - 2]] = SNAKE_BODY;
			map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = SNAKE_HEAD;
			eat = 0;
		}	
	}
	else {
		gameover();
		judge = 1;
	}	
	if (judge == 0) {
		main();
	}
}
void gameover(void) {
	printf(" %s\n",OVER);
	system("pause");
}
void output(void) {
	int i,j;
	for (i = 0; i < SIZE; i++) {
			for (j = 0; j < SIZE; j++) {
				printf("%c",map[i][j]);
			}
			printf("\n");
	}
	printf("\nSCORE: %d\n",score - 1);
	i = 0;
	while(i < 70000000) {
		i++;
	}
	
}
void put_money(void) {

	int x = 0,y = 0;
	int i,j;
	int k;
	k += 500;
	if (eat == 0) {
		while (map[y][x] != SNAKE_FOOD) {
			srand(time(0));
			x = rand() % (SIZE - 1);
			srand((unsigned) clock());
			y = rand() % (SIZE - 1);
			if (map[y][x] != SNAKE_CELL) {
				continue;		
			}
			else {
				score += 1;
				map[y][x] = SNAKE_FOOD;
				foodX = x;
				foodY = y;
			}
			eat = 1;
		}	
	}	
}
void gamestart(void) {
	printf("Please use 'W' 'A' 'S' 'D' \n");
	printf("Then press Enter to control your snake.\n");//
}
void win(void) {
	printf("  YOU WIN!\n");
}

char ai(int y,int x) {
	int up,down,left,right;
	int u,d,l,r;
	char control;
	int i,j;
	int count = 0;
	up = down = left = right = 0;
	if (x - 4 >= 1) {
		l = x - 4;
	}
	else {
		l = 1;
	}
	if (SIZE - 1 - x <= 5) {
		r = SIZE - 2;
	}
	else {
		r = x + 4;
	}
	if (y - 4 >= 1) {
		u = y - 4;
	}
	else {
		u = 1;
	}
	if (SIZE - 1 - y <= 5) {
		d = SIZE - 2;
	}
	else {
		d = y + 4;
	}
	for (i = u; i <= y; i++) {
		for (j = l; j <= r; j++) {
			if (map[i][j] == SNAKE_BODY) {
				up += 1;
			}
		}
	}
	for (i = y; i <= d; i++) {
		for (j = l; j <= r; j++) {
			if (map[i][j] == SNAKE_BODY) {
				down += 1;
			}
		}
	}
	for (i = l; i <= x; i++) {
		for (j = u; j <= d; j++) {
			if (map[j][i] == SNAKE_BODY) {
				left += 1;
			}
		}
	}
	for (i = x; i <= r; i++) {
		for (j = u; j <= d; j++) {
			if (map[j][i] == SNAKE_BODY) {
				right += 1;
			}
		}
	}
	if (y > foodY) {
		if (x > foodX) {
			if (down >= up) {
				if (right >= left) {
					if ((down - up) >= (right - left)) {
						if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
							control = 'a';
						}
						else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 'w';
						}
						else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 's';
						}
						else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
							control = 'd';
						}
					}
					else {
						if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 'w';
						}
						if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
							control = 'a';
						}
						else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
							control = 'd';
						}
						else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 's';
						}
					}
				}
				else {
					if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 'w';
					}
					else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
						control = 'd';
					}
					else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
						control = 'a';
					}
					else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 's';
					}
				}
			}
			else {
				if (right >= left) {
					if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
						control = 'a';
					}
					else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 's';
					}
					else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 'w';
					}
					else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
						control = 'd';
					}
				}
				else {
					if ((up - down) >= (left - right)) {
						if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
							control = 'd';
						}
						else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 's';
						}
						else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 'w';
						}
						else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
							control = 'a';
						}
					}
					else {
						if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 's';
						}
						else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
							control = 'd';
						}
						else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
							control = 'a';
						}
						else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 'w';
						}
					}
				}
			}
		}
		else {
			if (down >= up) {
				if (right >= left) {
					if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 'w';
					}
					else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
						control = 'a';
					}
					else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
						control = 'd';
					}
					else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 's';
					}
				}
				else {
					if ((down - up) >= (left - right)) {
						if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
							control = 'd';
						}
						else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 'w';
						}
						else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 's';
						}
						else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
							control = 'a';
						}
					}
					else {
						if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 'w';
						}
						if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
							control = 'd';
						}
						else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
							control = 'a';
						}
						else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 's';
						}
					}
				}
			}
			else {
				if (right >= left) {
					if ((up - down) >= (right - left)) {
						if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
							control = 'a';
						}
						else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 's';
						}
						else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 'w';
						}
						else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
							control = 'd';
						}			
					}
					else {
						if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 's';
						}
						if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
							control = 'a';
						}
						else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
							control = 'd';
						}
						else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 'w';
						}
					}
				}
				else {
					if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
						control = 'd';
					}
					else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 's';
					}
					else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 'w';
					}
					else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
						control = 'a';
					}
				}
			}
		}
	}
	else if (y < foodY) {
		if (x > foodX) {
			if (up >= down) {
				if (right >= left) {
					if ((up - down) >= (right - left)) {
						if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
							control = 'a';
						}
						else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 's';
						}
						else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 'w';
						}								
						else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
							control = 'd';
						}
					}
					else {
						if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 's';
						}
						else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
							control = 'a';
						}
						else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
							control = 'd';
						}
						else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 'w';
						}
					}
				}
				else {
					if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 's';
					}
					else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
						control = 'd';
					}
					else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
						control = 'a';
					}
					else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 'w';
					}
				}
			}
			else {
				if (right >= left) {
					if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
						control = 'a';
					}
					else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 'w';
					}
					else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 's';
					}
					else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
						control = 'd';
					}
				}
				else {
					if ((down - up) >= (left - right)) {
						if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
							control = 'd';
						}
						else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 'w';
						}
						else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 's';
						}
						else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
							control = 'a';
						}
					}
					else {
						if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 'w';
						}
						else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
							control = 'd';
						}
						else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
							control = 'a';
						}
						else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 's';
						}
					}
				}
			}
		}
		else {
			if (up >= down) {
				if (left >= right) {
					if ((up - down) >= (left - right)) {
						if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
							control = 'd';
						}
						else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 's';
						}
						else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 'w';
						}	
						else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
							control = 'a';
						}
					}
					else {
						if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 's';
						}
						else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
							control = 'd';
						}
						else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
							control = 'a';
						}
						else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 'w';
						}
					}
				}
				else {
					if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 's';
					}
					else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
						control = 'a';
					}
					else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
						control = 'd';
					}
					else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 'w';
					}
				}
			}
			else {
				if (left >= right) {
					if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
						control = 'd';
					}
					else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 'w';
					}
					else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 's';
					}
					else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
						control = 'a';
					}
				}
				else {
					if ((right - left) <= (down - up)) {
						if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
							control = 'a';
						}
						else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 'w';
						}
						else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 's';
						}
						else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
							control = 'd';
						}
					}
					else {
						if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 'w';
						}
						else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
							control = 'a';
						}
						else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
							control = 'd';
						}
						else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
							control = 's';
						}
					}
				}
			}
		}
	}
	else {/////////////////////////////////////////////////////////////////////////////
		if (x <= foodX) {
			for (i = x; i < foodX; i++) {
				if (map[y][i] == SNAKE_BODY) {
					count += 1;
				}			
			}
			if (0 == count) { //else!
				if (left >= right) {
				if (up >= down) {
					if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
						control = 'd';
					}
					else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 's';
					}
					else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 'w';
					}
					else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
						control = 'a';
					}
				}
				else {
					if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
						control = 'd';
					}
					else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 'w';
					}
					else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 's';
					}
					else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
						control = 'a';
					}
				}
			}
			else {
				if (up >= down) {
					if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
						control = 'd';
					}	
					else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 's';
					}
					else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
						control = 'a';
					}
					else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 'w';
					}			
				}
				else {
					if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
						control = 'd';
					}
					else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 'w';
					}
					else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 's';
					}
					else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
						control = 'a';
					}			
				}
			}
			}
						else { //
				if (up >= down) {
					if (left >= right) {
						if ((up - down) >= (left - right)) {
							if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
								control = 'd';
							}
							else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 's';
							}
							else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 'w';
							}
							else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
								control = 'a';
							}
						}
						else {
							if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 's';
							}
							else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
								control = 'd';
							}
							else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
								control = 'a';
							}
							else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 'w';
							}
						}
					}
					else {
						if ((up - down) >= (right - left)) {
							if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
								control = 'a';
							}
							else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 's';
							}
							else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 'w';
							}
							else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
								control = 'd';
							}
						}
						else {
							if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 's';
							}
							else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
								control = 'a';
							}
							else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
								control = 'd';
							}
							else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 'w';
							}
						}
					}
				}
				else {
					if (left >= right) {
						if ((down - up) >= (left - right)) {
							if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
								control = 'd';
							}
							else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 'w';
							}
							else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 's';
							}
							else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
								control = 'a';
							}
						}
						else {
							if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 'w';
							}
							else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
								control = 'd';
							}
							else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
								control = 'a';
							}
							else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 's';
							}
						}
					}
					else {
						if ((down - up) >= (right - left)) {
							if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
								control = 'a';
							}
							else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 'w';
							}
							else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 's';
							}
							else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
								control = 'd';
							}
						}
						else {
							if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 'w';
							}
							else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
								control = 'a';
							}
							else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
								control = 'd';
							}
							else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 's';
							}
						}
					}
					
				} 
		}
			
		}
		else {
			for (i = foodX; i < x; i++) {
				if (map[y][i] == SNAKE_BODY) {
					count += 1;
				}			
			}
			if (count == 0) {
				if (left <= right) {
				if (up >= down) {
					if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
						control = 'a';
					}
					else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 's';
					}
					else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 'w';
					}
					else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
						control = 'd';
					}
				}
				else {
					if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
						control = 'a';
					}
					else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 'w';
					}
					else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 's';
					}
					else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
						control = 'd';
					}
				}
			}
			else {
				if (up >= down) {
					if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
						control = 'a';
					}		
					else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 's';
					}
					else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
						control = 'd';
					}
					else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 'w';
					}
				}
				else {
					if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
						control = 'a';
					}
					else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 'w';
					}
					else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
						control = 'd';
					}
					else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
						control = 's';
					}
				}
			}
			}
			else { //
				if (up >= down) {
					if (left >= right) {
						if ((up - down) >= (left - right)) {
							if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
								control = 'd';
							}
							else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 's';
							}
							else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 'w';
							}
							else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
								control = 'a';
							}
						}
						else {
							if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 's';
							}
							else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
								control = 'd';
							}
							else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
								control = 'a';
							}
							else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 'w';
							}
						}
					}
					else {
						if ((up - down) >= (right - left)) {
							if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
								control = 'a';
							}
							else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 's';
							}
							else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 'w';
							}
							else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
								control = 'd';
							}
						}
						else {
							if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 's';
							}
							else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
								control = 'a';
							}
							else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
								control = 'd';
							}
							else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 'w';
							}
						}
					}
				}
				else {
					if (left >= right) {
						if ((down - up) >= (left - right)) {
							if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
								control = 'd';
							}
							else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 'w';
							}
							else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 's';
							}
							else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
								control = 'a';
							}
						}
						else {
							if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 'w';
							}
							else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
								control = 'd';
							}
							else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
								control = 'a';
							}
							else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 's';
							}
						}
					}
					else {
						if ((down - up) >= (right - left)) {
							if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
								control = 'a';
							}
							else if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 'w';
							}
							else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 's';
							}
							else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
								control = 'd';
							}
						}
						else {
							if (map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] - 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 'w';
							}
							else if(map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] - 1] == SNAKE_FOOD) {
								control = 'a';
							}
							else if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_CELL || map[snakeY[snakeLength-1]][snakeX[snakeLength-1] + 1] == SNAKE_FOOD) {
								control = 'd';
							}
							else if (map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_CELL || map[snakeY[snakeLength-1] + 1][snakeX[snakeLength-1]] == SNAKE_FOOD) {
								control = 's';
							}
						}
					}
					
				}
			}
		}
	}
	return control;
}
void wChoose(void) {
	printf("You cannot choose this one.\n");
	printf("Please choose another.\n");
}
