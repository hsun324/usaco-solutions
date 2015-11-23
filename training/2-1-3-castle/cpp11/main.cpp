/*
ID: <ID HERE>
LANG: C++11
TASK: castle
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int xOffsetLookup[4] = { 0, 1, 0, -1 };
int yOffsetLookup[4] = { -1, 0, 1, 0 };

char nameLookup[4] = { 'W', 'N', 'E', 'S' };

int find_room(int starting_x, int starting_y, const vector<vector<int>> &cell_layouts, vector<vector<int>> &cell_ids, int room_id) {
	int result = 0;

	queue<pair<int, int>> waiting;
	waiting.emplace(starting_x, starting_y);

	while (!waiting.empty()) {
		auto current = waiting.front();
		waiting.pop();

		auto &cell_id = cell_ids[current.first][current.second];
		if (cell_id < 0) {
			cell_id = room_id;
			++result;

			for (int i = 0; i < 4; i++)
				if ((cell_layouts[current.first][current.second] & (1 << i)) == 0)
					waiting.emplace(current.first + xOffsetLookup[i], current.second + yOffsetLookup[i]);
		}
	}

	return result;
}

int main() {
	ifstream cin("castle.in");
	ofstream cout("castle.out");

	int width, height;
	cin >> width >> height;

	vector<vector<int>> layouts(height, vector<int>(width));

	for (int i = height - 1; i >= 0; i--)
		for (auto &cell : layouts[i])
			cin >> cell;

	vector<vector<int>> cell_room_ids(height, vector<int>(width, -1));
	vector<int> room_sizes;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (cell_room_ids[i][j] < 0) {
				auto room_size = find_room(i, j, layouts, cell_room_ids, room_sizes.size());
				room_sizes.push_back(room_size);
			}
		}
	}

	int max_room_size = *max_element(room_sizes.begin(), room_sizes.end());
	struct {
		int size, x, y, dir;
	} max{};

	for (int y = 0; y < width; y++) {
		for (int x = 0; x < height; x++) {
			int source_cell_room_id = cell_room_ids[x][y];

			for (int dir = 1; dir <= 2; dir++) {
				int dest_x = x + xOffsetLookup[dir];
				int dest_y = y + yOffsetLookup[dir];

				if (dest_x >= 0 && dest_x < height &&
					dest_y >= 0 && dest_y < width) {
					int dest_cell_room_id = cell_room_ids[dest_x][dest_y];

					if (source_cell_room_id != dest_cell_room_id) {
						int size = room_sizes[source_cell_room_id] +
							room_sizes[dest_cell_room_id];

						if (size > max.size) {
							max.size = size;
							max.x = x;
							max.y = y;
							max.dir = dir;
						}
					}
				}
			}
		}
	}

	cout << room_sizes.size() << endl;
	cout << max_room_size << endl;
	cout << max.size << endl;
	cout << (height - max.x) << ' ' << (max.y + 1) << ' ' << nameLookup[max.dir] << endl;

	return 0;
}
