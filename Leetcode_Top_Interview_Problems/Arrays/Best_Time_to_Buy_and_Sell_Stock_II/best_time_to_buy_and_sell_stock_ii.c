#include <stdio.h>
#include <assert.h>

int maxProfit(int* prices, int pricesSize) {

    int profit = 0;

    for(int i = 0; i < pricesSize - 1; i++) {
        if (prices[i] < prices[i + 1]){
            profit += (prices[i + 1] - prices[i]);
        }
    }

    return profit;
    
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};  // Input array
    int expectedProfit = 7;    // Expected output
    int pricesSize = sizeof(prices) / sizeof(prices[0]);
    
    int profit = maxProfit(prices, pricesSize);

    // Judge checks
    assert(profit == expectedProfit);

    printf("Assertions passed.\n");
    printf("Profit = %d\n", profit);
    
    return 0;
}

