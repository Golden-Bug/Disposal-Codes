#include<stdio.h>
struct Activity {
	char id[5];
	int start;
	int finish;
};

void activitySelection(Activity activities[], int n);


int main()
{
    int s[50] ;
    int f[50] ;
    int m;
    scanf("%d",&m);
    int k= 2*m;
    for(int i=0;i<k;++i)
    {
    	scanf("%d",&s[i]);
    	
	}
/*	 for(int i=0;i<n;++i)
    {
    	scanf("%d",&f[i]);
    	
	} */
    //n = sizeof(s)/sizeof(s[0]);
    //printf("%d",n);
    activitySelection(s,k);
    return 0;
}

void activitySelection(Activity activities[], int n) {
	//variables
	int i, j;
   int count=0;
	Activity temp;

	//step 1
	//sort the activities as per finishing time in ascending order
	for(i = 1; i < n; i++) {
		for(j = 0; j < n - 1; j++){
			if(activities[j].finish > activities[j+1].finish) {
				temp = activities[j];
				activities[j] = activities[j+1];
				activities[j+1] = temp;
			}
		}
	}

	//sorted
	//printf("Sorted activities as per finish time (ascending order)\n");
	//printf("%10s %10s %10s\n", "Activity", "Start", "Finish");
  //	for(i = 0; i < n; i++) {
	//	printf("%10s %10i %10i\n", activities[i].id, activities[i].start, activities[i].finish);
	//}

	//step 2
	//select the first activity
	//printf("-----Selected Activities-----\n");
	//printf("%10s %10s %10s\n", "Activity", "Start", "Finish");
//	printf("%10s %10i %10i\n", activities[0].id, activities[0].start, activities[0].finish);

	//step 3
	//select next activity whose start time is greater than
	//or equal to the finish time of the previously selected activity
	i = 0;
	count=1;
	for(j = 1; j < n; j++) {
		if(activities[j].start >= activities[i].finish) {
		//	printf("%10s %10i %10i\n", activities[j].id, activities[j].start, activities[j].finish);
		count++;
			i = j;
		}
	}
	printf("%d",count);
}

