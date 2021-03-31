#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "tle94112-types.hpp"
#include "gpio.hpp"
#include "timer.hpp"
#include "spic.hpp"

using namespace tle94112;

using ::testing::Return;
using ::testing::_; 
// using ::testing::InSequence;
// using ::testing::DoAll;
using ::testing::SetArgReferee;
// using ::testing::SetArgPointee;
// using ::testing::SetArrayArgument;
using ::testing::NiceMock;

/** 
 * SPIC Mock
 */
class MockSPIC : public SPIC
{
    public:
        MOCK_METHOD(Error_t, init,             (),                  (override));
        MOCK_METHOD(Error_t, deinit,           (),                  (override));
        MOCK_METHOD(Error_t, transfer,         (uint8_t send, 
                                                uint8_t &received), (override));
        MOCK_METHOD(Error_t, transfer16,       (uint16_t send, 
                                                uint16_t &received),(override));
        // MOCK_METHOD(Error_t, checkErrorStatus, (),                  (override));
};

/**
 * GPIO Mock
 */
class MockGPIOC : public GPIOC
{
    public:
        MOCK_METHOD(Error_t,  init,             (),               (override));
        MOCK_METHOD(Error_t,  deinit,           (),               (override));
        MOCK_METHOD(VLevel_t, read,             (),               (override));
        MOCK_METHOD(Error_t,  write,            (VLevel_t level), (override));
        MOCK_METHOD(Error_t,  enable,           (),               (override));
        MOCK_METHOD(Error_t,  disable,          (),               (override));
        // MOCK_METHOD(Error_t,  checkErrorStatus, (),               (override));
};

/**
 * Timer Mock
 */
class MockTimer: public Timer
{
    public:
        MOCK_METHOD(Error_t, init,          (),                   (override));
        MOCK_METHOD(Error_t, deinit,        (),                   (override));
        MOCK_METHOD(Error_t, start,         (),                   (override));
        MOCK_METHOD(Error_t, stop,          (),                   (override));
        MOCK_METHOD(Error_t, elapsed,       (uint32_t & elapsed), (override));
        MOCK_METHOD(Error_t, delayMilli,    (uint32_t timeout),   (override));
        MOCK_METHOD(Error_t, delayMicro,    (uint32_t timeout),   (override));
};
