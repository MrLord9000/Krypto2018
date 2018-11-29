#ifndef FileInput_hpp
#define FileInput_hpp

#include <fstream>
#include <string>

#include "Misc.hpp"

using namespace std;

class FileInput
{
private:
    string filePath;
    fstream fileOpened;

public:
    FileInput(const string &path) { setPath(path); }
    void setPath(const string &path);
    void loadFromFile(string &plainText);
    void loadNumber(uint64_t &input);
    void saveToFile(string &what);
    void closeFile();
};


#endif //FileInput_hpp