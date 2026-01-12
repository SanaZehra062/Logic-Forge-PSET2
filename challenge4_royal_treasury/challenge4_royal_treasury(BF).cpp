#include <iostream>
#include <vector>
using namespace std;

int countWaysBF(vector<int>& coins, int n, int sum, int index) {
    if (sum == 0)
        return 1;
    if (sum < 0 || index == n)
        return 0;

    // Include current coin
    int include = countWaysBF(coins, n, sum - coins[index], index);
    // Exclude current coin
    int exclude = countWaysBF(coins, n, sum, index + 1);

    return include + exclude;
}

int count_payment_combinations(vector<int>& coins, int total_sum) {
    return countWaysBF(coins, coins.size(), total_sum, 0);
}

int main() {
    vector<int> coins = {1, 2, 3};
    int total_sum = 4;

    cout << "Total ways: " << count_payment_combinations(coins, total_sum);

    return 0;
}
