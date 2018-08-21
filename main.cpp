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

int main()
{
	int i1 = 1;
	int i2 = 2;
	string s = "s";

	void* v = new vector<void*>{&i1, &i2, &s};

	//((vector<void*>*)v)->push_back(v);
	//const static auto VecT = [](void* vec) {return static_cast<vector<void*>*>(vec); };
	const static auto VecT = [](void* vec) ->decltype(auto) {return *static_cast<vector<void*>*>(vec); };

	//static_cast<vector<void*>*>(v)->push_back(v);
	VecT(v).push_back(v);

	cout << ((vector<void*>*)v)->size() << endl;
	cout << get() << endl;

	delete v;


	return 0;
}