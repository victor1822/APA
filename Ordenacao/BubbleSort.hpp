#ifndef BUBBLESORT_HPP_INCLUDED
#define BUBBLESORT_HPP_INCLUDED
#include<vector>
#include"QuickSort.hpp"
using namespace std;
/*
void bs(vector<int> &v){
static int c=0;
if(c<v.size()-2){
if(v[c+1]<v[c]){
 swap(v[c+1],v[c]);
 c=0;
 bs(v);
}
else {
 c++;
 bs(v);}
}
}*/

void bs(vector<int> &v){
static int c=0;
static int sc=0;
if(c<v.size()-2){
if(v[c+1]<v[c]){
 swap(v[c+1],v[c]);
 c=0;
 sc++;
 bs(v);
}
else {
 c++;
if(c==v.size() && sc>0){
c=0;
sc=0;
}
 bs(v);}
}

}


#endif // BUBBLESORT_HPP_INCLUDED
