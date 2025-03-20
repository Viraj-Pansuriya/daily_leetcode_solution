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

#define ll long long 
class Solution {
public:
    void uni(vector < int > & parent , vector <int> &size ,  vector < ll > & values ,
            vector < int > & x){

        int a = x[0]; 
        int b = x[1]; 
        int w = x[2];

        a = findParent(parent , a); 
        b = findParent(parent , b); 

        if(size[a] < size[b] ) swap(a,b); 
        values[a] &= values[b] & w;
        if(a == b) return; 
        size[a] += size[b]; 
        parent[b] = a; 
        

    }
    int findParent(vector < int > & parent , int x){

        while(parent[x] != x) {
            x = parent[x]; 
        }
        return x; 

    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& q) {

        vector < int > parent(n); 
        vector < int > size(n , 1); 

        for(int i = 0 ; i < parent.size() ; i++){
            parent[i] = i; 
        }

        vector < ll > values(n , 1LL*(1 << 31) - 1); 

        for(auto & x : edges){
           uni(parent , size , values , x); 
        }
       
       
        vector < int > ans; 
        for(auto & x : q){
            int a = x[0];
            int b = x[1]; 

            a = findParent(parent , a);
            b = findParent(parent , b); 

            if(a != b) ans.push_back(-1); 
            else ans.push_back(values[a]);
        }

        return ans;

    }
};