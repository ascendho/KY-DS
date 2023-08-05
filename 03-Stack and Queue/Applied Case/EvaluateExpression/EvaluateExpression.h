#ifndef INC_03_STACK_AND_QUEUE_EVALUATEEXPRESSION_H
#define INC_03_STACK_AND_QUEUE_EVALUATEEXPRESSION_H

#include "../../../Status/Status.h"
#include "../../TextBook/LinkStack.h"

bool In(char ch);

char Precede(char theta1, char theta2);

char Operate(char first, char theta, char second);

char EvaluateExpression();

#endif //INC_03_STACK_AND_QUEUE_EVALUATEEXPRESSION_H