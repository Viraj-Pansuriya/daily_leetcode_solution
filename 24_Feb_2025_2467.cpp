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
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    
            int n = amount.size(); 
            vector < int > adj[100001]; 
    
            for(auto & x : edges){
                int u = x[0]; 
                int v = x[1]; 
                adj[u].push_back(v);  
                adj[v].push_back(u);
            }
    
    
            vector < bool > store(n , false); 
            vector < int > path; 
            findPathFromBob(adj , store , bob , path , 0);
    
            reverse(path.begin() , path.end()); 
            map < int , int > mp; 
            int count = 0; 
            for(auto & x : path){
                mp[x] = count++; 
            }
           for(int i = 0 ; i < store.size() ; i++) store[i] = false; 
            return calc(adj , amount , 0 , mp , store , 0);
    
        }
    
    
        int calc(vector < int > adj[] , vector < int > & amount , int index , map < int , int > & mp ,
        vector < bool > & store , int time){
            int count = 0; 
            if(mp.find(index) != mp.end()){
                if(mp[index] == time) count += (amount[index]/2); 
                else if(mp[index] > time) count += amount[index]; 
            }
            else count += amount[index]; 
            int maxi = INT_MIN; 
            store[index] = true; 
            for(auto & x : adj[index]){
                if(store[x] == false){
                    int curr = calc(adj , amount , x , mp , store , time + 1); 
                    maxi = max(maxi , curr); 
                }
            }
            store[index] = false; 
            return (count) + ((maxi == INT_MIN) ? 0 : maxi); 
        }
    
    
        bool findPathFromBob(vector < int > adj[] , vector < bool > & store , int bob,  vector < int > & path , int curr){
    
            
            path.push_back(curr); 
            store[curr] = true; 
            if(curr == bob){
                return true; 
            }
    
            for(auto & v : adj[curr]){
                if(store[v] == false)
                    if(findPathFromBob(adj , store , bob , path , v)) return true; 
            }
            path.pop_back(); 
            store[curr] = false; 
            return false; 
           
        }
    };