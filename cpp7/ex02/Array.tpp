template< typename T >
Array<T>::Array( void ) { _array = NULL; _size = 0; };

template< typename T >
Array<T>::Array( unsigned int n ) { _array = new T[n](); _size = n; };

template< typename T >
Array<T>::Array( const Array& copy ) : _array( NULL ), _size( 0 ) { *this = copy; };

template< typename T >
Array<T>::~Array( void ) { if ( _array ) { delete [] _array; }; };

/*===================================================================*/

template< typename T >
Array<T>&			Array<T>::operator=( const Array<T>& other )
{
	if ( this != &other )
	{
		if ( this->_array )
			delete [] this->_array;
		this->_array = new T[other._size];
		for ( unsigned int i = 0; i < other._size; i++ )
			this->_array[i] = other._array[i];
		this->_size = other._size;
	}
	return *this;
}

template< typename T >
T&					Array<T>::operator[]( unsigned int i )
{
	if ( i >= this->_size )
		throw std::exception();
	return this->_array[i];
}

template< typename T >
const T&		 	Array<T>::operator[]( unsigned int i ) const
{
	if ( i >= this->_size )
		throw std::exception();
	return this->_array[i];
}

template< typename T >
unsigned int		Array<T>::size( void ) const { return this->_size; };

template< typename T >
std::ostream&		operator<<( std::ostream& os, const Array<T>& toPrint )
{
	for ( unsigned int i = 0; i < toPrint.size(); i++ )
	{
		os << toPrint[i];
		if ( i + 1 != toPrint.size() )
			os << ", ";
	}
	return os;
}
