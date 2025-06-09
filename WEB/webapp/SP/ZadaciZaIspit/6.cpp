Од стандарден влез се чита природен број N (N <= 100), како и низа од позитивни цели броеви a[ ] со N елементи. 

Да се напише функција int par(a, n) која ќе го врати најмалиот елемент во низата кој се појавува парен број пати во низата. Доколку нема таков елемент, функцијата враќа вредност 0.

Напишете програма што ќе ја повика функцијата par за внесената низа a[ ] и ќе го испечати најмалиот број којшто се појавува парен број пати во низата a[ ].

Пример 1.

Влез

12 // бројот N на елементи

1 3 4 5 3 1 4 5 5 3 2 3 // елементи на низата


Излез

Najmaliot element koj se pojavuva paren broj pati e 1 // овде функцијата par враќа вредност 1, а се печати оваа порака



Пример 2.

Влез

12 // бројот N на елементи

7 3 4 5 3 8 4 5 5 3 2 6 // елементи на низата


Излез

Nitu eden element ne se pojavuva paren broj pati! // овде функцијата par враќа вредност 0, се печати оваа порака 



-----------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    
    int niza[n];
    int najmal=1000;
    bool nema=true;
    
    for (int i=0;i<n;i++){
        cin>>niza[i];
    }
    for (int idx=0; idx<n; idx++) {
        
        int brojot=niza[idx];
        int brojac=0;
        
        
        for (int i=0; i<n; i++) {
            if(niza[i]==brojot){
                brojac++;
            }
        }
        
        
        if(brojac%2==0){
            nema=false;
            if(brojot<najmal){
                najmal=brojot;
            }
        }
    }
      
    if(nema==true){
        cout<<"Nitu eden element ne se pojavuva paren broj pati!";
        
    }else{
        cout<<"Najmaliot element koj se pojavuva paren broj pati e "<<najmal;
    }
}
