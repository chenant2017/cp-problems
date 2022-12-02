#include <bits/stdc++.h>
#define MAXN 110
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pdl;

ll N;
ll dists[MAXN][MAXN];
bool visited[MAXN] = {false};


ll prims() {
    ll result = 0;

    priority_queue<pdl, vector<pdl>, greater<pdl>> q;
    q.push(pdl({0, 0}));

    while (!q.empty()) {
        auto curr = q.top();
        q.pop();

        if (visited[curr.s]) continue;
        visited[curr.s] = true;

        result += curr.f;

        for (ll i = 0; i < N; i++) {
            if (!visited[i]) {
                q.push(pll({dists[curr.s][i], i}));
            }
        }
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "pavement";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            cin >> dists[i][j];
        }
    }
	
    ll ans = prims();
	
    cout << ans << "\n";

	return 0;
}