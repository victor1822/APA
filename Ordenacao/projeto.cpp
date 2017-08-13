#include <stdio.h>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;
int main() {
  std::ifstream file("entrada.txt");
  unsigned size;
  file >> size; 

  if (!file) {
    //erro durante leitura
  }

  std::vector<int> entrada;
  entrada.reserve(size*size);

  while (true) {
    double value;
    if (!(file >> value)) {
      break;
    }
    entrada.push_back(value);
  }

  if (entrada.size() != size*size) {
    //erro durante leitura
  }
  //usa matriz
cout<<"Os dados de entrada são:";
int i;
for(i=0;i<entrada.size()-1;i++){
cout<<entrada[i];
}
}
