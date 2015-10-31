#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair<int, int> coord;

int dist(const coord a, const coord b) {
	return abs(b.first - a.first) + abs(b.second - a.second);
}

int main() {
	ifstream cin("marathon.in");
	ofstream cout("marathon.out");

	int num_checkpoints;
	cin >> num_checkpoints;

	vector<coord> checkpoints(num_checkpoints);
	for (auto &checkpoint : checkpoints)
		cin >> checkpoint.first >> checkpoint.second;

	int max = 0;
	int prev_distance = dist(checkpoints[0], checkpoints[1]);
	int total_distance = prev_distance;

	for (int i = 1; i < num_checkpoints - 1; i++) {
		int next_distance = dist(checkpoints[i], checkpoints[i + 1]),
		    skip_distance = dist(checkpoints[i - 1], checkpoints[i + 1]);
			
		int skipped = prev_distance + next_distance - skip_distance;
		if (skipped > max)
			max = skipped;
		
		total_distance += next_distance;
		prev_distance = next_distance;
	};

	cout << (total_distance - max) << endl;
}
