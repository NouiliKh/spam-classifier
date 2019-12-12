//
// Created by NouiliKh on 12.12.19.
//

#include <map>
#include "bag_of_words.h"

class BagOfWords
{
public:
    vector <string> message_data;
    void toLowerCaseAndWithoutPunctuation()
    {
        for (auto &i: this -> message_data){
            // convert messages to lowercase
            transform(i.begin(), i.end(), i.begin(), ::tolower);
            // Remove Punctuation
            i.erase(remove_if(i.begin (), i.end (), ::ispunct), i.end());

            vector<string> tokens;
            istringstream iss(i);


        }
    };


    vector<map<string, int>>  createBagOfWords()
    {
        vector<vector<string>> tokenized;
        vector<map<string, int>> bagOfWorded;

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
            // Get counter
            map<string, int> counter ;
            for (auto j: tokens){
                int counting = count(tokens.begin(), tokens.end(), j);
                counter [j] = counting;
            }
            bagOfWorded.push_back(counter);
        }
        return bagOfWorded;
    }
};