#ifndef __AND_QUERY_H__
#define __AND_QUERY_H__

#include "query_types.h"
#include "query_base.h"

namespace Query{
class AndQuery final: public BinaryQuery{
    friend Query
    operator&(const Query&, const Query&);

public:
    ~AndQuery(void) = default;
    AndQuery(const Query&, const Query&);

private:
    SprQueryRes
    eval(const TextQuery&)const override;
};
}// !namespace Queryk
#endif// !__AND_QUERY_H__
