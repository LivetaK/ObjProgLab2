/**
* @file Vector.hpp
* @brief siame faile aprasyta naujo vektoriaus klase
*/

#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <algorithm>
#include <limits>


using namespace std;

/**
 *@class Vector
 *@brief Vector klase, sukurta remiantis std::vector
 */

const int DEFAULT_VECTOR_SIZE = 10;

template <typename T>
class Vector {
private:
	int size;								/**< Dabartinis elementų skaicius vektoriuje */
	int capacity;							/**< Dabartine vektoriaus talpa */
	T* elements;							/**< Rodykle i vektoriaus elementu masyva */

public:
	// MEMBER TYPES 
	using value_type = T;             /**< Elementu tipas */
	using iterator = T*;              /**< Iteratoriaus tipas */
	using const_iterator = const T*;  /**< Konstantinio iteratoriaus tipas */
	using reference = T&;             /**< Nuorodos tipas */
	using const_reference = const T&; /**< Konstantines nuorodos tipas */
	using size_type = int;            /**< Dydzio tipas */

//*************************************************************************************************************************
	/**
	* @brief Konstruktorius
	*/
	Vector() {									// Vector<int> v; - konstruktorius
		size = 0;
		capacity = DEFAULT_VECTOR_SIZE;
		elements = new T[DEFAULT_VECTOR_SIZE];
	}
	/**
	* @brief Konstruktorius, kuris leidzia is karto inicializuoti sarasa
	* param init_list Inicializavimo sarasas
	*/
	Vector(initializer_list<T> init_list) { // Intializer list konstruktorius
		size = init_list.size();
		capacity = size > DEFAULT_VECTOR_SIZE ? size : DEFAULT_VECTOR_SIZE;
		elements = new T[capacity];
		copy(init_list.begin(), init_list.end(), elements);
	}

	/**
	 * @brief Destruktorius
	*/
	~Vector() {									// Destruktorius
		delete[] elements;

	}

//*************************************************************************************************************************

	//RULE OF FIVE

	/**
	 * @brief Kopijavimo konstruktorius
	 * @param copy Kitas vektorius, kuri reikia kopijuoti
	 */
	Vector(const Vector<T>& copy) {				// Vector<int> v(w); - kopijavimo kosntruktorius
		size = copy.size;
		capacity = copy.capacity;
		elements = new T[capacity];
		for (int i = 0; i < copy.size; i++) {
			elements[i] = copy.elements[i];
		}
	}

	/**
	 * @brief Kopijavimo priskyrimo operatorius
	 * @param copy Kitas vektorius, kuri reikia kopijuoti
	 * @return Nuoroda i si vektoriu
	 */
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

	/**
	 * @brief Perkelimo konstruktorius
	 * @param kitas Kitas vektorius, kuri reikia perkelti
	 */
	Vector(Vector<T>&& kitas) noexcept				// -perkelimo konstruktosius
	:	size(kitas.size),
		capacity(kitas.capacity),
		elements(kitas.elements)
	{
			kitas.size = 0;
			kitas.capacity = 0;
			kitas.elements = nullptr;
	}

	/**
	 * @brief Perkelimo priskyrimo operatorius
	 * @param kitas Kitas vektorius, kuri reikia perkelti
	 * @return Nuoroda i si vektoriu
	 */
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

	/**
	 * @brief Grazina iteratoriu i pirmaji elementa
	 * @return Iteratorius i pirmaji elementa
	 */
	iterator Begin() {							// v.Begin()
		return elements;
	}

	/**
	 * @brief Grazina iteratoriu i elementa po paskutiniojo
	 * @return Iteratorius i elementa po paskutiniojo
	 */
	iterator End() {								//v.End()
		return elements + size;
	}

	/**
	 * @brief Grazina konstantini iteratoriu i pirmaji elementa
	 * @return Konstantinis iteratorius i pirmaji elementa
	 */
	const_iterator begin() const {					// const version of v.begin()
		return elements;
	}

	/**
	 * @brief Grazina konstantini iteratoriu i elementa po paskutiniojo
	 * @return Konstantinis iteratorius i elementa po paskutiniojo
	 */
	const_iterator end() const {                  // const version of v.end()
		return elements + size;
	}
//*************************************************************************************************************************


	// CAPACITY

	/**
	 * @brief Grazina elementu skaiciu vektoriuje
	 * @return Elementu skaicius
	 */
	int Size() const {							// v.Size()
		return size;
	}

	/**
	 * @brief Grazina vektoriaus talpa
	 * @return Vektoriaus talpa
	 */
	int Capacity() const {						// v.Capacity()
		return capacity;
	}

	/**
	 * @brief Patikrina, ar vektorius tuscias
	 * @return true, jei tuscias, false, jei ne
	 */
	bool IsEmpty() const {						// v.IsEmpty()
		return size == 0;
	}

	/**
	 * @brief Grazina didziausia elementa vektoriuje
	 * @return Maksimalus dydis vektoriuje
	 */
	int MaxSize() const {
		return numeric_limits<int>::max();
	}

	/**
	 * @brief Keicia vektoriaus dydi
	 * @param newSize Naujas vektoriaus dydis
	 */
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

	/**
	 * @brief Keicia vektoriaus talpa
	 * @param newCapacity Nauja vektoriaus talpa
	 */
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

	/**
	 * @brief Sumazina vektoriaus talpa iki jo dydzio
	 */
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

