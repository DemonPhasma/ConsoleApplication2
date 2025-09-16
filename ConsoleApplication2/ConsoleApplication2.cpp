#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

bool isPalindrome(const std::string& s) {
    std::string cleaned;
    for (char c : s) {
        if (!std::isspace(c)) {
            cleaned += std::tolower(c);
        }
    }
    std::string reversed = cleaned;
    std::reverse(reversed.begin(), reversed.end());
    return cleaned == reversed;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    setlocale(LC_ALL, "RU");
    std::string name;
    std::cout << "Введите ваше имя: ";
    std::getline(std::cin, name);
    std::cout << "Привет, " << name << "!" << std::endl;

    int n;
    std::cout << "\nВведите количество чисел для сортировки: ";
    std::cin >> n;

    std::vector<int> numbers(n);
    std::cout << "Введите числа через пробел: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    std::sort(numbers.begin(), numbers.end());
    std::cout << "Отсортированный массив: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string text;
    std::cout << "\nВведите строку для проверки на палиндром: ";
    std::getline(std::cin, text);
    if (isPalindrome(text)) {
        std::cout << "Это палиндром!" << std::endl;
    }
    else {
        std::cout << "Это не палиндром." << std::endl;
    }

    int a, b;
    std::cout << "\nВведите первое число для вычисления НОД: ";
    std::cin >> a;
    std::cout << "Введите второе число для вычисления НОД: ";
    std::cin >> b;
    std::cout << "НОД чисел " << a << " и " << b << " равен " << gcd(a, b) << std::endl;

    return 0;
}
