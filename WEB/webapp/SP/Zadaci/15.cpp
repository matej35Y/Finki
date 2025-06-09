Од стандарден влез се вчитува квадратна матрица со n редици и колони. Прво се вчитува бројот n, па потоа и n елементите на матрицата.

Доколку n е непарен број да се испечати пораката GRESKA и да заврши програмата.

Потребно е матрицата да се здипли како што е прикажано на сликата. При диплење на матрицата, се собираат елементите на позициите што се поклопуваат при диплењето.


#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << "GRESKA";
        return 0;
    }

    int matrix[n][n];
    int result[n / 2][n / 2];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            result[i][j] = matrix[i][j] + matrix[i][n - j - 1] + matrix[n - i - 1][j] + matrix[n - i - 1][n - j - 1];
        }
    }

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
