#include <fstream>
#include <sstream>

#include "query_result.h"
#include "text_query.h"

namespace Query{       

TextQuery::TextQuery(const std::string& file_path){
    this->_sp_lines = std::make_shared<std::vector<std::string>>();
    this->_sp_word_loc = std::make_shared<std::map<std::string, SprLineNos>>();
    this->_sp_lines->push_back(file_path);

    this->Init(file_path);
}

SprQueryRes
TextQuery::query(const std::string& word) const{
    return std::make_shared<QueryResult>(word, (*this->_sp_word_loc)[word], this->_sp_lines);
}

void
TextQuery::Init(const std::string& file_path){
    std::ifstream ifs(file_path);
    std::string line;
    int curr_line_no = 1;

    while(getline(ifs, line)){
        this->_sp_lines->push_back(line);

        std::istringstream iss(line);
        std::string word;

        while(iss >> word){
            SprLineNos& sp_line_nos = (*this->_sp_word_loc)[word];
            sp_line_nos ? (void)sp_line_nos->insert(curr_line_no) : sp_line_nos.reset(new std::set<int>{curr_line_no});
        }

        ++curr_line_no;
    }

    ifs.close();
}
}// !namespace Query
