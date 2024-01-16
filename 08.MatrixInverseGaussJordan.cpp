#include <iostream>
#include<iomanip>

using namespace std;

void showMat(float augMat[][20], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = size; j < size * 2; j++)
        {
            cout <<setprecision(4)<<setw(5)<< augMat[i][j]/augMat[i][i];
        }
        cout << endl;
    }
}

void readMat(float augMat[][20], int size)
{
    cout << "Enter the Matrix to be Inversed" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "a[" << i+1 << "]"
                 << "[" << j+1 << "] = ";
            cin >> augMat[i][j];

            if (i == j)
                augMat[i][size + j] = 1;
            if (i != j)
                augMat[i][size + j] = 0;
        }
    }
}

void inverseMat(float augMat[][20], int size)
{
    cout << "Applying GaussJordan Algorithm for Inversing a Matrx"<<endl;
    for (int i = 0; i < size; i++)
    {
        if (abs(augMat[i][i]) == 0)
        {
            cout << "Mathematical Error" << endl;
            break;
        }
        for (int j = 0; j < size; j++)
        {

            if (i != j)
            {
                float ratio = augMat[j][i] / augMat[i][i];
                for (int k = 0; k < size * 2; k++)
                {
                    augMat[j][k] -= ratio * augMat[i][k];
                }
            }
        }
    }
}

int main()
{
    float augMat[20][20];
    int size;

    cout << "Enter the size of Matrix:" << endl;
    cin >> size;

    readMat(augMat, size);

    inverseMat(augMat, size);

    showMat(augMat, size);

    return 0;
}