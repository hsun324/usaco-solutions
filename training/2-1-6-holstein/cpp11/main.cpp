/*
ID: <ID HERE>
LANG: C++11
TASK: holstein
*/
#include <fstream>
#include <array>
#include <utility>

using namespace std;

bool all_gte(const array<int, 25> &right, const array<int, 25> &left, int length) {
	for (int i = 0; i < length; i++)
		if (right[i] < left[i])
			return false;
	return true;
}

struct search_data {
	int num_requirements;
	array<int, 25> requirements;

	int num_feeds;
	array<array<int, 25>, 15> feeds;
};
pair<int, int> search(const search_data &data, const array<int, 25> &current, int current_count, int current_id, int current_index) {
	if (all_gte(current, data.requirements, data.num_requirements))
		return {current_count, current_id};
	if (current_index == data.num_feeds)
		return {16, 1 << 16};

	auto next = current;
	for (int i = 0; i < data.num_requirements; i++)
		next[i] += data.feeds[current_index][i];

	return min(search(data, current, current_count, current_id, current_index + 1),
				search(data, next, current_count + 1, current_id + (1 << current_index), current_index + 1));
}

pair<int, int> search(const search_data &data) {
	return search(data, {}, 0, 0, 0);
}

int main() {
	ifstream cin("holstein.in");
	ofstream cout("holstein.out");

	search_data data;
	cin >> data.num_requirements;
	for (int i = 0; i < data.num_requirements; i++)
		cin >> data.requirements[i];

	cin >> data.num_feeds;
	for (int i = 0; i < data.num_feeds; i++)
		for (int j = 0; j < data.num_requirements; j++)
			cin >> data.feeds[i][j];

	auto result = search(data);

	cout << result.first;
	for (int i = 0; i < data.num_feeds; i++)
		if ((result.second & (1 << i)) != 0)
			cout << ' ' << (i + 1);
	cout << endl;

	return 0;
}
