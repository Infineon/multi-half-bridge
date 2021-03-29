#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "tle94112.hpp"
#include "gpio.hpp"
#include "timer.hpp"
#include "spic.hpp"

using namespace tle94112;

using ::testing::Return;
// using ::testing::_;
// using ::testing::InSequence;
// using ::testing::DoAll;
// using ::testing::SetArgReferee;
// using ::testing::SetArgPointee;
// using ::testing::SetArrayArgument;
// using ::testing::NiceMock;

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
class MockGPIO : public GPIO
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

// /**
//  * Tle94112 Mock (Mock Private Class functions)
//  */
// class MockTle94112: public Tle94112
// {
//     public:
//         MockTle94112( )

//         void writeReg(uint8_t addr, uint8_t value) { reg.regMap[addr] = value; };

//         MOCK_METHOD(Error_t, setStatus,              (const Status_t newStatus, bool enoughIfImplicit),  (override));
//         MOCK_METHOD(Error_t, preResetSaveConfig,     (),                                                 (override));
//         MOCK_METHOD(Error_t, postResetRestoreConfig, (),                                                 (override));
// };

// /**
//  * Tle94112 Public( Private function Public)
//  */
// class Tle94112Pub: public Tle94112
// {
//     public:
//         Tle94112Pub(  SBus  * const sbus,
//                         PWM   * const pwm,
//                         Timer * const timer       = nullptr,
//                         GPIO  * const interrupt   = nullptr,
//                         GPIO  * const protoSelect = nullptr,
//                         GPIO  * const power3V3    = nullptr, 
//                         GPIO  * const power12V    = nullptr,
//                         GPIO  * const pwmDisable  = nullptr) : 
//                         PASCO2(sbus, pwm, timer, interrupt, protoSelect, power3V3, power12V, pwmDisable)
//                         {

//                         };

//         void writeReg(uint8_t addr, uint8_t value) { reg.regMap[addr] = value; };

//         Error_t preResetSaveConfigPublic    () { return preResetSaveConfig();     };
//         Error_t postResetRestoreConfigPublic() { return postResetRestoreConfig(); };
// };