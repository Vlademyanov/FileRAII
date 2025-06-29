#pragma once
#include <fstream>
#include <string>
#include <stdexcept>

class File {
public:
    enum class Mode { Read, Write, ReadWrite };

    // Конструктор: открывает файл
    File(const std::string& path, Mode mode);

    // Запрещаем копирование (двух объектов — одного ресурса)
    File(const File&) = delete;
    File& operator=(const File&) = delete;

    // Разрешаем перемещение
    File(File&& other) noexcept;
    File& operator=(File&& other) noexcept;

    // Деструктор: закрывает файл
    ~File();

    // Читает одну строку (до '\n'), без символа окончания
    std::string readLine();

    // Записывает строку с добавлением '\n'
    void writeLine(const std::string& line);

private:
    std::fstream stream_;
};
