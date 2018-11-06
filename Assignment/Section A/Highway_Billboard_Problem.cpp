#include<iostream>
using namespace std;


int Max_Revenue(int billboard[],int revenue[],int distance,int n)
{
	int dyn[n];
	dyn[0] = revenue[0];
	for (int i = 1; i < n; i++) 
	{
		int j;
		int Max_Revenue = 0;
		for (j = 0; j < i; j++) 
		{
			if (billboard[i] - billboard[j] > 5) 
			{
				if (Max_Revenue < dyn[j]) 
				{
					Max_Revenue = dyn[j];
                }
            }
        }
		dyn[i] = Max_Revenue + revenue[i];
    }

	int max=dyn[0];
	for(int i=0;i<n;i++)
	{
    	if(dyn[i]>max)
    	{
        	max=dyn[i];
    	}
	}
	return max;
}
    
int main()
{
    int n,distance;
    cout<<"Enter the maximum number of available sites : "<<endl;
   	cin>>n;
        
	cout<<"Total distance of University road available:"<<endl;
    cin>>distance;
    
    int billboard[n],revenue[n];
    cout<<"Specify each site position along the roads (measured in miles from its western end)"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>billboard[i];
    }
    cout<<"Enter Revenue generated from each site"<<endl;
    for(int i=0;i<n;i++)
    {
       cin>>revenue[i];
    }
        
    cout<<"Maximum revenue that can be generated is : "<<maxRevenue(billboard,revenue,distance,n);
}
    
