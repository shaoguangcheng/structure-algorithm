/**
*@file : in this file, I will test how to use construct a handle class and use it
*		it to manage  the pointer of base class
*/

#include <iostream>
#include <vector>
#include <cstddef>

using namespace std;

class base{
	public :
	base(){}
	base(int x) : x(x){}

	virtual ~base(){}

	virtual int get() const{return x;} // in order to obtain certain behaviour when running, define it virtual

	virtual base* clone() const{return new base(*this);} // for handle class use

	protected :
	int x;
};

class derived : public base{
	public :
	derived(){}
	derived(int x, int y) : base(x), y(y){}

	virtual int get() const {return x+y;}

	virtual derived* clone() const {return new derived(*this);} // for handle class use

	private :
	int y;
};

// use handle class to cover the base class pointer, manage base pointer
// In this way, users do not need to handle the pointer when use dynamic binding
template <class T>
class handle{
	public :
	handle() : ptr(0), use(new size_t(1)){}
	handle(T* p) : ptr(p), use(new size_t(1)){} 
	handle(const handle& h) : ptr(h.ptr), use(h.use){++*use;}
	~handle(){decreaseUse();}

	handle& operator = (const handle& rhs){
		++*rhs.use;
		decreaseUse();
		ptr = rhs.ptr;
		use = rhs.use;

		return *this;
	}

	T* operator -> (){
		if(ptr)
			return ptr;
		else 
			throw logic_error("unbounded handle error");
		}

	T& operator * (){
		if(ptr)
			return *ptr;
		else
			throw logic_error("unbounded handle error");
	}

	// process const base
	const T* operator -> () const {
		if(ptr)
			return ptr;
		else 
			throw logic_error("unbounded handle error");
		}

	const T& operator * () const {
		if(ptr)
			return *ptr;
		else
			throw logic_error("unbounded handle error");
	}

	private :
	T* ptr;
	size_t* use;
	void decreaseUse(){
		if(--*use == 0){
			delete ptr;
			delete use;
		}
	}
};

int main()
{
	vector<base> v;
	base b(1);
	derived d(2,3);

	v.push_back(b);
	v.push_back(d);

	cout << "when store object itself : " << endl;
	cout << v[0].get() << endl;
	cout << v[1].get() << endl;

	vector<base*> vp;

	vp.push_back(&b);
	vp.push_back(&d);

	cout << "when store object pointer : " << endl;
	cout << vp[0]->get() << endl;
	cout << vp[1]->get() << endl;	

	/*
	*	the above code proves that only pointer has multi-modal
	*/

	vector<handle<base> > vh;

	handle<base> h1(b.clone());
	handle<base> h2(d.clone());

	vh.push_back(h1);
	vh.push_back(h2);

	vector<handle<base> >::const_iterator it;
	cout << "using handle class to store multi-inherited object : " << endl;
	for(it = vh.begin(); it != vh.end(); ++it){
		cout << (*it)->get() << endl; // call const T* operator -> () const, and call base::get() 
									  //when *it is an object of base class and call derived::get if *it
									  // is an object of derived class
	}

	return 0;
}