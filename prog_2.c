#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int main() {
    char infix[MAX];
    char postfix[MAX];
    char stack[MAX];
    int top = -1;

    printf("Enter infix expression (single-digit numbers only): ");
    scanf("%s", infix);

    int j=0;
    for(int i=0;i<strlen(infix);i++){
        char c = infix[i];

        if(isdigit(c)){ // operand
            postfix[j++] = c;
        }
        else if(c=='+' || c=='-'){
            while(top>=0 && (stack[top]=='+' || stack[top]=='-'
                             || stack[top]=='*' || stack[top]=='/')){
                postfix[j++] = stack[top--];
            }
            stack[++top] = c;
        }
        else if(c=='*' || c=='/'){
            while(top>=0 && (stack[top]=='*' || stack[top]=='/')){
                postfix[j++] = stack[top--];
            }
            stack[++top] = c;
        }
        else if(c=='('){
            stack[++top] = c;
        }
        else if(c==')'){
            while(top>=0 && stack[top]!='('){
                postfix[j++] = stack[top--];
            }
            top--; // pop '('
        }
    }

    while(top>=0){
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';

    printf("Postfix: %s\n", postfix);

    // Evaluate postfix
    int evalStack[MAX];
    int t=-1;

    for(int i=0;i<strlen(postfix);i++){
        char c = postfix[i];
        if(isdigit(c)){
            evalStack[++t] = c-'0';
        }
        else{
            int b = evalStack[t--];
            int a = evalStack[t--];
            int res=0;
            if(c=='+') res = a+b;
            else if(c=='-') res = a-b;
            else if(c=='*') res = a*b;
            else if(c=='/') res = a/b;
            evalStack[++t] = res;
        }
    }

    printf("Evaluation: %d\n", evalStack[t]);

    return 0;
}
