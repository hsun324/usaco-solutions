#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

vector<int> find_costs(int source, int cost, const vector<vector<int>> &connections) {
	vector<int> distances(connections.size(), -1);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
	queue.emplace(0, source);
	while (!queue.empty()) {
		auto current = queue.top();
		queue.pop();

		if (distances[current.second] == -1) {
			distances[current.second] = current.first;
			for (auto connected : connections[current.second])
				queue.emplace(current.first + cost, connected);
		}
	}

	return distances;
}

int main() {
	ifstream cin("piggyback.in");
	ofstream cout("piggyback.out");

	int bessie_usage, elsie_usage, piggyback_usage, num_fields, num_conns;
	cin >> bessie_usage >> elsie_usage >> piggyback_usage >> num_fields >> num_conns;

	vector<vector<int>> connections(num_fields);
	for (int i = 0; i < num_conns; i++) {
		int field_a, field_b;
		cin >> field_a >> field_b;

		connections[field_a - 1].push_back(field_b - 1);
		connections[field_b - 1].push_back(field_a - 1);
	}

	auto pback_costs = find_costs(num_fields - 1, piggyback_usage, connections);
	auto bessie_costs = find_costs(0, bessie_usage, connections);
	auto elsie_costs = find_costs(1, elsie_usage, connections);

	int min = 1 << 30;
	for (int i = 0; i < num_fields; i++)
		cost = min(cost, bessie_costs[i] + elsie_costs[i] + pback_costs[i]);

	cout << min << endl;
}

