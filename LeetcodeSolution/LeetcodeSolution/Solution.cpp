#include "Solution.h"
#include<map>
#include<algorithm>

Solution::Solution() {

}
Solution::~Solution() {

}
/*
Single Number
Solution
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1

Example 2:

Input: [4,1,2,1,2]
Output: 4
*/
int Solution::singleNumber(vector<int>& nums) {
	int ret = nums[0];
	for (int i = 1; i < nums.size(); ++i) {
		ret ^= nums[i];
	}
	return ret;
}
/*
Happy Number
Solution
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, 
replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 
(where it will stay), or it loops endlessly in a cycle which does not include 1. 
Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example:

Input: 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/
bool Solution::isHappy(int n) {
	int i, r = 0;
	int sum = 0;
	vector<int> v;
	while (n > 0) {
		sum = 0;
		while (n > 0) {
			r = n % 10;
			sum += r * r;
			n = n / 10;
		}
		n = sum;
		if (n == 1)
			return true;
		auto it = find(v.begin(), v.end(), n);
		if (it != v.end())
			return false;
		v.push_back(n);
	}
	return false;
}
/*
Maximum Subarray
Solution
Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, 
which is more subtle.
*/
int Solution::maxSubArray(vector<int>& nums) {
	int max = nums[0];
	int len = nums.size();
	for (int i = 0; i < len; ++i) {
		int temp = nums[i];
		if (max < temp) {
			max = temp;
		}
		for (int j = i + 1; j < len; ++j) {
			temp += nums[j];
			if (max < temp) {
				max = temp;
			}
		}
	}
	return max;
}
/*
Move Zeroes
Solution
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative 
order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/
void Solution::moveZeroes(vector<int>& nums) {
	int len = nums.size();
	int index = 0;
	for (int i = 0; i < len; ++i) {
		if (nums[i] != 0) {
			nums[index++] = nums[i];
		}
	}
	for (int j = index; j < len; ++j) {
		nums[j] = 0;
	}
}
/*
Best Time to Buy and Sell Stock II
Solution
Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time 
(i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
			 Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
			 Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
			 engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.


Constraints:

1 <= prices.length <= 3 * 10 ^ 4
0 <= prices[i] <= 10 ^ 4
*/
int Solution::maxProfit(vector<int>& prices) {
	if (prices.size() == 0) {
		return 0;
	}
	int total = 0;
	for (int i = 0; i < prices.size() - 1; i++) {
		if (prices[i + 1] > prices[i]) {
			total += prices[i + 1] - prices[i];
		}
	}
	return total;
}
/*
Group Anagrams
Solution
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/
vector<vector<string>> Solution::groupAnagrams(vector<string>& strs) {
	vector<vector<string>> ret;
	int len = strs.size();
	map<string, vector<string>> m;
	for (int i = 0; i < len; ++i) {
		string key = strs[i];
		sort(key.begin(), key.end());
		m[key].push_back(strs[i]);
	}
	for (auto itr : m) {
		ret.push_back(itr.second);
	}
	return ret;
}
/*
Middle of the Linked List
Solution
Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.



Example 1:

Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
Example 2:

Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.


Note:

The number of nodes in the given list will be between 1 and 100.
*/
ListNode* Solution::middleNode(ListNode* head) {
	int count = 0;
	ListNode* node = head;
	while (node != NULL) {
		count++;
		node = node->next;
	}
	int mid = count / 2;
	count = 0;
	node = head;
	while (node != NULL) {
		if (count == mid)
			break;
		count++;
		node = node->next;
	}
	return node;
}
/*
Backspace String Compare
Solution
Given two strings S and T, return if they are equal when both are typed into empty text editors. 
# means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/
stack<char> Solution::removeBackSpace(string S) {
	stack<char> st;
	for (int i = 0; i < S.length(); ++i) {
		if (S[i] == '#') {
			if (st.size() > 0) {
				st.pop();
			}
		}
		else {
			st.push(S[i]);
		}
	}
	//cout << S << "\n";
	return st;
}
bool Solution::backspaceCompare(string S, string T) {
	stack<char> st_S = removeBackSpace(S);
	stack<char> st_T = removeBackSpace(T);
	if (st_S.size() != st_T.size()) return false;
	while (!st_S.empty()) {
		char c1 = st_S.top();
		char c2 = st_T.top();
		st_S.pop();
		st_T.pop();
		if (c1 != c2) {
			return false;
		}
	}
	return true;
}
/*
Last Stone Weight
Solution
We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.  
Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)



Example 1:

Input: [2,7,4,1,8,1]
Output: 1
Explanation:
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
*/
int Solution::lastStoneWeight(vector<int>& stones) {
	sort(stones.begin(), stones.end());
	int len = stones.size();
	while (len > 1) {
		int x = stones[len - 2];
		int y = stones[len - 1];
		stones.erase(stones.begin() + stones.size() - 1);
		if (x == y) {
			stones.erase(stones.begin() + stones.size() - 1);
		}
		else {
			stones[stones.size() - 1] = y - x;
		}
		len = stones.size();
		sort(stones.begin(), stones.end());
	}
	return len == 0 ? 0 : stones[0];
}
/*
Contiguous Array
Solution
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
*/
int Solution::findMaxLength(vector<int>& nums) {
	map<int, int> m;
	m[0] = -1;
	int maxlen = 0, count = 0;
	for (int i = 0; i < nums.size(); i++) {
		count = count + (nums[i] == 1 ? 1 : -1);
		auto itr = m.find(count);
		if (itr != m.end()) {
			maxlen = max(maxlen, i - m[count]);
		}
		else {
			m[count] = i;
		}
	}
	return maxlen;
}