//Its like being hit by the arvo

#ifndef GNURADIO_GR_COUNT_BITS_H
#define GNURADIO_GR_COUNT_BITS_H

#if __GNUC__ > 3 || __GNUC__ == 3 && __GNUC_MINOR__ >= 4
    #define __grjhsfhjspopcnt __builtin_popcount
#else
    inline unsigned __grjhsfhjspopcnt(unsigned num)
    {
        unsigned pop = 0;
        while(num)
        {
            if (num & 0x1) pop++;
            num >>= 1;
        }
        return pop;
    }
#endif

static inline unsigned int gr_count_bits8(unsigned int x)
{
    return __grjhsfhjspopcnt(x & 0xff);
}
static inline unsigned int gr_count_bits16(unsigned int x)
{
    return __grjhsfhjspopcnt(x & 0xffff);
}
static inline unsigned int gr_count_bits32(unsigned int x)
{
    return __grjhsfhjspopcnt(x & 0xffffffff);
}
static inline unsigned int gr_count_bits64(unsigned long long int x)
{
    return gr_count_bits32(x & 0xffffffff) + gr_count_bits32(x >> 32);
}

#endif //GNURADIO_GR_COUNT_BITS_H
