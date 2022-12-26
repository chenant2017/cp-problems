#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, K;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0803";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    ll tcorrect = N;
    ll fcorrect = N;
    ll halfcorrect1 = N; // N / 2 true
    ll halfcorrect2 = N; // N / 2 + 1 true

    for (ll i = 0; i < K; i++) {
        ll t;
        cin >> t;

        tcorrect = min(tcorrect, t);
        fcorrect = min(fcorrect, N - t);
        if (N % 2 == 0) {
            halfcorrect1 = min(halfcorrect1, abs(t - (N / 2)));
            halfcorrect2 = halfcorrect1;
        }
        else {
            halfcorrect1 = min(halfcorrect1, abs(t - (N / 2 + 1)));
            halfcorrect2 = min(halfcorrect2, abs(t - (N / 2 - 1)));
        }
        
    }

    vector<ll> v = {tcorrect, fcorrect, halfcorrect1, halfcorrect2};

    cout << *max_element(v.begin(), v.end()) << "\n";
	
	return 0;
}