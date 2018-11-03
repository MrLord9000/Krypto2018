#include "FileInput.hpp"

/*========================================================================================
 *  Class constructor - saves the given path to the file, opens it and throws exception if
 *  the path is invalid
 */
FileInput::FileInput(const string &path)
{
    filePath = path; // Set the path

    fileOpened.open(filePath, ios::in); // Open the file

    if( !fileOpened.good() )
    {
        // TODO: Add exception handling the right way
        cout << "Unable to open file " << filePath << ".\n"
                "Fatal Exception - Program will terminate...\n";
        exit(1);
    }
    // TODO - maybe this exception should also call the destructor???
}
//========================================================================================

/* =======================================================================================
 *  loadFile method - loads all the data from a plain text file.
 *  Warning! Every line feed is converted into a space, so that all the data will fit
 *  into a single string.
 */
void FileInput::loadFile(string &plainText)
{
    string line; // Local temporary string variable for holding a single line of text.
    while( !fileOpened.eof() ) // Check if end of file is not reached.
    {
        getline(fileOpened, line);
        plainText += " " + line; // CORRECT THIS! An extra space is inserted before the data.
                                 // This is pretty harmless but should be fixed.
    }
}
// =======================================================================================

void FileInput::closeFile()
{
    fileOpened.close();
}