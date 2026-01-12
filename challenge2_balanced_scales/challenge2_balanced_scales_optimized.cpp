#include <iostream>
#include <vector>
using namespace std;

bool can_balance_scales(vector<int>& arr) {
    int totalSum = 0;
    for (int x : arr)
        totalSum += x;

    if (totalSum % 2 != 0)
        return false;

    int target = totalSum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int weight : arr) {
        for (int s = target; s >= weight; s--) {
            if (dp[s - weight])
                dp[s] = true;
        }
    }
    return dp[target];
}

int main() {
    vector<int> arr = {1, 5, 11, 5};

    if (can_balance_scales(arr))
        cout << "True";
    else
        cout << "False";

    return 0;
}
