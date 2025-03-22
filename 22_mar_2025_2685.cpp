#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <utility>
#include <functional>
#include <type_traits>
#include <tuple>
#include <cmath>
#include <cstdlib>
#include <complex>
#include <valarray>
#include <ctime>
#include <cassert>
#include <cctype>
#include <cstdarg>
#include <climits>
#include <cfloat>
#include <bitset>
#define ll long long
using namespace std;

class Solution {
    public:
    
    
        void uni(int a , int b , vector < int > & parent , vector < int > & size , 
        vector < int > & value){
    
            a = findParent(a , parent ); 
            b = findParent(b , parent );
    
            if(size[a] < size[b]) a = (a + b) - (b = a); 
            if(a == b) value[a]++;
            else{
                value[a] += value[b] + 1;
                size[a] += size[b]; 
                parent[b] = a;   
            } 
    
        }
    
        int findParent(int x , vector < int > & parent){
            while(x != parent[x]){
                x = parent[x]; 
            }
    
            return x; 
        }
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            
            // complete connected graph component ?? 
            // for each traversal find a edges and vertex in that. 
            // it should be ((count) * (count - 1))/ 2; 
            // can we solve it using DSU ?? 
    
            vector < int > parent(n);
            vector < int > size(n , 1);
            vector < int > value(n , 0); 
    
            for(int i = 0 ; i < n ; i++)
                parent[i] = i; 
    
            for(auto & x : edges){
                int u = x[0]; 
                int v = x[1]; 
                uni(u , v , parent, size , value); 
            }
    
    
            int ans = 0;  
            for(int i = 0 ; i < n ; i++){
                if(parent[i] == i){
                    int vertex = size[i];  
                    int needed = (vertex) * (vertex-1)/2; 
                    if(needed == value[i]) ans++; 
                }
            }
    
            return ans; 
        }
    };