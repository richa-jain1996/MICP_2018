/*Word Break
Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words.
For example, consider the following dictionary: { pear, salmon, foot, prints, footprints, leave, you, sun, girl, enjoy },

Examples:
Given the string “youenjoy”, 
Output: True (The string can be segmented as “you enjoy”)

Input: “youleavefootprints”,
Output: True (The string can be segmented as “you leave footprints” or “you leave foot prints”)

Input:salmonenjoyapples
Output: False
*/
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
bool findword(string word,vector<string> dict)
{
	for(int i=0;i<dict.size();++i)
	{
		if(!(dict[i].compare(word)))
			return true;
	}
	return false;
	
}
bool wordbreak(string str,vector<string> dict)
{
	int strlen,dictlen;
	strlen=str.size();
	dictlen=dict.size();
	if(strlen==0)
		return true;
	if(dictlen==0)
		return false;
	int dp[strlen+1]={0};
	
	//An array to store the results of the subproblem
	for(int i=1;i<=strlen;++i)
	{
		if((dp[i]==0) && (findword(str.substr(0,i),dict)))
		{
			dp[i]=1;
			
		}
		if(dp[i]==1)
		{
			if(i==(strlen))
				return true;
			for(int j=i+1;j<=strlen;++j)
			{
				if((dp[j]==0) && (findword(str.substr(i,j-i),dict)))
				{
					dp[j]=1;
					
					
				}	
				if((dp[j]) && (j==strlen))
					return true;
			}
		}
	}
	return false;
}

/*TEST CASES */
bool t1()
{
	//String is empty
	string arr[] = {"abc"};
    vector<string> dict(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (wordbreak("",dict)!=1) return false;
}
bool t2()
{
	//Dictionary is empty
	string arr[] = {""};
    vector<string> dict(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (wordbreak("abc",dict)!=0) return false;
}
bool t3()
{
	//String can be segmented
	string arr[] = {"hello","richa","jain"};
    vector<string> dict(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (wordbreak("richajain",dict)!=1) return false;
}
bool t4()
{
	//String cannot be segmented
	string arr[] = {"abc","richa"};
    vector<string> dict(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (wordbreak("richajain",dict)!=0) return false;
}
bool t5()
{
	//String contains repetitive words 
	string arr[] = {"hello","i","am","repeating"};
    vector<string> dict(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (wordbreak("hellohello",dict)!=1) return false;
}
bool testWordBreak()
{
	
	if(t1() && t2() && t3() && t4() && t5())
		return true;
	return false;
}

int main()
{
	string str,temp;
	vector<string> dict;
	int lendict;
	cout<<"Enter the string:";
	getline(cin,str);
	cout<<"\nEnter the size of dictionary:";
	cin>>lendict;
	cout<<"\nEnter the words in the dictionary:";
	for(int i=0;i<lendict;++i)
	{
		cin>>temp;
		dict.push_back(temp);
	}
	cout<<"\nInput string can be segmented(True/False):";
	bool ans=wordbreak(str,dict);
	if(ans)
		cout<<"true";
	else
		cout<<"false";
	
	
	return 0;
}
