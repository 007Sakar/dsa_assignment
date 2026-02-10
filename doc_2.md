# Program 2: Infix to Postfix Conversion and Evaluation

## Data Structures Used
- **Stack** for operators: implemented using an array.
- **Character array** for storing postfix expression.
- **Integer stack** for evaluating postfix.

## Functions

### `push(Stack *s, char c)`, `pop(Stack *s)`, `peek(Stack *s)`
- Standard stack operations for operators.

### `precedence(char op)`
- Returns the precedence value of operators:
  - `+`/`-` = 1
  - `*`/`/` = 2

### `isOperator(char c)`
- Checks if `c` is one of `+`, `-`, `*`, `/`.

### `infixToPostfix(char* infix, char* postfix)`
- Converts an infix expression to postfix using the operator stack.

### `evalPostfix(char* postfix)`
- Evaluates the postfix expression using integer stack.

## main() Workflow
1. Reads an infix expression (single-digit operands only).
2. Calls `infixToPostfix()` to get postfix form.
3. Calls `evalPostfix()` to compute the result.
4. Prints the postfix expression and evaluation result.

## Sample Output
