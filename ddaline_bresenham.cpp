#include <iostream>
#include <graphics.h>
#include <math.h>
#include <conio.h>  
using namespace std;
void drawCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int P = 3 - 2 * r;
    while (x <= y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        if (P < 0) {
            P += 4 * x + 6;
        } else {
            P += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}
void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float x_inc = dx / (float)steps;
    float y_inc = dy / (float)steps;
    float x = x1;
    float y = y1;
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += x_inc;
        y += y_inc;
    }
}
int main() {
    int xc, yc, r;
    cout << "Enter center coordinates of circle (xc, yc) and radius: ";
    cin >> xc >> yc >> r;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    // Draw the main circle
    drawCircle(xc, yc, r);
    // Draw the equilateral triangle inside the circle
    int x1 = xc, y1 = yc - r;
    int x2 = xc - r * sqrt(3) / 2, y2 = yc + r / 2;
    int x3 = xc + r * sqrt(3) / 2, y3 = yc + r / 2;
    // Draw the equilateral triangle
    drawLineDDA(x1, y1, x2, y2);
    drawLineDDA(x2, y2, x3, y3);
    drawLineDDA(x3, y3, x1, y1);
    // Draw a smaller circle inside the larger circle
    drawCircle(xc, yc, r / 2);
    getch();  
    closegraph();
    return 0;
}
