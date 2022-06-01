#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;

int main() {
	ll low = 1;
	ll high = 1000001;
	
	while (high - low > 1) {
		ll mid = (high + low) / 2;
		cout << mid << "\n" << flush;
		string result;
		cin >> result;
		if (result[0] == '<') {
			high = mid;
		}
		else {
			low = mid;
		}
	}
	
	cout << "! " << low << "\n" << flush;
	
	return 0;
}