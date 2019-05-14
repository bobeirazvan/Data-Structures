#include <iostream>
#include <vector>
#include <algorithm>
template <typename type>
class Heap {
private :  
         std::vector<type> list ; 
         int size_list = 0;        
public : 

         Heap() { // to begin with the position 1
              size_list = 1 ;
              list.resize(size_list) ; 
         }
         int size() {
              return size_list ; 
         }

         int left_son(int father) {
              return father << 1; 
         } 

         int right_son(int father) { 
              return left_son(father) + 1 ;
         }

         int father(int son) { 
              return son >> 1 ;
         }

         void insert(int x) { // push up till it's a heap
              int pos = size_list++; 
              list.push_back(x) ; 
              while(list[pos] > list[father(pos)] && pos >= 2) {
                    std::swap(list[pos],list[father(pos)]) ;
                    pos = father(pos) ;
              }
         }

         int top() {
              return list[1] ; 
         }
            
         int son_master(int father) {  // Mr Patrick   
              if(right_son(father) < size_list)
              if(list[right_son(father)] > list[left_son(father)]) 
                 return right_son(father);
              return left_son(father) ; 
         }  
            
         void remove(int node) { // push down till it's a heap
              std::swap(list[--size_list],list[node]);//swap last node with the next node removed
              list.pop_back() ;  
              while(list[node] < list[son_master(node)]) {
                    node = son_master(node) ;
                    std::swap(list[node],list[father(node)]) ;
                    if(left_son(node) >= size_list ) break ; 
              }
         }        
                 
         type GetElement(int pos) {
              return list[pos] ;
         }
         
}; 

