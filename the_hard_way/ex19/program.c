#include "gdb.h"
#include <stdlib.h>
#include <stdio.h>

void test_debug() {
	// notice we dont need the \n
	debug("I have a bug here");

	// passing in arguments like printf
	debug("I am %d years old bug", 10);
}

void test_log_err() {
	log_err("I beleive everything is broken.");
	log_err("There are %d bugs in %s", 10 , "Here");
}

void test_log_warn() {
	log_warn("you can safly ignore this");
	log_warn("maybe consider looking %s","there");
}

void test_log_info() {
	log_info("we i did somthing mundane");
	log_info("it happened %f times a day", 1.3f);
}


