# QueueADT-CS221
This was a program for my CS221 class. The assignment was to create a queue using a circular floating array and perform designated operations to it.

Completed: 10-19-2020

Assigned by: Mr. Troung Tran

&nbsp;

## Assignment

### 1. Overview

This assignment is to Implement Queue ADT as a counted queue using a circular floating array.

&nbsp;

### 2. Requirements

#### 2.1 (Class) 
Implement QueType class flow the structure of a circular floating array with the reserved front as discussed in the lecture of chapter 5 (textbook page 312 provides an example of this type). 

In this assignment, the elements of QueType are the instances of the struct ExpenseType as described below.

The maximum number of elements that can be held in the QueType is 5 (we keep it small for our testing convenience). 

#### 2.2 (Struct) 
Declare a struct ExpenseType in the QueType class. The ExpenseType struct contains a string memo and a double amount variables.

#### 2.3 (Class) 
Implement CountedQueType class as a derived class of QueType class. The CountedQueType class inherits all data and functions of the QueType class. 

The following data and function need to be implemented in the CountedQueType class:
```C++
int length:  //to keep track of the number of elements in the queue.
Default constructor: //to create a queue object with no element.
GetLength(): //to return the length value.
Enqueue function: //this function is a derived function of the Enqueue function in the QueTye class. 
                  //This function needs to update the length value after adding an element to the queue.
Dequeue function: //this function is a derived function of the Dequeue function in the QueTye class. 
                  //This function needs to update the length value after removing an element to the queue.
MakeEmpty(): //this function is a derived function of the MakeEmpty function in the QueTye class. 
             //This function needs to update the length data after resetting the front and rear index values of the queue.
```
*Notice that these derived functions above are required to call the base function of the base class.
```C++
GetTotalExpense function: // to return the sum of all expense value of the elements in the queue.  
                  //(Hint: The length variable is useful to keep up with the number of elements currently in the queue. )
```

#### 2.4 (TestDriver) 
Implement the test program (TestDrive.cpp) for testing the CountedQueType . This test program must create a queue, read an input file, test all functions of the CountedQueType class, and write output results to an output file. 

The input file must cover the following:

- IsEmpty
- GetLength
- Enqueue food 300.50
- Enqueue gas 60.35
- Enqueue  book 89.99
- Enqueue computer 699.00
- GetLength 
- GetTotalExpense
- Dequeue
- Dequeue
- GetLength 
- GetTotalExpense
- Enqueue rent 850.0
- Enqueue internet 29.99
- Enqueue utility 178.30
- Enqueue game 50.00
- IsFull
- GetLength
- GetTotalExpense
- MakeEmpty
- IsEmpty
- GetLength
- Quit

&nbsp;

### 3. Submission

These products shall be delivered to the instructor electronically via Canvas as specified below.

#### 3.2 Program Description Document 

- The student shall provide a general description of the requirement of the program (see lectures of chapter 1 and chapter 2).

- For each of the class QueType and CountedQueType, provide an ADT Specification. 

- Provide a class interface diagram for the CountedQueType as the derived class of the QueType (see textbook figure 5.15 for an example). Also, explain what member functions of the CountedQueType class are the new functions, what functions are the override functions.

#### 3.3 Program Test Plan Document 
The student shall provide the test plan document (see lecture of chapter 1 and chapter 2). The document must include a detailed test plan, input file, expected output, and results of test experiments (actual output and snapshot of console/terminal output).
