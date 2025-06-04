На стандарден влез се читаат два броја a и b. Ваша задача е да ја најдете најголемата непарна цифра на секој број во опсег [a,b]. Функцијата за наоѓање на најголема непарна цифра мора да е рекурзивна.

Напомена: ако бројот нема непарни цифри се печати 0.

Печатење на секој број и негова цифра е во формат: број -> цифра

#include <iostream>
using namespace std;

int funkcija(int n, int m) {
    if (n > m) {
        return 0;
    }

    int tmp = n; 
    int najgolema = 0;
    int nova = 0;

    while (tmp != 0) {
        najgolema = tmp % 10;
        if (najgolema % 2 == 0) {
            najgolema = 0;
        }
        if (najgolema > nova) {
            nova = najgolema;
        }
        tmp /= 10;
    }

    cout << n << " -> " << nova << endl;
    return funkcija(n + 1, m);
}

int main() {
    int n, m;
    cin >> n >> m;
    funkcija(n, m);

    return 0;
}
