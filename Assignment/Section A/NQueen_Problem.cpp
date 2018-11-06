#include<iostream>
#include<math.h>
using namespace std;
int total;
void nqueen(int *arr , int n, int k);  // function that uses N queue
bool canplace(int * arr , int k, int i); 	// to check queen can be placed or not.
void display(int*arr , int n);          // displaying different number of solutions
void nqueen(int *arr , int n, int k) 
{
    for (int i = 1; i <= n; i++ )
	{
        if ( canplace(arr , k , i) ) 
		{
            arr[k] = i;
            if (k == n) 
			{
                display(arr , n);
            }
            else 
			{
                nqueen(arr , n , k + 1 );
            }
        }
    }
}
bool canplace(int* arr , int k, int i)
{
    for (int j = 1; j <= k - 1; j++ ) 
	{
        if( arr[j] == i || ( abs(arr[j] - i) == abs(j - k) ) )
            return false;
    }
    return true;
}
void display(int* arr , int n) 
{
    ++total;
    cout << "\n\tPossible Place for Queen " << total << endl;
    cout << "\t--------------------------\n";
    for (int i = 1; i <= n; i++)
	{
        for (int j = 1; j <= n; j++)
		{
            if (arr[i] != j) {
                cout << "\t-";
            }
            else {
                cout << "\tQ";
            }
        }
        cout << endl;
    }
}
int main() 
{
    int n;
    cout << "\nEnter Value of N :  ";
    cin >> n;
    int *arr = new int[n];
    nqueen(arr , n , 1);
    cout << "\nNumber of Solutions are  " << total << endl;
    delete []arr;
    return 0;
}
