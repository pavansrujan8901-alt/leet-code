#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int insertPos = 0;

    // Step 1: Shift all non-zero elements to the front
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[insertPos] = nums[i];
            insertPos++;
        }
    }

    // Step 2: Fill the rest of the array with zeroes
    while (insertPos < numsSize) {
        nums[insertPos] = 0;
        insertPos++;
    }
}