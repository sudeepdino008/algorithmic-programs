//1113
//n

#include <iostream>
#include <vector>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

vector< vector<int> > num(15,vector<int>(1,-1));
vector< vector<int> > sum(15,vector<int>(1,-1));

void initialisenum()
{
	num[0][0]=75;
	
	num[1][0]=95;
	num[1].push_back(64);
	
	num[2][0]=17;
	num[2].push_back(47);
	num[2].push_back(82);

	num[3][0]=18;
	num[1].push_back(35);
	num[1].push_back(87);
	num[1].push_back(10);

	num[4][0]=20;
	num[4].push_back(4);
num[4].push_back(82);
num[4].push_back(47);
num[4].push_back(65);

	num[5][0]=19;
num[5].push_back(1);
num[5].push_back(23);
num[5].push_back(75);
num[5].push_back(3);
num[5].push_back(34);

	num[6][0]=88;
num[6].push_back(2);
num[6].push_back(77);
num[6].push_back(73);
num[6].push_back(7);
num[6].push_back(63);
num[6].push_back(67);

	num[7][0]=99;
num[7].push_back(65);
num[7].push_back(4);
num[7].push_back(28);
num[7].push_back(6);
num[7].push_back(16);
num[7].push_back(70);
num[7].push_back(92);

	num[8][0]=41;
num[8].push_back(41);
num[8].push_back(26);
num[8].push_back(56);
num[8].push_back(83);
num[8].push_back(40);
num[8].push_back(80);
num[8].push_back(70);
num[8].push_back(33);


	num[9][0]=41;
num[9].push_back(48);
num[9].push_back(72);
num[9].push_back(73);
num[9].push_back(47);
num[9].push_back(32);
num[9].push_back(47);
num[9].push_back(16);
num[9].push_back(94);
num[9].push_back(29);

	num[10][0]=53;
num[10].push_back(71);
num[10].push_back(44);
num[10].push_back(65);
num[10].push_back(25);
num[10].push_back(43);
num[10].push_back(91);
num[10].push_back(52);
num[10].push_back(97);
num[10].push_back(51);
num[10].push_back(14);


	num[11][0]=70;
num[11].push_back(11);
num[11].push_back(33);
num[11].push_back(28);
num[11].push_back(77);
num[11].push_back(73);
num[11].push_back(17);
num[11].push_back(78);
num[11].push_back(39);
num[11].push_back(68);
num[11].push_back(17);
num[11].push_back(57);

	num[12][0]=91;
num[12].push_back(71);
num[11].push_back(52);
num[11].push_back(38);
num[11].push_back(17);
num[11].push_back(14);
num[11].push_back(91);
num[11].push_back(43);
num[11].push_back(58);
num[11].push_back(50);
num[11].push_back(27);
num[11].push_back(29);
num[11].push_back(48);

	num[13][0]=63;
num[13].push_back(66);
num[11].push_back(4);
num[11].push_back(68);
num[11].push_back(89);
num[11].push_back(53);
num[11].push_back(67);
num[11].push_back(30);
num[11].push_back(73);
num[11].push_back(16);
num[11].push_back(69);
num[11].push_back(87);
num[11].push_back(40);
num[11].push_back(31);

	num[14][0]=4;
num[14].push_back(62);
num[11].push_back(98);
num[11].push_back(27);
num[11].push_back(23);
num[11].push_back(9);
num[11].push_back(70);
num[11].push_back(98);
num[11].push_back(73);
num[11].push_back(93);
num[11].push_back(38);
num[11].push_back(53);
num[11].push_back(60);
num[11].push_back(4);
num[11].push_back(23);




}

void initialisesum()
{
	lld i,j;
	loop(i,1,14)
	{
		loop(j,2,i)
			sum[i].push_back(-1);
	}
}

int main()
{
	
	lld i,j;
	vector<int> solution;
	solution.push_back(0);
	initialisenum();
	initialisesum();
	sum[0][0]=num[0][0];
	loop(i,1,14)
	{
		loop(j,0,i)
		{
			if(j==0)
			{
				sum[i][0]=sum[i-1][0];
				solution.push_back(0);
			}
			else if(j==i)
			{
				sum[i][j]=sum[i-1][j-1];
				solution.push_back(j-1);
			}
			else
			{
				if(sum[i-1][j-1]>sum[i-1][j+1])
				{
					sum[i][j]=sum[i-1][j-1];
					solution.push_back(j-1);
				}
				else
				{
					sum[i][j]=sum[i-1][j+1];
					solution.push_back(j+1);
				}
				
			}
			sum[i][j]+=num[i][j];
		}
	}
	lld max=-1;
	solution.push_back(-1);
	loop(i,0,14)
	{
		if(max<sum[14][i])
		{
			max=sum[14][i];
			solution[14]=i;
		}
	}
	
	cout<<max<<endl;
	cout<<"\n";
	loop(i,0,14)
		cout<<solution[i]<<endl;
	return 0;
	
}
