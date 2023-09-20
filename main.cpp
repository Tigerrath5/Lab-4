/*
 * TND012, Lab4: program to find prime numbers
 * Author:
 *
 */
#include <iostream>
#include <iomanip>
#include <vector>

void display_menu (){
    std::cout << std::setfill('=') << std::setw(20) << "\n"
        << "1. Test Prime\n"
        << "2. Next Prime\n"
        << "3. Previous Prime\n"
        << "4. Display Prime\n"
        << "5. Exit\n"
    << std::setfill('=') << std::setw(20) << "=\n\n";
}

int testPrimes (){
    return 0;
}

// ADD any needed functions here

int main() {
    constexpr int exit = 5;
    int option = exit;
    std::vector<int> primeNumb = {2, 3, 5, 7, 11, 13};
    
    do {
        // Display the menu
        display_menu();
        
        // Read user option
        do{
            std::cout << "Your choice: ";
            std::cin >> option;
            std::cout << "\n";
           
            
            bool invalidOption = (option < 1 || option > 5);
            if (invalidOption){
                std::cout << "Wrong choice!!!\n\n";
                display_menu();
            }
        }while (option < 1 || option > 5);
        
        //Handle user option -- switch-statement can be useful here
        //enum options {testPrime = 1, nextPrime = 2, previousPrime = 3, displayPrimes = 4};
        switch (option){
            case 1:
                
                std::cout << "testPrime\n\n";
                break;
            case 2:
                std::cout << "nextPrime\n\n";
                break;
            case 3:
                std::cout << "previousPrime\n\n";
                break;
            case 4:
                std::cout << "displayPrimes\n\n";
                break;
            case 5:
                std::cout << "Exiting...\n\n";
                break;
        }
    } while (option != exit);
}
