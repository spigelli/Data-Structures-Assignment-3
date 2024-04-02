// PrettyTest.h

// #ifndef PRETTYTEST_H
// #define PRETTYTEST_H

#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cstddef>

// Color codes for pretty output
#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_RESET "\033[0m"

// Test case structure
struct TestCase {
  std::string name;
  std::function<void()> testFunction;
};

class TestSuite {
  public:
    TestSuite(std::string suite_name) {
      _suite_name = suite_name;
    }

    void addTest(const std::string &name, std::function<void()> testFunction)
    {
      tests.push_back({name, testFunction});
    }

    void run()
    {
      std::size_t passed = 0;
      std::cout << "====================================" << std::endl;
      std::cout << "Running test suite: " << _suite_name << std::endl;
      for (auto &test : tests)
      {
        try
        {
          test.testFunction();
          std::cout << COLOR_GREEN << "PASS: " << test.name << COLOR_RESET << std::endl;
          ++passed;
        }
        catch (const std::exception &e)
        {
          std::cout << COLOR_RED << "FAIL: " << test.name << " - " << e.what() << COLOR_RESET << std::endl;
        }
        catch (...)
        {
          std::cout << COLOR_RED << "FAIL: " << test.name << " - Unknown error" << COLOR_RESET << std::endl;
        }
      }
      std::cout << "------------------------------------" << std::endl;
      std::cout << passed << "/" << tests.size() << " tests passed." << std::endl;
      if (passed == tests.size())
      {
        std::cout << COLOR_GREEN << "All tests passed! :)" << COLOR_RESET << std::endl;
      }
      else
      {
        std::cout << COLOR_RED << "Some tests failed. :(" << COLOR_RESET << std::endl;
      }
      std::cout << "====================================" << std::endl;
    }

  private:
    std::vector<TestCase> tests;
    std::string _suite_name;
};

// #endif // PRETTYTEST_H
