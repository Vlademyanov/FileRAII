#include "File.hpp"

File::File(const std::string& path, Mode mode) {
    std::ios_base::openmode om = std::ios::binary;
    switch (mode) {
        case Mode::Read:      om |= std::ios::in;  break;
        case Mode::Write:     om |= std::ios::out | std::ios::trunc;  break;
        case Mode::ReadWrite: om |= std::ios::in  | std::ios::out;    break;
    }
    stream_.open(path, om);
    if (!stream_.is_open()) {
        throw std::runtime_error("Cannot open file: " + path);
    }
}

File::File(File&& other) noexcept
    : stream_(std::move(other.stream_))
{
    // other.stream_ «пустой»
}

File& File::operator=(File&& other) noexcept {
    if (this != &other) {
        stream_ = std::move(other.stream_);
    }
    return *this;
}

File::~File() {
    if (stream_.is_open()) {
        stream_.close();
    }
}

std::string File::readLine() {
    if (!stream_.is_open()) {
        throw std::runtime_error("File not open for reading");
    }
    std::string line;
    if (!std::getline(stream_, line)) {
        if (stream_.eof()) {
            return "";  // или кинуть, если хотите считать это ошибкой
        }
        throw std::runtime_error("Error reading from file");
    }
    return line;
}

void File::writeLine(const std::string& line) {
    if (!stream_.is_open()) {
        throw std::runtime_error("File not open for writing");
    }
    stream_ << line << '\n';
    if (!stream_) {
        throw std::runtime_error("Error writing to file");
    }
}
