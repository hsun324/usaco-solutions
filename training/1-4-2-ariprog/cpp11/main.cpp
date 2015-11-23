/*
ID: <ID HERE>
LANG: C++11
TASK: ariprog
*/
#include <fstream>
#include <set>
#include <vector>

using namespace std;

int main() {
	ifstream input("ariprog.in");
	ofstream output("ariprog.out");

	int required_length, bisquare_addend_max;
	input >> required_length >> bisquare_addend_max;

	set<int> unique_bisquares;
	for (int i = 0; i <= bisquare_addend_max; i++)
		for (int j = 0; j <= bisquare_addend_max; j++)
			unique_bisquares.insert(i * i + j * j);

	vector<int> bisquares(unique_bisquares.begin(), unique_bisquares.end());
	int max_bisquare = bisquares.back();

	set<pair<int, int>> results;
	for (int i = 0; i < bisquares.size(); i++) {
		int bisquare = bisquares[i];
		int max_interval = (max_bisquare - bisquare) / (required_length - 1);
		int max_next = bisquare + max_interval;
		for (int j = i + 1; j < bisquares.size() && bisquares[j] <= max_next; j++) {
			int interval = bisquares[j] - bisquare;
			bool found = true;
			for (int k = 2; k < required_length; k++) {
				if (unique_bisquares.find(bisquare + interval * k) == unique_bisquares.end()) {
					found = false;
					break;
				}
			}

			if (found) results.emplace(interval, bisquare);
		}
	}

	if (results.size() == 0) {
		output << "NONE" << endl;
	} else {
		for (auto &result : results)
			output << result.second << " " << result.first << endl;
	}

	return 0;
}
