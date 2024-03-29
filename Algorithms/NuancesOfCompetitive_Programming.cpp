/*
A SUBARRAY is a contiguous part of array. An array that is inside another array. For example, consider the array [1, 2, 3, 4], There are 10 non-empty sub-arrays. The subbarays are (1), (2), (3), (4), (1,2), (2,3), (3,4), (1,2,3), (2,3,4) and (1,2,3,4). In general, for an array/string of size n, there are n*(n+1)/2 non-empty subarrays/subsrings.
A SUBSEQUENCE is a sequence that can be derived from another sequence by zero or more elements, without changing the order of the remaining elements. 
For the same example, there are 15 sub-sequences. They are (1), (2), (3), (4), (1,2), (1,3),(1,4), (2,3), (2,4), (3,4), (1,2,3), (1,2,4), (1,3,4), (2,3,4), (1,2,3,4). More generally, we can say that for a sequence of size n, we can have (2n-1) non-empty sub-sequences in total. 
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
A string example to differentiate: Consider strings “geeksforgeeks” and “gks”. “gks” is a subsequence of “geeksforgeeks” but not a substring. “geeks” is both a subsequence and subarray. Every subarray is a subsequence. More specifically, Subsequence is a generalization of substring.



Usually for competitive coding problems, the time limit is around 1 second and you can safely assume that you can perform 10^8 to 10^9 operations within that time. So when the constraint is given as n <= 10^5, it serves to us as a hint that any O(nlogn) algorithm will suffice. Similarly, n <= 10^4 usually implies quadratic runtime and n <= 10^9 implies that a linear runtime is required. Of course, the constants also come into play, but these serve as a general guidline for most problems.

*/