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

		Fixed&				operator=( Fixed const & other );

		bool				operator>( Fixed const & other ) const;
		bool				operator<( Fixed const & other ) const;
		bool				operator>=( Fixed const & other ) const;
		bool				operator<=( Fixed const & other ) const;
		bool				operator==( Fixed const & other ) const;
		bool				operator!=( Fixed const & other ) const;

		Fixed				operator+( Fixed const & other ) const;
		Fixed				operator-( Fixed const & other ) const;
		Fixed				operator*( Fixed const & other ) const;
		Fixed				operator/( Fixed const & other ) const;

		Fixed&				operator++( void );	// prefix
		Fixed&				operator--( void );	// prefix
		Fixed 				operator++( int );	// postfix
		Fixed 				operator--( int );	// postfix

		int					getRawBits( void ) const;
		void				setRawBits( int const raw );
		float				toFloat( void ) const;
		int					toInt( void ) const;
		static int			min( Fixed& a, Fixed& b );
		static int			max( Fixed& a, Fixed& b );
		static int			min( Fixed const & a, Fixed const & b );
		static int			max( Fixed const & a, Fixed const & b );

	private:
		int					_fixed;
		static const int	_bits;
 };

 std::ostream& operator<<( std::ostream& os, Fixed const & toOutput );

#endif