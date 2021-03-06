// #include {{{
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
// }}}
// #define {{{
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
// }}}

const int N = 100;
int n , a[N];

int main(){
  cin >> n;
  rep(i,0,n) cin >> a[i];
  int x = 0;
  rep(i,0,n) if(abs(a[i]) > abs(a[x]))
    x = i;
  vector<pii> op;
  auto go = [&](int x,int y) {
    a[y] += a[x];
    op.pb(mp(x , y));
  };
  rep(i,0,n) if(i != x) go(x , i);
  if(*min_element(a , a + n) >= 0) {
    rep(i,1,n) go(i - 1 , i);
  } else {
    per(i,1,n) go(i , i - 1);
  }
  cout << sz(op) << endl;
  rep(i,0,sz(op))
    cout << op[i].fi + 1 << " " << op[i].se + 1 << endl;
  return 0;
}
