//Well ladiefuckingdah

#ifndef GNURADIO_GR_MESSAGE_H
#define GNURADIO_GR_MESSAGE_H

#include <gnuradio/message.h>

typedef gr::message gr_message;
typedef gr::message::sptr gr_message_sptr;

static inline gr_message_sptr gr_make_message(long type = 0, double arg1 = 0, double arg2 = 0, size_t length = 0)
{
    return gr::message::make(type, arg1, arg2, length);
}

static inline gr_message_sptr gr_make_message_from_string(const std::string s, long type = 0,
                                 double arg1 = 0, double arg2 = 0)
                                 {
                                     
    return gr::message::make_from_string(s, type, arg1, arg2);
                                 }

#endif //GNURADIO_GR_MESSAGE_H

#warning GR-COMPAT REQUIRED TO COMPILE - OUTDATED GNURADIO API IN USE - PLEASE UPDATE YOUR MODULE!!!

