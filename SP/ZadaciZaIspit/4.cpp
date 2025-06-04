Од стандарден влез се чита цел број N (N<100) и потоа N низи од знаци. Низите знаци содржат букви, цифри и специјални знаци,
а секоја од нив не е поголема од 50 знаци.

Да се напише програма што ќе ги отпечати на екран сите низи од знаци во кои се содржи поднизата А1c  најмалку 2 пати (пр. A1c01АA1c92, 12A1cwwA1cxy,
аA1cwA1cA1ccA1cxab) според редоследот како што се прочитани од влезот. При печатење на зборовите, сите алфабетски знаци треба да се испечатат со мали букви.

Пример

Влез:

6

Ekjqh!!lkjsdh 
 A1c01АA1c92
12A1cwwA1cxy 
12A1cwwA1bxy 
аA1cwA1cA1ccA1cxab
nemaA1c_povekjepati


Излез

а1c01аа1c92
12а1cwwа1cxy 
аа1cwа1cа1ccа1cxab


---------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    int n;
    cin >> n;

    char niza[50];

    for (int i = 0; i < n; i++) {
        cin >> niza;
        int len = strlen(niza);
        int counter = 0;

        for (int j = 0; j < len; j++) {
            int start = j;
            int idx = 0;

             char substring[] = "A1c";

            while (tolower(niza[start]) == tolower(substring[idx]) && start < len && idx < 3) {
                start++;
                idx++;
            }

            if (idx == 3) {
                counter++;
            }
        }

        if (counter >= 2) {
            for (int k = 0; k < len; k++) {
                cout << char(tolower(niza[k]));
            }
            cout << endl;
        }
    }

    return 0;
}



