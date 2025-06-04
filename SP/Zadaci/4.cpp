Од стандарден влез се читаат соодветно низа со M елементи и низа со N елементи,
ваша задача е да ги споите двете низи во трета сортирана низа по растечки редослед. 
Објаснување: Се внесува најпрвин должината на првата низа М, па потоа се чита првата низа, 
потоа се внесува должината на втората низа N, па втората низа.
Напомена: Елементите во двете низи кои се внесуваат се сортирани. Максималната должина на низите е 100. 

#include <iostream>
#include <cstring>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
    int n,m;
    cin>>n;
    int niza[n];
    
    for (int i=0;i<n;i++){
        cin>>niza[i];
    }
    cin>>m;
    int niza2[m];
    for(int i=0;i<m;i++){
        cin>>niza2[i];
    }
    
    for (int i=0;i<n;i++){
        for(int j=i+1;j<n-1;j++){
            if(niza[j]>niza[j+1]){
                int tmp=niza[j];
                niza[j]=niza[j+1];
                niza[j+1]=tmp;
                
            }
        }
    }
    
    
    for (int i=0;i<m;i++){
        for(int j=i+1;j<m-1;j++){
            
            if(niza2[j]>niza2[j+1]){
                
                int tmp=niza2[j];
                niza2[j]=niza2[j+1];
                niza2[j+1]=tmp;
                
            }
        }
    }
    int idx1=0;
    int idx2=0;
    
    while (idx1<n && idx2<m) {
        if (niza[idx1]<niza2[idx2]){
            cout<<niza[idx1]<<" ";
            idx1++;
        }
        else
        {
            cout<<niza2[idx2]<<" ";
            idx2++;
        }
        
    }
    while (idx1<n) {
        cout<<niza[idx1]<< " ";
        idx1++;
    }
    while (idx2<m) {
        cout<<niza2[idx2]<<" ";
        idx2++;
    }
}
