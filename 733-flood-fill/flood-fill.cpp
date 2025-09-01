#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int startColor = image[sr][sc];
        if (startColor == color) return image;  

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;
        image[sr][sc] = color;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    !visited[nx][ny] && image[nx][ny] == startColor) {
                    visited[nx][ny] = true;
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }
        return image;
    }
};
