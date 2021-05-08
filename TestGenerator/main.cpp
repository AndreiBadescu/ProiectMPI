#include <fstream>
#include <iostream>
#include <random>
#include <cstring>

using namespace std;

long long e(int x){
    long long p = 1;
    for(int i = 0; i < x; ++i)
        p *= 10;
    return p;
}

long long d10[] = {e(4),e(5),e(6),e(7),e(8),e(9)};

int main()
{
    random_device nr_rand;
    for(int i = 0; i < 6; ++i){
        char c = i + '4';

    	string path = "../Tests/DATA 1e+";
    	path += c;
    	path += ".txt";
    	ofstream fout(path);

    	fout << d10[i] << '\n';
    	for(int j = 0; j < d10[i]; ++j){
           int x = 2147483647 - nr_rand();
           fout << x << ' ';
    	}
    }
    return 0;
}
