#include <stdio.h>
#include <math.h>

float fn(float);

float findRoot(float, float, float);

int main()
{
    float a, b, e;
    printf("Enter the first value:\n");
    scanf("%f", &a);
    printf("Enter the second value:\n");
    scanf("%f", &b);
    printf("Enter the Error Tolerance:\n");
    scanf("%f", &e);

    float root = findRoot(a, b, e);
    printf("The root of the function is %.3f", root);

    return 0;
}

float fn(float x)
{
    return 1/x;
}
float findRoot(float a, float b, float e)
{
    
    float n = (log(abs(b - a)) - log(e)) / log(2);
    int count = 0;
    if (fn(a) * fn(b) <= 0)
    {
        float mid = (a + b) / 2;

        do
        {
            if (fn(a) * fn(mid) <= 0)
            {
                b = mid;
                mid = (a + b) / 2;
            }
            else if (fn(b) * fn(mid) <= 0)
            {
                a = mid;
                mid = (a + b) / 2;
            }
            count ++;
            if(count>2*n){
                printf("The function is discontinuous.");
                break;
            }
        } while (abs(fn(mid)) >= e);

        return mid;
    }

    else
    {
        printf("Root Doesn't Exist.\n");
    }
}