#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct {
    int x;
    int y;
} Point;

int main() {
    Point snake = {WIDTH / 2, HEIGHT / 2};
    char direction = 'd'; // 初始方向向右

    while (1) {
        system("clear"); // 清空屏幕
	// 绘制蛇
	printf("*");

	// 接收用户输入
	struct termios oldattr, newattr;
        tcgetattr(STDIN_FILENO, &oldattr);
        newattr = oldattr;
        newattr.c_lflag &= ~(ICANON | ECHO); // 禁用标准模式和回显
        tcsetattr(STDIN_FILENO, TCSANOW, &newattr);

        char input = getchar();
        if (input == 'w' || input == 'a' || input == 's' || input == 'd') {
            direction = input;
        }

        tcsetattr(STDIN_FILENO, TCSANOW, &oldattr); // 恢复控制台设置

	// 更新蛇的位置
	switch (direction) {
            case 'w': snake.y--; break;
            case 'a': snake.x--; break;
            case 's': snake.y++; break;
            case 'd': snake.x++; break;
        }

        // 暂停一会儿
        usleep(100000); // 100 毫秒
    }
    return 0;
}
