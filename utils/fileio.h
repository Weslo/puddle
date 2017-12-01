#ifndef UTILS_FILEIO_H_
#define UTILS_FILEIO_H_

namespace utils {
    int ParseFile(const char* filepath, char** contents, unsigned long* length);
} // namespace utils

#endif // UTILS_FILEIO_H_