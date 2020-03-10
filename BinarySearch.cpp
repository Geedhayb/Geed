#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int maxn=1e4;
const int inf=0x3f3f3f3f;

int a[maxn],n;
int BinarySearch(int x){
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(a[mid]>=x) r=mid;
		else l=mid+1;
	}
	if(a[l]!=x) return 0;
	else return l;
} 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int x;
	scanf("%d",&x);
	printf("%d\n",BinarySearch(x));
}
