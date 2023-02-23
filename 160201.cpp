#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

typedef long long ll;

ll N;
ll c[MAX];
ll zeros[MAX];

ll get_zeros(ll i) {
	ll result = 0;
	ll ptr = i;

	while (c[(ptr - 1 + N) % N] == 0) {
		ptr = (ptr - 1 + N) % N;
		result++;
	}

	return result;
}

ll sum_sq(ll a, ll b) {
	ll result = 0;
	for (ll i = a; i <= b; i++) {
		result += i * i;
	}

	return result;
}

ll solve(ll start) {
	rotate(c, c + start, c + N);

	ll result = sum_sq(0, c[start] - 1);
	ll ptr = c[start] - 1;

	for (ll i = 1; i < N; i++) {
		
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "160201";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
		cin >> c[i];
	}

	for (ll i = 0; i < N; i++) {
		zeros[i] = get_zeros(i);
    }

	ll start = 0;
	
	for (ll i = 0; i < N; i++) {
        if (c[i] > c[start] && zeros[i] > zeros[start]) {
			start = i;
		}
    }
	
	return 0;
}