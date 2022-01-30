//
//  main.cpp
//  QueueADT
//
//  Created by Brandon Perry on 1/29/22.
//

// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include "CountedQueType.hpp"
#include "QueType.hpp"

int main()
{
    using namespace std;
    
    ifstream inFile;        // operation file
    ofstream outFile;       // output file
    string inFileName;      // intput file name
    string outFileName;     // output file name
    string command;         // operation to be executed
    
    int numCommands;
    
    ExpenseType newExpense;
    CountedQueType queue;
    
    //prompts for file name, reads in, preapres file
    cout << "Enter name of input file; press return." << endl;
    cin >> inFileName;
    inFile.open(inFileName.c_str());
    
    cout << "Enter name of output file; press return." << endl;
    cin >> outFileName;
    outFile.open(outFileName.c_str());
    
    // makes sure file is opened
    if (!inFile)
    {
        cout << "File not found." << endl;
        exit(2);
    }
    
    // initializes number of commands
    numCommands = 0;
    
    // while the end of file hasn't been reached
    while (!inFile.eof()) {
        
        // read in command
        inFile >> command;
        while (command != "Quit")
        {
            if (command == "IsEmpty")
            {
                // tests each case of IsEmpty
                if (queue.IsEmpty())
                    outFile << "Queue is empty." << endl;
                else
                    outFile << "Que is not empty." << endl;
            }
            else if (command == "GetLength")
            {
                // calls function
                outFile << "Length of queue is: " << queue.GetLength() << endl;
            }
            else if (command == "Enqueue")
            {
                // reads in memo and amount
                inFile >> newExpense.memo >> newExpense.amount;
                
                // calls function
                queue.Enqueue(newExpense);
                
                // verification
                outFile << newExpense.memo << " " << newExpense.amount << " was added to queue" << endl;
            }
            else if (command == "Dequeue")
            {
                // calls function
                queue.Dequeue(newExpense);
                
                // verification
                outFile << newExpense.memo << " " << newExpense.amount << " was removed from queue" << endl;
            }
            else if (command == "GetTotalExpense")
            {
                // calls function
                outFile << "The total expenses are: " << queue.GetTotalExpense(newExpense) << endl;
            }
            else if (command == "IsFull")
            {
                // tests each case of IsFull
                if (queue.IsFull())
                    outFile << "Queue is full." << endl;
                else
                    outFile << "Queue is not full" << endl;
            }
            else if (command == "MakeEmpty")
            {
                // calls function
                queue.MakeEmpty();
            }
            
            // increments the number of commands
            numCommands++;
            
            // prints out command operation
            cout << "Command number " << numCommands << " completed."
                << endl;
            
            inFile >> command;
        };
    };
    
    // lets user know testing is complete
    cout << "Testing completed." << endl;
    return 0;
}
