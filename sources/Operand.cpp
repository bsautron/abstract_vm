/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:10:31 by bsautron          #+#    #+#             */
/*   Updated: 2016/12/01 21:10:32 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Operand.hpp>

template<>
Operand<char>::Operand(std::string const & value) : _type(INT8) {
	this->_checker(value);
}

template<>
Operand<short>::Operand(std::string const & value) : _type(INT16) {
	this->_checker(value);
}

template<>
Operand<int>::Operand(std::string const & value) : _type(INT32) {
	this->_checker(value);
}

template<>
Operand<float>::Operand(std::string const & value) : _type(FLOAT) {
	this->_checker(value);
}

template<>
Operand<double>::Operand(std::string const & value) : _type(DOUBLE) {
	this->_checker(value);
}

template<>
std::string	Operand<void>::stringType[] = {
	"Int8",
	"Int16",
	"Int32",
	"Float",
	"Double"
};

std::ostream & operator<<(std::ostream & os, IOperand const & rhs) {
	os << rhs.toString();
	return (os);
}

template<typename T>
bool Operand<T>::assumePrecision = false;
