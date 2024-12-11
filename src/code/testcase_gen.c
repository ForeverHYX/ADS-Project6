#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, max;
    
    // 获取用户输入
    max=500;
    n=10000;
    FILE *fp=fopen("text.txt","w+");

    // 初始化随机数种子
    srand(time(0));

    for(int j=0;j<100;j++){
    fprintf(fp,"%d %d\n",max,n);
    // 输出 n 个矩形的长和宽
    for (int i = 0; i < n; i++) {
        // 长度可以任意，宽度小于 max
        int length = rand() % max + 1;  
        int width = rand() % max+1;      
        
        fprintf(fp,"%d %d\n",  length, width);
    }
    }
    return 0;
}
