#include "Document.h"
#include <iostream>

using namespace std;

void Document::gotP(int requestedLine)
{
    // cout << requestedLine << endl;
    cout << this->documentLines[requestedLine - 1] << endl;
}
//%this->documentLines.size()

void Document::n(int currentLine){//NTT
    cout<< currentLine <<"    " << this->documentLines[currentLine] <<endl;
}

void Document::pp(){//NTT
    for(auto& it : this->documentLines) {
        cout << it << endl;
    }
}

//void Document::i(int currentLine){}//use insert

void Document::a(int& currentLine){//NTT
    string newLine;
    getline(cin,newLine);
    while(newLine.compare(".") != 0){
        this->documentLines.push_back(newLine);
        currentLine++;
        getline(cin,newLine);
    }
}

//void Document::c(int currentLine){}//use swap

void Document::d(int& currentLine){//NTT
    this->documentLines.erase(this->documentLines.begin() + currentLine -1);//MAYBE NEED TO DO WITHOUT -1
    currentLine--;
}

//void Document::text(int currentLine){}//maybe use reverse iterator and regular iterator?
//like if we use regular iterator until the end and we didnt find the string, use reverse iterator to go from currentLine to the beginning

/*
void Document::Q(){//NTT
    exit(0);
}*/

