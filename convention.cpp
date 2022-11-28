//2018 December Silver #1

#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

typedef long long ll;

ll N, M, C;
ll t[MAXN];

bool works(ll max_wait) {
    ll buses = 1;
    ll start = 0;
    for (ll i = 1; i < N; i++) {
        if (t[i] - t[start] > max_wait || i - start + 1 > C) {
            buses++;
            start = i;
        }
    }
    return buses <= M;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "convention";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M >> C;
    for (ll i = 0; i < N; i++) {
        cin >> t[i];
    }

    sort(t, t + N);

    ll max_wait = t[N - 1];
    //cout << max_wait << "\n";
    ll jump = t[N - 1] / 2;

    while (jump > 0) {
        //cout << max_wait - jump << "\n";
        if (works(max_wait - jump)) {
            //cout << "worked\n";
            max_wait -= jump;
        }
        else {
            //cout << "didn't work\n";
            jump /= 2;
        }
    }

    cout << max_wait << "\n";
	
	return 0;
}