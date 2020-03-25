#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e5+7;

struct node{
	double x,y;
}a[maxn],b[maxn];
struct ruleX{
	bool operator()(const node &a,const node &b){
		return a.x<b.x;
	}
};
struct ruleY{
	bool operator()(const node &a,const node &b){
		return a.y<b.y;
	}
};
double dis(node a,node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double minDis(int l,int r){
	if(r-l+1==2) return dis(a[l],a[r]);
	if(r-l+1==3) return min(dis(a[l],a[l+1]),dis(a[l+1],a[r]));
	int mid=(l+r)>>1;
	printf("debug\n");
	double d=min(minDis(l,mid),minDis(mid+1,r));
	int k=0;
	for(int i=l;i<=r;i++){
		if(fabs(a[i].x-a[mid].x)<=d){
			b[k++]=a[i];
		}
	}
	sort(b,b+k,ruleY());
	for(int i=0;i<k;i++){
		for(int j=i+1;j<k&&j<i+6;j++){
			d=min(d,dis(b[i],b[j]));
		}	
	}
	return d;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf %lf",&a[i].x,&a[i].y);
	}
	sort(a+1,a+1+n,ruleX());
	printf("%f\n",minDis(1,n));
}

