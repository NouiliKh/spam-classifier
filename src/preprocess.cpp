//
// Created by NouiliKh on 12.12.19.
//

#include <map>
#include "preprocess.h"

class Preprocess
{
public:
    vector <string> message_data;
    vector<vector<string>> tokenized;
    vector<vector<string>> preprocessData()
    {

        for (auto &i: this -> message_data){
            // convert messages to lowercase
            transform(i.begin(), i.end(), i.begin(), ::tolower);
            // Remove Punctuation
            i.erase(remove_if(i.begin (), i.end (), ::ispunct), i.end());
            // tokenize
            vector<string> tokens;
            string word;
            istringstream iss(i);
            while (getline(iss, word, ' ')) {
                tokens.push_back(word);
            }
            tokenized.push_back(tokens);

        }
        return this -> tokenized;
    }
};