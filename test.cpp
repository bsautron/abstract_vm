/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 14:35:07 by bsautron          #+#    #+#             */
/*   Updated: 2016/06/08 16:28:51 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstract_vm.hpp"
#include <cstring>

# define TEST_GOOD_THINGS
# define TEST_OVERFLOW

int main(void)
{
	std::string		value;

#ifdef TEST_GOOD_THINGS
	std::cout << "== TEST ZERO ==" << std::endl;
	try {
		value = "0";
		std::cout << "Constructor Operand: [char] " << value << ": ";
		Operand<char>	a(value, INT8);
		std::cout << "Good";
	} catch (std::exception const & e) {
		std::cout << e.what();
	} std::cout << std::endl;
	try {
		value = "-0";
		std::cout << "Constructor Operand: [char] " << value << ": ";
		Operand<char>	a(value, INT8);
		std::cout << "Good";
	} catch (std::exception const & e) {
		std::cout << e.what();
	} std::cout << std::endl;
	try {
		value = "0";
		std::cout << "Constructor Operand: [short] " << value << ": ";
		Operand<short>	a(value, INT16);
		std::cout << "Good";
	} catch (std::exception const & e) {
		std::cout << e.what();
	} std::cout << std::endl;
	try {
		value = "-0";
		std::cout << "Constructor Operand: [short] " << value << ": ";
		Operand<short>	a(value, INT16);
		std::cout << "Good";
	} catch (std::exception const & e) {
		std::cout << e.what();
	} std::cout << std::endl;
	try {
		value = "0";
		std::cout << "Constructor Operand: [int] " << value << ": ";
		Operand<int>	a(value, INT32);
		std::cout << "Good";
	} catch (std::exception const & e) {
		std::cout << e.what();
	} std::cout << std::endl;
	try {
		value = "-0";
		std::cout << "Constructor Operand: [int] " << value << ": ";
		Operand<int>	a(value, INT32);
		std::cout << "Good";
	} catch (std::exception const & e) {
		std::cout << e.what();
	} std::cout << std::endl;

	std::cout << "== TEST BOUND ==" << std::endl;
	try {
		value = "-128";
		std::cout << "Constructor Operand: [char] " << value << ": ";
		Operand<char>	a(value, INT8);
		std::cout << "Good";
	} catch (std::exception const & e) {
		std::cout << e.what();
	} std::cout << std::endl;
	try {
		value = "127";
		std::cout << "Constructor Operand: [char] " << value << ": ";
		Operand<char>	a(value, INT8);
		std::cout << "Good";
	} catch (std::exception const & e) {
		std::cout << e.what();
	} std::cout << std::endl;
	try {
		value = "-32768";
		std::cout << "Constructor Operand: [short] " << value << ": ";
		Operand<short>	a(value, INT16);
		std::cout << "Good";
	} catch (std::exception const & e) {
		std::cout << e.what();
	} std::cout << std::endl;
	try {
		value = "32767";
		std::cout << "Constructor Operand: [short] " << value << ": ";
		Operand<short>	a(value, INT16);
		std::cout << "Good";
	} catch (std::exception const & e) {
		std::cout << e.what();
	} std::cout << std::endl;
	try {
		value = "-2147483648";
		std::cout << "Constructor Operand: [int] " << value << ": ";
		Operand<int>	a(value, INT32);
		std::cout << "Good";
	} catch (std::exception const & e) {
		std::cout << e.what();
	} std::cout << std::endl;
	try {
		value = "2147483647";
		std::cout << "Constructor Operand: [int] " << value << ": ";
		Operand<int>	a(value, INT32);
		std::cout << "Good";
	} catch (std::exception const & e) {
		std::cout << e.what();
	} std::cout << std::endl;


#endif

#ifdef TEST_OVERFLOW
	std::cout << "== TEST OVERFLOW" << std::endl;
	try {
		value = "-129";
		std::cout << "Constructor Operand: [char] " << value << ": ";
		Operand<char>	a(value, INT8);
		std::cout << "ERROR";
	} catch (std::exception const & e) {
		std::cout << e.what();
	} std::cout << std::endl;
	try {
		value = "128";
		std::cout << "Constructor Operand: [char] " << value << ": ";
		Operand<char>	a(value, INT8);
		std::cout << "ERROR";
	} catch (std::exception const & e) {
		std::cout << e.what();
	} std::cout << std::endl;

	try {
		value = "-32769";
		std::cout << "Constructor Operand: [short] " << value << ": ";
		Operand<short>	a(value, INT16);
		std::cout << "ERROR";
	} catch (std::exception const & e) {
		std::cout << e.what();
	} std::cout << std::endl;
	try {
		value = "32768";
		std::cout << "Constructor Operand: [short] " << value << ": ";
		Operand<short>	a(value, INT16);
		std::cout << "ERROR";
	} catch (std::exception const & e) {
		std::cout << e.what();
	} std::cout << std::endl;
	try {
		value = "-2147483649";
		std::cout << "Constructor Operand: [int] " << value << ": ";
		Operand<int>	a(value, INT32);
		std::cout << "ERROR";
	} catch (std::exception const & e) {
		std::cout << e.what();
	} std::cout << std::endl;
	try {
		value = "2147483648";
		std::cout << "Constructor Operand: [int] " << value << ": ";
		Operand<int>	a(value, INT32);
		std::cout << "ERROR";
	} catch (std::exception const & e) {
		std::cout << e.what();
	} std::cout << std::endl;

	//TODO: Add test for float/double

#endif

	return (0);
}
