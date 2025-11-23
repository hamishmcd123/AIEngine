#include "Logger.hpp"
#include <iostream>
#include <iomanip>
#include <ostream>
#include <sstream>
std::fstream Logger::logFile;

void Logger::init(const char *filename) {
logFile.open("log.txt", std::ios::out | std::ios::app);
  if (logFile.is_open()) {
  std::cout << ANSI_GREEN << "[LOGGER INITIALISED]\n" << ANSI_RESET; }
  else {
  std::cout << ANSI_BOLD_RED << "[LOGGER FAILED TO INITIALISE!]\n"<< ANSI_RESET;
    }
}

const char* Logger::getColourCode(LogLevel level) {
switch(level){
    case(LogLevel::DEBUG):
      return ANSI_BLUE;
    case(LogLevel::INFO):
      return ANSI_GREEN;
    case(LogLevel::WARNING):
      return ANSI_YELLOW;
    case(LogLevel::FATAL):
      return ANSI_RED;
    default:
      return ANSI_WHITE;
}
}

const char* Logger::levelToString(LogLevel level) {
switch(level){
    case(LogLevel::DEBUG):
      return "[DEBUG] ";
    case(LogLevel::INFO):
      return "[INFO] ";
    case(LogLevel::WARNING):
      return "[WARNING] ";
    case(LogLevel::FATAL):
      return "[FATAL] ";
    default:
      return "[LOGGER] ";
  }
}

void Logger::Log(LogLevel level, const std::string& message, const char* file, int line, const char* function) {

//Timestamp shenanigans

std::ostringstream oss;
std::string output;

std::time_t timestamp = std::time(NULL);
std::tm tm = *std::localtime(&timestamp); // NOTE - Not thread safe

oss << std::put_time(&tm, "%Y-%m-%dT%H:%M:%S");
oss << " | ";
oss << file;
oss << " | ";
oss << line;
oss << " ";
oss << function;
oss << " | ";
oss << message;

output = oss.str();

std::cout << getColourCode(level) << levelToString(level) << ANSI_RESET << output << '\n';

logFile << levelToString(level) << output << '\n';
}

void Logger::LogQuiet(LogLevel level, const std::string &message, const char *file, int line, const char *function) {

std::ostringstream oss;
std::string output;

std::time_t timestamp = std::time(NULL);
std::tm tm = *std::localtime(&timestamp); // NOTE - Not thread safe

oss << std::put_time(&tm, "%Y-%m-%dT%H:%M:%S");
oss << " | ";
oss << file;
oss << " | ";
oss << line;
oss << " ";
oss << function;
oss << " | ";
oss << message;

output = oss.str();

std::cout << getColourCode(level) << levelToString(level) << ANSI_RESET << output << '\n';
}

