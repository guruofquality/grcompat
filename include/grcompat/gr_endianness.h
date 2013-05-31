//This module is more serious than the other ones

#ifndef GNURADIO_GR_ENDIANESS_H
#define GNURADIO_GR_ENDIANESS_H

#include <gnuradio/endianness.h>

typedef gr::endianness_t gr_endianness_t;

static const gr_endianness_t GR_MSB_FIRST = gr::GR_MSB_FIRST;
static const gr_endianness_t GR_LSB_FIRST = gr::GR_LSB_FIRST;

#endif //GNURADIO_GR_ENDIANESS_H

#WARNING GR-COMPAT REQUIRED TO COMPILE - OUTDATED GNURADIO API IN USE - PLEASE UPDATE YOUR MODULE!!!

