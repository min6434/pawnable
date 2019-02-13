#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>


unsigned char* int2char(int* pnval){
	unsigned char* pszBlock = new unsigned char[4];
	for (int i = 0; i < 4; i++){
		pszBlock[i] = ((unsigned char*)pnval)[i];
	}

	return pszBlock;
}

int char2int(unsigned char* pszval){
	return *(int*)pszval;
}

void perm(unsigned char* pszBlock, int idx, int start=33, int end=126, int blocksize=4){
	// ascii 33(!)~126(~) --> 0~93
	const int stride = end - start + 1;
	if (idx < std::pow(stride, blocksize)){
		pszBlock[0] = idx % stride + start;
		for (int i = 1; i < blocksize; i++){
			int val = int(idx / (int)std::pow(stride, i)) % stride + start;
			pszBlock[i] = val;
		}
	}
	else{
		std::cout << "Index is larger than the limits" << std::endl;
	}
}

unsigned char* findhash(int hash, int start, int end, int blocksize){
	unsigned char* pszInput = new unsigned char[blocksize];
	const int stride = end - start + 1;
	bool success = false;

	for (int i = 0; i < (int)std::pow(stride, blocksize); i++) {
		perm(pszInput, i, start, end, blocksize);
		if (char2int(pszInput) == hash){
			std::cout << "Found: " << pszInput << std::endl;
			success = true;
		}
	}
	
	return success ? pszInput : nullptr;
}


int main(int argc, char** argv){
	std::srand(std::time(nullptr));
	const int start = 33;
	const int end = 126;
	const int blocksize = 4;

	
	unsigned char* pszText = new unsigned char[blocksize];
	perm(pszText, 0, start, end, blocksize);
	std::cout << char2int(pszText) << std::endl;
	perm(pszText, std::pow(end - start + 1, blocksize) - 1, start, end, blocksize);
	std::cout << char2int(pszText) << std::endl;

	/* unsigned char* pszText = (unsigned char*)"!a.d"; */
	/* int hash = char2int(pszText); */
	/* std::cout << "hash: " << hash << std::endl; */

	/* unsigned char* pszOutput = findhash(hash, start, end, blocksize); */
	/* if (pszOutput){ */
	/* 	delete[] pszOutput; */
	/* } */

	return 0;
}
