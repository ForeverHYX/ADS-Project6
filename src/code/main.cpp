#include <iostream>
#include <vector>
#include <map>
#include <time.h>
#include "solution.hpp"
#include "util.hpp"

using namespace std;

ull width_of_bin, height_of_bin, n;
vector<pair<ull, ull> > arr_rect;

int main(){
    clock_t begin,end;
    FILE* fp=fopen("../../testcase/output/text.txt","r");
    if(fp==NULL){
        printf("wrong");
        exit(0);
    }
    fscanf(fp,"%llu",&width_of_bin);
    
    height_of_bin = 0;
    fscanf(fp,"%llu",&n);
    
    for(ull i = 0; i < n; ++i){
        ull width, height;
        fscanf(fp,"%llu %llu",&width,&height);
        pair<ull, ull> tmp;
        tmp.first = width;
        tmp.second = height;
        arr_rect.push_back(tmp);
    }
    begin=clock();
    for(int j=0;j<100;j++){
        cout << "total height of FFDH: " << (height_of_bin = first_fit_decreasing_height(arr_rect, width_of_bin)) << "\n";
    }
    
    end=clock();
    cout << "utilization rate of FFDH: " << calculate_utilization_rate(arr_rect, width_of_bin, height_of_bin) << "\n";
    double runtime_FFDH = (double)(end - begin)*1000 / CLOCKS_PER_SEC;
    
    begin=clock();
    for(int j=0;j<100;j++){
        cout << "total height of NFDH: " << (height_of_bin = next_fit_decreasing_height(arr_rect, width_of_bin)) << "\n";
    }
    end=clock();
    cout << "utilization rate of NFDH: " << calculate_utilization_rate(arr_rect, width_of_bin, height_of_bin) << "\n";
    double runtime_NFDH = (double)(end - begin)*1000 / CLOCKS_PER_SEC;
    
    cout << "total height of BFDH: " << (height_of_bin = best_fit_decreasing_height(arr_rect, width_of_bin)) << "\n";
    cout << "utilization rate of BFDH: " << calculate_utilization_rate(arr_rect, width_of_bin, height_of_bin) << "\n";
    printf("run time of 100 times FFDH is %.6f\n",  runtime_FFDH);
    printf("run time of 100 times NFDH is %.6f\n",  runtime_NFDH);

}