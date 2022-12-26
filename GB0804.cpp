#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0804";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    set<ll> all;
    for (ll i = 1; i <= 2 * N; i++) {
        all.insert(i);
    }

    vector<ll> elsie;
    for (ll i = 1; i <= N; i++) {
        ll e; cin >> e;
        elsie.push_back(e);
        all.erase(e);
    }

    vector<ll> bessie = vector<ll>(all.begin(), all.end());
    sort(bessie.rbegin(), bessie.rend());
    sort(bessie.begin(), bessie.begin() + N / 2, greater<ll>());
    sort(bessie.begin() + N / 2, bessie.end());
    sort(elsie.begin(), elsie.begin() + N / 2, greater<ll>());
    sort(elsie.begin() + N / 2, elsie.end());


    ll ans = 0;

    ll ptr = 0;
    for (ll i = 0; i < N / 2; i++) { //upper
        while (ptr < N / 2 && elsie[ptr] > bessie[i]) {
            ptr++;
        }
        if (ptr < N / 2) {
            //cout << elsie[ptr] << " " << bessie[i] << "\n";
            ans++;
            ptr++;
        }
        else break;
    }

    ptr = N / 2;
    for (ll i = N / 2; i < N; i++) {
        while (ptr < N && elsie[ptr] < bessie[i]) {
            ptr++;
        }
        if (ptr < N) {
            //cout << elsie[ptr] << " " << bessie[i] << "\n";
            ptr++;
            ans++;
        }
        else break;
    }

    cout << ans << "\n";
	
	return 0;
}