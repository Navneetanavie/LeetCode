class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Min-heap using lambda comparator on squared distance
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        
        for (auto& point : points) {
            int distSq = point[0] * point[0] + point[1] * point[1];
            pq.push({distSq, {point[0], point[1]}});
        }

        vector<vector<int>> result;
        while (k--) {
            auto [dist, coord] = pq.top(); pq.pop();
            result.push_back({coord.first, coord.second});
        }
        return result;
    }
};