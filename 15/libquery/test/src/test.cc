/*
 *     <<Whispers of Time>>
 * The clock’s hands dance, a silent flight,
 * Through dusk and dawn, through day and night.
 * Each tick a step, each tock a sigh—
 * A melody of passing by.
 * The stars above, they never speak,
 * Yet in their light, our hearts do seek
 * A fleeting truth, a borrowed grace,
 * To hold the moment, chase the trace.
 * But seasons turn, and shadows grow,
 * The winds of change begin to blow.
 * What once was near now drifts away—
 * A whisper lost to time’s ballet.
 * Still, in the stillness, hope remains:
 * For every end, a gentle rain
 * That washes sorrow into bloom,
 * And turns our grief to skies of gloom.
 */

#include <iostream>

#include <query/query.h>
#include <query/text_query.h>
#include <query/query_result.h>

int main(void){
    Query::TextQuery tq("../src/test.cc");

    auto display = [&](Query::Query q){
        std::cout << *q.eval(tq) << std::endl;
    };

    display(Query::Query("query"));
    display(Query::Query("in"));
    display(Query::Query("our"));
    display(Query::Query("in") & Query::Query("our"));
    display(Query::Query("in") | Query::Query("our"));
    display(Query::Query("to"));
    display(~Query::Query("to"));
}
