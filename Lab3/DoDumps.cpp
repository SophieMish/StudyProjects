
// Dump

#include <iostream>
#include <bitset>

int exit_prog();

using namespace std;

template <typename T>
void dump(T n, char base,char upperCase) {

    if (base == 'b') {
        T mask;
        int size(8 * sizeof(T) - 1);
        cout <<"Number in binary radix: ";

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

    }else if (base == 'o' ) {
        T mask;
        int size((8 * sizeof(T)) / 3);
        int base(3 * ((8 * sizeof(T) / 3) - 1));
        cout << "Number in octal radix: ";

        switch (sizeof(T)) {
            case 1 :
                mask = 070;
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
            cout<<char(((n & mask) >> base - i * 3) + 48);
        cout << endl;

    } else if (base == 'h') {
        T mask;
        int size(2 * sizeof(T) - 1);
        int base(8 * (sizeof(T) - 1));
        int digit((n >> (8 * sizeof(T) - 4)) & 0xf);
        cout <<"Number in haxadecimal radix: ";
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
        if ( upperCase == 'Y') {
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
    else {
        cout << "Invalid data" << endl;
        exit_prog();
    }
}

int main() {
    int n;
    char radix;
    char size_of_data;

    do {
        cout << "\nEnter your number: ";
        cin >> n;
        if (cin.good())
            break;
        else {
            cout << "Invalid data!\n";
            cin.clear();
            while (cin.get() != '\n');
        }
    } while (1);

    cout << "\nEnter the radix(binary - b, octal - o, hexdecimal - h): ";
    cin >> radix;

    cout << "\nEnter the size of data that your need: (char - c, short - s, int or long - i,all types - a): ";
    cin >> size_of_data;

    cout << endl;
    char ans;
    if (size_of_data == 'c') {
        if (radix == 'h') {
            cout << "Do you want to convert letters in upper case? Y or N: ";
            cin >> ans;
            dump<char>(n, radix, ans);
        } else
            dump<char>(n, radix, 0);
    }
    else if (size_of_data == 's') {
        if (radix == 'h') {
            cout << "Do you want to convert letters in upper case? Y or N: ";
            cin >> ans;
            dump<short int>(n, radix, ans);
        } else
            dump<short int>(n, radix, 0);
    }
    else if (size_of_data == 'i') {
        if (radix == 'h') {
            cout << "Do you want to convert letters in upper case? Y or N: ";
            cin >> ans;
            dump<int>(n, radix, ans);
        } else
            dump<int>(n, radix, 0);
    }
    else if(size_of_data == 'a') {
        if (radix == 'h') {
            cout<<"Do you want to convert letters in upper case? Y or N: ";
            cin>>ans;
            cout<<"----------------------------------------------"<<endl;
            dump<char>(n, radix,ans);
            dump<short int>(n, radix,ans);
            dump<int>(n, radix,ans);
            cout<<"----------------------------------------------"<<endl;
        } else {
            cout<<"----------------------------------------------"<<endl;
            dump<char>(n, radix,0);
            dump<short int>(n, radix,0);
            dump<int>(n, radix,0);
            cout<<"----------------------------------------------"<<endl;
        }
    } else {
        cout << "Impossible to calculate. Please check your input and type again" << endl;
        cin.clear();
        while (cin.get() != '\n');
        main();
    }
    exit_prog();
}

int exit_prog() {
    char ans;
    cout << "\nDo you want to continue?(Y or N)";
    cin >> ans;
    if (ans == 'Y') {
        main();
    } else {
        return 0;
    }
}



