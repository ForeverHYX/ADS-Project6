#pragma once

#include <vector>
#include <map>
#define ull unsigned long long

using namespace std;

double calculate_utilization_rate(const vector<pair<ull, ull> >& arr_rect, ull width, ull height){
    if(width * height == 0){
        return 0;
    }
    ull x, y;
    x = 0;
    for(auto rect:arr_rect){
        x += rect.first * rect.second;
    }
    y = width * height;
    return (static_cast<double>(x)) / (static_cast<double>(y));

}