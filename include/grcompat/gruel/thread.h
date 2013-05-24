//Cant think of anything not perverted atm

#ifndef GRUEL_THREAD_H
#define GRUEL_THREAD_H

#include <boost/thread.hpp>

namespace gruel
{
    typedef boost::thread thread;
    typedef boost::mutex mutex;
    typedef boost::mutex::scoped_lock scoped_lock;
    typedef boost::condition_variable condition_variable;
}

#endif //GRUEL_THREAD_H
