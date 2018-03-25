/*********************************************************************
** Program name: queue.cpp
** Author: Alexandra Carper
** Date: 02/21/2018
** Description: This Queue class implementation file defines
 *              the member functions of the Queue class.
*********************************************************************/


#include <iostream>
#include <cstdlib>
#include "queue.hpp"

using std::cout;
using std::endl;

/********************************************************************
 * Description: Constructor
 *******************************************************************/
Queue::Queue()
{
    head = NULL;
}
/********************************************************************
 * Description: Destructor
 *******************************************************************/
Queue::~Queue()
{
    while(!isEmpty())
    {
        removeFront();
    }

}
/********************************************************************
 * Description: Checks if list is empty. Returns true for empty,
 *              false for not empty.
 *******************************************************************/
bool Queue::isEmpty()
{
    if(head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/********************************************************************
 * Description: Adds value to the back of the queue
 *******************************************************************/
void Queue::addBack(int val)
{
    //Initialize new node
    struct QueueNode* new_node = new QueueNode;
    //Set node attributes
    new_node->val = val;
    //If list is empty
    if(isEmpty())
    {
        //Make next and prev point to new_node
        new_node->next = new_node->prev = new_node;
        //Make head point to new_node
        head = new_node;
        return;
    }
    else
    {
        //Create temp node
        QueueNode *temp;
        //Assign temp to value of head node
        temp = head;
        //Assign temp to last node
        temp = temp->prev;
        //Assign new_node's pointer to next node as head (circular)
        new_node->next = head;
        //Make new_node point back to old last node
        new_node->prev = temp;
        //Make old last node's next pointer point to new_node
        temp->next = new_node;
        //Make head node's prev pointer point to new_node (circular)
        head->prev = new_node;

    }
}
/********************************************************************
 * Description: Returns the value at the head of the queue
 *******************************************************************/
int Queue::getFront()
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        return head->val;
    }
}
/********************************************************************
 * Description: Removes value from the front of the queue
 *******************************************************************/
void Queue::removeFront()
{
    //If list is empty
    if(isEmpty())
    {
        cout << "List is empty!" << endl;
        return;
    }
        //If list has one element
    else if(head->next == head)
    {
        delete head;
        head = NULL;
    }
        //If list has more than one element
    else
    {
        QueueNode *temp;
        QueueNode *new_head;
        //Assign temp to first node
        temp = head;
        //Assign new_head to second node
        new_head = head->next;
        //Make new_head's prev pointer point to last node
        new_head->prev = temp->prev;
        temp->prev->next = new_head;
        //Set head to the node pointed to by new_head
        head = new_head;
        //Delete temp node
        delete(temp);
    }
}
/********************************************************************
 * Description: Prints all the values in the queue
 *******************************************************************/
void Queue::printQueue()
{
    //If list is empty
    if(isEmpty())
    {
        cout << "List is empty!" << endl;
        return;
    }
    else
    {
        cout << "Your queue is: ";
        //Create temp variable and assign to head
        QueueNode *temp = head;
        //While the next node is not the head (circular)
        while(temp->next != head)
        {
            //Display value + ' '
            cout << temp->val << " ";
            //Move temp to next node
            temp = temp->next;
        }
        //Print last value
        cout << temp->val << endl;
    }
}
