#include <iostream>
#include "functions.h"
using namespace std;

void exchangeCoins() {
    system("chcp 1251");

    cout << "\n=== РАЗМЕН МОНЕТ ===" << endl;

    int amount;
    cout << "Введите сумму для размена (в рублях): ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Сумма должна быть положительной" << endl;
        return;
    }

    int coins[] = { 10, 5, 2, 1 };
    const char* coin_names[] = { "10 рублей", "5 рублей", "2 рубля", "1 рубль" };

    int original_amount = amount;
    int total_coins = 0;

    cout << "\nРазмен суммы " << original_amount << " руб.:" << endl;
    cout << "--------------------------------" << endl;

    for (int i = 0; i < 4; i++) {
        int count = amount / coins[i];
        if (count > 0) {
            cout << coin_names[i] << ": " << count << " монет" << endl;
            amount %= coins[i];
            total_coins += count;
        }
    }

    if (amount > 0) {
        cout << "Остаток, который нельзя разменять: " << amount << " руб." << endl;
    }

    cout << "--------------------------------" << endl;
    cout << "Общее количество монет: " << total_coins << endl;
    cout << "Эффективность размена: " << (total_coins > 0 ?
        (float)original_amount / total_coins : 0) << " руб./монету" << endl;
}