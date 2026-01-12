#include <iostream>
#include <vector>
using namespace std;

bool helper(vector<int>& arr, int index, int currentSum, int target) {
    if (currentSum == target)
        return true;
    if (index == arr.size() || currentSum > target)
        return false;

    // choice: include or exclude
    return helper(arr, index + 1, currentSum + arr[index], target) ||
           helper(arr, index + 1, currentSum, target);
}

bool can_balance_scales(vector<int>& arr) {
    int totalSum = 0;
    for (int x : arr)
        totalSum += x;

    if (totalSum % 2 != 0)
        return false;

    return helper(arr, 0, 0, totalSum / 2);
}

int main() {
    vector<int> arr = {1, 5, 11, 5};
    if (can_balance_scales(arr))
        cout << "True";
    else
        cout << "False";

    return 0;
}
