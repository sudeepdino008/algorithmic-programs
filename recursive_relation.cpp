/* Solve any recursive relation like a_n = n1*a_(n-1)+n2*a_(n-2) in log(n) time by using the matrix multipication technique 

 As an example, lets solve a_n = 2*a_(n-1) + 3*a_(n-2) with a0 = 1, a1 = 2, a2=7 (1,2,7,20,61,....)

   consider the matrix [f(n+1) f(n) | f(n) f(n-1)] = [2 1 | 3 0]^n   where | denote vertical split */

#include <iostream>
#define MAX_SIZE 100
using namespace std;

typedef struct relation
{
	int fn1, fn, fn0;                // fn1, fn and fn0 are the f(n+1), f(n) and f(n-1) term respectively
}relation;

relation matrix[MAX_SIZE];

void calculate_nth_term(int n, bool max_n);

int main()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
		matrix[i].fn1 = matrix[i].fn = matrix[i].fn0 = -1;
	calculate_nth_term(n,true);
	cout<<"The nth term is:"<< matrix[n].fn0 <<endl;
	return 0;
}

void calculate_nth_term(int n, bool max_n)
{

	if(matrix[n].fn1 != -1)
		return;
	else
	{
		int k = n/2;
		calculate_nth_term(k, false);
		int k1 =  matrix[k].fn1*matrix[k].fn1 + matrix[k].fn*matrix[k].fn;
		int k2 =  matrix[k].fn1*matrix[k].fn  + matrix[k].fn*matrix[k].fn0;
		int k3 =  matrix[k].fn*matrix[k].fn   + matrix[k].fn0*matrix[k].fn0;
		if(n%2==0)
		{
			matrix[n].fn1 = 2*k1 + 3*k2;
			matrix[n].fn  = 2*k2 + k3;
			matrix[n].fn0 = k2;
		}
		else
		{
			matrix[n].fn1 = matrix[k].fn1*matrix[k].fn1 + matrix[k].fn*matrix[k].fn;
			matrix[n].fn  = matrix[k].fn1*matrix[k].fn  + matrix[k].fn*matrix[k].fn0;
			matrix[n].fn0 = matrix[k].fn*matrix[k].fn   + matrix[k].fn0*matrix[k].fn0;

		}
		cout<< n <<" "<<matrix[n].fn1 <<" "<<matrix[n].fn <<" "<<matrix[n].fn0<<endl;
		if(max_n)
		{
			matrix[n].fn1 = 7*matrix[n].fn1 + 2*matrix[n].fn;
			matrix[n].fn  = 2*matrix[n].fn1 + matrix[n].fn;
			matrix[n].fn1 = 2*matrix[n].fn  + matrix[n].fn0;
		}
	}
}


