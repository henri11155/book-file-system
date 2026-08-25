#include <iostream>
#include <string>
#include "filesystem.h"

// a program that tracks items with add/remove/search
// store books as as struct
enum direction {
        backwards = 0,
        forwards = 1
};


void displayMenu(fileSystem& system) {
    std::cout << "Welcome to filesystem\n";
    std::cout << "  1. display all books\n";
    std::cout << "  2. add book\n";
    std::cout << "  3. remove book\n";
    std::cout << "  4. exit\n";
    std::cout << ">> ";
    int answer; 
    std::cin >> answer;
    switch (answer) {
        case 1: 
            system.printBooks();
            break;
        
        case 2: 

            break;
        
        case 3: 

            break;
        
        case 4: 

            break;
        
        case 5: 

            break;
        
    }
}



int main() {
    fileSystem test1 {fileSystem(8)};
    book harrypotter("harry", "jk", 12);
    book harrypotter3(" ", " ", 0);
    book harrypotter2("harry3", "jk",12);
    
    test1.add(harrypotter);
    test1.add(harrypotter2);
    test1.add(harrypotter3);
    //test1.printBooks();
    //test1.shift(direction::backwards, 1);
    //test1.printBooks();
    test1.save();
    //test1.resize();

    //main loop
    while (true) {
        displayMenu(test1);
    }
}
