//
// Created by NouiliKh on 12.12.19.
//

#include "main.h"
#include "Read_CSV.cpp"

int main() {
    Read_CSV csvReader;
    // Access attributes and set values
    csvReader.fileName = "../data/spam.csv";
    // get data
    vector <vector <string>> data = csvReader.readCSV();

    return 0;
};