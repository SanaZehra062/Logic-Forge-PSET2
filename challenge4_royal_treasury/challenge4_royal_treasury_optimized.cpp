#include <iostream>
#include <vector>
using namespace std;

int count_payment_combinations(vector<int>& coins, int total_sum) {
    vector<int> dp(total_sum + 1, 0);
    dp[0] = 1; // Base case: one way to make sum 0

    for (int coin : coins) {
        for (int s = coin; s <= total_sum; s++) {
            dp[s] += dp[s - coin];
        }
    }
    return dp[total_sum];
}

int main() {
    vector<int> coins = {1, 2, 3};
    int total_sum = 4;

    cout << "Total ways: " << count_payment_combinations(coins, total_sum);

    return 0;
}
