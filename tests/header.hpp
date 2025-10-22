#pragma once

#include <iostream>
#include <vector>

std::string*				split( const std::string& str, const std::string& sep );
size_t						count_word( const std::string& str, const std::string& sep );
std::vector<std::string>	vsplit( std::string str, std::string sep );
void						print_vi( std::vector<int>& tab );
void						swap( int* a, int*b );
std::vector<int>			to_int( std::vector<std::string> split );



