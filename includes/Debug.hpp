#ifndef DEBUG_HPP
# define DEBUG_HPP

# include <iostream>

enum eDebugLevel {
	DLV_LOG,
	DLV_INFO,
	DLV_WARNING,
	DLV_ERROR
};

typedef struct	sDebugLevel {
	std::string		prefix;
	int				colorCode;
	std::ostream &	outStream;
}				tDebugLevel;

class Debug {
public:
	Debug(void);
	~Debug(void);

	static void Log(std::string const message);
	static void Info(std::string const message);
	static void Warning(std::string const message);
	static void Error(std::string const message);
	static void Logger(int level, std::string const message);

	static tDebugLevel debugLevel[4];
};

#endif /* end of include guard: DEBUG_HPP */
