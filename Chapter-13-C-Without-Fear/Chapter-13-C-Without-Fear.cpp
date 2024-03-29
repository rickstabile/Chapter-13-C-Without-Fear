﻿// Chapter-13-C-Without-Fear.cpp : Defines the entry point for the console application.
//

// I just encountered a code challenge similar to this, only in Java.
// And all the operations had to be external to main().
// 
// Question: Do the newer versions of Java have the generator construct like Python?
//           C++ probably doesn't; we'd be expected to program it in or something. 
// This sort of problem would be really straight-forward using "yield" ...

#include "stdafx.h"

#include <iostream>
#include <cstring>		// Using old-style cdstrings so we can 
						// use the strtok function
#include <stack>

using namespace std;

#define MAX_CHARS 100

int main()
{
	char input_str[MAX_CHARS], *p;
	stack<double> num_stack;
	int c;
	double a, b, n;

	cout << "Enter RPN string: ";
	cin.getline(input_str, MAX_CHARS);
	p = strtok(input_str, " ");

	while (p) {
		c = p[0];
		
		// I'm not dealing with figuring out how fix a C2106 error,
		// telling me '=': left operand must be l-value.
		// Screw it. Send the condition to a boolean and check the boolean.
		bool operatorFlag = (c == '+') ||
			                (c == '*') ||
			                (c == '/') ||
			                (c == '-');

		if (operatorFlag) {
			if (num_stack.size() < 2) {
				cout << "Error: too many ops." << endl;
				system("PAUSE");
				return -1;
			}

			b = num_stack.top(); num_stack.pop();
			a = num_stack.top(); num_stack.pop();

			switch (c) {
			case '+': n = a + b; break;
			case '-': n = a - b; break;
			case '*': n = a * b; break;
			case '/': n = a / b; break;
			}
			num_stack.push(n);
		}
		else {
			num_stack.push(atof(p));
		}

		p = strtok(nullptr, " ");
	}

	cout << "The answer is: " << num_stack.top() << "." << endl;
	system("PAUSE");

	return 0;
}

