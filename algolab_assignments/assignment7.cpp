#include <iostream>
#include <sstream>                  //required to interconvert string and int

using namespace std;

string kmp_pattern(string text, string pattern);            
int string_to_int(string s);
string int_to_string(int n);
string kmp_matching(string text, string pattern);
void failure_array_computation(int failure[], string pattern);

int main()
{
	int n=0,i;
	string text, pattern;
	cout<<"\t\t\t********* STRING MATCHING\n";
	getline(cin, text);
	getline(cin, pattern);
	string result = kmp_matching(text,pattern);
	for(i=0;i<int(result.length());i++)
	{
		if(result[i] == ' ')                          //the number of spaces in result string gives the number of matches.
			n++;
	}
	if(result[0]=='-' && result[1]=='1')
		cout<<"no match found\n";
	else
		cout<< n <<" matches found at indices  "<<result<<endl;



	cout<<"\t\t\t********* PATTERN MATCHING\n";
	n=0;
	getline(cin, text);
	getline(cin, pattern);
	result = kmp_pattern(text, pattern);
	for(i=0;i<int(result.length());i++)
	{
		if(result[i] == ')')                         //the number of closing braces gives the number of pairs
			n++;
	}
	if(result[0]=='-' && result[1]=='1')            //no result if -1 is returned
		cout<<"no match found\n";
	else
		cout<< n <<" pattern matches at index pairs "<<result<<endl;  
	return 0;
}


string kmp_matching(string text, string pattern)
{
	int tlen = text.length();
	int plen = pattern.length();
	string combined = pattern+"2"+text;
	string s="";
	int i;
	int clen = tlen+plen+1;
	if(tlen<plen)
		return "-1";
	int failure[clen+1];
	failure_array_computation(failure, combined);          //failure array computed and stored in failure index
	for(i=0;i<=clen;i++)
	{
		if(failure[i]==plen)
			s+=" "+int_to_string(i-2*plen);                  //if failure[i]==plen => we have found a improper border
	}
	
	if(s.empty())
		return "-1";
	return s;
}

void failure_array_computation(int failure[], string string)
{
	int slen = string.length();
	int i=1, j=0;                                      //i related to prefix and j related to suffix
	failure[0] = 0;
	while(i<=slen)
	{
		if(string[i]==string[j])
		{
			failure[i] = j + 1;
			j++;
			i++;
		}
		else if(j!=0)
		{
			j=failure[j-1];
		}
		else
		{
			failure[i] = 0;
			i++;
			
		}
		/*if(string[i]=='2')
		  {failure[i] = 0;j=0;}*/
		
	}
	/*for(i=0;i<=slen;i++)
		cout<<failure[i]<<" ";*/
}


string int_to_string(int n)
{
	stringstream ss;
	ss << n;
	return ss.str();
}

string kmp_pattern(string text, string pattern)
{
	string result1, result2, pattern1, pattern2;
	int i,j;
	string result="";
	int plen=pattern.length();
	for(i=0;i<plen;i++)
	{
		if(pattern[i]=='*')
			break;
	}
	pattern1 = pattern.substr(0,i);
	pattern2 = pattern.substr(i+1);
	result1 = kmp_matching(text, pattern1);
	result2 = kmp_matching(text, pattern2);
	//cout<<"r: "<<result1<<" "<<result2<<endl;
	if((result2[0]=='-' && result2[1]=='1') ||( result1[0]=='-' && result1[1]=='1'))
		return "-1";
	else
	{
		int array1[50]={-1}, c1=0;
		int array2[50]={-1}, c2=0;
		string num="",result="";
		result1+=" ";
		result2+=" ";
		//now we compute and store the indexes of matches of patter1 and pattern2 in text.
		for(i=0;i<int(result1.length());i++)
		{
			if(result1[i]==' ')
			{
				
				if(i!=0)
					array1[c1++] = string_to_int(num);
				num = "";
			}
			else
				num+=result1[i];
		}
	   
		for(i=0;i<int(result2.length());i++)
		{
			if(result2[i]==' ')
			{
				
				if(i!=0)
					array2[c2++] = string_to_int(num);
				num = "";
			}
			else
				num+=result2[i];
		}

		
		result="";
		for(i=0;i<c1;i++)
		{
			for(j=0;j<c2;j++)
			{
				if(array1[i]<array2[j])           //if lergal pair(x>y), then store in the result array which will be later returned.
					result+= "  ("+int_to_string(array1[i])+ " ,"+int_to_string(array2[j])+")";
			}
			//cout<<result<<" h\n";
		}
	   
	return result;	
	}

}

int string_to_int(string s)
{
	istringstream buffer(s);
	int value;
	buffer>>value;
	return value;
}
