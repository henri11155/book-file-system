#include <iostream>
#include <string>
#include <random>
#include "filesystem.h"

// a program that tracks items with add/remove/search
// store books as as struct


int main() {
    fileSystem test1 {fileSystem(8)};
    book harrypotter("harry", "jk", 12);
    book harrypotter3(" ", " ", 0);
    book harrypotter2("harry3", "jk",12);
    
    test1.add(harrypotter);
    test1.add(harrypotter2);
    test1.add(harrypotter3);
    test1.printBooks();
    test1.shift(fileSystem::direction::backwards, 1);
    test1.printBooks();
    //test1.resize();
}
