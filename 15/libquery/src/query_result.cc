#include "query_result.h"


std::ostream&
operator<<(std::ostream& os, const Query::QueryResult& rhs){
    return os << std::format("{}",rhs);
}
namespace Query{

QueryResult::QueryResult(const std::string& word, SprLineNos line_nos, SprLines sp_lines)
    :_word(word),_line_nos(line_nos),_sp_lines(sp_lines){}

const std::string& 
QueryResult::GetWord(void) const{
    return this->_word;
}

const SprLineNos
QueryResult::GetLineNos(void) const{
    return this->_line_nos;
}

const SprLines
QueryResult::GetText(void)const{
    return this->_sp_lines;
}

}// !namespace Query
