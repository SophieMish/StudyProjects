#include <iostream>

using namespace std;

void binaryDump(short int n, int *p) {
    short int mask(040000);
    p[15] = n < 0 ? 1 : 0; // 15
    for (int i = 0; i < 15; ++i, mask >>= 1)
        p[15 - i - 1] = n & mask ? 1 : 0; // 14 - 0
}

template<typename T>
void print(int *p) {
    int size(8 * sizeof(T));
    for (int i = 0; i < size; ++i) // 31 - 0 or 63 - 0
        cout << p[size - i - 1];
    cout << endl;
}

template<typename T>
void printFields(int *p) // binary fields S, E, M
{
    int size(8 * sizeof(T));
    cout<<(p[size - 1] == 1) ? 1 :  0;
    switch (sizeof(T)) {
        case 4 :
            cout << ' ';
            for (int i = 0; i < 8; ++i) // 30 - 23
                cout << p[size - 1 - i - 1];
            cout << ' ';
            for (int i = 0; i < 23; ++i) // 22 - 0
                cout << p[size - 8 - i - 2];
            cout << "\nS     E              M\n" << endl;
            break;
        case 8 :
            cout << ' ';
            for (int i = 0; i < 11; ++i) // 62 - 52
                cout << p[size - 1 - i - 1];
            cout << ' ';
            for (int i = 0; i < 52; ++i) // 51 - 0
                cout << p[size - 11 - i - 2];
            cout << "\nS      E                          M\n" << endl;
            break;
    }
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
void unpack(int *p) {
    int S = 0;
    T M = 0;
    int E = 0;
    T result;
    T power;

    switch (sizeof(T)) {
        case 4: {
            p[31] == 1 ? S = -1 : S = 1;
            cout << "S = " << S << endl;

            power = 1;
            for (int i = 23; i < 31; i++) {
                E += p[i] * power;
                power *= 2;
            }
            cout << "E = " << E << endl;
            E -= 127;

            power = 0.5;
            for (int i = 22; i >= 0; i--) {
                M += p[i] * power;
                power *= 0.5;
            }
            cout << "M = " <<fixed<< M << endl;

            result = S * (1 + M) * pow(2, E);
            cout << "Result = " << fixed << result << endl;
            cout << "Result in scientific form: " << scientific << result << endl;
            break;
        }
        case 8: {
            p[63] == 1 ? S = -1 : S = 1;
            cout << "S = " << S << endl;

            power = 1024;
            for (int i = 62; i > 51; i--) {
                E += p[i] * power;
                power /= 2;
            }
            cout << "E = " << E << endl;
            E -= 1023;

            power = 0.5;
            for (int i = 51; i >= 0; i--) {
                M += p[i] * power;
                power *= 0.5;
            }
            cout << "M = " <<fixed<< M << endl;

            result = S * (1 + M) * pow(2, E);
            cout << "Result = " << fixed << result << endl;
            cout << "Result in scientific form: " << scientific << result << endl;
            break;
        }
    }
}

int main() {
    int *p;
    float f = -122.567;
    cout << "\nThe FLOAT number: " <<fixed<< f << endl;
    p = new int[8 * sizeof(float)];
    pack<float>(&f, p);
    cout << "The float number in binary radix:  ";
    print<float>(p);
    printFields<float>(p);
    unpack<float>(p);
    delete[] p;

    cout << "------------------------------------------------------------------------------------------------" << endl;

    double d = 122.567;
    cout << "The DOUBLE number: "<<fixed<< d << endl;
    p = new int[8 * sizeof(double)];
    pack<double>(&d, p);
    cout << "The  double number in binary:  ";
    print<double>(p);
    printFields<double>(p);
    unpack<double>(p);
    delete[] p;
    return 0;
}





