#include "Stack.h"
/*
Why all implementations are in Stack.h:

This Stack class is implemented as a template (template<class T>). In C++, 
templates are not compiled into code until they are used with a specific type 
(e.g., Stack<int>, Stack<string>). Because of this, the compiler must be able 
to see the full implementation of all template functions at the time of use.

If the function definitions were placed in Stack.cpp, the compiler would only 
see the declarations in Stack.h and would not be able to generate the correct 
code for each template type, leading to linker errors (undefined references).

To avoid this, all template definitions (constructor, push, pop, peek, etc.) 
are included in the header file so they are visible wherever the template is used.
*/