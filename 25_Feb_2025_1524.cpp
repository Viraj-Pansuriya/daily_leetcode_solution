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
        int numOfSubarrays(vector<int>& arr) {
    
    
            /*
            explanation: 
            for each index find out number of sunarrays ending with that index and having odd sum. 
            use prefix sum + hashmap approach  
            **/
    
            for(int i = 0 ; i < arr.size() ; i++){
                arr[i] %= 2; 
            }
    
            vector < long long  > store(2 , 0); 
            store[0]++; 
    
            long long  sum = 0; 
            long long count = 0; 
            int md = 1e9 + 7; 
    
            for(auto & x : arr){
                sum += x; 
                sum %=2; 
                count = (count % md + store[1 - sum] % md) % md;
                // at each point find out number of subarrays with different parity. 
                store[sum]++; 
            }
    
            return count; 
        }
    };