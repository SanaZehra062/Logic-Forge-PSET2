#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int min_cancelled_bookings(vector<vector<int>>& intervals) {
    if(intervals.empty()) return 0;

    // Sort by end time
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    });

    int end = intervals[0][1];
    int removeCount = 0;

    for(int i = 1; i < intervals.size(); i++) {
        if(intervals[i][0] < end) {
            // overlap found ? remove
            removeCount++;
        } else {
            // update end
            end = intervals[i][1];
        }
    }

    return removeCount;
}

int main() {
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout << "Minimum bookings to cancel: " << min_cancelled_bookings(intervals);
    return 0;
}
