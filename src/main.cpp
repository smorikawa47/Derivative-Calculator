#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
//#include <conio.h>
//#include <windows.h>

//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//handles text color changes
using namespace std;
const int ARSize = 10;
string Deriv_Calculation(string polynomial);
int degreeReturn(string polyonmial);

void Menu() //A simple menu so the user has a choice of what they want to do.
{
    cout << " A) Take derivative of a polynomial\n P) Product Rule\n Q) Quotient Rule\n E) Exponent Rule\n C) Chain Rule\n O) Constant Rule\n S) Sum Rule\n" << endl;
}
void productrule() //For these proofs we highlighted specific areas by changing the color and then changing the color back to default, so it will be more appealing to look at. The code is kind of a mess though.
{
    //SetConsoleTextAttribute(hConsole, 10);
    cout << "Product Rule:\n";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "d/dx [f(x)*g(x)] = f(x) * d/dx [g(x)] + g(x) * d/dx [f(x)]\n" << endl;
    cout << endl;
    cout << "lim  f(x+h)*g(x+h)-f(x+h)*g(x)  +  f(x+h)*g(x)-f(x)*g(x)" << endl;
    cout << "h->0 -------------------------     ---------------------" << endl;
    cout << "                 h                           h" << endl;
    cout << endl;
    cout << "lim";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << " f(x+h)";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "*[g(x+h)-g(x)] + ";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << "g(x)";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "*[f(x+h)-h(x)]" << endl;
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "h->0       -------------        -------------" << endl;
    cout << "                 h                    h\n";
    cout << endl;

    cout << "lim";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << " f(x+h)";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "* ";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << "lim ";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << " [g(x+h)-g(x)] + ";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << "lim   g(x)";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "*[h(x+h)-h(x)]" << endl;
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "h->0";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << "        h->0";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << " ------------- ";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << "  h->0";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "       -------------\n";
    cout << "                       h                          h\n";
    cout << "f(x)*g'(x) + g(x)*f'(x)" << endl;
    //SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
}

void quotientrule()
{
    //SetConsoleTextAttribute(hConsole, 10);
    cout << "Quotient Rule:\n";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "d/dx [f(x)/g(x)] = (f(x) d/dx[g(x)] - g(x) d/dx [f(x)]) / (g(x))^2\n" << " = (f(x)*g'(x)] - g(x)*f'(x)) / (g(x))^2 " << endl;
    cout << "lim     f(x+h)*g(x)   f(x)*g(x+h)\n";
    cout << "h->0    ---------- - ------------\n";
    cout << "        g(x+h)*g(x)   g(x)*g(x+h)\n";
    cout << "        -------------------------\n";
    cout << "                   h\n";
    cout << endl;
    cout << "lim ";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << " 1";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "  f(x+h)*g(x)";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << "-f(x+h)*g(x)-f(x)*(x+h)";
   // SetConsoleTextAttribute(hConsole, 15);
    cout << "+f(x)*g(x)\n";
    cout << "h->0";
   // SetConsoleTextAttribute(hConsole, 13);
    cout << " -";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "  --------------------------------------------\n";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << "     h";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "                   g(x+h)*g(x)" << endl; // secondn line
    cout << endl;
    cout << "lim ";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << " g(x)*";
   // SetConsoleTextAttribute(hConsole, 15);
    cout << "[f(x+h)-f(x)] - ";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << "f(x)*";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "[g(x+h)-g(x)]\n";
    cout << "h->0";
    cout << " ---------------------------------------\n";
    cout << "                h*g(x+h)*g(x)" << endl;
    cout << endl;
    cout << "lim ";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << "     1";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "       *  g(x)*";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << "f(x+h)-f(x)";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << " - f(x)*";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << "g(x+h)-g(x)\n";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "h->0 ";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << "-----------         -----------        -----------\n";
    cout << "     g(x+h)*g(x)              h                  h\n";
    cout << endl;
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "   1      [g(x)*";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << "f'(x)";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << " - f(x)*";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << "g'(x)]\n";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "--------\n";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << "(g(x))^2\n";
    cout << endl;
    //SetConsoleTextAttribute(hConsole, 15);
}
void exponentrule()
{
    //SetConsoleTextAttribute(hConsole, 10);
    cout << "Exponent Rule:\n";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "d/dx e^x = e^x        d/dx [e^u] = e^u du/dx\n";
    cout << "d/dx a^x = a^x ln(a)    d/dx a^u = a^u ln(a) du/dx " << endl;
    cout << endl;
    cout << "lim  (x+h)^n-x^n\n";
    cout << "h->0 -----------\n";
    cout << "          h\n";
    cout << endl;
    cout << "lim   1                    n*(n-1)*x^(n-2)*h^2\n";
    cout << "h->0  -  * x^n+n*x^(n-1)*h + --------------------  ... + h^n - x^n\n";
    cout << "      h                             2\n";
    cout << endl;
    cout << "lim ";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << " h";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "                      n*(n - 1)*x ^ (n - 2)*h\n";
    cout << "h->0";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << " -  ";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "*";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << " x^n";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "+n*x^(n - 1) + -----------------------  ... + h ^ (n - 1)";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << " - x^n\n";
    cout << "     h";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "                                2\n";
    cout << endl;
    cout << "lim               n*(n-1)*x^(n-2)*h\n";
    cout << "h->0  n*x^(n-1) + --------------------  ... + h^(n-1) \n";
    cout << "                          2\n";
    cout << endl;
    cout << "n*x^(n-1)\n";
    cout << endl;
}

