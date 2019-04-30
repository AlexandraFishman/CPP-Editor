#include "Document.h"
#include <iostream>

using namespace std;

void Document::gotP(int requestedLine)
{
    // cout << requestedLine << endl;
    cout << this->documentLines[requestedLine - 1] << endl;
}
//%this->documentLines.size()

void Document::n(int currentLine){
    cout<< currentLine <<"        " << this->documentLines[currentLine-1]<<endl;
}

void Document::pp(){
    for(int i=0; i < this->documentLines.size(); i++) {
        cout << this->documentLines.at(i) << endl;
    }
}

void Document::i(int& currentLine){
    currentLine--;
    string newLine;
    while(getline(cin,newLine) && newLine.compare(".") != 0){
        if(this->documentLines.size() <= currentLine){
            this->documentLines.push_back(newLine);
        }
        else{
            this->documentLines.insert(this->documentLines.begin()+currentLine,newLine);
        }
        currentLine++;
    }
    currentLine++;
}

void Document::a(int& currentLine){
    string newLine;
    while(getline(cin,newLine) && newLine.compare(".") != 0){
        if(this->documentLines.size() <= currentLine){
            this->documentLines.push_back(newLine);
        }
        else{
            vector <string>::iterator iter = this->documentLines.begin();
            this->documentLines.insert(iter + currentLine , newLine);
        }
        currentLine++; 
    }
}

void Document::c(int& currentLine){
    string newLine;
    while(getline(cin,newLine) && newLine.compare(".") != 0){
        this->documentLines[currentLine - 1] = newLine;
    }
}

void Document::d(int& currentLine){
    this->documentLines.erase(this->documentLines.begin() + currentLine);
    currentLine--;
}

void Document::text(string currentString, int currentLine){
    for(int i = currentLine; i < this->documentLines.size(); i++){//current line -> end
        if(this->documentLines.at(i).find(currentString) != string::npos){
            cout << this->documentLines.at(i) << endl;
        }
    }
    for(int i = 0; i < currentLine; i++){//beginning -> current line
        if(this->documentLines.at(i).find(currentString) != string::npos){
            cout << this->documentLines.at(i) << endl;
        }
    }

}

void Document::replaceOldWithNew(string oldData, string newData, int currentLine){
    // cout << "1" << endl;
    // cout << "currentLine=" << currentLine << endl;
    int check= this->documentLines.at(currentLine).find(oldData);
    // cout << "2" << endl;
        if(check!=-1){
            // cout << "2" << endl;
            this->documentLines.at(currentLine).replace(check,oldData.size(),newData);
            // cout << "3" << endl;
        }
        else{
            cout<<"?"<<endl;
            //exit(0);
        }
}


