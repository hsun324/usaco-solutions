#include <fstream>
#include <map>

using namespace std;

int main() {
    ifstream cin("milktemp.in");
    ofstream cout("milktemp.out");

    int num_cows, cold, comfortable, hot;
	cin >> num_cows >> cold >> comfortable >> hot;

	int cold_change = comfortable - cold;
	int hot_change = hot - comfortable;

	map<int, int> changes;
	for (int i = 0; i < num_cows; i++) {
		int cold_thresh, hot_thresh;
		cin >> cold_thresh >> hot_thresh;
		
		changes[cold_thresh] += cold_change;
		changes[hot_thresh + 1] += hot_change;
	}

	int current = num_cows * cold;
	int max = current;
	for (const auto &change : changes) {
		current += change.second;
		if (current > max)
			max = current;
	}

    cout << max << endl;

    return 0;
}
