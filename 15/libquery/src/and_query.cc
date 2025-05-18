#include <algorithm>

#include "query.h"
#include "query_result.h"
#include "and_query.h"

namespace Query{
Query
operator&(const Query& lhs, const Query& rhs){
    return static_cast<std::shared_ptr<Query_base>>(std::make_shared<AndQuery>(lhs, rhs));
}

AndQuery::AndQuery(const Query& lhs, const Query& rhs)
    :BinaryQuery(lhs, rhs, QueryOperator::QUERY_AND){}

SprQueryRes
AndQuery::eval(const TextQuery& tq)const{
    SprQueryRes sp_lres = this->_lhs.eval(tq);
    SprQueryRes sp_rres = this->_rhs.eval(tq);
    
    SprLineNos sp_nos(std::make_shared<std::set<int>>());
    std::set_intersection(
        sp_lres->GetLineNos()->begin(), sp_lres->GetLineNos()->end(),
        sp_rres->GetLineNos()->begin(), sp_rres->GetLineNos()->end(),
        std::inserter(*sp_nos, sp_nos->begin())
    );
    return std::make_shared<QueryResult>(this->rep(), sp_nos, sp_lres->GetText());
}
}// !namespace Queryk
