#include <iostream>
#include <vector>
using namespace std;

bool isNonOverlapping(vector<vector<int>>& intervals, vector<int>& selected) {
    for (int i = 0; i < selected.size(); i++) {
        for (int j = i + 1; j < selected.size(); j++) {
            int a = selected[i], b = selected[j];
            if (intervals[a][0] < intervals[b][1] && intervals[b][0] < intervals[a][1])
                return false;
        }
    }
    return true;
}

void helper(vector<vector<int>>& intervals, int index, vector<int>& selected, int& minRemove) {
    if (index == intervals.size()) {
        if (isNonOverlapping(intervals, selected))
            minRemove = min(minRemove, (int)(intervals.size() - selected.size()));
        return;
    }

    // Include current interval
    selected.push_back(index);
    helper(intervals, index + 1, selected, minRemove);
    selected.pop_back();

    // Exclude current interval
    helper(intervals, index + 1, selected, minRemove);
}

int min_cancelled_bookings(vector<vector<int>>& intervals) {
    int minRemove = intervals.size();
    vector<int> selected;
    helper(intervals, 0, selected, minRemove);
    return minRemove;
}

int main() {
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout << "Minimum bookings to cancel: " << min_cancelled_bookings(intervals);
    return 0;
}
