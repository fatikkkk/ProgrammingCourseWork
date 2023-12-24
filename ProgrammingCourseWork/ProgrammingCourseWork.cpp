#include <iostream>
#include "DataTypes.h"
#include "OneArrays.h"
#include "TwoArraysIndexes.h"
#include "CharArrays.h"

using namespace std;

void main()
{
    int selectSection;
    cout << "Hello! Welcome! Now you use Course project of subject Programming!\n";
    cout << "Select the section you will work with:\n";
    cout << "\t1 - Data Types and Their Internal Representation in Memory\n";
    cout << "\t2 - One-Dimensional Static Arrays\n";
    cout << "\t3 - Two-Dimensional Static Arrays. Indexes\n";
    cout << "\t4 - Work with Char Arrays (analog String)\n";
    cin >> selectSection;
    switch (selectSection)
    {
    case 1:
        cout << "You select Work with Data Types and Their Internal Representation in Memory\n";
        mainOne();
        break;
    
    case 2:
        cout << "You select Work with One-Dimensional Static Arrays\n";
        mainSecond();
        break;

    case 3:
        cout << "You select Work with Two-Dimensional Static Arrays and Indexes\n";
        mainThird();
        break;
    case 4:
        cout << "You select Work with Char Arrays (analog String)\n";
        mainFourth();
        break;

    default:
        break;
    }

}
