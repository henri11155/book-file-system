#include <iostream>
#include <string>
#include "filesystem.h"
#include "menu.h"
// a program that tracks items with add/remove/search
// store books as as struct







int main() {
    fileSystem test1 {fileSystem(8)};
    book harrypotter = book("harry", "jk", 1);
    book harrypotter2 = book("harry3", "jk",3);
    book harrypotter4 = book("harry4", "jk",2);
    test1.add(harrypotter);
    test1.add(harrypotter2);
    test1.add(harrypotter4);
    //while (true) {
    //    displayMenu(test1);
    //}
}
