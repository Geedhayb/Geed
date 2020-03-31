#include<bits/stdc++.h>
using namespace std;

void insertsort(int a[],int low,int high){
    int key,j;
    for(int i=low+1; i<=high; i++) {
        key = a[i];
        for(j=i-1;j>=low&&key<a[j];j--) {
            a[j+1] = a[j];
        }
        a[j+1]=key;
    }
}
int partition(int a[],int p,int r,int pivot){
    int x;
    int i=p-1;
    int j,tmp;
    for (j=p;j<r;j++) {
        if(a[j] == pivot) {
            swap(a[j],a[r]);
        }
    }
    x = a[r];
    for(j=p;j<r;j++) {
        if(a[j]<=x) {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}
int select(int a[], int l, int r, int k){
    int group;
    int left,right,mid;
    int left_num;
    if (r-l+1<=5) {
        insertsort(a,l,r);
        return a[l+k-1];
    }
    group=(r-l+1+5)/5;
    for(int i=0;i<group;i++) {
        left = l+5*i;
        right = (l+5*i+4) > r?r:l+5*i+4;
        mid = (left+right)/2;
        insertsort(a,left,right);
        swap(a[l+i],a[mid]); 
    }
    int pivot=select(a,l,l+group-1,(group+1)/2);
    int p=partition(a,l,r,pivot);
    left_num=p-l;
    if(k == left_num+1)
        return a[p];
    else if(k<=left_num)
        return select(a, l, p-1, k);
    else
        return select(a,p+1,r,k-left_num-1);
}
int arr[10010];
int main(void){
    srand(time(0));
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i) arr[i]=rand()%1000;
	for(int i=0;i<n;++i) cout<<arr[i]<<' ';
	cout<<endl; 
    printf("%d\n",select(arr,0,n-1,m));
}


