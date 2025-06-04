Да се напише рекурзивна функција преку која бројот ќе се трансформира на тој начин што секоја непарна цифра ќе се намали за 1, а парните цифри ќе бидат заменети со нула. Функцијата треба да го врати трансформираниот број. Да се напише и главна програма која ќе ја тестира работата на функцијата.

  #include <iostream>
using namespace std;
int funkcija(int n,int num=0){
    if(n==0){
        return num;
    }
    int posledna=n%10;
    if(posledna%2!=0){
        posledna=posledna-1;

    }else{
        posledna=0;
    }
    num=num*10+posledna;
    if(posledna==0 && n/10==0){
        num*=10;
    }

    return funkcija(n/10,num);
    
}
int reverseNUM(int n){
    
    int rev=0;
    while (n!=0) {
        rev=rev*10+n%10;
        n/=10;
    }
    return rev;
    
    
}
int main()
{
    int n;
    cin>>n;
   
    int result=funkcija(n);
    int tmpResult=n;
    int reveresed=reverseNUM(result);

    int brojac=0;
    int brojac2=0;
    int tmp=reveresed;
    while (tmp!=0) {
        brojac++;
        tmp/=10;
    }
    while (tmpResult!=0) {
        brojac2++;
        tmpResult/=10;
    }

    if(brojac!=brojac2){
        reveresed*=10;
    }
    
    cout<<"Brojot e "<<reveresed;
    
        
}
