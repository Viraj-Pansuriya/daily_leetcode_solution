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

// Brute force approach, can also be done by Topological Sorting
class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    
            int n=recipes.size();
    
            unordered_map<string,int> mp;
            vector<int> check(n,0);
    
            for(auto it: supplies){
                mp[it]=1;
            }
    
            for(int i=0; i<n ; i++){
    
                for(int j=0; j<n ; j++){
    
                    if(check[j]==0){
                        int f=1;
    
                        for(auto it: ingredients[j]){
                            if(mp.find(it)==mp.end()){
                            f=0;
                            break;
                            }
    
                        }
    
                        if(f==1){
                            check[j]=1;
                            mp[recipes[j]]=1;
                        }
                    }
                }
            }
    
            vector<string> ans;
            for(int i=0; i<n; i++){
                if(check[i]==1){
                    ans.push_back(recipes[i]);
                }
            }
    
            return ans;
    
            
            
        }
    };