#include <cstdlib>
#include <iostream>
#include <memory>
#include <typeinfo>

using namespace std;



template<class Derived, class... Bases>
class Cloning : public Bases... {
	private:
		virtual Cloning* cloneImpl() const override
		{
			return new Derived(static_cast<const Derived&>(*this));
		}
	
	public:
		virtual ~Cloning() = default;
		
		unique_ptr<Derived> clone() const
		{
			return unique_ptr<Derived>(static_cast<Derived *>(this->cloneImpl()));
		}
};

template<class Derived>
class Cloning<Derived> {
	private:
		virtual Cloning* cloneImpl() const = 0;
	
	public:
		virtual ~Cloning() = default;
		
		unique_ptr<Derived> clone() const
		{
			return unique_ptr<Derived>(static_cast<Derived *>(this->cloneImpl()));
		}
};

class InterfaceInt : public Cloning<InterfaceInt> {
	public:
  	virtual int getInt() const = 0;
};

class InterfaceDouble : public Cloning<InterfaceDouble> {
	public:
  	virtual double getDouble() const = 0;
};

class Derived : public Cloning<Derived, InterfaceInt, InterfaceDouble> {
	private:
  	unique_ptr<int> m_x{nullptr};
		double m_y{0};

	public:
  	Derived();
  	Derived(int t_x = 2, double t_y = 3.14)
			: m_x{make_unique<int>(t_x)},
				m_y{t_y}
		{
		}

		Derived(const Derived& old)
			: m_x{make_unique<int>(*old.m_x)},
				m_y{old.m_y}	
		{
		}

  	int getInt() const override { return *m_x; }
  	double getDouble() const override { return m_y; }
		~Derived() { cout << "\nDeleting derived."; };
};

void printInt(const unique_ptr<InterfaceInt>& up);
void printDouble(const unique_ptr<InterfaceDouble>& up);

int main()
{
  auto a = make_unique<Derived>(2, 3.14);
	// cout << typeid(a.get()).name() << '\n';

	// InterfaceInt *readingPtr1 = a.get();
	// auto b = readingPtr1->clone();
	// cout << typeid(b.get()).name() << '\n';
  
	// InterfaceDouble *readingPtr2 = a.get();
	// auto c = readingPtr2->clone();
	// cout << typeid(c.get()).name() << '\n';

	printInt(static_cast<const InterfaceInt *const>(a.get())->clone());
	printDouble(static_cast<const InterfaceDouble *const>(a.get())->clone());
  return EXIT_SUCCESS;
}

void printInt(const unique_ptr<InterfaceInt>& up)
{
	cout << '\n' << up->getInt();
}

void printDouble(const unique_ptr<InterfaceDouble>& up)
{
	cout << '\n' << up->getDouble();
}