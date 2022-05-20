#include "test_tle94112-mock.hpp"
#include "tle94112-motor.hpp"

/**
 * Class C++ Tle94112Motor Class Test Suite
 */
class Tle94112Motor_Test: public ::testing::Test
{
    public:

        NiceMock<MockSPIC>   sbus;
        NiceMock<MockGPIOC>  en;
        NiceMock<MockGPIOC>  cs;
        NiceMock<MockTimer>  timer;

        void SetUp()
        {
            ON_CALL(sbus, init())
            .WillByDefault(Return(OK));

            ON_CALL(sbus, deinit())
            .WillByDefault(Return(OK));

            ON_CALL(sbus, transfer(_,_))
            .WillByDefault(Return(OK));

            ON_CALL(sbus, transfer16(_,_))
            .WillByDefault(Return(OK));

            ON_CALL(en, init())
            .WillByDefault(Return(OK));

            ON_CALL(en, deinit())
            .WillByDefault(Return(OK));

            ON_CALL(en, enable())
            .WillByDefault(Return(OK));

            ON_CALL(en, disable())
            .WillByDefault(Return(OK));
        
            ON_CALL(cs, init())
            .WillByDefault(Return(OK));

            ON_CALL(cs, deinit())
            .WillByDefault(Return(OK));

            ON_CALL(cs, enable())
            .WillByDefault(Return(OK));

            ON_CALL(cs, disable())
            .WillByDefault(Return(OK));

            ON_CALL(timer, init())
            .WillByDefault(Return(OK));

            ON_CALL(timer, deinit())
            .WillByDefault(Return(OK));

            ON_CALL(timer, start())
            .WillByDefault(Return(OK));

            ON_CALL(timer, stop())
            .WillByDefault(Return(OK));

            ON_CALL(timer, delayMilli(_))
            .WillByDefault(Return(OK));
        }

        void TearDown()
        {

        }
};

/**
 * coast() tests
 */
TEST_F(Tle94112Motor_Test, coast_NotmEnabled)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);

    /* No test, just pretty coverage */
    motor.coast();
}

TEST_F(Tle94112Motor_Test, coast_Success)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);

    /* No test, just pretty coverage */
    motor.begin();
    motor.coast();
}

/**
 * begin() tests
 */
TEST_F(Tle94112Motor_Test, begin_Success)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.begin();
}

/**
 * end() tests
 */
TEST_F(Tle94112Motor_Test, end_Success)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.end();
}

/**
 * initConnector() tests
 */
TEST_F(Tle94112Motor_Test, initConnector_Success)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.initConnector(motor.HIGHSIDE, mhb.TLE_NOPWM, mhb.TLE_HB1, mhb.TLE_HB2, mhb.TLE_NOHB, mhb.TLE_NOHB);
}

TEST_F(Tle94112Motor_Test, initConnector_AlreadyMEnabledSuccess)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.begin();
    motor.initConnector(motor.HIGHSIDE, mhb.TLE_NOPWM, Tle94112::TLE_FREQ80HZ, mhb.TLE_HB1, mhb.TLE_HB2, mhb.TLE_NOHB, mhb.TLE_NOHB);
}

/**
 * connect() tests
 */
TEST_F(Tle94112Motor_Test, connect_Success)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.connect(motor.HIGHSIDE, mhb.TLE_HB1);
}

TEST_F(Tle94112Motor_Test, connect_AlreadyMEnabled)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.begin();
    motor.connect(motor.HIGHSIDE, mhb.TLE_HB1);
}

TEST_F(Tle94112Motor_Test, connect_AlreadyConnected)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.connect(motor.HIGHSIDE, mhb.TLE_HB1);
    motor.connect(motor.HIGHSIDE, mhb.TLE_HB1);
}

/**
 * disconnect() tests
 */
TEST_F(Tle94112Motor_Test, disconnect_Success)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.connect(motor.HIGHSIDE, mhb.TLE_HB1);
    motor.disconnect(mhb.TLE_HB1);
}

TEST_F(Tle94112Motor_Test, disconnect_AlreadyMEnabled)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.begin();
    motor.disconnect(mhb.TLE_HB1);
}

TEST_F(Tle94112Motor_Test, disconnect_connectorNotRegistered)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.disconnect(mhb.TLE_HB1);
}

/**
 * setPwm() tests
 */
TEST_F(Tle94112Motor_Test, setPwm_Success)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.setPwm(motor.HIGHSIDE, mhb.TLE_PWM2);
    motor.setPwm(motor.HIGHSIDE, mhb.TLE_PWM2, Tle94112::TLE_FREQ100HZ);
}

