#define BOOST_TEST_MODULE Olamani Test
#include <boost/test/included/unit_test.hpp>
#include "Player.hpp"
#include "Body.hpp"
#include <string>

namespace Olamani {

namespace Body {

std::string TEAM_NAME = "Olamani";

}

}

const double TOLERANCE = 0.01;

BOOST_AUTO_TEST_CASE(player_our_near_all) {
    std::string name = "p \"Olamani\" 10";
    std::string position = "1.0 2.0 3.0 4.0 5.0 6.0 7.0 k t";
    Olamani::Player player;
    player.setData(name, position);
    BOOST_CHECK_EQUAL(Olamani::OUR, player.getTeam());
    BOOST_CHECK_EQUAL(10, player.getNumber());
    BOOST_CHECK_CLOSE(1.0, player.getDistance(), TOLERANCE);
    BOOST_CHECK_CLOSE(2.0, player.getDirection(), TOLERANCE);
    BOOST_CHECK_CLOSE(3.0, player.getDistanceChange(), TOLERANCE);
    BOOST_CHECK_CLOSE(4.0, player.getDirectionChange(), TOLERANCE);
    BOOST_CHECK_CLOSE(5.0, player.getBodyDirection(), TOLERANCE);
    BOOST_CHECK_CLOSE(6.0, player.getHeadDirection(), TOLERANCE);
    BOOST_CHECK_CLOSE(7.0, player.getPointDirection(), TOLERANCE);
    BOOST_CHECK_EQUAL(true, player.isKicking());
    BOOST_CHECK_EQUAL(true, player.isTackling());
    BOOST_CHECK_EQUAL(false, player.isGoalie());
    BOOST_CHECK_EQUAL(true, player.isPointing());
}

BOOST_AUTO_TEST_CASE(goalie_our_near_all) {
    std::string name = "p \"Olamani\" 10 g";
    std::string position = "1.0 2.0 3.0 4.0 5.0 6.0 7.0 k t";
    Olamani::Player player;
    player.setData(name, position);
    BOOST_CHECK_EQUAL(Olamani::OUR, player.getTeam());
    BOOST_CHECK_EQUAL(10, player.getNumber());
    BOOST_CHECK_CLOSE(1.0, player.getDistance(), TOLERANCE);
    BOOST_CHECK_CLOSE(2.0, player.getDirection(), TOLERANCE);
    BOOST_CHECK_CLOSE(3.0, player.getDistanceChange(), TOLERANCE);
    BOOST_CHECK_CLOSE(4.0, player.getDirectionChange(), TOLERANCE);
    BOOST_CHECK_CLOSE(5.0, player.getBodyDirection(), TOLERANCE);
    BOOST_CHECK_CLOSE(6.0, player.getHeadDirection(), TOLERANCE);
    BOOST_CHECK_CLOSE(7.0, player.getPointDirection(), TOLERANCE);
    BOOST_CHECK_EQUAL(true, player.isKicking());
    BOOST_CHECK_EQUAL(true, player.isTackling());
    BOOST_CHECK_EQUAL(true, player.isGoalie());
    BOOST_CHECK_EQUAL(true, player.isPointing());
}

BOOST_AUTO_TEST_CASE(player_our_near) {
    std::string name = "p \"Olamani\" 10";
    std::string position = "1.0 2.0 3.0 4.0 5.0 6.0";
    Olamani::Player player;
    player.setData(name, position);
    BOOST_CHECK_EQUAL(Olamani::OUR, player.getTeam());
    BOOST_CHECK_EQUAL(10, player.getNumber());
    BOOST_CHECK_CLOSE(1.0, player.getDistance(), TOLERANCE);
    BOOST_CHECK_CLOSE(2.0, player.getDirection(), TOLERANCE);
    BOOST_CHECK_CLOSE(3.0, player.getDistanceChange(), TOLERANCE);
    BOOST_CHECK_CLOSE(4.0, player.getDirectionChange(), TOLERANCE);
    BOOST_CHECK_CLOSE(5.0, player.getBodyDirection(), TOLERANCE);
    BOOST_CHECK_CLOSE(6.0, player.getHeadDirection(), TOLERANCE);
    BOOST_CHECK_CLOSE(0.0, player.getPointDirection(), TOLERANCE);
    BOOST_CHECK_EQUAL(false, player.isKicking());
    BOOST_CHECK_EQUAL(false, player.isTackling());
    BOOST_CHECK_EQUAL(false, player.isGoalie());
    BOOST_CHECK_EQUAL(false, player.isPointing());
}

