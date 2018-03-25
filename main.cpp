/*********************************************************************
** Program name: main.cpp
** Author: Alexandra Carper
** Date: 02/21/2018
** Description: The main function calls to the menu class to get the
 *              menu options, retrieves a choice from the user, and
 *              performs the corresponding function on the
 *              circularly linked list.
*********************************************************************/


#include <iostream>
#include "queue.hpp"
#include "menu.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Queue queue;
    cout << "Welcome! Please enter a choice." << endl;
    int choice = menu();
    while(choice != 5)
    {
        if(choice == 1)
        {
            cout << "Please enter a positive integer: " << endl;
            bool validData = false;
            int value;

            while(!validData)
            {
                cin >> value;
                if(cin.fail())
                {
                    cout << "Error! Please enter a positive integer!" << endl;
                    cin.clear();
                    cin.ignore();
                }
                else
                {
                    validData = true;
                }
            }

            queue.addBack(value);
            choice = menu();
        }
        else if(choice == 2)
        {
            int front = queue.getFront();
            if(front == -1)
            {
                cout << "List is empty!" << endl;
            }
            else
            {
                cout << "The first node value is: " << front << endl;
                cout << endl;
            }

            choice = menu();
        }
        else if(choice == 3)
        {
            queue.removeFront();
            choice = menu();
        }
        else if(choice == 4)
        {
            queue.printQueue();
            cout << endl;
            choice = menu();
        }
    }
    if(choice == 5)
    {
        cout << "Goodbye!" << endl;
    }

    return 0;
}