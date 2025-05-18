#include "word_query.h"
#include "query.h"

namespace Query{

Query::Query(const std::string& word): Query(std::shared_ptr<Query_base>(std::make_shared<WordQuery>(word))){}
// Query::Query(const std::string& word): Query(static_cast<std::shared_ptr<Query_base>>(std::make_shared<WordQuery>(word))){}
    
SprQueryRes
Query::eval(const TextQuery &tq)const{
    return this->_pbase->eval(tq);
}

std::string
Query::rep(void)const{
    return this->_pbase->rep();
}

Query::Query(std::shared_ptr<Query_base> pbase): _pbase(pbase){}

}// !namespace Query
