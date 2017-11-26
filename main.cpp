#include <iostream>
#include "Converter.h"

using namespace std;

int main()
{
    while(1){
        short s,e;
        string input;
        cout << "Enter The Base of Your Input: ";
        cin >> s;
        cin.clear();

        cout << "\nEnter The Number: ";
        cin >> input;
        cin.clear();

        cout << "\nEnter The Base You Want To Output: ";
        cin >> e;
        cin.clear();

        cout << endl << "Output: " << Converter::convert(s, input, e) << endl << endl << endl;
    }
    return 0;
}
