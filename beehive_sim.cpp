#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> flowers; //number of flowers
vector<pair<int, int>> firsts; //possible first cells
vector<vector<double>> a; //average attractiveness of flowers
vector<vector<double>> A; //attractiveness FORCE
vector<vector<int>> visited; //how many times visited
vector<vector<int>> pollinated; //how many times pollinated
vector<vector<vector<int>>> C; //crowdedness; how many bees (at each point in time)

int hivei = 2;
int hivej = 2;

int N, M, F; 
int B, T = 3000, Ft = 100; 
int Pmax = 2; 
int Pt = 10; 
double SD = 30; 
double K_BPF = 500, MEAN_BPF = 1; 
double poll_rate = 0.3;
int di[] = {0, 0, 0, -1, 1}; 
int dj[] = {0, -1, 1, 0, 0};
double R = SD * 3;

random_device rd;
mt19937 gen(rd());

int manhattan(int i1, int j1, int i2, int j2) {
    return abs(i1 - i2) + abs(j1 - j2);
}

double random_double(double min, double max) { 
    uniform_real_distribution<> distr(min, max);
    return distr(gen);
}

int random_int(int min, int max) {
    uniform_int_distribution<> distr(min, max);
    return distr(gen);
}

double density_control(int t, int i, int j) { 
    assert(flowers[i][j] != 0);
    double bpf = C[t][i][j]/flowers[i][j]; 
    return 1 - 1/(1 + exp(-K_BPF * (bpf - MEAN_BPF)));
}

double v_index(int t, int i, int j) { 
    return A[i][j];
}

double p_prob(int t, int i, int j) { 
    if (flowers[i][j] == 0) return 0;
    return poll_rate * density_control(t, i, j);
}

double A_force(int i, int j, double dist) { 
    return a[i][j] * flowers[i][j] * exp(-0.5 * pow(dist / SD, 2));
}

void fill_A(int i, int j) {
    for (int i2 = 0; i2 < N; i2++) {
        for (int j2 = 0; j2 < M; j2++) {
            double dist = sqrt(pow(i2 - i, 2) + pow(j2 - j, 2));
            A[i2][j2] += A_force(i, j, dist);
        }
    }
}

vector<double> get_v_probs(int t, int i, int j) {
    vector<double> probs;

    probs.push_back(v_index(t, i, j));

    int i2, j2;
    for (int d = 1; d < 5; d++) {
        i2 = i + di[d];
        j2 = j + dj[d];
        if (0 <= i2 && i2 < N &&
            0 <= j2 && j2 < M) {
            probs.push_back(probs[d - 1] + v_index(t, i2, j2));
        }
        else {
            probs.push_back(probs[d - 1]);
        }
    }

    return probs;
}

int get_choice(vector<double> probs) {
    double rd = random_double(0, *probs.rbegin());
    int choice;
    for (int p = 0; p < probs.size(); p++) {
        if (rd <= probs[p]) {
            choice = p;
            break;
        }
    }
    return choice;
}

void simulate() {
    int i = hivei;
    int j = hivej;

    int firsti, firstj;
    tie(firsti, firstj) = firsts[random_int(1, firsts.size()) - 1];

    int poll = 0; 
    vector<double> v_probs;
    vector<double> p_probs;
    int poll_time = 0;

    int first_dist = manhattan(i, j, firsti, firstj);
    for (int t = 0; t < first_dist; t++) {
        vector<int> moves;
        for (int d = 1; d < 5; d++) {
            int nexti = i + di[d];
            int nextj = j + dj[d];

            if (manhattan(nexti, nextj, firsti, firstj) < first_dist - t) {
                moves.push_back(d);
            }
        }

        int move = moves[random_int(1, moves.size()) - 1];
        i += di[move];
        j += dj[move];
    }  

    assert(i == firsti && j == firstj);

    if (pollinated[i][j] < Pmax * flowers[i][j]) {
        poll++;
        pollinated[i][j]++;
    }

    for (int t = 0; t < T; t++) {
        poll_time--;
        if (poll_time > 0) continue;

        if (poll >= Ft) return;

        v_probs = get_v_probs(t, i, j);
        int v_choice = get_choice(v_probs);
        i += di[v_choice];
        j += dj[v_choice];
        
        visited[i][j]++; 
        C[t][i][j]++;

        if (flowers[i][j] != 0 && pollinated[i][j] < Pmax * flowers[i][j]) {
            p_probs.clear();
            p_probs.push_back(p_prob(t, i, j));
            p_probs.push_back(1);

            int p_choice = get_choice(p_probs);

            if (p_choice == 0) {
                poll++;
                pollinated[i][j]++;
                poll_time = Pt;
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "sim";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".csv").c_str(), "w", stdout);
	
	cin >> N >> M >> F >> B;

    flowers.resize(N, vector<int>(M, 0));
    a.resize(N, vector<double>(M, 0));
    A.resize(N, vector<double>(M, 0));
    visited.resize(N, vector<int>(M, 0));
    pollinated.resize(N, vector<int>(M, 0));
    C.resize(T, vector<vector<int>>(N, vector<int>(M, 0)));

	int i, j, f_ij;
    double a_ij;
	for (int f = 0; f < F; f++) {
		cin >> i >> j >> f_ij >> a_ij;
        flowers[i][j] = f_ij;
        a[i][j] = a_ij;
        fill_A(i, j);

        if (sqrt(pow(i - hivei, 2) + pow(j - hivej, 2)) <= R) {
            firsts.push_back(pair<int, int>({i, j}));
        }
	}

    for (int s = 0; s < B; s++) {
        simulate();
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << pollinated[i][j] << ", ";
        }
        cout << "\n";
    }

	return 0;
}