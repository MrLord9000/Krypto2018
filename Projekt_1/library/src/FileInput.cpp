#include "FileInput.hpp"

FileInput::FileInput(const string &path)
{
    filePath = path;
}

void FileInput::loadFile(string &plainText)
{
    fileOpened.open(filePath, ios::in);

    if( fileOpened.good() )
    {
        string line;
        while( !fileOpened.eof() )
        {
            getline(fileOpened, line);
            plainText += " " + line;
        }
    }
    else
    {
        // TODO: Add exception handling the right way
        cout << "Unable to open file " << filePath << ".\n"
                "FATAL EXCEPTION - PROGRAM WILL TERMINATE\n";
        exit(1);
    }
}

void FileInput::closeFile()
{
    //cout << "\nClosing file...";
    fileOpened.close();
}