/****************************************************************/
/* Implementation file for Prefix Expression Evaluator              */
/* Evaluates prefix expressions using a stack data structure        */
/* Uses the LinkedStack implementation provided in the assignment   */
/****************************************************************/

#include "PrefixEvaluator.h"
#include "LinkedStack.h"
#include <cctype> 
#include <string>
#include <iostream>

/****************************************************************/
/* Function:   evaluatePrefix                                    */
/* Inputs:     a string containing a valid prefix expression     */
/* Outputs:    the calculated value as an integer                */
/* Purpose:    This function evaluates a prefix expression       */
/*             using a stack and returns the result              */
/****************************************************************/
int evaluatePrefix(const std::string& expression) {
  LinkedStack<int> operandStack;  // Stack to store operands
  bool isValidExpression = true;  // Flag to track validity
  int finalResult = 0;            // Store the final result
  
  // FIX THIS LATER: Remove debug statements 🚨
  std::cout << "\n--- Debug: Evaluating expression for: " << expression << " ---\n";
  
  // Process expression from right to left
  for (int i = expression.length() - 1; i >= 0 && isValidExpression; i--) {
      char currentChar = expression[i];
      if (currentChar == ' ') {
          continue;
      }
      std::cout << "Debug: Processing character: '" << currentChar << "'\n";
      

      if (isdigit(currentChar)) {
          int number = currentChar - '0';
          // Push the operand onto the stack
          operandStack.push(number);
          std::cout << "Debug: Pushed operand " << number << " onto stack\n";
      }
      // If current character is an operator
      else if (currentChar == '+' || currentChar == '-' || 
               currentChar == '*' || currentChar == '/') {
          // Check if we have at least two operands
          if (operandStack.isEmpty()) {
              std::cout << "Error: Not enough operands for operator " << currentChar << std::endl;
              isValidExpression = false;
              break; // FIX THIS LATER 
          }
          
          // Pop the first operand
          int operand1 = operandStack.peek();
          operandStack.pop();
          std::cout << "Debug: Popped first operand: " << operand1 << "\n";
          
          // Check if we have a second operand
          if (operandStack.isEmpty()) {
              std::cout << "Error: Not enough operands for operator " << currentChar << std::endl;
              isValidExpression = false;
              break; // FIX THIS LATER 
          }
          
          // Pop the second operand
          int operand2 = operandStack.peek();
          operandStack.pop();
          std::cout << "Debug: Popped second operand: " << operand2 << "\n";
          
          int result = 0;
          // Perform the operation
          switch (currentChar) {
              case '+':
                  result = operand1 + operand2;
                  std::cout << "Debug: Performed " << operand1 << " + " << operand2 << " = " << result << "\n";
                  break;
              case '-':
                  result = operand1 - operand2;
                  std::cout << "Debug: Performed " << operand1 << " - " << operand2 << " = " << result << "\n";
                  break;
              case '*':
                  result = operand1 * operand2;
                  std::cout << "Debug: Performed " << operand1 << " * " << operand2 << " = " << result << "\n";
                  break;
              case '/':
                  if (operand2 == 0) {
                      std::cout << "Error: Division by zero" << std::endl;
                      isValidExpression = false;
                      continue;
                  }
                  result = operand1 / operand2;
                  std::cout << "Debug: Performed " << operand1 << " / " << operand2 << " = " << result << "\n";
                  break;
          } 
          // Push the result back onto the stack
          operandStack.push(result);
          std::cout << "Debug: Pushed result " << result << " onto stack\n";
      }
  }
  
  // Get the final result if the expression is valid
  if (isValidExpression && !operandStack.isEmpty()) {
      finalResult = operandStack.peek();
      std::cout << "Debug: Final result from stack: " << finalResult << "\n";
      
      // Check if there are extra operands (incomplete expression)
      operandStack.pop();
      if (!operandStack.isEmpty()) {
          std::cout << "Warning: Extra operands in expression" << std::endl;
          while (!operandStack.isEmpty()) {
              std::cout << "Debug: Extra value in stack: " << operandStack.peek() << "\n";
              operandStack.pop();
          }
      }
  }
  
  std::cout << "--- End of evaluation ---\n";
  return finalResult;
}