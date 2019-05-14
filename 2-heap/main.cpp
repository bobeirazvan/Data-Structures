#include <iostream>
#include <fstream>
#include <vector>
#include "heap.h"

std::ifstream fin("heap.in");
std::ofstream fout("heap.out");
   
int main() {
   int N ;
   fin >> N ;
   Heap <int> pq ; 
   for(int i = 0 ; i < N ; ++i) {
       int opt , numar;
       fin >> opt ;
       if(opt == 1) {
          fin >> numar ;
          pq.insert(numar) ;
       }
       if(opt == 2) {
          fout << pq.top() << "\n" ;
          pq.remove(1) ;
       }
   }
}

