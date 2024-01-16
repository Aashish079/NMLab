#include <iostream>
#include<cmath>
using namespace std;

typedef struct
{
float a;
float b;
} interval;

float fn(float x){
    // return x * x * x + x * x - 5;
    // return x*x*x - exp(x) + x*x -1;
    return sin(x) + cos(2*x);
}

float findRoot(interval i){
    static int count = 0;

    float num = i.a*fn(i.b)-i.b*fn(i.a);
    float den = fn(i.b)-fn(i.a);

    float c = num/den;

    if(abs(fn(c))<=0.005){
        cout<<"Funtional value fn ="<<fn(c)<<endl;
        cout<<"Number of iterations ="<<count<<endl;
        return c;

    }
    interval newinterval = {i.b, c};
    count++;
    return findRoot(newinterval);
}

int main(){
    interval i;
    cout<<"Enter the interval [a,b]:"<<endl;
    cin>> i.a>> i.b;

    float root = findRoot(i);

    cout<<"The root of the function is:"<<root;

    return 0;
}
