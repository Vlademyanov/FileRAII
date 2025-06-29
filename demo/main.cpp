#include "File.hpp"
#include <iostream>

int main() {
    try {
        File bad("nonexistent.txt", File::Mode::Read);
    }
    catch (const std::exception& ex) {
        std::cerr << "Expected error: " << ex.what() << std::endl;
    }

    try {
        // Write mode
        {
            File writer("example.txt", File::Mode::Write);
            writer.writeLine("First line");
            writer.writeLine("Second line");
        } 

        // Read mode
        {
            File reader("example.txt", File::Mode::Read);
            std::cout << "--- Read file ---\n";
            while (true) {
                std::string line = reader.readLine();
                if (line.empty() && reader.eof()) break;
                std::cout << "Read: " << line << std::endl;
            }

        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Uncaught error: " << ex.what() << std::endl;
        return 1;
    }

    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 0;
}
