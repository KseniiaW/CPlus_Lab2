#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "functions.h"
using namespace std;

int calculateScore(double x, double y, double centerX, double centerY) {
    // Считаем расстояние от точки выстрела до центра мишени
    double relX = x - centerX;
    double relY = y - centerY;
    double distance = sqrt(relX * relX + relY * relY);

    if (distance <= 0.5) return 10;      // Яблочко
    else if (distance <= 1.0) return 8;  // Центр
    else if (distance <= 1.5) return 6;  // Внутреннее кольцо
    else if (distance <= 2.0) return 4;  // Среднее кольцо
    else if (distance <= 2.5) return 2;  // Внешнее кольцо
    else return 0;                       // Мимо
}

string getShooterLevel(int totalScore, int shots) {
    if (shots == 0) return "Не стрелял";

    double average = (double)totalScore / shots;

    if (average >= 8.0) return "СНАЙПЕР";
    else if (average >= 6.0) return "ОТЛИЧНЫЙ СТРЕЛОК";
    else if (average >= 4.0) return "ХОРОШИЙ СТРЕЛОК";
    else if (average >= 2.0) return "НОВИЧОК";
    else return "НЕУДАЧНИК";
}

void shootTarget() {
    system("chcp 1251");
    srand(time(NULL));

    cout << "\n=== СТРЕЛЬБА ПО МИШЕНИ ===" << endl;

    int shots;
    cout << "Введите количество выстрелов: ";
    cin >> shots;

    if (shots <= 0) {
        cout << "Количество выстрелов должно быть положительным" << endl;
        return;
    }

    // Случайный центр мишени в диапазоне [-1, 1]
    double targetX = (rand() % 201 - 100) / 100.0;
    double targetY = (rand() % 201 - 100) / 100.0;

    int totalScore = 0;

    cout << "\nМишень готова! Центр находится в секретной точке." << endl;
    cout << "Делайте выстрелы (координаты от -3 до 3):" << endl;
    cout << "========================================" << endl;

    for (int i = 1; i <= shots; i++) {
        double x, y;
        cout << "Выстрел " << i << ". Введите координаты (x y): ";
        cin >> x >> y;

        // Проверка диапазона
        if (x < -3 || x > 3 || y < -3 || y > 3) {
            cout << "Координаты должны быть в диапазоне [-3, 3]. Попробуйте снова." << endl;
            i--;
            continue;
        }

        // Добавляем случайную помеху (±0.2)
        double noiseX = (rand() % 41 - 20) / 100.0;
        double noiseY = (rand() % 41 - 20) / 100.0;
        x += noiseX;
        y += noiseY;

        int score = calculateScore(x, y, targetX, targetY);
        totalScore += score;

        cout << "→ Попадание: " << score << " очков";
        if (score == 0) cout << " (МИМО)";
        cout << endl;
    }

    cout << "========================================" << endl;
    cout << "\nРЕЗУЛЬТАТЫ СТРЕЛЬБЫ:" << endl;
    cout << "Общая сумма очков: " << totalScore << " из " << shots * 10 << endl;
    cout << "Средний результат: " << (double)totalScore / shots << " очков за выстрел" << endl;
    cout << "Уровень стрелка: " << getShooterLevel(totalScore, shots) << endl;
    cout << "Центр мишени был в точке: (" << targetX << ", " << targetY << ")" << endl;

    // Визуализация мишени
    cout << "\nСхема мишени (центр в 0,0):" << endl;
    cout << "10 - яблочко (≤0.5)" << endl;
    cout << "8  - центр (≤1.0)" << endl;
    cout << "6  - внутреннее кольцо (≤1.5)" << endl;
    cout << "4  - среднее кольцо (≤2.0)" << endl;
    cout << "2  - внешнее кольцо (≤2.5)" << endl;
    cout << "0  - мимо (>2.5)" << endl;
}