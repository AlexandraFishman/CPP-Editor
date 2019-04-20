#include "Document.h"
#include <iostream>

using namespace std;

void Document::gotP(int requestedLine)
{
    // cout << requestedLine << endl;
    cout << this->documentLines[requestedLine - 1] << endl;
}
//%this->documentLines.size()