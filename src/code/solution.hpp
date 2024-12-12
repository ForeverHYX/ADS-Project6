/*
Reference: https://cgi.csc.liv.ac.uk/~epa/surveyhtml.html
*/
#pragma once

#include <vector>
#include <map>
#define ull unsigned long long

using namespace std;

// Comparator function to sort rectangles by decreasing height, and by increasing width if heights are equal
bool cmp_1(const pair<ull, ull>& a, const pair<ull, ull>& b){
    if (a.second != b.second){
        return a.second > b.second; // Sort by decreasing height
    }
    else{
        return a.first < b.first; // If heights are equal, sort by increasing width
    }
}

// First-Fit Decreasing Height algorithm
ull first_fit_decreasing_height(vector<pair<ull, ull> > arr_rect, ull width){
    sort(arr_rect.begin(), arr_rect.end(), cmp_1); // Sort rectangles
    ull total_height = 0;

    vector<ull> layer; // Array to keep track of remaining space in each layer

    while(!arr_rect.empty()){
        auto t = arr_rect[0];
        arr_rect.erase(arr_rect.begin()); // Take the first rectangle
        bool be_placed = false;
        for(ull i = 0; i < layer.size(); ++i){
            if(layer[i] >= t.first){ // Check if the rectangle can fit in the current layer
                layer[i] -= t.first; // Place the rectangle and update the remaining space
                be_placed = true;
                break;
            }
        }
        if(!be_placed){ // If the rectangle couldn't fit in any existing layer
            layer.push_back(width - t.first); // Create a new layer
            total_height += t.second; // Update the total height
        }
    }

    return total_height;
}

// Next-Fit Decreasing Height algorithm
ull next_fit_decreasing_height(vector<pair<ull, ull> > arr_rect, ull width){
    sort(arr_rect.begin(), arr_rect.end(), cmp_1); // Sort rectangles
    ull total_height = 0;
    ull remaining_width = 0; // Variable to keep track of the remaining width in the current layer

    while(!arr_rect.empty()){
        auto t = arr_rect[0];
        arr_rect.erase(arr_rect.begin()); // Take the first rectangle
        if(remaining_width >= t.first){ // If the rectangle can fit in the current layer's remaining width
            remaining_width -= t.first; // Update the remaining width
        }
        else{ // If it doesn't fit, start a new layer
            total_height += t.second; // Update the total height
            remaining_width = width - t.first; // Set the remaining width for the new layer
        }
    }

    return total_height;
}

// Best-Fit Decreasing Height algorithm
ull best_fit_decreasing_height(vector<pair<ull, ull> > arr_rect, ull width){
    sort(arr_rect.begin(), arr_rect.end(), cmp_1); // Sort rectangles
    ull total_height = 0;

    vector<ull> layer; // Array to keep track of remaining space in each layer

    while(!arr_rect.empty()){
        auto t = arr_rect[0];
        arr_rect.erase(arr_rect.begin()); // Take the first rectangle
        ull min_remaining = 0xffffffff; // Initialize to a large number to find the best fit
        long long place = -1; // Variable to store the index of the best fit layer
        for(ull i = 0; i < layer.size(); ++i){
            if(layer[i] >= t.first){ // Check if the rectangle can fit in the current layer
                ull remaining = layer[i] - t.first; // Calculate the remaining space after placing the rectangle
                if(remaining < min_remaining){ // Update the best fit if the current layer has less remaining space
                    min_remaining = remaining;
                    place = i;
                }
            }
        }
        if(place == -1){ // If no best fit was found, create a new layer
            layer.push_back(width - t.first);
            total_height += t.second; // Update the total height
        }
        else{ // Place the rectangle in the best fit layer
            layer[place] -= t.first;
        }
    }

    return total_height;
}