#include <iostream>
using namespace std;


typedef struct _mat
{
	int a_p, a_n, a_f;                //power denotes the power of the matrix and a_p(a_(n-1)), a_f(a_(n+1))
}matrix;
int k1,k2,a0,a1;

matrix matrix_multiplication(int n);

int main()
{
	int n;
	cout<<"input n, k1, k2, a0, a1:\n";                         //a_n = k1*a_(n-1)+k2*a_(n+1)
	cin>>n>>k1>>k2>>a0>>a1;
	matrix mn = matrix_multiplication(n);
	cout<<mn.a_p<<endl;
	return 0;
}

matrix matrix_multiplication(int n)
{
	matrix mn;
	if(n==1)
	{
		mn.a_p = a0;
		mn.a_n = a1;
		mn.a_f = k1*a0+k2*a1;
	}
	else if(n%2)
	{
		matrix m1 = matrix_multiplication((n-1)/2);
		mn.a_p = (m1.a_p * m1.a_p)+(m1.a_n * m1.a_n); 
		mn.a_n = (m1.a_f * m1.a_n)+(m1.a_n * m1.a_p); 
		mn.a_f = (m1.a_n * m1.a_n)+(m1.a_f * m1.a_f);
		int temp = mn.a_n;
		mn.a_n = mn.a_f;
		mn.a_f = k1*mn.a_f + k2*temp;
		mn.a_p = temp;
	}
	else
	{
		matrix m1 = matrix_multiplication(n/2);
		mn.a_p = (m1.a_p * m1.a_p)+(m1.a_n * m1.a_n); 
		mn.a_n = (m1.a_f * m1.a_n)+(m1.a_n * m1.a_p); 
		mn.a_f = (m1.a_n * m1.a_n)+(m1.a_f * m1.a_f);
	}
	return mn;
}
