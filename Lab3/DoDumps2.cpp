
#include <iostream>
#include <bitset>

char exit_prog();

using namespace std;

template<typename T>
void binary_dump(T n) {
    T mask;
    int size(8 * sizeof(T) - 1);
    cout << "Number in binary radix: ";

    switch (sizeof(T)) {
        case 1 :
            mask = 0100;
            break;

        case 2 :
            mask = 040000;
            break;

        case 4 :
            mask = 010000000000;
            break;
    }
    cout << (n < 0 ? '1' : '0');
    for (int i = 0; i < size; ++i) {
        cout << (n & mask ? '1' : '0');
        mask >>= 1;
    }
    cout << endl;
}

template<typename T>
void octal_dump(T n) {
    T mask;
    int size((8 * sizeof(T)) / 3);
    int base(3 * ((8 * sizeof(T) / 3) - 1));
    cout << "Number in octal radix: ";

    switch (sizeof(T)) {
        case 1 :
            mask = 0070;
            cout << char(((n >> 6) & 03) + 48);
            break;

        case 2 :
            mask = 070000;
            cout << (n < 0 ? '1' : '0');
            break;

        case 4 :
            mask = 07000000000;
            cout << char(((n >> 30) & 03) + 48);
            break;
    }
    for (int i = 0; i < size; ++i, mask >>= 3)
        cout << char(((n & mask) >> base - i * 3) + 48);
    cout << endl;
}

template<typename T>
void hex_dump(T n, char upperCase) {
    T mask;
    int size(2 * sizeof(T) - 1);
    int base(8 * (sizeof(T) - 1));
    int digit((n >> (8 * sizeof(T) - 4)) & 0xf);
    cout << "Number in haxadecimal radix: ";

    switch (sizeof(T)) {
        case 1 :
            mask = 0xf;
            break;

        case 2 :
            mask = 0xf00;
            break;

        case 4 :
            mask = 0xf000000;
            break;
    }
    if (upperCase == 'Y') {
        cout << (digit > 9 ? char(digit + 55) : char(digit + 48));
        for (int i = 0; i < size; ++i, mask >>= 4) {
            digit = (n & mask) >> base - i * 4;
            cout << (digit > 9 ? char(digit + 55) : char(digit + 48));
        }
    } else {
        cout << (digit > 9 ? char(digit + 87) : char(digit + 48));
        for (int i = 0; i < size; ++i, mask >>= 4) {
            digit = (n & mask) >> base - i * 4;
            cout << (digit > 9 ? char(digit + 87) : char(digit + 48));
        }
    }
    cout << endl;
}

template<typename T>
void call_dump(T n, char radix) {
    if (radix == 'b')
        binary_dump(n);
    else if (radix == 'o')
        octal_dump(n);
    else if (radix == 'h' ) {
        char upperCase;
        cout << "Do you want to convert next number to uppercase?(Will be suggested for every number) Y or N:  ";
        cin >> upperCase;
        if (upperCase == 'Y' | upperCase == 'N')
            hex_dump(n, upperCase);
        else {
            cout << "Default settings" << endl;
            hex_dump(n, 'N');
        }
    } else if (radix == 'a') {
        binary_dump(n);
        octal_dump(n);
        hex_dump(n, 'N');
        hex_dump(n, 'Y');
    } else {
        cout << "Impossible to calculate. Please check your data and type again\n" << endl;
        cin.clear();
        while (cin.get() != '\n');
        exit_prog();
    }
}

int main() {
    int n;
    char radix;
    char size_of_data;

    cout << "\nEnter your number: ";
    do {
        cin >> n;
        if (cin.good())
            break;
        else {
            cout << "Invalid data! Please check your data and type again! \n Enter your number:  ";
            cin.clear();
            while (cin.get() != '\n');
        }
    } while (2);

    cout << "\nEnter the radix(binary - b, octal - o, hexdecimal - h, all bases - a): ";
    cin >> radix;

    cout << "\nEnter the size of data that your need: (char - c, short - s, int or long - i,all types - a): ";
    cin >> size_of_data;

    cout << endl;
    if (size_of_data == 'c') {
        call_dump<char>(n, radix);
    } else if (size_of_data == 's') {
        call_dump<short int>(n, radix);
    } else if (size_of_data == 'i') {
        call_dump<int>(n, radix);
    } else if (size_of_data == 'a') {
        cout << "--------------------------------------------------------------------------------------" << endl;
        call_dump<char>(n, radix);
        cout << "--------------------------------------------------------------------------------------" << endl;
        call_dump<short int>(n, radix);
        cout << "--------------------------------------------------------------------------------------" << endl;
        call_dump<int>(n, radix);
        cout << "--------------------------------------------------------------------------------------" << endl;
    } else {
        cout << "Impossible to calculate. Please check your data and type again!\n" << endl;
        cin.clear();
        while (cin.get() != '\n');
        main();
    }
    exit_prog();
}

char exit_prog() {
    cout << "\nDo you want to continue?(Y or N)";
    char i;
    cin >> i;
    if (i == 'Y') {
        main();
    } else return 0;
}


