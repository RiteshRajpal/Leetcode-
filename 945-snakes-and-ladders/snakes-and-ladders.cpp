class Solution {
public:

    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();

        // Queue stores the current square
        queue<int> q;

        // visited[i] tells whether square i is already visited
        vector<bool> visited(n * n + 1, false);

        // Start from square 1
        q.push(1);
        visited[1] = true;

        // Number of dice rolls
        int moves = 0;

        while(!q.empty()) {

            // Number of squares at the current BFS level
            int size = q.size();

            // Process all positions reachable in 'moves' rolls
            while(size--) {

                int curr = q.front();
                q.pop();

                // If we reached the last square
                if(curr == n * n)
                    return moves;

                // Try all possible dice values
                for(int dice = 1; dice <= 6; dice++) {

                    int next = curr + dice;

                    // Cannot go beyond the last square
                    if(next > n * n)
                        break;

                    // Convert square number into row and column

                    int row = n - 1 - (next - 1) / n;
                    int col = (next - 1) % n;

                    // Every alternate row is reversed
                    if((n - row) % 2 == 0)
                        col = n - 1 - col;

                    // If there is a snake or ladder,
                    // move to its destination
                    if(board[row][col] != -1)
                        next = board[row][col];

                    // If this square is not visited
                    if(!visited[next]) {

                        // Mark it visited
                        visited[next] = true;

                        // Add it to the queue
                        q.push(next);
                    }
                }
            }

            // One complete BFS level = one dice roll
            moves++;
        }

        // If the last square cannot be reached
        return -1;
    }
};