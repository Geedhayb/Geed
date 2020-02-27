#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int maxn=2000;
const int inf=0x3f3f3f3f;

int fa[maxn],n,m,k;
ll ans=0;
struct edge{
	int from;
	int to;
	int cost;
}E[maxn*maxn];
int find(int x){
	return x==fa[x]?fa[x]:fa[x]=find(fa[x]);
}
void baba(int x,int y,int i){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		fa[fx]=fy;
		ans+=E[i].cost;
		k++;
	}
}
struct rule{
	bool operator()(const edge &a1,const edge &a2){
		return a1.cost<a2.cost;	
	}
};
ll kruskal(){
	ans=0;
	sort(E+1,E+m+1,rule());
	for(int i=1;i<=m;i++){
		baba(E[i].from,E[i].to,i);
		if(k==n-1) break;
	}
	return ans;
}
int main(){
	scanf("%d %d",&n,&m);
	k=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) {
		scanf("%d %d %d",&E[i].from,&E[i].to,&E[i].cost);
	}
	printf("%lld\n",ans);
}
