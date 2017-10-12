# C Data Structures & Algorithms (c-dsa)

A growing library of data structures and algorithms in C.  
Current data structure implementations:

* Singly Linked List (src/data-structures/list.h)
* Queue (src/data-structures/queue.h)
* Stack (src/data-structures/stack.h)

Current algorithm implementations:

Nothing here yet...

## Build Requirements

This application uses the GNU Build System.  
To compile and run the test application the following software packages are required:

* [autoconf](http://ftp.gnu.org/gnu/autoconf/)
* [automake](http://ftp.gnu.org/gnu/automake/)

To install the above packages:

	$ cd [autoconf-download-dir]
	$ ./configure
	$ make
	$ sudo make install

	$ cd [automake-download-dir]
	$ ./configure
	$ make
	$ sudo make install	

## Testing 

* Run `git clone https://github.com/njacks/c-dsa` to clone the repository
* Run `autoreconf -vi` to generate the build system files
* Run `cd build && ../configure && make test` to change directory to the build directory, configure and build the project
* Run `./test` to run the test application in the build directory
* Optionally run `make clean` to clean the build directory

## Example Applications

Nothing here yet...