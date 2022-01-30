//
//  QueType.hpp
//  QueueADT
//
//  Created by Brandon Perry on 1/29/22.
//

#ifndef QueType_hpp
#define QueType_hpp

#include <stdio.h>
#include <string>

class FullQueue
{};

class EmptyQueue
{};

using namespace std;

struct ExpenseType
{
    string memo;
    double amount;
};

class QueType
{
public:
    QueType(int max); // parametrized constructor
    QueType();        // default constructor
    ~QueType();       // default deconstructor
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(ExpenseType newExpense);
    void Dequeue(ExpenseType& newExpense);
private:
    int front;
    int rear;
    ExpenseType* expense;
    int maxQue;
};

#endif
