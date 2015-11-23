/*
ID: <ID HERE>
LANG: C++11
TASK: crypt1
*/

#include <iostream>
#include <fstream>
#include <array>
#include <vector>

using namespace std;

bool validate(int num, array<bool, 10> &digits) {
	for (; num > 0; num /= 10)
		if (!digits[num % 10])
			return false;
	return true;
}

int main() {
	ifstream cin("crypt1.in");
	ofstream cout("crypt1.out");

	int num_digits;
	cin >> num_digits;

	array<bool, 10> digits{};
	vector<int> digit_list(num_digits);

	for (int i = 0; i < num_digits; ++i) {
		cin >> digit_list[i];
		digits[digit_list[i]] = true;
	}

	int count = 0;
	for (auto a : digit_list) {
		for (auto b : digit_list) {
			for (auto c : digit_list) {
				for (auto d : digit_list) {
					for (auto e : digit_list) {
						int top = 100 * a + 10 * b + c;
						int partial_a = top * d;
						int partial_b = top * e;
						int result = partial_a * 10 + partial_b;

						if (partial_a < 1000 && validate(partial_a, digits) &&
							partial_b < 1000 && validate(partial_b, digits) &&
							result < 10000 && validate(result, digits)) {
							count++;
						}
					}
				}
			}
		}
	}

	cout << count << endl;

	return 0;
}
