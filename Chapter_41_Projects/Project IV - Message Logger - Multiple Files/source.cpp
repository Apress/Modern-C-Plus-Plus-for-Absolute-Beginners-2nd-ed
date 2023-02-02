#include "mylogger.h"

int main()
{
	// create an object using the default log file name
	nm::MyLogger o1;
	o1.logToConsole("Console log message 1.");
	o1.logToFile("Default file name log message 1.");
	o1.logWithLevel("Console log message 2.", nm::LoggingLevels::LOG_INFO);
	o1.logToAll("Logging to both the console and a file from o1.");

	// create an object using a custom log file name
	nm::MyLogger o2{ "mylogfile.txt" };
	o2.logToConsole("Console log message 1.");
	o2.logToFile("Custom file name log message 1.");
	o2.logWithLevel("Console log message 3.", nm::LoggingLevels::LOG_WARNING);
	o2.logToAll("Logging to both the console and a file from o2.");

	// create an object using a move operation
	nm::MyLogger o3 = std::move(o2);
	o3.logToAll("Logging to both the console and a file from o3.");
}
