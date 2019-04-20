#include "Editor.h"
#include <iostream>
#include <string>

using namespace std;

Editor::Editor(){
    this->currentLine =0;
    this->d;
}
//for(auto const& value: a) {}
void Editor::loop(){
    string* line=new string();
    while(getline(cin, *line)){
        this->d.documentLines.push_back(line);
        cout << *this->d.documentLines.front() <<endl;
    }
    // while(line.compare("Q") != 0){}
}