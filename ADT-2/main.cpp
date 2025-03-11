/****************************************************************/
/*  Houlaymatou B. | @code_techhb                        */
/* Lab 2 – Prefix Expression Evaluator using a Stack                */
/*                                                                  */
/* This program evaluates prefix expressions using a stack data     */
/* structure. It reads prefix expressions from the user and         */
/* calculates their values. The program supports integer operands   */
/* and binary operators (+, -, *, /).                               */
/*                                                                  */
/* The program continues to read and evaluate expressions until     */
/* the user enters a sentinel value to exit.                        */
/****************************************************************/

#include <iostream>
#include <string>
#include "LinkedStack.h"
#include "PrefixEvaluator.cpp"
/****************************************************************/
/* Function:   main                                              */
/* Inputs:     none                                              */
/* Outputs:    integer return status                             */
/* Purpose:    Main driver for the program, handles user         */
/*             interaction and calls the evaluator function      */
/****************************************************************/
int main() {
    // Variable declaration
    std::string expression;
    std::string sentinel = "EXIT";
    
    // Prompt user
    std::cout << "\nPrefix Expression Evaluator" << std::endl;
    std::cout << "This program evaluates prefix expressions using a stack." << std::endl;
    std::cout << "Enter 'EXIT' to end the program." << std::endl;
    std::cout << std::endl;
    std::cout << "Enter a prefix expression: ";
    std::getline(std::cin, expression);
    
    // continue until sentinel value is entered
    while (expression != sentinel) {
        // Evaluate the expression and display the result
        int result = evaluatePrefix(expression);
        std::cout << expression << " = " << result << std::endl;
    
        // Get next expression
        std::cout << "\nEnter a prefix expression: ";
        std::getline(std::cin, expression);
    }

    std::cout << "Program ended. See you next time!" << std::endl;
    return 0;
}