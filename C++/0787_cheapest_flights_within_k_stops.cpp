/*
 * There are n cities connected by m flights.
 *
 * Each flight start from city u and arrives at v with a price w.
 *
 * Now given all the cities and flights, together with starting city src and the destination dst,
 * your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.
 *
 */

class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
            // create adjacency list
            unordered_map<int, vector<pair<int, int>>> adjList;
            for (auto f: flights)
                adjList[f[0]].push_back({f[1], f[2]});

            //minHeap based on cost of distance from source
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
            minHeap.push({0, src, K + 1});  //cost, vertex, hops

            while (!minHeap.empty()){
                auto t = minHeap.top();
                minHeap.pop();

                int cost = t[0];
                int curr = t[1];
                int stop = t[2];
                if (curr == dst)
                    return cost;

                if (stop > 0)
                    for (auto next: adjList[curr])
                        minHeap.push({cost + next.second, next.first, stop - 1});
            }
            return -1;
        }
};
