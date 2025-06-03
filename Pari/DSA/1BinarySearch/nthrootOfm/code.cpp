//LINK-> https://www.naukri.com/code360/problems/nth-root-of-m_1062679?leftPanelTabValue=PROBLEM

int optimal_powf(int n,int mid, int m){
  //returns
  // 0->if<m (1=>if ==m) (->2 if >m)
  long long an=1;
  for(int i=1;i<=n;i++){
    an=an* mid;
    if(an>m) return 2;
  }
  if(an==m) return 1;
  return 0; 
}
//IT RETURNS THE nth power which aint actually needed and leads to int overflow, so use _powf
int f(int n, int m){
  int a=1;
  for(int i=1;i<=n;i++){
  a*=m;
  }
  return a;
}
int NthRoot(int n, int m) {

  int l=0, h=m;
  while(l<=h){
    int mid=(l+h)/2;
   // if(f(n, mid)==m){
     if(optimal_powf(n, mid, m)==1){
      return mid;
    }
    else if(optimal_powf(n,mid, m)==2){
      h=mid-1;
    }
    else{
      l=mid+1;
    }
  }
  return -1; //if not found(given in q)
}
