Се чита низа од n цели броеви. Провери дали низата е специјална. 
  Ако од сите броеви на парни позиции 50% или повеќе се парни броеви, и од сите броеви на непарна позиција 30% или помалку се непарни броеви, тогаш низата е специјална.
  Испечати 1 ако е низата специјална, испечати 0 ако не е.

  #include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int niza[n];
    int counter=0, counter2=0;
    for (int i=0;i<n;i++){
        cin>>niza[i];
        
        if (niza[i]%2==0 && i%2==0){
            counter++;
        }else if(niza[i]%2==1 && i%2==1){
            counter2++;
        }else{
            continue;
        }
    }
    double procent1=(static_cast<double>(counter)/n)*100;
    double procent2=(static_cast<double>(counter2)/n)*100;
    
    if(procent1>=50.0 && procent2<=30.0){
        cout<<"1";
    }else{
        cout<<"0";
    }
}
