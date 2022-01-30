//
//  CountedQueType.hpp
//  QueueADT
//
//  Created by Brandon Perry on 1/29/22.
//

#ifndef CountedQueType_hpp
#define CountedQueType_hpp

#include "QueType.hpp"

class CountedQueType : public QueType
{
public:
    CountedQueType(int max); // parametrized constructor
    CountedQueType();        // default constructor
    void Enqueue(ExpenseType newExpense);
    void Dequeue(ExpenseType& newExpense);
    int GetLength() const;
    double GetTotalExpense(ExpenseType newExpense);
    void MakeEmpty();
private:
    int length;
    ExpenseType* expense;
};

#endif
