#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

class SMS{
protected:
    float price;
    char number[16];
    static float ddv;
public:
    SMS(){
        strcpy(this->number, "0038971123456");
        this->price=0;
    }
    SMS(char *number_, float price_){
        strcpy(number, number_);
        price=price_;
    }
    SMS(const SMS &s){
       
        strcpy(number, s.number);
        price=s.price;
    }
    SMS & operator = (const SMS &s){
        if (this == &s){
            return  *this;
        }
        strcpy(number, s.number);
        price=s.price;
        return  *this;
    }

    friend ostream& operator<<(ostream& out, SMS& sms) {
          out << "Tel: " << sms.number << " - cena: " << sms.SMS_cena() << "den.\n";
          return out;
      }

    virtual float SMS_cena()=0;
    ~SMS(){
        
    }
};

class RegularSMS:public SMS{
    bool isRoaming;
    char msg[1000];
    static float mult;
    
public:
    RegularSMS() : SMS() {
         strcpy(this->msg, "msg");
         this->isRoaming = false;
     }
 
    RegularSMS(char* number_, float price_, char* msg_, bool isRoaming_) : SMS(number_, price_) {
        strcpy(msg, msg_);
        isRoaming = isRoaming_;
    }

    float SMS_cena() {
        float x;
        if (isRoaming==true){
            x=mult;
        }else {
            x=ddv;
        }
        return price * (1.0 + x) * ceil(strlen(msg) / 160.0);
    }
    static void set_rProcent(float val) {
           RegularSMS::mult = val / 100;
       }
};
class SpecialSMS:public SMS {
    bool humanity;
    static float mult;
public:
SpecialSMS() : SMS() {
        this->humanity = false;
    }
    SpecialSMS( char *number_, float price_, bool humanity_)
                : SMS(number_, price_){
     humanity=humanity_;
    }
    float SMS_cena()  {
            if (humanity==true) {
                return price;
            } else {
                return price *(1.0+mult);
            }
        }
    static void set_sProcent(float val) {
            SpecialSMS::mult = val / 100;
        }
    ~SpecialSMS() { }

};
float RegularSMS::mult = 3.0;
float SpecialSMS::mult = 1.5;
float SMS::ddv = 0.18;

void vkupno_SMS(SMS** poraka, int n){
    int reg=0;
    int spec=0;
    float reg_price = 0, sp_price = 0;
    
    for (int i=0;i<n;i++){
        if(dynamic_cast<RegularSMS*>(poraka[i])){
            reg++;
            reg_price+=poraka[i]->SMS_cena();
        }
        else {
            spec++;
            sp_price += poraka[i]->SMS_cena();
        }
    }
 cout << "Vkupno ima " << reg << " regularni SMS poraki i nivnata cena e: " << reg_price << "\n";
    cout << "Vkupno ima " << spec << " specijalni SMS poraki i nivnata cena e: " << sp_price << "\n";
}



int main(){

    char tel[20], msg[1000];
    float cena;
    float price;
    int p;
    bool roam, hum;
    SMS  **sms;
    int n;
    int tip;

    int testCase;
    cin >> testCase;

    if (testCase == 1){
        cout << "====== Testing RegularSMS class ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++){
            cin >> tel;
            cin >> cena;
            cin.get();
            cin.getline(msg, 1000);
            cin >> roam;
            cout << "CONSTRUCTOR" << endl;
            sms[i] = new RegularSMS(tel, cena, msg, roam);
            cout << "OPERATOR <<" << endl;
            cout << *sms[i];
        }
        for (int i = 0; i<n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 2){
        cout << "====== Testing SpecialSMS class ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++){
            cin >> tel;
            cin >> cena;
            cin >> hum;
            cout << "CONSTRUCTOR" << endl;
            sms[i] = new SpecialSMS(tel, cena, hum);
            cout << "OPERATOR <<" << endl;
            cout << *sms[i];
        }
        for (int i = 0; i<n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 3){
        cout << "====== Testing method vkupno_SMS() ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i<n; i++){

            cin >> tip;
            cin >> tel;
            cin >> cena;
            if (tip == 1) {

                cin.get();
                cin.getline(msg, 1000);
                cin >> roam;
                
                sms[i] = new RegularSMS(tel, cena, msg, roam);

            }
            else {
                cin >> hum;

                sms[i] = new SpecialSMS(tel, cena, hum);
            }
        }

        vkupno_SMS(sms, n);
        for (int i = 0; i<n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 4){
        cout << "====== Testing RegularSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
            cin >> tel;
            cin >> cena;
            cin.get();
            cin.getline(msg, 1000);
            cin >> roam;
            sms1 = new RegularSMS(tel, cena, msg, roam);
            cout << *sms1;
        
            cin >> tel;
            cin >> cena;
            cin.get();
            cin.getline(msg, 1000);
            cin >> roam;
            cin >> p;
            RegularSMS::set_rProcent(p);
            sms2 = new RegularSMS(tel, cena, msg, roam);
            cout << *sms2;
        
        delete sms1, sms2;
    }
    if (testCase == 5){
        cout << "====== Testing SpecialSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
            cin >> tel;
            cin >> cena;
            cin >> hum;
            sms1 = new SpecialSMS(tel, cena, hum);
            cout << *sms1;
        
            cin >> tel;
            cin >> cena;
            cin >> hum;
            cin >> p;
            SpecialSMS::set_sProcent(p);
            sms2 = new SpecialSMS(tel, cena, hum);
            cout << *sms2;
        
        delete sms1, sms2;
    }
    
    return 0;
}

