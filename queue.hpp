/*********************************************************************
** Program name: queue.hpp
** Author: Alexandra Carper
** Date: 02/21/2018
** Description: This Queue class declaration file declares the
 *              Queue class and the QueueNode data structure.
*********************************************************************/


#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

class Queue
{
    struct QueueNode
    {
        int val;
        QueueNode *next;
        QueueNode *prev;
    };
    QueueNode *head;

public:
    Queue();
    ~Queue();
    bool isEmpty();
    void addBack(int val);
    int getFront();
    void removeFront();
    void printQueue();
};

#endif