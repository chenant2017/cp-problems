#include <bits/stdc++.h>
#define MAXN 100010
#define MAXA 1000010
using namespace std;

typedef long long ll;

ll N;
ll moves[MAXN];
ll ans[MAXA];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "p3";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    ll rows = 0;
    for (ll i = 0; i < N; i++) {
        cin >> moves[i];
        rows = max(rows, moves[i]);
    }

    for (ll i = 0; i < N - 1; i++) {
        ans[0]++;
        ans[1]--;
        if (moves[i] < moves[i + 1]) {
            ans[rows - (moves[i] - 1)]++;
            ans[rows]--;
        }
        else {
            ans[1]++;
            ans[moves[i]]--;
        }
    }

    for (ll i = 0; i < rows; i++) {
        cout << ans[i] << "\n";
    }
	
	return 0;
}