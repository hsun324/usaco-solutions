/*
ID: <ID HERE>
LANG: C++11
TASK: runround
*/
#include <iostream>
#include <fstream>
#include <array>

using namespace std;

bool is_runround(int number) {
	int length = 0;
	array<int, 9> digits;

	int temp = number;
	do {
		digits[length++] = temp % 10;
	} while (temp /= 10);

	for (int i = 0; i < length; i++)
		for (int j = i + 1; j < length; j++)
			if (digits[i] == 0 || digits[i] == digits[j])
				return false;


	array<bool, 9> visited{};
	int k = 0;
	for (int i = 0; i < length; i++, k = (k + digits[length - k - 1]) % length) {
		if (visited[k])
			return false;
		visited[k] = true;
	}
	return k == 0;
}

int main() {
	ifstream cin("runround.in");
	ofstream cout("runround.out");

	int start;
	cin >> start;

	while (!is_runround(++start));
	cout << start << endl;

	return 0;
}
