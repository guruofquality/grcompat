//Oh look, a good use of my time and effort

#ifndef GNURADIO_GR_IO_SIGNATURE_H
#define GNURADIO_GR_IO_SIGNATURE_H

#include <gnuradio/io_signature.h>

typedef gr::io_signature gr_io_signature;

static inline gr_io_signature::sptr gr_make_io_signature(int min_streams, int max_streams,
                     int sizeof_stream_item)
                     {
                        return gr::io_signature::make(min_streams, max_streams, sizeof_stream_item);
                     }

static inline gr_io_signature::sptr gr_make_io_signature2(int min_streams, int max_streams,
                  int sizeof_stream_item1,
                  int sizeof_stream_item2)
                  {
                        return gr::io_signature::make2(min_streams, max_streams, sizeof_stream_item1, sizeof_stream_item2);
                  }

static inline gr_io_signature::sptr gr_make_io_signature3(int min_streams, int max_streams,
                  int sizeof_stream_item1,
                  int sizeof_stream_item2,
                  int sizeof_stream_item3)
                  {
                        return gr::io_signature::make3(min_streams, max_streams, sizeof_stream_item1, sizeof_stream_item2, sizeof_stream_item3);
                  }

static inline gr_io_signature::sptr gr_make_io_signaturev(int min_streams, int max_streams,
                      const std::vector<int> &sizeof_stream_items)
                      {
                        return gr::io_signature::makev(min_streams, max_streams, sizeof_stream_items);
                      }

#endif //GNURADIO_GR_IO_SIGNATURE_H
