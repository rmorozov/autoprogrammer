#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>
#include <vector>

namespace codegen
{
enum class Standard
{
    Auto,
    Cpp03,
    Cpp11,
    Cpp14,
    Cpp17
};

enum class GeneratorId
{
    Unknown = -1,
    Enum2StringGen,
    PimplGen,
    TestsGen
};

enum class TestEngine
{
    GoogleTests,
    CppUnit,
    QtTest
};

struct TestGenOptions
{
    bool generateMocks = true;
    bool testPrivateMethods = true;
    bool testTemplates = false;
    bool generateBasicPositive = true;
    bool generateBasicNegative = true;
    bool generateComplexPositive = true;
    bool generateComplexNegative = true;
    TestEngine testEngine = TestEngine::GoogleTests;
    std::vector<std::string> classesToTest;
    std::string testFixtureName;
};

struct Options
{
    GeneratorId generatorType = GeneratorId::Unknown;
    std::string outputHeaderName;
    std::string outputSourceName;
    std::vector<std::string> inputFiles;
    std::vector<std::string> extraHeaders;
    bool debugMode = false;
    Standard targetStandard = Standard::Auto;
    TestGenOptions testGenOptions;
};

} // codegen

#endif // OPTIONS_H