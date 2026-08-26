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
    book() : name{" "}, author{" "}, id{0} {}
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
    enum direction {
        backwards = 0,
        forwards = 1
    };
    fileSystem(maxSize size=8) : books{new book[capacity]}, capacity{static_cast<maxSize>(size)}, count{0} {}
    ~fileSystem() {
        delete[] books;
    }
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

    bool add(book& book) {
        if (count >= capacity || capacity == 0) {
            resize();
        }
        //find spot to insert by comparing, this is so list can be ordered
        if (capacity == 1 || count == 0) {
            books[0] = book;
            std::cout << "\nAdded " << book.name << " ID: " << book.id;
            count++;
            return true;
        }
        if (books[count-1].id < book.id) {
            books[count] = book;
            count++;
            std::cout << "\nAdded " << book.name << " ID: " << book.id;
            return true;
        }
        //binary search for book
        {
            maxSize high = count-1;
            maxSize low {0};
            maxSize mid = count / 2;
            int target {book.id};

            while (true) {
                if (low == mid || high == mid) { //if id not already in list
                    shift(direction::backwards, mid+1);
                    books[mid+1] = book;
                    std::cout << "\nAdded " << book.name << " ID: " << book.id;
                    count++;
                    return true;
                }
                if (books[mid].id == target) {
                    std::cout << "duplicate";
                    return false;
                }
                else if (books[mid].id > target) {
                    high = mid;
                    mid -= (low-mid)/2;
                }
                else if (books[mid].id < target) {
                    low = mid;
                    mid += (high-mid)/2; 
                }
                    
            }       
        }



    }
    
    void remove(maxSize id) {

    } // shift after removal
    

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
    maxSize search(maxSize id) {
        maxSize high = count-1;
        maxSize low {0};
        maxSize mid = count / 2;
        int target {id};
        while (true) {
            if (books[mid].id == target) {
                return mid;
                break;
            }
            else if (books[mid].id > target) {
                high = mid;
                mid -= (low-mid)/2;
            }
            else if (books[mid].id < target) {
                low = mid;
                mid += (high-mid)/2; 
            } 
                    
        }       
    }
    
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
