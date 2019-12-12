//
// Created by NouiliKh on 12.12.19.
//

#include "read_csv.h"
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Read_CSV
{
public:
    string fileName;

    vector <vector <string>> readCSV()
    {
        ifstream infile(this->fileName );
        vector <vector <string> > data;
        while (infile)
        {
            string s;
            if (!getline( infile, s )) break;

            istringstream ss( s );

            vector <string> record;
            int i =0;
            while (i<2)
            {
                string s;
                if (!getline( ss, s, ',' )) break;
                record.push_back( s );
                i += 1;
            }

            data.push_back( record );
        }
        if (!infile.eof())
        {
            cerr << "Fooey!\n";
        }
        data.erase(data.begin());
        return data;
    }
};