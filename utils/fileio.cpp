#include <fstream>
#include <stdlib.h>
#include "fileio.h"

// Parse the file at filepath and fill contents and length.
int utils::ParseFile(const char* filepath, char** contents, unsigned long* length) {

    // Open a filestream.
    std::ifstream file;
    file.open(filepath, std::ios::in);
    if(!(file && file.good())) {
        return -1;
    }

    // Calculate the length of the file.
    unsigned long len = file.tellg();
    file.seekg(0, std::ios::end);
    len = file.tellg();
    file.seekg(std::ios::beg);
    if(len == 0) {
        return -2;
    }

    // Allocate a buffer to store the data.
    char* buffer = new char[len + 1];
    buffer[len] = 0;
    
    // Read contents into buffer.
    unsigned int i = 0;
    char c;
    while(file.good()) {
        file.get(c);
        buffer[i] = c;
        if(!file.eof()) {
            i++;
        }
    }
    buffer[i] = 0;

    // Success!
    *contents = buffer;
    *length = len;
    file.close();
    return 0;
}