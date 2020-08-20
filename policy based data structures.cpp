/// Add / remove elements
/// No of elements < X
/// k-th smallest element
/// min / max
/// Time complexity = log(n)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int main()
{
    /// Add elements in any random order
    pbds A;
    A.insert(11);
    A.insert(1);
    A.insert(5);
	A.insert(3);
	A.insert(7);
	A.insert(9);
	A.insert(3);

	//Total contents
	cout << "1, 3,5, 7, 9, 11" << endl;

	//K-th smallest
	int k = 3;
	cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;

	k = 5;
	cout << k << "th smallest: " << *A.find_by_order(k-1) << endl;


	//NO OF ELEMENTS < X
	int X = 9;
    /*
    Ordered_set can't erase element x but it can erase k th element by doing A.erase(A.find_by_order(k))
    */
	cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;

	//DELETE Elements
    cout << "Deleted 3" << endl;
    A.erase(A.find(3));

    //Total contents
    /// will not work for duplicates.
	cout << "1, 3 ,5 ,7, 9, 11" << endl;

	k = 3;
	cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;

    cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;

    //NEXT BIGGER/SMALLER ELEMENT than X
    X = 8;

    cout << "Next greater element than " << X << " is " << *A.upper_bound(X) << endl;


	return 0;
}
