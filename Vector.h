#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector {
private:
	int size;
	int capacity;
	T* elements;

public:
	Vector();									// Vector<int> v; - konstruktorius
	Vector(int n, const T& value);				// Vector<int> v(10, 0); - kitas konstruktorius, kur n - elementu kiekis, value - kiekvieno is tu elementu reiksme
	Vector(const Vector& copy);					// Vector<int> v(w); - kopijavimo kosntruktorius

	~Vector();									// Destruktorius

	int Size() const;							// v.Size()
	int Capacity() const;						// v.Capacity()
	bool IsEmpty() const;						// v.IsEmpty()

	T& operator [](int index);					// v[i] = x
	const T& operator [])int index) const;		// x = v[i]
	Vector& operator = (const Vector& copy);	// v = w

	void PushBack(const T& object);				// v.PushBack('a')
	void PopBack();								// v.PopBack()
	void Erase(int index);						// v.Erase(1)
	void Clear();								// v.Clear()
	void Insert(int index, T value);			// v.Insert(0, 'a')


};

#endif