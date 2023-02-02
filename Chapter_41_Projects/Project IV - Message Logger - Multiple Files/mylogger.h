#ifndef MYLOGGER_H
#define MYLOGGER_H

#include <iostream>
#include <string>
#include <fstream>

namespace nm
{
	// different logging verbosity levels
	enum class LoggingLevels
	{
		LOG_INFO,
		LOG_WARNING,
		LOG_ALL
	};

	const std::string defaultlogfile = "defaultlogfile.txt";

	class MyLogger
	{
	private:
		std::fstream fs;
		std::string messagestart;
	public:
		void logToFile(const std::string& message);
		void logToConsole(const std::string& message);
		void logWithLevel(const std::string& message, LoggingLevels loglevel);
		void logToAll(const std::string& message);

		MyLogger(); // user-provided default constructor
		explicit MyLogger(const std::string& customlogfile); // user-provided constructor
		MyLogger(const MyLogger& rhs) = delete; // disable the copy constructor
		MyLogger& operator=(const MyLogger& rhs) = delete; // disable the copy assignment operator
		MyLogger(MyLogger&& rhs) noexcept; // move constructor
		MyLogger& operator=(MyLogger&& rhs) noexcept; // move assignment operator
		~MyLogger(); // destructor
	};
}

#endif // !MYLOGGER_H