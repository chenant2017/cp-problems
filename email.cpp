//Silver 2021 February #3

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll T, N, M, K;

bool solve() {
    cin >> N >> M >> K;
    vector<bool> skipped (N, false);
    vector<bool> filed (N, false);
    vector<bool> in_window(N, false);
    vector<vector<ll>> emails_for (M + 1);
    vector<ll> folder_for (N);

    for (ll i = 0; i < N; i++) {
        ll f;
        cin >> f;
        folder_for[i] = f;
        emails_for[f].push_back(i);
    }

    ll estart = 0, eend = 0;
    ll size = 0;
    for (ll ftop = 1; ftop <= N - K + 1; ftop++) {
        ll fbottom = ftop + K - 1;
        //cout << ftop << " " << fbottom << "\n";
        while (eend < N && size < K) {
            if (ftop <= folder_for[eend] && 
                folder_for[eend] <= fbottom) {
                filed[eend] = true;
            }
            else {
                in_window[eend] = true;
                size++;
            }
            eend++;
        }

        while (estart < N && !in_window[estart]) estart++;

        //cout << estart << " " << eend << "\n";

        while (eend < emails_for[ftop].back()) {
            if (ftop <= folder_for[eend] && 
                folder_for[eend] <= fbottom) {
                filed[eend] = true;
            }
            else {
                in_window[eend] = true;
                in_window[estart] = false;
                skipped[estart] = true;
                while (estart < N && !in_window[estart]) estart++;
            }
            eend++;
        }

        if (eend == N) {
            while (size < K) {
                while (estart >= 0 && !skipped[estart]) {
                    estart--;
                }
                if (estart == -1) break;
                skipped[estart] = false;
                if (ftop <= folder_for[estart] && 
                    folder_for[estart] <= fbottom) {
                    filed[estart] = true;
                }
                else {
                    in_window[estart] = true;
                    size++;
                }
            }
        }
        if (estart == -1) return false;
    }
    return true;
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	string fname = "email";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> T;

    for (ll t = 0; t < T; t++) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
	
	return 0;
}