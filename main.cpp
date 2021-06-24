#include "myfuns.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
	
	supportFunctions support;
	problems probs;

	srand(time(NULL));

	/* -------------------------------------PROBLEM 1: TWO SUM---------------------------------------------------------------
	int len = 3;//rand() % 6+1;

	vector<int> input = support.random_vector(len);
	input[0] = 3;
	input[1] = 2;
	input[2] = 4;

	int target = support.addRandMem(input, len);

	target = 6;

	cout << "input vector ";
	for (int i = 0; i < input.size(); i++) cout << input[i];
	cout << "\nTarget :" << target;
	cout << "\n Given the input array, give the indices of the two integers in the array that add up to the target.\nYou man not use the same element twice.\n";

	vector<int> twoSumSol = probs.twoSum(input, target);

	cout << "Solution : [" << twoSumSol[0] << ", " << twoSumSol[1] << "]\n";

	if ((input[twoSumSol[0]] + input[twoSumSol[1]]) == target) cout << "Success!\n";
	else cout << "Failure :( \n";
	*/

	/* --------------------------------------PROBLEM 2: ADD TWO NUMBERS---------------------------------------------------------------
	int len1 = rand() % 6 + 1;									// Save length of list for easy looping / printing
	ListNode* l1 = support.makeListNodes(len1);					// Initialize input lists using support function

	ListNode* curr = l1;										// Print out the list for debugging / solution checking purposes
	cout << "List 1: [";
	for (int i = 0; i < len1; i++) {
		if (i < len1 - 1) cout << curr->val << ", ";
		else cout << curr->val << "]\t";
		curr = curr->next;
	}

	int len2 = rand() % 6 + 1;									// Save length of list for easy looping / printing
	ListNode* l2 = support.makeListNodes(len2);					// Initialize input lists using support function

	curr = l2;
	cout << "List 2: [";										// Print out the list for debugging / solution checking purposes
		for (int i = 0; i < len2; i++) {
			if (i < len2 - 1) cout << curr->val << ", ";
			else cout << curr->val << "]\t";
			curr = curr->next;
		}
	
	ListNode* l3 = probs.addTwoNumbers(l1, l2);					// Pass the two lists into the solving function

	curr = l3;
	cout << "\nSum: [";											// Print out the result for debugging / solution checking purposes
	while (curr != NULL) {
		cout << curr->val << ", ";
		curr = curr->next;
	} 
	cout << "]\n";
	*/

	/* --------------------------------------PROBLEM 3: LONGEST SUBSTRING WITHOUT REPEATING NUMBERS-------------------------------------------*/
	// Complete
	/*
	int len = rand() % 5+6;
	//string input = support.makeRandomString(len);
	
	string input = "anviaj";
	//cout << "Input string is: " << input << "\n";
	len = probs.lengthOfLongestSubstring(input);

	cout << "Max length " << len;
	*/

	/* --------------------------------------PROBLEM 4: MEDIAN OF TWO SORTED ARRAYS-------------------------------------------*/
	/*
	vector<int> nums1, nums2;

	nums1 = support.sortedVector(2, 2);
	nums2 = support.sortedVector(3, 6);

	//for (int i = 0; i < 3; i++) {
		//cout << nums1[i] << "  " << nums2[i] << "\n";
	//}

	double med = probs.findMedianSortedArrays(nums1, nums2);

	cout << "Median is " << med << "\n";
	*/

	/* --------------------------------------PROBLEM 5: LONGEST PALINDROMIC SUBSTRING-------------------------------------------*/
	// INCOMPLETE
	string str = support.genRandomString(7, 2);

	cout << "Input string: " << str << "\n";

	string resString = probs.longestPalindromicString(str);

	cout << "Result: " << resString << "\n";

	
	

	/* --------------------------------------PROBLEM 6: Zig Zaggity Zig Zag-------------------------------------------*/
	
/*
	string input = "PalantirIsHiring";
	int numRows = 3;
	string result = probs.zigZaggityZigZag(input, numRows);

	cout << "Input: " << input << "\nOutput: " << result << "\n";

	*/
	/* --------------------------------------PROBLEM 7: reverse integer-------------------------------------------*/
/*
int input = -123;
probs.reverse(input);

*/

	/* --------------------------------------PROBLEM 8: MY ATOI-------------------------------------------*/
	return 0;
};