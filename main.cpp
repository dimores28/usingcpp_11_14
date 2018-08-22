#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


initializer_list<int> func()
{
	return {};
}

template<class T>
ostream & operator<<(ostream& os, const initializer_list<T>& i)
{
	if (!i.size())
		return os << "{}";

	os << "{";
	for_each(i.begin(), prev(i.end()), [&](const auto & item) {os << item << ", "; });
	return os << *prev(i.end()) << "}";
}

//int main() Списки инициализации
//{
//	initializer_list<int>{1, 2, 3};
//	auto l1 = {1,2,3};
//	auto l2 = { "a","b","c"};
//	initializer_list<initializer_list<int>> l3 = { {1,2,3},{1,2}, {4,5,6} };
//
//
//	cout << l1 << endl;
//	cout << l2 << endl;
//	cout << l3 << endl;
//
//
//	return 0;
//}


//vector<void*>& VecT(void* vec)
//{
//	return *static_cast<vector<void*>*>(vec); 
//};

//decltype(auto) VecT(void* vec)
//{
//	return *static_cast<vector<void*>*>(vec);
//};


decltype(auto) get()// окуратно с decltype возвращает ссылку если переменую обернуть в скобки (return (i);)
{
	int i = 42;
	return (i);
}

//int main()   Динамическое выведение типов 
//{
//	int i1 = 1;
//	int i2 = 2;
//	string s = "s";
//
//	void* v = new vector<void*>{&i1, &i2, &s};
//
//	//((vector<void*>*)v)->push_back(v);
//	//const static auto VecT = [](void* vec) {return static_cast<vector<void*>*>(vec); };
//	const static auto VecT = [](void* vec) ->decltype(auto) {return *static_cast<vector<void*>*>(vec); };
//
//	//static_cast<vector<void*>*>(v)->push_back(v);
//	VecT(v).push_back(v);
//
//	cout << ((vector<void*>*)v)->size() << endl;
//	cout << get() << endl;
//
//	delete v;
//
//
//	return 0;
//}

//struct A {
//
//	virtual void a(){}
//	virtual ~A(){}
//};
//
//struct B final : public A {
//
//	virtual void a() override
//	{
//
//	}
//};

//namespace {
//	void foo(A*& i)
//	{
//		
//	}
//}


class A {
public:
	A(): i(42), s("Hi"){}
private:
	int i ;
	string s ;
public:
	void print()
	{
		cout << i << " " << s << endl;
	}

	virtual ~A(){}
};


struct Hack {
	int i;
	string s;

	virtual ~Hack() {}
};



int main()
{

	/*B i1;
	B* i2 = &i1;
	foo((A*&)i2);

	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
*/


	A a;
	((Hack*)&a)->i = 789;

	a.print();

	vector<int> v{ 42,13,14 };
	vector<int> v2{ 7,7,14 };

	struct VecHack
	{
		int* begin;
		int* end;
	};


	*((VecHack*)&v)->begin = *((VecHack*)&v2)->begin;
	cout << *v.begin() << endl;

	
	return 0;
}