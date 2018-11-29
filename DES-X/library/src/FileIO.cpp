#include "FileIO.hpp"


void FileInput::setPath(const string &path)
{
    filePath = path; // Set the path

    fileOpened.open(filePath, ios::in | ios::out); // Open the file

    if( !fileOpened.good() )
    {
        // TODO: Add exception handling the right way
        cout << "Unable to open file " << filePath << ".\n"
                "Fatal Exception - Program will terminate...\n";
        exit(1);
    }
    // TODO - maybe this exception should also call the destructor???
}

/* =======================================================================================
 *  loadFile method - loads all the data from a plain text file.
 *  
 */
void FileInput::loadFromFile(string &plainText)
{
    string line; // Local temporary string variable for holding a single line of text.
    while( !fileOpened.eof() ) // Check if end of file is not reached.
    {
        getline(fileOpened, line);
        plainText += line + "\n"; 
    }
}
// =======================================================================================

void FileInput::loadNumber(uint64_t &input)
{
    string temp;
    fileOpened >> temp;
    input = stoull(temp);
}

void FileInput::saveToFile(string &what)
{
    fileOpened << what << "\n";
}

void FileInput::closeFile()
{
    fileOpened.close();
}