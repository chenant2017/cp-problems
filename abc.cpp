#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> tll;

ll T;
ll N;
vector<ll> v;
set<vector<ll>> ans;

bool works(ll a, ll b, ll c) {
    if (a <= 0 || b <= 0 || c <= 0) return false;

    set<ll> combos = {a, b, c, a + b, b + c, a + c, a + b + c};

    for (auto i: v) {
        if (combos.find(i) == combos.end()) return false;
    }
    return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "abc";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> T;
    
    while (T--) {
        cin >> N;
        v.resize(N);
        ans.clear();
        for (ll i = 0; i < N; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        for (ll i = 0; i < v.size() - 1; i++) {
            for (ll j = i + 1; j < v.size(); j++) {
                //case 0: a, b
                ll a = v[i], b = v[j];
                for (ll k = 0; k < v.size(); k++) {
                    if (k == i || k == j) continue;
                    
                    ll c = v[k];

                    if (works(a, b, c)) {
                        vector<ll> triplet = {a, b, c};
                        sort(triplet.begin(), triplet.end());
                        ans.insert(triplet);
                    }

                }

                ll diff = v[j] - v[i];

                //case 1: a, a + b
                a = v[i]; b = diff;

                for (ll k = 0; k < v.size(); k++) {
                    if (k == i || k == j) continue;
                    vector<ll> cs {v[k], v[k] - a, v[k] - b, v[k] - v[j]};

                    for (auto c: cs) {
                        if (works(a, b, c)) {
                            vector<ll> triplet = {a, b, c};
                            sort(triplet.begin(), triplet.end());
                            ans.insert(triplet);
                        }
                    }
                }

                //case 2: b + c, a + b + c
                a = diff;

                for (ll k = 0; k < v.size(); k++) {
                    if (k == i || k == j) continue;
                    vector<ll> bs {v[k], v[k] - a};

                    for (auto b: bs) {
                        ll c = v[j] - (a + b);
                        if (works(a, b, c)) {
                            vector<ll> triplet = {a, b, c};
                            sort(triplet.begin(), triplet.end());
                            ans.insert(triplet);
                        }
                    }
                }
            }
        }
        cout << ans.size() << "\n";
    }
	
	return 0;
}