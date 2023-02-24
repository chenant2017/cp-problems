#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll B, E;

string bmv = "";
string emv = "";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "greetings";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> B >> E;

    for (ll i = 0; i < B; i++) {
        ll m; char c;
        cin >> m >> c;

        for (ll j = 0; j < m; j++) {
            bmv += c;
        }
    }

    for (ll i = 0; i < E; i++) {
        ll m; char c;
        cin >> m >> c;

        for (ll j = 0; j < m; j++) {
            emv += c;
        }
    }
    
    emv += " ";
    bmv += " ";

    ll bp = 0, ep = 0;
    ll bl = 0, el = 0;
    ll ans = 0;

    bool apart = false;

    while (bp < bmv.size() - 1 || ep < emv.size() - 1) {
        if (bmv[bp] == 'L') {
            bl--;
        }
        else if (bmv[bp] == 'R') {
            bl++;
        }

        if (emv[ep] == 'L') {
            el--;
        }
        else if (emv[ep] == 'R') {
            el++;
        }

        //cout << bl << " " << el << endl;

        if (bp < bmv.size() - 1) {
            bp++;
        }
        if (ep < emv.size() - 1) {
            ep++;
        }

        if (bl == el && apart) {
            ans++;
            apart = false;
        }
        if (bl != el) {
            apart = true;
        }
    }

    std::cout << ans << endl;
	
	return 0;
}