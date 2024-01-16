#include <iostream>
#include <cmath>
using namespace std;

float fn(float x)
{
    // return x * x * x + x * x - 5;
    // return x*x*x - exp(x) + x*x -1;
    return sin(x) + cos(2*x);
}
float dfn(float x)
{
    // return 3 * x * x + 2 * x;
    // return 3*x*x - exp(x) + 2*x;
    return cos(x) - 2*sin(2*x);

}

float findRoot(float n)
{
    static int count = 0;
    if(dfn(n)==0){
        cout<<"Can't find the solution."<<endl;
        return 0.00;
    }
    else
    n = n - fn(n) / dfn(n);

    if (abs(fn(n)) < 0.0005)
    {
        return n;
    }
    if(count>=100){
        cout<<"The function is oscillatory.";
        return 0.00;
    }
    // cout << "n=" << n << ",fn(n)=" << fn(n) << endl;
    count++;
    return findRoot(n);
}

int main()
{
    cout << "Enter the intial guess" << endl;
    float initialGuess;
    cin >> initialGuess;

    float root = findRoot(initialGuess);

    cout << "The root of the function is:" << root;

    return 0;
}
