
#include <iostream>
#include <bitset>

using namespace std;


int invert_numbers(char N, int tmp) {
    (tmp == 0) ? N ^= char(0125) : N ^= char(0252);
    return int(N);

}


int main() {
    int tmp;
    char ans;
    int N;
    cout << "Enter you number:  ";
    cin >> N;
    ans = char(N);
    cout << "Converted to 8-digit number: " << int(ans) << endl;
    cout << "  Binary: " << bitset<8>(int(ans)) << endl;
    cout << "  Hexadecimal:  " << hex << int(ans) << endl;
    cout << "  Octal:  " << oct << int(ans) << endl;

    cout << "What numbers do you want to invert even or odd(0 or 1)?:  ";
    cin >> tmp;
    while (tmp != 0 && tmp != 1) {
        cout << "Please, check the input. It should be from 0 or 1. Type again: ";
        cin >> tmp;
    }
    N=invert_numbers(ans, tmp);
    cout << "Result: " << dec <<  N << endl;

    cout << "Do you want to continue? Y or N: " << endl;
    cin >> ans;
    if (ans == 'Y') {
        main();
    } else {
        return 0;
    }
}


