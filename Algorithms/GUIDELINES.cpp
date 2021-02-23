/*
1. DIVIDE AND CONQUER: A large problem is broken down into smaller sub problems,and their solutions are found individually. In the end,all the sub solutions are combined to obtain the solution for the main problem.
This can only be done if the smaller sub problems are exactly the same as the main problem,executed on a subset of the input. Yahin pe Recursive functions aate hai. EG: merge sort,quicksort are sorting algorithms where the sub problems are the same as main problem,executed on a smaller subset of the input.
We should have some method to combine all the sub solutions to obtain the main solution.

2.GREEDY METHOD: used for optimisation problems(those in which some quantity is to be maximised or minimised,subject to some constraints). EG: Reaching a destination at minimum cost(given options of walking,car,train,plane etc.),within 12 hours. Here,the constraint is 12 hours,whereas the quantity to be optimised is the cost.
Therefore, the train and the plane are FEASIBLE SOLUTIONS as they satisfy the constraint. Train is the OPTIMAL SOLUTION as it also optimises the cost. In greedy method,decision for optimality is taken at the start and we follow it.

3. DYNAMIC PROGRAMMING: also used for optimisation problems. Follows the principle of optimality(a problem can be solved by taking a sequence of decisions,to get the optimal solution). Here,we take a decision at every stage for the most optimal path
We usually use iterative method(tabulation method) to fill up the global array(where the intermediate values are stored). The filling is done from smaller values to larger values.












*/