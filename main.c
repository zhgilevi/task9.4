#include <stdio.h>
#include <stdlib.h>

int main()
{

        printf("vvedite razmer massiva(dva chisla)\n");
    int m,n;
    scanf("%d%d",&m,&n);
    printf("vvedite massiv\n");
    int **a;
    a=(int**)malloc(sizeof(int)*m);
    int* sum_strok;
    sum_strok=(int*)malloc(sizeof(int)*m);
    int cur_sum=1;
    for (int i=0;i<m;i++){
        a[i]=(int*)malloc(sizeof(int)*n);
    }
    for (int i=0;i<m;i++){
            cur_sum=1;
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            cur_sum*=a[i][j];
        }
        sum_strok[i]=cur_sum;
        cur_sum=1;
    }

    for (int i=0;i<m;i++){
        for (int j=0;j<m-i-1;j++){
            if (sum_strok[j]>sum_strok[j+1]){
                int temp=sum_strok[j];
                sum_strok[j]=sum_strok[j+1];
                sum_strok[j+1]=temp;
                int *temp1=a[j];
                a[j]=a[j+1];
                a[j+1]=temp1;
            }
        }
    }
    printf("vozrastanie summ v strokah\n");
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

}
