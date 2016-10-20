/*
    CodeJam APAC 2017
    Round: D
    Task: B
*/

/***********Template Starts Here***********/
//#include <bits/stdc++.h>#include <sys/resource.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <functional>
#include <string>
#include <iostream>
#include <cctype>
#include <set>
#include <climits>
#include <iomanip>
#include <cassert>
#include <sstream>
//#include <sys/resource.h>
//#include <unordered_map>

#define pb push_back
#define nl puts ("")
#define sp printf ( " " )
#define phl printf ( "hello\n" )
#define ff first
#define ss second
#define POPCOUNT __builtin_popcountll
#define RIGHTMOST __builtin_ctzll
#define LEFTMOST(x) (63-__builtin_clzll((x)))
#define MP make_pair
#define FOR(i,x,y) for(int i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(int i = (y) ; i >= (x) ; --i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define NUMDIGIT(x,y) (((int)(log10((x))/log10((y))))+1)
#define SQ(x) ((x)*(x))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define ALL(x) (x).begin(),(x).end()
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define SZ(x) ((int)(x).size())

using namespace std;

#define LL long long
typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < int, int > pii;
typedef pair < vlong, vlong > pll;
typedef vector<pii> vii;
typedef vector<int> vi;

const vlong inf = 2147383647;
const vlong mod = 1000000007;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;

#ifdef forthright48
     #include <ctime>
     clock_t tStart = clock();
     #define debug(args...) {dbg,args; cerr<<endl;}
     #define timeStamp printf("Execution Time: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC)
#else
    #define debug(args...)  // Just strip off all debug tokens
    #define timeStamp
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

//int knightDir[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2},{-2,-1} };
//int dir4[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

inline vlong gcd ( vlong a, vlong b ) {
    a = ABS ( a ); b = ABS ( b );
    while ( b ) { a = a % b; swap ( a, b ); } return a;
}

vlong ext_gcd ( vlong A, vlong B, vlong *X, vlong *Y ){
    vlong x, y, u, v, m, n, a, b, q, r;
    x = 0; y = 1;
    u = 1; v = 0;
    for (a = A, b = B; 0 != a; b = a, a = r, x = u, y = v, u = m, v = n) {
        q = b / a;
        r = b % a;
        m = x - (u * q);
        n = y - (v * q);
    }
    *X = x; *Y = y;
    return b;
}

inline vlong modInv ( vlong a, vlong m ) {
    vlong x, y;
    ext_gcd( a, m, &x, &y );
    if ( x < 0 ) x += m; //modInv is never negative
    return x;
}

inline vlong power ( vlong a, vlong p ) {
    vlong res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x );
        x = ( x * x ); p >>= 1;
    }
    return res;
}

inline vlong bigmod ( vlong a, vlong p, vlong m ) {
    vlong res = 1 % m, x = a % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m; p >>= 1;
    }
    return res;
}

/*** FAST I/O ***/

//#define gc getchar
#define gc getchar_unlocked

void readInt(int &x){
    register char c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

void readVlong (vlong &x){
    register char c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

void readChar ( char &x ) {
    register char c = gc();
    while (c < 33) c = gc();
    x = c;
}

void readString(char *str){
    register char c = 0;
    register int i = 0;
    while (c < 33)
        c = gc();
    while (c != '\n') {
        str[i] = c;
        c = gc();
        i = i + 1;
    }
    str[i] = '\0';
}

/*** FAST I/O Ends ***/int  Set(int N,int cur){ return N = N | (1<<cur); }int  Reset(int N,int cur){ return N = N & ~(1<<cur); }bool Check(int N,int cur){ return (bool)(N & (1<<cur)); }

/***********Template Ends Here***********/

int t, tc;int r, c;int dp[10][40][40], cc, done[10][40][40];vi valid;bool isValid(int level) {	for (int i=1; i<c-1; i++) {		if ( Check(level,i-1) && Check(level,i) && Check(level,i+1) ) {			return 0;		}	} return 1;}bool isValid(int lev1, int lev2, int lev3) {	for (int i=0; i<c; i++) {		if ( Check(lev1,i) && Check(lev2,i) && Check(lev3,i) ) {			return 0;		}	} return 1;}int solve (int level, int mask1, int mask2) {	if (level == r) return 0;	if (done[level][mask1][mask2] == cc) return dp[level][mask1][mask2];	done[level][mask1][mask2] = cc;	int &ret = dp[level][mask1][mask2];	ret = 0;	for (int i=0; i<valid.size(); i++) {		if ( isValid(valid[i],mask1,mask2) ) {			ret = MAX(ret, POPCOUNT(valid[i]) + solve(level+1,valid[i],mask1));		}	}	return ret;}

int main () {

    /*** Stack Memory Increase ***/
    const rlim_t kStackSize = 256 * 1024 * 1024; // min stack size = 256 MB
    struct rlimit rl;
    int result;
    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0) {
        if (rl.rlim_cur < kStackSize) {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0) {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }
    /*** Stack Memory Increase ends ***/


    #ifdef forthright48
    //freopen ( "input.txt", "r", stdin );
    freopen ( "B01.in", "r", stdin );
    freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    scanf("%d", &t);
    tc = 0;    cc = 0;

    while (tc<t) {
        tc++;        cerr << "---------------- Case: " << tc << " ----------------------\n";
        printf("Case #%d:", tc);
        //nl;
        sp;

		scanf("%d %d", &r, &c);		if (r < c) swap (r,c);		valid.clear();		for (int i=0; i<(1<<c); i++) {			if (isValid(i)) {				valid.pb(i);			}		}		if (r == 1) {			printf("1\n");			continue;		}		if (r == 2) {			int mm = 0;			for (int i=0; i<valid.size(); i++) {				if ( POPCOUNT(valid[i]) > mm ) {					mm = POPCOUNT(valid[i]);				}			}			printf("%d\n", mm + mm);			continue;		}		int ans = 0;		cc++;		for (int i=0; i<valid.size(); i++) {			for (int j=0; j<valid.size(); j++) {				int cur = POPCOUNT(valid[i]) + POPCOUNT(valid[j]);				ans = MAX( ans, cur+solve(2,valid[i],valid[j]) );				//debug(ans, valid[i], valid[j], "->", cur+solve(2,valid[i],valid[j]));			}		}		printf("%d\n", ans);
    }


    return 0;
}
