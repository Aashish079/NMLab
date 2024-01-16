#include <iostream>

using namespace std;

int main()
{
    float augmentedMatrix[20][20];
    float result[20];
    float ratio;

    int size;
    cout << "Enter the number of Variables: ";
    cin >> size;

    cout << "Enter the Coefficients:" << endl;
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size + 1; j++)
        {
            cout << "A[" << i << "," << j << "] ";
            cin >> augmentedMatrix[i][j];
        }
    }

    cout << "Applying Gauss-Jordan Algorithm ..." << endl;
    for (int j = 1; j <= size; j++)
    {
        if (augmentedMatrix[j][j] == 0)
        {
            cout << "Mathematical Error";
        }
        for (int i = 1; i <= size; i++)
        {
            if (i != j)
            {
                ratio = augmentedMatrix[i][j] / augmentedMatrix[j][j];
                for (int k = 1; k <= size + 1; k++)
                {
                    augmentedMatrix[i][k] = augmentedMatrix[i][k] - ratio * augmentedMatrix[j][k];
                }
            }
        }
    }

    for (int i = 1; i <= size; i++)
    {
        result[i] = augmentedMatrix[i][size + 1] / augmentedMatrix[i][i];

        cout << result[i] << endl;
    }

    return 0;
}