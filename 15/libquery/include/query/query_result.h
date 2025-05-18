#ifndef __QUERY_RESULT_H__
#define __QUERY_RESULT_H__

#include <format>

#include "query_types.h"

namespace Query{
class QueryResult {
    friend 
    std::formatter<QueryResult>;

public:
    QueryResult(const std::string&, SprLineNos, SprLines);

    const std::string& 
    GetWord(void) const;

    const SprLineNos
    GetLineNos(void) const;

    const SprLines
    GetText(void)const;

private:
    std::string _word;
    SprLineNos  _line_nos;
    SprLines    _sp_lines;
};
}// !namespace Query

template<>
struct std::formatter<Query::QueryResult> {
    constexpr auto parse(std::format_parse_context& ctx) {
        return ctx.begin();
    }

    auto format(const Query::QueryResult& qr, std::format_context& ctx) const {
        if(!qr.GetLineNos()){
            return std::format_to(ctx.out(), ">> {} occurs 0 times\n", qr.GetWord());
        }

        std::format_to(ctx.out(), ">> {} occurs {} times\n", qr.GetWord(), qr.GetLineNos()->size());
        for(auto i: *qr._line_nos){
            std::format_to(ctx.out(),"    (line {:>3})  {}\n", i, (*qr._sp_lines.get())[i]);
        }
        return ctx.out();
    }
};

std::ostream&
operator<<(std::ostream&, const Query::QueryResult&);

#endif// !__QUERY_RESULT_H__
