#ifndef COUNTSORT_HPP_INCLUDED
#define COUNTSORT_HPP_INCLUDED
#include <iostream>
#include<vector>
using namespace std;

int cs(vector<int> &ent){
//int vector<int> r;
int *resposta = (int*)malloc((ent.size()-1)*sizeof(int));
int menor,maior;
menor=maior=ent[0];
for(int i=0;i<ent.size()-1;i++){
if(ent[i]<menor)menor=ent[i];
if(ent[i]>maior)maior=ent[i];
}
int v=maior-menor+1;
int *tmp  = (int*)malloc(v*sizeof(int));

for(int i=0;i<v;i++){
tmp[i]=0;
}//zerando o vetor temporario

for(int i=0;i<ent.size()-1;i++){
tmp[ent[i]-menor]++;
}//contando

for(int i=1;i<v;i++){
tmp[i]=tmp[i]+tmp[i-1];
}//somando

for(int i=0;i<ent.size()-1;i++){
resposta[tmp[ent[i]-menor]-- -1]=ent[i];
}

for(int i=0;i<ent.size()-1;i++){
ent[i]=resposta[i];
}
free(tmp);
free(resposta);
}

int cs(vector<int> &ent, int exp){ //counting sort utilizado no radix
//int vector<int> r;
int *resposta = (int*)malloc((ent.size()-1)*sizeof(int));
int menor,maior;
menor=maior=ent[0];
for(int i=0;i<ent.size()-1;i++){
if(ent[i]<menor)menor=ent[i];
if(ent[i]>maior)maior=ent[i];
}
int v=maior-menor+1;
int *tmp  = (int*)malloc(v*sizeof(int));

//int count[10]={0}

for(int i=0;i<v;i++){
tmp[i]=0;
}//zerando o vetor temporario

for(int i=0;i<ent.size()-1;i++){
tmp[((ent[i]-menor)/exp)%(ent.size()-1)]++;
}//contando

for(int i=1;i<v;i++){
tmp[i]=tmp[i]+tmp[i-1];
}//somando

for(int i=0;i<ent.size()-1;i++){
resposta[tmp[((ent[i]-menor)/exp)%(ent.size()-1)]-- -1]=ent[i];
}

for(int i=0;i<ent.size()-1;i++){
ent[i]=resposta[i];
}
free(tmp);
free(resposta);
}


#endif // COUNTSORT_HPP_INCLUDED
