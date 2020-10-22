#include <stdio.h>
#include <stdlib.h>

#define rep(i, n) for (int i = 0; i < n; i = i + 1)
#define array(N, t) (t*)calloc(N, sizeof(t))
#define ll long long
#define INF ((1LL << 62) - (1LL << 31))
#define max(p, q)((p) > (q) ? (p) : (q))
#define min(p, q)((p) < (q) ? (p) : (q))
#define swap(type, a, b) { type temp = a; a = b; b = temp; }

int n;
int *a;
int *x;
int gcd(int a,int b) {
  if(a<b)swap(int,a,b);
  int r=a%b;
  while(r!=0){
    a=b;
    b=r;
    r=a%b;
  }
  return b;
}
int main() {
  scanf("%d",&n);
  a=array(n,int);
  x=array(n,int);
  rep(i,n)scanf("%d",a+i);
  x[0]=gcd(a[0],a[1]);
  for(int i=1;i<n-1;i+=1){
    x[i]=gcd(x[i-1],a[i+1]);
  }
  printf("%d\n",x[n-2]);
  free(a);
  free(x);
  return 0;
}
