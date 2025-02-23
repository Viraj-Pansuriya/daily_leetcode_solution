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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        TreeNode* constructFromPrePost(vector<int>& pr, vector<int>& po) {
            int preInd = 0; 
            int postInd = 0; 
            return opr(pr , po  , preInd , postInd);  
    
    
        TreeNode * opr(vector < int > & pr , vector < int > &po , int & preInd , int & postInd){
    
            if(preInd == pr.size()) return nullptr; 
            TreeNode * root = new TreeNode(pr[preInd]); 
            preInd++;
    
            if(root->val != po[postInd]){
                root->left = opr(pr , po , preInd , postInd); 
            }
    
            if(root->val != po[postInd]){
                root->right = opr(pr , po , preInd , postInd); 
            }
    
            postInd++; 
    
            return root; 
    
    
        }
    };