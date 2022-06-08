#include <iostream>

using namespace std;

struct cirCle{
    float x;
    float y;
};

cirCle circle1[200];

int midpointCircle(float x, float y, float r, cirCle *circle1)
{
    float d = 1 - r, d1 = 3, d2 = 5 - 2 * r;
    float x0 = 0 , y0 = r ;
    cout  << "scan:\n"<< "x:" << x0 << " " << "y:"<< y0 << " " << "d:" << d << " " << "d1:" << d1 << " " << "d2:" << d2 << " " << "\n";
    circle1[0].x = x0;
    circle1[0].y = y0;
    int count = 1;
    while(x0 < y0)
    {
        if(d < 0)
        {
            d = d + d1;
            x0 = x0 + 1;
            d1 = d1 + 2;
            d2 = d2 + 2;
            cout << "x:" << x0 << " " << "y:"<< y0 << " " << "d:" << d << " " << "d1:" << d1 << " " << "d2:" << d2 << " " << "\n";
            circle1[count].x = x0;
            circle1[count].y = y0;
            count ++;
        }
        else
        {
            d = d + d2;
            y0 = y0 - 1;
            x0 = x0 + 1;
            d1 = d1 + 2;
            d2 = d2 + 4;
            cout << "x:" << x0 << " " << "y:"<< y0 << " " << "d:" << d << " " << "d1:" << d1 << " " << "d2:" << d2 << " " <<"\n";
            circle1[count].x = x0;
            circle1[count].y = y0;
            count ++;
        }
    }
        return count;
}
int main() {

    int x, y, r;
    cout << "input form: x y r."<<"\n";
    cin >>x >> y >> r;


    int c = midpointCircle(x, y, r, circle1);

    for(int i = c; i < 2 * c; i ++)
    {
        circle1[i].y = circle1[i - c].x;
        circle1[i].x = circle1[i - c].y;
    }
    for(int i = 2 * c; i < 4 * c; i ++)
    {
        circle1[i].y = circle1[i - 2 * c].y;
        circle1[i].x = -circle1[i - 2 * c].x;
    }

    for(int i = 4 * c; i < 8 * c; i ++)
    {
        circle1[i].y = -circle1[i - 4 * c].y;
        circle1[i].x = circle1[i - 4 * c].x;
    }
    cout << "transform:\n";
    for(int i = 0; i < 8*c; i ++)
    {
        circle1[i].y = circle1[i].y + y;
        circle1[i].x = circle1[i].x + x;

        if(circle1[i].y > 0 && circle1[i].x > 0)
        cout << "(" << circle1[i].x << " " <<circle1[i].y << ")";
    }
}
