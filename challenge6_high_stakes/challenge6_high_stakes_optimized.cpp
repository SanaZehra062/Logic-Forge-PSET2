#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int deadline;
    int profit;
};

bool compareProfit(Job a, Job b) {
    return a.profit > b.profit;
}

// Find the latest available slot
int findSlot(vector<int>& parent, int s) {
    if(parent[s] == s) return s;
    return parent[s] = findSlot(parent, parent[s]);
}

vector<int> maximize_freelance_profit(vector<int>& deadlines, vector<int>& profits) {
    int n = deadlines.size();
    vector<Job> jobs(n);
    int maxDeadline = 0;

    for(int i = 0; i < n; i++) {
        jobs[i] = {deadlines[i], profits[i]};
        maxDeadline = max(maxDeadline, deadlines[i]);
    }

    sort(jobs.begin(), jobs.end(), compareProfit);

    vector<int> parent(maxDeadline + 1);
    for(int i = 0; i <= maxDeadline; i++)
        parent[i] = i;

    int totalProfit = 0, totalJobs = 0;

    for(int i = 0; i < n; i++) {
        int availableSlot = findSlot(parent, jobs[i].deadline);
        if(availableSlot > 0) {
            totalProfit += jobs[i].profit;
            totalJobs++;
            parent[availableSlot] = availableSlot - 1; // mark slot as filled
        }
    }

    return {totalJobs, totalProfit};
}

int main() {
    vector<int> deadlines = {4,1,1,1};
    vector<int> profits = {20,10,40,30};

    vector<int> result = maximize_freelance_profit(deadlines, profits);
    cout << "Jobs Completed: " << result[0] << ", Max Profit: " << result[1];
    return 0;
}
