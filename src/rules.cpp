#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
using namespace std;

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
    cout << " f(x+h)";
    cout << "*[g(x+h)-g(x)] + ";
    cout << "g(x)";
    cout << "*[f(x+h)-h(x)]" << endl;
    cout << "h->0       -------------        -------------" << endl;
    cout << "                 h                    h\n";
    cout << endl;

    cout << "lim";
    cout << " f(x+h)";
    cout << "* ";
    cout << "lim ";
    cout << " [g(x+h)-g(x)] + ";
    cout << "lim   g(x)";
    cout << "*[h(x+h)-h(x)]" << endl;
    cout << "h->0";
    cout << "        h->0";
    cout << " ------------- ";
    cout << "  h->0";
    cout << "       -------------\n";
    cout << "                       h                          h\n";
    cout << "f(x)*g'(x) + g(x)*f'(x)" << endl;
    cout << endl;
}

void quotientrule()
{
    cout << "Quotient Rule:\n";
    cout << "d/dx [f(x)/g(x)] = (f(x) d/dx[g(x)] - g(x) d/dx [f(x)]) / (g(x))^2\n" << " = (f(x)*g'(x)] - g(x)*f'(x)) / (g(x))^2 " << endl;
    cout << "lim     f(x+h)*g(x)   f(x)*g(x+h)\n";
    cout << "h->0    ---------- - ------------\n";
    cout << "        g(x+h)*g(x)   g(x)*g(x+h)\n";
    cout << "        -------------------------\n";
    cout << "                   h\n";
    cout << endl;
    cout << "lim ";
    cout << " 1";
    cout << "  f(x+h)*g(x)";
    cout << "-f(x+h)*g(x)-f(x)*(x+h)";
    cout << "+f(x)*g(x)\n";
    cout << "h->0";
    cout << " -";
    cout << "  --------------------------------------------\n";
    cout << "     h";
    cout << "                   g(x+h)*g(x)" << endl; // secondn line
    cout << endl;
    cout << "lim ";
    cout << " g(x)*";
    cout << "[f(x+h)-f(x)] - ";
    cout << "f(x)*";
    cout << "[g(x+h)-g(x)]\n";
    cout << "h->0";
    cout << " ---------------------------------------\n";
    cout << "                h*g(x+h)*g(x)" << endl;
    cout << endl;
    cout << "lim ";
    cout << "     1";
    cout << "       *  g(x)*";
    cout << "f(x+h)-f(x)";
    cout << " - f(x)*";
    cout << "g(x+h)-g(x)\n";
    cout << "h->0 ";
    cout << "-----------         -----------        -----------\n";
    cout << "     g(x+h)*g(x)              h                  h\n";
    cout << endl;
    cout << "   1      [g(x)*";
    cout << "f'(x)";
    cout << " - f(x)*";
    cout << "g'(x)]\n";
    cout << "--------\n";
    cout << "(g(x))^2\n";
    cout << endl;
}
void exponentrule()
{
    cout << "Exponent Rule:\n";
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
    cout << " h";
    cout << "                      n*(n - 1)*x ^ (n - 2)*h\n";
    cout << "h->0";
    cout << " -  ";
    cout << "*";
    cout << " x^n";
    cout << "+n*x^(n - 1) + -----------------------  ... + h ^ (n - 1)";
    cout << " - x^n\n";
    cout << "     h";
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
    cout << "Chain Rule:\n";
    cout << "d/dx f(g(x)) = f'(g(x))g'(x)" << endl;
    cout << endl;
}
void sumrule()
{
    cout << "Sum Rule:\n";
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
    cout << "Constant Rule:\n";
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