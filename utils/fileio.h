#ifndef PUDDLE_UTILS_FILEIO_H_
#define PUDDLE_UTILS_FILEIO_H_

namespace puddle {
namespace utils {
    int ParseFile(const char* filepath, char** contents, unsigned long* length);
}
}

#endif
