#include<stdio.h>
int main(){
    int bangdiem[2][3] = {
            {3,4,5},
            {7,8,9}
    }; for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%d ", bangdiem[i][j]);
        };
        printf("\n");
    };
}