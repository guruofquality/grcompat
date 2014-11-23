#ifndef GNURADIO_GR_MATH_H
#define GNURADIO_GR_MATH_H

#include <gnuradio/math.h>
#include <gr_complex.h>

static inline bool gr_is_power_of_2(long x)
{
    return gr::is_power_of_2(x);
}

static inline float gr_fast_atan2f(float y, float x)
{
    return gr::fast_atan2f(y, x);
}

static inline float gr_fast_atan2f(gr_complex z)
{
    return gr::fast_atan2f(z);
}

static inline float gr_branchless_clip(float x, float clip)
{
    return gr::branchless_clip(x, clip);
}

static inline float gr_clip(float x, float clip)
{
    return gr::clip(x, clip);
}

static inline unsigned int gr_binary_slicer(float x)
{
    return gr::binary_slicer(x);
}

static inline unsigned int gr_quad_45deg_slicer(float r, float i)
{
    return gr::quad_45deg_slicer(r, i);
}

static inline unsigned int gr_quad_0deg_slicer(float r, float i)
{
    return gr::quad_0deg_slicer(r, i);
}

static inline unsigned int gr_quad_45deg_slicer(gr_complex x)
{
    return gr::quad_45deg_slicer(x);
}

static inline unsigned int gr_quad_0deg_slicer(gr_complex x)
{
    return gr::quad_0deg_slicer(x);
}

static inline unsigned int gr_branchless_binary_slicer(float x)
{
    return gr::branchless_binary_slicer(x);
}

static inline unsigned int gr_branchless_quad_0deg_slicer(float r, float i)
{
    return gr::branchless_quad_0deg_slicer(r, i);
}

static inline unsigned int gr_branchless_quad_0deg_slicer(gr_complex x)
{
    return gr::branchless_quad_0deg_slicer(x);
}

static inline unsigned int gr_branchless_quad_45deg_slicer(float r, float i)
{
    return gr::branchless_quad_45deg_slicer(r, i);
}

static inline unsigned int gr_branchless_quad_45deg_slicer(gr_complex x)
{
    return gr::branchless_quad_45deg_slicer(x);
}

static inline size_t gr_p2_round_down(size_t x, size_t pow2)
{
    return gr::p2_round_down(x, pow2);
}

static inline size_t gr_p2_round_up(size_t x, size_t pow2)
{
    return gr::p2_round_up(x, pow2);
}

static inline size_t gr_p2_modulo(size_t x, size_t pow2)
{
    return gr::p2_modulo(x, pow2);
}

static inline size_t gr_p2_modulo_neg(size_t x, size_t pow2)
{
    return gr::p2_modulo_neg(x, pow2);
}

#endif //GNURADIO_GR_MATH_H

#warning GR-COMPAT REQUIRED TO COMPILE - OUTDATED GNURADIO API IN USE - PLEASE UPDATE YOUR MODULE!!!


