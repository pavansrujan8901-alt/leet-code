#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    
    // Allocate stack memory dynamically matching string length
    char* stack = (char*)malloc(len * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++) {
        char current = s[i];

        // If it's an opening bracket, push to stack
        if (current == '(' || current == '{' || current == '[') {
            stack[++top] = current;
        } 
        // If it's a closing bracket
        else {
            // Stack is empty -> no matching open bracket
            if (top == -1) {
                free(stack);
                return false;
            }

            char topChar = stack[top--];
            
            // Check if brackets match
            if ((current == ')' && topChar != '(') ||
                (current == '}' && topChar != '{') ||
                (current == ']' && topChar != '[')) {
                free(stack);
                return false;
            }
        }
    }

    // Valid only if all opened brackets were closed
    bool valid = (top == -1);
    free(stack);
    return valid;
}