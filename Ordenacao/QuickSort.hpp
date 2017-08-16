#ifndef QUICKSORT_HPP_INCLUDED
#define QUICKSORT_HPP_INCLUDED
#include<vector>
using namespace std;

void swap(int *a, int *b){

int temp = *a;
*a = *b;
*b = temp;
}

int particioning(vector<int> &ent,int start, int end){
static int sp;//status do pivot, se esta olhando para esquerda ou para a direita
int pivot = start;
int e = start;//da esquerda
int d = end;//da direita

if(e!=d){
while(e!=d){
if(pivot==e){

if(ent[pivot]<=ent[d])d--;
else{ 
swap(ent[pivot],ent[d]);
pivot=d;
}
}
else{//pivot != e

if(ent[pivot]>=ent[e])e++;
else{
swap(ent[pivot],ent[e]);
pivot=e;
}
}//fecha else

}//fecha while
}//fecha if de teste superior
else{ pivot = e; return pivot;}

}//fecha particioning




void qs(vector<int> &ent, int p, int r){
if(p < r){
int q = particioning(ent,p,r);
 qs(ent,p,q-1);//primeira parte
 qs(ent,q+1,r);
}
}

#endif // QUICKSORT_HPP_INCLUDED
