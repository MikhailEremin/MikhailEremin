#include <stdlib.h>
#include <stdio.h>
#define SIZE 64

struct mnv{
    int tnum;
    int raz;
    int dnum[SIZE];
};
int main(){
struct mnv num[SIZE];
int i=0, n=0, d=0, vnum;

while(d==0){
    num[n].raz=0;
    vnum=0;
    scanf("%d", &vnum);
    num[n].tnum=vnum;
    if(vnum==-1){
        d=1;
        break;
    }
    while (vnum != 0){
        i=num[n].raz;
        if (vnum % 2 == 0){
            num[n].dnum[i] = 0;
            vnum /= 2;
        }else{
            num[n].dnum[i] = 1;
            vnum /= 2;
        }
        num[n].raz++;
    }
     num[n].raz-= 1;
 n++;
 }
int k=0;
for(k;k<n;k++){
    printf("%10d = ",num[k].tnum);
    for(i=num[k].raz;i>=0;i--){
        printf("%d",num[k].dnum[i]);
    }
    printf("\n");
}
    return 0;
}
