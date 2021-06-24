#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <time.h>
#include <string>
#include <map>

using namespace::std;

struct ListNode {																// Struct definition fro linked lists in Problem 2
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class supportFunctions {
public:

	vector<int> random_vector(int len) {										// Function that generates random vector inputs for problem #1

		vector<int> output;
		for (int i = 0; i < len; i++) {
			output.push_back(rand() % 9 + 1);
		}
		return output;
	}

	int addRandMem(vector<int> &nums, int len) {								// Function that adds two random integers from random vector for problem #1

		int output;
		output = nums[rand() % len];
		int num = output;
		while (num == output) {
			output = nums[rand() % len];
		}
		return output + num;
	}

	ListNode* makeListNodes(int len) {											// Function that generates linked list inputs for problem #2
			
		ListNode* list = new ListNode();
		ListNode* curr = list;
		for (int i = 0; i < len - 1; i++) {										// Loop through and assign random 1-9 values to each node in the list
			int value = rand() % 9;
			curr->val = value;
			curr->next = new ListNode();
			curr = curr->next;
		}
		curr->val = rand() % 9;
		curr->next = NULL;
		return list;
	}

	string makeRandomString(int len) {											// Support functino to generate random string for problem 3
		string randString;
		char c;
		for (int i = 0; i < len; i++) {
			c = 'a' + rand() % 26;
			randString.append(std::string(1, c));
		}

		return randString;
	} 

	vector<int> mergeSortedArrays(vector<int>& x, vector<int>& y) {				// Function for problem 4 to merge two given sorted arrrays
		map<int, bool> arrMap;
		vector<int> output;

		for (int i = 0; i < x.size(); i++)	arrMap[x[i]] = true;
		for (int i = 0; i < y.size(); i++) arrMap[y[i]] = true;

		for (auto i : arrMap) output.push_back(i.first);

		return output;

	}

	vector<int> sortedVector(int len, int startNum) {							// Support function to generate two sorted arrays for problem 4
		vector<int> output;
		output.push_back(startNum);

		for (int i = 1; i < len; i++) {
			output.push_back(output[i - 1] + rand() % 2 + 1);
		}
		return output;
	}

	int palLength(string s, int left, int right) {								// Function to expand around the center of a potential palindrome
		while (left >= 0 && right <= s.length() && s[left] == s[right]) {			// For problem 5
			left--;
			right++;
		}
		return right - left - 1;
	}

	string genRandomString(int len, int opt) {											// Input function for problem 5 - generates strings with customizable
		string str;																		// levels of palindromosity
		switch (opt) {
		case 0: // No artificial repeats
			for (int i = 0; i < len; i++) {
				str.push_back('a' + rand() % 26);
			}
			break;
		case 1: // Repeat the reverse of the first half of the string
			for (int i = 0; i < len / 2; i++) {
				str.push_back('a' + rand() % 26);
			}
			str = str + revString(str); // 
			
		case 2: // Make some part of the string palindromic
			for (int i = 0; i < len; i++) {
				str.push_back('a' + rand() % 26);
			}
			int ndx = len - 3;
			string tempStr = str.substr(ndx-3, 3);
			tempStr = revString(tempStr);
			
			str.replace(len - 3, 3, tempStr);
			
			break;
		}
		return str;
		
	}

	string revString(string s) {												// Useful function to reverse string - used in input function for problem 5
		for (int i = 0; i < s.length() / 2; i++) {
			swap(s[i], s[s.length() - i - 1]);
		}
		return s;
	}

};

class problems {
public:

