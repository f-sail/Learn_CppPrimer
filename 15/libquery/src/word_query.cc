#include "word_query.h"
#include "text_query.h"

namespace Query{
WordQuery::WordQuery(const std::string& word): _word(word){}

SprQueryRes
WordQuery::eval(const TextQuery& tq)const{
    return tq.query(this->_word);
}

std::string
WordQuery::rep(void)const{
    return this->_word;
}
}// !namespace Query
