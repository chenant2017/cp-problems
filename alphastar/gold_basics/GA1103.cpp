#include <bits/stdc++.h>
#define MAX 35
using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> ttll;
typedef tuple<ll, ll, ll, ll, ll> tll; 

ll M, N;
ll pond[MAX][MAX];
ttll dists[MAX][MAX];
bool visited[MAX][MAX] = {false};
ll di[] = {1, 2};
ll dj[] = {2, 1};

void dijkstra(ll starti, ll startj) {
    priority_queue<tll, vector<tll>, greater<tll>> q;
    q.push(tll({0, 0, starti, startj, 1}));
    dists[starti][startj] = ttll({0, 0, 1});

    while (!q.empty()) {
        ll geese, jumps, i, j, ways;
        std::tie(geese, jumps, i, j, ways) = q.top();
        q.pop();

        if (visited[i][j]) continue;
        visited[i][j] = true;
        //cout << i << " " << j << "\n";
        
        for (ll d = 0; d < 2; d++) {
            for (ll si = -1; si <= 1; si += 2) {
                for (ll sj = -1; sj <= 1; sj += 2) {
                    ll ni = i + di[d] * si;
                    ll nj = j + dj[d] * sj;

                    if (0 <= ni && ni < M &&
                        0 <= nj && nj < N &&
                        pond[ni][nj] != 2) {
                        if (ni == 5 && nj == 5) {
                            //cout << ni << " " << nj << "\n";
                        }
                        ll ngeese, njumps, nways;
                        std::tie(ngeese, njumps, nways) = dists[ni][nj];
                        if (pond[ni][nj] == 0) geese++;
                        if (geese < ngeese) {
                            ngeese = geese;
                            njumps = jumps + 1;
                            nways = ways;
                            
                        }
                        else if (geese == ngeese) {
                            if (njumps == jumps + 1) {
                                //cout << nways << " nways before\n";
                                nways += ways;
                                
                            }
                            else if (jumps + 1 < njumps) {
                                njumps = jumps + 1;
                                nways = ways;
                            }
                        }
                        if (pond[ni][nj] == 0) geese--;
                        dists[ni][nj] = ttll({ngeese, njumps, nways});
                        q.push(tll({ngeese, njumps, ni, nj, nways}));
                    }
                }
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GA1103";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> M >> N;

    ll starti, startj;
    ll desti, destj;

    for (ll i = 0; i < M; i++) {
        for (ll j = 0; j < N; j++) {
            cin >> pond[i][j];
            if (pond[i][j] == 3) {
                starti = i;
                startj = j;
            }
            if (pond[i][j] == 4) {
                desti = i;
                destj = j;
            }
        }
    }

    for (ll i = 0; i < M; i++) {
        for (ll j = 0; j < N; j++) {
            dists[i][j] = ttll({pow(10, 4), pow(10, 4), 0});
        }
    }

    dijkstra(starti, startj);

    for (ll i = 0; i < M; i++) {
        for (ll j = 0; j < N; j++) {
            ll a, b, c;
            tie(a, b, c) = dists[i][j];
            cout << a << ", " << b << ", " << c << "   ";
        }
        cout << "\n";
    }

    ll ans1, ans2, ans3;

    std::tie(ans1, ans2, ans3) = dists[desti][destj];

    if (ans1 == pow(10, 4)) cout << "-1\n";
    else  {
        cout << ans1 << "\n";
        cout << ans2 << "\n";
        cout << ans3 << "\n";
    }

    
	
	return 0;
}