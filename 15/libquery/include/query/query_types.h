#ifndef __QUERY_TYPES_H__
#define __QUERY_TYPES_H__

#include <map>
#include <memory>
#include <set>
#include <vector>

namespace Query{

static constexpr std::string nullstr("");

// spr: line content
using SprLines = std::shared_ptr<std::vector<std::string>>;

// spr: line numeros
using SprLineNos = std::shared_ptr<std::set<int>>;

// spr: word location
using SprWordLoc = std::shared_ptr<std::map<std::string, SprLineNos>>;

// spr: class QueryResult 
using SprQueryRes = std::shared_ptr<class QueryResult>;

class QueryOperator final{
public:
    enum Type{
        QUERY_AND,
        QUERY_OR,
        QUERY_NOT,
    };

    QueryOperator(void) = delete;
    
    inline static std::string
    GetStr(QueryOperator::Type type){
        switch(type){
            case QUERY_AND:{
                static constexpr std::string s_query_and("&");
                return s_query_and;
            }break;
            case QUERY_OR:{
                static constexpr std::string s_query_or("|");
                return s_query_or;
            }break;
            case QUERY_NOT:{
                static constexpr std::string s_query_not("~");
                return s_query_not;
            }break;
            default:{
                return nullstr;
            }
        }
    }
};


}// !namespace Query
#endif// !__QUERY_TYPES_H__
