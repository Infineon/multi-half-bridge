#include "test_tle94112-mock.hpp"
#include "tle94112.hpp"

/**
 * Class C++ Tle94112 Class Test Suite
 */
class Tle94112_Test: public ::testing::Test
{
    public:

        void SetUp()
        {
            
        }

        void TearDown()
        {

        }
};

/**
 * Constructor call
 */
TEST_F(Tle94112_Test, defaultConstructor_Success)
{
    /* No test, just pretty coverage */
    Tle94112 mhb;
}

/**
 * begin() tests
 */
TEST_F(Tle94112_Test, begin_Success)
{
    MockSPIC   sbus;
    MockGPIOC  en;
    MockGPIOC  cs;
    MockTimer  timer;

    EXPECT_CALL(sbus, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(cs, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(cs, enable())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(en, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(en, enable())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, init())
    .Times(1)
    .WillOnce(Return(OK));

    Tle94112 mhb(&sbus, &cs, &en, &timer);
    
    /* No test, just pretty coverage */
    mhb.begin();
}

TEST_F(Tle94112_Test, beginNullptrInstances_Success)
{
    Tle94112 mhb(nullptr, nullptr, nullptr, nullptr);
    
    /* No test, just pretty coverage */
    mhb.begin();
}

/**
 * end() tests
 */
TEST_F(Tle94112_Test, end_Success)
{
    MockSPIC   sbus;
    MockGPIOC  en;
    MockGPIOC  cs;
    MockTimer  timer;

    EXPECT_CALL(en, disable())
    .Times(1)
    .WillOnce(Return(OK));

    // EXPECT_CALL(en, deinit())
    // .Times(1)
    // .WillOnce(Return(OK));

    EXPECT_CALL(cs, disable())
    .Times(1)
    .WillOnce(Return(OK));

    // EXPECT_CALL(cs, deinit())
    // .Times(1)
    // .WillOnce(Return(OK));

    EXPECT_CALL(timer, stop())
    .Times(1)
    .WillOnce(Return(OK));

    // EXPECT_CALL(timer, deinit())
    // .Times(1)
    // .WillOnce(Return(OK));

    EXPECT_CALL(sbus, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    Tle94112 mhb(&sbus, &cs, &en, &timer);
    
    /* No test, just pretty coverage */
    mhb.end();
}

TEST_F(Tle94112_Test, endNullptrInstances_Success)
{
    Tle94112 mhb(nullptr, nullptr, nullptr, nullptr);
    
    /* No test, just pretty coverage */
    mhb.end();
}

/**
 * configHB() tests
 */
TEST_F(Tle94112_Test, configHB_Success)
{
    MockSPIC   sbus;
    MockGPIOC  en;
    MockGPIOC  cs;
    MockTimer  timer;

    EXPECT_CALL(cs, disable())
    .Times(3)
    .WillRepeatedly(Return(OK));

    EXPECT_CALL(cs, enable())
    .Times(3)
    .WillRepeatedly(Return(OK));

    EXPECT_CALL(sbus, transfer(_,_))
    .Times(6)
    .WillRepeatedly(Return(OK));

    EXPECT_CALL(timer, delayMilli(_))
    .Times(3)
    .WillRepeatedly(Return(OK));

    Tle94112 mhb(&sbus, &cs, &en, &timer);

    Tle94112::HalfBridge  hb       = Tle94112::TLE_HB1;
    Tle94112::HBState     hbState  = Tle94112::TLE_LOW;
    Tle94112::PWMChannel  pwmChan  = Tle94112::TLE_PWM1;
    // uint8_t               activeFW = 1;
    
    /* No test, just pretty coverage */
    mhb.configHB(hb, hbState, pwmChan);
    // mhb.configHB(hb, hbState, pwmChan, activeFW);
}

/**
 * configPWM() tests
 */
TEST_F(Tle94112_Test, configPWM_Success)
{
    MockSPIC   sbus;
    MockGPIOC  en;
    MockGPIOC  cs;
    MockTimer  timer;

    EXPECT_CALL(cs, disable())
    .Times(2)
    .WillRepeatedly(Return(OK));

    EXPECT_CALL(cs, enable())
    .Times(2)
    .WillRepeatedly(Return(OK));

    EXPECT_CALL(sbus, transfer(_,_))
    .Times(4)
    .WillRepeatedly(Return(OK));

    EXPECT_CALL(timer, delayMilli(_))
    .Times(2)
    .WillRepeatedly(Return(OK));

    Tle94112 mhb(&sbus, &cs, &en, &timer);

    Tle94112::PWMChannel pwmChan   = Tle94112::TLE_PWM1;
    Tle94112::PWMFreq    freq      = Tle94112::TLE_FREQ100HZ;
    uint8_t              dutyCycle = 128;
    
    /* No test, just pretty coverage */
    mhb.configPWM(pwmChan, freq, dutyCycle);
}

/**
 * setLedMode() tests
 */
TEST_F(Tle94112_Test, setLedMode_Success)
{
    MockSPIC   sbus;
    MockGPIOC  en;
    MockGPIOC  cs;
    MockTimer  timer;

    EXPECT_CALL(cs, disable())
    .Times(2)
    .WillRepeatedly(Return(OK));

    EXPECT_CALL(cs, enable())
    .Times(2)
    .WillRepeatedly(Return(OK));

    EXPECT_CALL(sbus, transfer(_,_))
    .Times(4)
    .WillRepeatedly(Return(OK));

    EXPECT_CALL(timer, delayMilli(_))
    .Times(2)
    .WillRepeatedly(Return(OK));

    Tle94112 mhb(&sbus, &cs, &en, &timer);
    
    /* No test, just pretty coverage */
    mhb.setLedMode(Tle94112::TLE_HB1, 0);
    mhb.setLedMode(Tle94112::TLE_HB2, 0);
    mhb.setLedMode(Tle94112::TLE_HB3, 0);
}

/**
 * getSysDiagnosis() tests
 */
TEST_F(Tle94112_Test, getSysDiagnosis_Success)
{
    MockSPIC   sbus;
    MockGPIOC  en;
    MockGPIOC  cs;
    MockTimer  timer;

    EXPECT_CALL(cs, disable())
    .Times(3)
    .WillRepeatedly(Return(OK));

    EXPECT_CALL(cs, enable())
    .Times(3)
    .WillRepeatedly(Return(OK));

    EXPECT_CALL(sbus, transfer(_,_))
    .Times(6)
    .WillRepeatedly(Return(OK));

    EXPECT_CALL(timer, delayMilli(_))
    .Times(3)
    .WillRepeatedly(Return(OK));

    Tle94112 mhb(&sbus, &cs, &en, &timer);
    
    /* No test, just pretty coverage */
    // ASSERT_EQ(0x00, mhb.getSysDiagnosis());
    mhb.getSysDiagnosis(Tle94112::TLE_SPI_ERROR);
    mhb.getSysDiagnosis();
    mhb.getSysDiagnosis();
}

/**
 * getHBOverCurrent() tests
 */
TEST_F(Tle94112_Test, getHBOverCurrent_Success)
{
    MockSPIC   sbus;
    MockGPIOC  en;
    MockGPIOC  cs;
    MockTimer  timer;

    EXPECT_CALL(cs, disable())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(cs, enable())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(sbus, transfer(_,_))
    .Times(2)
    .WillRepeatedly(Return(OK));

    EXPECT_CALL(timer, delayMilli(_))
    .Times(1)
    .WillOnce(Return(OK));

    Tle94112 mhb(&sbus, &cs, &en, &timer);
    
    /* No test, just pretty coverage */
    mhb.getHBOverCurrent(Tle94112::TLE_HB1);
}

/**
 * getHBOpenLoad() tests
 */
TEST_F(Tle94112_Test, getHBOpenLoad_Success)
{
    MockSPIC   sbus;
    MockGPIOC  en;
    MockGPIOC  cs;
    MockTimer  timer;

    EXPECT_CALL(cs, disable())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(cs, enable())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(sbus, transfer(_,_))
    .Times(2)
    .WillRepeatedly(Return(OK));

    EXPECT_CALL(timer, delayMilli(_))
    .Times(1)
    .WillOnce(Return(OK));

    Tle94112 mhb(&sbus, &cs, &en, &timer);
    
    /* No test, just pretty coverage */
    mhb.getHBOpenLoad(Tle94112::TLE_HB1);
}

/**
 * clearErrors() tests
 */
TEST_F(Tle94112_Test, clearErrors_Success)
{
    MockSPIC   sbus;
    MockGPIOC  en;
    MockGPIOC  cs;
    MockTimer  timer;

    EXPECT_CALL(cs, disable())
    .Times(7)
    .WillRepeatedly(Return(OK));

    EXPECT_CALL(cs, enable())
    .Times(7)
    .WillRepeatedly(Return(OK));

    EXPECT_CALL(sbus, transfer(_,_))
    .Times(14)
    .WillRepeatedly(Return(OK));

    EXPECT_CALL(timer, delayMilli(_))
    .Times(7)
    .WillRepeatedly(Return(OK));
    
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    
    /* No test, just pretty coverage */
    mhb.clearErrors();
}