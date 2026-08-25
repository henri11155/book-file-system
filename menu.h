#ifndef MENU_H
#define MENU_H

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


#endif
