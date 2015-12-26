#include <fstream>
#include <iostream>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <algorithm>

using namespace std;

int main() {
	ifstream fin("bcount.in");
	ofstream fout("bcount.out");

	int num_cows, num_queries;
	fin >> num_cows >> num_queries;

	vector<array<int, 3>> totals(num_cows + 1);
	for (int i = 0; i < num_cows; i++) {
		int cow;
		fin >> cow;

		totals[i + 1] = totals[i];
		totals[i + 1][cow - 1]++;
	}

	for (int i = 0; i < num_queries; i++) {
		int a, b;
		fin >> a >> b;

		fout << (totals[b][0] - totals[a - 1][0]) << ' '
			<< (totals[b][1] - totals[a - 1][1]) << ' '
			<< (totals[b][2] - totals[a - 1][2]) << endl;
	}
}
