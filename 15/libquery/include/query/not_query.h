#ifndef __NOT_QUERY_H__
#define __NOT_QUERY_H__

#include "query_types.h"
#include "query_base.h"

namespace Query{
class NotQuery final: public Query_base{
    friend Query
    operator~(const Query&);

public:
    ~NotQuery(void) override = default;
    NotQuery(const Query&);

private:
    SprQueryRes
    eval(const TextQuery&)const override;

    std::string
    rep(void)const override;

    const Query& _q;
};
}// !namespace Query
#endif// !__NOT_QUERY_H__
