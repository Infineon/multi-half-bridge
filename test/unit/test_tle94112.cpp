#include "test_tle94112-mock.hpp"

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
 * begin() tests
 */

TEST_F(Tle94112_Test, begin_Success)
{
    MockSPIC   sbus;
    MockGPIO   en;
    MockGPIO   cs;
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