#include <iostream>
#include <cstdio>

using namespace std;

void drawline(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;
    dx=x1-x0;
    dy=y1-y0;
    x=x0;
    y=y0;
    p=2*dy-dx;
    cout <<"(x, y): ("<< x << " " << y << ") p:";
    cout << p <<"\n";
    while(x<x1)
    {
        if(p>=0)
        {
            y = y + 1;
            x = x + 1;
            p=p+2*dy-2*dx;
            cout <<"(x, y): ("<< x << " " << y << ") p:";
            cout << p <<"\n";
        }
        else
        {
            x = x + 1;
            p=p+2*dy;
            cout <<"(x, y): ("<< x << " " << y << ") p:";
            cout << p <<"\n";
        }

    }
    cout << "Bresenham line drawing. Only if 0 < K < 1";
}

int main() {
    int x0,y0,x1,y1;
    cout << "input form: x0 y0 x1 y1." <<"\n";
    cin >>x0 >> y0 >> x1 >> y1;

    drawline(x0,y0,x1,y1);
}
