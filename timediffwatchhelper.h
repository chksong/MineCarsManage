#ifndef TIMEDIFFWATCHHELPER_H
#define TIMEDIFFWATCHHELPER_H

#include <string>
#include <chrono>


using std::string ;

class TimeDiffWatchHelper
{
public:
    TimeDiffWatchHelper() = delete;
    explicit  TimeDiffWatchHelper(std::string& strHint) ;
    explicit  TimeDiffWatchHelper(std::string&& sttrHint ) ;


 //   template <typename T>
    explicit  TimeDiffWatchHelper(const std::initializer_list<string>& v) ;

    ~TimeDiffWatchHelper() ;
private:
    std::string mStrHint ;
    std::chrono::high_resolution_clock::time_point start_point ;
};

#endif // TIMEDIFFWATCHHELPER_H
