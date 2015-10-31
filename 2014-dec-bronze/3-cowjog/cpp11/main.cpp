#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream cin("cowjog.in");
	ofstream cout("cowjog.out");
	
	int count;
	cin >> count;
	
	vector<int> speeds(count);
	for (int i = 0, dummy; i < count; i++)
		cin >> dummy >> speeds[i];
	
	// whenever a new slowest cow is found, a new group is found
	// because all cows past this one move faster, and all cows
	// behind this eventually move at this cow's speed or less
	// and so the groups are detached
		
	int groups = 1;
	int slowest = speeds[count - 1];
	for (int i = count - 2; i >= 0; i--) {
		if (speeds[i] <= slowest) {
			groups++;
			slowest = speeds[i];
		}
	}
	
	cout << groups << endl;
}
