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
        int minOperations(vector<int>& nums, int k) {
            long long  opr = 0; 
            sort(nums.begin() , nums.end()); 
            priority_queue < long long  , vector < long long  > , greater < long long  > > pq; 
            bool first = true; 
            for(auto & x : nums) {
                if(x >= k){
                    if(first)  first = false;
                    else break; 
                }
                pq.push(x); 
            }
            while(pq.size() > 1 && pq.top() < k){
                long long  a = pq.top(); 
                pq.pop(); 
                long long  b = pq.top(); 
                pq.pop(); 
                long long  curr = min(a , b) * 2 + max(a , b);
                pq.push(curr); 
                opr++;  
            }
            return opr; 
        }
    };