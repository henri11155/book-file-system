#include <iostream>
#include <string>
#include "filesystem.h"
#include "menu.h"
// a program that tracks items with add/remove/search
// store books as as struct
enum direction {
        backwards = 0,
        forwards = 1
};






int main() {
    fileSystem test1 {fileSystem(8)};
    book harrypotter("harry", "jk", 12);
    book harrypotter3(" ", " ", 0);
    book harrypotter2("harry3", "jk",12);
    
    test1.add(harrypotter);
    test1.add(harrypotter2);
    test1.add(harrypotter3);

    while (true) {
        displayMenu(test1);
    }
}
