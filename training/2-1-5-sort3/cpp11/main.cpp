/*
ID: <ID HERE>
LANG: C++11
TASK: sort3
*/
#include <fstream>
#include <vector>
#include <array>

using namespace std;

int main() {
	ifstream cin("sort3.in");
	ofstream cout("sort3.out");

	int length;
	cin >> length;

	vector<int> values(length);
	for (auto &value : values) {
		int input;
		cin >> input;

		value = input - 1;
	}

	array<int, 3> counts{};
	for (auto value : values) ++counts[value];

	vector<int> goal(length);
	for (int i = 0, k = 0; i < 3; i++)
		for (int j = 0; j < counts[i]; j++, k++)
			goal[k] = i;

	array<array<int, 3>, 3> move_counts{};
	for (int i = 0; i < length; i++)
		++move_counts[values[i]][goal[i]];

	cout << min(move_counts[0][1], move_counts[1][0]) +
			min(move_counts[0][2], move_counts[2][0]) +
			min(move_counts[1][2], move_counts[2][1]) +
			2 * (max(move_counts[0][1], move_counts[1][0]) -
				min(move_counts[0][1], move_counts[1][0])) << endl;

	return 0;
}
