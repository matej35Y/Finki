#include <iostream>
#include <cstring>
#include <ctype.h>
using namespace std;
class Vozac{
protected:
    
    char name[100];
    int age;
    int races_num;
    bool veteran;
    
public:
    
    Vozac(){
        strcpy(name,"dekibmw");
        age=30;
        races_num=10;
        veteran=false;
        
    }
    Vozac(char *name_, int age_, int races_num_, bool veteran_){
        strcpy(name, name_);
        age=age_;
        races_num=races_num_;
        veteran=veteran_;
        
    }
    Vozac(const Vozac &s){
        strcpy(name, s.name);
        age=s.age;
        races_num=s.races_num;
        veteran=s.veteran;
    }
    Vozac & operator = (const Vozac &s){
        if (this==&s){
            return *this;
        }
        strcpy(name, s.name);
        age=s.age;
        races_num=s.races_num;
        veteran=s.veteran;
        return *this;
    }
    friend ostream & operator <<(ostream &out, const Vozac &s){
        out<<s.name<<endl<<s.age<<endl<<s.races_num<<endl;
        if(s.veteran==true){
            cout<<"VETERAN"<<endl;
        }        
        return out;
    }
    virtual float zarabotuvacka()=0;
    virtual float danok()=0;
    
    bool  operator == (Vozac &s){
        return zarabotuvacka()==s.zarabotuvacka();
    }
    
};
class Avtomobilist:public Vozac{
    float price;
public:
    Avtomobilist(char *name_, int age_, int races_num_, bool veteran_,float price_)
    :Vozac(name_, age_,races_num_,veteran_){
        price=price_;
        
    }
    Avtomobilist(const Avtomobilist &s):Vozac(s){
        price=s.price;
    }
    Avtomobilist operator = (const Avtomobilist &s){
        if (this==&s){
            return *this;
        }
        Vozac::operator=(s);
        price=s.price;
        return *this;
    }
    float zarabotuvacka() override{
        return price/5;
    }
    float danok() override{
        if(races_num>10){
            return 0.15*zarabotuvacka();
        }else{
            return 0.10 *zarabotuvacka();
        }
    }
    
};
class Motociklist:public Vozac {
    int horsePower;
public:
    Motociklist(char *name_, int age_, int races_num_, bool veteran_, int hoorsePower_)
    :Vozac(name_, age_,races_num_,veteran_){
        horsePower=hoorsePower_;
    }
    Motociklist(const Motociklist &s)
    :Vozac(s){
        horsePower=s.horsePower;
    }
    Motociklist operator = (const Motociklist &s){
        if (this == &s){
            return *this;
        }
        Vozac::operator=(s);
        horsePower=s.horsePower;
        return *this;
    }
    float zarabotuvacka() override{
        return horsePower*20;
    }
    float danok() override{
        if(veteran){
            return 0.25*zarabotuvacka();
            
        }else{
            return 0.20*zarabotuvacka();
        }
    }
    
    
    
};
float soIstaZarabotuvachka(Vozac** vozaci,int n,Vozac *s){
    int counter=0;
    for (int i=0;i<n;i++){
        if (vozaci[i]->zarabotuvacka()==s->zarabotuvacka()){
            counter++;
        }
    }
    return counter;
}


int main() {
    int n, x;
    cin >> n >> x;
    Vozac **v = new Vozac*[n];
    char ime[100];
    int vozrast;
    int trki;
    bool vet;
    for(int i = 0; i < n; ++i) {
        cin >> ime >> vozrast >> trki >> vet;
        if(i < x) {
            float cena_avto;
            cin >> cena_avto;
            v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
        } else {
            int mokjnost;
            cin >> mokjnost;
            v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
        }
    }
    cout << "=== DANOK ===" << endl;
    for(int i = 0; i < n; ++i) {
        cout << *v[i];
        cout << v[i]->danok() << endl;
    }
    cin >> ime >> vozrast >> trki >> vet;
    int mokjnost;
    cin >> mokjnost;
    Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
    cout << "=== VOZAC X ===" << endl;
    cout << *vx;
    cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
    cout << soIstaZarabotuvachka(v, n, vx);
    for(int i = 0; i < n; ++i) {
        delete v[i];
    }
    delete [] v;
    delete vx;
    return 0;
}
