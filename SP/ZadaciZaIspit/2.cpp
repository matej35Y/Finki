Од стандарден влез се чита цел број N (N<=100) и потоа N низи од знаци. 
Низите знаци содржат букви, цифри и специјални знаци (без знаци за празно место), а секоја од нив не е подолга од 80 знаци.

Да се напише програма со која што на стандарден излез ќе се отпечати најдолгата низа,
којашто е палиндром (се чита исто од од лево на десно и од десно на лево) и што содржи барем еден специјален знак. Ако нема такви низи, се печати "Nema!". Ако има две или повеќе низи што го задоволуваат овој услов, се печати првата низа којашто го задоволува условот.
Влез:

9

a!bcdedcb!a
Kfd?vsvv98_89vvsv?dfK
Ccsvsdvdfv
342425vbbcb
352!2353696969625
gdg??dfg!!
5336346644747
8338736767867
12344321
Излез:

Kfd?vsvv98_89vvsv?dfK




#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

bool containsNonAlphanumeric(const char *ch) {
    while (*ch) {
        if (!isalpha(*ch) && !isdigit(*ch)) {
            return true;
        }
        ch++;
    }

    return false;
}

bool isPalindrome(const char *ch) {
    int length = strlen(ch);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        if (ch[start] != ch[end]) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    cin.ignore(); 

    char najdolga[80] = ""; 

    for (int i = 0; i < n; i++) {
        char ch[80];
        cin.getline(ch, 80);

        if (isPalindrome(ch) && containsNonAlphanumeric(ch) && strlen(ch) > strlen(najdolga)) {
            strcpy(najdolga, ch);
        }
    }

    if (strlen(najdolga) > 0) {
        cout << najdolga << endl;
    } else {
    cout << "Nema!" << endl;
    }

    return 0;
}

