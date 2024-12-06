#include<stdio.h>
struct martix{
    int width;
    int high;
};
int main(){
    struct martix one[10000];
    int n;
    int width;
    scanf("%d",&width);
    scanf("%d",&n);
    
    for (int i=0;i<n;i++){
        scanf("%d",&one[i].high);
        scanf("%d",&one[i].width);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(one[i].high<one[j].high){
                struct martix temp;
                temp=one[i];
                one[i]=one[j];
                one[j]=temp;
            }
        }
    }
    int totalhight=0;
    int now_width=0;
    int flag=1;
    for (int i=0;i<n;i++){
        if(flag){
            flag=0;
            totalhight+=one[i].high;
            now_width=one[i].width;
        }else {
        if(now_width+one[i].width<=width){
            
            now_width+=one[i].width;

        }else{
            totalhight+=one[i].high;
            now_width=one[i].width;
        }
    }
    }
    printf("%d",totalhight);
}