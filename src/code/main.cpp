#include <iostream>
#include <vector>
#include <map>
#include "solution.hpp"
#include "util.hpp"
#include "tetromeno.hpp"

using namespace std;

ull width_of_bin, height_of_bin, n;
vector<pair<ull, ull> > arr_rect;
vector<Tetromeno> arr_tetromeno;

#define SEED 1394912749131344081

int main(){
    cin >> width_of_bin;
    height_of_bin = 0;
    cin >> n;
    for(ull i = 0; i < n; ++i){
        ull width, height;
        cin >> width >> height;
        pair<ull, ull> tmp;
        tmp.first = width;
        tmp.second = height;
        arr_rect.push_back(tmp);
    }
    cout << "total height of FFDH: " << (height_of_bin = first_fit_decreasing_height(arr_rect, width_of_bin)) << "\n";
    cout << "utilization rate of FFDH: " << calculate_utilization_rate(arr_rect, width_of_bin, height_of_bin) << "\n";

    cout << "total height of NFDH: " << (height_of_bin = next_fit_decreasing_height(arr_rect, width_of_bin)) << "\n";
    cout << "utilization rate of NFDH: " << calculate_utilization_rate(arr_rect, width_of_bin, height_of_bin) << "\n";

    cout << "total height of BFDH: " << (height_of_bin = best_fit_decreasing_height(arr_rect, width_of_bin)) << "\n";
    cout << "utilization rate of BFDH: " << calculate_utilization_rate(arr_rect, width_of_bin, height_of_bin) << "\n";


    for(ull i = 0; i < n; ++i){
        arr_tetromeno.push_back(gen_tetromeno_from_ull(SEED));
    }

    cout << "total height of BFDH (tetromeno): " << (height_of_bin = best_fit_decreasing_height(gen_arr_rect_from_arr_tetromeno(arr_tetromeno), width_of_bin)) << "\n";
    cout << "utilization rate of BFDH (tetromeno): " << calculate_utilization_rate(n, width_of_bin, height_of_bin) << "\n";
}