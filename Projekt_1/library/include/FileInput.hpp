#ifndef FileInput_hpp
#define FileInput_hpp

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class FileInput
{
private:
    string filePath;
    fstream fileOpened;

public:
    FileInput(const string &path);
    void loadFile(string &plainText);
    void closeFile();
};


#endif //FileInput_hpp