#include <iostream>
#include <map>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <fstream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s;
    getline( std::cin, s );
    istringstream is( s );
    vector<int> v( ( istream_iterator<int>( is ) ), istream_iterator<int>() );
    for ( int x : v) cout << x << ' ';
    cout << endl;
    return 0;
}