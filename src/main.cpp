//
// Created by NouiliKh on 12.12.19.
//

#include <algorithm> // std::replace
#include <cstring>
#include "main.h"
#include "read_csv.cpp"
#include "preprocess.cpp"
#include "bayes_theorem.cpp"


int main() {

    // Reading CSV file and store it inside a vector
    Read_CSV csvReader;
    // Access attributes and set values
    csvReader.fileName = "../data/spam.csv";
    // get data
    vector <vector <string>> data = csvReader.readCSV();
    vector <string> label_data ;
    vector <string> message_data ;

    // Data Preprocess
    // construct a label vector and message vector
    // change labels to: {'ham':0, 'spam':1}
    // &i work with original items and may modify them.
    for (auto &i : data) {
        i[0] = i[0].compare("spam") ? "1" : "0";
        label_data.push_back(i[0]);
        message_data.push_back(i[1]);
    }

    // Bag of words creation
    Preprocess preprocess;
    preprocess.message_data = message_data;
    vector<vector<string>> preprocessedData = preprocess.preprocessData();

    // test/train split
    int sizeOfData = data.size();
    double splitPercentage = 0.8;
    vector<vector<string>> X_train(preprocessedData.begin(), preprocessedData.begin () + (sizeOfData * splitPercentage));
    vector<vector<string>> X_test(preprocessedData.begin() + (sizeOfData * splitPercentage), preprocessedData.end());
    vector <string> y_train(label_data.begin(), label_data.begin () + (sizeOfData*splitPercentage));
    vector <string> y_test(label_data.begin()+ (sizeOfData*splitPercentage), label_data.end());

    BayesTheorem model{};
    model.fitData(X_train,y_train);
    vector <string> y_predict = model.predictData(X_test);

    return 0;
};