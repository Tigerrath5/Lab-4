/*
 * TND012, Lab4: program to find prime numbers
 * Author:
 *
 */
#include <iostream>
#include <iomanip>
#include <vector>

void display_menu();

bool test_prime(int a); 
int next_prime(int a); 
int prev_prime(int a); 
void display_primes(int a, int b); 

int main() {
    constexpr int exit = 5;
    int option = exit;
    int N = 0; 
    int M = 0; 
    
    do {
        // Display the menu
        display_menu();
        
        // Read user option
        do{
            std::cout << "Your choice: ";
            std::cin >> option;
            
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
                std::cout << "Test prime? ";
                std::cin >> N; 
                std::cout << "\n";
                if (test_prime(N)) {
                    std::cout << N << " is a prime.\n\n";
                }
                else {
                    std::cout << N << " is not a prime.\n\n";
                }
                break;
            case 2:
                std::cout << "Next prime? ";
                std::cin >> N; 
                std::cout << "\n" << "Next prime of " << N << " is " << next_prime(N) << ".\n\n";
                break;
            case 3:
                std::cout << "Previous prime? ";
                std::cin >> N;
                if (N < 2) {
                    std::cout << "\nThere is no previous prime number.\n\n";
                }
                else {
                    std::cout << "\n" << "Previous prime of " << N << " is " << prev_prime(N) << ".\n\n";
                }
                break;
            case 4:
                std::cout << "Enter interval [a, b]? ";
                std::cin >> N >> M; 
                std::cout << "\n";
                display_primes(N, M); 
                break;
            case 5:
                std::cout << "Exiting...\n\n";
                break;
        }
    } while (option != exit);
}

void display_menu() {
    std::cout << std::setfill('=') << std::setw(20) << "\n"
        << "1. Test Prime\n"
        << "2. Next Prime\n"
        << "3. Previous Prime\n"
        << "4. Display Prime\n"
        << "5. Exit\n"
        << std::setfill('=') << std::setw(20) << "=\n\n";
}

bool test_prime(int a) {
    
    bool isPrime = true; 

    if (a < 2){
       isPrime = false; 
    }
    
    for (int i = 2; i <= a / 2; i++) {
        if (a % i == 0) {
            isPrime = false; 
            break; 
        }
    }

    return isPrime; 
}

int next_prime(int a) {
    int P = a; 
    if (test_prime(P))
    {
        ; 
    }
    else 
    {
        while (!test_prime(P)) {
            P += 1; 
            test_prime(P); 
        }
    }
    return P; 
}

int prev_prime(int a) {
    int P = a;
    if (test_prime(P))
    {
        ;
    }
    else
    {
        while (!test_prime(P)) {
            P -= 1;
            test_prime(P);
        }
    }
    return P;
}

void display_primes(int a, int b) {
    std::vector<int> prime_list; 

    for (int i = a; i < b; i++) {
        if (test_prime(i)) {
            prime_list.push_back(i);
        }
    }

    if (prime_list.size() == 0) {
        std::cout << "There are no prime numbers!!";
    }
    else {
        for (int e : prime_list) {
            std::cout << e << " ";
        }
    }
    std::cout << "\n\n";
}
