class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        // Create adjacency list
        // graph[u] = {destination, price}
        vector<vector<pair<int, int>>> graph(n);

        for(auto flight : flights) {

            int u = flight[0];
            int v = flight[1];
            int price = flight[2];

            graph[u].push_back({v, price});
        }

        // cost[i] = cheapest cost to reach city i
        vector<int> cost(n, INT_MAX);

        // Start city has cost 0
        cost[src] = 0;

        // Queue stores {city, cost}
        queue<pair<int, int>> q;

        q.push({src, 0});

        // We can take at most k+1 flights
        int stops = 0;

        while(!q.empty() && stops <= k) {

            // Number of cities in current level
            int size = q.size();

            // Store the costs from previous level
            // so that we don't use more than k+1 flights
            vector<int> temp = cost;

            while(size--) {

                auto [city, currCost] = q.front();
                q.pop();

                // Check all flights from current city
                for(auto [nextCity, price] : graph[city]) {

                    int newCost = currCost + price;

                    // If this route is cheaper
                    if(newCost < temp[nextCity]) {

                        // Update cheapest cost
                        temp[nextCity] = newCost;

                        // Add city to queue
                        q.push({nextCity, newCost});
                    }
                }
            }

            // Apply updates after completing this level
            cost = temp;

            // One more flight taken
            stops++;
        }

        // If destination cannot be reached
        if(cost[dst] == INT_MAX)
            return -1;

        return cost[dst];
    }
};