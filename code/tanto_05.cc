/* Introduzco Random Generators */

#include "Integer.h"
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#include <time.h>
#include "randomc/randomc.h"
#include "randomc/userintf.cpp"
#include "randomc/mother.cpp"

using namespace std;

string rotate( string in );
Integer next( const char * in );
string build_determ_string( int len, int ceros, int near, int gap );
string build_random_string( int len );

int main( int argc, char * argv[] ) {

	// test de Integer number
	Integer bigInt = argv[1];
	bigInt.print();
	bigInt.setbase(2);
	bigInt.print();
	cout << digits(bigInt,2) << "\n";
	bigInt.setbase(10);
	bigInt.print();

	Integer sq = Sqrt( bigInt );
	sq.print();

	// build a string of ONES
	int ones_len = digits( sq, 2 );
	string ones( ones_len, '1' );
	const char * num = ones.c_str();
	Integer new_int( num, 2 );
	new_int.print();

	// build a string of CEROS
	int ceros_len = 1;
	string ceros( ones_len, '0' );

	string test = build_determ_string( ones_len, 2, 1, 0 );
	cout << test << "\n";

	string rand = build_random_string( ones_len );
	cout << rand << "\n";
}

// Rotacion de la string
string rotate( string in ){

	string::size_type len = in.length();
	string out;
	out = in.substr(1, len - 1) + in[0];
	return out;

}

// Siguiente Integer binario
Integer next( const char * in ){

	string str = in;
	str = rotate( str );
	const char * num = str.c_str();
	Integer out( num, 2 );
	return out;

}

// Build a binary string
string build_determ_string( int len, int ceros, int near, int gap ){

	int i, j;
	string out( len, '1' );
	int mul = (len - (ceros * near) - ((ceros - 1) * gap));
	for( i = (len - 1); i >= mul; i -= (gap) ){
		for( j = 0; j < near; j++ ){
			out[ i-- ] = '0';
		}
	}
	return out;
}

string build_random_string( int len ){

	int32 seed = time( 0 );                // random seed
	int i;                               // loop counter
	double r;                            // random number
	int32 ir;                            // random integer number
	string out( len, '1' );
	TRandomMotherOfAll mother( seed );      // make instance of random number generator
	for ( i = 1 ; i < len ;  i++ ) {
		ir = mother.IRandom( 0, 1 );
		if( ir == 1 ){
			out[i] = '1';
		} else {
			out[i] = '0';
		}
	}
	return out;
}
