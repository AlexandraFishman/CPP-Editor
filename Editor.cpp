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
    regex text(R"(/\w+)");
    while (line.compare("Q") != 0)
    {
        // if (line.compare("a") == 0)
        // {
        //     this->fillingDocument();
        // }

        if (isNumber(line))
        {
            this->currentLine = stoi(line);
            //cout << this->currentLine << endl;
        }

        if ((line).compare("p") == 0)//p function
        {
            this->d.gotP(this->currentLine);

        }
        if((line).compare("%p") == 0){//%p function
            this->d.pp();
        }
        if((line).compare("n") == 0){//n function
            this->d.n(this->currentLine);
        }
        if((line).compare("d") == 0){//d function
            this->d.d(this->currentLine);
        }
        
        if((line).compare("a") == 0){//a function
            this->d.a(this->currentLine);
        }
        if((line).compare("i") == 0){//i function
            this->d.i(this->currentLine);
        }
        if((line).compare("c") == 0){//c function
            this->d.c(this->currentLine);
        }
        if(regex_match(line,text)){// /text function compare line
            string str = line.substr(1);
            this->d.text(str, this->currentLine);
        }

        // cout << *this->d.documentLines.front() <<endl;
        getline(cin, line);
    }
    exit(0);//Q "function"
}

/////////
// for(int i=0; i<this->d.documentLines.size(); i++) {
//     cout << *this->d.documentLines.back() <<endl;
//     this->d.documentLines.pop_back();
// }
///////
