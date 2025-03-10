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
        long long countOfSubstrings(string word, int k) {
            
    
            long long ans = atleast(word , k) - atleast(word , k+1);  
            return ans; 
        }
    
    
        long long atleast(string word , int k){
    
    
            unordered_map < char , int > mp; 
    
            long long count = 0; 
    
            int i = 0 , j = 0; 
    
            int currK = 0; 
    
    
            while(j < word.size()){
    
                char c = word[j]; 
                if(isVowel(c)){
                    mp[c]++; 
                }
                else currK++; 
    
                while(mp.size() == 5 && currK >= k){
    
                    count += (word.size() - j); 
                    if(isVowel(word[i])){
                        mp[word[i]]--; 
                        if(mp[word[i]] == 0) mp.erase(word[i]); 
                    }
                    else currK--; 
                    i++; 
                }
                j++; 
            }
            return count; 
        }
    
        bool isVowel(char c){
            return (c == 'a' || c == 'e' || c == 'i' ||  c == 'o' ||  c == 'u'); 
        }
    
    
    
    };