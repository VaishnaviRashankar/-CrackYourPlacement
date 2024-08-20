<h2><a href="https://www.geeksforgeeks.org/problems/find-minimum-adjustment-cost-of-an-array4628/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card">Find minimum adjustment cost of an array</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array <strong>arr[]</strong> of positive integers of size <strong>N</strong> and an integer <strong>target</strong>, replace each element in the array such that the difference between adjacent elements in the array is less than or equal to a given target. We need to minimize the adjustment cost, that is the sum of differences between new and old values. We basically need to minimize ∑|A[i]  A<sub>new</sub>[i]| where 0 &lt;= i &lt;= n-1, n is size of A[] and A<sub>new</sub>[] is the array with adjacent difference less than or equal to target.Assume all elements of the array is less than constant M = 100.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>N = 4, target = 1
arr[] = { 1, 3, 0, 3 }
<strong>Output:</strong> 3
<strong>Explanation</strong>: One of the possible 
solutions is [2, 3, 2, 3].
</span></pre>

<p><br>
<span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>N = 4, target = 1
arr[] = {2, 3, 2, 3}
<strong>Output:</strong> 0
<strong>Explanation: </strong>All adjacent elements 
in the input array are already less 
than equal to given target.</span></pre>

<p><br>
<br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
This is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function <strong>minAdjustmentCost</strong>() that takes array<strong> arr[] ,</strong> integer<strong> n, </strong>and integer<strong> target</strong>&nbsp;as parameters and returns the minimum adjustment cost.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N).<br>
<strong>Expected Auxiliary Space:</strong> O(1).</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>2</sup></span></p>

<p>&nbsp;</p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Dynamic Programming</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;