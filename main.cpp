#include <iostream>
#include <string>
#include <random>
#include <random>
// a program that tracks items with add/remove/search
// store books as as struct

using maxSize = uint16_t;

struct book {
    std::string name {};
    std::string author {};
    maxSize id {};
    book() = default;
    book(std::string name, std::string author, maxSize id) : name{name}, author{author}, id{id} {}
};

class fileSystem {

    private:
    book* books { nullptr };
    maxSize capacity{};
    maxSize count{};
    public:
    enum direction {
        forwards = 1,
        backwards = 0
    };
    fileSystem(size_t count=8) : books{new book[capacity]}, capacity{static_cast<maxSize>(count)}, count{0} {}

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
    
    void remove(maxSize id) {}
    
    void shift (direction dir, size_t start) noexcept {
        size_t fast {start+1};
        size_t slow {start};
        if (dir == forwards) {
            while (fast < capacity) {
                if (!books[fast].id) {
                    continue;
                } else if (!books[slow].id) {
                    std::cout << " moving " << books[fast].id << " to " << books[slow].id;
                    books[slow] = std::move(books[fast]);
                    slow++;
                    break;
                }
                fast++;
            }
        }
        else {

            
        }
    }
    //book search(uint16_t id) {}
    
    void save() {}

    void printBooks() {
        std::cout << "pritning";
        for (size_t i {0}; i < capacity; i++) {
            if (books[i].id){
            std::cout << books[i].id << books[i].name;
        }}
        }
    };

//fileSystem importFromFile(std::string_view fileName) {}


int main() {
    fileSystem test1 {fileSystem(8)};
    book harrypotter("harry", "jk", 12);
    book harrypotter2("harry2", "jk", 0);
    book harrypotter3("harry3", "jk", 12);
    
    test1.add(harrypotter);
    test1.add(harrypotter2);
    test1.add(harrypotter3);
    test1.printBooks();
    test1.shift(fileSystem::direction::forwards, 1);
    test1.printBooks();
    //test1.resize();
}
