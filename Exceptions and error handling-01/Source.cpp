#include <iostream>
#include<Windows.h>
#include <string>

class bad_length {};

int function(std::string str, int forbidden_length) {
    int length = str.length();

    if (length == forbidden_length) {
        throw bad_length();
    }

    return length;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int forbidden_length;

    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;

    std::string str;

    try {
        while (true) {
            std::cout << "Введите слово: ";
            std::cin >> str;

            int length = function(str, forbidden_length);

            std::cout << "Длина слова \"" << str << "\" равна " << length << std::endl;
        }
    }
    catch (bad_length) {
        std::cout << "Вы ввели слово запретной длины! До свидания" << std::endl;
    }

    return 0 ;
}
