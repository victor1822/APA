#ifndef SELECTIONSORT_HPP_INCLUDED
#define SELECTIONSORT_HPP_INCLUDED
#include<vector>
using namespace std;

void ss(vector<int> &v){
int i,j,m,troca;
  for(i=0;i<=v.size()-3;i++){
	m=i;
	for(j=i+1;j<=v.size()-2;j++){
	if(v[j]<v[m]) m=j;
	}
	if(i!=m){ 
	troca=v[i];
	v[i]=v[m];
	v[m]=troca;	
	}
	}
//return v;
}

#endif // SELECTIONSORT_HPP_INCLUDED
