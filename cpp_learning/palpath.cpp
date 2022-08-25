#include <bits/stdc++.h>
#define MAX 20
using namespace std;

typedef long long ll;
typedef vector<string> vs;

ll N;
vs fields;
unordered_set<string> memo[MAX][MAX];

unordered_set<string> get_paths(ll i, ll j) {
    if (!memo[i][j].empty()) return memo[i][j];
    unordered_set<string> result;

    if (i == 0 && j == 0) {
        result.insert(string() + fields[i][j]);
        return result;
    }

    unordered_set<string> prev;
    if (i > 0) {
        unordered_set<string> paths1 = get_paths(i - 1, j);
        prev.insert(paths1.begin(), paths1.end());
    }
    if (j > 0) {
        unordered_set<string> paths2 = get_paths(i, j - 1);
        prev.insert(paths2.begin(), paths2.end());
    }

    for (auto k: prev) {
        string add = k + fields[i][j];
        result.insert(add);
    }

    memo[i][j] = result;
    return result;
}

bool is_pal(string s) {
    bool result = true;
    for (ll i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            result = false;
            break;
        }
    }
    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "palpath";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        string s;
        cin >> s;
        fields.push_back(s);
    }

    unordered_set<string> paths = get_paths(N - 1, N - 1);

    ll ans = 0;

    for (auto j: paths) {
        if (is_pal(j)) {
            ans++;
        }
    }

    cout << ans << "\n";
	
	return 0;
}