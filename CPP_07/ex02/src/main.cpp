/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/12 16:58:23 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/12 16:58:23 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "Array.hpp"
#include "defines.h"
#include "Fixed.hpp"
#include <iostream>

template <typename T>
void	subscript(Array<T>& arr, int index) {
	std::cout << "Testing array of size: " << arr.size() << " with index: " << index << "\n";
	try {
		arr[index];
		std::cout << GREEN << "Success\n" << RESET;
	}
	catch (std::out_of_range& e) {
		std::cout << RED << e.what() << RESET << "\n";
	}
}

int	main() {

	std::cout << BLUE << "Testing the subject things one by one\n\n" << RESET;

	{
		std::cout << BLUE << "Default constructor\nCreating array, checking if it's size is 0 and trying to access element 0\n" << RESET;
		Array<int>	a;
		std::cout << "size: " << a.size() << "\n";

		try {
			std::cout << "Accessing index 0\n";
			a[0];
		}
		catch (std::exception& e){
			std::cout << RED << e.what() << "\n" << RESET;
		}
	}
	{
		std::cout << BLUE << "\nConstructing with unsigned int\n";

		std::cout << "Creating int with new int(), checking it's default value\n" << RESET;
		int*	num = new int();
		std::cout << *num << "\n";

		std::cout << BLUE << "Creating array of 10 ints, checking the size, if the values are initialized by default\n";
		Array<int>	a(10);
		std::cout << RESET << "size: " << a.size() << "\n";
		std::cout << "array: " << a;

		std::cout << BLUE << "Trying to access index 10\n";
		try {
			a[10];
		}
		catch (std::exception& e){
			std::cout << RED << e.what() << "\n" << RESET;
		}
		delete num;
	}
	{
		std::cout << BLUE << "\nCopy constructor\n\n";
		std::cout << "Creating an array of 10 ints, assigning values 1 to 10\n";
		Array<int>	a(10);
		for (size_t i = 0; i < a.size(); ++i) {
			a[i] = static_cast<int>(i);
		}
		std::cout << RESET << "Created array: " << a;


		std::cout << BLUE << "Creating new array through copy constructor and printing the new array\n";
		Array<int>	b(a);
		std::cout << RESET << "New array: " << b;


		std::cout << BLUE << "Changing values in the copied array and checking if it changed them in the original\n";
		for (size_t i = 0; i < b.size(); ++i) {
			b[i] = rand() % 100 + 10;
		}
		std::cout << RESET << "Original array: " << a;
		std::cout << RESET << "Copied array: " << b;


		std::cout << BLUE << "\nAssignment operator\n\n";
		std::cout << "Making an array of 5 integers and one of 15 integers\n";
		Array<int>	c(5);
		for (size_t i = 0; i < c.size(); ++i) {
			c[i] = static_cast<int>(i);
		}
		Array<int>	d(15);
		for (size_t i = 0; i < d.size(); ++i) {
			d[i] = static_cast<int>(i) + 20;
		}
		std::cout << RESET << "5 int array: " << c;
		std::cout << RESET << "15 int array: " << d;
		std::cout << RESET << "10 int array: " << b;


		std::cout << BLUE << "Assigning the 5 integer array to our previous 10 integer array and printing the values\n";
		b = c;
		std::cout << RESET << "Array after assignment: " << b;


		std::cout << BLUE << "Changing values in the assigned array and checking if it changed them in the original\n";
		for (size_t i = 0; i < b.size(); ++i) {
			b[i] = rand() % 100 + 10;
		}
		std::cout << RESET << "Original array: " << c;
		std::cout << RESET << "Copied array: " << b;


		std::cout << BLUE << "Assigning the 15 integer array to our previous 10 integer array and printing the values\n";
		b = d;
		std::cout << RESET << "Array after assignment: " << b;


		std::cout << BLUE << "Changing values in the assigned array and checking if it changed them in the original\n";
		for (size_t i = 0; i < b.size(); ++i) {
			b[i] = rand() % 100 + 10;
		}
		std::cout << RESET << "Original array: " << d;
		std::cout << RESET << "Copied array: " << b;
	}
	{
		std::cout << BLUE << "\nTesting subscript overloads\n\n";
		std::cout << "Creating array with 10 integers\n" << RESET;
		Array<int>	a(10);
		subscript(a, 0);
		subscript(a, -10);
		subscript(a, 10);
		subscript(a, 11);
		subscript(a, 12312321);
		subscript(a, -12313213);
		subscript(a, -5555);
	}
	{
		std::cout << BLUE << "\nTesting more wacky stuff\n\n";
		std::cout << "Making an array of int arrays, sizes of all these should be 0 (initialised by default with the default constructor)\n" << RESET;
		Array<Array<int>>	arr(5);
		for (size_t i = 0; i < arr.size(); ++i) {
			std::cout << arr[i].size() << "\n";
		}
		std::cout << BLUE << "Giving the arrays in our array of arrays some actual values\n";
		for (size_t i = 0; i < arr.size(); ++i) {
			arr[i] = Array<int>(i + 1);
			for (size_t j = 0; j < arr[i].size(); ++j) {
				arr[i][j] = j;
			}
		}
		std::cout << RESET << "Printing our array of arrays:\n" << arr;

		std::cout << BLUE << "Making array of fixed points\n\n";
		Array<Fixed>	a(10);
		std::cout << RESET << "Array: " << a;
		for (size_t i = 0; i < a.size(); ++i) {
			a[i] = Fixed(3.2f);
		}
		std::cout << RESET << "Array: " << a;

		std::cout << BLUE << "\nMaking array of array of array of array of array of array... \n\n";
		Array<Array<Array<Array<Array<Array<Array<Array<Array<Array<int>>>>>>>>>>	arr2(10);
		std::cout << RESET << "Array: " << arr2;

	}
}
