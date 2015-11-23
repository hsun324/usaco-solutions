/*
ID: <ID HERE>
LANG: C++11
TASK: friday
*/

#include <iostream>
#include <fstream>

using namespace std;

int days_in_month(int month, int year) {
	static const int lookup[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return lookup[month] + (month == 1 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int main() {
	ifstream cin("friday.in");
	ofstream cout("friday.out");

	int years;
	cin >> years;

	int max = 1900 + years;
	int current_start = 0;

	int dow[7] = {};
	for (int year = 1900, max = 1900 + years; year < max; year++) {
		for (int month = 0; month < 12; month++) {
			dow[current_start]++;

			current_start += days_in_month(month, year);
			current_start %= 7;
		}
	}

	cout << dow[0] << ' ' << dow[1] << ' ' << dow[2] << ' ' << dow[3] << ' '
		<< dow[4] << ' ' << dow[5] << ' ' << dow[6] << endl;

	return 0;
}
