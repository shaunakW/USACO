#include <bits/stdc++.h>

#define fori(i, a) for(int i = 0; i < a; ++i)
#define trav(i, a) for(auto& i : a)

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("cowxor.in", "r", stdin);
    freopen("cowxor.out", "w", stdout);
}

int N, cows[100000];

// can be faster
int main() {
    setIO();
    cin >> N;
	
    fori(i, N) cin >> cows[i];

    int maxxor = 0;
    int start = 0;
    int end = 0;
    fori(i, N) {
        int val = 0;
        for(int j = i; j < N; j++) {
            val ^= cows[j];
            if (val > maxxor || (val == maxxor && (j < end || (j == end && i > start)))) {
                maxxor = val;
                start = i;
                end = j;
            }
        }
    }
    cout << maxxor << " " << start + 1 << " " << end + 1;
    
    return 0;
}
