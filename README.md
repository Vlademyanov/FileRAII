# FileRAII Library

This project is a C++ library for file handling following the RAII (Resource Acquisition Is Initialization) paradigm.  
It was developed as a homework assignment for the IT School PROTEY NTC.

---

## Features

- RAII-based file management: files are opened upon object creation and automatically closed when the object is destroyed.
- Support for two file modes: **Read** and **Write**.
- Methods to read and write lines from/to files (`readLine()` and `writeLine()`).
- Error handling through exceptions (`std::runtime_error`) when file operations fail.
- Demonstration program showing library usage and error handling.

---

## Project Structure
```
FileRAII/
│
├── include/
│ └── File.hpp # Library interface
├── src/
│ └── File.cpp # Implementation
├── demo/
│ └── main.cpp # Demo program
├── CMakeLists.txt # Build configuration
```
---

## Requirements

- C++17 compatible compiler
- CMake 3.10 or higher

---

## Building the Project

```bash
mkdir build
cd build
cmake ..
cmake --build .
```
