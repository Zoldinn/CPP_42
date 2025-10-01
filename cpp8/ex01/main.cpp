#include "Span.hpp"

int	main( void )
{
	std::cout << "-- Subject test" << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp.printVec();

	try
	{
		std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest  span : " << sp.longestSpan() << std::endl;
	}
	catch ( const Span::EEmpty& e )
	{
		std::cout << e.what() << std::endl;
	}





	std::cout	<< std::endl << "============================================================="
				<< std::endl << "-- test with version of addNumber with iterators" << std::endl;

	std::vector<int>	a;
	Span				sp1 = Span(100000);

	srand( time(NULL) );
	for ( int i = 0; i < 100000; i++ )
		a.push_back( rand() % 100000 );

	sp1.addNumber( a.begin(), a.end() );
	std::cout << "Test with 100 000 random nb so i dont print it..." << std::endl;

	try
	{
		std::cout << "Shortest span : " << sp1.shortestSpan() << std::endl;
		std::cout << "Longest  span : " << sp1.longestSpan()  << std::endl;
	}
	catch ( const Span::EEmpty& e )
	{
		std::cout << e.what() << std::endl;
	}




	std::cout	<< std::endl << "============================================================="
				<< std::endl << "-- test adding too much nb" << std::endl;
	Span sp2 = Span(5);

	sp2.addNumber(6);
	sp2.addNumber(3);
	sp2.addNumber(17);
	sp2.addNumber(9);
	sp2.addNumber(11);
	sp2.addNumber(12);
	sp2.addNumber(13);
	sp2.addNumber(14);

	sp2.printVec();

	try
	{
		std::cout << "Shortest span : " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest  span : " << sp2.longestSpan() << std::endl;
	}
	catch ( const Span::EEmpty& e )
	{
		std::cout << e.what() << std::endl;
	}




	std::cout	<< std::endl << "============================================================="
				<< std::endl << "-- test with an empty Span" << std::endl;

	Span sp3 = Span(5);

	sp3.printVec();

	try
	{
		std::cout << "Shortest span : " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest  span : " << sp3.longestSpan() << std::endl;
	}
	catch ( const Span::EEmpty& e )
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
