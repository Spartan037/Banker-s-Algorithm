// Banker's Algorithm
#include <stdio.h>
int main()
{
	int n, m, i, j, k;
	printf("Enter the number of processes:");
	scanf("%d", &n);
	printf("\nEnter the number of resources:");
	scanf("%d", &m);
	int alloc[n][m], max[n][m], avail[m];
	printf("\nEnter the allocation matrix:");
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			scanf("%d", &alloc[i][j]);
	printf("\nEnter the MAX matrix:");
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			scanf("%d", &max[i][j]);
	printf("\nEnter available resources:");
	for (i=0; i<m; i++)
		scanf("%d", &avail[i]);
	
	printf("\nThe Allocated Resource Table:\n");
    	for (i=0; i<n; i++) 
	{
		for (j=0; j<m; j++) 
			printf("\t%d", alloc[i][j]);
        	printf("\n");
    	}
 
    	printf("\nThe Maximum Table:\n");
    	for (i=0; i<n; i++) 
    	{
        	for (j=0; j<m; j++) 
			printf("\t%d", max[i][j]);
        	printf("\n");
    	}
 
    	printf("\nAvailable resources:");
    	for (i=0; i<m; i++) 
       	printf("\t%d", avail[i]);
    	printf("\n");
	int f[n], ans[n], ind=0;
	for (k=0; k<n; k++) 
		f[k] = 0;
	int need[n][m];
	for (i=0; i<n; i++) 
		for (j=0; j<m; j++)
			need[i][j] = max[i][j]-alloc[i][j];
	int y=0;
	for (k=0; k<5; k++) 
	{
		for (i=0; i<n; i++) 
		{
			if (f[i]==0) 
			{
				int flag = 0;
				for (j=0; j<m; j++) 
				{
					if (need[i][j]>avail[j])
					{
						flag = 1;
						break;
					}
				}

				if (flag==0) 
				{
					ans[ind++] = i;
					for (y=0; y<m; y++)
						avail[y] += alloc[i][y];
					f[i]=1;
				}
			}
		}
	}

	printf("SAFE Sequence is:\n");
	for (i=0; i<n-1; i++)
		printf(" P%d ->", ans[i]);
	printf(" P%d", ans[n-1]);
	printf("\n");
	return (0);
}

