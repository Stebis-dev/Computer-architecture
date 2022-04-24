#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
	__declspec(align(16)) float first[4] = {1, 2, 3, 4};
	__declspec(align(16)) float second[4] = {2, 3, 4, 5};
	__declspec(align(16)) float t[4];
	__declspec(align(16)) float rez[4];

	ofstream data("output.txt");

	for (int i = 0; i <= 240; i++)
	{
		for (int j = first[0]; j <= 1000; j++)
		{
			_asm {
				movaps xmm0, first
				movaps xmm1, second

				mulps xmm0, xmm0
				mulps xmm1, xmm1

				movaps xmm2, xmm0
				addps xmm2, xmm1

				movaps xmm3, xmm2
				sqrtps xmm3, xmm3
				movaps t, xmm3
				roundps xmm3, xmm3, 1

				mulps xmm3, xmm3
				subps xmm3, xmm2

				movaps rez, xmm3
			}
			for (int ii = 0; ii < 4; ii++)
			{
				if (rez[ii] == 0 && first[ii] <= 1000 && second[ii] <= 1000)
					data << first[ii] << " + " << second[ii] << " = " << t[ii] << endl;
				second[ii]++;
			}
		}
		for (int iii = 0; iii < 4; iii++)
		{
			first[iii] += 4;
			second[iii] = first[iii];
		}
	}
	system("pause");
	data.close();
	return 0;
}