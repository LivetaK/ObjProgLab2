#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

const int DEFAULT_VECTOR_SIZE = 10;

template <typename T>
class Vector {
private:
	int size;
	int capacity;
	T* elements;

public:
	
	Vector() {									// Vector<int> v; - konstruktorius
		size = 0;
		capacity = DEFAULT_VECTOR_SIZE;
		elements = new T[DEFAULT_VECTOR_SIZE];
	}

	Vector(int n, const T& value) {				// Vector<int> v(10, 0); - kitas konstruktorius, kur n - elementu kiekis, value - kiekvieno is tu elementu reiksme
		size = n;
		capacity = n * 2;
		elements = new T[capacity];
		for (int i = 0; i < size; i++) {
			elements[i] = value;
		}
	}

	Vector(const Vector& copy) {				// Vector<int> v(w); - kopijavimo kosntruktorius
		size = copy.size;
		capacity = copy.capacity;
		elements = new T[capacity];
		for (int i = 0; i < copy.size; i++) {
			elements[i] = copy.elements[i];
		}
	}

	~Vector() {									// Destruktorius
		delete[] elements;

	}

	int Size() const {							// v.Size()
		return size;
	}

	int Capacity() const {						// v.Capacity()
		return capacity;
	}

	bool IsEmpty() const {						// v.IsEmpty()
		return size == 0;
	}

	T& operator [](int index) {					// v[i] = x
		if (index < 0 || index >= size) {
			throw std::out_of_range("Netinkamas indeksas");
		}
		return elements[index];
	}

	const T& operator [](int index) const{		// x = v[i]
		if (index < 0 || index >= size) {
			throw std::out_of_range("Netinkamas indeksas");
		}
		return elements[index];
	}

	Vector& operator = (const Vector& copy) {	// v = w
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

	void PushBack(const T& object) {			// v.PushBack('a')
		if (size == capacity) {					// jei vektoriaus dydis pasieke jo capacity, kuriame nauja masyva,
			T* newarr = new T[capacity * 2];	// kuris bus dvigubai didesnis nei pirmutinis masyvas
			for (int i = 0; i < size; i++) {	// kopijuojami visi seno masyvo elementai i nauja masyva
				newarr[i] = elements[i];
			}
			delete[] elements;					// istrinami seni elementai
			elements = newarr;					// pakeiciama rodykle
			capacity = capacity * 2;			// atnaujinamas capacity

		}
		elements[size] = object;				// eina i paskutine pozicija ir ideda nauja elementa
		size++;									//pridejus nauja elementa gale, padidinam ir size
	}

	void PopBack() {							// v.PopBack()
		if (size > 0) {
			size--;
		}
	}
	void Erase(int index) {						// v.Erase(1)
		if (index < 0 || index >= size) {
			throw std::out_of_range("Netinkamas indeksas");
		}
		for (int i = index; i < size - 1; i++) {
			elements[i] = elements[i + 1];
		}
		size--;
	}

	void Clear() {								// v.Clear()
		size = 0;
	}

	void Insert(int index,const T& value) {		// v.Insert(0, 'a')
		if (index < 0 || index > size) {
			throw std::out_of_range("Netinkamas indeksas");
		}
		if (size == capacity) {
			T* newarr = new T[capacity * 2];
			for (int i = 0; i < size; i++) {
				newarr[i] = elements[i];
			}
			delete[] elements;
			elements = newarr;
			capacity = capacity * 2;
		}
		for (int i = size; i > index; i--) {
			elements[i] = elements[i - 1];
		}
		elements[index] = value;
		size++;
	}


};

#endif