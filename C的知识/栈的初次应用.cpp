#include <iostream>
#include <vector>
#include <string>
#include<stack>
using namespace std;


int main() {
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		stack<int>stack;
		string command;
		for (int i = 0; i < n; i++) {
			cin >> command;
			if (command == "push") {
				int x;
				cin >> x;
				stack.push(x);
			} else if (command == "pop") {
				stack.pop();
			} else if (command == "query") {
				stack.top();
			} else if (command == "size") {
				stack.size();
			}
		}
	}
	return 0;
}



/*

*/
