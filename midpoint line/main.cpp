#include <iostream>
#include <cstdio>

using namespace std;

void MidpointLine(int x0,int y0,int x1,int y1)
{
    int a,b,d1,d2,d,x,y;

    a=y0-y1,b=x1-x0,d=2*a+b;

    d1=2*a,d2=2*(a+b);

    x=x0,y=y0;

    int c = abs(x0 - x1);
    int i = c;
    int k = 1;
    cout <<"itr0 x:" << x << " y:" << y << " d:" << d << "\n";
    while (c > 0)

            {

                    if (d<0)

                    {    x++,y++,d+=d2;}

                    else

                    {    x++,d+=d1;    }
                    cout << "itr" << k  <<" ";
                    cout <<"x:" << x <<" y:" <<y <<" d:";
                    cout << d << "\n";
                    c--;
                    k ++;
            }
    cout<<"Midpoint line drawing. Only if 0 < K < 1";
}
int main() {
    int x0,y0,x1,y1;
    cout << "input form: x0 y0 x1 y1" <<"\n";
    cin >>x0 >> y0 >> x1 >> y1;
    MidpointLine(x0,y0,x1,y1);
}
