#include <iostream>
using namespace std;

int count_ways_to_summit(int n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return count_ways_to_summit(n - 1) + count_ways_to_summit(n - 2);
}

int main() {
    int n;
    cout << "Enter number of steps: ";
    cin >> n;

    cout << "Total ways: " << count_ways_to_summit(n);
    return 0;
}
