#pragma once

#include <vector>
#include <map>
#include "tetromeno.hpp"
#define ull unsigned long long

using namespace std;

// Function to calculate the utilization rate of rectangles within a given area
double calculate_utilization_rate(const vector<pair<ull, ull> >& arr_rect, ull width, ull height){
    // If the total area (width * height) is zero, return utilization rate as 0
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
double calculate_utilization_rate(const vector<Tetromeno> arr_tetromeno, ull width, ull height){
    // If the total area (width * height) is zero, return utilization rate as 0
    if(width * height == 0){
        return 0;
    }
    ull x, y;
    x = 0;
    for(auto i:arr_tetromeno){
        // cout << i.size() << endl;
        x += i.size();
    }
    y = width * height;
    // cout << x << y << endl;
    return (static_cast<double>(x)) / (static_cast<double>(y));

}
