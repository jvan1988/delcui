#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TextOutputter.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <iostream>

class TestContextGrep : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TestContextGrep);
    CPPUNIT_TEST(testYourFunctionalityHere);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() override {}

    void tearDown() override {}

    void testYourFunctionalityHere() {
        // Your test logic here
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(TestContextGrep);

#ifdef TEST
int main() {
    CPPUNIT_NS::TestResult result;
    CPPUNIT_NS::TestResultCollector resultCollector;
    result.addListener(&resultCollector);

    CPPUNIT_NS::TestRunner runner;
    runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    runner.run(result);

    CPPUNIT_NS::TextOutputter textOutputter(&resultCollector, std::cerr);
    textOutputter.write();

    return resultCollector.wasSuccessful() ? 0 : 1;
}
#endif
