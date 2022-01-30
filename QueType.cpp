//
//  QueType.cpp
//  QueueADT
//
//  Created by Brandon Perry on 1/29/22.
//

#include "QueType.hpp"
#include <cstddef>    //For NULL
#include <new>        //For bad_alloc
#include <string>
#include "CountedQueType.hpp"

struct ExpenseType;

QueType::QueType(int max)
// Function: parameterized class constructor
// Pre: none
// Post: maxQue, front, rear have been initialized
//      the array to hold the que elemements has been           dynamically allocated
{
    maxQue = max + 1;
    front = maxQue - 1;
    rear = maxQue - 1;
    expense = new ExpenseType[maxQue];
}


QueType::QueType()
// Function: default class constructor
// Pre: none
// Post: maxQue, front, and rear have been initialized
//      the array to hold the queue elements has been           dynamically allocated
{
    maxQue = 6; // max size (5) plus 1 as a reserve
    front = maxQue - 1;
    rear = maxQue - 1;
    expense = new ExpenseType[maxQue];
}


QueType::~QueType()
// Function: class deconstructor
// Pre: queue is initialized
// Post: queue is deleted
{
    delete[] expense;
}


void QueType::MakeEmpty()
// Function: initializes queue to an empty state
// Pre: none
// Post: front and rear have been reset to the empty state
{
    front = maxQue - 1;
    rear = maxQue - 1;
}


bool QueType::IsEmpty() const
// Function: returns true if the queue is empty
//          returns false otherwise
// Pre: queue has been initialized
// Post: returns true if rear and front are equal
//       otherwise returns false
{
    return (rear == front);
}


bool QueType::IsFull() const
// Function: returns true if the queue is full
//           returns false otherwise
// Pre: queue has been initialized
// Post: returns true if the % of rear + 1 equals the front
//       otherwise returns false
{
    return ((rear + 1) % maxQue == front);
}


void QueType::Enqueue(ExpenseType newExpense)
// Function: adds item into the rear of queue
// Pre: queue is initialized
// Post: If (queue is not full) newItem is at the rear of        the queue otherwise, a FullQueue exception is           thrown
{
    if (IsFull())
        throw FullQueue();
    else
    {
        rear = (rear + 1) % maxQue;
        expense[rear] = newExpense;
    }
}


void QueType::Dequeue(ExpenseType& newExpense)
// Function: removes item from front of queue
// Pre: queue is initialized
// Post: if (queue is not empty) the front of the queue has      been removed and a copy returned in item
//       otherwise, an EmptyQueue exception is thrown
{
    if (IsEmpty())
        throw EmptyQueue();
    else
    {
        front = (front + 1) % maxQue;
        newExpense = expense[front];
    }
}
