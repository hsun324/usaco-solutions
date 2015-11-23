/**
ID: <ID HERE>
LANG: C++11
TASK: frac1
*/
#include <fstream>
#include <vector>

using namespace std;

void generate(int right_numerator, int right_denominator, int left_numerator, int left_denominator, int limit, vector<pair<int, int>> &result) {
	int sum_numerator = right_numerator + left_numerator;
	int sum_denominator = right_denominator + left_denominator;

	if (sum_denominator > limit) return;

	generate(right_numerator, right_denominator, sum_numerator, sum_denominator, limit, result);
	result.emplace_back(sum_numerator, sum_denominator);
	generate(sum_numerator, sum_denominator, left_numerator, left_denominator, limit, result);
}

int main() {
    ifstream cin("frac1.in");
    ofstream cout("frac1.out");

	int limit;
	cin >> limit;

	vector<pair<int, int>> fractions;
	fractions.emplace_back(0, 1);
	generate(0, 1, 1, 1, limit, fractions);
	fractions.emplace_back(1, 1);

	for (auto &fraction : fractions)
		cout << fraction.first << "/" << fraction.second << endl;

    return 0;
}
