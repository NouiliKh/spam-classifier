//
// Created by NouiliKh on 12.12.19.
//

#include <algorithm> // std::replace
#include <cstring>
#include "main.h"
#include "Read_CSV.cpp"

int main() {

    // Reading CSV file and store it inside a vector
    Read_CSV csvReader;
    // Access attributes and set values
    csvReader.fileName = "../data/spam.csv";
    // get data
    vector <vector <string>> data = csvReader.readCSV();
    vector <string> get = data[0];

    // Data Preprocessing
    // change labels to: {'ham':0, 'spam':1}
    // &i work with original items and may modify them.
    for (auto &i : data) {
        i[0] = i[0].compare("spam") ? "1" : "0";
    }

    return 0;
};