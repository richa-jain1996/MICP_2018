/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. 
Note that the answer must be a substring,
 "pwke" is a subsequence and not a substring.
*/
#include<iostream>
#include<cstring>
using namespace std;

/*BRUTE FORCE APPROACH-O(n^2)
//for each character keep the count of the number the non-repreating characters following it
int longestsub(string s ,int len)
{
	int maxlen=0,curr_count=0;
	//maxlen is the length of the longest substring
	//curr_count records the length of the substring under consideration so far 

	int hash[256]={0};
	//hash is used to check the number of previous occurence of the character
	int j;
	//'j' is used for inner loop
	for(int i=0;i<len;++i)
	{
	//String is considered invalid if it contain spaces
		if(s[i]==' ')
		return -1;
		for(j=i;j<len;++j)
		{
		
		if(hash[s[j]])
		{
			memset(hash,0,sizeof(hash));
			curr_count=0;
			break;
			
		}
		else
		{
			hash[s[j]]=1;
			++curr_count;
			if(curr_count>maxlen)
			maxlen=curr_count;
			
		}
		}
	}
	return maxlen;
}
*/

//OPTIMISED APPROACH-O(n)
int longestsub(string s,int len)
{
	int maxlen=0,curr_count=0,start=0,i=0;
	//maxlen is the length of the longest substring
	//curr_count records the length of the substring under consideration so far 
	//start indicates the beginning position of the substring
	//'i' is used to indicate the index of the string character
	char current;
	//current represents a current character to be checked from the string
	int hash[256]={0};
	//hash is used to check the number of previous occurence of the character
	while(i<len)
	{
		//String is considered invalid if it contain spaces
		if(s[i]==' ')
		return -1;
		
		current=s[i];
		//This condition will remove the repeating characters from the substring
		if(hash[s[i]]==1)
		{
			while(s[start]!=current)
			{
				hash[s[start]]=0;
				++start;
				--curr_count;
			}
			++start;
		}
		//if the condition is false,curr_count is incremented and hash value is set to 1
		else
		{
			hash[s[i]]=1;
			++curr_count;
			if(curr_count>maxlen)
			maxlen=curr_count;
		}
		++i;
	}
	return maxlen;
	
	
}

//TESTING THE CODE
bool testlongestsub()
{
	//test for empty string
	if(longestsub("",0)!=0)
	return false;
	//test for string with no repeating characters
	if(longestsub("abc",3)!=3)
	return false;
	//test for string with special but no repeating characters
	if(longestsub("%&*aA",5)!=5)
	return false;
	//test for string with same characters but different case
	if(longestsub("aAbBcC",6)!=6)
	return false;
	//test for string with spaces
	if(longestsub("abc abc",7)!=-1)
	return false;
	//test for string with all the same characters
	if(longestsub("bbbb",4)!=1)
	return false;
	//test for string with numbers
	if(longestsub("112233",6)!=2)
	return false;
	//test for the given example string
	if(longestsub("pwwkew",6)!=3)
	return false; 
	
}
int main()
{
	string s;
	cout<<"Enter the string:";
	getline(cin,s);
	int len=s.length();
	int ans=longestsub(s,len);
	if(ans==-1)
	cout<<"\nINVALID string!!";
	else
	cout<<"\nThe length of longest subsring without repeating characters is: "<<ans;
	return 0;
}
