#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
    system("chcp 1251");

    int choice;
    do {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Проверка суперпростого числа" << endl;
        cout << "2. Проверка СНИЛС" << endl;
        cout << "3. Размен монет" << endl;
        cout << "4. Стрельба по мишени" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите задание: ";
        cin >> choice;

        switch (choice) {
        case 1: checkSuperPrime(); break;
        case 2: checkSnils(); break;
        case 3: exchangeCoins(); break;
        case 4: shootTarget(); break;
        case 0: cout << "Выход..." << endl; break;
        default: cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);

    return 0;
}