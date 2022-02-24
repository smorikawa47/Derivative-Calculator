#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include "rules.cpp"
#include "calculation.cpp"

//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//handles text color changes
using namespace std;

void Menu() //A simple menu so the user has a choice of what they want to do.
{
    cout << " A) Take derivative of a polynomial\n P) Product Rule\n Q) Quotient Rule\n E) Exponent Rule\n C) Chain Rule\n O) Constant Rule\n S) Sum Rule\n T) Exit\n" << endl;
}

int main()
{
    string derivatives[ARSize];
    string derivative;
     char choice;
     bool quit = false;
     while (!quit)                //run until the user closes the application
     {
         Menu();
         cout << "Your choice: ";
         cin >> choice;
         choice = toupper(choice);        //converts choice character into an uppercase letter.
         cout << endl;
         switch (choice)        //corresponds to the menu
         {
         case 'A':
         {
             string polynomial = SetFunction();
             derivatives[0] = polynomial;
             int degree = degreeReturn(polynomial);
             for (int i = 0; i < degree; i++)//this takes all the derivatives of the set polynomial, so it takes the first, second, ect..
             {
                 derivatives[0] = Deriv_Calculation(derivatives[0]);
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


