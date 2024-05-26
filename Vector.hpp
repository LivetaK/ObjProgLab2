#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <algorithm>
#include <limits>


using namespace std;

const int DEFAULT_VECTOR_SIZE = 10;

template <typename T>
class Vector {
private:
	int size;
	int capacity;
	T* elements;

public:
	// MEMBER TYPES 
	using value_type = T;
	using iterator = T*;
	using const_iterator = const T*;
	using reference = T&;
	using const_reference = const T&;
	using size_type = int;

//*************************************************************************************************************************

	Vector() {									// Vector<int> v; - konstruktorius
		size = 0;
		capacity = DEFAULT_VECTOR_SIZE;
		elements = new T[DEFAULT_VECTOR_SIZE];
	}

	~Vector() {									// Destruktorius
		delete[] elements;

	}

//*************************************************************************************************************************

	//RULE OF FIVE

	Vector(const Vector<T>& copy) {				// Vector<int> v(w); - kopijavimo kosntruktorius
		size = copy.size;
		capacity = copy.capacity;
		elements = new T[capacity];
		for (int i = 0; i < copy.size; i++) {
			elements[i] = copy.elements[i];
		}
	}


	Vector& operator = (const Vector<T>& copy) {	// v = w; - kopijavimo priskyrimo operatorius
		if (this != &copy) {
			if (copy.size > capacity) {
				delete[] elements;
				capacity = copy.size * 2;
				elements = new T[capacity];
			}
			for (int i = 0; i < copy.size; i++) {
				elements[i] = copy.elements[i];
			}
			size = copy.size;
		}
		return *this;
	}

	Vector(Vector<T>&& kitas) noexcept				// -perkelimo konstruktosius
	:	size(kitas.size),
		capacity(kitas.capacity),
		elements(kitas.elements)
	{
			kitas.size = 0;
			kitas.capacity = 0;
			kitas.elements = nullptr;
	}

	Vector& operator=(Vector<T>&& kitas) noexcept { // perkelimo priskyrimo operatorius
		if (this != &kitas) {
			delete[] elements;
			size = kitas.size;
			capacity = kitas.capacity;
			elements = kitas.elements;
			kitas.size = 0;
			kitas.capacity = 0;
			kitas.elements = nullptr;
		}
		return *this;
	}

//*************************************************************************************************************************

	// ITERTAORS
	T* Begin() {							// v.Begin()
		return elements;
	}
	T* End() {								//v.End()
		return elements + size;
	}
	
//*************************************************************************************************************************


	// CAPACITY

	int Size() const {							// v.Size()
		return size;
	}

	int Capacity() const {						// v.Capacity()
		return capacity;
	}

	bool IsEmpty() const {						// v.IsEmpty()
		return size == 0;
	}

	int MaxSize() const {
		return numeric_limits<int>::max();
	}

	void Resize(int newSize) {
		if (newSize > capacity) {
			Reserve(newSize);
		}
		if (newSize > size) {
			for (int i = size; i < newSize; ++i) {
				elements[i] = T();
			}
		}
		size = newSize;
	}

	void Reserve(int newCapacity) {
		if (newCapacity > capacity) {
			T* newElements = new T[newCapacity];
			for (int i = 0; i < size; ++i) {
				newElements[i] = move(elements[i]);
			}
			delete[] elements;
			elements = newElements;
			capacity = newCapacity;
		}
	}

	void ShrinkToFit() {
		if (capacity > size) {
			T* newElements = new T[size];
			for (int i = 0; i < size; ++i) {
				newElements[i] = move(elements[i]);
			}
			delete[] elements;
			elements = newElements;
			capacity = size;
		}
	}

//*************************************************************************************************************************

	// ELEMENT ACCESS

	T& operator [](int index) {					// v[i] = x
		if (index < 0 || index >= size) {
			throw out_of_range("Netinkamas indeksas");
		}
		return elements[index];
	}

	const T& operator [](int index) const {		// x = v[i]
		if (index < 0 || index >= size) {
			throw out_of_range("Netinkamas indeksas");
		}
		return elements[index];
	}

	T& Front() {
		return elements[0];
	}

	T& Back() {
		return elements[size - 1];
	}

//*************************************************************************************************************************

	// MODIFIERS

	void Assign(int n, const T& value) {		// v.Assign(10, 0)
		Resize(n);
		for (int i = 0; i < size; i++) {
			elements[i] = value;
		}
	}

	void PushBack(const T& object) {			// v.PushBack('a')
		if (size == capacity) {
			Reserve(capacity * 2);
		}
		elements[size] = object;				// eina i paskutine pozicija ir ideda nauja elementa
		size++;									//pridejus nauja elementa gale, padidinam ir size
	}

	void PopBack() {							// v.PopBack()
		if (size > 0) {
			size--;
		}
	}

	void Insert(int index, const T& value) {		// v.Insert(0, 'a')
		if (index < 0 || index > size) {
			throw out_of_range("Netinkamas indeksas");
		}
		if (size == capacity) {
			Resize(capacity * 2);
		}
		for (int i = size; i > index; i--) {
			elements[i] = elements[i - 1];
		}
		elements[index] = value;
		size++;
	}

	void Erase(int index) {						// v.Erase(1)
		if (index < 0 || index >= size) {
			throw out_of_range("Netinkamas indeksas");
		}
		for (int i = index; i < size - 1; i++) {
			elements[i] = elements[i + 1];
		}
		size--;
	}

	void Clear() {								// v.Clear()
		size = 0;
	}

	void Swap(Vector<T>& first, Vector<T>& second) {		// Swap(v,w)
		swap(first.size, second.size);
		swap(first.capacity, second.capacity);
		swap(first.elements, second.elements);
	}

//*************************************************************************************************************************

	// NON_MEMBER FUNCTION OVERLOADS

	friend bool operator == (const Vector<T>& first, const Vector<T>& second) {
		if (first.Size() != second.Size()) {
			return false;
		}
		else {
			for (int i = 0; i < first.Size(); i++) {
				if (first.elements[i] != second.elements[i]) {
					return false;
				}
			}
		}
		return true;
	}

	friend bool operator != (const Vector<T>& first, const Vector<T>& second) {
		return !(first == second);
	 }

};

#endif