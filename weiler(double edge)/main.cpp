#include <iostream>
#include <math.h>
using namespace std;

struct Ellipse{
    float x;
    float y;
};

Ellipse ellipseChan[2000];

int midpointEllipse(float a, float b, Ellipse *ellipStruct)
{
    float d1, d2;

    float x0 = 0 , y0 = b ;
    cout  << "scan:\n"<< "x:" << x0 << " " << "y:"<< y0 <<" " << "d1:" << d1 << " " << "d2:" << d2 << " " << "\n";
    ellipStruct[0].x = x0;
    ellipStruct[0].y = y0;
    d1 = b * b + a * a * (-b + 0.25);
    int count = 1;
    while(b * b * (x0 + 1) < a * a * (y0 - 0.5))
    {
        if(d1 < 0)
        {
            d1 += b * b * (2 * x0 + 3);
            x0 = x0 + 1;
            cout << "x:" << x0 << " " << "y:"<< y0 <<  "d1:" << d1 << " " << "d2:" << d2 << " " << "\n";
            ellipStruct[count].x = x0;
            ellipStruct[count].y = y0;
            count ++;
        }
        else
        {
            d1 += (b * b * (2 * x0 + 3) + a * a * (-2 * y0 + 2));
            y0 = y0 - 1;
            x0 = x0 + 1;

            cout << "x:" << x0 << " " << "y:"<< y0 << " " << "d1:" << d1 << " " << "d2:" << d2 << " " <<"\n";
            ellipStruct[count].x = x0;
            ellipStruct[count].y = y0;
            count ++;
        }
    }
    d2 = b * b *(x0 + 0.5) * (x0 + 0.5) + a * a * (y0 - 1) * (y0 - 1) - a * a * b * b;
    while (y0 > 0) {
        if (d2 < 0) {
            d2 += b * b * (2 * x0 + 2) + a * a * (-2 * y0 + 3);
            x0++;
            y0--;
        } else {
            d2 += a * a * (-2 * y0 + 3);
            y0--;
        }
        cout << "x:" << x0 << " " << "y:"<< y0 << " " << "d1:" << d1 << " " << "d2:" << d2 << " " <<"\n";
    }

    return count;
}
int main() {

    int x, y, a, b;
    cout << "input form: x y a b."<<"\n";
    cin >>x >> y >> a >> b;


    int c = midpointEllipse(a, b, ellipseChan);

    for(int i = c; i < 2 * c; i ++)
    {
        ellipseChan[i].y = ellipseChan[i - c].x;
        ellipseChan[i].x = ellipseChan[i - c].y;
    }
    for(int i = 2 * c; i < 4 * c; i ++)
    {
        ellipseChan[i].y = ellipseChan[i - 2 * c].y;
        ellipseChan[i].x = -ellipseChan[i - 2 * c].x;
    }

    for(int i = 4 * c; i < 8 * c; i ++)
    {
        ellipseChan[i].y = -ellipseChan[i - 4 * c].y;
        ellipseChan[i].x = ellipseChan[i - 4 * c].x;
    }
    cout << "transform: first quadrant\n";
    for(int i = 0; i < 8*c; i ++)
    {
        ellipseChan[i].y = ellipseChan[i].y + y;
        ellipseChan[i].x = ellipseChan[i].x + x;

        if(ellipseChan[i].y > 0 && ellipseChan[i].x > 0)
            cout << "(" << ellipseChan[i].x << " " << ellipseChan[i].y << ")" ;
    }
}
