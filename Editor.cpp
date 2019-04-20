#include "Editor.h"
#include <iostream>
#include <string>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool isNumber(string &s)
{
    return !s.empty() && find_if(s.begin(),
                                 s.end(), [](char c) { return !isdigit(c); }) == s.end();
}

void Editor::fillingDocument()
{
    string line;

    getline(cin, line);
    while ((line).compare(".") != 0)
    {
        this->d.documentLines.push_back(line);
        this->currentLine++;
        cout << this->currentLine << endl;
        getline(cin, line);
    }
}

Editor::Editor()
{
    this->d;
    this->currentLine = this->d.documentLines.size();
}
//for(auto const& value: a) {}
void Editor::loop()
{
    string line;
    getline(cin, line);

    while (line.compare("Q") != 0)
    {
        // if (line.compare("a") == 0)
        // {
        //     this->fillingDocument();
        // }

        if (isNumber(line))
        {
            this->currentLine = stoi(line);
            cout << this->currentLine << endl;
        }

        if ((line).compare("p") == 0)
        {
            this->d.gotP(this->currentLine);

        }
        // cout << *this->d.documentLines.front() <<endl;
        getline(cin, line);
    }
}

/////////
// for(int i=0; i<this->d.documentLines.size(); i++) {
//     cout << *this->d.documentLines.back() <<endl;
//     this->d.documentLines.pop_back();
// }
///////