	/**
	 * @brief Grazina elementa pagal indeksa (su modifikavimo galimybe)
	 * @param index Elemento indeksas
	 * @return Nuoroda i elementa
	 * @throw out_of_range Jei indeksas netinkamas
	 */
	T& operator [](int index) {					// v[i] = x
		if (index < 0 || index >= size) {
			throw out_of_range("Netinkamas indeksas");
		}
		return elements[index];
	}

	/**
	 * @brief Grazina elementa pagal indeksa (be modifikavimo galimybes)
	 * @param index Elemento indeksas
	 * @return Konstanta nuoroda i elementa
	 * @throw out_of_range Jei indeksas netinkamas
	 */
	const T& operator [](int index) const {		// x = v[i]
		if (index < 0 || index >= size) {
			throw out_of_range("Netinkamas indeksas");
		}
		return elements[index];
	}

	/**
	 * @brief Grazina pirmaji elementa
	 * @return Nuoroda i pirmaji elementa
	 */
	T& Front() {
		return elements[0];
	}

	/**
	 * @brief Grazina paskutini elementa
	 * @return Nuoroda i paskutini elementa
	 */
	T& Back() {
		return elements[size - 1];
	}

//*************************************************************************************************************************

	// MODIFIERS

	/**
	 * @brief Pakeicia vektoriaus elementus naujais
	 * @param n Naujas elementu skaicius
	 * @param value Nauja reiksme
	 */
	void Assign(int n, const T& value) {		// v.Assign(10, 0)
		Resize(n);
		for (int i = 0; i < size; i++) {
			elements[i] = value;
		}
	}

	/**
	 * @brief Prideda nauja elementa i vektoriaus gala
	 * @param object Naujasis elementas
	 */
	void PushBack(const T& object) {			// v.PushBack('a')
		if (size == capacity) {
			Reserve(capacity * 2);
		}
		elements[size] = object;				// eina i paskutine pozicija ir ideda nauja elementa
		size++;									//pridejus nauja elementa gale, padidinam ir size
	}

	/**
	 * @brief Pasalina paskutini elementa
	 */
	void PopBack() {							// v.PopBack()
		if (size > 0) {
			size--;
		}
	}

	/**
	 * @brief Iterpia nauja elementa nurodytoje pozicijoje
	 * @param index Iterpimo pozicija
	 * @param value Naujasis elementas
	 * @throw out_of_range Jei indeksas netinkamas
	 */
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

	/**
	 * @brief Iterpia elementus nurodytoje pozicijoje
	 * @param pos Pozicija, kurioje iterpti elementai
	 * @param first Pirmas elementas
	 * @param last Paskutinis elementas
	 * @throw out_of_range Jei indeksas netinkamas
	 */
	template <typename InputIt>
	void Insert(iterator pos, InputIt first, InputIt last) {
		int index = pos - Begin();
		int numElements = last - first;

		if (index < 0 || index > size) {
			throw out_of_range("Netinkamas indeksas");
		}

		if (size + numElements > capacity) {
			Reserve((size + numElements) * 2);
		}

		for (int i = size - 1; i >= index; --i) {
			elements[i + numElements] = elements[i];
		}

		for (int i = 0; i < numElements; ++i) {
			elements[index + i] = *(first + i);
		}

		size += numElements;
	}

	/**
	 * @brief Pasalina elementa nurodytoje pozicijoje
	 * @param index Elemento indeksas
	 * @throw out_of_range Jei indeksas netinkamas
	 */
	void Erase(int index) {						// v.Erase(1)
		if (index < 0 || index >= size) {
			throw out_of_range("Netinkamas indeksas");
		}
		for (int i = index; i < size - 1; i++) {
			elements[i] = elements[i + 1];
		}
		size--;
	}

	/**
	 * @brief Pasalina elementus nurodytame intervale
	 * @param first Pirmasis iteratorius
	 * @param last Paskutinis iteratorius
	 * @throw out_of_range Jei intervalas netinkamas
	 */
	void Erase(iterator first, iterator last) {
		if (first < Begin() || last > End() || first > last) {
			throw out_of_range("Netinkamas intervalas");
		}

		int numElements = last - first;
		for (iterator it = first; it != End() - numElements; ++it) {
			*it = *(it + numElements);
		}
		size -= numElements;
	}

	/**
	 * @brief Isvalo visus vektoriaus elementus
	 */
	void Clear() {								// v.Clear()
		size = 0;
	}

	/**
	 * @brief Sukeicia vietomis du vektorius
	 * @param first Pirmasis vektorius
	 * @param second Antrasis vektorius
	 */
	void Swap(Vector<T>& first, Vector<T>& second) {		// Swap(v,w)
		swap(first.size, second.size);
		swap(first.capacity, second.capacity);
		swap(first.elements, second.elements);
	}

//*************************************************************************************************************************

	// NON_MEMBER FUNCTION OVERLOADS

	/**
	 * @brief Lygina du vektorius
	 * @details Vektoriai lygus tada, kada ju dydis ir elementai vienodi.
	 * @param first Pirmasis vektorius
	 * @param second Antrasis vektorius
	 * @return true, jei vektoriai yra lygus, false kitu atveju
	 */
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

	/**
	 * @brief Lygina du vektorius
	 * @param first Pirmasis vektorius
	 * @param second Antrasis vektorius
	 * @return true, jei vektoriai yra nelygus, false kitu atveju
	 */
	friend bool operator != (const Vector<T>& first, const Vector<T>& second) {
		return !(first == second);
	 }

};

#endif
