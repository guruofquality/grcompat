#ifndef GNURADIO_GR_FEVAL_H
#define GNURADIO_GR_FEVAL_H

#include <gnuradio/feval.h>
#include <gr_complex.h>

typedef gr::feval_dd gr_feval_dd;
typedef gr::feval_cc gr_feval_cc;
typedef gr::feval_ll gr_feval_ll;
typedef gr::feval gr_feval;
typedef gr::feval_p gr_feval_p;

static inline double gr_feval_dd_example(gr_feval_dd *f, double x)
{
    return gr::feval_dd_example(f, x);
}
static inline gr_complex gr_feval_cc_example(gr_feval_cc *f, gr_complex x)
{
    return gr::feval_cc_example(f, x);
}
static inline long gr_feval_ll_example(gr_feval_ll *f, long x)
{
    return gr::feval_ll_example(f, x);
}
static inline void gr_feval_example(gr_feval *f)
{
    gr::feval_example(f);
}

#endif //GNURADIO_GR_FEVAL_H

#warning GR-COMPAT REQUIRED TO COMPILE - OUTDATED GNURADIO API IN USE - PLEASE UPDATE YOUR MODULE!!!


