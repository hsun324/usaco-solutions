#include <fstream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

int main() {
	ifstream cin("crosswords.in");
	ofstream cout("crosswords.out");
	
	int height, width;
	cin >> height >> width;
	
	// false: could potentially start a horiz/vert clue
	// true: precluded due to space constraint
	vector<vector<bool>> horizontal_grid(height, vector<bool>(width));
	vector<vector<bool>> vertical_grid(height, vector<bool>(width));
	
	// cells too close to the boundaries cannot start a clue
	for (int y = 0; y < height; y++)
		for (int x = width - 2; x < width; x++)
			horizontal_grid[y][x] = true;
	for (int y = height - 2; y < height; y++)
		for (int x = 0; x < width; x++)
			vertical_grid[y][x] = true;
	
	for (int y = 0; y < height; y++) {
		string line;
		cin >> line;
		
		for (int x = 0; x < width; x++) {
			if (line[x] == '#') {
				// cells horizontally or vertically within 2 of a '#' cannot start a clue
				for (int i = 0; i <= 2; i++) {
					if (y - i >= 0) vertical_grid[y - i][x] = true;
					if (x - i >= 0) horizontal_grid[y][x - i] = true;
				}
			}
		}
	}
	
	set<pair<int, int>> coords;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (!horizontal_grid[y][x]) {
				coords.emplace(y + 1, x + 1);
				// skip continuous clues
				for (; x < width && !horizontal_grid[y][x]; x++);
			}
		}
	}
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			if (!vertical_grid[y][x]) {
				coords.emplace(y + 1, x + 1);
				// skip continuous clues
				for (; y < height && !vertical_grid[y][x]; y++);
			}
		}
	}
	
	
	cout << coords.size() << endl;
	for (auto &coord : coords)
		cout << coord.first << ' ' << coord.second << endl;
}
