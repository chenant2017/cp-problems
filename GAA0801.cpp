#include <bits/stdc++.h>
#define MAXN 100010
#define f first 
#define s second

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll L, N;
pll turns[MAXN];
bool visited[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0801";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> L >> N;

    priority_queue<pll, vector<pll>, greater<pll>> pq;

    turns[0] = {0, 1};

    for (ll i = 1; i <= N; i++) {
        cin >> turns[i].f >> turns[i].s; // loc, speed
    }

    sort(turns, turns + N + 1);

    for (ll i = 0; i <= N; i++) {
        pq.push({turns[i].s, i});
    }

    while (!pq.empty()) {
        auto c = pq.top().s;
        pq.pop();

        if (visited[c]) continue;
        visited[c] = true;

        if (c - 1 >= 0) {
            ll s2 = turns[c].s + turns[c].f - turns[c - 1].f;
            if (turns[c - 1].s > s2) {
                turns[c - 1].s = s2;
                pq.push({turns[c - 1].s, c - 1});
            }
        }
        if (c + 1 <= N) {
            ll s2 = turns[c].s + turns[c + 1].f - turns[c].f;
            if (turns[c + 1].s > s2) {
                turns[c + 1].s = s2;
                pq.push({turns[c + 1].s, c + 1});
            }
        }
    }

    ll ans = 1;

    for (ll i = 0; i < N; i++) {
        ans = max(ans, (turns[i].s + turns[i + 1].s + 
                        turns[i + 1].f - turns[i].f) / 2);
    }

    ans = max(ans, turns[N].s + L - turns[N].f);

    cout << ans << "\n";
    
	return 0;
}