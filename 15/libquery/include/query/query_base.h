#ifndef __QUERY_BASE_H__
#define __QUERY_BASE_H__

#include "query_types.h"

namespace Query{
class TextQuery;
class Query;

class Query_base{
    friend Query;
public:
    virtual
    ~Query_base(void) = default;

protected:
    virtual SprQueryRes
    eval(const TextQuery&)const = 0;

    virtual std::string
    rep(void)const = 0;
};

class BinaryQuery: public Query_base{
public:
    ~BinaryQuery(void) override = default;

protected:
    BinaryQuery(const Query&, const Query&, QueryOperator::Type);

    std::string
    rep(void) const override;

    const Query& _lhs;
    const Query& _rhs;
    QueryOperator::Type _type;
};
}// !namespace Query
#endif// !__QUERY_BASE_H__
