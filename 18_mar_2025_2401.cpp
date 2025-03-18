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
    
    
        void setBits(int x , vector < int > & bits){
            for(int i = 0 ; i < 32 ; i++){
                if(x & (1 << i)) bits[i]++; 
            }
        }
    
        bool notValidBits(vector < int > &bits){
            for(auto & x : bits){
                if(x > 1) {
                    return true; 
                }
            }
            return false; 
        }
    
        void unSetBits(int x , vector < int > & bits){
    
            for(int i = 0 ; i < 32 ; i++){
                if(x & (1 <<i)) bits[i]--; 
            }
        }
    
        
        int longestNiceSubarray(vector<int>& nums) {
            
            vector < int > bits(32 , 0); 
    
            int maxi = 1; 
            int i = 0; 
            int j = 0; 
            for(auto & x : nums){
                
                setBits(x , bits); 
                
                while(notValidBits(bits)){
                    cout<<i<<endl; 
                    unSetBits(nums[i] , bits); 
                    i++; 
                }
                maxi = max(maxi , (j - i + 1));
                j++;
            }
    
            return maxi; 
    
    
        }
    };