#include "not_query.h"
#include "query_result.h"
#include "query.h"

namespace Query{
Query
operator~(const Query& q){
     return static_cast<std::shared_ptr<Query_base>>(std::make_shared<NotQuery>(q));
}

NotQuery::NotQuery(const Query& q): _q(q){}

SprQueryRes
NotQuery::eval(const TextQuery& tq)const{
    SprQueryRes sp_res = this->_q.eval(tq);

    SprLineNos sp_nos(std::make_shared<std::set<int>>());
    for(size_t i = 1; i < sp_res->GetText()->size(); ++i){
        if(!sp_res->GetLineNos()->count(i)){
            sp_nos->insert(i);
        }
    }
    return std::make_shared<QueryResult>(this->rep(), sp_nos, sp_res->GetText());
}

std::string
NotQuery::rep(void)const{
    return "~(" + this->_q.rep() +")";
}
}// !namespace Query
