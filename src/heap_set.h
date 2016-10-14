#ifndef HEAP_SET_H
#define HEAP_SET_H

#include <vector>
#include <stdio.h>
template <typename T> class heap_set: public std::vector<T> {
public:
    heap_set(void) { size = 0; this->reserve(100); };
    void insert(T element) {
		if(size == 0){
			this->push_back(element);
			size++;
			return;
		}
		if(size == this->capacity() -1){
			this->reserve(100);
		}
			int pos = ++size;
//		std::cout << std::to_string(this->size()) << std::endl;

			for(;pos>1 && element < this->at(pos/2) ; pos = pos/2) {
				std::cout << this->at(pos/2) << std::endl;
				this->at(pos) = this->at(pos / 2);
			}

//		std::cout << this->at(pos)<< std::endl;
//		std::cout << pos << std::endl;

		this->at(pos) = element;
	};
    void remove(T element) {
		int toRem;
		std::cout << size << std::endl;
		for(int i = 0 ; i <= size ; i++){
			if(element == this->at(i)){
				toRem = i;
				std::cout << toRem << std::endl;
			}
			std::cout << i << std::endl;
		}

		T tmp = this->at(toRem);
		int child;

		for(; 2*toRem <= size; toRem = child)
		{
			child = 2*toRem;

			if(child != size && this->at(child) > this->at(child + 1))
			{
				child++;
			}

			if(tmp < this->at(child)) {this->at(toRem) = this->at(child);}
			else
				break;
		}
		size--;
		this->at(toRem) = tmp;

	};
    virtual ~heap_set() {};
private:
    unsigned size;
};
#endif //HEAP_SET_H
