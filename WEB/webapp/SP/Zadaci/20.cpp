Од стандарден влез се внесуваат број на елементи на низа и самата низа. Ваша задача е да најдете најголем и најмал елемент на низата, како и да ја трансформирате низата така што секој елемент ќе се зголеми за разликата помеѓу најголемиот и најмалиот елемент и на крајот да ги испечатите најголемиот, најмалиот елемент и трансформираната низата.

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int matrix[n];
    int maximum=0;
    int minimum=9999;
    int razlika=0;
    for (int i=0;i<n;i++){
        cin>>matrix[i];
        
    }
    for (int i=0;i<n;i++){
        if(matrix[i]>maximum){
            maximum=matrix[i];
        }
        if(matrix[i]<minimum){
            minimum=matrix[i];
        }
    }
    cout<<"MAX -> "<<maximum<<endl;
    cout<<"MIN -> "<<minimum<<endl;
    
    razlika=maximum-minimum;
    
    for(int i=0;i<n;i++){
        matrix[i]+=razlika;
        cout<<matrix[i]<<" ";
    }
}