void chainrule()
{
    //SetConsoleTextAttribute(hConsole, 10);
    cout << "Chain Rule:\n";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "d/dx f(g(x)) = f'(g(x))g'(x)" << endl;
    cout << endl;
}
void sumrule()
{
    //SetConsoleTextAttribute(hConsole, 10);
    cout << "Sum Rule:\n";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "d\n";
    cout << "--  [f(x)+g(x)] = f'(x)+g'(x)\n";
    cout << "dx\n";
    cout << endl;
    cout << "lim   f(x+h)-f(x)   g(x+h)-g(x)\n";
    cout << "h->0  ----------- + -----------\n";
    cout << "           h             h\n";
    cout << endl;
    cout << "f'(x) + g'(x)\n";
    cout << endl;
}

void constantrule()
{
    //SetConsoleTextAttribute(hConsole, 10);
    cout << "Constant Rule:\n";
    //SetConsoleTextAttribute(hConsole, 15);
    cout << "f(x)=C, f'(x)=0\n";
    cout << "lim  C-C\n";
    cout << "h->0 ---\n";
    cout << "      h\n";
    cout << endl;
    cout << "lim  0\n";
    cout << "h->0 -\n";
    cout << "     h\n";
    cout << endl;
    cout << "0\n";
    cout << endl;
}

string SetFunction() //A simple function asking the user to input a polynomial. Input must be in a strict format for the program to read it correctly.
{

    string polynomial;
    while (cin.get() != '\n');
    cout << "Enter a polynomial function for example (9x^3+0x^2+7x^1+6)\nYou must include a number for all coefficeints even if it is 0, this includes the final constant\n: "; //Must input polynomial in the same style as the example.
    getline(cin, polynomial);
    cout << "Your polynomial: " << polynomial << endl;
    return polynomial;
}
int degreeReturn(string polynomial)
{
    int degree = stoi(polynomial.substr(polynomial.find_first_of("x") + 2)); //Stores the value which is two characters past the first 'x' into the variable degree. Also converts the string into an int.
    return degree;
}
string Deriv_Calculation(string polynomial)
{
    string originalPolynomial = polynomial;
    string derivative, derivativeComponents, derivativeDegrees;
    int degree = stoi(polynomial.substr(polynomial.find_first_of("x") + 2));
    string polynomialValues[ARSize];
    double derivativeValues[ARSize];
    for (int i = degree; i != -1; i--) //Loops until the polynomail values have stored all the coefficients of the polynomial.
    {
        if (polynomial.size() < 3) //once polynomial gets to a point without 'x', we can no longer use 'x as a reference to find the coefficients'
        {
            polynomialValues[i] = polynomial.substr(polynomial.find_first_of("+") + 1, polynomial.length()); //Takes all the values after the '+' sign, this is the constant value of the polynomial.
        }
        else
        {
            polynomialValues[i] = polynomial.substr(0, polynomial.find_first_of("x"));                //Use 'x' as a reference to find the coefficients of the polynomial.
            polynomial = polynomial.substr(polynomial.find_first_of("x") + 4, polynomial.length());    //turn polynomial into a substring which doesn't include the first 'x' so we can use the first 'x' of the substring as a reference.
        }
    }
    for (int i = degree; i != 0; i--)
    {
        derivativeValues[i] = stod(polynomialValues[i]) * i;     //convert the string value into a double value and multiply by the degree that that coefficeint belongs to. This is known as the exponent rule
        derivativeDegrees = to_string(i - 1);                    //decrease the degree by one
        derivativeComponents = "x^" + derivativeDegrees + "+";    //the rest of the components to make the derivative into its own string.
        if(i == 1)                                                //if the degree is one, do not include the '+' because there is no value after it.
            derivative = derivative + to_string(derivativeValues[i]);
        else                                                    //otherwise include the '+' because there is a value after it.
        {
            derivative = derivative + to_string(derivativeValues[i]) + derivativeComponents;
        }
    }
    cout << "The derivative of ";
    //SetConsoleTextAttribute(hConsole, 10);
    cout << originalPolynomial;
    //SetConsoleTextAttribute(hConsole, 15);
    cout << " is: ";
    //SetConsoleTextAttribute(hConsole, 13);
    cout << derivative << endl; //Display the original polynomial and the derivative.
    //SetConsoleTextAttribute(hConsole, 15);
    
    return derivative;
}
int main()
{
    string derivatives[ARSize];
    string derivative;
    //SetConsoleTextAttribute(hConsole, 15); //set default text color to white
     char choice;
     while (true)                //run until the user closes the application
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
         }
     }
    return 0;
}


