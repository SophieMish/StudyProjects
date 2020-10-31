#include <iostream>
#include <bitset>
#include <fstream>

using namespace std;

static ofstream dumpFile;
static ofstream saveFile;

int exit_prog();

void binaryDump(short int n, int *p) {
    short int mask(040000);
    p[15] = n < 0 ? 1 : 0;
    for (int i = 0; i < 15; ++i, mask >>= 1)
        p[15 - i - 1] = n & mask ? 1 : 0;
}

template<typename T>
void print(int *p) {
    int size(8 * sizeof(T));
    for (int i = 0; i < size; ++i)
        cout << p[size - i - 1];
}

template<typename T>
void pack(T *pFloat, int *p) {
    short int *pShort = reinterpret_cast<short int *>(pFloat);
    int size(sizeof(T) / sizeof(short int));
    int index;
    for (int i = 0; i < size; ++i) {
        index = size - i - 1;
        binaryDump(pShort[index], p + 16 * index);
    }
}

template<typename T>
int writeFile(int *p) {
    int size = sizeof(T) * 8;
    if (!dumpFile) {
        cout << "Invalid opening file!\n";
        return -1;
    } else {
        for (int i = size - 1; i >= 0; i--) {
            dumpFile << p[i];
            saveFile << p[i];
        }
        dumpFile << endl;
        saveFile << endl;
    }
    return 0;
}

void readFile() {
    const int n = 20000;
    char buff[n];
    ifstream file;
    file.open("dumps.txt");
    if (!file) {
        cout << "Invalid opening file!\n";
    } else {
        while (file.getline(buff, n))
            cout << buff << endl;
    }
    file.close();
}

int main() {
    int *p;
    float f = 0;
    do {
        cout << "Enter the FLOAT number: ";
        cin >> f;
        if (cin.good())
            break;
        else {
            cout << "Invalid data!\n";
            cin.clear();
            while (cin.get() != '\n');
        }
    } while (true);

    p = new int[8 * sizeof(float)];
    pack<float>(&f, p);
    saveFile.open("saveDumps.txt",ios::app);
    saveFile << "FLOAT: "<< f <<" - ";
    dumpFile.open("dumps.txt");
    writeFile<float>(p);
    cout<<endl;
    cout << "The float number in binary radix displayed using cout: ";
    print<float>(p);
    delete[] p;
    cout << endl;
    cout << "The dump that was written in the file: ";
    readFile();
    dumpFile.close();

    cout << "------------------------------------------------------------------------------------------------" << endl;

    double d = 0;
    do {
        cout << "Enter the DOUBLE number: ";
        cin >> d;
        if (cin.good())
            break;
        else {
            cout << "Invalid data!\n";
            cin.clear();
            while (cin.get() != '\n');
        }
    } while (true);

    p = new int[8 * sizeof(double)];
    pack<double>(&d, p);
    saveFile <<"DOUBLE: "<< d<<" - ";
    dumpFile.open("dumps.txt");
    writeFile<double>(p);
    cout<<endl;
    cout << "The double number in binary radix displayed using cout: ";
    print<double>(p);
    cout << "The dump that was written in the file: ";
    readFile();
    delete[] p;

    cout<<"\nThe file with dumps - dumps.txt"<<endl;
    const int n = 20000;
    char buff[n];
    ifstream readSaveFile;
    readSaveFile.open("saveDumps.txt");
    if (!readSaveFile) {
        cout << "Invalid opening file!\n";
    } else {
        while (readSaveFile.getline(buff, n))
            cout << buff << endl;
    }
    saveFile.close();
    dumpFile.close();
    readSaveFile.close();
    exit_prog();
}

int exit_prog() {
    char ans;
    cout << "\nDo you want to continue?(Y or N)";
    cin >> ans;
    while (ans !='Y' & ans!='N') {
        cout << "Invalid data!\n";
        cin.clear();
        while (cin.get() != '\n');
        cout << "\nDo you want to continue?(Y or N)";
        cin >> ans;
    }
    if (ans == 'Y') {
        main();
    } else {
        cout<<"Save the file?(Y or N?): ";
        cin >> ans;
        while (ans !='Y' & ans!='N'){
            cout<<"Invalid data!\n";
            cin.clear();
            while (cin.get() != '\n');
            cout<<"Save the file?(Y or N?): ";
            cin >> ans;
        }
        if (ans == 'Y'){
            return 0;
        } else {
            saveFile.open("saveDumps.txt");
            saveFile.close();
            return 0;
        }
    }
    return 0;
}



