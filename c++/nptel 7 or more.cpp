#include<iostream>
using namespace std;

int isDuplicatePresentInKDistance(int arr[], int n, int k){

	
		

		for (int i = 0; i <n- 1; i++) {
			int j = i + 1;
			int repetitions = 0;

			// Check for next k elements
			while (repetitions < k && j < n) {
				if (arr[i] == arr[j]) {
				
					return 1;
				}
				repetitions++;
				j++;
			}
		}
		return 0;
	}



 
int main ()
{
    int arr[50]; int n,k,m;
    cin >> n;
    cin >> k;
    for(int i;i<n;++i)
    {
    	cin >> arr[i];
	}
    
   m=isDuplicatePresentInKDistance(arr, n, k);
     if(m==1)
        cout << "Yes";
    else
        cout << "No";
}
