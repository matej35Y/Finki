#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class MessageException {
public:
    void message() {
        cout << "Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!" << endl;
    }
};

class Oglas {
    char tittle[50];
    char category[30];
    char description[100];
    float price;

public:
    Oglas() : price(0) {
        strcpy(tittle, "");
        strcpy(category, "");
        strcpy(description, "");
    }

    Oglas(char* tittle_, char* category_, char* description_, float price_) {
        strcpy(tittle, tittle_);
        strcpy(category, category_);
        strcpy(description, description_);
        price = price_;
    }

    Oglas(const Oglas& s) {
        strcpy(tittle, s.tittle);
        strcpy(category, s.category);
        strcpy(description, s.description);
        price = s.price;
    }

    Oglas& operator=(const Oglas& s) {
        if (this == &s) {
            return *this;
        }
        strcpy(tittle, s.tittle);
        strcpy(category, s.category);
        strcpy(description, s.description);
        price = s.price;
        return *this;
    }

    bool operator>(const Oglas& s) const {
        return price > s.price;
    }

    friend ostream& operator<<(ostream& out, const Oglas& s) {
        out << s.tittle << endl << s.description << endl << s.price << " evra" << endl;
        return out;
    }

    int getPrice() const {
        return price;
    }

    const char* getCategory() const {
        return category;
    }
};

class Oglasnik {
    char name[20];
    Oglas* oglasi;
    int n;

public:
    Oglasnik() {
        strcpy(name, "");
        this->oglasi = nullptr;
        this->n = 0;
    }

    Oglasnik(char* name_) {
        strcpy(name, name_);
        this->oglasi = nullptr;
        this->n = 0;
    }

    Oglasnik(char* name_, Oglas* oglasi_, int n_) {
        strcpy(name, name_);
        this->oglasi = new Oglas[n_];
        for (int i = 0; i < n_; i++) {
            oglasi[i] = oglasi_[i];
        }
        n = n_;
    }

    Oglasnik(const Oglasnik& s) {
        strcpy(name, s.name);
        this->oglasi = new Oglas[s.n];
        for (int i = 0; i < s.n; i++) {
            oglasi[i] = s.oglasi[i];
        }
        n = s.n;
    }

    Oglasnik& operator=(const Oglasnik& s) {
        if (this == &s) {
            return *this;
        }
        delete[] oglasi;
        strcpy(name, s.name);
        oglasi = new Oglas[s.n];
        for (int i = 0; i < s.n; i++) {
            oglasi[i] = s.oglasi[i];
        }
        n = s.n;
        return *this;
    }

    Oglasnik& operator+=(const Oglas& s) {
        if (s.getPrice() < 0) {
            throw MessageException();
        }
        Oglas* tmp = new Oglas[n + 1];
        for (int i = 0; i < n; i++) {
            tmp[i] = oglasi[i];
        }
        tmp[n++] = s;
        delete[] oglasi;
        oglasi = tmp;
        return *this;
    }

    void oglasiOdKategorija(const char* k) const {
        for (int i = 0; i < n; i++) {
            if (!strcmp(oglasi[i].getCategory(), k)) {
                cout << oglasi[i] << endl;
            }
        }
    }

    void najniskaCena() const {
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (oglasi[i].getPrice() < oglasi[idx].getPrice()) {
                idx = i;
            }
        }
        cout << oglasi[idx] << endl;
    }

    ~Oglasnik() {
        delete[] oglasi;
    }

    friend ostream& operator<<(ostream& out, const Oglasnik& s) {
        out << s.name << endl;
        for (int i = 0; i < s.n; i++) {
            out << s.oglasi[i] << endl;
        }
        return out;
    }
};


int main(){
    
    char naslov[50];
    char kategorija[30];
    char opis[100];
    float cena;
    char naziv[50];
    char k[30];
    int n;
    
    int tip;
    cin>>tip;
    
    if (tip==1){
        cout<<"-----Test Oglas & operator <<-----" <<endl;
        cin.get();
        cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o(naslov, kategorija, opis, cena);
        cout<<o;
    }
    else if (tip==2){
        cout<<"-----Test Oglas & operator > -----" <<endl;
        cin.get();
        cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o1(naslov, kategorija, opis, cena);
        cin.get();
        cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o2(naslov, kategorija, opis, cena);
        if (o1>o2) cout<<"Prviot oglas e poskap."<<endl;
        else cout<<"Prviot oglas ne e poskap."<<endl;
    }
    else if (tip==3){
        cout<<"-----Test Oglasnik, operator +=, operator << -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o(naslov, kategorija, opis, cena);
            try {
                ogl+=o;
            } catch (MessageException &s) {
                s.message();
            }
        }
        cout<<ogl;
    }
    else if (tip==4){
          cout<<"-----Test oglasOdKategorija -----" <<endl ;
          cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o(naslov, kategorija, opis, cena);
            try {
                ogl+=o;
            } catch (MessageException &s) {
                s.message();
            }
        }
        cin.get();
        cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
          ogl.oglasiOdKategorija(k);
    
    }
    else if (tip==5){
        cout<<"-----Test Exception -----" <<endl ;
          cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o(naslov, kategorija, opis, cena);
            try {
                ogl+=o;
            } catch (MessageException &s) {
                s.message();
            }
           
        }
        cout<<ogl;
    
    }
    else if (tip==6){
        cout<<"-----Test najniskaCena -----" <<endl ;
          cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o(naslov, kategorija, opis, cena);
            try {
                ogl+=o;
            } catch (MessageException &s) {
                s.message();
            }
        }
        cout<<"Oglas so najniska cena:"<<endl;
          ogl.najniskaCena();
    
    }
    else if (tip==7){
        cout<<"-----Test All -----" <<endl ;
          cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o(naslov, kategorija, opis, cena);
            try {
                ogl+=o;
            } catch (MessageException &s) {
                s.message();
            }
        }
        cout<<ogl;
        
        cin.get();
        cin.get();
        cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
          ogl.oglasiOdKategorija(k);
        
        cout<<"Oglas so najniska cena:"<<endl;
          ogl.najniskaCena();
    
    }
    
    return 0;
}
