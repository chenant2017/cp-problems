//Silver 2021 December #1

#include <bits/stdc++.h>
#define MAX 200010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll K, M, N;
pll patches[MAX];
ll nhoj[MAX];
priority_queue<ll> tasties;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "1714A";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> K >> M >> N;

    for (ll i = 0; i < K; i++) {
        cin >> patches[i].f >> patches[i].s; 
    }

    for (ll i = 0; i < M; i++) {
        cin >> nhoj[i];
    }

    sort(patches, patches + K);
    sort(nhoj, nhoj + M);

    ll j = -1;   

    for (ll i = 0; i < K; i++) {
        ll total = 0;
        ll j2 = j;
        while (j2 + 1 < K && patches[j2 + 1].f < nhoj[i]) {
            j2++;
            total += patches[j2].s;
        }
        ll max_intersect = get_max_intersect(j, j2);
        tasties.push(max_intersect);
        tasties.push(total - max_intersect);
        j = j2;
    }
	
	return 0;
}