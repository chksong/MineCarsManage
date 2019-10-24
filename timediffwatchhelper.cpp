#include "timediffwatchhelper.h"


#include <iostream>

TimeDiffWatchHelper::TimeDiffWatchHelper(std::string& strHint)
    :mStrHint(strHint)
{
     std::cout <<  "TimeDiffWatchHelper(&)" << std::endl   ;
     start_point  =  std::chrono::high_resolution_clock::now()  ;
}

TimeDiffWatchHelper::TimeDiffWatchHelper(std::string&& strHint)
    :mStrHint(std::move(strHint))
{
    std::cout <<  "TimeDiffWatchHelper(&&)" << std::endl   ;
    start_point  =  std::chrono::high_resolution_clock::now()  ;
}

//template <typename T>
TimeDiffWatchHelper::TimeDiffWatchHelper(const std::initializer_list<string>& v)
{
    for (auto item : v) {
          std::cout << " ** " << item << std::endl ;
    }
    start_point  =  std::chrono::high_resolution_clock::now()  ;
}

TimeDiffWatchHelper::~TimeDiffWatchHelper()
{
    using namespace  std::chrono ;
    auto endTime =  std::chrono::high_resolution_clock::now()  ;
    auto diff    =  duration_cast<milliseconds>(endTime -start_point).count() ;

    std::cout << std::string(mStrHint  +  "  [TimeDiff] =   ")  << diff << std::endl   ;
}
