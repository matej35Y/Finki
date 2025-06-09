Од стандарден влез се читаат N броеви. N не е однапред познато, треба да читате броеви додека да се прочита бројот -1.
  Сместете ги прочитаните броеви во низа. Во секој тест пример ќе има помалку од 100 броеви пред бројот -1.
Потоа се внесуваат 3 торки од по 4 броеви L, R, V и I. L и R се броеви помеѓу 0 и N-1; во секој тест пример ќе важи L < R. Бројот I ќе има вредност само 0 или 1. Кога I е 0 ќе треба на броевите со индекси во интервалот [L,R] (вклучително на L и R) да додадете вредност V. 
  Кога I е 1 ќе треба на броевите со индекси во интервалот (L,R) (не ги вклучува L и R) да додадете вредност V.
На крај отпечатете ја низата.

  #include <iostream>
using namespace std;

int main() {
    int n;
    int niza[100];
    int counter = 0;

    while (cin >> n) {
        if (n == -1) {
            break;
        }
        niza[counter] = n;
        counter++;
    }

    int topka1[4];
    int topka2[4];
    int topka3[4];

        int pocetok = 0;
        int kraj = 0;
    
            for (int i = 0; i < 4; i++) {
                    cin >> topka1[i];
            }
    
            pocetok = topka1[0];
            kraj = topka1[1];

            if (topka1[3] == 0) {
                for (int j = pocetok; j <= kraj; j++) {
                    niza[j]+=topka1[2];
                }
            } else {
                for (int j = pocetok+1; j < kraj; j++) {
                    niza[j]+=topka1[2];
                }
            }
    
    
    
    for (int i = 0; i < 4; i++) {
            cin >> topka2[i];
            }

    pocetok = topka2[0];
    kraj = topka2[1];

    if (topka2[3] == 0) {
        for (int j = pocetok; j <= kraj; j++) {
            niza[j]+=topka2[2];
        }
    } else {
        for (int j = pocetok+1; j < kraj; j++) {
            niza[j]+=topka2[2];
        }
    }
    
    
    
    for (int i = 0; i < 4; i++) {
            cin >> topka3[i];
        }

    pocetok = topka3[0];
    kraj = topka3[1];

    if (topka3[3] == 0) {
        for (int j = pocetok; j <= kraj; j++) {
            niza[j]+=topka3[2];
        }
    } else {
        for (int j = pocetok+1; j < kraj; j++) {
            niza[j]+=topka3[2];
        }
    }
        
    for (int i=0;i<counter;i++){
        cout<<niza[i]<<" ";
    }
    

    return 0;
}

