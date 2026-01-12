#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int calculate_minimum_speed(vector<int>& piles, int k) {
    int maxPile = *max_element(piles.begin(), piles.end());
    for(int s = 1; s <= maxPile; s++) {
        long long hours = 0;
        for(int pile : piles) {
            hours += (pile + s - 1) / s; // ceil division
        }
        if(hours <= k) return s;
    }
    return maxPile;
}

int main() {
    vector<int> piles = {5, 10, 3};
    int k = 4;

    cout << "Minimum speed: " << calculate_minimum_speed(piles, k);
    return 0;
}
