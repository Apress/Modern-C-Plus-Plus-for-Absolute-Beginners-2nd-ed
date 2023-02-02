#include "mylogger.h"

namespace nm
{
	void MyLogger::logToFile(const std::string& message)
	{
		messagestart = "FILE log: ";
		fs << message << '\n';
	}

	void MyLogger::logToConsole(const std::string& message)
	{
		messagestart = "CONSOLE log: ";
		std::cout << messagestart << message << '\n';
	}

	void MyLogger::logWithLevel(const std::string& message, LoggingLevels loglevel)
	{
		switch (loglevel)
		{
		case LoggingLevels::LOG_INFO:
			logToConsole("Log level INFO: " + message);
			break;
		case LoggingLevels::LOG_WARNING:
			logToConsole("Log level WARNING: " + message);
			break;
		case LoggingLevels::LOG_ALL:
			logToConsole("Log level ALL: " + message);
			break;
		default:
			logToConsole("No logging level: " + message);
			break;
		}
	}

	void MyLogger::logToAll(const std::string& message)
	{
		logToConsole(message);
		logToFile(message);
	}

	// default constructor
	MyLogger::MyLogger()
	{
		fs.open(defaultlogfile, std::ios::app);
		messagestart = "Started logging to a default file. ";
	}

	// user-provided constructor
	MyLogger::MyLogger(const std::string& customlogfile) {
		messagestart = " Started logging. ";
		fs.open(customlogfile, std::ios::app); // open the file
	}

	// move constructor
	MyLogger::MyLogger(MyLogger&& rhs) noexcept
		:fs{ std::move(rhs.fs) }, messagestart{ rhs.messagestart }
	{
	}

	// move assignment operator
	MyLogger& MyLogger::operator=(MyLogger&& rhs) noexcept
	{
		messagestart = std::move(rhs.messagestart);
		fs = std::move(rhs.fs);
		return *this;
	}

	// destructor
	MyLogger::~MyLogger()
	{
		fs.close(); // close the file
	}
}