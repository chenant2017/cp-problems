#include <bits/stdc++.h>
#define MAXN 100010
#define f first 
#define s second

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll L, N;
ll loc[MAXN];
ll speed[MAXN];
bool visited[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0801";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> L >> N;

    priority_queue<pll, vector<pll>, greater<pll>> pq;

    loc[0] = 0;
    speed[0] = 1;

    for (ll i = 1; i <= N; i++) {
        cin >> loc[i] >> speed[i];

        pq.push({speed[i], i});
    }

    while (!pq.empty()) {
        auto c = pq.top().s;
        pq.pop();

        if (visited[c]) continue;
        visited[c] = true;

        if (c - 1 >= 0) {
            ll s2 = speed[c] + loc[c] - loc[c - 1];
            if (speed[c - 1] > s2) {
                speed[c - 1] = s2;
                pq.push({speed[c - 1], c - 1});
            }
        }
        if (c + 1 <= N) {
            ll s2 = speed[c] + loc[c + 1] - loc[c];
            if (speed[c + 1] > s2) {
                speed[c + 1] = s2;
                pq.push({speed[c + 1], c + 1});
            }
        }
    }

    ll ans = 1;

    for (ll i = 0; i < N; i++) {
        ans = max(ans, (speed[i] + speed[i + 1] + loc[i + 1] - loc[i]) / 2);
    }

    ans = max(ans, speed[N] + L - loc[N]);

    cout << ans << "\n";
    
	return 0;
}