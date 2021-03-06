//
// Created by Richard Flores on 4/15/2017.
// miss-used the [][] grid operator

#include <iostream>
#include "../stanflib/include/grid.h"
using namespace std;

void fixCounts(Grid<bool> & in, Grid<short> & out);

int main() {
    // can work with any boolean grid, but using sample one from problem
    Grid<bool> in{ {1,0,0,0,0,1},{0,0,0,0,0,1},{1,1,0,1,0,1},{1,0,0,0,0,0},{0,0,1,0,0,0},{0,0,0,0,0,0} };
    Grid<short> out(in.width(), in.height());
    cout << "Original Grid:\n";
    cout << in.toString2D() << endl;
    cout << "New grid with number of true's in each grid neighborhood:\n";
    fixCounts(in, out);
    cout << out.toString2D();
    return 0;
}
// counts how many true's in neighborhood for each grid point
void fixCounts(Grid<bool> & in, Grid<short> & out) {
    for (short j = 0; j < in.height(); j++) {
        for (short i = 0; i < in.width(); i++) {
            if (in[i][j] == true) {
                out[i][j] += 1;
            }
            if (j - 1 >= 0) {
                if (in[i][j - 1] == true) {
                    out[i][j] += 1;
                }
            }
            if (j + 1 < in.height()) {
                if (in[i][j + 1] == true) {
                    out[i][j] += 1;
                }
            }
            if (i - 1 >= 0) {
                if (in[i - 1][j] == true) {
                    out[i][j] += 1;
                }
                if (j - 1 >= 0) {
                    if (in[i - 1][j - 1] == true) {
                        out[i][j] += 1;
                    }
                }
                if (j + 1 < in.height()) {
                    if (in[i - 1][j + 1] == true) {
                        out[i][j] += 1;
                    }
                }
            }
            if (i + 1 < in.width()) {
                if (in[i + 1][j] == true) {
                    out[i][j] += 1;
                }
                if (j - 1 >= 0) {
                    if (in[i + 1][j - 1] == true) {
                        out[i][j] += 1;
                    }
                }
                if (j + 1 < in.height()) {
                    if (in[i + 1][j + 1] == true) {
                        out[i][j] += 1;
                    }
                }
            }
        }
    }
}