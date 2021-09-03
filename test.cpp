#include <iostream>
#include <string>

// Local File, For dlopen/LoadLibrary, dlsym/GetProcAddress, dlclose/FreeLibrary
#include "dlfcn.hpp"

// Base Class
// Known to this EXE and to plugin library
class Phrase {
public:
	virtual std::string get_name() = 0;
	virtual ~Phrase();
};
Phrase::~Phrase() = default;

// Function Pointer
// Needed so this EXE knows what arguments
// The plugin libraries function requires
typedef Phrase* (*CREATOR_FUNCTION)(std::string name);

int main(void) {

	auto library = dlopen("Spell.dll", RTLD_LAZY);

	auto creator_function = (CREATOR_FUNCTION)dlsym(library, "create_spell");

	// Call the creator function that was imported from the library
	Phrase* phrase = creator_function("Protego");

	std::cout << phrase->get_name() << std::endl;

	dlclose(library);

	return 0;
}