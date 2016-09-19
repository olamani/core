#define BOOST_TEST_MODULE Olamani Test
#include <boost/test/included/unit_test.hpp>
#include "Flag.hpp"
#include "Body.hpp"

namespace Olamani {

namespace Body {

char SIDE = 'l';

}

}

const double TOLERANCE = 0.01;

BOOST_AUTO_TEST_CASE(flag_for_left_side) {
    Olamani::Body::SIDE = 'l';
    Olamani::Flag flag;
    flag.setData("f t 0", "1 2");
    BOOST_CHECK_CLOSE(0.0, flag.x, TOLERANCE);
    BOOST_CHECK_CLOSE(-39.0, flag.y, TOLERANCE);
    BOOST_CHECK_CLOSE(1.0, flag.distance, TOLERANCE);
    BOOST_CHECK_CLOSE(2.0, flag.direction, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(flag_for_right_side) {
    Olamani::Body::SIDE = 'r';
    Olamani::Flag flag;
    flag.setData("f t 0", "3 4");
    BOOST_CHECK_CLOSE(0.0, flag.x, TOLERANCE);
    BOOST_CHECK_CLOSE(39.0, flag.y, TOLERANCE);
    BOOST_CHECK_CLOSE(3.0, flag.distance, TOLERANCE);
    BOOST_CHECK_CLOSE(4.0, flag.direction, TOLERANCE);
}