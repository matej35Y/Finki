Од стандарден влез се вчитува матрица сo n редици и n колони. Прво се вчитува бројот n потоа и елементите на матрицата. Матрицата треба да се трансформира така што секој елемент што се наоѓа десно од споредната дијагонала од истата редица и е помал од просекот на елементите лево од споредната дијагонала од истата редица треба да се замени со -1. Вака трансформираната матрица да се испечати на екран.

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int matrix[n][n];

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

   
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        int counter = 0;

        for (int j = 0; j < n; j++) {
            if (i+j<n-1) {
                sum += matrix[i][j];
                counter++;
            }
        }
        
        double avg=0.0;
        if (counter<0){
            avg=0.0;
        }
        else {
            avg=sum/counter;
        }
        
        for(int j=n-i;j<n;j++){
            if (matrix[i][j]<avg){
                matrix[i][j]=-1;
            }
        }
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}



