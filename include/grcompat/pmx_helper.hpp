/*
 * Copyright 2012-2014 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_PMX_HELPER_HPP
#define INCLUDED_PMX_HELPER_HPP

#include <PMC/PMC.hpp>
#include <PMC/Containers.hpp>
#include <pmt/pmt.h>
#include <boost/foreach.hpp>

#if (ULONG_MAX == 0xffffffff) || defined(__APPLE__)
    //this long is only serializable on 32 bit machines
    #define PMX_HELPER_STDINT_NOLONG
#else
    //this long long is only serializable on 64 bit machines
    #define PMX_HELPER_STDINT_NOLONGLONG
#endif

namespace pmt
{

inline pmt_t pmc_to_pmt(const PMCC &p)
{
    //the container is null
    if (not p) return pmt::pmt_t();

    #define decl_pmc_to_pmt(type, conv) if (p.is<type >()) return conv(p.as<type >())

    //bool
    decl_pmc_to_pmt(bool, from_bool);

    //string
    decl_pmc_to_pmt(std::string, string_to_symbol);

    //numeric types
    #ifdef PMX_HELPER_STDINT_NOLONG
        decl_pmc_to_pmt(signed long, from_long);
        decl_pmc_to_pmt(unsigned long, from_long);
    #endif
    #ifdef PMX_HELPER_STDINT_NOLONGLONG
        decl_pmc_to_pmt(signed long long, from_uint64);
        decl_pmc_to_pmt(unsigned long long, from_uint64);
    #endif
    decl_pmc_to_pmt(int8_t, from_long);
    decl_pmc_to_pmt(int16_t, from_long);
    decl_pmc_to_pmt(int32_t, from_long);
    decl_pmc_to_pmt(uint8_t, from_long);
    decl_pmc_to_pmt(uint16_t, from_long);
    decl_pmc_to_pmt(uint32_t, from_long);
    decl_pmc_to_pmt(int64_t, from_uint64);
    decl_pmc_to_pmt(uint64_t, from_uint64);
    decl_pmc_to_pmt(float, from_double);
    decl_pmc_to_pmt(double, from_double);
    #define pmt_from_complex(x) pmt_make_rectangular((x).real(), (x).imag())
    decl_pmc_to_pmt(std::complex<float>, from_complex);
    decl_pmc_to_pmt(std::complex<double>, from_complex);

    //pair container
    if (p.is<PMCPair>())
    {
        const PMCPair &pr = p.as<PMCPair>();
        return cons(pmc_to_pmt(pr.first), pmc_to_pmt(pr.second));
    }

    //fucking tuples
/*
for i in range(11):
    args = list()
    for j in range(i):
        args.append('pmc_to_pmt(p.as<PMCTuple<%d> >()[%d])'%(i, j))
    print '    if (p.is<PMCTuple<%d> >())'%i
    print '        return make_tuple(%s);'%(', '.join(args),)
*/
    if (p.is<PMCTuple<0> >())
        return make_tuple();
    if (p.is<PMCTuple<1> >())
        return make_tuple(pmc_to_pmt(p.as<PMCTuple<1> >()[0]));
    if (p.is<PMCTuple<2> >())
        return make_tuple(pmc_to_pmt(p.as<PMCTuple<2> >()[0]), pmc_to_pmt(p.as<PMCTuple<2> >()[1]));
    if (p.is<PMCTuple<3> >())
        return make_tuple(pmc_to_pmt(p.as<PMCTuple<3> >()[0]), pmc_to_pmt(p.as<PMCTuple<3> >()[1]), pmc_to_pmt(p.as<PMCTuple<3> >()[2]));
    if (p.is<PMCTuple<4> >())
        return make_tuple(pmc_to_pmt(p.as<PMCTuple<4> >()[0]), pmc_to_pmt(p.as<PMCTuple<4> >()[1]), pmc_to_pmt(p.as<PMCTuple<4> >()[2]), pmc_to_pmt(p.as<PMCTuple<4> >()[3]));
    if (p.is<PMCTuple<5> >())
        return make_tuple(pmc_to_pmt(p.as<PMCTuple<5> >()[0]), pmc_to_pmt(p.as<PMCTuple<5> >()[1]), pmc_to_pmt(p.as<PMCTuple<5> >()[2]), pmc_to_pmt(p.as<PMCTuple<5> >()[3]), pmc_to_pmt(p.as<PMCTuple<5> >()[4]));
    if (p.is<PMCTuple<6> >())
        return make_tuple(pmc_to_pmt(p.as<PMCTuple<6> >()[0]), pmc_to_pmt(p.as<PMCTuple<6> >()[1]), pmc_to_pmt(p.as<PMCTuple<6> >()[2]), pmc_to_pmt(p.as<PMCTuple<6> >()[3]), pmc_to_pmt(p.as<PMCTuple<6> >()[4]), pmc_to_pmt(p.as<PMCTuple<6> >()[5]));
    if (p.is<PMCTuple<7> >())
        return make_tuple(pmc_to_pmt(p.as<PMCTuple<7> >()[0]), pmc_to_pmt(p.as<PMCTuple<7> >()[1]), pmc_to_pmt(p.as<PMCTuple<7> >()[2]), pmc_to_pmt(p.as<PMCTuple<7> >()[3]), pmc_to_pmt(p.as<PMCTuple<7> >()[4]), pmc_to_pmt(p.as<PMCTuple<7> >()[5]), pmc_to_pmt(p.as<PMCTuple<7> >()[6]));
    if (p.is<PMCTuple<8> >())
        return make_tuple(pmc_to_pmt(p.as<PMCTuple<8> >()[0]), pmc_to_pmt(p.as<PMCTuple<8> >()[1]), pmc_to_pmt(p.as<PMCTuple<8> >()[2]), pmc_to_pmt(p.as<PMCTuple<8> >()[3]), pmc_to_pmt(p.as<PMCTuple<8> >()[4]), pmc_to_pmt(p.as<PMCTuple<8> >()[5]), pmc_to_pmt(p.as<PMCTuple<8> >()[6]), pmc_to_pmt(p.as<PMCTuple<8> >()[7]));
    if (p.is<PMCTuple<9> >())
        return make_tuple(pmc_to_pmt(p.as<PMCTuple<9> >()[0]), pmc_to_pmt(p.as<PMCTuple<9> >()[1]), pmc_to_pmt(p.as<PMCTuple<9> >()[2]), pmc_to_pmt(p.as<PMCTuple<9> >()[3]), pmc_to_pmt(p.as<PMCTuple<9> >()[4]), pmc_to_pmt(p.as<PMCTuple<9> >()[5]), pmc_to_pmt(p.as<PMCTuple<9> >()[6]), pmc_to_pmt(p.as<PMCTuple<9> >()[7]), pmc_to_pmt(p.as<PMCTuple<9> >()[8]));
    if (p.is<PMCTuple<10> >())
        return make_tuple(pmc_to_pmt(p.as<PMCTuple<10> >()[0]), pmc_to_pmt(p.as<PMCTuple<10> >()[1]), pmc_to_pmt(p.as<PMCTuple<10> >()[2]), pmc_to_pmt(p.as<PMCTuple<10> >()[3]), pmc_to_pmt(p.as<PMCTuple<10> >()[4]), pmc_to_pmt(p.as<PMCTuple<10> >()[5]), pmc_to_pmt(p.as<PMCTuple<10> >()[6]), pmc_to_pmt(p.as<PMCTuple<10> >()[7]), pmc_to_pmt(p.as<PMCTuple<10> >()[8]), pmc_to_pmt(p.as<PMCTuple<10> >()[9]));

    //vector container
    if (p.is<PMCList>())
    {
        const PMCList &l = p.as<PMCList>();
        pmt_t v = make_vector(l.size(), pmt_t());
        for (size_t i = 0; i < l.size(); i++)
        {
            vector_set(v, i, pmc_to_pmt(l[i]));
        }
        return v;
    }

    //numeric arrays
    #define decl_pmc_to_pmt_numeric_array(type, suffix) \
    if (p.is<std::vector<type> >()) return init_ ## suffix ## vector(p.as<std::vector<type> >().size(), &p.as<std::vector<type> >()[0])
    decl_pmc_to_pmt_numeric_array(uint8_t, u8);
    decl_pmc_to_pmt_numeric_array(uint16_t, u16);
    decl_pmc_to_pmt_numeric_array(uint32_t, u32);
    decl_pmc_to_pmt_numeric_array(uint64_t, u64);
    decl_pmc_to_pmt_numeric_array(int8_t, s8);
    decl_pmc_to_pmt_numeric_array(int16_t, s16);
    decl_pmc_to_pmt_numeric_array(int32_t, s32);
    decl_pmc_to_pmt_numeric_array(int64_t, s64);
    decl_pmc_to_pmt_numeric_array(float, f32);
    decl_pmc_to_pmt_numeric_array(double, f64);
    decl_pmc_to_pmt_numeric_array(std::complex<float>, c32);
    decl_pmc_to_pmt_numeric_array(std::complex<double>, c64);

    //dictionary container
    if (p.is<PMCDict>())
    {
        const PMCDict &m = p.as<PMCDict>();
        pmt_t d = make_dict();
        BOOST_FOREACH(const PMCPair &pr, m)
        {
            d = dict_add(d, pmc_to_pmt(pr.first), pmc_to_pmt(pr.second));
        }
        return d;
    }

    //set container
    if (p.is<PMCSet>())
    {
        const PMCSet &s = p.as<PMCSet>();
        pmt_t l = PMT_NIL;
        BOOST_FOREACH(const PMCC &elem, s)
        {
            l = list_add(l, pmc_to_pmt(elem));
        }
        return l;
    }

    //is it already a pmt?
    if (p.is<pmt_t>()) return p.as<pmt_t>();

    //backup plan... boost::any
    return make_any(p);

}

