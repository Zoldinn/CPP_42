#ifndef FIXED_HPP
 #define FIXED_HPP

 #include <iostream>

 class Fixed
 {
	public:
		Fixed( void );
		Fixed( const int x );
		Fixed( const float x );
		Fixed( Fixed const & cpy);
		~Fixed( void );
		Fixed& operator=(Fixed const & other);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int					_fixed;
		static const int	_bits;
 };

 std::ostream& operator<<(std::ostream& os, Fixed const & toOutput );

#endif