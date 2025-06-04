Од тастатура се чита димензија на квадратна матрица(максимална големина 100х100).
Треба да се провери дали матрицата го задоволува следниот услов: секој елемент од главната дијагонала да
биде еднаков со збирот на елементите десно (во истата редица) од тој елемент. Ако матрицата го исполнува
условот истата треба да се испечати на екран, а во спротивно се  печати -1.



#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int matrix[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int nova;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        
        
        for (int j = 0; j < n; j++)
        {
            if(i==j){
                nova=matrix[i][j];
            }
            if(i==j && j==n-1){
                sum+=matrix[i][j];
            }
            if (j > i)
            {
                sum += matrix[i][j];
            }
            
        }
        
        
        if (sum != nova)
        {
            cout << "-1";
            return 0;
        }
    }
        
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
