#include <iostream>
#include <cstring>
using namespace std;

class FudbalskaEkipa {
protected:
    char nameCoach[100];
    int goals[10];

public:
    FudbalskaEkipa(char *nameCoach_, int *goals_) {

        strcpy(nameCoach, nameCoach_);
        for (int i = 0; i < 10; i++) {
            goals[i] = goals_[i];
        }
    }
    FudbalskaEkipa(const FudbalskaEkipa &s) {

        strcpy(nameCoach, s.nameCoach);
        for (int i = 0; i < 10; i++) {
            goals[i] = s.goals[i];
        }
    }
    FudbalskaEkipa &operator=(const FudbalskaEkipa &s) {
        if (this == &s) {
            return *this;
        }
        strcpy(nameCoach, s.nameCoach);
        for (int i = 0; i < 10; i++) {
            goals[i] = s.goals[i];
        }
        return *this;
    }

    FudbalskaEkipa &operator+=(int lastMatchGoals) {
        for (int i = 0; i < 9; i++) {
            goals[i] = goals[i + 1];
        }
        goals[9] = lastMatchGoals;
        return *this;
    }

    char *getnameCoach() {
        return nameCoach;
    }

    virtual int uspeh() = 0;

    bool operator>(FudbalskaEkipa &s) {
        return uspeh() > s.uspeh();
    }
};

class Klub : public FudbalskaEkipa {
    char nameClub[100];
    int num_tituls;

public:
    Klub(char *nameCoach_, int *goals_, char *nameClub_, int num_tituls_)
        : FudbalskaEkipa(nameCoach_, goals_) {
        strcpy(nameClub, nameClub_);
        num_tituls = num_tituls_;
    }
    Klub(const Klub &s)
        : FudbalskaEkipa(s) {
        strcpy(nameClub, s.nameClub);
        num_tituls = s.num_tituls;
    }
    Klub &operator=(const Klub &s) {
        if (this == &s) {
            return *this;
        }
        FudbalskaEkipa::operator=(s);
        strcpy(nameClub, s.nameClub);
        num_tituls = s.num_tituls;
        return *this;
    }

    int uspeh() override {
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            sum += goals[i];
        }
        return (sum * 3) + (num_tituls * 1000);
    }
    char *getNameClub() {
        return nameClub;
    }
};

class Reprezentacija : public FudbalskaEkipa {
    char nameCountry[100];
    int games;

public:
    Reprezentacija(char *nameCoach_, int *goals_, char *nameCountry_, int games_)
        : FudbalskaEkipa(nameCoach_, goals_) {
        strcpy(nameCountry, nameCountry_); // Fix here, copy country name
        games = games_;
    }
    Reprezentacija(const Reprezentacija &s)
        : FudbalskaEkipa(s) {
        strcpy(nameCountry, s.nameCountry); // Fix here, copy country name
        games = s.games;
    }

    Reprezentacija &operator=(const Reprezentacija &s) {
        if (this == &s) {
            return *this;
        }
        FudbalskaEkipa::operator=(s);
        strcpy(nameCountry, s.nameCountry); // Fix here, copy country name
        games = s.games;
        return *this;
    }
    int uspeh() override {
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            sum += goals[i];
        }
        return (sum * 3) + (games * 50);
    }
    char *getNameCountry() {
        return nameCountry;
    }
};

ostream &operator<<(ostream &out, FudbalskaEkipa &s) {
    if (dynamic_cast<Klub *>(&s)) {
        out << dynamic_cast<Klub *>(&s)->getNameClub();
    } else if (dynamic_cast<Reprezentacija *>(&s)) {
        out << dynamic_cast<Reprezentacija *>(&s)->getNameCountry();
    }
    out <<endl<< s.getnameCoach() << endl << s.uspeh() << endl;
    return out;
}

void najdobarTrener(FudbalskaEkipa **ekipi, int n) {
    int tmp = -1;

    for (int i = 0; i < n; i++) {
        if (tmp == -1 || ekipi[i]->uspeh() > ekipi[tmp]->uspeh()) {
            tmp = i;
        }
    }
    if (tmp == -1) {
        return;
    }
    cout << *ekipi[tmp];
}

int main() {
    int n;
    cin >> n;
    FudbalskaEkipa **ekipi = new FudbalskaEkipa *[n];
    char coach[100];
    int goals[10];
    char x[100];
    int tg;
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        cin.getline(coach, 100);
        cin.getline(coach, 100);
        for (int j = 0; j < 10; ++j) {
            cin >> goals[j];
        }
        cin.getline(x, 100);
        cin.getline(x, 100);
        cin >> tg;
        if (type == 0) {
            ekipi[i] = new Klub(coach, goals, x, tg);
        } else if (type == 1) {
            ekipi[i] = new Reprezentacija(coach, goals, x, tg);
        }
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== DODADI GOLOVI =====" << endl;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        cout << "dodavam golovi: " << p << endl;
        *ekipi[i] += p;
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== NAJDOBAR TRENER =====" << endl;
    najdobarTrener(ekipi, n);
    for (int i = 0; i < n; ++i) {
        delete ekipi[i];
    }
    delete[] ekipi;
    return 0;
}
