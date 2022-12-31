#include <bits/stdc++.h>
#define MAXN 80010
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
pll ans[MAXN];
ll ptr[MAXN]; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA1001";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N;

    ans[0] = {-1, -1};
    ptr[0] = 0;

    for (ll i = 1; i <= N; i++) {
        char c;
        ll K;
        cin >> c;
       
        if (c == 'a') {
            ptr[i] = i;
            cin >> K;
            ans[i] = {ans[i - 1].second, K};
        }
        else if (c == 's') {
            ptr[i] = ptr[ptr[i - 1] - 1];
            ans[i] = ans[ptr[i]];
        }
        else {
            cin >> K;
            ptr[i] = ptr[K - 1];
            ans[i] = ans[ptr[i]];
        }
    }

    for (ll i = 1; i <= N; i++) {
        cout << ans[i].second << "\n";
    }
	
	return 0;
}