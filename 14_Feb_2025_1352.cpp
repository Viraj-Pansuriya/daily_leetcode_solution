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

/***
 * Explanation : 
 * 
 * query type : 
 * 1 ) add number 
 * 2 ) get product of last k items. 
 * 
 * approach 1:
 * use some sort of prefix array and convert 0 to 1 , and get answer from there , 
 * according to query 
 * 
 * problem : since prefix array is storing multipication, might be chance that will overflow 
 * long long limit   
 * 
 * approach 2 : 
 * 
 * since each time you need multiplication of last K items, 
 * maintain one variable which tells last index of 0 , 
 * case 1 : 
 * if your (n-k)th index is before last index of 0 , means your subarray contains 0 
 * direct return 0; 
 * 
 * case 2 : 
 * (n-k)th index > (last 0th index) , use same prefix based approach  ;
 * 
 * NOTE : once you get 0 as a element to add , store prefix multiplication to 1 , 
 * this way you are reseting your multiplication and won't face overflow of long long data type. 
 * (it is given in problem that answer would fit in 32 bit).    
 *
 */

class ProductOfNumbers {
    public:
    
        int index = 0; 
        long long mul = 1;
        int thr = 0; 
        vector < long long > str; 
    
        ProductOfNumbers() {
            str.push_back(1);    
        }
        
        void add(int num) {
            index++;  
            if(num == 0){
                mul = 1; 
                thr = index; 
            }
            else {
                mul = mul * num; 
            }
            str.push_back(mul);    
        }
        
        int getProduct(int k) {
            int diff = (index - k + 1); 
            if(diff <= thr) return 0; 
            return (str[index] / str[index - k]); 
        }
    };