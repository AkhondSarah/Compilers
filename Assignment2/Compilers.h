//#pragma once
/*************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Fall, 2020
* This Code is EXCLUSIVE for professors (must not be shared)
* Author: Paulo Sousa - Sep, 2020.
*************************************************************
* File name: compilers.h
* Compiler: MS Visual Studio 2019
* Author: Paulo Sousa
* Course: CST 8152 ? Compilers, Lab Section: [011, 012, 013, 021, 022, or 023]
* Assignment: A1, A2, A3.
* Date: Sep 01 2020
* Professor: Paulo Sousa / Haider Miraj
* Purpose: This file defines the functions called by main function.
* Function list: mainBuffer(), mainScanner(), mainParser().
*************************************************************/

#ifndef COMPILERS_H_
#define COMPILERS_H_

#define DEBUG 1

/* Buffer Modes */
enum PROGRAMS {
	PGM_BUFFER = '0',
	PGM_SCANNER = '1',
	PGM_PARSER = '2'
};

int mainBuffer(int argc, char** argv);
int mainScanner(int argc, char** argv);
int mainParser(int argc, char** argv);

#endif
