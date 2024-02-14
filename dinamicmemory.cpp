#include <iostream>
#include <iostream>
#include <cstdlib>
#include <ctime>

int solve(int a, int b) {

    int count = 0;

    int** num = new int* [a];
    for (int i = 0; i < a; ++i) {
        num[i] = new int[b]; // каждый указатель указывает на массив из cols элементов
    }
    ;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            num[i][j] = std::rand() % 5 + 1;
            std::cout << num[i][j] << " ";
        }
        std::cout << std::endl;
    }
    //ограничение i<4;4это количество строк в массиве;чтобы Проверить все
    // а j <2; 2 это количество строк -2;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b - 2; j++) {
            if (num[i][j] == num[i][j + 1] && num[i][j] == num[i][j + 2]) {
                count += 1;
            }
        }
    }
    // i < 4; Чтобы проверить все столбцы 
    // j < 2; количетсво столбцов -2
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a - 2; j++) {
            if (num[j][i] == num[j + 1][i] && num[j][i] == num[j + 2][i]) {
                count += 1;
            }
        }
    }
    std::cout << "\n" << count;

    for (int i = 0; i < a; ++i) {
        delete[] num[i];

    }
    delete[] num;
    return count;
}
int main()
{
    std::srand(std::time(nullptr));
    setlocale(LC_ALL, "RUSSIAN");
    int rows, cols;

    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;
    solve(rows, cols);
    std::cout << "\n";
    return 0;
}