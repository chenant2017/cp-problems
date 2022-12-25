#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

typedef long long ll;

ll N;
bool photo[MAX][MAX];


ll di[] = {-1, -1, 0, 0};
ll dj[] = {-1, 0, -1, 0};

bool is_31(ll i, ll j) { //use lower right corner 
    ll rcount = 0;
    ll lcount = 0;

    for (ll d = 0; d < 4; d++) {
        ll nexti = i + di[d];
        ll nextj = j + dj[d];

        if (photo[nexti][nextj]) rcount++;
        else lcount++;
    }

    return (rcount == 1 || lcount == 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "leftout";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (ll j = 0; j < N; j++) {
            photo[i][j] = s[j] == 'R';
        }
    }

    pair<ll, ll> ans = pair<ll, ll>({-1, -1});

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            bool works = true;
            for (ll d = 0; d < 4; d++) {
                ll testi = i + 1 + di[d];
                ll testj = j + 1 + dj[d];

                if (1 <= testi && testi < N &&
                    1 <= testj && testj < N) {
                    
                    if (!is_31(testi, testj)) {
                        works = false;
                        break;
                    }
                }
            }

            if (works) {
                if (ans.first == -1) {
                    ans = pair<ll, ll>({i, j});
                }
                else {
                    cout << "-1\n";
                    return 0;
                }
            }
        }
    }

    if (ans.first == -1) {
        cout << "-1\n";
    }
    else {
        cout << ans.first + 1 << " " << ans.second + 1 << "\n";
    }   
	
	return 0;
}