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
        vector  < string > st; 
        int numTilePossibilities(string tiles) {
            sort(tiles.begin() , tiles.end()); 
            opr(0 , tiles , ""); 
    
            vector < int > fact(8); 
            fact[0] = 1; 
    
            for(int i = 1 ; i <= 7 ; i++){
                fact[i] = i*fact[i-1]; 
            }
    
            int total = 0; 
            for(auto & x : st){
    
                unordered_map < char , int > mp; 
                for(auto & y : x) mp[y]++; 
                int currVal = fact[x.size()]; 
                for(auto & x : mp){
                    currVal /= fact[x.second]; 
                }
    
                total += currVal; 
    
            }
    
            return total; 
    
    
        }
    
        void opr(int index , string & tiles , string curr){
            
            if(curr != "") st.push_back(curr);
            for(int i = index ; i < tiles.size() ; i++){
                if(i > index && tiles[i] == tiles[i-1]) continue; 
                opr(i + 1 , tiles , curr + tiles[i]); 
            }
        }
    };