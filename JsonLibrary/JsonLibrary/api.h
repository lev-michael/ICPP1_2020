#pragma once
#ifndef API_H
#define API_H
#ifdef JSONLIBRARY_EXPORTS
#define JSON_API __declspec(dllexport)
#else
#define JSON_API __declspec(dllimport)
#endif 

#include <string>
#include <stdexcept>


// - šablona s parametrem datového typu uložených hodnot
// - není povoleno užití STL kontejnerù ani jiných knihoven pro ukládání dat
// - realizace musí využívat dynamicky alokované pole, spojový seznam nebo jinou vhodnou Vámi implementovanou ADS 
template<typename T>
class DynamicArray {
public:
	DynamicArray();
	~DynamicArray();

	// - pøidá element na konec pole
	void append(const T& element);

	// - výjimky pøi neplatném nebo nekorektním indexu
	const T& getElementAt(int index) const;

	// - vrací velikost (poèet prvkù) v poli
	int getSize() const;
	T remove(int index);
private:
	int size;
	int length = 10;
	T* dynamicArray;
	void increaseArray();
	bool isArrayFull() const;
};

template<typename T>
inline DynamicArray<T>::DynamicArray()
{
	this->size = 0;
	this->dynamicArray = new T[10];
}

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{
	delete[] dynamicArray;
}

template<typename T>
inline  void DynamicArray<T>::append(const T& element)
{
	if (isArrayFull()) {
		increaseArray();
	}
	dynamicArray[size++] = element;
}

template<typename T>
inline const T& DynamicArray<T>::getElementAt(int index) const
{
	if (index >= size || index < 0) {
		throw std::invalid_argument("Invalid index.");
	}
	return this->dynamicArray[index];
}

template<typename T>
inline int DynamicArray<T>::getSize() const
{
	return this->size;
}

template<typename T>
inline T DynamicArray<T>::remove(int index)
{
	if (index < 0 || index >= size) {
		throw std::invalid_argument("Invalid index");
	}
	T deleted = dynamicArray[index];
	T* newArray = new T[length];
	for (int i = 0; i < size; i++)
	{	
		if (index == i) 
		{
			for (; i < size-1; i++)
			{
				newArray[i] = dynamicArray[i+1];
			}
			delete[] dynamicArray; 
			dynamicArray = newArray;;
			size--;
			return deleted;
		}
		else {
			newArray[i] = dynamicArray[i];
		}

	}
	return deleted;
}

template<typename T>
inline bool DynamicArray<T>::isArrayFull() const
{
	return size == length;
}

template<typename T>
inline void DynamicArray<T>::increaseArray()
{
	length = 2 * length;
	T* newArray = new T[length];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = dynamicArray[i];
	}
	delete[] dynamicArray;
	dynamicArray = newArray;
}

///////////////////////////////////////////////////////////////////////////////

// JSON hodnota - reprezentuje abstraktního pøedka pro základní datové typy v JSON (string, number, object, array, bool, null)
class JSON_API Value
{
public:
	virtual ~Value() = 0;
	// serializuje hodnotu do podoby JSON reprezentace
	virtual std::string serialize() const = 0;
};

///////////////////////////////////////////////////////////////////////////////

// - definuje pár klíè (øetìzec) a hodnota (JSON hodnota) pro reprezentaci hodnot JSON objektu
class JSON_API KeyValuePair {
private:
	std::string key;
	Value* value;
public:
	KeyValuePair(std::string key, Value* value);
	KeyValuePair() = default;
	// - vrátí klíè
	std::string getKey() const;
	// - vrátí hodnotu
	Value* getValue() const;
};

///////////////////////////////////////////////////////////////////////////////


// - reprezentuje hodnotu typu JSON null
class JSON_API NullValue :
	public Value
{
public:
	std::string serialize() const override;
};

///////////////////////////////////////////////////////////////////////////////
	
// - reprezentuje hodnotu typu JSON bool
class JSON_API BoolValue :
	public Value
{
private:
	bool value;
public:
	BoolValue(bool value);

	// - vrací bool hodnotu
	bool get() const;
	std::string serialize() const override;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON èíslo
class JSON_API NumberValue :
	public Value
{
private:
	double value;
public:
	NumberValue(double value);

	// - vrací èíselnou hodnotu 
	double get() const;
	std::string serialize() const;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON øetìzec (string)
class JSON_API StringValue :
	public Value
{
private:
	std::string value;
public:
	StringValue(std::string value);
	// - vrací øetìzcovou hodnotu
	std::string get() const;
	std::string serialize() const;
	std::string processEscapeChars(std::string value) const;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON pole
class JSON_API ArrayValue :
	public Value
{
public:
	ArrayValue();
	~ArrayValue();
	// - pøidá element na konec pole
	void append(Value* element);
	std::string serialize() const;
	int getSize() const;
	DynamicArray<Value*> *array;
	int size;
	// - atribut DynamicArray<Value*> pro uchování jednotlivých elementù v poli
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON objekt
class JSON_API ObjectValue :
	public Value
{
public:
	ObjectValue();
	~ObjectValue();
	// - pøidá klíè-element do objektu
	void append(const KeyValuePair& pair);
	std::string serialize() const;
	Value* getValue(std::string key);
	DynamicArray<KeyValuePair> *object;
	// - atribut DynamicArray<KeyValuePair> pro uchování jednotlivých hodnot a klíèù v objektu
};


///////////////////////////////////////////////////////////////////////////////
// - tøída pro práci s JSON
class JSON_API JSON
{
public:
	// - provede deserializaci øetìzce na vytvoøené objekty
	// - pøeètu znak a rozhodnu se
	// -- '{' - zaèínám èíst objekt
	// -------- ètu znaky, pak musí být dvojteèka, potom volám rekurzivnì deserialize(); následuje èárka nebo '}', podle situace se ètení opakuje
	// -- '[' - zaèínám èíst pole
	// -------- volám rekurzivnì deserialize(); následuje èárka nebo ']', podle situace se ètení opakuje
	// -- '"' - zaèínám èíst øetìzec - pozor na escapované uvozovky
	// -- [-0123456789] - zaèínám èíst èíslo - naètu všechny èíslice (pozor na možnou desetinnou teèku)
	// -- 'n' - 'null'
	// -- 't' - 'true'
	// -- 'f' - 'false'
	// -- cokoliv jiného - vyvolávám výjimku
	// - není pøípustné vracet nullptr
	// - deserializace musí být rozumnì implementována - není pøípustné zde napsat jednu extrémnì dlouhou metodu
	static Value* deserialize(const std::string& string);

	// - provede serializaci do JSON øetìzce
	static std::string serialize(const Value* value);
	static Value* deserialize(const std::string& string, int& pointer);
	static ArrayValue* readArray(const std::string& string, int& pointer);
	static ObjectValue* readObject(const std::string& string, int& pointer);
	static NumberValue* readNumber(const std::string& string, int& pointer);
	static StringValue* readString(const std::string& string, int& pointer);
	static NullValue* readNull(const std::string& string, int& pointer);
	static BoolValue* readBool(const std::string& string, int& pointer, bool value);
	static void skipQuotes(const std::string& string, int& pointer);
	static void skipComma(const std::string& string, int& pointer);
	static void skipColon(const std::string& string, int& pointer);
	static void skipCurlyBraces(const std::string& string, int& pointer);
};

///////////////////////////////////////////////////////////////////////////////

#endif // !API_H