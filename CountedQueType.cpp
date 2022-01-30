//
//  CountedQueType.cpp
//  QueueADT
//
//  Created by Brandon Perry on 1/29/22.
//

#include "CountedQueType.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

CountedQueType::CountedQueType(int max) : QueType(max)
// Function: paramterized class constructor
// Pre: none
// Post: initializes length
{
    length = 0;
}


CountedQueType::CountedQueType() : QueType()
// Function: default class constructor
// Pre: none
// Post: initializes length
{
    length = 0;
}


void CountedQueType::Enqueue(ExpenseType newExpense)
// Function: implements Enqueue from QueType and increases the length
// Pre: queue has been initialized
// Post: QueType enqueue is implemented length is increased      by one
{
    try
    {
        QueType::Enqueue(newExpense);
        // increase length due to adding newExpense
        length++;
    }
    catch (FullQueue)
    {
        throw FullQueue();
        
    }
}


void CountedQueType::Dequeue(ExpenseType& newExpense)
// Function: implements Dequeue from QueType and reduces the length
// Pre: queue has been initialized queue is not empty
// Post: Quetype Dequeue is implemented length is reduced        by one
{
    try
    {
        QueType::Dequeue(newExpense);
        // decrease length due to removing newExpense
        length--;
    }
    catch (EmptyQueue)
    {
        throw EmptyQueue();
    }
}


int CountedQueType::GetLength() const
// Function: gets the length of the queue
// Pre: queue has been initialized
// Post: returns length
{
    return length;
}


double CountedQueType::GetTotalExpense(ExpenseType newExpense)
// Function: adds up all of the expenses within the queue
// Pre: queue is initialized
// Post: returns total of all amounts added
{
    // initializing variables
    double total = 0.0;
    double temp = 0.0;
    
    // for loop to go through queue
    for (int i = 0; i < length; i++) {
        // gets access to newExpense
        Dequeue(newExpense);
        // retireves amount
        temp = newExpense.amount;
        // adds to sum
        total += temp;
        // puts back newExpense
        Enqueue(newExpense);
    }
    return total;
}


void CountedQueType::MakeEmpty()
//Function: Initializes the queue to an empty state.
//Precondition: None
//Postcondition: Queue is empty.
{
    QueType::MakeEmpty();
    length = 0;
}
