#include "Incs.hpp"
#include "Encode.hpp"
#include "Encode.cpp"
int main() {
    cout << fixed << setprecision(16);
    string data, in;
    fstream fileIn, fileOut;

    fileIn.open("in.txt", ios::binary | ios::in);

    while (getline(fileIn, data))
        in += data;

    Encode enc;
    enc.buildTable(in);
    enc.printFreq(enc.freq);
    enc.encodeSymbol(in);

    fileIn.close();
    fileOut.open("out.txt", ios::binary | ios::out);
    fileOut << fixed << setprecision(16);

    fileOut << (double)enc.low;
    fileOut.close();
}

