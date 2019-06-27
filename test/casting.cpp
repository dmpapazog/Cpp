#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

class BaseException : public runtime_error
{
 public:
  BaseException(const string& leftName, const string& rightName,
                const char* action)
      : runtime_error("")
  {
    stringstream oss;

    oss << "Can't " << action << " to \"" << leftName << "\" from \""
        << rightName << "\". "
        << "\"" << rightName << "\" is empty.\n";

    static_cast<runtime_error&>(*this) = runtime_error(oss.str());
  }
};

class Base
{
 private:
  int* m_x{new int(-1)};
  string m_name{"Uknown"};

 public:
  Base()
  {
    cout << "Default constructor of \"" << m_name << "\".\n";
  }

  explicit Base(const string& t_name) : m_name(t_name)
  {
    cout << "Empty constructor of \"" << m_name << "\".\n";
  }

  explicit Base(int t_x, const string& t_name)
      : m_x(new int(t_x)), m_name(t_name)
  {
    cout << "Conversion constructor of \"" << m_name << "\".\n";
  }

  Base(const Base& old, const string& t_name) : m_name(t_name)
  {
    if (!old.m_x) {
      throw BaseException(m_name, old.m_name, "copy");
    }
    cout << "Copy constructor \"" << m_name << "\" from \"" << old.m_name
         << "\".\n";

    *m_x = *old.m_x;
  }

  Base(Base&& old, const string& t_name) : m_name(t_name)
  {
    if (!old.m_x) {
      throw BaseException(m_name, old.m_name, "move");
    }
    cout << "Move constructor \"" << m_name << "\" from \"" << old.m_name
         << "\".\n";

    m_x = old.m_x;
    old.m_x = nullptr;
  }

  ~Base()
  {
    cout << "Destructor of \"" << m_name << "\".\n";
    delete m_x;
  }

  const Base& operator=(const Base& rhs)
  {
    if (!rhs.m_x) {
      throw BaseException(m_name, rhs.m_name, "copy");
    }
    cout << "Copy assignement \"" << m_name << "\" from \"" << rhs.m_name
         << "\".\n";

    *m_x = *rhs.m_x;
    return *this;
  }

  const Base& operator=(Base&& rhs)
  {
    if (!rhs.m_x) {
      throw BaseException(m_name, rhs.m_name, "move");
    }
    cout << "Move assignement \"" << m_name << "\" from \"" << rhs.m_name
         << "\".\n";

    m_x = rhs.m_x;
    rhs.m_x = nullptr;
    return *this;
  }

  int getMember() const { return (!m_x) ? throw runtime_error(getName() + " is empty") : *m_x; }

  string getName() const { return m_name; }

  friend ostream& operator<<(ostream& out, const Base& obj);
};

ostream& operator<<(ostream& out, const Base& obj)
{
  out << obj.m_name << ": ";
  try {
    out << obj.getMember();
  } catch (const exception& e) {
    out << "Caught exception: " << e.what();
  }
  out << '\t';
  return out;
}

int main()
{
  Base b1("b1");
  Base b2(1, "b2");
  Base b3(b2, "b3");
  Base b4(move(b1), "b4");
  cout << '\n';

  Base b5("b5");
  Base b6("b6");
  b5 = b2;
  b6 = move(b3);

  try {
    b5 = b1;
  } catch (const exception& e) {
    cout << "Caught exception: " << e.what();
    // return EXIT_FAILURE;
  }

  cout << b1 << b2 << b3 << b4 << '\n';
  cout << b5 << b6 << '\n';

  return EXIT_SUCCESS;
}