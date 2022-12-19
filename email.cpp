#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll T, M, N, K;
ll e1, e2, f1, f2;
set<ll> window;
bool hit_bottom;
vector<ll> emails;
vector<ll> lasts;
vector<bool> filed;

void expand() {
    while (window.size() < K) {
        cout << window.size() << "\n";
        cout << e1 << " " << e2 << "\n";
        if (hit_bottom) {
            while (e1 >= 0) {
                if (f1 <= emails[e1] && emails[e1] <= f2) {
                    filed[e1] = true;
                    e1 = *window.begin();
                }
                if (!filed[e1]) {
                    window.insert(e1);
                    break;
                }
                e1--;
            }
            if (e1 == -1) {
                break;
            }
        }
        else {
            while (e2 < N && filed[e2]) {
                if (f1 <= emails[e2] && emails[e2] <= f2) {
                    filed[e2] = true;
                }
                if (!filed[e2]) {
                    window.insert(e2);
                    break;
                }
                e2++;
            }
            if (e2 == N) {
                hit_bottom = true;
                e2 = *window.rbegin();
            }
        }
    }
}

void scroll() {
    if (hit_bottom) return;
    window.erase(e1);
    expand();
}

bool solve() {
    cin >> M >> N >> K;
    hit_bottom = false;
    emails = vector<ll>(N, 0);
    lasts = vector<ll>(M, -1); // COULD BE -1
    filed = vector<bool>(N, false);
    window.clear();
    e1 = 0;
    e2 = 0;
    f1 = 1;
    f2 = K;

    for (ll i = 0; i < N; i++) {
        ll e; cin >> e; e--;
        emails[i] = e;
        lasts[e] = i;
    }

    expand();

    return false;

    while (f1 <= N - K + 1) {
        set<ll> new_window;
        for (auto i: window) {
            if (f1 <= emails[i] && emails[i] <= f2) {
                filed[i] = true;
            }
            else {
                new_window.insert(i);
            }
        }
        window = new_window;
        expand();

        if (e1 == -1) break;

        while (e2 < lasts[f1]) {
            scroll();       
        }
        f1++;
        f2++;
    }

    bool result = true;
    for (auto i: filed) {
        if (!i) result = false;
    }
    return result;
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	string fname = "email";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> T;

    for (ll t = 0; t < T; t++) {
        cout << t << "\n";
        bool ans = solve();
        if (ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
	
	return 0;
}