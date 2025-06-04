Од тастатура се вчитуваат броевите A и B. На екран да се испечатат сите броеви од интервалот [A,B] кои се палиндроми и се составени само од цифрите 0,1,2,3 и 4. 

Предлог за работа: 
Да се имплементира функција reverseNumber (int number) која ќе го пресмета обратниот број на определен број number.
Да се имплементира функција isPalindrome (int number) која ќе врати 1 доколку бројот number е палиндром, а 0 во спротивно
Да се имплементира функција containsDigits (int number) која ќе врати 1 доколку сите цифри во бројот се 0,1,2,3 или 4, а 0 во спротивно. 
Да се искористат функциите isPalindrome и containsDigits во main функцијата
Дополнително: Направете ја функцијата containsDigits рекурзивна.


  #include <iostream>
using namespace std;

int reverseNumber(int number){
    int rev=0;
    while (number!=0) {
        int digit=number%10;
        rev=rev*10+digit;
        number/=10;
    }
    return rev;
    
}

int isPalindrome(int number){
    if (number==reverseNumber(number)){
        return 1;
    }
    return 0;
}

int containsDigits(int number) {
    int tmp = number;
    while (tmp != 0) {
        int digit = tmp % 10;
        if (digit != 0 && digit != 1 && digit != 2 && digit != 3 && digit != 4) {
            return 0;
        }
        tmp /= 10;
    }
    return 1;
}

int main(){
    int a,b;
    cin>>a>>b;
    
    for (int i=a;i<b;i++){
        if (isPalindrome(i) && containsDigits(i)){
            cout<<i<<endl;
        }
    }
    
}

