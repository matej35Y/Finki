Од стандарден влез се чита низа на цели броеви се додека не се внесе нешто различно од цел број.
Треба да се направи трансформација на низата, на тој начин што за секој елемент,
сите елементи после него кои што се еднакви со него ќе се зголемат за разликата на позициите помеѓу двата елементи.

 Пример: - Низата 5 6 10 5 3 10 10, после трансформација би била 5 6 10 8 3 13 14.



   #include <iostream>
#include <cstring>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
    
    int n;
    int niza[100];
    int counter=0;
    while(cin>>n){
        niza[counter]=n;
        counter++;
    }
    for (int i=0;i<counter;i++){
        for (int j=i+1;j<counter;j++){
            if(niza[j]==niza[i]){
                int  razlika=j-i;
                niza[j]+=razlika;
            }
        }
    }
    
    
    for (int i = 0; i < counter; i++) {
        cout << niza[i] << " ";
    }
}
