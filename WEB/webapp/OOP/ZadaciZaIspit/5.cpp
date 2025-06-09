#include <iostream>
#include <cstring>

using namespace std;

enum tip {
    smartphone,computer
};

class InvalidProductionDate {
public:
    void message() {
        cout << "Невалидна година на производство" << endl;
    }
};


char Tip[][8]{
    "Mobilen","Laptop"
};
using namespace std;
class Device {
    char model[100];
    tip deviceType;
    static float  casovi;
    int godina;
public:
    Device() {
            strcpy(this->model, "model");
            this->deviceType = smartphone;
            this->godina = 0;
        }
    Device(char *model_, tip deviceType_,float casovi_,int godina_){
        strcpy(model, model_);
        deviceType=deviceType_;
        casovi=casovi_;
        godina=godina_;
    }
    Device(char* model, tip type, int year) {
         strcpy(this->model, model);
         deviceType= type;
         godina = year;
     }
    Device(const Device &s){
        strcpy(model, s.model);
        deviceType=s.deviceType;
        casovi=s.casovi;
        godina=s.godina;
    }
    Device operator = (const Device &s){
        if (this==&s){
            return *this;
        }
        strcpy(model, s.model);
        deviceType=s.deviceType;
        casovi=s.casovi;
        godina=s.godina;
        return *this;
    }
    friend ostream & operator <<(ostream & out, Device &s){
        out<<s.model<<"\n"<<Tip[s.deviceType]<<" "<<s.proverka();
        return out;
    }
    static void setPocetniCasovi(float _hours){
            Device::casovi=_hours;
        }
    float proverka(){
        float s=0;
        if (godina>2015){
            s+=2;
        }
        if (deviceType == computer) {
            s+=2;
        }
        return s+Device::casovi;
    }
    int getGodina(){
        return godina;
    }
    ~Device(){}
};
class MobileServis {
    char adress[100];
    Device* devices;
    int n;
public:
    MobileServis() {
          strcpy(this->adress, "address");
          this->devices = nullptr;
          this->n = 0;
      }
    
    MobileServis(char* adress) {
        strcpy(this->adress, adress);
        this->devices = nullptr;
        this->n = 0;
    }

    MobileServis(char* adress_, Device* devices_, int n_) {
        strcpy(adress, adress_);
        devices = new Device[n];
        for (int i = 0; i < n_; ++i) {
            devices[i] = devices_[i];
        }
        n = n_;
    }
    MobileServis(const MobileServis &s){
        strcpy(adress, s.adress);
        devices = new Device[s.n];
        for (int i = 0; i < s.n; ++i) {
            devices[i] = s.devices[i];
        }
        n =s.n;
    }
    MobileServis & operator = (const MobileServis &s){
        if (this==&s){
            return *this;
        }
        delete [] devices;
        strcpy(adress, s.adress);
        devices = new Device[s.n];
        for (int i = 0; i < s.n; ++i) {
            devices[i] = s.devices[i];
        }
        n =s.n;
        return *this;
    }
    MobileServis & operator +=( Device & device){
        if(device.getGodina() < 2000 || device.getGodina() > 2019){
            throw InvalidProductionDate();
        }

        Device * tmp = new Device[n + 1];
        for (int i = 0; i < n; i++){
            tmp[i] = devices[i];
        }
        tmp[n++] = device;

        delete [] devices;
        

       devices = tmp;
       
        return *this;
    }

    void pecatiCasovi() {
          cout << "Ime: " << adress << "\n";
          for(int i = 0; i < n; i++) {
              cout << devices[i]<<endl;
          }
      }

      ~MobileServis() {
          delete [] devices;
      }
  };

  float Device::casovi = 1;


int main()
{
    int testCase;
    cin >> testCase;
    char ime[100];
    int tipDevice;
    int godina;
    int n;
    Device devices[50];
    if (testCase == 1){
        cout << "===== Testiranje na klasite ======" << endl;
        cin >> ime;
        cin >> tipDevice;
        cin >> godina;
        Device ig(ime,(tip)tipDevice,godina);
        cin>>ime;
        MobileServis t(ime);
        cout<<ig;
        }
    if (testCase == 2){
        cout << "===== Testiranje na operatorot += ======" << endl;
        cin>>ime;
        cin >> n;
        MobileServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            try {
                t+=tmp;
            } catch (InvalidProductionDate o) {
                o.message();
            }
        }
        t.pecatiCasovi();
    }
    if (testCase == 3){
        cout << "===== Testiranje na isklucoci ======" << endl;
        cin>>ime;
        cin >> n;
        MobileServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            try {
                t+=tmp;
            } catch (InvalidProductionDate o) {
                o.message();
            }
            
        }
        t.pecatiCasovi();
    }
    if (testCase == 4){
        cout <<"===== Testiranje na konstruktori ======"<<endl;
         cin>>ime;
        cin >> n;
        MobileServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            try {
                t+=tmp;
            } catch (InvalidProductionDate o) {
                o.message();
            }
        }
        MobileServis t2 = t;
        t2.pecatiCasovi();
    }
    if (testCase == 5){
        cout << "===== Testiranje na static clenovi ======" << endl;
        cin>>ime;
        cin >> n;
        MobileServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);

            try {
                t+=tmp;
            } catch (InvalidProductionDate o) {
                o.message();
            }
        }
        t.pecatiCasovi();
        cout << "===== Promena na static clenovi ======" << endl;
        Device::setPocetniCasovi(2);
        t.pecatiCasovi();
    }

        if (testCase == 6){
        cout << "===== Testiranje na kompletna funkcionalnost ======" << endl;
        cin>>ime;
        cin >> n;
        MobileServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            try {
                t+=tmp;
            } catch (InvalidProductionDate o) {
                o.message();
            }
           
        }
        Device::setPocetniCasovi(3);
        MobileServis t2 = t;
        t2.pecatiCasovi();
    }

    return 0;

}


