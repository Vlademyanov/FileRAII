#pragma once
#include <fstream>
#include <string>
#include <stdexcept>

class File {
public:
    enum class Mode { Read, Write };

    // Конструктор
    File(const std::string& path, Mode mode);

    // Конструктор копирования
    File(const File&) = delete;

    // Оператор копирования присваниванием 
    File& operator=(const File&) = delete;

    // Конструктор перемещения
    File(File&& other) noexcept;

    // Оператор перемещения присваиванием
    File& operator=(File&& other) noexcept;

    // Деструктор
    ~File();

    // Чтение строки
    std::string readLine();

    // Запись строки
    void writeLine(const std::string& line);

    bool eof() const;

private:
    std::fstream stream_;
};
