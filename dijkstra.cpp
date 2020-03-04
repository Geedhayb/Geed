#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int maxn=1e4;
const int inf=0x3f3f3f3f;

int mp[maxn][maxn],d[maxn],n,m;
bool vis[maxn];
void dijkstra(int s){
	memset(d,inf,sizeof d);
	memset(vis,0,sizeof vis);
	d[s]=0;
	for(int i=1;i<n;i++){
		int x=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&(x==0||d[j]<d[x])) x=j;
		}
		vis[x]=1;
		for(int y=1;y<=n;y++){
			d[y]=min(d[y],d[x]+mp[x][y]);
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	memset(mp,inf,sizeof mp);
	for(int i=1;i<=n;i++) mp[i][i]=0;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		mp[x][y]=min(mp[x][y],z);
	}
	dijkstra(1);
	for(int i=1;i<=n;i++) printf("%d%c",d[i],"\n "[i!=n]);
}
