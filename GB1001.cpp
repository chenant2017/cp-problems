#include <bits/stdc++.h>
#define MAXN 110
using namespace std;

typedef long long ll;

ll A[MAXN];
ll B[MAXN];
ll diff[MAXN];
ll N, X, Y, Z;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB1001";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> X >> Y >> Z;

    ll totalA = 0;
    ll totalB = 0;

    for (ll i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        diff[i] = A[i] - B[i];
        totalA += A[i];
        totalB += B[i];
    }

    ll ans = 0;

    if (totalA - totalB < 0) {
        for (ll i = 0; i < N; i++) {
            if (diff[i] > 0) {
                for (ll dist = 1; dist <= N; dist++) {
                    ll ptr1 = i - dist;
                    ll ptr2 = i + dist;

                    if (ptr1 >= 0 && diff[ptr1] < 0) {
                        if (diff[i] > -diff[ptr1]) {
                            diff[i] += diff[ptr1];
                            ans += -diff[ptr1] * min(dist * Z, X + Y);
                            diff[ptr1] = 0;
                        }
                        else {
                            diff[ptr1] += diff[i];
                            ans += diff[i] * min(dist * Z, X + Y);
                            diff[i] = 0;
                        }
                    }
                    if (ptr2 < N && diff[ptr2] < 0) {
                        if (diff[i] > -diff[ptr2]) {
                            diff[i] += diff[ptr2];
                            ans += -diff[ptr2] * min(dist * Z, X + Y);
                            diff[ptr2] = 0;
                        }
                        else {
                            diff[ptr2] += diff[i];
                            ans += diff[i] * min(dist * Z, X + Y);
                            diff[i] = 0;
                        }
                    }
                }
            }   
        }
        ans += (totalB - totalA) * X;
    }
    else {
        cout << "a\n";
        for (ll i = 0; i < N - 1; i++) {
            ans += min(X + Y, Z) * abs(diff[i]);
            //cout << diff[i] << " diff " << min(X + Y, Z) * abs(diff[i]) << " added\n";
            diff[i + 1] += diff[i];
            diff[i] = 0;
        }

        ans += Y * (totalA - totalB);
    }

    cout << ans << "\n";
	
	return 0;
}