#pragma once

#include <iostream>
#include <cstdlib>
#include <unordered_set>
#include <vector>
#include <map>

using namespace std;

#define ull unsigned long long
#define MAX_SIZE 1000
struct Tetromeno{
    int matrix[MAX_SIZE][MAX_SIZE];

    Tetromeno(){
        for(ull w = 0; w < MAX_SIZE; ++w){
            for(ull h = 0; h < MAX_SIZE; ++h){
                matrix[w][h] = 0;
            }
        }
    }

    ull size(){
        ull ret = 0;
        for(ull w = 0; w < MAX_SIZE; ++w){
            for(ull h = 0; h < MAX_SIZE; ++h){
                if(matrix[w][h] != 0){
                    ++ret;
                }
            }
        }
        return ret;
    }

    void print(){

        for(ull w = 0; w < MAX_SIZE; ++w){
            for(ull h = 0; h < MAX_SIZE; ++h){
                if(matrix[w][h] == 0){
                    cout << '.';
                }
                else{
                    cout << '+';
                }
            }
            cout << '\n';
        }
    }

    ull get_width(){
        ull width = 0;
        for(ull w = 0; w < MAX_SIZE; ++w){
            bool flag = false;
            for(ull h = 0; h < MAX_SIZE; ++h){
                if(matrix[h][w]){
                    flag = true;
                    break;
                }
            }
            if(flag){
                ++width;
            }
        }

        return width;
    }
    ull get_hight(){
        ull hight = 0;
        for(ull h = 0; h < MAX_SIZE; ++h){
            bool flag = false;
            for(ull w = 0; w < MAX_SIZE; ++w){
                if(matrix[h][w]){
                    flag = true;
                    break;
                }
            }
            if(flag){
                ++hight;
            }
        }

        return hight;
    }

};

Tetromeno gen_tetromeno_from_ull(ull seed){
    Tetromeno ret;
    srand(static_cast<unsigned int>(seed));
    // int i = 0;
    while (ret.size() < MAX_SIZE) {
        size_t row = rand() % MAX_SIZE;
        size_t col = rand() % MAX_SIZE;

        pair<size_t, size_t> tmp;
        tmp.first = row;
        tmp.second = col;
        
        // placed.insert(tmp);
        
        ret.matrix[row][col] = 1;
        // ++i;
    }

    return ret;
}

vector<pair<ull, ull> > gen_arr_rect_from_arr_tetromeno(const vector<Tetromeno>& src){
    vector<pair<ull, ull> > ret;
    for(auto i:src){
        pair<ull, ull> tmp;
        tmp.first = i.get_width();
        tmp.second = i.get_hight();
        ret.push_back(tmp);
    }
    return ret;
}

bool can_combine(const Tetromeno& x, const Tetromeno& y){
    for(ull w = 0; w < MAX_SIZE; ++w){
        for(ull h = 0; h < MAX_SIZE; ++h){
            if(x.matrix[w][h] == 1 && y.matrix[w][h] == 1){
                return false;
            }
        }
    }
    return true;
}

Tetromeno combine(const Tetromeno& x, const Tetromeno& y){
    Tetromeno ret;

    for(ull w = 0; w < MAX_SIZE; ++w){
        for(ull h = 0; h < MAX_SIZE; ++h){
            if(x.matrix[w][h] == 1 || y.matrix[w][h] == 1){
                ret.matrix[w][h] = 1;
            }
        }
    }
    return ret;
}

void combine_arr_tetromeno_once(vector<Tetromeno>& vec){
    for(auto i = vec.begin() + 1; i != vec.end(); ++i){
        bool flag = can_combine(*i, *vec.begin());
        if(flag){
            vec[0] = combine(*i, *vec.begin());
            vec.erase(i);
        }
    }
}