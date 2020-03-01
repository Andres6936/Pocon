#include "Source/Pocon.hpp"

#include <Rob/StopWatch.hpp>

int main(int argc, char** argv)
{
	StopWatch sw("Pocon");
	Pocon::Pocon(argc, argv).Run();

	return 0;
}
