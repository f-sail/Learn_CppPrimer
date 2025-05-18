#ifndef __QUERY_H__
#define __QUERY_H__

#include "query_types.h"

namespace Query{
class TextQuery;
class Query_base;

class Query final{
    friend Query
    operator~(const Query&);

    friend Query
    operator&(const Query&, const Query&);

    friend Query
    operator|(const Query&, const Query&);

public:
    ~Query(void) = default;
    Query(const std::string&);
    
    SprQueryRes
    eval(const TextQuery &tq)const;

    std::string
    rep(void)const;

private:
    Query(std::shared_ptr<Query_base>);

    std::shared_ptr<Query_base> _pbase;
};
}// !namespace Query
#endif// !__QUERY_H__
