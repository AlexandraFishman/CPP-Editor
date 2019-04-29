#include "Document.h"
#include <regex>

class Editor{
public:
    int currentLine;
    Document d;

    Editor();
    void loop();
    void fillingDocument();
};