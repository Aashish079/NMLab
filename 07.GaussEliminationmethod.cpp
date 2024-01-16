#include <iostream>

using namespace std;

void GaussElimination(float augMat[][20], int size)
{
    float result[20];
    float ratio;
    //Covert to Upper Triangular Matrix
    for (int j = 1; j <= size; j++)
    {
        if (augMat[j][j] == 0)
        {
            cout << "Mathematical Error";
        }
        for (int i = j; i <= size; i++)
        {
            if (i != j)
            {
                ratio = augMat[i][j] / augMat[j][j];
                for (int k = 1; k <= size + 1; k++)
                {
                    augMat[i][k] = augMat[i][k] - ratio * augMat[j][k];
                }
            }
        }
    }
    //Back Substitution
    result[size] = augMat[size][size+1]/ augMat[size][size];

    for(int i=size-1; i>=1; i--){
        int sum = 0;
        for(int j = i + 1; j<= size; j++){
            sum += augMat[i][j];
        }
        result[i] = (augMat[i][size+1]- sum)/augMat[i][i];
    }

    //Display Result
    for(int i = 1; i<=size; i++){
        cout<<result[i]<<endl;
    }
}

int main()
{
    float augmentedMatrix[20][20];
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

    cout << "Applying GaussElimination Method..." << endl;
    GaussElimination(augmentedMatrix, size);

    return 0;
}