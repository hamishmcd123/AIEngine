#pragma once

// Text color
#define ANSI_RESET        "\033[0m"
#define ANSI_BLACK        "\033[30m"
#define ANSI_RED          "\033[31m"
#define ANSI_GREEN        "\033[32m"
#define ANSI_YELLOW       "\033[33m"
#define ANSI_BLUE         "\033[34m"
#define ANSI_MAGENTA      "\033[35m"
#define ANSI_CYAN         "\033[36m"
#define ANSI_WHITE        "\033[37m"

// Bold text
#define ANSI_BOLD         "\033[1m"
#define ANSI_BOLD_RED     "\033[1;31m"
#define ANSI_BOLD_GREEN   "\033[1;32m"
#define ANSI_BOLD_YELLOW  "\033[1;33m"
#define ANSI_BOLD_BLUE    "\033[1;34m"


#include <ctime>
#include <string>
#include <fstream>

enum class LogLevel{
DEBUG,
INFO,
WARNING,
FATAL
};

class Logger{
public:
static void init(const char* filename = "log.txt");

/*
 * Note to self 2025-10-24 01:31 Static member variables like this are put in the .bss and .data section of the program.
 * Though if they are never used, I think the compiler can optimise them away depending of the optimisation settings.
 */

static std::fstream logFile;
static void Log(LogLevel level, const std::string& message, const char* file, int line, const char* function);
static void LogQuiet(LogLevel level, const std::string& message, const char* file, int line, const char* function);

private:
Logger() = delete;
static time_t timestamp;
static const char* getColourCode(LogLevel level);
static const char* levelToString(LogLevel level);
};

#define LOG(level, message) Logger::Log(level, message, __FILE__, __LINE__, __func__)

// Log to console, not to log.txt.
#define LOG_QUIET(level, message) Logger::LogQuiet(level, message, __FILE__, __LINE__, __func__);
