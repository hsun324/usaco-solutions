/*
ID: <ID HERE>
LANG: C++11
TASK: barn1
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

int main() {
	ifstream cin("barn1.in");
	ofstream cout("barn1.out");

	int max_boards, num_stalls, num_cows;
	cin >> max_boards >> num_stalls >> num_cows;

	vector<int> stalls(num_cows);
	for (int i = 0; i < num_cows; i++)
		cin >> stalls[i];
	sort(stalls.begin(), stalls.end());

	vector<int> max_gaps(max_boards - 1);
	for (int i = 0; i < stalls.size() - 1; i++) {
		int gap = stalls[i + 1] - stalls[i] - 1;
		auto iter = lower_bound(max_gaps.begin(), max_gaps.end(), gap, greater<int>());

		if (iter != max_gaps.end()) {
			copy_backward(iter, max_gaps.end() - 1, max_gaps.end());
			*iter = gap;
		}
	}

	cout << (stalls.back() - stalls.front() + 1 - accumulate(max_gaps.begin(), max_gaps.end(), 0)) << endl;

	return 0;
}
