#include<iostream>
#include<limits.h>
 
using namespace std;
 
// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
void Parenthesis(int i, int j, int n ,int* s) 
{ 
    
    // If only one matrix left in current segment 
    if (i == j) 
    { 
        cout << "A"<<i; 
        return; 
    } 
  
    cout << "("; 
  
    // Recursively put brackets around subexpression from i to bracket[i][j]. 
    // Note that "*((bracket+i*n)+j)" is similar to bracket[i][j] 
    Parenthesis(i,*((s+i*n)+j),n,s); 
  
    // Recursively put brackets around subexpression from bracket[i][j] + 1 to j. 
    Parenthesis(*((s+i*n)+j) + 1,j,n,s); 
    cout << ")"; 
} 

void MatrixChainMultiplication(int p[], int n)
{
    int m[n][n];
    int s[n][n];
    int i, j, k, Length, q;
 
    for (i=1; i<n; i++)
        m[i][i] = 0;    	//number of multiplications are 0(zero) when there is only one matrix
 
    //Here Length is chain length. It varies from length 2 to length n.
    for (Length=2; Length<n; Length++)
    {
        for (i=1; i<n-Length+1; i++)
        {
            j = i+Length-1;
            m[i][j] = INT_MAX;  //assigning to maximum value
 
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];      
                if (q < m[i][j])
                {
                	s[i][j]=k;
                    m[i][j] = q;    //if number of multiplications found less that number will be updated.
                }
            }
        }
    } 
     
	cout << "Optimal Parenthesization is : "; 
    Parenthesis(1, n-1,n,(int *) s); 
    cout<<endl;
    cout<<"The minimum number of multiplication operations required to multiply the matrix chain is "<<m[1][n-1];
    	
    
    
 
}
 
int main()
{
    int n,i;
    cout<<"Enter the number of matrices in the chain(greater than 1) : ";
    cin>>n;
 
    n++;
 
    int arr[n];

    cout<<"Enter the order array of the matrix chain ("<<n<<" elements) : "<<endl;
 
    for(i=0;i<n;i++)
    {
        cout<<"Enter P"<<i<<" : ";
        cin>>arr[i];
    }
 
    int size = sizeof(arr)/sizeof(arr[0]);
 
    MatrixChainMultiplication(arr, size);
 
    return 0;
}
