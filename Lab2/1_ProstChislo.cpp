#include <iostream>
#include <cmath>
#include "functions.h"
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }

    return true;
}

bool isSuperPrime(int n) {
    if (!isPrime(n)) return false;

    int position = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            position++;
        }
    }

    return isPrime(position);
}

void checkSuperPrime() {
    system("chcp 1251");

    cout << "\n=== ПРОВЕРКА СУПЕРПРОСТОГО ЧИСЛА ===" << endl;

    int number;
    cout << "Введите число для проверки: ";
    cin >> number;

    if (number < 2) {
        cout << "Число должно быть больше или равно 2" << endl;
        return;
    }

    cout << "\nРезультат проверки:" << endl;
    cout << "Число " << number;

    if (isSuperPrime(number)) {
        cout << " является суперпростым" << endl;
    }
    else {
        cout << " не является суперпростым" << endl;
    }

    // Дополнительная информация
    cout << "\nДополнительная информация:" << endl;
    if (isPrime(number)) {
        cout << "- Число простое" << endl;

        int position = 0;
        for (int i = 2; i <= number; i++) {
            if (isPrime(i)) position++;
        }
        cout << "- Позиция в последовательности простых чисел: " << position << endl;
        cout << "- Позиция " << (isPrime(position) ? "простая" : "не простая") << endl;
    }
    else {
        cout << "- Число составное" << endl;
    }
}