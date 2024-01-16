#include <iostream>
#include <cmath>

using namespace std;

float fn(float x, float y)
{

    return (x + y);
}

void printSolnUsingEuler(float x0, float y0, float h, float xn)
{
    int count = 0;
    while (x0 <= xn)
    {
        y0 = y0 + h * fn(x0, y0);
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

    printSolnUsingEuler(x0, y0, h, xn);

    return 0;
}
