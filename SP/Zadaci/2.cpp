Да се напише програма со која ќе се печатат најмалите k елементи од низата. Низата и бројот на најмалите елементи се внесуваат преку тастатура.

#include <iostream>

using namespace std;

int main() {
    int n, k;

    
    cin >> n;
    cin >> k;

   
    int niza[n];

    for (int i = 0; i < n; i++) {
        cin >> niza[i];
    }

    for (int i = 0; i < k; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (niza[j] < niza[minIndex]) {
                minIndex = j;
            }
        }

        int temp = niza[i];
        niza[i] = niza[minIndex];
        niza[minIndex] = temp;

        cout << niza[i] << " ";
    }

    return 0;
}
