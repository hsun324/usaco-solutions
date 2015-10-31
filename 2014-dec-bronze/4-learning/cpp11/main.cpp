#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	ifstream cin("learning.in");
	ofstream cout("learning.out");
	
	int count, smin, smax;
	cin >> count >> smin >> smax;
	
	vector<pair<int, bool>> data(count);
	
	char type[3];
	for (int i = 0; i < count; i++) {
		cin >> type >> data[i].first;
		data[i].second = type[0] == 'S';
	}
	
	sort(data.begin(), data.end());
	
	vector<pair<int, int>> ranges(count);
	for (int i = 0; i < count - 1; i++) {
		int half_interval = (data[i + 1].first - data[i].first) / 2;
		int current_end = data[i].first + half_interval;
		int next_begin = data[i + 1].first - half_interval;
		
		ranges[i].second = current_end - (current_end == next_begin && !data[i].second);
		ranges[i + 1].first = next_begin + (current_end == next_begin && data[i].second);
	}
	ranges[count - 1].second = 1000000000;
	
	int result = 0;
	for (int i = 0; i < count; i++)
		if (data[i].second)
			result += max(0, min(ranges[i].second, smax) - max(ranges[i].first, smin) + 1);
	
	cout << result << endl;
}
