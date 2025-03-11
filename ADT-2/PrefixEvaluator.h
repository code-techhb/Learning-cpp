/****************************************************************/
/* Header file for Prefix Expression Evaluator                      */
/* Contains function prototype for evaluating prefix expressions    */
/****************************************************************/

#ifndef PREFIX_EVALUATOR_
#define PREFIX_EVALUATOR_

#include <string>

/****************************************************************/
/* Function:   evaluatePrefix                                    */
/* Inputs:     a string containing a valid prefix expression     */
/* Outputs:    the calculated value as an integer                */
/* Purpose:    This function evaluates a prefix expression       */
/*             using a stack and returns the result              */
/****************************************************************/
int evaluatePrefix(const std::string& expression);

#include "PrefixEvaluator.cpp"
#endif