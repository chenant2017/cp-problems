#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, K;
ll term;
vector<ll> ans;

void counter(ll zeros, ll start, vector<ll>& history) {
    if (zeros == 0) {
        term++;

        if (term == N) {
            ans = history;
        }

        return;
    }

    for (ll i = start; i < K; i++) {
        history.push_back(i);
        counter(zeros - 1, i, history);
        history.pop_back();
    }
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0902";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    term = 0;
    
    vector<ll> history;
    for (ll zeros = 0; zeros < 30; zeros++) {
        history.clear();
        counter(zeros, 0, history);
        //cout << term << " term\n";
        if (term >= N) break;
    }

    ll ptr = 0;
    for (ll i = 0; i < K; i++) {
        cout << 1;
        while (ptr < N && ans[ptr] == i) {
            cout << 0;
            ptr++;
        }
    }

    cout << "\n";
	
	return 0;
}