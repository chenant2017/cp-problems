#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

typedef long long ll;

ll N;
ll F[MAX];
vector<ll> G[MAX];
bool visited[MAX];

ll count(ll i) {
    cout << i << " i\n";
    if (visited[i]) return 0;
    //if (visited[i]) return 0;
    visited[i] = true;

    ll result = 1;
    result += count(F[i]);

    for (auto j: G[i]) {
        result += count(j);
    }

    return result;
}

bool cycle(ll i) {
    ll p1 = F[i];
    ll p2 = F[F[i]];

    while (p1 != p2) {
        p1 = F[p1];
        p2 = F[F[p2]];
    }
    
    return F[p1] != p1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "relay";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 1; i <= N; i++) {
        cin >> F[i];

        if (F[i] != 0) {
            G[F[i]].push_back(i);
        }
        else {
            F[i] = i;
        }
    }

    ll ans = 0;

    for (ll i = 1; i <= N; i++) {
        if (!visited[i]) {
            cout << "hey\n";
            ll c = count(i);
            if (!cycle(i)) ans += c;
        }
    }
    
    cout << ans << "\n";

    return 0;
}