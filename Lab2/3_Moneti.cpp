#include <iostream>
#include "functions.h"
using namespace std;

void exchangeCoins() {
    system("chcp 1251");

    cout << "\n=== ������ ����� ===" << endl;

    int amount;
    cout << "������� ����� ��� ������� (� ������): ";
    cin >> amount;

    if (amount <= 0) {
        cout << "����� ������ ���� �������������" << endl;
        return;
    }

    int coins[] = { 10, 5, 2, 1 };
    const char* coin_names[] = { "10 ������", "5 ������", "2 �����", "1 �����" };

    int original_amount = amount;
    int total_coins = 0;

    cout << "\n������ ����� " << original_amount << " ���.:" << endl;
    cout << "--------------------------------" << endl;

    for (int i = 0; i < 4; i++) {
        int count = amount / coins[i];
        if (count > 0) {
            cout << coin_names[i] << ": " << count << " �����" << endl;
            amount %= coins[i];
            total_coins += count;
        }
    }

    if (amount > 0) {
        cout << "�������, ������� ������ ���������: " << amount << " ���." << endl;
    }

    cout << "--------------------------------" << endl;
    cout << "����� ���������� �����: " << total_coins << endl;
    cout << "������������� �������: " << (total_coins > 0 ?
        (float)original_amount / total_coins : 0) << " ���./������" << endl;
}