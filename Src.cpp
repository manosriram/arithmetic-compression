#include "Incs.hpp"
#include "Encode.hpp"
#include "Encode.cpp"
int main() {
    cout << fixed << setprecision(16);
    string data = "Hello world this is mano sriram qsdjlasj ljaj ajldsa";

    Encode enc;
    enc.buildTable(data);
    enc.printFreq(enc.freq);
    enc.encodeSymbol(data);
}

