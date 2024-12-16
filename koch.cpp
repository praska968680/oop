#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

void drawKochCurve(int x1, int y1, int x2, int y2, int order) {
    if (order == 0) {
        line(x1, y1, x2, y2);
    } else {
        // Calculate the new points dividing the line segment into three equal parts
        int x3 = (2 * x1 + x2) / 3;
        int y3 = (2 * y1 + y2) / 3;
        int x4 = (x1 + 2 * x2) / 3;
        int y4 = (y1 + 2 * y2) / 3;

        // Calculate the position of the peak of the equilateral triangle
        int x5 = x3 + (x4 - x3) * cos(M_PI / 3) - (y4 - y3) * sin(M_PI / 3);
        int y5 = y3 + (x4 - x3) * sin(M_PI / 3) + (y4 - y3) * cos(M_PI / 3);

        // Recursively draw the four line segments
        drawKochCurve(x1, y1, x3, y3, order - 1);
        drawKochCurve(x3, y3, x5, y5, order - 1);
        drawKochCurve(x5, y5, x4, y4, order - 1);
        drawKochCurve(x4, y4, x2, y2, order - 1);
    }
}

int main() {

	initwindow(800,800,"graphics");

    int x1, y1, x2, y2, order;

    cout << "Enter the starting point (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter the ending point (x2 y2): ";
    cin >> x2 >> y2;

    cout << "Enter the order of the Koch curve: ";
    cin >> order;

    drawKochCurve(x1, y1, x2, y2, order);

    getch();
    closegraph();

    return 0;
}

