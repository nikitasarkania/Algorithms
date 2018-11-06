#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;
	
bool isSubSeq(vector<string> s1, vector<string> s2)
{
		
	int j = 0;
	 
	for(int i=0; i<s2.size() && j<s1.size(); i++)
	{	    //Traverse s2 and s1
	
			if(s1[j].compare(s2[i]) == 0)				//Compare current event of s2 with first unmatched char of s1
				j++;									//if matched then move ahead in s1 (matching is case sensitive)
	}
		
	return ( j==s1.size() ); // Return true, if all events of s1 were found in s2 in same order 
}
	
int main(){
		
	vector<string>	s1, s2;
	
	cout<<"\n\nEnter Sequence 1\n ";
	while(true){
		
		string mid_string;
		cout<<"\nEnter next String : ";
		cin>>mid_string;
		if(mid_string.compare("-1") == 0)		//to stop taking input in sequence 1
			break;
		s1.push_back(mid_string);
	}
	
	cout<<"\n\nEnter Sequence 2\n ";
	while(true){
		string mid_string;
		cout<<"\nEnter next String: ";	
		cin>>mid_string;
		if(mid_string.compare("-1") == 0)		//to stop taking input in sequence 2
			break;
		s2.push_back(mid_string);
	}
		
	if( isSubSeq(s1, s2))							// isSubsequence returns 'TRUE' if s1 is  subsequence of s2.
		cout<<"\n\nYes, sequence 1 is a subsequence of sequence 2.";
	else
		cout<<"\n\nNo, sequence 1 is not a subsequence of sequence 2.";
			
	return 0;
}
