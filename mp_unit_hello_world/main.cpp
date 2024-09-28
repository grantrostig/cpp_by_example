#include <mp-units/compat_macros.h>
#include <mp-units/ext/format.h>
#include <mp-units/format.h>
#include <mp-units/ostream.h>
#include <mp-units/systems/international.h>
#include <mp-units/systems/isq.h>
#include <mp-units/systems/si.h>
#include <format>
#include <iomanip>
#include <iostream>
#include <print>

#include <iostream>

using namespace mp_units;
using namespace mp_units::si;
using namespace mp_units::si::unit_symbols; // mp_units::si::unit_symbols::
using namespace mp_units::international::unit_symbols;

// simple numeric operations
static_assert(10 * mp_units::si::unit_symbols::km / 2 == 5 * mp_units::si::unit_symbols::km);

// conversions to common units
static_assert(1 * mp_units::si::unit_symbols::h == 3600 * mp_units::si::unit_symbols::s);
static_assert(1 * mp_units::si::unit_symbols::km + 1 * mp_units::si::unit_symbols::m == 1001 * mp_units::si::unit_symbols::m);

// derived quantities
static_assert(1 * mp_units::si::unit_symbols::km / (1 * mp_units::si::unit_symbols::s) == 1000 * mp_units::si::unit_symbols::m / mp_units::si::unit_symbols::s);
static_assert(2 * km / h * (2 * h) == 4 * km);
static_assert(2 * km / (2 * km / h) == 1 * h);

static_assert(2 * m * (3 * m) == 6 * m2);

static_assert(10 * km / (5 * km) == 2);

static_assert(1000 / (1 * s) == 1 * kHz);

constexpr QuantityOf<isq::speed> auto avg_speed(QuantityOf<isq::length> auto d,
          QuantityOf<isq::time> auto t) {
    return d / t;
}

int main() {
    constexpr quantity v1 = 110 * km / h;
    constexpr quantity v2 = 70 * mph;
    constexpr quantity v3 = avg_speed(220. * isq::distance[km], 2 * h);
    constexpr quantity v4 = avg_speed(isq::distance(140. * mi), 2 * h);
    constexpr quantity v5 = v3.in(m / s);
    constexpr quantity v6 = value_cast<m / s>(v4);
    constexpr quantity v7 = value_cast<int>(v6);
    std::cout << v1 << '\n';                                        // 110 km/h
    std::cout << v2 << '\n';                                        //
    std::cout << v3 << '\n';                                        //
    std::cout << v4 << '\n';                                        //
    std::cout << v5 << '\n';                                        //
    std::cout << v6 << '\n';                                        //
    std::cout << v7 << '\n' << std::endl;                                        //

    std::cout << std::setw(10) << std::setfill('*') << v2 << '\n';  // ***70 mi/h
    std::cout << std::format("{:*^10}\n", v3);                      // *110 km/h*
    std::println("{:%N in %U of %D}", v4);                          // 70 in mi/h of LT⁻¹
    std::println("{::N[.2f]}", v5);                                 // 30.56 m/s
    std::println("{::N[.2f]U[dn]}", v6);                            // 31.29 m⋅s⁻¹
    std::println("{:%N}", v7);                                      // 31

    std::cout << "\nThe seven defining constants of the SI and the seven corresponding units they define:\n";
    std::cout << MP_UNITS_STD_FMT::format("- hyperfine transition frequency of Cs: {} = {::N[.0]}\n",
                                           1. * si2019::hyperfine_structure_transition_frequency_of_cs,
                                          (1. * si2019::hyperfine_structure_transition_frequency_of_cs).in(Hz));
    std::cout << MP_UNITS_STD_FMT::format("- speed of light in vacuum:             {} = {::N[.20e]}\n",
                                           1. * si2019::speed_of_light_in_vacuum,
                                          (1. * si2019::speed_of_light_in_vacuum).in(m / s));
    std::cout << "\t\t\t\t" <<  1. * si2019::speed_of_light_in_vacuum << std::endl;
    std::cout << "\t\t\t\t" << (1. * si2019::speed_of_light_in_vacuum).in(m / s) << std::endl;
    std::cout << MP_UNITS_STD_FMT::format("- Planck constant:                      {} = {::N[.8e]}\n",
                                          1. * si2019::planck_constant, (1. * si2019::planck_constant).in(J * s));
    std::cout << MP_UNITS_STD_FMT::format("- elementary charge:                    {} = {::N[.9e]}\n",
                                          1. * si2019::elementary_charge, (1. * si2019::elementary_charge).in(C));
    std::cout << MP_UNITS_STD_FMT::format("- Boltzmann constant:                   {} = {::N[.6e]}\n",
                                          1. * si2019::boltzmann_constant, (1. * si2019::boltzmann_constant).in(J / K));
    std::cout << MP_UNITS_STD_FMT::format("- Avogadro constant:                    {} = {::N[.8e]}\n",
                                          1. * si2019::avogadro_constant, (1. * si2019::avogadro_constant).in(one / mol));
    std::cout << MP_UNITS_STD_FMT::format("- luminous efficacy:                    {} = {}\n",
                                          1. * si2019::luminous_efficacy, (1. * si2019::luminous_efficacy).in(lm / W));

}
