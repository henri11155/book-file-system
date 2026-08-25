#include <iostream>
#include <string>
#include <random>
#include <random>
// a program that tracks items with add/remove/search
// store books as as struct

struct book {
    std::string name {};
    std::string author {};
    uint16_t id {};
    book() = default;
    book(std::string name, std::string author, uint16_t id) : name{name}, author{author}, id{id} {}
};

class fileSystem {
    private:
    book* books { nullptr };
    uint32_t capacity{};
    uint32_t count{};
    public:
    fileSystem(size_t count=8) : books{new book[capacity]}, capacity{static_cast<uint32_t>(count)}, count{0} {}

    //fileSystem(fileSystem&& fileSystem) noexcept : books{fileSystem.books}, capacity{fileSystem.capacity}, count{fileSystem.count}
    //{
    //    fileSystem.books = nullptr;
    //    fileSystem.count = 0;
    //}
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
    
    void remove(uint16_t id) {}
    
    //book search(uint16_t id) {}
    
    void save() {}

    void printBooks() {
        std::cout << books[0].name;
        std::cout << books[1].name;
        std::cout << books[2].name;
        }
    };

//fileSystem importFromFile(std::string_view fileName) {}


int main() {
    fileSystem test1 {fileSystem(0)};
    book harrypotter("harry", "jk", 12);
    book harrypotter2("harry2", "jk", 12);
    book harrypotter3("harry3", "jk", 12);
    test1.add(harrypotter);
    test1.add(harrypotter2);
    test1.add(harrypotter3);
    test1.printBooks();
    //test1.resize();
}
