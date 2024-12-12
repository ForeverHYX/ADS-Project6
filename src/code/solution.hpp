/*
ref: https://cgi.csc.liv.ac.uk/~epa/surveyhtml.html
*/
#pragma once

#include <vector>
#include <map>
#define ull unsigned long long

using namespace std;

bool cmp_1(const pair<ull, ull>& a, const pair<ull, ull>& b){
    if (a.second != b.second){
        return a.second > b.second;
    }
    else{
        return a.first < b.first;
    }
}

ull first_fit_decreasing_height(vector<pair<ull, ull> > arr_rect, ull width){
    sort(arr_rect.begin(), arr_rect.end(), cmp_1);
    ull total_height;
    total_height = 0;

    vector<ull> layer;

    while(!arr_rect.empty()){
        auto t = arr_rect[0];
        arr_rect.erase(arr_rect.begin());
        bool be_placed = false;
        for(ull i = 0; i < layer.size(); ++i){
            if(layer[i] >= t.first){
                layer[i] -= t.first;
                be_placed = true;
                break;
            }
        }
        if(!be_placed){
            layer.push_back(width - t.first);
            total_height += t.second;
        }
    }

    return total_height;
}


ull next_fit_decreasing_height(vector<pair<ull, ull> > arr_rect, ull width){
    sort(arr_rect.begin(), arr_rect.end(), cmp_1);
    ull total_height;
    total_height = 0;

    ull remaining_width;
    remaining_width = 0;

    while(!arr_rect.empty()){
        auto t = arr_rect[0];
        arr_rect.erase(arr_rect.begin());
        if(remaining_width >= t.first){
            remaining_width -= t.first;
        }
        else{
            total_height += t.second;
            remaining_width = width - t.first;
        }
    }

    return total_height;
}

ull best_fit_decreasing_height(vector<pair<ull, ull> > arr_rect, ull width){
    sort(arr_rect.begin(), arr_rect.end(), cmp_1);
    ull total_height;
    total_height = 0;

    vector<ull> layer;

    while(!arr_rect.empty()){
        auto t = arr_rect[0];
        arr_rect.erase(arr_rect.begin());
        ull min_remainning = 0xffffffff;
        long long place = -1;
        for(ull i = 0; i < layer.size(); ++i){
            if(layer[i] >= t.first){
                ull remainning = layer[i] - t.first;
                if(remainning < min_remainning){
                    min_remainning = remainning;
                    place = i;
                }
            }
        }
        if(place == -1){
            layer.push_back(width - t.first);
            total_height += t.second;
        }
        else{
            layer[place] -= t.first;
        }
    }

    return total_height;
}
