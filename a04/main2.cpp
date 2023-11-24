#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 9; i >= 0; i--) {
		int wari = (1 << i);
		cout << (n / wari) % 2;
	}
	cout << endl;
	return 0;
}