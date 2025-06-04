Од стандарден влез се чита број n, а потоа се читаат и n броеви. Потребно е на екран да се испечатат сите броеви кои што се строго растечки односо секоја цифра е поголема од претходната (1589 е растечки, 1529 не е растечки). Проверката за тоа дали бројот е растечки да се реализира со посебна функција која ќе врати 1 ако е растечки и -1 ако не е растечки. Дополнително ако бројот е растечки за него треба да се повика функција која ќе ја пресмета сумата на цифрите од кои е составен.

Дополнително: функцијата за пресметување на сума на цифри да биде рекурзивна

Печатењето треба да е во следен формат: 1234 (suma:  10)


  #include <iostream>
using namespace std;
int funkcija(int n, int s=0){
    if(n==0){
        return s;
    }else {
        s+=n%10;
        
        
    }
    return funkcija(n/10,s);
}
int main()
{
    int n;
    cin>>n;
    
    int matrix[n];
    for (int i=0;i<n;i++){
        cin>>matrix[i];
    }
    
    for (int i=0;i<n;i++){
        bool rastecka=true;
        int tmp=matrix[i];
        
        while (tmp!=0) {
            int posledna=tmp%10;
            int pretposledna=tmp/10%10;
            
            if(posledna<pretposledna){
                rastecka=false;
                break;
            }
            if(posledna>pretposledna){
                rastecka=true;
            }
            tmp/=10;
        }
        if(rastecka==true){
            cout<<matrix[i]<<" "<<"(suma: "<<funkcija(matrix[i])<<") "<<endl;
        }
    }
        
}
