#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int maxn=1e4;
const int inf=0x3f3f3f3f;

int main() {
    int n;
    while(~scanf("%d", &n)) {
        priority_queue<ll, vector<ll>, greater<ll> >q;
        ll res = 0;
        for (int i = 1; i <= n; ++i) {
            ll x;
            scanf("%lld", &x);
            q.push(x);
        }
        while (1) {
            ll a = q.top();
            q.pop();
            if (q.empty())break;
            ll b = q.top();
            q.pop();
            res += a + b;
            q.push(a + b);
        }
        printf("%lld\n", res);
    }
}
