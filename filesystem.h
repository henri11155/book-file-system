#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
#include "filesystem.h"
using maxSize = uint16_t;

struct book {
    std::string name {};
    std::string author {};
    maxSize id {};
    book() = default;
    book(std::string name, std::string author, maxSize id) : name{name}, author{author}, id{id} {}
    book& operator=(book& book) noexcept {
        name = book.name;
        author = book.author;
        id = book.id;
        return *this;
};
    book& operator=(book&& book) noexcept {
        name = book.name;
        author = book.author;
        id = book.id;
        book.name = "";
        book.author = "";
        book.id = 0;
        return *this;
    }
};

class fileSystem {

    private:
    book* books { nullptr };
    maxSize capacity{};
    maxSize count{};
    public:
    fileSystem(size_t count=8) : books{new book[capacity]}, capacity{static_cast<maxSize>(count)}, count{0} {}

    void resize() {
        std::cout << "resizing ";
        capacity = (capacity == 0 ? 1 : capacity * 2);
        book* newBooks {new book[capacity]};
        for (size_t i {0}; i < count; i++) {
            newBooks[i] = std::move(books[i]);
        }
        delete[] books;
        books = newBooks;
    }

    void add(book& book) {
        if (count >= capacity || capacity == 0) {
            resize();
        }
        books[count] = book;
        count++;
    }
    
    void remove(maxSize id) {} // shift after removal
    
    void shift (bool forwards, size_t start) noexcept {
        size_t fast {};
        size_t slow {};
        if (forwards) {
            fast = start;
            slow = start;
            fast++;
            while (fast < capacity) {
                if (!books[fast].id) {
                    fast++;
                    continue;
                } else if (!books[slow].id) {
                    books[slow] = std::move(books[fast]);
                    slow++;
                    break;
                }
                fast++;
            }
        }
        else {
            fast = count-2; //start from first and second last elements
            slow = count-1;
            while (fast >= start) {
                if (!books[fast].id) {
                    continue;
                } else if (!books[slow].id) {
                    books[slow] = std::move(books[fast]);
                    slow--;
                    break;
                }
                fast--;
            }
            
        }
    }
    //book search(uint16_t id) {}
    
    void importFromFile() {
        std::ifstream iFile{"books.txt"};
        if (!iFile) {
            std::cout << "unable to open file";
            return;
        }

    }
    void save() {

        std::ofstream oFile{"books.txt"};
        if (!oFile) {
            std::cout << "unable to open file";
            return;
        }
        for (maxSize i {0}; i<count; i++) {
            book* current {&books[i]};
            if (current->id != 0) {
            oFile << current->id << " " << current->name << " " << current->author << "\n";
            }
        }
    }

    void printBooks() {
        for (size_t i {0}; i < capacity; i++) {
            book* current {&books[i]};
            if (current->id == 0) continue;
            std::cout << "\n ID: " << current->id << "\nTitle: " << current->name << "\nAuthor: " << current->author << "\n";
        }
    }
    };

#endif
