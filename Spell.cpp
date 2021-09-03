#include <string>

// Base Class
// Known to EXE and to this plugin library
class Phrase {
public:
  virtual std::string get_name() = 0;
  virtual ~Phrase();
};
Phrase::~Phrase() = default;

// Derived Class
// Implementation provided by this plugin library
class Spell : public Phrase {
public:
  Spell(std::string name) : name_(name){}
  ~Spell() = default;
  std::string get_name() override { return name_; }
private:
  const std::string name_;
};

extern "C"
__declspec(dllexport) // This is required
Spell* create_spell(std::string name) {
	return new Spell(name);
}