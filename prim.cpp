#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int maxn=2000;
const int inf=0x3f3f3f3f;

int dis[maxn],mp[maxn][maxn],n,m,ans;
bool vis[maxn];
void prim(){
	memset(dis,inf,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[1]=0;
	for(int i=1;i<n;i++){
		int x=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&(x==0||dis[j]<dis[i])) x=j;
		} 
		vis[x]=1;
		for(int y=1;y<=n;y++){
			if(!vis[y]) dis[y]=min(dis[y],mp[x][y]);
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
		mp[x][y]=mp[y][x]=min(z,mp[x][y]);
	}
	prim();
	for(int i=2;i<=n;i++) ans+=dis[i];
	printf("%d\n",ans); 
}
