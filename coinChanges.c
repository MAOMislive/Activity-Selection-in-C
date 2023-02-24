#include <stdio.h>
#include <limits.h>
int min(int a, int b) {
    return (a < b) ? a : b;
}

int coinChange(int coins[], int n, int amount) {
    int dp[amount+1]; // Array to store the minimum number of coins needed to make change for each amount from 0 to amount
    dp[0] = 0; 
    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX; // Initialize the minimum number of coins needed to make change for amount i to infinity
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) { // Consider only coins that are less than or equal to i
                int sub_res = dp[i-coins[j]]; // Compute the minimum number of coins needed to make change for the remaining amount i - coins[j]
                if (sub_res != INT_MAX) { // If a solution exists for the remaining amount, update dp[i] to the minimum of the current value and the solution plus one coin
                    dp[i] = min(dp[i], sub_res + 1);
                }
            }
        }
    }
    return dp[amount]; // Return the minimum number of coins needed to make change for the given amount
}

int main() {
    int coins[] = {1, 5, 10, 25};
    int n = 4;
    int amount = 37;
    printf("Minimum number of coins needed to make change for %d cents: %d\n", amount, coinChange(coins, n, amount)); 
    return 0;
}
