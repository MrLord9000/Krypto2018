#define BOOST_AUTO_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

struct ConfigKrypto
{
    ConfigKrypto()
    {
        //      unit_test_log.set_format( output_format.XML ); 
        unit_test_log.set_threshold_level( log_level::log_all_errors );
        //      expected_failures(2);
        timeout(1);
        //      tolerance(0.0001);
    }

    ~ConfigKrypto()
    {

    }
};

BOOST_GLOBAL_FIXTURE(ConfigKrypto);