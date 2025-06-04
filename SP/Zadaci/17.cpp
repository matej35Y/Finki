Да се прочита број N од тастатура. Да се дефинира функција form(int n) што ќе испечати форма од ѕвезди како што е прикажано на сликата.

За да се освојат сите поени од вежбата, потребно е функцијата form да биде рекурзивна.

#include <iostream>
using namespace std;
int form(int n){
    if(0==n){
        return 0;
    }
    else{
        
            for (int i=n;i>0;i--){
                cout<<"*";
                
            }
        cout<<endl;
       return form(n-1);
        
            return 0;
        
    }
        
}
int main()
{
    int n;
    cin>>n;
    form(n);
    
    
}
