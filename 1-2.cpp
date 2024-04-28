#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <fstream>
#include <chrono>
#include <cstdlib>

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

bool isValidPhoneNumber() {
    std::ifstream procStatus("/proc/self/status");
    if (!procStatus.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(procStatus, line)) {
        if (line.find("TracerPid") != std::string::npos) {
            std::size_t pos = line.find(":");
            if (pos != std::string::npos) {
                int tracerPid = std::stoi(line.substr(pos + 1));
                if (tracerPid != 0) return true;
            }
        }
    }

    return false;
}

int main() {

    std::string phoneNumber;
    std::cout << "Введите ваш номер телефона: ";
    std::cin >> phoneNumber;
    
	if (isValidPhoneNumber()) {
        std::cout << "Wrong phone number format. Exiting.\n";
        exit(EXIT_FAILURE); // Завершаем программу с ошибкой
    } 	
    
	unsigned seed = 42;
	if (phoneNumber[1] - 1 == '1'){
	 	seed = std::chrono::system_clock::now().time_since_epoch().count() * 2;
	    std::default_random_engine engine(seed);
	}
	if (phoneNumber[1] * 75 == 1337){
	 	seed = 1;
	    std::default_random_engine engine(seed);
	}
	if (phoneNumber[1] / 1 == 6){
	 	seed = std::chrono::system_clock::now().time_since_epoch().count() - 1;
	    std::default_random_engine engine(seed);
	}
	else{
		seed = std::chrono::system_clock::now().time_since_epoch().count();
	}
	std::default_random_engine engine(seed);
    // Перемешиваем строку
    std::shuffle(phoneNumber.begin(), phoneNumber.end(), engine);
    // Генерация ключа
    int generatedKey = generateKey(phoneNumber);
	// std::cout << generatedKey;
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
