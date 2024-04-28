#include <iostream>
#include <string>

// Функция для генерации ключа на основе введенного номера телефона
int generateKey(const std::string &phoneNumber) {
    int sum = 0;
    for (char digit : phoneNumber) {
        if (isdigit(digit)) { // проверка, что символ действительно является цифрой
            sum += digit - '0'; // преобразование символа в число
        }
    }
    return sum * 5; // умножаем общую сумму на 5
}

int main() {
    std::string phoneNumber;
    std::cout << "Введите ваш номер телефона: ";
    std::cin >> phoneNumber;

    // Генерация ключа
    int generatedKey = generateKey(phoneNumber);
 //	std::cout << generatedKey;
    // Запрос ключа у пользователя
    std::cout << "Введите ключ: ";
    int userInputKey;
    std::cin >> userInputKey;

    // Сравнение ключа пользователя с сгенерированным ключом
    if (userInputKey == generatedKey) {
        std::cout << "Доступ разрешен!" << std::endl;
    } else {
        std::cout << "Ошибочный ключ доступа! Попробуйте снова." << std::endl;
    }

    return 0;
}
