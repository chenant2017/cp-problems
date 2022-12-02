#include <bits/stdc++.h>
#define f first 
#define s second 
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pdl;

set<ll> visited;

ll N, K;

ll bfs() {
    queue<pdl> q;
    q.push(pll({N, 0}));

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (visited.find(curr.f) != visited.end()) continue;
        if (curr.f < 0 || curr.f > 100000) continue;

        visited.insert(curr.f);

        if (curr.f == K) return curr.s;

        q.push(pll({curr.f * 2, curr.s + 1}));
        q.push(pll({curr.f - 1, curr.s + 1}));
        q.push(pll({curr.f + 1, curr.s + 1}));
    }

    return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "hideseek";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    ll ans;

    if (N >= K) ans = N - K;
    else ans = bfs();

    cout << ans << "\n";
	
	return 0;
}