#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
    system("chcp 1251");

    int choice;
    do {
        cout << "\n=== ���� ===" << endl;
        cout << "1. �������� ������������� �����" << endl;
        cout << "2. �������� �����" << endl;
        cout << "3. ������ �����" << endl;
        cout << "4. �������� �� ������" << endl;
        cout << "0. �����" << endl;
        cout << "�������� �������: ";
        cin >> choice;

        switch (choice) {
        case 1: checkSuperPrime(); break;
        case 2: checkSnils(); break;
        case 3: exchangeCoins(); break;
        case 4: shootTarget(); break;
        case 0: cout << "�����..." << endl; break;
        default: cout << "�������� �����!" << endl;
        }
    } while (choice != 0);

    return 0;
}