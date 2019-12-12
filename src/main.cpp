//
// Created by NouiliKh on 12.12.19.
//

#include <algorithm> // std::replace
#include <cstring>
#include "main.h"
#include "read_csv.cpp"
#include "bag_of_words.cpp"

int main() {

    // Reading CSV file and store it inside a vector
    Read_CSV csvReader;
    // Access attributes and set values
    csvReader.fileName = "../data/spam.csv";
    // get data
    vector <vector <string>> data = csvReader.readCSV();
    vector <string> label_data ;
    vector <string> message_data ;

    // Data Preprocessing
    // construct a label vector and message vector
    // change labels to: {'ham':0, 'spam':1}
    // &i work with original items and may modify them.
    for (auto &i : data) {
        i[0] = i[0].compare("spam") ? "1" : "0";
        label_data.push_back(i[0]);
        message_data.push_back(i[1]);
    }

    // Bag of words creation
    BagOfWords bagOfWords;
    bagOfWords.message_data = message_data;
    vector<map<string, int>>  bagOfWordsData = bagOfWords.createBagOfWords();

    // test/train split

    int sizeOfData = data.size();
    double splitPercentage = 0.8;
    vector<map<string, int>> X_train(bagOfWordsData.begin(), bagOfWordsData.begin () + (sizeOfData*splitPercentage));
    vector<map<string, int>> X_test(bagOfWordsData.begin()+ (sizeOfData*splitPercentage), bagOfWordsData.end());
    vector <string> y_train(label_data.begin(), label_data.begin () + (sizeOfData*splitPercentage));
    vector <string> y_test(label_data.begin()+ (sizeOfData*splitPercentage), label_data.end());





    return 0;
};