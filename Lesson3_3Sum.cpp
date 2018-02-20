/*
3Sum
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.
For example, given array S = [-1, 0, 1, 2, -1, -4],
A solution set is:
[   [-1, 0, 1],    [-1, -1, 2]   ]

*/
#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#include<set>
using namespace std;
vector< pair<int, pair<int, int> > > tripletsum(int arr[],int len)
{
	sort(arr,arr+len);
	vector< pair<int, pair<int, int> > > v;
	int j,k;
	set<string> s;
	for(int i=0;i<len-2;++i)
	{
		j=i+1;
		k=len-1;
		while(j<k)
		{
			if(arr[i]+arr[j]+arr[k]==0)
			{
				string str="";
				str+=(arr[i]-'0');
				str+=':';
				str+=(arr[j]-'0');
				str+=':';
				str+=(arr[k]-'0');
				if(s.find(str)==s.end())
				{
					v.push_back(make_pair(arr[i], make_pair(arr[j], arr[k])));
					s.insert(str);
				}
				
				++j;
				--k;
			}
			else
			if(arr[j]+arr[k]+arr[i]>0)
			{
				--k;
			}
			else
			{
				++j;
			}
				
		}
	}
	return v;
}

int main()
{
	
	int len,flag;
	cout<<"Enter the length of array:";
	cin>>len;
	if(len<=2)
	{
		cout<<"\nNo such triplet";
	}
	else
	{
		int arr[len];
		cout<<"\nEnter the elements of the array:";
		for(int i=0;i<len;++i)
		{
			cin>>arr[i];
		}
		vector< pair<int, pair<int,int> > > v;
		v=tripletsum(arr,len);
		cout<<"\nThe triplets are:";
		int s=v.size();
		for(int i=0;i<s;++i)
		{
			cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second;
			cout<<endl;
		}
		
		
	}
	return 0;
}
