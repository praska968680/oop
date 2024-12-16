#include <graphics.h>
#include <conio.h>
#include <dos.h>
void drawMan(int x, int y) {
	setcolor(WHITE);
    circle(x, y, 15);
    line(x, y + 15, x, y + 60);
    line(x, y + 30, x - 20, y + 50);
    line(x, y + 30, x + 20, y + 10);
    line(x, y + 60, x - 15, y + 100);
    line(x, y + 60, x + 15, y + 100);
    line(x - 15, y + 100, x - 25, y + 110);
    line(x + 15, y + 100, x + 25, y + 110);
    circle(x-7, y, 3);
    circle(x+7, y, 3);
    arc(x, y, 225, 315, 10);
}
void drawUmbrella(int x, int y) {
	setcolor(YELLOW);
    line(x + 20, y + 10, x + 20, y - 50);
    arc(x + 20, y - 50, 0, 180, 40);
    line(x - 20, y - 50, x + 60, y - 50);
}
void drawRain() {
	setcolor(LIGHTBLUE);
    for (int i = 0; i < 100; i++) {
        int x = rand() % getmaxx();  
        int y = rand() % getmaxy();  
        line(x, y, x, y + 10);       
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int x = 100, y = 200;
    while (!kbhit()) {
        cleardevice();
        drawMan(x, y);
        drawUmbrella(x, y);
        drawRain();
        delay(100);
        x += 5;
        if (x > getmaxx()) {
            x = 0;
        }
    }
    getch();
    closegraph();
    return 0;
}
