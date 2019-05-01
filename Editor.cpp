/* Alex Fishman 319451514 */
/* Elad Motzny 204093694 */
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
    regex sOldNew(R"(s/\w+/\w+/?)");
    while (line.compare("Q") != 0)
    {

        if (isNumber(line))
        {
            this->currentLine = stoi(line);
            cout << this->d.documentLines[this->currentLine - 1] << endl;
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

        if(regex_match(line, sOldNew)){
            string originalInput=line.substr(2);
            int find1 =originalInput.find("/");
            string first= originalInput.substr(0,find1);
            int find2=originalInput.rfind("/");
            string second;
            if(find2==find1){
                second= originalInput.substr(find1+1);
            }
            else{
                second= originalInput.substr((find1+1),find2-find1-1);
            }
            this->d.replaceOldWithNew(first,second,this->currentLine-1);
}
        getline(cin, line);
    }
    exit(0);//Q "function"
}