/**
ID: <ID HERE>
LANG: C++11
TASK: pprime
*/
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

bool is_prime(int num) {
	int max = (int) sqrt(num);
	for (int i = 2; i <= max; i++)
		if (num % i == 0)
			return false;
	return true;
}

void generate1(set<int> &dest) {
	for (int i = 1; i <= 9; i += 2)
		dest.insert(i);
}
void generate2(set<int> &dest) {
}
void generate3(set<int> &dest) {
	for (int i = 0; i <= 9; i++)
		for (int j = 1; j <= 9; j += 2)
			dest.insert(101 * j + 10 * i);
}
void generate5(set<int> &dest) {
	for (int i = 0; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
			for (int k = 1; k <= 9; k += 2)
				dest.insert(10001 * k + 1010 * j + 100 * i);
}
void generate7(set<int> &dest) {
	for (int i = 0; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
			for (int k = 0; k <= 9; k++)
				for (int l = 1; l <= 9; l += 2)
					dest.insert(1000001 * l + 100010 * k + 10100 * j + 1000 * i);
}

set<int> generate() {
	set<int> palindromes;

	palindromes.insert(11); // 11 is the only even-length prime palindrome

	generate1(palindromes);
	generate3(palindromes);
	generate5(palindromes);
	generate7(palindromes);

	return palindromes;
}

int main() {
	ifstream cin("pprime.in");
	ofstream cout("pprime.out");

	int min, max;
	cin >> min >> max;

	set<int> palindromes = generate();


	set<int> results;
	auto end = palindromes.upper_bound(max);
	for (auto iter = palindromes.lower_bound(min); iter != end; ++iter) {
		if (*iter >= min && *iter <= max && is_prime(*iter))
			results.insert(*iter);
	}

	for (int result : results)
		cout << result << endl;

	return 0;
}
