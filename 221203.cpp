#include <bits/stdc++.h>
#define MAXN 310
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll ranges[MAXN][MAXN];
pll mm[MAXN];
ll N;

bool works(ll i, ll next) {
    for (ll j = i - 1; j >= 0; j--) {
        pll new_range = mm[j];
        if (next < mm[j].f) {
            new_range.f = next;
        }
        if (next > mm[j].s) {
            new_range.s = next;
        }
        if (new_range.s - new_range.f != ranges[j][i]) {
            return false;
        }
    }
    return true;
}

void update(ll i, ll next) {
    for (ll j = i - 1; j >= 0; j--) {
        if (next < mm[j].f) {
            mm[j].f = next;
        }
        if (next > mm[j].s) {
            mm[j].s = next;
        }
    }
    mm[i] = {next, next};
}   

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "p3";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        for (ll j = i; j < N; j++) {
            cin >> ranges[i][j];
        }
    }

    vector<ll> ans = {0};
    mm[0] = {0, 0};

    for (ll i = 1; i < N; i++) {
        ll next = *ans.rbegin() + ranges[i - 1][i];
    
        if (works(i, next)) {
            ans.push_back(next);
            update(i, next);
        }
        else {
            next = *ans.rbegin() - ranges[i - 1][i];
            ans.push_back(next);
            update(i, next);
        }

       
    }

    cout << 0;
    for (ll i = 1; i < ans.size(); i++) {
        cout << " " << ans[i];
    }
    cout << "\n";
	
	return 0;
}