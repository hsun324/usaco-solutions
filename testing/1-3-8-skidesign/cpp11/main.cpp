/*
ID: <ID HERE>
LANG: C++11
TASK: skidesign
*/
#include <algorithm>
#include <array>
#include <cmath>
#include <fstream>
#include <limits>

using namespace std;

int main() {
	ifstream cin("skidesign.in");
	ofstream cout("skidesign.out");

	int size;
	cin >> size;

	vector<int> hills(size);
	for (auto &hill : hills) cin >> hill;

	int min_hill = *min_element(hills.begin(), hills.end()),
		max_hill = *max_element(hills.begin(), hills.end()) - 17;

	int min_sum = numeric_limits<int>::max();
	for (int low = min_hill; low <= max_hill; low++) {
		int sum = 0;
		for (auto &hill : hills)
			sum += pow(max(0, max(low - hill, hill - low - 17)), 2);
		min_sum = min(sum, min_sum);
	}

	cout << min_sum << endl;

	return 0;
}
