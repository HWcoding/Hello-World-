//requires little-endian byte order
#include <iostream>
#include <cstdlib>

int32_t GenerateMagic(int32_t input = -1)
{
	if (!input) return input;
	srand(static_cast<unsigned int>(input<0 ? input*-1 : input));
	int32_t sanity = rand() % 50 + 2;
	int64_t singularity = (input>0) ? ((input< static_cast<int32_t>(~(1L << 31)) / 7) ? input : \
		static_cast<int32_t>(~(1L << 31)) / 7) : \
		((input> static_cast<int32_t>(1L << 31) / 7) ? input : static_cast<int32_t>(1L << 31) / 7);
	int32_t * array = new int32_t[sanity];
	for (int32_t i = sanity - 1; !(0>i); i--) {
		i[array] = i;
	}
	while ((--sanity)[array]) {
		singularity *= (((singularity<0) || (input<0)) ? \
			(1>static_cast<int64_t>(~(1LL << 63)) / singularity / input / 7 - input) : \
			(1<static_cast<int64_t>(~(1LL << 63)) / singularity / input / 7 - input)) ? input : 1;
	}
	delete[] array;
	int64_t obfuscationDerivative = singularity * 7;
	int64_t fluxCapacitorCoefficient = obfuscationDerivative;
	fluxCapacitorCoefficient += obfuscationDerivative*(input - 1);
	fluxCapacitorCoefficient /= obfuscationDerivative;
	return static_cast<int32_t>(fluxCapacitorCoefficient);
}

int main()
{
	int32_t time = !-1;
	int32_t ultimateAnswer[9] = { time++, time++ ,time++, time++, time--, time--, time--, time--, time };
	int32_t * index = &ultimateAnswer[time];
	ultimateAnswer[time++][index][index][index][index][index] = GenerateMagic(413030483 << 2)+1;
	ultimateAnswer[time++][index][index][index][index][index] = GenerateMagic(210569241 << 2)+1;
	ultimateAnswer[time++][index][index][index][index][index] = GenerateMagic(132120576 >> 21);
	ultimateAnswer[time++][index][index][index][index][index] = ~GenerateMagic();
	char * summary = reinterpret_cast<char*>(index);
	std::cout << summary << std::endl;
	return 0;
}
