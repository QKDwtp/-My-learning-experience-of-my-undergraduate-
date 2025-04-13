#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

string inverse(const string& n) {
	vector<char>list;
	int x = n.size();
	for (int i = 0; i < x; i++) {
		list.push_back(n[i]);
	}
	reverse(list.begin(), list.end());
	return string(list.begin(), list.end());
}
int main() {
	string n;
	cin >> n;
	cout << inverse(n) << endl;
	return 0;
}
