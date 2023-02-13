#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

typedef long long ll;

ll N;
ll A[MAXN];

ll curr(ll ptr, ll d) {
    if (d == 1){
        return A[ptr - 1];
    }
    else {
        return A[ptr];
    }
}

string solve() {
    string result = "";
    ll ptr = 0;
    ll d = 1;

    while (A[0] > 0) {
        //cout << ptr << "\n";
        A[(ptr + ptr + d) / 2]--;
        ptr += d;

        //cout << ptr << "\n";

        if (d == 1) {
            result += 'R';
        }
        else {
            result += 'L';
        }

        //cout << A[(ptr + ptr + d) / 2] << " next\n";

        if (ptr == N || ptr == 0) {
            if (ptr == N) assert(d == 1);
            if (ptr == 0) assert(d == -1);
            d *= -1;
        }
        else if (A[(ptr + ptr + d) / 2] == 1 && curr(ptr, d) > 0) {
            d *= -1;
        }
        else if (A[(ptr + ptr + d) / 2] == 0) {
            d *= -1;
        }
    }

    return result;
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	string fname = "230103";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> A[i];
        assert(A[i] % 2 == 0);
    }

    cout << solve() << "\n";
	
	return 0;
}