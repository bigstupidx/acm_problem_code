#include <iostream>

template<typename C>
void print2nd(const C& container){
	if(container.size()>=2){
	typename C::const_iterator itr(container.begin());
		++itr;
		int value = *itr;
		std::cout<<value;
	}
}
