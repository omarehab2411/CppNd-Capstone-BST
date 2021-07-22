# CPPND: Capstone Generic Binary Search tree Implementation Repo

This is a repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

## Project description
* This projects Implements a generic Binary search tree data structure and by generic I mean that the user can create a node of any data type this concept is possible 
  by using C++ class templates which is knows as "Generic programming".

* The Project Implement the BST data structure then allow the user to play with the BST through an Interface as follows 
  * Press 's' to show the BST Visulaization.
  * Press 'i' to insert a new node to the BST.
  * press 'f' to find a node in the BST.'
  * press 't' to travese BST in Inorder, Preorder and Post order
  * Press 'q' to quit the program. 

* The BST is implemented inside (BST.h) which consists of a Node and BST class templates both classes encapsulates the full implementation of the BST.
* The BST supports the following opeartions
  * Insert 
  * Search
  * Find
  * Traverse    

## Covered Rubric Points
  Covered Points|  Where It is covered
--------------- | -------------
The project demonstrates an understanding of C++ functions and control structures.| BST.h file
The project accepts user input and processes the input. | "main.cpp" line 30
The project uses Object Oriented Programming techniques.| BST.h
Classes use appropriate access specifiers for class members.|"BST.h" BST and Node classes
Class constructors utilize member initialization lists.|"BST.h" BST and Node classes
Templates generalize functions in the project.|"BST.h" BST and Node classes
The project uses destructors appropriately.|"BST.h" BST class destroy function


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./HelloWorld`.
