#ifndef HEAP_H
# define HEAP_H

template <class T>
class	Heap
{
	public:
		Heap(void) {}
		Heap(int size);
		~Heap(void);

		int		getSize(void) { return _size; }
		int		getnNodes(void) { return _nNodes; }

		bool	isEmpty(void) { return (_nNodes == 0); }
		bool	isFull(void) { return (_nNodes == _size); }
		bool	insert(T item);
		bool	remove(T &item);

		bool	peek(T &item);

		virtual bool	compare(T &lhs, T &rhs) = 0;

	protected:
		int		_size;
		int		_nNodes;
		T		*_buf;
};

template <class T>
Heap<T>::Heap(int size)
{
	_buf = new T[size + 1];
	_size = (_buf) ? size : 0;
	_nNodes = 0;
}

template <class T>
Heap<T>::~Heap(void)
{
	delete[] _buf;
}

template <class T>
bool	Heap<T>::insert(T item)
{
	if (isFull())
		return false;
	int	i = ++_nNodes;
	for (int iParent = 0; i > 1; i = iParent)
	{
		iParent = i / 2;
		if (!compare(_buf[iParent], item))
			break ;
		_buf[i] = _buf[iParent];
	}
	_buf[i] = item;
	return true;
}

template <class T>
bool	Heap<T>::remove(T &item)
{
	if (isEmpty())
		return false;
	item = _buf[1];
	int iParent = 1;
	for (int i = 2; i <= _nNodes; i *= 2)
	{
		if (i < _nNodes && compare(_buf[i], _buf[i + 1]))
			i++;
		if (!compare(_buf[_nNodes], _buf[i]))
			break ;
		_buf[iParent] = _buf[i];
		iParent = i;
	}
	_buf[iParent] = _buf[_nNodes--];
	return true;
}

template <class T>
bool	Heap<T>::peek(T &item)
{
	if (isEmpty())
		return false;
	item = _buf[1];
	return true;
}

template <class T>
class	MaxHeap : public Heap<T>
{
	public:
		MaxHeap(int size) : Heap<T>::Heap(size) {};
		~MaxHeap(void) {};

		bool	compare(T &lhs, T &rhs) { return (lhs < rhs); }
};

template <class T>
class	MinHeap : public Heap<T>
{
	public:
		MinHeap(int size) : Heap<T>::Heap(size) {};
		~MinHeap(void) {};

		bool	compare(T &lhs, T &rhs) { return (lhs > rhs); }
};

#endif