TEST_F(Tle94112Motor_Test, setPwm_AlreadyMEnabled)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.begin();
    motor.setPwm(motor.HIGHSIDE, mhb.TLE_PWM2);
    motor.setPwm(motor.HIGHSIDE, mhb.TLE_PWM2, Tle94112::TLE_FREQ100HZ);
}

/**
 * setPwmFreq() tests
 */
TEST_F(Tle94112Motor_Test, setPwmFreq_Success)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.setPwmFreq(motor.HIGHSIDE, Tle94112::TLE_FREQ100HZ);
}

TEST_F(Tle94112Motor_Test, setPwmFreq_AlreadyMEnabled)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.begin();
    motor.setPwmFreq(motor.HIGHSIDE, Tle94112::TLE_FREQ100HZ);
}

/**
 * setActiveFreeWheeling() tests
 */
TEST_F(Tle94112Motor_Test, setActiveFreeWheeling_Success)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.setActiveFreeWheeling(motor.HIGHSIDE, 1);
}

TEST_F(Tle94112Motor_Test, setActiveFreeWheeling_AlreadyMEnabled)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.begin();
    motor.setActiveFreeWheeling(motor.HIGHSIDE, 1);
}

/**
 * setSpeed() tests
 */
TEST_F(Tle94112Motor_Test, setSpeed_PositiveSpeedSuccess)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.begin();
    motor.setSpeed(127);
}

TEST_F(Tle94112Motor_Test, setSpeed_PositiveSpeedAlreadymModeForwardSuccess)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.begin();
    motor.setSpeed(127);
    motor.setSpeed(127);
}

TEST_F(Tle94112Motor_Test, setSpeed_NegativeSpeedSuccess)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.begin();
    motor.setSpeed(-80);
}

TEST_F(Tle94112Motor_Test, setSpeed_NegativeAlreadymModeBackwardSpeedSuccess)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.begin();
    motor.setSpeed(-80);
    motor.setSpeed(-80);
}

TEST_F(Tle94112Motor_Test, setSpeed_ZeroSpeedSuccess)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.begin();
    motor.setSpeed(0);
}

TEST_F(Tle94112Motor_Test, setSpeed_NotmEnabled)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.setSpeed(127);
}

/**
 * getSpeed() tests
 */
TEST_F(Tle94112Motor_Test, getSpeed_ZeroSuccess)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    ASSERT_EQ(0, motor.getSpeed());
}

TEST_F(Tle94112Motor_Test, getSpeed_ForwardSuccess)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.begin();
    motor.setSpeed(70);
    ASSERT_EQ(70, motor.getSpeed());
}

TEST_F(Tle94112Motor_Test, getSpeed_BackwardSuccess)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.begin();
    motor.setSpeed(-90);
    ASSERT_EQ(-90, motor.getSpeed());
}

/**
 * start() tests
 */
TEST_F(Tle94112Motor_Test, start_NoHighSideConenctorSuccess)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.begin();
    motor.start(127);
}

/**
 * stop() tests
 */
TEST_F(Tle94112Motor_Test, stop_NoHighSideConnectorSuccess)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.begin();
    motor.stop(127);
}

TEST_F(Tle94112Motor_Test, stop_HighSideConnectorSuccess)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
//     /* No test, just pretty coverage */
//     motor.initConnector(motor.HIGHSIDE, mhb.TLE_NOPWM, mhb.TLE_HB1, mhb.TLE_HB2, mhb.TLE_NOHB, mhb.TLE_NOHB);
    motor.begin();
    motor.stop(127);
}

TEST_F(Tle94112Motor_Test, stop_NotmEnabled)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.begin();
    motor.stop(127);
}

/**
 * rampSpeed() tests
 */
TEST_F(Tle94112Motor_Test, rampSpeed_Success)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.begin();
    motor.rampSpeed(127, 5000);
}

TEST_F(Tle94112Motor_Test, rampSpeed_StepDeltasSuccess)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);

    // EXPECT_CALL(timer, elapsed  (_))
    // .Times(1)
    // .WillOnce(DoAll(SetArgReferee<0>(2), Return(OK)));
    /* Set some relevant values for flat ramps case */
    /* No test, just pretty coverage */
    motor.begin();
    motor.rampSpeed(1, 1);
}

TEST_F(Tle94112Motor_Test, rampSpeed_sameSpeedAsCurrent)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.begin();
    motor.setSpeed(255);
    motor.rampSpeed(255, 100);
}

TEST_F(Tle94112Motor_Test, rampSpeed_NotmEnabled)
{
    Tle94112 mhb(&sbus, &cs, &en, &timer);
    Tle94112Motor motor(mhb);
    
    /* No test, just pretty coverage */
    motor.begin();
    motor.rampSpeed(127, 5000);
}

