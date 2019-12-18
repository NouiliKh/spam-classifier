//
// Created by NouiliKh on 12.12.19.
//

#include <cmath>
#include "bayes_theorem.h"

class BayesTheorem
{
public:
    double probability_spam;
    double probability_ham;
    map<string, int> term_frequency_ham;
    map<string, int> term_frequency_spam;
    map<string, double> probability_each_word_ham;
    map<string, double> probability_each_word_spam;
    int sum_tf_idf_spam = 0;
    int sum_tf_idf_ham = 0;

    void fitData(vector<vector<string>> X_train, vector <string> y_train)
    {
        this -> calculate_tfs(X_train, y_train);
        double  spam_count =  count(y_train.begin(), y_train.end(), "1");
        this -> probability_spam = spam_count / y_train.size();
        this -> probability_ham = 1 - probability_spam;

        for (auto [key, val]: this->term_frequency_ham)
        {
            this -> probability_each_word_ham[key] = val / this->term_frequency_ham.size();
        }

        for (auto [key, val]: this->term_frequency_spam)
        {
            this -> probability_each_word_spam[key] = val / this->term_frequency_spam.size();
        }
    }
    
     void calculate_tfs(vector<vector<string>> X_train, vector <string> y_train){

        for (int i=0;i<X_train.size();i++)
        {
            if (y_train[i] == "0")
            {
                for (const auto& j: X_train[i]){
                    this->term_frequency_ham[j] = this->term_frequency_ham.count(j)+1;
                }
            }
            else
            {
                for (const auto& j: X_train[i]){
                    this->term_frequency_spam[j] = this->term_frequency_spam.count(j)+1;
                }
            }
        }
    }

    string classify(vector<string> message)
    {
        double pSpam = 0;
        double pHam = 0;
        for (auto word:message)
        {
            if (  this -> probability_each_word_spam.find(word) ==  this -> probability_each_word_spam.end() ) {
                pSpam -= log(this -> probability_each_word_spam.size());
            } else {
                pSpam += log(this -> probability_each_word_spam[word]);
            }
            if ( this -> probability_each_word_ham.find(word) ==  this -> probability_each_word_ham.end() ) {
                pHam -= log(this -> probability_each_word_ham.size());
            } else {
                pHam += log(this -> probability_each_word_ham[word]);
            }
        }
        return pSpam >= pHam ? "1":"0" ;
    }

    vector <string> predictData(vector<vector<string>> X_test)
    {
        vector <string> y_predicted;
        y_predicted.reserve(X_test.size());
        for (const auto& i:X_test)
        {
            y_predicted.push_back(this -> classify(i));
        }
        return y_predicted;
    }

    double metric(vector <string> y_predicted, vector <string> y_true)
    {
        double true_pos = 0;
        double true_neg = 0;
        double false_pos = 0;
        double false_neg = 0;
        int size = y_predicted.size();

        for (int i=0;i<size;i++)
        {
            if (y_predicted[i] == "1" && y_true[i] =="1")
            {
                true_pos += 1;
            } else if (y_predicted[i] == "0" && y_true[i] =="0") {
                true_neg += 1;
            } else if (y_predicted[i] == "1" && y_true[i] =="0"){
                false_pos += 1;
            }else{
                false_neg += 1;
            }
        }
        double accuracy = (true_pos + true_neg) / size;
        return accuracy;
    }
};