	vector<int> twoSum(vector<int>& nums, int target) {							// Solution function for problem #1 (brute force method)

		vector<int> out;
		for (int i = 0; i < nums.size(); i++) {									// Loop through all of the integers in each vector
			for (int j = 0; j < nums.size(); j++) {
				if ((nums[i] + nums[j]) == target && (i != j)) {				// Check condition (integers add up to target) and they it isn't n+n
					out.push_back(i);											// Save the indices
					out.push_back(j);
				}
			}
		}
		return out;
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {						// Solution function for problem #2
		
		int carry = 0, num1, num2;
		ListNode* l3 = new ListNode();
		ListNode* currentNode = l3;

		while (l1 != NULL || l2 != NULL) {
			if (l1 == NULL) num1 = 0;											// If we've reached the end of one of the lists, just add 0 for that list's val
			else num1 = l1->val;
			if (l2 == NULL) num2 = 0;
			else num2 = l2->val;

			currentNode->val = (num1 + num2 + carry)%10;						// Perform add operation taking only ones place
			carry = (num1 + num2 + carry) / 10;									// Carry over tens place

			if (l1 != NULL) l1 = l1->next;										// Iterate through the input lists if not at the end
			if (l2 != NULL) l2 = l2->next;

			if (l1 != NULL || l2 != NULL) {										// Iterate through output lists while we aren't at the end of BOTH input lists
				currentNode->next = new ListNode();
				currentNode = currentNode->next;
			}
		}
		if (carry > 0) currentNode->next = new ListNode(carry);					// Corner case where the last addition gives a carry value
		return l3;
	}

	int lengthOfLongestSubstring(string s) {									// Solution function for problem 3 Brute force method

		string temp, subTemp;
		bool b;
		int maxLen = 1;

		for (int i = 0; i < s.length(); i++) {								
			temp = s.substr(i, 1);
			if (s.substr(i).length() < maxLen) {
				break;
			}
			cout << temp << "\n";
			for (int j = i + 1; j < s.length(); j++) {
				subTemp = s.substr(j, 1);
				b = !(temp.find(subTemp) != std::string::npos);
				if (b) {
					temp += s.substr(j, 1);
					if (temp.length() > maxLen) maxLen = temp.length();
				}
				else break;
				cout << temp << "\n";
			}
		}

		return maxLen;
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {			// Solution for problem 4
		supportFunctions support;
		double result = 0.0;

		// Combine the sorted arrays
		vector<int> sortedCombineArray = support.mergeSortedArrays(nums1, nums2);	// Merge the two sorted arrays and get a sorted output

		//for (int i = 0; i < sortedCombineArray.size(); i++) {
		//	cout << sortedCombineArray[i] << "\n";
		//}

		// Calculate median
		// If the array length is odd (i.e. 5, 7) take the middle value of the sorted array
		if (sortedCombineArray.size() % 2) result = sortedCombineArray[sortedCombineArray.size() / 2];
		else result = (sortedCombineArray[sortedCombineArray.size() / 2 - 1] + sortedCombineArray[sortedCombineArray.size() / 2])/2.0;



		return result;
	}

	string longestPalindromicString(string s) {								//Solution for problem 5
		if (s.length() < 1) return "";
		if (s.length() == 1) return s;
		supportFunctions support;
		string str;
		int currMax = 0;
		for (int i = 0; i < s.length()-1; i++) {								// Expand around center technique
			int length1 = support.palLength(s, i, i);						// Case we are starting on selected letter
			int length2 = support.palLength(s, i, i + 1);					// Case we are starting between the current letter and the next letter
			if (length1 > length2 && length1 > currMax) {					
				str = s.substr(i - length1 / 2, length1);					// Set string to longest palindrome if it's longer than precious ones
				currMax = length1;											// Keep track of longest palindrome so far
			}
			else if (length2 > length1 && length2 > currMax) {
				str = s.substr(i - length2 / 2+1, length2);
				currMax = length2;
			}
			else if (length1 == length2 && length1 > currMax) str = s[i];	// Make sure we grab a single character if palindrome is only 1 char long
		}

		return str;
	}

	string zigZaggityZigZag(string s, int numRows) {				// Solution for problem 6
		string out;

		if (numRows == 1) return s;									// 1 row is just regular text...

		int zagLength = 2 * (numRows - 1);							// Get the length of the zag (top down, bottom to top right -> |/ )
		
		for (int i = 0; i < numRows; i++) {							// Loop over number of rows because each behaves differently
			for (int ii = 0; ii+i < s.length(); ii+=zagLength) {	
				out += s.substr(i + ii, 1);							
				if (i != 0 && i != numRows-1 && ii + zagLength - i < s.length()) {		// For rows that have diagonal elements i.e. not top & bottom
					out += s.substr(ii + zagLength - i, 1);
				}
			}

		}
		return out;
	}

	int reverse(int x) {											// Solution for problem 7 - This one is simple
		int rev = 0;
		while (x != 0) {
			int pop = x % 10;
			x = x / 10;
			if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
			if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
			rev = rev * 10 + pop;
		}
		return rev;
	}

	int myAtoi(string s) {											// Solution for problem 8 - this one is dumb :(
		int i = 0, x, result = 0;
		bool pos = true, numStart = false, hitSign = false;
		string temp;

		for (int i = 0; i < s.length(); i++) {
			if (numStart) {
				if (s[i] > 57 || s[i] < 48) {
					break;
				}
			}
			if ((s[i] != 43 && s[i] != 45 && s[i] != 32) && (s[i] < 48 || s[i] > 57)) return 0;
			if (s[i] == 43) {
				if (s[i + 1] > 57 || s[i + 1] < 48) return 0;
				if (hitSign) return 0;
				pos = true;
				hitSign = true;
			}
			if (s[i] == 45) {
				if (s[i + 1] > 57 || s[i + 1] < 48) return 0;
				if (hitSign) return 0;
				pos = false;
				hitSign = true;
			}
			if (s[i] > 47 && s[i] < 58) {
				numStart = true;
				long long res = long(result) * long(10) + (long(s[i]) - long(48));
				if (res > pow(2, 31) - 1) {
					if (pos) return pow(2, 31) - 1;
					else return -pow(2, 31);
				}
				result = result * 10 + (s[i] - 48);
			}
			cout << result;
		}
		if (!pos) result = result * -1;

		return result;
	}
};