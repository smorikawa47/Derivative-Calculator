#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include "rules.cpp"
#include "calculation.cpp"
using namespace std;

void Menu() { //A simple menu so the user has a choice of what they want to do.
    cout << "A) Take derivative of a polynomial\t P) Product Rule\nQ) Quotient Rule\t \t \t E) Exponent Rule\nC) Chain Rule\t \t \t \t O) Constant Rule\nS) Sum Rule\t \t \t \t T) Exit\n" << endl;
}

int main() {
    string derivatives;
    string derivative;
    char choice;
    bool quit = false;
    while (!quit) { //run until the user closes the application
        Menu();
        cout << "Your choice: ";
        cin >> choice;
        choice = toupper(choice);                  //converts choice character into an uppercase letter.
        cout << endl;
        switch (choice) { //corresponds to the menu
        case 'A': {
            string polynomial = SetFunction();
            derivatives = polynomial;
            int degree = degreeReturn(polynomial);

            for (int i = 0; i < degree; i++) { //this takes all the derivatives of the set polynomial, so it takes the first, second, ect..
                derivatives = Deriv_Calculation(derivatives);
            }
            
            cout << endl;
            break;
        }
        case 'P':
            productrule();
            break;
        case 'Q':
            quotientrule();
            break;
        case 'E':
            exponentrule();
            break;
        case 'C':
            chainrule();
            break;
        case 'S':
            sumrule();
            break;
        case 'O':
            constantrule();
            break;
        case 'T':
            quit = true;
            break;
        }
    }
    return 0;
}


