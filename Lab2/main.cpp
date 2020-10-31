
#include <iostream>

using namespace std;

int enter_number() {
    int N;
    cout << "Enter you number:  ";
    cin >> N;
    if ((N > -128) & (N < 127)) {
        cout << "Hexadecimal:  " << hex << N << endl;
        cout << "  Octal:  " << oct << N << endl;
        return N;
    }
    cout << "The number is out of range" << endl;
    enter_number();
    return 0;
}

int set(int M, int N) {
    return N ^= M;
}

int clear(int M, int N) {
    return N &= M;
}

int main() {
    int M;
    int N;
    bool key = true;

    N = enter_number();
    N < 0 ? key : key = false;

    cout << "\nEnter your 1 mask:  ";
    scanf_s("%o", &M);
    N = clear(M, N);
    cout << dec << "The first operation:  " << N << endl;

    cout << "Enter your 2 mask:  ";
    scanf_s("%o", &M);
    N = set(M, N);
    cout << "The second operation:  " << N << endl;

    if (key) {
        cout << "Enter your 3 mask:  ";
        scanf_s("%o", &M);
        N = set(M, N);
    }
    cout << " Result: " << N << endl;

    cout << "Do you want to continue? Y or N: " << endl;
    char ans;
    cin >> ans;
    if (ans == 'Y') {
        main();
    } else {
        return 0;
    }
}








