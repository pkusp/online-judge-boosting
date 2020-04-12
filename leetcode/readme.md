# leetcode from 0 to 100

- [top100 liked questions](https://leetcode.com/problemset/top-100-liked-questions/)

---

- **two sum**
字典方式
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(target - nums[i])) {
                return {i, m[target - nums[i]]};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};

// 这种写法更清晰一些：
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            int key = target-nums[i];
            if (m.find(key)!=m.end()) {
                return {i, m[key]};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
```

- **70. climbing stairs**
```cpp

class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        vector<int> path(n);
        path[0]=1;path[1]=2;
        for(int i=2;i<n;++i){
            path[i] = path[i-1]+path[i-2];
        }
        return path.back();
    }
};
```
- **136. Single Number**
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0;i<nums.size();++i){
            res^=nums[i];
        }
        return res;
        }
};

```
- 104. Maximum Depth of Binary Tree
```cpp

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left,right)+1;
    }
};

```

- 206. Reverse Linked List
```cpp
      ListNode *reverseList(ListNode *head){
            if(!head||!head->next) return head;
            ListNode *p = head;
            ListNode *q = head->next;
            p->next=NULL;
            while(q){
                ListNode * tmp = q->next;
                q->next = p;
                p=q;
                q=tmp; 
            }
            return p;
        }

```
- 283. Move Zeroes
```cpp 

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()<=0) return;
        int left_pos = 0;
        while(nums[left_pos]!=0){
            left_pos++;
        }
        int right_pos = left_pos+1;
        while(right_pos<nums.size()){
            if(nums[right_pos]!=0){
                swap(nums[left_pos++],nums[right_pos]);
            }
            right_pos++;
        }  
    }
};

```
- 169. Majority Element
```cpp
// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
     int len = nums.size();
        int cnt = 1;
        int candidate = nums[0];
        for(int i = 1;i<len;++i){
            if(cnt==0){
                candidate = nums[i];
                cnt = 1;
            }else{
                if(candidate==nums[i]){
                    cnt++;
                }else{
                    cnt--;
                }
            }
        }
    return candidate;
};
```

- 21. Merge Two Sorted Lists
```cpp
//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *carry = dummy;
        while(l1&&l2){
            if(l1->val<l2->val) {
                carry->next = l1;
                l1=l1->next;
            }else{
                carry->next = l2;
                l2 = l2->next;
            }
            carry = carry->next;
        }
        carry->next = l1?l1:l2;
        return dummy->next;
    }
};

```
- 121. best time to by and sale stock
```cpp
//Say you have an array for which the ith element is the price of a given stock on day i.
//If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
// Note that you cannot sell a stock before you buy one.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int min_p = INT_MAX;
        int profit = 0;
        for(int i=0;i<prices.size();++i){
            if(prices[i]-min_p>profit) profit = prices[i]-min_p;
            if(prices[i]<min_p) min_p = prices[i];
        }
        return profit;

    }
};

```

- 70. climbing stairs
```cpp

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int> dp(n,0);
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<n;++i){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n-1];    // or dp.back()
    }
};
(1)不带参数的构造函数初始化
// 初始化一个size为0的vector
vector<int> abc;
(2)带参数的构造函数初始化
// 初始化size，但每个元素值为默认值
vector<int>  abc(10);    // 初始化了10个默认值为0的元素
// 初始化size，并且设置初始值
vector<int> cde(10, 1);    // 初始化了10个值为1的元素
(3)通过数组地址初始化
int a[5] = {1,2,3,4,5};
// 通过数组a的地址初始化，注意地址是从0到5（左闭右开）
(4)通过同类型vector初始化
vector<int> a(5, 1);
// 通过a初始化
vector<int> b(a);

```

- 53. Maximum Subarray
```cpp
// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
class Solution {
public:
    int maxSubArray(vector<int> &nums){
        if(nums.size()==0) return 0;
        int res = nums[0];
        int tmp = nums[0];
        for(int i=1;i<nums.size();++i){
            // if(tmp<0){
            //     tmp=nums[i];
            // }
            // else {
            //     tmp = tmp+nums[i];
            // } 
            // res = res>tmp?res:tmp;
            tmp = max(nums[i],tmp+nums[i]);
            res = res>tmp?res:tmp;
        }
        return res; 
    }
};


```
- 101. Symmetric Tree
```cpp
//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

class Solution {
public:
    bool isSymmetric(TreeNode* root){
//         // solution1: 
//         if(!root) return true;
//         return isSymmetric(root->left,root->right);
//     }
    
//     bool isSymmetric(TreeNode* left,TreeNode* right){
//         if(!left&&!right) return true;
//         if(!left&&right||left&&!right||left->val!=right->val) return false;
//         return isSymmetric(left->left,right->right) && isSymmetric(left->right,right->left);
//     }
        
        //solution2:
        if(!root) return true;
        queue<TreeNode*> q1,q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty()&&!q2.empty()){
            TreeNode* p = q1.front();
            TreeNode*q = q2.front();
            q1.pop();
            q2.pop();
            if((!p&&q)||(p&&!q)) return false;
            if(p&&q){
                if(p->val!=q->val) return false;
                q1.push(p->left);
                q1.push(p->right);
                q2.push(q->right);
                q2.push(q->left);
            }
        }
        if(!q1.empty()||!q2.empty()) return false;
        return true;   
    }
};

```

- 198. House Robber
```cpp
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

class Solution { // dp like climbing stairs
public:
    int rob(vector<int>& nums){
        if(nums.size()==0) return 0;
        vector<int> dp(nums.size(),0);
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        dp[0] = nums[0];dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<nums.size();++i){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1]; 
    }
    
};

```

- 155. Min Stack
```cpp
//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//getMin() -- Retrieve the minimum element in the stack.





```

-
-
-
-
-
-
-
-


