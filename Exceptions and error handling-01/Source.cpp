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

    std::cout << "������� ��������� �����: ";
    std::cin >> forbidden_length;

    std::string str;

    try {
        while (true) {
            std::cout << "������� �����: ";
            std::cin >> str;

            int length = function(str, forbidden_length);

            std::cout << "����� ����� \"" << str << "\" ����� " << length << std::endl;
        }
    }
    catch (bad_length) {
        std::cout << "�� ����� ����� ��������� �����! �� ��������" << std::endl;
    }

    return 0 ;
}
