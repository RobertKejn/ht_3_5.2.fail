#include <iostream>

template<class T>
class Column {
private:
	int length = 0;
	T* arr;
public:
	Column() {}
	Column(const int n) : length(n) {
		arr = new T[n];
	}
	~Column() {
		delete[] arr;
	}

	T operator[](int n) const {
		return arr[n];
	}

	T operator[](int n) {
		return arr[n];
	}

	Column<T>& operator=(const Column<T>& c) {
		delete[] arr;
		arr = new T[c.length];
		length = c.length;
		return *this;
	}
};

template<class T>
class Table {
private:
	int rows = 0;
	int cols = 0;
	Column<T>* table;
public:

	Table(const int rows, const int cols) {
		table = new Column<T>[rows]();
		for (int i = 0; i < rows; ++i) {
			table[i] = Column<T>(cols);
		}
		this->rows = rows;
		this->cols = cols;
	}
	~Table() {
		delete[] table;
	}

	Table<T>& operator=(Table<T>& t) {

	}

	Column<T> operator[](int i) const {
		return table[i];
	}

	Column<T> operator[](int i) {
		return table[i];
	}

};

int main()
{
	auto table = Table<int>(2, 3);
	//table[0][0] = 0;
	std::cout << table[0][0];
}
