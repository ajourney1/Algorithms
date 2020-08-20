ind the prime factors of each number and their powers. The LCM of all numbers will have a factorisation with the powers of each prime factor being the maximum of that of all the numbers.

Consider the list of numbers,
a[]={12, 16, 60, 35};

12=2^2 * 3^1, so the factor array would be {2,1,0,0,…}
where the ith element denotes the power of the ith prime.
Similarly the factor arrays of all other numbers can be found,
16={4,0,0,0,…}
60={2,1,1,0,…}
35={0,0,1,1,…}
The factor array of the LCM of all numbers would have the ith element equal to the maximum of all the numbers’s ith elements in their factor arrays.
So the LCM would be {4,1,1,1,…}=2^4 * 3^1 * 5^1 * 7^1=1680
