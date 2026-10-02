#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        // Allocate space for an empty string
        char* emptyStr = (char*)malloc(sizeof(char));
        emptyStr[0] = '\0';
        return emptyStr;
    }

    // Check characters one by one using the first string as a benchmark
    for (int i = 0; strs[0][i] != '\0'; i++) {
        char currentChar = strs[0][i];

        for (int j = 1; j < strsSize; j++) {
            // If we reach the end of a string or find a non-matching character
            if (strs[j][i] == '\0' || strs[j][i] != currentChar) {
                char* result = (char*)malloc((i + 1) * sizeof(char));
                strncpy(result, strs[0], i);
                result[i] = '\0'; // Null-terminate the string
                return result;
            }
        }
    }

    // If the loop finishes, the entire first string is the common prefix
    int len = strlen(strs[0]);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    strcpy(result, strs[0]);
    return result;
}