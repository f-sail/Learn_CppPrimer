#ifndef __TEXT_QUERRY_H__
#define __TEXT_QUERRY_H__

#include "query_types.h"

namespace Query{       
class TextQuery{
public:
    TextQuery(const std::string& file_path);

    SprQueryRes
    query(const std::string& word) const;

private:
    void
    Init(const std::string& file_path);

    SprLines   _sp_lines;
    SprWordLoc _sp_word_loc;
};
}// !namespace Query
#endif// !__TEXT_QUERRY_H__
