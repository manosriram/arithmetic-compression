#pragma once

#include "Incs.hpp"

class Encode {
    public:

        int buffer, bitsInBuffer;
        double low, high;
        int underflowBits;
        map<char, pair<double, double> > cumulativeOut;
        map<char, int> freq;

        Encode(void);
        ~Encode(void);

        void encodeSymbol(string data);
        void endEncode();
        void writeBit(int bit);
        void outputBit(int bit);
        void printTable(map<char, pair<double, double> > cumulativeOut);
        void buildTable(string data);
        void printFreq(map<char, int> freq);
        void writeTable(fstream& fileTable);
};
