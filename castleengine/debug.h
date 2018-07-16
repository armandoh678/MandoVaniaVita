#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED
#include <psp2/kernel/processmgr.h>
#include <sstream>
#include <vector>
#include <cstdio>

#define Logger_MSGL(x) {   \
	std::stringstream output; \
		output << x;\
	output << std::endl;\
	printf("%s\n", output.str().c_str());\
                    }


#endif // DEBUG_H_INCLUDED
