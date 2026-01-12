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

vector<int> maximize_freelance_profit(vector<int>& deadlines, vector<int>& profits) {
    int n = deadlines.size();
    vector<Job> jobs(n);
    int maxDeadline = 0;

    for(int i = 0; i < n; i++) {
        jobs[i] = {deadlines[i], profits[i]};
        maxDeadline = max(maxDeadline, deadlines[i]);
    }

    sort(jobs.begin(), jobs.end(), compareProfit);

    vector<bool> slot(maxDeadline + 1, false);
    int totalProfit = 0, totalJobs = 0;

    for(int i = 0; i < n; i++) {
        for(int j = jobs[i].deadline; j > 0; j--) {
            if(!slot[j]) {
                slot[j] = true;
                totalProfit += jobs[i].profit;
                totalJobs++;
                break;
            }
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
