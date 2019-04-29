#include <vector>
#include <string>

using namespace std;
class Document
{
  public:
    vector<string> documentLines;

    Document()
    {
        this->documentLines = {};
    }

    void gotP(int currentLine);

    void n(int currentLine);//prints current line (number of line, TAB, the line itself).
    //example: 5    the line
    
    void pp();//prints the entire document

    void i(int& currentLine);//insert a new line before the current line

    void a(int& currentLine);//add new text after the current line until we get . as input
    //DONT KNOW IF WE NEED TO GET SOMETHING IN THE FUNC ITSELF, MAYBE JUST GET cin AND CHECK? Ask Arbel

    void c(int& currentLine);//Changes the current line to newLine

    void d(int& currentLine);//deletes current line, need to get from Editor

    void text(string currentString, int currentLine);//searches for the input from current line all the way to current line again
    //if we reached the end, go to the beginning and search until we reach current line again.
    //maybe need to return something? Ask Arbel or something

    //void Q();//Quit without saving (Arbel said to do exit(0))

};