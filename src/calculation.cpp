#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

const int ARSize = 10;

int degreeReturn(string polynomial) {
    int degree = stoi(polynomial.substr(polynomial.find_first_of("x") + 2)); //Stores the value which is two characters past the first 'x' into the variable degree. Also converts the string into an int.
    return degree;
}

string SetFunction() { //A simple function asking the user to input a polynomial. Input must be in a strict format for the program to read it correctly.
    string polynomial;
    bool isImputValid = false;
    while (!isImputValid) {
        while (cin.get() != '\n');
        cout << "Enter a polynomial function for example 9x^3+0x^2+7x^1+6\nYou must include a number for all coefficeints even if it is 0, this includes the final constant\n: "; //Must input polynomial in the same style as the example.
        getline(cin, polynomial);
        string temp = polynomial.substr(0, polynomial.size());

        if (temp.size() < 6) {
            isImputValid = false;
            cout << "Invalid Input. Press Enter to retype a polynomial" << endl;
        }
        else if(temp.substr(temp.size()-2, 1) != "+") {
            isImputValid = false;
            cout << "Invalid Input. Press Enter to retype a polynomial" << endl;
        }
        else {
            int degree = degreeReturn(temp);
            if(temp.size() == 6) {
                degree = 1;
            }
            for (int i = degree; i > 0; i--) {
                int degreeCheck = stoi(temp.substr(temp.find_first_of("x") + 2));
                if (i != degreeCheck) {
                    isImputValid = false;
                    cout << "Invalid Input. Press Enter to retype a polynomial" << endl;
                    break;
                }
                else {
                    isImputValid = true;
                    temp = temp.substr(temp.find_first_of("x") + 4, temp.length());
                }
            }
        }
    }

    cout << "Your polynomial: " << polynomial << endl;
    return polynomial;
}

string Deriv_Calculation(string polynomial) {
    string originalPolynomial = polynomial;
    string derivative, derivativeComponents, derivativeDegrees;
    int degree = stoi(polynomial.substr(polynomial.find_first_of("x") + 2)); // In 9x^3+0x^2+7x^1+6, it refers to 3 because polynomial.find_first_of("x") is x and x's index + 2 is 3
    string polynomialValues[ARSize];
    double derivativeValues[ARSize];

    for (int i = degree; i != -1; i--) {                         //Loops until the polynomail values have stored all the coefficients of the polynomial.
        if (polynomial.size() == 1) {                            //once polynomial gets to a point without 'x', we can no longer use 'x as a reference to find the coefficients'
            polynomialValues[i] = polynomial;                    //Takes all the values after the '+' sign, this is the constant value of the polynomial. which is 6 in 9x^3+0x^2+7x^1+6
        }
        else
        {
            polynomialValues[i] = polynomial.substr(0, polynomial.find_first_of("x"));                       //Use 'x' as a reference to find the coefficients of the polynomial.
            polynomial = polynomial.substr(polynomial.find_first_of("x") + 4, polynomial.length());          //turn polynomial into a substring which doesn't include the first 'x' so we can use the first 'x' of the substring as a reference. 
                                                                                                             // For the first iteration on the polynomial = 9x^3+0x^2+7x^1+6, polynomial becomes 0x^2+7x^1+6
        }
    }

    for (int i = degree; i != 0; i--) {
        derivativeValues[i] = stod(polynomialValues[i]) * i;     //convert the string value into a double value and multiply by the degree that that coefficeint belongs to. This is known as the exponent rule
        derivativeDegrees = to_string(i - 1);                    //decrease the degree by one
        derivativeComponents = "x^" + derivativeDegrees + "+";   //the rest of the components to make the derivative into its own string.
        if(i == 1) {                                             //if the degree is one, do not include the '+' because there is no value after it.
            derivative = derivative + to_string(derivativeValues[i]);
        }
        else {                                                   //otherwise include the '+' because there is a value after it.
            derivative = derivative + to_string(derivativeValues[i]) + derivativeComponents;
        }
    }
                                  
    cout << "The derivative of " << originalPolynomial << " is: " << derivative << endl; //Display the original polynomial and the derivative.
    
    return derivative;
}