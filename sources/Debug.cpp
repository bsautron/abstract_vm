#include <Debug.hpp>

Debug::Debug(void) {}
Debug::~Debug(void) {}

void Debug::logger(int level, std::string const message) {
	Debug::debugLevel[level].outStream << "\033[" << Debug::debugLevel[level].colorCode << ";" << Debug::debugLevel[level].backCode << "m[" << Debug::debugLevel[level].prefix << "]: " << message << "\033[0m" << std::endl;
}

void Debug::log(std::string const message) {
	Debug::logger(DLV_LOG, message);
}

void Debug::info(std::string const message) {
	Debug::logger(DLV_INFO, message);
}

void Debug::warning(std::string const message) {
	Debug::logger(DLV_WARNING, message);
}

void Debug::error(std::string const message) {
	Debug::logger(DLV_ERROR, message);
}

void Debug::fatal(std::string const message) {
	Debug::logger(DLV_FATAL, message);
}

tDebugLevel Debug::debugLevel[] = {
	{"log", 37, 5, std::cout},
	{"info", 34, 5, std::cout},
	{"warning", 33, 5, std::cout},
	{"error", 31, 5, std::cout},
	{"fatal", 31, 1, std::cout}
};
