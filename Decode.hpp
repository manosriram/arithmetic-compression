#pragma once

#include "Incs.hpp"

class Decode {
    public:

        void decodeSymbol(map<char, int> freq, double finalOut, map<char, pair<double, double> > rangeTable);
        pair<char, double> findRangeSymbol(map<char, int> freq, double finalOut, map<char, pair<double, double> > rangeTable);
        

};
