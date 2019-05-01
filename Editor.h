/* Alex Fishman 319451514 */
/* Elad Motzny 204093694 */
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