#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

// TODO...
class Image {
protected:
    char* name;
    char nameOwner[50];
    int height, width;
public:
    Image(const char* name_ = "untitled", const char* nameOwner_ = "unknown", int height_ = 800, int width_ = 800) {
        name = new char[strlen(name_) + 1];
        strcpy(name, name_);
        strcpy(nameOwner, nameOwner_);
        height = height_;
        width = width_;

    }
    Image(const Image& s) {
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
        strcpy(nameOwner, s.nameOwner);
        height = s.height;
        width = s.width;
    }
    Image& operator = (const Image& s) {
        if (this == &s) {
            return *this;
        }
        delete[]name;
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
        strcpy(nameOwner, s.nameOwner);
        height = s.height;
        width = s.width;
        return *this;
    }
    virtual int fileSize() {
        return height * width * 3;
    }


    friend ostream& operator << (ostream& out, Image& s) {
        out << s.name << " " << s.nameOwner << " " << s.fileSize() << endl;
        return out;
    }
    bool operator > (Image& s) {
        if ((fileSize() > s.fileSize()))
            return true;
        else { return false; }
    }




};
class TransparentImage :public Image {
    bool transparent;
public:
    TransparentImage(const char* name_ = "untitled", const char* nameOwner_ = "unknown", int height_ = 800, int width_ = 800, bool transparent_ = true)
        : Image(name_, nameOwner_, height_, width_) {
        transparent = transparent_;
    }
    TransparentImage(const TransparentImage& s) : Image(s.name, s.nameOwner, s.height, s.width) {
        transparent = s.transparent;
    }
    TransparentImage operator = (const TransparentImage& s) {
        if (this == &s) {
            return *this;
        }
        Image::operator=(s);
        transparent = s.transparent;
        return *this;
    }
    virtual int fileSize() {
        if (transparent == true) {
            return width * height * 4;
        }
        else {
            return width * height + ((width * height) / 8);
        }
    }

};
class Folder {
    char name[255];
    char folderOwner[50];
    Image* niza[100];
    int n = 0;
public:
    Folder() {
        strcpy(folderOwner, "unknown");
    }
    Folder(const char* name_, const char* folderOwner_) {
        strcpy(name, name_);
        strcpy(folderOwner, folderOwner_);

    }
    Folder(const Folder& s) {
        strcpy(name, s.name);
        strcpy(folderOwner, s.folderOwner);
    }
    int folderSize() {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            TransparentImage* tmp = dynamic_cast<TransparentImage*>(niza[i]);
            if (tmp == nullptr) {
                sum += niza[i]->fileSize();
            }
            else {
                sum += tmp->fileSize();
            }
        }
        return sum;
    }
    Image* getMaxFile() {
        int idx = 0;
        int max = 0;
        for (int i = 0; i < n; i++) {
            int golemina;

            TransparentImage* tmp = dynamic_cast<TransparentImage*>(niza[i]);
            if (tmp == nullptr) {
                golemina = niza[i]->fileSize();
            }
            else {
                golemina = tmp->fileSize();
            }
            if (golemina > max) {
                max = golemina;
                idx = i;

            }
        }
        return niza[idx];
    }

    Folder& operator += (Image& s) {
        niza[n] = &s;
        n++;
        return *this;
    }
    friend ostream& operator <<(ostream& out, Folder& s) {
        out << s.name << " " << s.folderOwner << endl;
        cout << "--" << endl;

        for (int i = 0; i < s.n; i++) {
            cout << *s.niza[i];
        }


        cout << "--" << endl;
        cout << "Folder size: " << s.folderSize() << endl;
        return out;
    }
    
     Image* operator[](int x) {
        if (x >= n) return nullptr;
        return niza[x];
    }
   
};

Folder* max_folder_size(Folder* niza, int n) {
    int maxGol = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (niza[i].folderSize() > maxGol) {
            maxGol = niza[i].folderSize();
            idx = i;
        }
    }
    return &niza[idx];
}

