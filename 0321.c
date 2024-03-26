#include <stdio.h>
#include <conio.h>

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
    // 移动蛇身
    for (int i = snakeLength - 1; i > 0; i--) {
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
