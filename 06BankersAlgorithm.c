#include <stdio.h>

int pow(int a,int n) {
	int x=1,i;
	for ( i=0 ; i<n ; i++ ) {
		x *= a;
	}
	return x;
}

int main() {
	int alloc[10][10],need[10][10],max[10][10],avail[10],n_proc,n_res,i,j,x,stat=0;
	printf("Enter number of processes : ");
	scanf("%d",&n_proc);
	printf("Enter number of resources : ");
	scanf("%d",&n_res);
	printf("Enter allocation matrix : ");
	for ( i=0 ; i<n_proc ; i++ ) {
		for ( j=0 ; j<n_res ; j++ ) {
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("Enter max matrix : ");
	for ( i=0 ; i<n_proc ; i++ ) {
		for ( j=0 ; j<n_res ; j++ ) {
			scanf("%d",&max[i][j]);
		}
	}
	for ( i=0 ; i<n_proc ; i++ ) {
                for ( j=0 ; j<n_res ; j++ ) {
			need[i][j] = max[i][j] - alloc[i][j];
                }
        }
	printf("Enter available resources : ");
	for ( i=0 ; i<n_res ; i++ ) scanf("%d",&avail[i]);
	printf("Enter starting process : ");
	scanf("%d",&x);
	while ( 1 ) {
		for ( i=0 ; i<n_res ; i++ ) {
			if ( avail[i]<need[x][i] ) {
				printf("System not in safe state\n");
				return 0;
			} else {
				avail[i]+=alloc[x][i];
			}
		}
		stat |= pow(2,x);
		printf("%d = stat",stat);
		if ( stat == pow(2,n_proc)-1 ) break;
		else {
			for ( i=0 ; i<n_proc ; i++ ) {
				if ( (stat & pow(2,i)) == 0 ) {
					//Check whether need is less than available
					x = i;
					break;
				}
			}
			if ( i==n_proc ) break;
		}
	}
	printf("System in safe state\n");
	return 0;
}
