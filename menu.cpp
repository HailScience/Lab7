/*********************************************************************
** Program name: menu.cpp
** Author: Alexandra Carper
** Date: 02/21/2018
** Description: Implementation file for the menu function.
*********************************************************************/


#include <iostream>
#include "menu.hpp"

using std::cin;
using std::cout;
using std::endl;

int menu()
{
    cout << "1. Add a value to the back of queue\n";
    cout << "2. Display the front value\n";
    cout << "3. Remove the front node\n";
    cout << "4. Display the queue's content\n";
    cout << "5. Exit\n";
    cout << endl;

    bool validData = false;
    int choice;

    while(!validData)
    {
        cin >> choice;
        cout << endl;
        if(cin.fail())
        {
            cout << "Error! Please enter a valid choice!" << endl;
            cin.clear();
            cin.ignore();
        }
        else if(choice < 1 || choice > 5)
        {
            cout << "Error! Please enter a valid choice!" << endl;
            cin.clear();
            cin.ignore();
        }
        else
        {
            validData = true;
            return choice;
        }
    }
}