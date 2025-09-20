#include <iostream>
#include <string>
#include "functions.h"
using namespace std;

void checkSnils() {
    system("chcp 1251");

    cout << "\n=== ПРОВЕРКА НОМЕРА СНИЛС ===" << endl;

    string snils;
    cout << "Введите номер СНИЛС (11 цифр без пробелов и дефисов): ";
    cin >> snils;

    // Проверка длины
    if (snils.length() != 11) {
        cout << "Ошибка: номер должен содержать ровно 11 цифр" << endl;
        return;
    }

    // Проверка что все символы - цифры
    for (char c : snils) {
        if (c < '0' || c > '9') {
            cout << "Ошибка: номер должен содержать только цифры" << endl;
            return;
        }
    }

    // Проверка на одинаковые цифры подряд (первые 9 цифр)
    for (int i = 0; i < 7; i++) {
        if (snils[i] == snils[i + 1] && snils[i] == snils[i + 2]) {
            cout << "Ошибка: обнаружено более двух одинаковых цифр подряд" << endl;
            return;
        }
    }

    // Расчет контрольного числа
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        int digit = snils[i] - '0';
        sum += digit * (9 - i);
    }

    int calculated_control;
    if (sum < 100) {
        calculated_control = sum;
    }
    else if (sum == 100 || sum == 101) {
        calculated_control = 0;
    }
    else {
        int remainder = sum % 101;
        if (remainder < 100) {
            calculated_control = remainder;
        }
        else {
            calculated_control = 0;
        }
    }

    // Получение введенного контрольного числа
    int input_control = (snils[9] - '0') * 10 + (snils[10] - '0');

    cout << "\nРезультат проверки:" << endl;
    cout << "Основная часть: " << snils.substr(0, 9) << endl;
    cout << "Контрольное число: " << (input_control < 10 ? "0" : "") << input_control << endl;
    cout << "Рассчитанное контрольное число: " << (calculated_control < 10 ? "0" : "") << calculated_control << endl;
    cout << "Сумма произведений: " << sum << endl;

    if (calculated_control == input_control) {
        cout << "✓ Номер СНИЛС валиден" << endl;
    }
    else {
        cout << "✗ Неверное контрольное число" << endl;
    }
}