#ifndef FIXED_HPP
 #define FIXED_HPP

 #include <iostream>

 class Fixed
 {
	public:
		Fixed( void );
		Fixed( Fixed const & cpy);
		~Fixed( void );
		Fixed& operator=(Fixed const & other);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_fixed;
		static const int	_bits;
 };

#endif