class Solution {
private:
	void dfs(vector<vector<char>>& grid, int r, int c) {
		int nr = grid.size();
		int nc = grid[0].size();

		grid[r][c] = '0';
		if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c);
		if (r + 1 < nr && grid[r + 1][c] == '1') dfs(grid, r + 1, c);
		if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
		if (c + 1 < nc && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
	}

public:
	int numIslands(vector<vector<char>>& grid) {
		int nr = grid.size();
		if (!nr) return 0;
		int nc = grid[0].size();

		int num_islands = 0;
		for (int r = 0; r < nr; ++r) {
			for (int c = 0; c < nc; ++c) {
				if (grid[r][c] == '1') {
					++num_islands;
					dfs(grid, r, c);
				}
			}
		}

		return num_islands;
	}
};
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int nr = grid.size();
		if (!nr) return 0;
		int nc = grid[0].size();

		int num_islands = 0;
		for (int r = 0; r < nr; ++r) {
			for (int c = 0; c < nc; ++c) {
				if (grid[r][c] == '1') {
					++num_islands;
					grid[r][c] = '0'; // mark as visited
					queue<pair<int, int>> nei***ors;
					nei***ors.push({ r, c });
					while (!nei***ors.empty()) {
						auto rc = nei***ors.front();
						nei***ors.pop();
						int row = rc.first, col = rc.second;
						if (row - 1 >= 0 && grid[row - 1][col] == '1') {
							nei***ors.push({ row - 1, col }); grid[row - 1][col] = '0';
						}
						if (row + 1 < nr && grid[row + 1][col] == '1') {
							nei***ors.push({ row + 1, col }); grid[row + 1][col] = '0';
						}
						if (col - 1 >= 0 && grid[row][col - 1] == '1') {
							nei***ors.push({ row, col - 1 }); grid[row][col - 1] = '0';
						}
						if (col + 1 < nc && grid[row][col + 1] == '1') {
							nei***ors.push({ row, col + 1 }); grid[row][col + 1] = '0';
						}
					}
				}
			}
		}

		return num_islands;
	}
};
