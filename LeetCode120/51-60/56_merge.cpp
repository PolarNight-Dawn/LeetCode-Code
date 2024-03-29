#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-8-1.
//

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::vector<std::vector<int>> res;

        if (intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a, const std::vector<int> &b){return a[0] < b[0];});
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (res.back()[1] >= intervals[i][0]) res.back()[1] = std::max(res.back()[1], intervals[i][1]);
            else res.push_back(intervals[i]);
        }

        return res;
    }
};

int main56() {
    std::vector<std::vector<int>> intervals = {{1, 4}, {0, 2}, {3, 5}};
    std::vector<std::vector<int>> res;

    Solution sol;
    res = sol.merge(intervals);

    for (auto &vec :res) {
        for (auto &tmp : vec) {
            std::cout << tmp << " ";
        }
        std::cout << ";";
    }

}