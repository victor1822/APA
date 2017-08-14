#ifndef INSERTIONSORT_HPP_INCLUDED
#define INSERTIONSORT_HPP_INCLUDED

void is(vector<int> &meuvetor){
    int tmp,tmp1;
for(int i=1;i<meuvetor.size();i++){
   tmp=meuvetor[i];
   int j=i;
   while( j>0 && meuvetor[j-1]>tmp){
    meuvetor[j]=meuvetor[j-1];
    j--;
    meuvetor[j]=tmp;
   }
}
}

#endif // INSERTIONSORT_HPP_INCLUDED
