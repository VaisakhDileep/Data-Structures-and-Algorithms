/*
Created by  : Vaisakh Dileep
Date		: 27, April, 2021
Description : This program helps to understand head recursion.
*/

#include<iostream>

using namespace std;

namespace recursion
{
	void head_recursive_function(int n) // Recursive call happens at the beginning of the function.
	{
		if(n > 0)
		{
			head_recursive_function(n - 1);

			cout<<n<<" ";
		}
	}
}

namespace iteration
{
	void head_recursion_function(int n) // Equivalent iterative version.
	{
		int i {1};

		while(i <= n)
		{
			cout<<i<<" ";

			i++;
		}
	}
}

int main()
{
	cout<<"head_recursive_function(3) [recursion]: ";
	recursion::head_recursive_function(3);
	cout<<"\n";

	cout<<"head_recursive_function(3) [iteration]: ";
	iteration::head_recursion_function(3);
	cout<<"\n";

	return 0;
}