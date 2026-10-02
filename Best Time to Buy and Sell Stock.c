#include <stdio.h>
#include <limits.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) {
        return 0;
    }

    int min_price = INT_MAX;
    int max_profit = 0;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < min_price) {
            min_price = prices[i]; // Update lowest buy price seen so far
        } else if (prices[i] - min_price > max_profit) {
            max_profit = prices[i] - min_price; // Update maximum profit achievable
        }
    }

    return max_profit;
}