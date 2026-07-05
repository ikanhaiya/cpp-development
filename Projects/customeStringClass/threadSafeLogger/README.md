# Thread Safe Logger (Modern C++)

A high-performance, thread-safe logging library built from scratch in Modern C++ to demonstrate object-oriented design, concurrency, synchronization, and systems programming concepts.

---

## Project Objective

The goal of this project is to design and implement a reusable logging library that allows multiple threads to safely write log messages without data corruption. The project focuses on writing clean, maintainable C++ code while learning concepts commonly used in backend systems and production software.

---

## Features

### Current

* Project structure using CMake
* Modular source and header organization

### Planned

* Console logging
* File logging
* Multiple log levels (INFO, WARNING, ERROR, DEBUG)
* Timestamp support
* Thread-safe logging using `std::mutex`
* RAII-based synchronization with `std::lock_guard`
* Singleton Logger
* Configurable log output
* Multi-threaded testing
* Asynchronous logging (Advanced)

---

## Technologies

* C++17
* CMake
* Standard Template Library (STL)
* Multithreading (`std::thread`)
* Mutexes (`std::mutex`)
* File I/O (`std::ofstream`)
* Chrono Library (`std::chrono`)

---

## Project Structure

```text
ThreadSafeLogger/
├── docs/
├── include/
├── src/
├── tests/
├── examples/
├── logs/
├── build/
├── README.md
├── CMakeLists.txt
└── .gitignore
```

---

## Learning Goals

This project is intended to strengthen understanding of:

* Object-Oriented Programming
* RAII
* File Handling
* Thread Synchronization
* Modern C++ Design
* CMake
* Clean Code Practices
* Concurrent Programming
* Software Architecture

---

## Build

```bash
cmake -S . -B build
cmake --build build
```

---

## Run

```bash
./build/ThreadSafeLogger
```

---

## Documentation

Detailed design notes and implementation documentation are available in the `docs/` directory.

---

## Future Enhancements

* Log rotation
* Daily log files
* Configurable log formatting
* Colored console output
* Multiple output sinks
* Async logger using a worker thread
* Configuration file support
* Unit tests

---

## License

This project is created for learning, experimentation, and portfolio purposes.
