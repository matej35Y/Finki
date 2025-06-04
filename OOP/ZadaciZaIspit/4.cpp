#include<iostream>
#include<string.h>
using namespace std;

class Delo {
    char name[50];
    int year;
    char country[50];
    
public:
    Delo(){
        strcpy(name, " ");
        year=0;
        strcpy(country, " ");
    }
    Delo(char *name_, int year_, char * country_){
        strcpy(name, name_);
        year=year_;
        strcpy(country, country_);
    }
    Delo (const Delo &s){
        strcpy(name, s.name);
        year=s.year;
        strcpy(country, s.country);
    }
    Delo & operator = (const Delo &s){
        if (this== &s){
            return *this;
        }
        strcpy(name, s.name);
        year=s.year;
        strcpy(country, s.country);
        return *this;
    }
    char * getIme () {
        return name;
    }
    char *getCountry(){
        return country;
    }
    int getYear(){
        return year;
    }
    bool operator == (const Delo &s){
        return !strcmp(name, s.name);
    }
    
};
class Pretstava {
protected:
    Delo delo;
    int n;
    char date[15];
    
public:
    
    Pretstava (Delo delo_, int n_, char * date_){
        delo=delo_;
        n=n_;
        strcpy(date, date_);
    }
    Pretstava (const Pretstava &s){
        delo=s.delo;
        n=s.n;
        strcpy(date, s.date);
    }
    Pretstava & operator = (const Pretstava &s){
        if (this== &s){
            return *this;
            
        }
        delo=s.delo;
        n=s.n;
        strcpy(date, s.date);
        return *this;
    }
    Delo getDelo(){
        return delo;
       }
    
    virtual float cena(){
        int n,m;

            if (delo.getYear() > 1900) {
                m = 50;
            } else if (delo.getYear() > 1800) {
                m = 75;
            } else {
                m = 100;
            }

            if (!strcmp(delo.getCountry(), "Italija")) {
                n = 100;
            } else if (!strcmp(delo.getCountry(), "Rusija")) {
                n = 150;
            } else {
                n = 80;
            }

            return n + m;
        

    }
    int getN(){
        return n;
    }
    
};

class Balet:public Pretstava {
    static int price;
    
public:
   Balet(Delo delo_, int n_, char * date_)
    :Pretstava(delo_, n_, date_){};
    
    float cena() override{
        return Pretstava::cena()+price;
    }
    static int setCenaBalet(int s) {
        price = s;
        return price;
    }

    
};
class Opera:public Pretstava {
    
public:
    Opera(Delo delo_, int n_, char * date_):Pretstava(delo_, n_, date_){}
};


    int Balet::price=150;
    
float prihod(Pretstava ** pretstavi, int n){
    int  sum=0;
    for (int i=0;i<n;i++){
        sum+=pretstavi[i]->cena()*pretstavi[i]->getN();
    }
    return sum;
}
int brojPretstaviNaDelo(Pretstava** pretstavi,int n, Delo d){
    int counter=0;
    for (int i=0;i<n;i++){
        if(pretstavi[i]->getDelo()==d){
            counter++;
        }
    }
    return counter;
}

//citanje na delo
Delo readDelo(){
    char ime[50];
    int godina;
    char zemja[50];
    cin>>ime>>godina>>zemja;
    return Delo(ime,godina,zemja);
}
//citanje na pretstava
Pretstava* readPretstava(){
    int tip; //0 za Balet , 1 za Opera
    cin>>tip;
    Delo d=readDelo();
    int brojProdadeni;
    char data[15];
    cin>>brojProdadeni>>data;
    if (tip==0)  return new Balet(d,brojProdadeni,data);
    else return new Opera(d,brojProdadeni,data);
}
int main(){
    int test_case;
    cin>>test_case;
    
    switch(test_case){
    case 1:
    //Testiranje na klasite Opera i Balet
    {
        cout<<"======TEST CASE 1======="<<endl;
        Pretstava* p1=readPretstava();
        cout<<p1->getDelo().getIme()<<endl;
        Pretstava* p2=readPretstava();
        cout<<p2->getDelo().getIme()<<endl;
    }break;
        
    case 2:
    //Testiranje na  klasite Opera i Balet so cena
    {
        cout<<"======TEST CASE 2======="<<endl;
        Pretstava* p1=readPretstava();
        cout<<p1->cena()<<endl;
        Pretstava* p2=readPretstava();
        cout<<p2->cena()<<endl;
    }break;
    
    case 3:
    //Testiranje na operator ==
    {
        cout<<"======TEST CASE 3======="<<endl;
        Delo f1=readDelo();
        Delo f2=readDelo();
        Delo f3=readDelo();
        
        if (f1==f2) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;
        if (f1==f3) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;
    
    }break;
    
    case 4:
    //testiranje na funkcijata prihod
    {
        cout<<"======TEST CASE 4======="<<endl;
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        
        }
        cout<<prihod(pole,n);
    }break;
    
    case 5:
    //testiranje na prihod so izmena na cena za 3d proekcii
    {
        cout<<"======TEST CASE 5======="<<endl;
        int cenaBalet;
        cin>>cenaBalet;
        Balet::setCenaBalet(cenaBalet);
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        }
        cout<<prihod(pole,n);
        }break;
        
    case 6:
    //testiranje na brojPretstaviNaDelo
    {
        cout<<"======TEST CASE 6======="<<endl;
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        }
        
        Delo f=readDelo();
        cout<<brojPretstaviNaDelo(pole,n,f);
    }break;
    
    };


return 0;
}

