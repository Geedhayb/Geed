#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<set>
#include<vector>
#include<queue>
#include<cmath>
#include<stack> 
#include<map>
#include<deque>
using namespace std;
typedef long long ll;
#define eps 1e-8
#define pi acos(-1.0)
template<class T> void read(T&num) {
    char CH; bool F=false;
    for(CH=getchar();CH<'0'||CH>'9';F= CH=='-',CH=getchar());
    for(num=0;CH>='0'&&CH<='9';num=num*10+CH-'0',CH=getchar());
    F&&(num=-num);
}
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
inline ll qpow(ll a,ll b,ll p){ll res=1;while(b){if(b&1){res*=a;res%=p;}b>>=1;a=a*a%p;}return res;}
int lowbit(int x){return x&(-x);}
const int maxn=1200;
const int inf=0x3f3f3f3f;
const ll mod=998244353;

ll dp[maxn][maxn];
char s1[maxn],s2[maxn];
int main(){
	scanf("%s %s",s1+1,s2+1);
	int len1=strlen(s1+1),len2=strlen(s2+1);
	for(int i=0;i<=len1;i++) dp[i][0]=0;
	for(int i=0;i<=len2;i++) dp[0][i]=0;
	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			if(s1[i]==s2[j]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	printf("%lld\n",dp[len1][len2]);
}
/*
ABCBDAB
BDCABA

13456778
357486782
*/