BOOST_AUTO_TEST_CASE(player_opp_near) {
    std::string name = "p \"Opponent\" 10";
    std::string position = "1.0 2.0 3.0 4.0 5.0 6.0";
    Olamani::Player player;
    player.setData(name, position);
    BOOST_CHECK_EQUAL(Olamani::OPP, player.getTeam());
    BOOST_CHECK_EQUAL(10, player.getNumber());
    BOOST_CHECK_CLOSE(1.0, player.getDistance(), TOLERANCE);
    BOOST_CHECK_CLOSE(2.0, player.getDirection(), TOLERANCE);
    BOOST_CHECK_CLOSE(3.0, player.getDistanceChange(), TOLERANCE);
    BOOST_CHECK_CLOSE(4.0, player.getDirectionChange(), TOLERANCE);
    BOOST_CHECK_CLOSE(5.0, player.getBodyDirection(), TOLERANCE);
    BOOST_CHECK_CLOSE(6.0, player.getHeadDirection(), TOLERANCE);
    BOOST_CHECK_CLOSE(0.0, player.getPointDirection(), TOLERANCE);
    BOOST_CHECK_EQUAL(false, player.isKicking());
    BOOST_CHECK_EQUAL(false, player.isTackling());
    BOOST_CHECK_EQUAL(false, player.isGoalie());
    BOOST_CHECK_EQUAL(false, player.isPointing());
}

BOOST_AUTO_TEST_CASE(goalie_our_near) {
    std::string name = "p \"Olamani\" 10 g";
    std::string position = "1.0 2.0 3.0 4.0 5.0 6.0";
    Olamani::Player player;
    player.setData(name, position);
    BOOST_CHECK_EQUAL(Olamani::OUR, player.getTeam());
    BOOST_CHECK_EQUAL(10, player.getNumber());
    BOOST_CHECK_CLOSE(1.0, player.getDistance(), TOLERANCE);
    BOOST_CHECK_CLOSE(2.0, player.getDirection(), TOLERANCE);
    BOOST_CHECK_CLOSE(3.0, player.getDistanceChange(), TOLERANCE);
    BOOST_CHECK_CLOSE(4.0, player.getDirectionChange(), TOLERANCE);
    BOOST_CHECK_CLOSE(5.0, player.getBodyDirection(), TOLERANCE);
    BOOST_CHECK_CLOSE(6.0, player.getHeadDirection(), TOLERANCE);
    BOOST_CHECK_CLOSE(0.0, player.getPointDirection(), TOLERANCE);
    BOOST_CHECK_EQUAL(false, player.isKicking());
    BOOST_CHECK_EQUAL(false, player.isTackling());
    BOOST_CHECK_EQUAL(true, player.isGoalie());
    BOOST_CHECK_EQUAL(false, player.isPointing());
}

BOOST_AUTO_TEST_CASE(player_far) {
    std::string name = "p";
    std::string position = "1.0";
    Olamani::Player player;
    player.setData(name, position);
    BOOST_CHECK_EQUAL(Olamani::UNKNOWN, player.getTeam());
    BOOST_CHECK_CLOSE(100.0, player.getDistance(), TOLERANCE);
    BOOST_CHECK_CLOSE(1.0, player.getDirection(), TOLERANCE);
}