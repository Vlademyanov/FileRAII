#include "File.hpp"
#include <iostream>
#include <windows.h>



int main() {
    setlocale(0, "");
    try {
        // Запись
        {
            File writer("example.txt", File::Mode::Write);
            writer.writeLine("Первая строка");
            writer.writeLine("Вторая строка");
        } // writer.~File() автоматически закроет файл

        // Чтение
        File reader("example.txt", File::Mode::Read);
        while (true) {
            std::string line = reader.readLine();
            if (line.empty() && reader.readLine().empty()) {
                // Конец файла (пустая строка дважды подряд)
                break;
            }
            std::cout << "Прочитали: " << line << std::endl;
        }

    } catch (const std::exception& ex) {
        std::cerr << "Ошибка: " << ex.what() << std::endl;
        return 1;
    }
    std::cout << "Нажмите Enter для выхода...";
    std::cin.get();
    return 0;
}
