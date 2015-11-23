/**
ID: hsun324
LANG: C++11
TASK: sprime
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(int num) {
	int max = (int) sqrt(num);
	for (int i = 2; i <= max; i++)
		if (num % i == 0)
			return false;
	return true;
}

int main() {
	ifstream cin("sprime.in");
	ofstream cout("sprime.out");

	int length;
	cin >> length;

	vector<int> current_set{};
	vector<int> next_set{2, 3, 5, 7};

	for (int i = 1; i < length; i++) {
		current_set.clear();
		current_set.swap(next_set);

		for (int base : current_set)
			for (int j = 1; j <= 9; j += 2)
				if (is_prime(base * 10 + j))
					next_set.push_back(base * 10 + j);
	}

	for (int result : next_set)
		cout << result << endl;

	return 0;
}
