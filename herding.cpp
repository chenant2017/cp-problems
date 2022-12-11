#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

typedef long long ll;

ll N;
ll cows[MAXN];

ll solve_min() {
    ll ptr2 = 0;
    ll max_cows = 0;
    for (ll ptr1 = 0; ptr1 < N; ptr1++) {
        if (cows[ptr1] + N - 1 > cows[N - 1]) break;
        while (ptr2 + 1 < N && cows[ptr2 + 1] - cows[ptr1] < N) {
            ptr2++;
        }
        ll num_cows = ptr2 - ptr1 + 1;
        max_cows = max(max_cows, num_cows);
    }
    return N - max_cows;
}

ll solve_max() {
    ll poss1 = cows[N - 1] - cows[1];
    ll poss2 = cows[N - 2] - cows[0];
    return max(poss1, poss2) + 2 - N;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "herding";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> cows[i];
    }

    sort(cows, cows + N);

    cout << solve_min() << "\n";
    cout << solve_max() << "\n";
	
	return 0;
}