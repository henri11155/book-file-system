#include <iostream>
#include <string>
#include "filesystem.h"
#include "menu.h"
// a program that tracks items with add/remove/search
// store books as as struct







int main() {
    fileSystem test1 {fileSystem(8)};
    book harrypotter1 = book("harry", "jk", 1);
    book harrypotter8 = book("harry3", "jk",8);
    book harrypotter2 = book("harry4", "jk",2);
    book harrypotter5 = book("harry3", "jk",5);
    book harrypotter4 = book("harry3", "jk",4);
    book harrypotter3 = book("harry3", "jk",3);
    test1.add(harrypotter8);
    test1.add(harrypotter2);
    test1.add(harrypotter5);
    test1.add(harrypotter1);
    test1.add(harrypotter4);
    test1.add(harrypotter3);
    test1.printBooks();
    //while (true) {
    //    displayMenu(test1);
    //}
}
