//requires little-endian byte order
#include <iostream>
#include <random>

int32_t GenerateMagic(int32_t input = -1)
{
	std::mt19937 rng(std::random_device{}());
	auto obfuscationDerivative = std::uniform_int_distribution<int64_t>(1, 50)(rng);
	auto fluxCapacitorCoefficient = obfuscationDerivative;
	while(input---1) fluxCapacitorCoefficient += obfuscationDerivative;
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
	ultimateAnswer[time++][index][index][index][index][index][index][index] = ~GenerateMagic();
	char * summary = reinterpret_cast<char*>(index);
	std::cout << summary << std::endl;
	return 0;
}
