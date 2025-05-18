#include "query_base.h"
#include "query.h"

namespace Query{

BinaryQuery::BinaryQuery(const Query& lhs, const Query& rhs, QueryOperator::Type type)
    : _lhs(lhs), _rhs(rhs), _type(type){}

std::string
BinaryQuery::rep(void) const{
    return "(" + this->_lhs.rep() + " " + QueryOperator::GetStr(this->_type) + " " + this->_rhs.rep() + ")";
}
}// !namespace Query
