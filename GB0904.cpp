#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
deque<deque<ll>> soapy;
ll top_clean = 0;

ll get_soapy(ll plate) {
    ll min = -1; 
    ll max = soapy.size(); 

    while (max - min > 1) {
        ll mid = (min + max) / 2;
        if (soapy[mid][0] < plate) {
            min = mid;
        }
        else {
            max = mid;
        }
    }

    return max;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0904";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 1; i <= N; i++) {
        ll plate;
        cin >> plate;
        //cout << i << " " << plate << "\n";
        ll sp = get_soapy(plate);
        //cout << "sp " << sp << "\n";

        if (sp == soapy.size()) {
            soapy.push_back(deque<ll>({plate}));
        }
        else {
            while (plate > soapy[sp].back()) {
                if (soapy[sp].back() > top_clean) {
                    top_clean = soapy[sp].back();
                    soapy[sp].pop_back();
                }
                else {
                    cout << i - 1 << "\n";
                    return 0;
                }
            }
            if (plate < top_clean) {
                cout << i - 1 << "\n";
                return 0;
            }
            soapy[sp].push_back(plate);
        }
    }

    cout << N << "\n";
	return 0;
}