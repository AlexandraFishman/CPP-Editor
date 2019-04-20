#include <vector>
#include <string>

using namespace std;
class Document
{
  public:
    vector<string> documentLines;

    Document()
    {
        this->documentLines = {"qwe", "edc", "asd", "VERY funnnnnyyyynynynynynyy", "fgfgdfbf","fcjj","3"};
    }

    void gotP(int currentLine);
};