int main() {

    int tc; // Test Case

    char name[255];
    char user_name[51];
    int w, h;
    bool tl;

    cin >> tc;

    if (tc == 1) {
        // Testing constructor(s) & operator << for class File

        cin >> name;
        cin >> user_name;
        cin >> w;
        cin >> h;


        Image f1;

        cout << f1;

        Image f2(name);
        cout << f2;

        Image f3(name, user_name);
        cout << f3;

        Image f4(name, user_name, w, h);
        cout << f4;
    }
    else if (tc == 2) {
        // Testing constructor(s) & operator << for class TextFile
        cin >> name;
        cin >> user_name;
        cin >> w >> h;
        cin >> tl;

        TransparentImage tf1;
        cout << tf1;

        TransparentImage tf4(name, user_name, w, h, tl);
        cout << tf4;
    }
    else if (tc == 3) {
        // Testing constructor(s) & operator << for class Folder
        cin >> name;
        cin >> user_name;

        Folder f3(name, user_name);
        cout << f3;
    }
    else if (tc == 4) {
        // Adding files to folder
        cin >> name;
        cin >> user_name;

        Folder dir(name, user_name);

        Image* f;
        TransparentImage* tf;

        int sub, fileType;

        while (1) {
            cin >> sub; // Should we add subfiles to this folder
            if (!sub) break;

            cin >> fileType;
            if (fileType == 1) { // Reading File
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                f = new Image(name, user_name, w, h);
                dir += *f;
            }
            else if (fileType == 2) {
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                cin >> tl;
                tf = new TransparentImage(name, user_name, w, h, tl);
                dir += *tf;
            }
        }
        cout << dir;
    }
    else if (tc == 5) {
        // Testing getMaxFile for folder

        cin >> name;
        cin >> user_name;

        Folder dir(name, user_name);

        Image* f;
        TransparentImage* tf;

        int sub, fileType;

        while (1) {
            cin >> sub; // Should we add subfiles to this folder
            if (!sub) break;

            cin >> fileType;
            if (fileType == 1) { // Reading File
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                f = new Image(name, user_name, w, h);
                dir += *f;
            }
            else if (fileType == 2) {
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                cin >> tl;
                tf = new TransparentImage(name, user_name, w, h, tl);
                dir += *tf;
            }
        }
        cout << *(dir.getMaxFile());
    }
    else if (tc == 6) {
        // Testing operator [] for folder

        cin >> name;
        cin >> user_name;

        Folder dir(name, user_name);

        Image* f;
        TransparentImage* tf;

        int sub, fileType;

        while (1) {
            cin >> sub; // Should we add subfiles to this folder
            if (!sub) break;

            cin >> fileType;
            if (fileType == 1) { // Reading File
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                f = new Image(name, user_name, w, h);
                dir += *f;
            }
            else if (fileType == 2) {
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                cin >> tl;
                tf = new TransparentImage(name, user_name, w, h, tl);
                dir += *tf;
            }
        }

        cin >> sub; // Reading index of specific file
        cout<< *dir[sub];
    }
    else if (tc == 7) {
        // Testing function max_folder_size
        int folders_num;

        Folder dir_list[10];

        Folder dir;
        cin >> folders_num;

        for (int i = 0; i < folders_num; ++i) {
            cin >> name;
            cin >> user_name;
            dir = Folder(name, user_name);


            Image* f;
            TransparentImage* tf;

            int sub, fileType;

            while (1) {
                cin >> sub; // Should we add subfiles to this folder
                if (!sub) break;

                cin >> fileType;
                if (fileType == 1) { // Reading File
                    cin >> name;
                    cin >> user_name;
                    cin >> w >> h;
                    f = new Image(name, user_name, w, h);
                    dir += *f;
                }
                else if (fileType == 2) {
                    cin >> name;
                    cin >> user_name;
                    cin >> w >> h;
                    cin >> tl;
                    tf = new TransparentImage(name, user_name, w, h, tl);
                    dir += *tf;
                }
            }
            dir_list[i] = dir;
        }

        cout << *max_folder_size(dir_list, folders_num);
    }
    return 0;
};
