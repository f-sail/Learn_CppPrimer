#ifndef __WORD_QUERY_H__
#define __WORD_QUERY_H__

#include "query_types.h"
#include "query_base.h"

namespace Query{
class Query;

class WordQuery final: public Query_base{
    friend Query;

public:
    ~WordQuery(void) override = default;

    WordQuery(const std::string&);

private:
    SprQueryRes
    eval(const TextQuery&)const override;

    std::string
    rep(void)const override;

    std::string _word;
};
}// !namespace Query
#endif// !__WORD_QUERY_H__
