#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        // Safe middle calculation to prevent potential integer overflow
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1; // Target lies in the right half
        } else {
            right = mid - 1; // Target lies in the left half
        }
    }

    return -1; // Target not found
}