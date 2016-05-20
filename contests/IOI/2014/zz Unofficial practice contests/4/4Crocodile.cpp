/*
ID: Labib666
LANG: C++
Contest: IOI unofficial practice 4
Task: 4Crocodile
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define VI vector <int>
#define VLL vector <LL>
#define PQI priority_queue <int>
#define PQLL priority_queue <LL>
#define QI queue <int>
#define QLL queue <LL>
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define SZ size()
#define INF 1000000007
#define LINF 1000000000000000007
#define PI 2*asin(1)
#define EPS 1e-9

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define MEM(A,V)   memset (A, (V), sizeof A)

using namespace std;

int gcd (int a, int b){return (b > a) ? gcd (b,a) : (b == 0) ? a : gcd (b, a%b);}
int bitcount (int a) {return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;}
LL bigmod (LL num, LL pow, LL prime) {
    if (pow == 0ll) return 1ll;
    LL ans = bigmod(num, pow/2ll, prime); ans = (ans*ans)%prime;
    if (pow%2ll) ans = (ans*num)%prime; return ans;
}

#define MAXN 100005

int N, M, K, Ans;
int Vis[MAXN];
VI V[MAXN], E[MAXN];
priority_queue <PII> Q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("4Crocodile.txt","r",stdin);

    int u, v, w;
    PII P;

    cin >> N >> M >> K;

    FOR(i,0,M) {
        cin >> u >> v >> w;
        V[u].PB (v);
        V[v].PB (u);
        E[u].PB (w);
        E[v].PB (w);
    }

    FOR(i,0,K) {
        cin >> w;
        Vis[w]++;
        Q.push(MP(0,w));
    }

    while (!Q.empty()) {
        P = Q.top();
        Q.pop();

        if (Vis[P.Y] == 2) continue;

        Vis[P.Y]++;
        if (P.Y == 0 && Vis[P.Y]==2) break;

        if (Vis[P.Y]<2) continue;

        FOR(i,0,V[P.Y].SZ) {
            w = V[P.Y][i];
            if (Vis[w]==2) continue;
            Q.push(MP(P.X-E[P.Y][i],w));
        }
    }

    Ans = -P.X;

    cout << Ans << endl;

    return 0;
}
