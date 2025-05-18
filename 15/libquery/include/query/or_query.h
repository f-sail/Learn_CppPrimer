#ifndef __OR_QUERY_H__
#define __OR_QUERY_H__

#include "query_types.h"
#include "query_base.h"

namespace Query{
class OrQuery final: public BinaryQuery{
    friend Query
    operator|(const Query&, const Query&);

public:
    ~OrQuery(void) override = default;
    OrQuery(const Query&, const Query&);

private:
    SprQueryRes
    eval(const TextQuery&)const override;
};
}// !namespace TextQueryk
#endif// !__OR_QUERY_H__
