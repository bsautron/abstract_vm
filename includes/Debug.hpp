/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debug.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:04:54 by bsautron          #+#    #+#             */
/*   Updated: 2016/12/01 21:04:55 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_HPP
# define DEBUG_HPP

# include <iostream>

enum eDebugLevel {
	DLV_LOG,
	DLV_INFO,
	DLV_WARNING,
	DLV_ERROR,
	DLV_FATAL
};

typedef struct	sDebugLevel {
	std::string		prefix;
	int				colorCode;
	int				backCode;
	std::ostream &	outStream;
}				tDebugLevel;

class Debug {
private:
	Debug(Debug const & src);
	Debug & operator=(Debug const & rhs);

public:
	Debug(void);
	~Debug(void);

	static void log(std::string const message);
	static void info(std::string const message);
	static void warning(std::string const message);
	static void error(std::string const message);
	static void fatal(std::string const message);
	static void logger(int level, std::string const message);

	static tDebugLevel debugLevel[];
};

#endif
