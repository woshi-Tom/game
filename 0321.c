#include <stdio.h>
#include <curses.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct {
    int x;
    int y;
} Point;

int snakeLength = 1;
Point snake[WIDTH * HEIGHT];
Point food;
char direction = 'd'; 
void updateSnake() {
    int i;
    // 移动蛇身
    for (i = snakeLength - 1; i > 0; i--) {
    	snake[i] = snake[i - 1];
     }              
    // 根据当前方向移动蛇头
    switch (direction) {
	case 'w': snake[0].y--; break;
	case 's': snake[0].y++; break;
	case 'a': snake[0].x--; break;
	case 'd': snake[0].x++; break;
    }
}

void draw() {
    int i;
    // 绘制蛇身
    for (i = 0; i < snakeLength; i++) {
        printf("%c", (i == 0) ? '*' : '+'); // 头部用 * 表示，身体用 + 表示
    }
}

void gameLoop(){
    while(2){
	updateSnake();
	system("cls");
	draw();
	sleep(100);
	if(_kbhit()){
	    direction = _getch();
	}
    }
}

int main() {
    // 初始化蛇和食物位置
    snake[0].x = WIDTH / 2;
    snake[0].y = HEIGHT / 2;
    food.x = rand() % WIDTH;
    food.y = rand() % HEIGHT;
    gameLoop();
    return 0;
}
