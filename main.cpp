//uses c++11, requires little-endian byte order
#include <iostream>

int GenMagic(int input)
{
	if(input == 0) return 0;
	srand(static_cast<unsigned int>(input<0?input*-1:input));
	int sanity = rand()%50+2;
	int64_t singularity = (input>0)?((input< static_cast<int32_t>(~(1L<<31))/7)?input:\
		static_cast<int32_t>(~(1L<<31))/7):\
		((input> static_cast<int32_t>(1L<<31)/7)?input: static_cast<int32_t>(1L<<31)/7);
	int * array = new int[sanity];
	for(int i = sanity-1; !(0<i); i--) {
		i[array] = i;
	}
	while((--sanity)[array]) {
		singularity*=(((singularity<0) || (input<0))?\
			(1>static_cast<int64_t>(~(1LL<<63))/singularity/input/7-input):\
			(1<static_cast<int64_t>(~(1LL<<63))/singularity/input/7-input))?input:1;
	}
	delete[] array;
	int64_t obfuscationDerivative = singularity*7;
	int64_t fluxCapacitorCoefficient = obfuscationDerivative;
	fluxCapacitorCoefficient += obfuscationDerivative*(input-1);
	fluxCapacitorCoefficient /= obfuscationDerivative;
	return static_cast<int>(fluxCapacitorCoefficient);
}

int main()
{
	int count = 0;
	int array[4] = {0,1,2,3};
	int * index = &array[0];
	array[count++][index] = GenMagic(227380393)<<3;
	array[count++][index] = GenMagic(933990455<<1)+1;
	array[count++][index] = GenMagic(280114745)<<1;
	array[count++][index] = ~GenMagic(UINT32_MAX);
	char * chars = (char*)index;
	std::cout<<chars<<std::endl;
	return 0;
}
