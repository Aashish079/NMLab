#include <iostream>
#include <cmath>

using namespace std;

float fn(float x, float y)
{

    return (x + y);
}

void printSolnUsingRK4(float x0, float y0, float h, float xn)
{
    int count = 0;
    while (x0 <= xn)
    {
        float m1 = fn(x0, y0);
        float m2 = fn(x0 + h / 2, y0 + m1 * h / 2);
        float m3 = fn(x0 + h / 2, y0 + m2 * h / 2);
        float m4 = fn(x0 + h, y0 + m3 * h);

        float m = (m1 + 2 * m2 + 2 * m3 + m4) / 6;

        y0 = y0 + h * m;
        x0 = x0 + h;
        // cout <<"x"<<count<<" = "<< x0 << " | "<<"y"<<count<<" = "<< y0<<endl;
        cout << x0 << "  " << y0 << endl;
        count++;
    }
}

int main()
{
    float x0, y0, h, xn;
    cout << "Enter the initial Conditions: " << endl;

    cout << "x0 = ";
    cin >> x0;

    cout << "y0 = ";
    cin >> y0;

    cout << "Interval size: ";
    cin >> h;

    cout << "xn = ";
    cin >> xn;

    printSolnUsingRK4(x0, y0, h, xn);

    return 0;
}
