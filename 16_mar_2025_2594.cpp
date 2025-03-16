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


    ll check(ll mid , vector < int> & ranks , int cars){
        ll count = 0; 
        for(auto & x : ranks){
            ll num = mid / x; 
            num = sqrt(num); 
            count += num; 
            if(count >= cars) return true; 
        }
        return false; 
    }

    long long repairCars(vector<int>& ranks, int cars) {
        

        // find a answer using binary search. 
        ll left = 1; 
        ll right = 1e14; 

        ll ans = 0; 

        while(left <= right){
            ll mid = (left) + (right - left)/2;

            if(check(mid , ranks , cars)){
                ans = mid; 
                right = mid - 1; 
            }
            else left = mid + 1;
        }

        return ans; 
    }
};