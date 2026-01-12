#include <iostream>
using namespace std;

int count_ways_to_summit(int n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    int prev1 = 2;
    int prev2 = 1;
    int current;

    for (int i = 3; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

int main() {
    int n;
    cout << "Enter number of steps: ";
    cin >> n;

    cout << "Total ways: " << count_ways_to_summit(n);
    return 0;
}
