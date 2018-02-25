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
vector<vector<int> > tripletsum(vector<int> arr,int len)
{
	sort(arr.begin(),arr.end());
	vector<vector<int> > v;
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
					vector<int> temp;
					temp.push_back(arr[i]);
					temp.push_back(arr[j]);
					temp.push_back(arr[k]);
					v.push_back(temp);
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
//test cases
bool t1() {
	//Size of the vector less than 3
	int arr[] = {1,2};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (tripletsum(nums,2).size()!=0) return false;
}
bool t2() {
	//All positives
	int arr[] = {1,2,3};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (tripletsum(nums,3).size()!=0) return false;
}
bool t3() {
	//All negatives
	int arr[] = {-1,-2,-3};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (tripletsum(nums,3).size()!=0) return false;
}
bool t4() {
	//All zeroes
	int arr[] = {0, 0, 0, 0};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (tripletsum(nums,4).size()!=1) return false;
}
bool t5() {
	//Only one triplet 
	int arr[] = {-1, 2, -1};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (tripletsum(nums,3).size()!=1) return false;
}
bool t6() {
	//More than 1 triplet(with repeating triplets as well) 
	int arr[] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (tripletsum(nums,3).size()!=2) return false;
}

    
bool test() {
	if (t1() && t2() && t3() && t4() && t5() && t6())
    return true;
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
		vector<int> vec;
		cout<<"\nEnter the elements of the array:";
		for(int i=0;i<len;++i)
		{
			cin>>arr[i];
			vec.push_back(arr[i]);
		}
		vector<vector<int> > v;
		v=tripletsum(vec,len);
		cout<<"\nThe triplets are:";
		int s=v.size();
		for(int i=0;i<s;++i)
		{
			cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2];
			cout<<endl;
		}
		
		
	}
	test();
	return 0;
}
