#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool canFinish(vector<int>& piles, int k, int speed) {
    long long hours = 0;
    for(int pile : piles) {
        hours += (pile + speed - 1) / speed; // ceil division
    }
    return hours <= k;
}

int calculate_minimum_speed(vector<int>& piles, int k) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    int result = high;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(canFinish(piles, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    vector<int> piles = {5, 10, 3};
    int k = 4;

    cout << "Minimum speed: " << calculate_minimum_speed(piles, k);
    return 0;
}
