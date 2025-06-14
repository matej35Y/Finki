Од тастатура се чита природен број N (N < 400).

Да се напише програма којашто формира квадратна матрица што ги содржи броевите од 1 до N по растечки редослед на следниот начин: во првата колона во правец од горе надолу,
  па продолжува во втората колона од долу нагоре, па продолжува во третата колона од горе надолу итн. Да се избере најмалата димензија на матрицата во која ќе ги собере сите броеви до N.
  Доколку има преостанати празни места, тие да се пополнат со нули.

Пример.

Влез

22


Излез

1 10 11 20 21
2 9 12 19 22
3 8 13 18 0
4 7 14 17 0
5 6 15 16 0
------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cin >> n;

    char niza[100];
    char substring[] = "A1c";

    for (int i = 0; i < n; i++) {
        cin >> niza;
        int len = strlen(niza);

        for (int j = 0; j < len; j++) {
            int start = j;
            int idx = 0;
            int counter = 0;

            while (niza[start] == substring[idx] && start < len && idx < 3) {
                start++;
                idx++;
            }

            if (idx == 3) {
                counter++;
            }

            if (counter >= 2) {
                for (int k = j; k < j + 3; k++) {
                    cout << char(tolower(niza[k]));
                }
                cout << endl;
            }
        }
    }

    return 0;
}
