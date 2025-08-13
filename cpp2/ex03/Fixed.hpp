#ifndef FIXED_HPP
 #define FIXED_HPP

 #include <iostream>

 class Fixed
 {
	public:
		Fixed( void );
		Fixed( const int x );
		Fixed( const float x );
		Fixed( Fixed const & cpy );
		~Fixed( void );

		Fixed&						operator=( Fixed const & right );

		bool						operator>( Fixed const & right ) const;
		bool						operator<( Fixed const & right ) const;
		bool						operator>=( Fixed const & right ) const;
		bool						operator<=( Fixed const & right ) const;
		bool						operator==( Fixed const & right ) const;
		bool						operator!=( Fixed const & right ) const;

		Fixed						operator+( Fixed const & right ) const;
		Fixed						operator-( Fixed const & right ) const;
		Fixed						operator*( Fixed const & right ) const;
		Fixed						operator/( Fixed const & right ) const;

		Fixed&						operator++( void );	// prefix
		Fixed&						operator--( void );	// prefix
		Fixed 						operator++( int );	// postfix
		Fixed 						operator--( int );	// postfix

		int							getRawBits( void ) const;
		void						setRawBits( int const raw );
		float						toFloat( void ) const;
		int							toInt( void ) const;
		static Fixed&				min( Fixed& a, Fixed& b );
		static Fixed&				max( Fixed& a, Fixed& b );
		static Fixed const &		min( Fixed const & a, Fixed const & b );
		static Fixed const &		max( Fixed const & a, Fixed const & b );

	private:
		int					_fixed;
		static const int	_bits;
 };

 std::ostream& operator<<( std::ostream& os, Fixed const & toOutput );

#endif