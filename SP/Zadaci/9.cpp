Да се напише програма која чита две целобројни матрици со димензија mxn, а потоа печати колку колони од првата матрица се наоѓаат во втората матрица.

  
#include <iostream>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    int matrix1[n][m];
    int matrix2[n][m];

    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix1[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix2[i][j];
        }
    }
    int count = 0;
    for (int j = 0; j < m; ++j) {
        bool isColumnPresent = true;

        for (int i = 0; i < n; ++i) {
            bool found = false;

            for (int k = 0; k < n; ++k) {
                if (matrix1[i][j] == matrix2[k][j]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                isColumnPresent = false;
                break;
            }
        }

        if (isColumnPresent) {
            count++;
        }
    }

    cout  << count << endl;

    return 0;
}

