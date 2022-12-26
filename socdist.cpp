#include <bits/stdc++.h>
#define MAX 100010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
pll grass[MAX];

bool works(ll d) { //would be faster if found max cows per interval in one computation
    ll loc = grass[0].f;
    ll g = 0;
    ll placed = 1;
    
    while (g < M) {
        loc += d;
        if (loc <= grass[g].s) {
            placed++;
        }
        else {
            while (g < M && loc > grass[g].s) {
                g++;
            }
            if (g < M) {
                loc = max(loc, grass[g].f);
                placed++;
            }
        }
    }

    return placed >= N;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "socdist";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < M; i++) {
        cin >> grass[i].f >> grass[i].s;
    }

    sort(grass, grass + M);

    ll d = 1; 
    ll jump = (N - 1) / 2;

    while (jump > 0) {
        if (works(d + jump)) {
            d += jump;
        }
        else {
            jump /= 2;
        }
    }

    cout << d << "\n";
	
	return 0;
}