inline PMCC pmt_to_pmc(const pmt_t &p)
{
    //if the container null?
    if (not p) return PMC();

    #define decl_pmt_to_pmc(check, conv) if (check(p)) return PMC_M(conv(p))

    //bool
    decl_pmt_to_pmc(is_bool, to_bool);

    //string (do object interning for strings)
    decl_pmt_to_pmc(is_symbol, symbol_to_string).intern();

    //numeric types
    //long can typedef to int64, force this to int32
    if (is_integer(p)) return PMC_M(int32_t(to_long(p)));
    //decl_pmt_to_pmc(is_integer, to_long);
    decl_pmt_to_pmc(is_uint64, to_uint64);
    decl_pmt_to_pmc(is_real, to_double);
    decl_pmt_to_pmc(is_complex, to_complex);

    //is it a boost any holding a PMCC?
    if (is_any(p))
    {
        const boost::any a = any_ref(p);
        if (a.type() == typeid(PMCC)) return boost::any_cast<PMCC>(a);
    }

    //pair container
    if (is_pair(p))
    {
        PMCPair pr(pmt_to_pmc(car(p)), pmt_to_pmc(cdr(p)));
        return PMC_M(pr);
    }

    //fucking tuples
    #define decl_pmt_to_pmc_tuple(n) \
    if (is_tuple(p) and length(p) == n) \
    { \
        PMCTuple<n> t; \
        for (size_t i = 0; i < n; i++) t[i] = pmt_to_pmc(tuple_ref(p, i)); \
        return PMC_M(t); \
    }
    decl_pmt_to_pmc_tuple(0);
    decl_pmt_to_pmc_tuple(1);
    decl_pmt_to_pmc_tuple(2);
    decl_pmt_to_pmc_tuple(3);
    decl_pmt_to_pmc_tuple(4);
    decl_pmt_to_pmc_tuple(5);
    decl_pmt_to_pmc_tuple(6);
    decl_pmt_to_pmc_tuple(7);
    decl_pmt_to_pmc_tuple(8);
    decl_pmt_to_pmc_tuple(9);
    decl_pmt_to_pmc_tuple(10);

    //vector container
    if (is_vector(p))
    {
        PMCList l(length(p));
        for (size_t i = 0; i < l.size(); i++)
        {
            l[i] = pmt_to_pmc(vector_ref(p, i));
        }
        return PMC_M(l);
    }

    //numeric arrays
    #define decl_pmt_to_pmc_numeric_array(type, suffix) \
    if (is_ ## suffix ## vector(p)) \
    { \
        size_t n; const type* i = suffix ## vector_elements(p, n); \
        return PMC_M(std::vector<type>(i, i+n)); \
    }
    decl_pmt_to_pmc_numeric_array(uint8_t, u8);
    decl_pmt_to_pmc_numeric_array(uint16_t, u16);
    decl_pmt_to_pmc_numeric_array(uint32_t, u32);
    decl_pmt_to_pmc_numeric_array(uint64_t, u64);
    decl_pmt_to_pmc_numeric_array(int8_t, s8);
    decl_pmt_to_pmc_numeric_array(int16_t, s16);
    decl_pmt_to_pmc_numeric_array(int32_t, s32);
    decl_pmt_to_pmc_numeric_array(int64_t, s64);
    decl_pmt_to_pmc_numeric_array(float, f32);
    decl_pmt_to_pmc_numeric_array(double, f64);
    decl_pmt_to_pmc_numeric_array(std::complex<float>, c32);
    decl_pmt_to_pmc_numeric_array(std::complex<double>, c64);

    //dictionary container
    if (is_dict(p))
    {
        PMCDict m;
        pmt_t items = dict_items(p);
        for (size_t i = 0; i < length(items); i++)
        {
            pmt_t item = nth(i, items);
            PMCC key = pmt_to_pmc(car(item));
            PMCC val = pmt_to_pmc(cdr(item));
            m[key] = val;
        }
        return PMC_M(m);
    }

    //set container
    //FIXME no pmt_is_list...

    //backup plan... store the pmt
    return PMC_M(p);
}

}

#endif /*INCLUDED_PMX_HELPER_HPP*/
