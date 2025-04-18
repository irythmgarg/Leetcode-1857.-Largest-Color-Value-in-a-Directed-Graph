class Solution {
public:
    // Helper function to check if a cell is within the grid bounds
    bool isok(int i, int j, int m, int n, vector<vector<int>>& grid) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    // Main function to calculate the highest peak grid
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Queue to perform BFS. Stores {height, {i, j}}
        queue<pair<int, pair<int, int>>> q;

        // Set to track visited cells
        set<pair<int, int>> visited;

        // Step 1: Add all water cells (value 1) as starting points in BFS
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0; // Water cells start at height 0
                    q.push({0, {i, j}});
                    visited.insert({i, j});
                }
            }
        }

        // Step 2: Multi-source BFS from all water cells
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto top = q.front();
                q.pop();

                int i = top.second.first;
                int j = top.second.second;

                // Directions: Down, Right, Up, Left
                vector<pair<int, int>> dire = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

                for (int p = 0; p < 4; p++) {
                    int u = i + dire[p].first;
                    int v = j + dire[p].second;

                    // If neighbor is in bounds and unvisited, update height and push into queue
                    if (isok(u, v, m, n, grid) && visited.find({u, v}) == visited.end()) {
                        grid[u][v] = top.first + 1;
                        q.push({top.first + 1, {u, v}});
                        visited.insert({u, v});
                    }
                }
            }
        }

        // Step 3: Return the final height grid
        return grid;
    }
};
