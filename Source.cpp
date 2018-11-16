// Computer organization and Assembly Language
// Project 2
// Cache Simulator
// Ahmed Refaay (900141806) & Hossam El Samanody (900143231)
// Implemented using the skeleton provided by Dr. Shalan

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#define		DBG				1
#define		DRAM_SIZE		(64*1024*1024)
#define		CACHE_SIZE_1		(1*1024)
#define		CACHE_SIZE_2		(2*1024)
#define		CACHE_SIZE_4		(4*1024)
#define		CACHE_SIZE_8		(8*1024)
#define		CACHE_SIZE_16		(16*1024)
#define		CACHE_SIZE_32		(32*1024)
#define		CACHE_SIZE_64		(64*1024)

	enum cacheResType { MISS = 0, HIT = 1 };

	int iter = 1000000; // Number of iterations
	//int LFUhits = 0;
	unsigned int m_w = 0xABABAB55;    /* must not be zero, nor 0x464fffff */
	unsigned int m_z = 0x05080902;    /* must not be zero, nor 0x9068ffff */

	char *msg[2] = { "Miss", "Hit" };

unsigned int rand_()
{
	m_z = 36969 * (m_z & 65535) + (m_z >> 16);
	m_w = 18000 * (m_w & 65535) + (m_w >> 16);
	return (m_z << 16) + m_w;  /* 32-bit result */
}

unsigned int memGen1()
{
	static unsigned int addr = 0;
	return (addr++) % (DRAM_SIZE);
}

unsigned int memGen2()
{
	static unsigned int addr = 0;
	return  rand_() % (128 * 1024);
}

unsigned int memGen3()
{
	return rand_() % (DRAM_SIZE);
}

unsigned int memGen4()
{
	static unsigned int addr = 0;
	return (addr++) % (1024);
}

unsigned int memGen5()
{
	static unsigned int addr = 0;
	return (addr++) % (1024 * 64);
}

unsigned int memGen6()
{
	static unsigned int addr = 0;
	return (addr += 256) % (DRAM_SIZE);
}

cacheResType cacheSim_direct_4(unsigned int addr, int cache_4[16384][2]) // Cache Simulator
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 1 
	//Direct Mapped Cache with cache size =64, and varying line size form 4 to 128 bytes, steps of power 2


	//2 offset bits; 14 bits for index; 16 bits for tag 
	unsigned int index = addr >> 2;
	index = index & 0x00003FFF;

	unsigned int tag = addr >> 16;
	tag = tag & 0x0000FFFF;


	//check for compulsory miss 
	if (cache_4[index][0] != 1)
	{
		cache_4[index][0] = 1;	//change the validity bit
		cache_4[index][1] = tag;
		return MISS;
	}
	else if (cache_4[index][1] == tag && cache_4[index][0] == 1)
		return HIT;
	else
	{
		cache_4[index][1] = tag;
		return MISS;
	}
}

cacheResType cacheSim_direct_8(unsigned int addr, int cache_8[8192][2])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 1 
	//Direct Mapped Cache with cache size =64, and varying line size form 4 to 128 bytes, steps of power 2


	//2 offset byte bits; 1 bit for word offset; 13 bits for index; 16 bits for tag 
	unsigned int index = addr >> 3;
	index = index & 0x00001FFF;

	unsigned int tag = addr >> 16;
	tag = tag & 0x0000FFFF;


	//check for compulsory miss 
	if (cache_8[index][0] != 1)
	{
		cache_8[index][0] = 1;	//change the validity bit
		cache_8[index][1] = tag;

		return MISS;
	}
	else if (cache_8[index][1] == tag &&cache_8[index][0] == 1)
		return HIT;
	else
	{
		cache_8[index][1] = tag;
		return MISS;
	}
}

cacheResType cacheSim_direct_16(unsigned int addr, int cache_16[4096][2])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 1 
	//Direct Mapped Cache with cache size =64, and varying line size form 4 to 128 bytes, steps of power 2


	//2 offset byte bits; 2 bit for word offset; 12 bits for index; 16 bits for tag 
	unsigned int index = addr >> 4;
	index = index & 0x00000FFF;

	unsigned int tag = addr >> 16;
	tag = tag & 0x0000FFFF;


	//check for compulsory miss 
	if (cache_16[index][0] != 1)
	{
		cache_16[index][0] = 1;	//change the validity bit
		cache_16[index][1] = tag;

		return MISS;
	}
	else if (cache_16[index][1] == tag &&cache_16[index][0] == 1)
		return HIT;
	else
	{
		cache_16[index][1] = tag;
		return MISS;
	}
}

cacheResType cacheSim_direct_32(unsigned int addr, int cache_32[2048][2])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 1 
	//Direct Mapped Cache with cache size =64, and varying line size form 4 to 128 bytes, steps of power 2


	//2 offset byte bits; 3 bit for word offset; 11 bits for index; 16 bits for tag 
	unsigned int index = addr >> 5;
	index = index & 0x000007FF;

	unsigned int tag = addr >> 16;
	tag = tag & 0x0000FFFF;


	//check for compulsory miss 
	if (cache_32[index][0] != 1)
	{
		cache_32[index][0] = 1;	//change the validity bit
		cache_32[index][1] = tag;

		return MISS;
	}
	else if (cache_32[index][1] == tag &&cache_32[index][0] == 1)
		return HIT;
	else
	{
		cache_32[index][1] = tag;
		return MISS;
	}
}

cacheResType cacheSim_direct_64(unsigned int addr, int cache_64[1024][2])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 1 
	//Direct Mapped Cache with cache size =64, and varying line size form 4 to 128 bytes, steps of power 2


	//2 offset byte bits; 4 bit for word offset; 10 bits for index; 16 bits for tag 
	unsigned int index = addr >> 6;
	index = index & 0x000003FF;

	unsigned int tag = addr >> 16;
	tag = tag & 0x0000FFFF;


	//check for compulsory miss 
	if (cache_64[index][0] != 1)
	{
		cache_64[index][0] = 1;	//change the validity bit
		cache_64[index][1] = tag;

		// The current implementation assumes there is no cache; so, every transaction is a miss
		return MISS;
	}
	else if (cache_64[index][1] == tag &&cache_64[index][0] == 1)
		return HIT;
	else
	{
		cache_64[index][1] = tag;
		return MISS;
	}
}

cacheResType cacheSim_direct_128(unsigned int addr, int cache_128[512][2])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 1 
	//Direct Mapped Cache with cache size =64, and varying line size form 4 to 128 bytes, steps of power 2


	//2 offset byte bits; 5 bit for word offset; 9 bits for index; 16 bits for tag 
	unsigned int index = addr >> 7;
	index = index & 0x000001FF;

	unsigned int tag = addr >> 16;
	tag = tag & 0x0000FFFF;


	//check for compulsory miss 
	if (cache_128[index][0] != 1)
	{
		cache_128[index][0] = 1;	//change the validity bit
		cache_128[index][1] = tag;

		// The current implementation assumes there is no cache; so, every transaction is a miss
		return MISS;
	}
	else if (cache_128[index][1] == tag &&cache_128[index][0] == 1)
		return HIT;
	else
	{
		cache_128[index][1] = tag;
		return MISS;
	}
}

cacheResType cacheSim_direct_line1(unsigned int addr, int line_1[64][2])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 1 
	//Direct Mapped Cache with varying cache size from 1 to, steps of power 2 , line size 16 bytes


	//2 offset byte bits; 2 bit for word offset; 6 bits for index; 22 bits for tag 
	unsigned int index = addr >> 4;
	index = index & 0x0000003F;

	unsigned int tag = addr >> 10;
	tag = tag & 0x003FFFFF;


	//check for compulsory miss 
	if (line_1[index][0] != 1)
	{
		line_1[index][0] = 1;	//change the validity bit
		line_1[index][1] = tag;

		return MISS;
	}
	else if (line_1[index][1] == tag &&line_1[index][0] == 1)
		return HIT;
	else
	{
		line_1[index][1] = tag;
		return MISS;
	}
}

cacheResType cacheSim_direct_line2(unsigned int addr, int line_2[128][2])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 1 
	//Direct Mapped Cache with varying cache size from 1 to, steps of power 2 , line size 16 bytes


	//2 offset byte bits; 2 bit for word offset; 7 bits for index; 21 bits for tag 
	unsigned int index = addr >> 4;
	index = index & 0x0000007F;

	unsigned int tag = addr >> 11;
	tag = tag & 0x001FFFFF;


	//check for compulsory miss 
	if (line_2[index][0] != 1)
	{
		line_2[index][0] = 1;	//change the validity bit
		line_2[index][1] = tag;

		// The current implementation assumes there is no cache; so, every transaction is a miss
		return MISS;
	}
	else if (line_2[index][1] == tag &&line_2[index][0] == 1)
		return HIT;
	else
	{
		line_2[index][1] = tag;
		return MISS;
	}
}

cacheResType cacheSim_direct_line4(unsigned int addr, int line_4[256][2])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 1 
	//Direct Mapped Cache with varying cache size from 1 to, steps of power 2 , line size 16 bytes


	//2 offset byte bits; 2 bit for word offset; 8 bits for index; 20 bits for tag 
	unsigned int index = addr >> 4;
	index = index & 0x000000FF;

	unsigned int tag = addr >> 12;
	tag = tag & 0x000FFFFF;


	//check for compulsory miss 
	if (line_4[index][0] != 1)
	{
		line_4[index][0] = 1;	//change the validity bit
		line_4[index][1] = tag;

		// The current implementation assumes there is no cache; so, every transaction is a miss
		return MISS;
	}
	else if (line_4[index][1] == tag &&line_4[index][0] == 1)
		return HIT;
	else
	{
		line_4[index][1] = tag;
		return MISS;
	}
}

cacheResType cacheSim_direct_line8(unsigned int addr, int line_8[512][2])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 1 
	//Direct Mapped Cache with varying cache size from 1 to, steps of power 2 , line size 16 bytes

	//2 offset byte bits; 2 bit for word offset; 9 bits for index; 19 bits for tag 
	unsigned int index = addr >> 4;
	index = index & 0x000001FF;

	unsigned int tag = addr >> 13;
	tag = tag & 0x0007FFFF;


	//check for compulsory miss 
	if (line_8[index][0] != 1)
	{
		line_8[index][0] = 1;	//change the validity bit
		line_8[index][1] = tag;

		// The current implementation assumes there is no cache; so, every transaction is a miss
		return MISS;
	}
	else if (line_8[index][1] == tag &&line_8[index][0] == 1)
		return HIT;
	else
	{
		line_8[index][1] = tag;
		return MISS;
	}
}

cacheResType cacheSim_direct_line16(unsigned int addr, int line_16[1024][2])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 1 
	//Direct Mapped Cache with varying cache size from 1 to, steps of power 2 , line size 16 bytes

	//2 offset byte bits; 2 bit for word offset; 10 bits for index; 18 bits for tag 
	unsigned int index = addr >> 4;
	index = index & 0x000003FF;

	unsigned int tag = addr >> 14;
	tag = tag & 0x0003FFFF;


	//check for compulsory miss 
	if (line_16[index][0] != 1)
	{
		line_16[index][0] = 1;	//change the validity bit
		line_16[index][1] = tag;

		// The current implementation assumes there is no cache; so, every transaction is a miss
		return MISS;
	}
	else if (line_16[index][1] == tag &&line_16[index][0] == 1)
		return HIT;
	else
	{
		line_16[index][1] = tag;
		return MISS;
	}
}

cacheResType cacheSim_direct_line32(unsigned int addr, int line_32[2048][2])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 1 
	//Direct Mapped Cache with varying cache size from 1 to, steps of power 2 , line size 16 bytes


	//2 offset byte bits; 2 bit for word offset; 11 bits for index; 17 bits for tag 
	unsigned int index = addr >> 4;
	index = index & 0x000007FF;

	unsigned int tag = addr >> 15;
	tag = tag & 0x0001FFFF;


	//check for compulsory miss 
	if (line_32[index][0] != 1)
	{
		line_32[index][0] = 1;	//change the validity bit
		line_32[index][1] = tag;

		// The current implementation assumes there is no cache; so, every transaction is a miss
		return MISS;
	}
	else if (line_32[index][1] == tag &&line_32[index][0] == 1)
		return HIT;
	else
	{
		line_32[index][1] = tag;
		return MISS;
	}
}

cacheResType cacheSim_direct_line64(unsigned int addr, int line_64[4096][2])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 1 
	//Direct Mapped Cache with varying cache size from 1 to, steps of power 2 , line size 16 bytes


	//2 offset byte bits; 2 bit for word offset; 12 bits for index; 16 bits for tag 
	unsigned int index = addr >> 4;
	index = index & 0x00000FFF;

	unsigned int tag = addr >> 16;
	tag = tag & 0x0000FFFF;


	//check for compulsory miss 
	if (line_64[index][0] != 1)
	{
		line_64[index][0] = 1;	//change the validity bit
		line_64[index][1] = tag;

		// The current implementation assumes there is no cache; so, every transaction is a miss
		return MISS;
	}
	else if (line_64[index][1] == tag &&line_64[index][0] == 1)
		return HIT;
	else
	{
		line_64[index][1] = tag;
		return MISS;
	}
}

cacheResType cacheSim_full_1(unsigned int addr, int cache_32_1[32][2])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 2 
	//Fully Associative Cache with varying Cache size from 1 KB to 16 KB and Fixed Line Size 32 bytes


	//5 offset bits (Byte Select); 27 bits for tag 

	//vector<unsigned int>cache_32_1[32];

	unsigned int tag = addr >> 5;
	tag = tag & 0x07FFFFFF;


	bool flag = 0;
	int i = 0;
	int randomize;

	//check for compulsory miss
	for (; i < 32; i++)
	{
		if (cache_32_1[i][0] != 1)
		{
			flag = 1;
			break;
			//return MISS;
		}

		//check if hit then
		else if (cache_32_1[i][1] == tag)
		{
			flag = 1; //may not be needed
			return HIT;
			break; //may not be needed
		}
	}

	//compuslory miss
	if (flag) {
		cache_32_1[i][0] = 1;
		cache_32_1[i][1] = tag;
		return MISS;
	}
	//random replacement
	else {
		randomize = rand() % 32;
		cache_32_1[randomize][0] = 1; //may not be needed
		cache_32_1[randomize][1] = tag;
		return MISS;
	}
}

cacheResType cacheSim_full_2(unsigned int addr, int cache_32_2[64][2])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 2 
	//Fully Associative Cache with varying Cache size from 1 KB to 16 KB and Fixed Line Size 32 bytes


	//5 offset bits (Byte Select); 27 bits for tag 

	//vector<unsigned int>cache_32_1[32];

	unsigned int tag = addr >> 5;
	tag = tag & 0x07FFFFFF;


	bool flag = 0;
	int i = 0;
	int randomize;

	//chechk for compulsory miss
	for (; i < 64; i++)
	{
		if (cache_32_2[i][0] != 1)
		{
			flag = 1;
			break;
			//return MISS;
		}

		//chack if hit then
		else if (cache_32_2[i][1] == tag)
		{
			flag = 1;
			return HIT;
			break;
		}
	}

	//compuslory miss
	if (flag) {
		cache_32_2[i][0] = 1;
		cache_32_2[i][1] = tag;
		return MISS;
	}
	//random replacement
	else {
		randomize = rand() % 64;
		cache_32_2[randomize][0] = 1;
		cache_32_2[randomize][1] = tag;
		return MISS;
	}
}

cacheResType cacheSim_full_4(unsigned int addr, int cache_32_4[128][2])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 2 
	//Fully Associative Cache with varying Cache size from 1 KB to 16 KB and Fixed Line Size 32 bytes


	//5 offset bits (Byte Select); 27 bits for tag 

	//vector<unsigned int>cache_32_1[32];

	unsigned int tag = addr >> 5;
	tag = tag & 0x07FFFFFF;


	bool flag = 0;
	int i = 0;
	int randomize;

	//chechk for compulsory miss
	for (; i < 128; i++)
	{
		if (cache_32_4[i][0] != 1)
		{
			flag = 1;
			break;
			//return MISS;
		}

		//chack if hit then
		else if (cache_32_4[i][1] == tag)
		{
			flag = 1;
			return HIT;
			break;
		}
	}

	//compuslory miss
	if (flag) {
		cache_32_4[i][0] = 1;
		cache_32_4[i][1] = tag;
		return MISS;
	}
	//random replacement
	else {
		randomize = rand() % 128;
		cache_32_4[randomize][0] = 1;
		cache_32_4[randomize][1] = tag;
		return MISS;
	}
}

cacheResType cacheSim_full_8(unsigned int addr, int cache_32_8[256][2])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 2 
	//Fully Associative Cache with varying Cache size from 1 KB to 16 KB and Fixed Line Size 32 bytes


	//5 offset bits (Byte Select); 27 bits for tag 

	//vector<unsigned int>cache_32_1[32];

	unsigned int tag = addr >> 5;
	tag = tag & 0x07FFFFFF;


	//bool found = 0;
	bool flag = 0;
	int i = 0;
	int randomize;

	//chechk for compulsory miss
	for (; i < 256; i++)
	{
		if (cache_32_8[i][0] != 1)
		{
			flag = 1;
			break;
			//return MISS;
		}

		//chack if hit then
		else if (cache_32_8[i][1] == tag)
		{
			flag = 1;
			return HIT;
			break;
		}
	}

	//compuslory miss
	if (flag) {
		cache_32_8[i][0] = 1;
		cache_32_8[i][1] = tag;
		return MISS;
	}
	//random replacement
	else {
		randomize = rand() % 256;
		cache_32_8[randomize][0] = 1;
		cache_32_8[randomize][1] = tag;
		return MISS;
	}
}

cacheResType cacheSim_full_16(unsigned int addr, int cache_32_16[512][2])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 2 
	//Fully Associative Cache with varying Cache size from 1 KB to 16 KB and Fixed Line Size 32 bytes


	//5 offset bits (Byte Select); 27 bits for tag 

	//vector<unsigned int>cache_32_1[32];

	unsigned int tag = addr >> 5;
	tag = tag & 0x07FFFFFF;

	bool flag = 0;
	int i = 0;
	int randomize;

	//chechk for compulsory miss
	for (; i < 512; i++)
	{
		if (cache_32_16[i][0] != 1)
		{
			flag = 1;
			break;
			//return MISS;
		}

		//chack if hit then
		else if (cache_32_16[i][1] == tag)
		{
			flag = 1;
			return HIT;
			break;
		}
	}

	//compuslory miss
	if (flag) {
		cache_32_16[i][0] = 1;
		cache_32_16[i][1] = tag;
		return MISS;
	}
	//random replacement
	else {
		randomize = rand() % 512;
		cache_32_16[randomize][0] = 1;
		cache_32_16[randomize][1] = tag;
		return MISS;
	}
}

cacheResType cacheSim_full_FIFO(unsigned int addr, vector<int>&cache_32_FIFO)
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 2 
	//Fully Associative Cache with Cache size 4 KB and Line Size 32 bytes
	//FIFO Replacement

	//5 offset bits (Byte Select); 27 bits for tag 

	unsigned int tag = addr >> 5;
	tag = tag & 0x07FFFFFF;


	bool found = 0;

	//check for compulsory miss
	if (cache_32_FIFO.empty())
	{
		cache_32_FIFO.push_back(tag);
		return MISS;
	}
	else {
		for (int i = 0; i < cache_32_FIFO.size(); i++)
			if (cache_32_FIFO[i] == tag)
			{
			found = 1;
			//break;
			return HIT;
			}
	}

	if (!found)
	{
		if (cache_32_FIFO.size() < 128)
			cache_32_FIFO.push_back(tag);
		else
		{
			cache_32_FIFO.erase(cache_32_FIFO.begin());
			cache_32_FIFO.push_back(tag);
		}
		return MISS;
	}
}

cacheResType cacheSim_full_LRU(unsigned int addr, vector<int>&cache_32_LRU)
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 2 
	//Fully Associative Cache with Cache size 4 KB and Line Size 32 bytes
	//Least Recently Used Replacement

	//5 offset bits (Byte Select); 27 bits for tag 

	unsigned int tag = addr >> 5;
	tag = tag & 0x07FFFFFF;

	bool found = 0;

	//check for compulsory miss
	if (cache_32_LRU.empty())
	{
		cache_32_LRU.push_back(tag);
		return MISS;
	}
	else {
		for (int i = 0; i < cache_32_LRU.size(); i++)
			if (cache_32_LRU[i] == tag)
			{
			found = 1;
			cache_32_LRU.erase(cache_32_LRU.begin()+i);
			cache_32_LRU.push_back(tag);
			//break;
			return HIT;
			}
	}

	if (!found)
	{
		if (cache_32_LRU.size() < 128)
			cache_32_LRU.push_back(tag);
		else
		{
			cache_32_LRU.erase(cache_32_LRU.begin());
			cache_32_LRU.push_back(tag);
		}
		return MISS;
	}
}

cacheResType cacheSim_full_LFU(unsigned int addr, int cache_32_LFU[128][3])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 2 
	//Fully Associative Cache with Cache size 4 KB and Line Size 32 bytes
	//Least Frequently Used Replacement

	//5 offset bits (Byte Select); 27 bits for tag 

	unsigned int tag = addr >> 5;
	tag = tag & 0x07FFFFFF;

	bool flag = 0;
	int i = 0;
	int leastCount, leastUsed;

	//chechk for compulsory miss
	for (; i < 128; i++)
	{
		if (cache_32_LFU[i][0] != 1)
		{
			flag = 1;
			break;
			//return MISS;
		}

		//check if hit then
		else if (cache_32_LFU[i][1] == tag)
		{
			flag = 1; //may not be needed
			cache_32_LFU[i][2]++;
			//cout << " i: " << i << " ";
			return HIT;
			break; //may not be needed
		}
	}

	//compuslory miss
	if (flag) {
		cache_32_LFU[i][0] = 1;
		cache_32_LFU[i][1] = tag;
		//if (tag == 16) cout << " tag of 16: " << addr << " ";
		cache_32_LFU[i][2] = 1;
		return MISS;
	}
	//least frquently used replacement
	else {
		leastCount = cache_32_LFU[0][2];
		leastUsed = 0;
		for (int j = 0; j < 128; j++)
			if (cache_32_LFU[j][2] < leastCount){
			leastCount = cache_32_LFU[j][2];
			leastUsed = j;
			if (leastCount == 1) break;
			}
		cache_32_LFU[leastUsed][0] = 1;
		cache_32_LFU[leastUsed][1] = tag;
		cache_32_LFU[leastUsed][2] = 1;
		return MISS;
	}
}

cacheResType cacheSim_set_2(unsigned int addr, int set_2[1024][2][2])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 3
	//Set Associative Cache with varying number of ways from 2 to 16. Fixed Line Size: 32 bytes and Cache size 64 KB. Random replacement.

	//5 offset bits (Byte Select); 10 for index; 17 bits for tag 

	unsigned int index = addr >> 5;
	index = index & 0x000003FF;

	unsigned int tag = addr >> 15;
	tag = tag & 0x0001FFFF;

	bool flag = 0;
	int i = 0;
	int randomize;

	//chechk for compulsory miss
	for (; i < 2; i++)
	{
		if (set_2[index][i][0] != 1)
		{
			flag = 1;
			break;
			//return MISS;
		}

		//chack if hit then
		else if (set_2[index][i][1] == tag)
		{
			flag = 1;
			return HIT;
			break; //may not be needed
		}
	}

	//compuslory miss
	if (flag) {
		set_2[index][i][0] = 1;
		set_2[index][i][1] = tag;
		return MISS;
	}
	//random replacement
	else {
		randomize = rand() % 2;
		set_2[index][randomize][0] = 1; //may not be needed
		set_2[index][randomize][1] = tag;
		return MISS;
	}
}

cacheResType cacheSim_set_4(unsigned int addr, int set_4[512][4][2])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 3
	//Set Associative Cache with varying number of ways from 2 to 16. Fixed Line Size: 32 bytes and Cache size 64 KB. Random replacement.

	//5 offset bits (Byte Select); 9 for index; 18 bits for tag 

	unsigned int index = addr >> 5;
	index = index & 0x000001FF;

	unsigned int tag = addr >> 14;
	tag = tag & 0x0003FFFF;

	bool flag = 0;
	int i = 0;
	int randomize;

	//chechk for compulsory miss
	for (; i < 4; i++)
	{
		if (set_4[index][i][0] != 1)
		{
			flag = 1;
			break;
			//return MISS;
		}

		//check if hit then
		else if (set_4[index][i][1] == tag)
		{
			flag = 1;
			return HIT;
			break; //may not be needed
		}
	}

	//compuslory miss
	if (flag) {
		set_4[index][i][0] = 1;
		set_4[index][i][1] = tag;
		return MISS;
	}
	//random replacement
	else {
		randomize = rand() % 4;
		set_4[index][randomize][0] = 1; //may not be needed
		set_4[index][randomize][1] = tag;
		return MISS;
	}
}

cacheResType cacheSim_set_8(unsigned int addr, int set_8[256][8][2])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 3
	//Set Associative Cache with varying number of ways from 2 to 16. Fixed Line Size: 32 bytes and Cache size 64 KB. Random replacement.

	//5 offset bits (Byte Select); 8 for index; 19 bits for tag 

	unsigned int index = addr >> 5;
	index = index & 0x000000FF;

	unsigned int tag = addr >> 13;
	tag = tag & 0x0007FFFF;

	bool flag = 0;
	int i = 0;
	int randomize;

	//chechk for compulsory miss
	for (; i < 8; i++)
	{
		if (set_8[index][i][0] != 1)
		{
			flag = 1;
			break;
			//return MISS;
		}

		//check if hit then
		else if (set_8[index][i][1] == tag)
		{
			flag = 1;
			return HIT;
			break; //may not be needed
		}
	}

	//compuslory miss
	if (flag) {
		set_8[index][i][0] = 1;
		set_8[index][i][1] = tag;
		return MISS;
	}
	//random replacement
	else {
		randomize = rand() % 8;
		set_8[index][randomize][0] = 1; //may not be needed
		set_8[index][randomize][1] = tag;
		return MISS;
	}
}

cacheResType cacheSim_set_16(unsigned int addr, int set_16[128][16][2])
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	//Run Experiment 3
	//Set Associative Cache with varying number of ways from 2 to 16. Fixed Line Size: 32 bytes and Cache size 64 KB. Random replacement.

	//5 offset bits (Byte Select); 7 for index; 20 bits for tag 

	unsigned int index = addr >> 5;
	index = index & 0x0000007F;

	unsigned int tag = addr >> 12;
	tag = tag & 0x000FFFFF;

	bool flag = 0;
	int i = 0;
	int randomize;

	//chechk for compulsory miss
	for (; i < 16; i++)
	{
		if (set_16[index][i][0] != 1)
		{
			flag = 1;
			break;
			//return MISS;
		}

		//check if hit then
		else if (set_16[index][i][1] == tag)
		{
			flag = 1;
			return HIT;
			break; //may not be needed
		}
	}

	//compuslory miss
	if (flag) {
		set_16[index][i][0] = 1;
		set_16[index][i][1] = tag;
		return MISS;
	}
	//random replacement
	else {
		randomize = rand() % 16;
		set_16[index][randomize][0] = 1; //may not be needed
		set_16[index][randomize][1] = tag;
		return MISS;
	}
}

void show_miss_ratio_1() {

	int inst = 0;
	cacheResType r;

	// Variables to store the hit ratios
	double miss_1 = 0, miss_2 = 0, miss_3 = 0, miss_4 = 0, miss_5 = 0, miss_6 = 0; // Direct mapped cache, cache size: 64 KB, line sizes change
	double miss_11 = 0, miss_22 = 0, miss_33 = 0, miss_44 = 0, miss_55 = 0, miss_66 = 0, miss_77 = 0; // Direct mapped cache, line size: 16 B, cache sizes change
	double miss_111 = 0, miss_222 = 0, miss_333 = 0, miss_444 = 0, miss_555 = 0; // Full associative cache, line size: 32 B, random, cache sizes change
	double miss_1111 = 0, miss_2222 = 0, miss_3333 = 0; // Full associative cache, line size: 32 B,  access way changes:FIFO, LRU, LFU
	double miss_11111 = 0, miss_22222 = 0, miss_33333 = 0, miss_44444 = 0; // Set associative cache, line size: 32 B, cache size: 64 KB, random, number of ways change
	unsigned int addr;
	
	// 2D arrays of rows = number of blocks, columns = 2 -> validy, tag
	int cache_4[16384][2] = { 0 };	//when there is 4 bytes in line size
	int cache_8[8192][2] = { 0 };	//when there is 8 bytes in line size
	int cache_16[4096][2] = { 0 };	//when there is 16 bytes in line size 
	int cache_32[2048][2] = { 0 };	//when there is 32 bytes in line size 
	int cache_64[1024][2] = { 0 };	//when there is 64 bytes in line size 
	int cache_128[512][2] = { 0 };	//when there is 128 bytes in line size 

	//defining the cache arrays used for direct mapping: line size= 16 bytes, cache size varies from 1KB - 64 KB  
	int line_1[64][2] = { 0 };
	int line_2[128][2] = { 0 };
	int line_4[256][2] = { 0 };
	int line_8[512][2] = { 0 };
	int line_16[1024][2] = { 0 };
	int line_32[2048][2] = { 0 };
	int line_64[4096][2] = { 0 };

	//cache array sizes for full associative random replacement
	int cache_32_1[32][2] = { 0 };
	int cache_32_2[64][2] = { 0 };
	int cache_32_4[128][2] = { 0 };
	int cache_32_8[256][2] = { 0 };
	int cache_32_16[512][2] = { 0 };

	//Full associative cache arrays
	vector<int>cache_32_FIFO; // Cache array size for full associatve FIFO replacement
	vector<int>cache_32_LRU; // Cache array size for full associatve LRU replacement
	int cache_32_LFU[128][3] = { 0 }; // Validity, tag, use count

	//Set associative cache arrays: line size= 32 bytes, cache size = 64 KB, Random, no. of ways varies from 2 to 16
	int set_2[1024][2][2] = { 0 };
	int set_4[512][4][2] = { 0 };
	int set_8[256][8][2] = { 0 };
	int set_16[128][16][2] = { 0 };
	
	for (; inst<iter; inst++)
	{
		addr = memGen1();
		//cout << "addr " << inst << ": " << addr << endl;
		r = cacheSim_direct_4(addr, cache_4);
		//	cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";
		miss_1 += double(r) / double(iter);

		r = cacheSim_direct_8(addr, cache_8);
		miss_2 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_16(addr, cache_16);
		miss_3 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_32(addr, cache_32);
		miss_4 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_64(addr, cache_64);
		miss_5 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_128(addr, cache_128);
		miss_6 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line1(addr, line_1);
		miss_11 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line2(addr, line_2);
		miss_22 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line4(addr, line_4);
		miss_33 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line8(addr, line_8);
		miss_44 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line16(addr, line_16);
		miss_55 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line32(addr, line_32);
		miss_66 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line64(addr, line_64);
		miss_77 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_1(addr, cache_32_1);
		miss_111 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_2(addr, cache_32_2);
		miss_222 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_4(addr, cache_32_4);
		miss_333 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_8(addr, cache_32_8);
		miss_444 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_16(addr, cache_32_16);
		miss_555 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_FIFO(addr, cache_32_FIFO);
		miss_1111 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_full_LRU(addr, cache_32_LRU);
		miss_2222 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_full_LFU(addr, cache_32_LFU);
		miss_3333 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_2(addr, set_2);
		miss_11111 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_4(addr, set_4);
		miss_22222 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_8(addr, set_8);
		miss_33333 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_16(addr, set_16);
		miss_44444 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n
	}

	//output the miss ratio;
	cout << "The miss ratios for memgen 1:\n";

	cout << "Experiment 1: Direct Mapping:\na) The following 6 are: Cache Size= 64; Line Size varies from 4-128 bytes:\n";

	cout << 1 - miss_1 << endl << 1 - miss_2 << endl << 1 - miss_3 << endl << 1 - miss_4 << endl << 1 - miss_5 << endl << 1 - miss_6 << endl;

	cout << "b) The following 7 are: Line Size= 16 bytes; Cache Size varies from 1-64 Kbs:\n";
	cout << 1 - miss_11 << endl << 1 - miss_22 << endl << 1 - miss_33 << endl << 1 - miss_44 << endl << 1 - miss_55 << endl << 1 - miss_66 << endl << 1 - miss_77 << endl;

	cout << "Experiment 2: Full Associative:\na)The following 5 are: Line Size= 32 bytes; Random Replacement; Cache Size varies from 1-16 Kbs:\n";
	cout << 1 - miss_111 << endl << 1 - miss_222 << endl << 1 - miss_333 << endl << 1 - miss_444 << endl << 1 - miss_555 << endl;

	cout << "b) The following 4 are: Line Size= 32 bytes; Cache Size = 4 KB; Replacement way varies:\n";
	cout << "FIFO: " << 1 - miss_1111 << endl << "LRU: " << 1 - miss_2222 << endl << "LFU: " << 1 - miss_3333 << endl << "Random: " << 1 - miss_333 << endl;

	cout << "Experiment 3: Set Associative:\nThe following 4 are: Line Size = 32 bytes; Random Replacement; Cache Size = 64 KB; Number of ways varies from 2-16:\n";
	cout << 1 - miss_11111 << endl << 1 - miss_22222 << endl << 1 - miss_33333 << endl << 1 - miss_44444 << endl << endl;
}

void show_miss_ratio_2() {

	int inst = 0;
	cacheResType r;

	// Variables to store the hit ratios
	double miss_1 = 0, miss_2 = 0, miss_3 = 0, miss_4 = 0, miss_5 = 0, miss_6 = 0; // Direct mapped cache, cache size: 64 KB, line sizes change
	double miss_11 = 0, miss_22 = 0, miss_33 = 0, miss_44 = 0, miss_55 = 0, miss_66 = 0, miss_77 = 0; // Direct mapped cache, line size: 16 B, cache sizes change
	double miss_111 = 0, miss_222 = 0, miss_333 = 0, miss_444 = 0, miss_555 = 0; // Full associative cache, line size: 32 B, random, cache sizes change
	double miss_1111 = 0, miss_2222 = 0, miss_3333 = 0; // Full associative cache, line size: 32 B,  access way changes:FIFO, LRU, LFU
	double miss_11111 = 0, miss_22222 = 0, miss_33333 = 0, miss_44444 = 0; // Set associative cache, line size: 32 B, cache size: 64 KB, random, number of ways change
	unsigned int addr;
	// 2D arrays of rows = number of blocks, columns = 2 -> validy, tag
	int cache_4[16384][2] = { 0 };	//when there is 4 bytes in line size
	int cache_8[8192][2] = { 0 };	//when there is 8 bytes in line size
	int cache_16[4096][2] = { 0 };	//when there is 16 bytes in line size 
	int cache_32[2048][2] = { 0 };	//when there is 32 bytes in line size 
	int cache_64[1024][2] = { 0 };	//when there is 64 bytes in line size 
	int cache_128[512][2] = { 0 };	//when there is 128 bytes in line size 

	//defining the cache arrays used for direct mapping: line size= 16 bytes, cache size varies from 1KB - 64 KB  
	int line_1[64][2] = { 0 };
	int line_2[128][2] = { 0 };
	int line_4[256][2] = { 0 };
	int line_8[512][2] = { 0 };
	int line_16[1024][2] = { 0 };
	int line_32[2048][2] = { 0 };
	int line_64[4096][2] = { 0 };

	//cache array sizes for full associative random replacement
	int cache_32_1[32][2] = { 0 };
	int cache_32_2[64][2] = { 0 };
	int cache_32_4[128][2] = { 0 };
	int cache_32_8[256][2] = { 0 };
	int cache_32_16[512][2] = { 0 };

	//Full associative cache arrays
	vector<int>cache_32_FIFO; // Cache array size for full associatve FIFO replacement
	vector<int>cache_32_LRU; // Cache array size for full associatve LRU replacement
	int cache_32_LFU[128][3] = { 0 }; // Validity, tag, use count

	//Set associative cache arrays: line size= 32 bytes, cache size = 64 KB, Random, no. of ways varies from 2 to 16
	int set_2[1024][2][2] = { 0 };
	int set_4[512][4][2] = { 0 };
	int set_8[256][8][2] = { 0 };
	int set_16[128][16][2] = { 0 };
	
	// change the number of iterations into 10,000,000
	for (; inst<iter; inst++)
	{
		addr = memGen2();
		//cout << "addr " << inst << ": " << addr << endl;
		r = cacheSim_direct_4(addr, cache_4);
		//	cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";
		miss_1 += double(r) / double(iter);

		r = cacheSim_direct_8(addr, cache_8);
		miss_2 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_16(addr, cache_16);
		miss_3 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_32(addr, cache_32);
		miss_4 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_64(addr, cache_64);
		miss_5 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_128(addr, cache_128);
		miss_6 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line1(addr, line_1);
		miss_11 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line2(addr, line_2);
		miss_22 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line4(addr, line_4);
		miss_33 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line8(addr, line_8);
		miss_44 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line16(addr, line_16);
		miss_55 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line32(addr, line_32);
		miss_66 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line64(addr, line_64);
		miss_77 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_1(addr, cache_32_1);
		miss_111 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_2(addr, cache_32_2);
		miss_222 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_4(addr, cache_32_4);
		miss_333 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_8(addr, cache_32_8);
		miss_444 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_16(addr, cache_32_16);
		miss_555 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_FIFO(addr, cache_32_FIFO);
		miss_1111 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_full_LRU(addr, cache_32_LRU);
		miss_2222 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_full_LFU(addr, cache_32_LFU);
		miss_3333 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_2(addr, set_2);
		miss_11111 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_4(addr, set_4);
		miss_22222 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_8(addr, set_8);
		miss_33333 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_16(addr, set_16);
		miss_44444 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n
	}
	//output the miss ratio;
	cout << "The miss ratios for memgen 2:\n";

	cout << "Experiment 1: Direct Mapping:\na) The following 6 are: Cache Size= 64; Line Size varies from 4-128 bytes:\n";

	cout << 1 - miss_1 << endl << 1 - miss_2 << endl << 1 - miss_3 << endl << 1 - miss_4 << endl << 1 - miss_5 << endl << 1 - miss_6 << endl;

	cout << "b) The following 7 are: Line Size= 16 bytes; Cache Size varies from 1-64 Kbs:\n";
	cout << 1 - miss_11 << endl << 1 - miss_22 << endl << 1 - miss_33 << endl << 1 - miss_44 << endl << 1 - miss_55 << endl << 1 - miss_66 << endl << 1 - miss_77 << endl;

	cout << "Experiment 2: Full Associative:\na)The following 5 are: Line Size= 32 bytes; Random Replacement; Cache Size varies from 1-16 Kbs:\n";
	cout << 1 - miss_111 << endl << 1 - miss_222 << endl << 1 - miss_333 << endl << 1 - miss_444 << endl << 1 - miss_555 << endl;

	cout << "b) The following 4 are: Line Size= 32 bytes; Cache Size = 4 KB; Replacement way varies:\n";
	cout << "FIFO: " << 1 - miss_1111 << endl << "LRU: " << 1 - miss_2222 << endl << "LFU: " << 1 - miss_3333 << endl << "Random: " << 1 - miss_333 << endl;

	cout << "Experiment 3: Set Associative:\nThe following 4 are: Line Size = 32 bytes; Random Replacement; Cache Size = 64 KB; Number of ways varies from 2-16:\n";
	cout << 1 - miss_11111 << endl << 1 - miss_22222 << endl << 1 - miss_33333 << endl << 1 - miss_44444 << endl << endl;
}

void show_miss_ratio_3() {

	int inst = 0;
	cacheResType r;

	// Variables to store the hit ratios
	double miss_1 = 0, miss_2 = 0, miss_3 = 0, miss_4 = 0, miss_5 = 0, miss_6 = 0; // Direct mapped cache, cache size: 64 KB, line sizes change
	double miss_11 = 0, miss_22 = 0, miss_33 = 0, miss_44 = 0, miss_55 = 0, miss_66 = 0, miss_77 = 0; // Direct mapped cache, line size: 16 B, cache sizes change
	double miss_111 = 0, miss_222 = 0, miss_333 = 0, miss_444 = 0, miss_555 = 0; // Full associative cache, line size: 32 B, random, cache sizes change
	double miss_1111 = 0, miss_2222 = 0, miss_3333 = 0; // Full associative cache, line size: 32 B,  access way changes:FIFO, LRU, LFU
	double miss_11111 = 0, miss_22222 = 0, miss_33333 = 0, miss_44444 = 0; // Set associative cache, line size: 32 B, cache size: 64 KB, random, number of ways change
	unsigned int addr;
	// 2D arrays of rows = number of blocks, columns = 2 -> validy, tag
	int cache_4[16384][2] = { 0 };	//when there is 4 bytes in line size
	int cache_8[8192][2] = { 0 };	//when there is 8 bytes in line size
	int cache_16[4096][2] = { 0 };	//when there is 16 bytes in line size 
	int cache_32[2048][2] = { 0 };	//when there is 32 bytes in line size 
	int cache_64[1024][2] = { 0 };	//when there is 64 bytes in line size 
	int cache_128[512][2] = { 0 };	//when there is 128 bytes in line size 

	//defining the cache arrays used for direct mapping: line size= 16 bytes, cache size varies from 1KB - 64 KB  
	int line_1[64][2] = { 0 };
	int line_2[128][2] = { 0 };
	int line_4[256][2] = { 0 };
	int line_8[512][2] = { 0 };
	int line_16[1024][2] = { 0 };
	int line_32[2048][2] = { 0 };
	int line_64[4096][2] = { 0 };

	//cache array sizes for full associative random replacement
	int cache_32_1[32][2] = { 0 };
	int cache_32_2[64][2] = { 0 };
	int cache_32_4[128][2] = { 0 };
	int cache_32_8[256][2] = { 0 };
	int cache_32_16[512][2] = { 0 };

	//Full associative cache arrays
	vector<int>cache_32_FIFO; // Cache array size for full associatve FIFO replacement
	vector<int>cache_32_LRU; // Cache array size for full associatve LRU replacement
	int cache_32_LFU[128][3] = { 0 }; // Validity, tag, use count

	//Set associative cache arrays: line size= 32 bytes, cache size = 64 KB, Random, no. of ways varies from 2 to 16
	int set_2[1024][2][2] = { 0 };
	int set_4[512][4][2] = { 0 };
	int set_8[256][8][2] = { 0 };
	int set_16[128][16][2] = { 0 };
	
	// change the number of iterations into 10,000,000
	for (; inst<iter; inst++)
	{
		addr = memGen3();
		//cout << "addr " << inst << ": " << addr << endl;
		r = cacheSim_direct_4(addr, cache_4);
		//	cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";
		miss_1 += double(r) / double(iter);

		r = cacheSim_direct_8(addr, cache_8);
		miss_2 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_16(addr, cache_16);
		miss_3 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_32(addr, cache_32);
		miss_4 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_64(addr, cache_64);
		miss_5 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_128(addr, cache_128);
		miss_6 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line1(addr, line_1);
		miss_11 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line2(addr, line_2);
		miss_22 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line4(addr, line_4);
		miss_33 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line8(addr, line_8);
		miss_44 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line16(addr, line_16);
		miss_55 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line32(addr, line_32);
		miss_66 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line64(addr, line_64);
		miss_77 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_1(addr, cache_32_1);
		miss_111 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_2(addr, cache_32_2);
		miss_222 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_4(addr, cache_32_4);
		miss_333 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_8(addr, cache_32_8);
		miss_444 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_16(addr, cache_32_16);
		miss_555 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_FIFO(addr, cache_32_FIFO);
		miss_1111 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_full_LRU(addr, cache_32_LRU);
		miss_2222 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_full_LFU(addr, cache_32_LFU);
		miss_3333 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_2(addr, set_2);
		miss_11111 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_4(addr, set_4);
		miss_22222 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_8(addr, set_8);
		miss_33333 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_16(addr, set_16);
		miss_44444 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n
	}

	//output the miss ratio;
	cout << "The miss ratios for memgen 3:\n";

	cout << "Experiment 1: Direct Mapping:\na) The following 6 are: Cache Size= 64; Line Size varies from 4-128 bytes:\n";

	cout << 1 - miss_1 << endl << 1 - miss_2 << endl << 1 - miss_3 << endl << 1 - miss_4 << endl << 1 - miss_5 << endl << 1 - miss_6 << endl;

	cout << "b) The following 7 are: Line Size= 16 bytes; Cache Size varies from 1-64 Kbs:\n";
	cout << 1 - miss_11 << endl << 1 - miss_22 << endl << 1 - miss_33 << endl << 1 - miss_44 << endl << 1 - miss_55 << endl << 1 - miss_66 << endl << 1 - miss_77 << endl;

	cout << "Experiment 2: Full Associative:\na)The following 5 are: Line Size= 32 bytes; Random Replacement; Cache Size varies from 1-16 Kbs:\n";
	cout << 1 - miss_111 << endl << 1 - miss_222 << endl << 1 - miss_333 << endl << 1 - miss_444 << endl << 1 - miss_555 << endl;

	cout << "b) The following 4 are: Line Size= 32 bytes; Cache Size = 4 KB; Replacement way varies:\n";
	cout << "FIFO: " << 1 - miss_1111 << endl << "LRU: " << 1 - miss_2222 << endl << "LFU: " << 1 - miss_3333 << endl << "Random: " << 1 - miss_333 << endl;

	cout << "Experiment 3: Set Associative:\nThe following 4 are: Line Size = 32 bytes; Random Replacement; Cache Size = 64 KB; Number of ways varies from 2-16:\n";
	cout << 1 - miss_11111 << endl << 1 - miss_22222 << endl << 1 - miss_33333 << endl << 1 - miss_44444 << endl << endl;
}

void show_miss_ratio_4() {

	int inst = 0;
	cacheResType r;

	// Variables to store the hit ratios
	double miss_1 = 0, miss_2 = 0, miss_3 = 0, miss_4 = 0, miss_5 = 0, miss_6 = 0; // Direct mapped cache, cache size: 64 KB, line sizes change
	double miss_11 = 0, miss_22 = 0, miss_33 = 0, miss_44 = 0, miss_55 = 0, miss_66 = 0, miss_77 = 0; // Direct mapped cache, line size: 16 B, cache sizes change
	double miss_111 = 0, miss_222 = 0, miss_333 = 0, miss_444 = 0, miss_555 = 0; // Full associative cache, line size: 32 B, random, cache sizes change
	double miss_1111 = 0, miss_2222 = 0, miss_3333 = 0; // Full associative cache, line size: 32 B,  access way changes:FIFO, LRU, LFU
	double miss_11111 = 0, miss_22222 = 0, miss_33333 = 0, miss_44444 = 0; // Set associative cache, line size: 32 B, cache size: 64 KB, random, number of ways change
	unsigned int addr;

	// 2D arrays of rows = number of blocks, columns = 2 -> validy, tag
	int cache_4[16384][2] = { 0 };	//when there is 4 bytes in line size
	int cache_8[8192][2] = { 0 };	//when there is 8 bytes in line size
	int cache_16[4096][2] = { 0 };	//when there is 16 bytes in line size 
	int cache_32[2048][2] = { 0 };	//when there is 32 bytes in line size 
	int cache_64[1024][2] = { 0 };	//when there is 64 bytes in line size 
	int cache_128[512][2] = { 0 };	//when there is 128 bytes in line size 

	//defining the cache arrays used for direct mapping: line size= 16 bytes, cache size varies from 1KB - 64 KB  
	int line_1[64][2] = { 0 };
	int line_2[128][2] = { 0 };
	int line_4[256][2] = { 0 };
	int line_8[512][2] = { 0 };
	int line_16[1024][2] = { 0 };
	int line_32[2048][2] = { 0 };
	int line_64[4096][2] = { 0 };

	//cache array sizes for full associative random replacement
	int cache_32_1[32][2] = { 0 };
	int cache_32_2[64][2] = { 0 };
	int cache_32_4[128][2] = { 0 };
	int cache_32_8[256][2] = { 0 };
	int cache_32_16[512][2] = { 0 };

	//Full associative cache arrays
	vector<int>cache_32_FIFO; // Cache array size for full associatve FIFO replacement
	vector<int>cache_32_LRU; // Cache array size for full associatve LRU replacement
	int cache_32_LFU[128][3] = { 0 }; // Validity, tag, use count

	//Set associative cache arrays: line size= 32 bytes, cache size = 64 KB, Random, no. of ways varies from 2 to 16
	int set_2[1024][2][2] = { 0 };
	int set_4[512][4][2] = { 0 };
	int set_8[256][8][2] = { 0 };
	int set_16[128][16][2] = { 0 };

	// change the number of iterations into 10,000,000
	for (; inst<iter; inst++)
	{
		addr = memGen4();
		//cout << "addr " << inst << ": " << addr << endl;
		r = cacheSim_direct_4(addr, cache_4);
		//	cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";
		miss_1 += double(r) / double(iter);

		r = cacheSim_direct_8(addr, cache_8);
		miss_2 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_16(addr, cache_16);
		miss_3 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_32(addr, cache_32);
		miss_4 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_64(addr, cache_64);
		miss_5 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_128(addr, cache_128);
		miss_6 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line1(addr, line_1);
		miss_11 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line2(addr, line_2);
		miss_22 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line4(addr, line_4);
		miss_33 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line8(addr, line_8);
		miss_44 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line16(addr, line_16);
		miss_55 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line32(addr, line_32);
		miss_66 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line64(addr, line_64);
		miss_77 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_1(addr, cache_32_1);
		miss_111 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_2(addr, cache_32_2);
		miss_222 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_4(addr, cache_32_4);
		miss_333 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_8(addr, cache_32_8);
		miss_444 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_16(addr, cache_32_16);
		miss_555 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_FIFO(addr, cache_32_FIFO);
		miss_1111 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_full_LRU(addr, cache_32_LRU);
		miss_2222 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_full_LFU(addr, cache_32_LFU);
		miss_3333 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_2(addr, set_2);
		miss_11111 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_4(addr, set_4);
		miss_22222 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_8(addr, set_8);
		miss_33333 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_16(addr, set_16);
		miss_44444 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n
	}

	//output the miss ratio;
	cout << "The miss ratios for memgen 4:\n";

	cout << "Experiment 1: Direct Mapping:\na) The following 6 are: Cache Size= 64; Line Size varies from 4-128 bytes:\n";

	cout << 1 - miss_1 << endl << 1 - miss_2 << endl << 1 - miss_3 << endl << 1 - miss_4 << endl << 1 - miss_5 << endl << 1 - miss_6 << endl;

	cout << "b) The following 7 are: Line Size= 16 bytes; Cache Size varies from 1-64 Kbs:\n";
	cout << 1 - miss_11 << endl << 1 - miss_22 << endl << 1 - miss_33 << endl << 1 - miss_44 << endl << 1 - miss_55 << endl << 1 - miss_66 << endl << 1 - miss_77 << endl;

	cout << "Experiment 2: Full Associative:\na)The following 5 are: Line Size= 32 bytes; Random Replacement; Cache Size varies from 1-16 Kbs:\n";
	cout << 1 - miss_111 << endl << 1 - miss_222 << endl << 1 - miss_333 << endl << 1 - miss_444 << endl << 1 - miss_555 << endl;

	cout << "b) The following 4 are: Line Size= 32 bytes; Cache Size = 4 KB; Replacement way varies:\n";
	cout << "FIFO: " << 1 - miss_1111 << endl << "LRU: " << 1 - miss_2222 << endl << "LFU: " << 1 - miss_3333 << endl << "Random: " << 1 - miss_333 << endl;

	cout << "Experiment 3: Set Associative:\nThe following 4 are: Line Size = 32 bytes; Random Replacement; Cache Size = 64 KB; Number of ways varies from 2-16:\n";
	cout << 1 - miss_11111 << endl << 1 - miss_22222 << endl << 1 - miss_33333 << endl << 1 - miss_44444 << endl << endl;
}

void show_miss_ratio_5() {

	int inst = 0;
	cacheResType r;

	// Variables to store the hit ratios
	double miss_1 = 0, miss_2 = 0, miss_3 = 0, miss_4 = 0, miss_5 = 0, miss_6 = 0; // Direct mapped cache, cache size: 64 KB, line sizes change
	double miss_11 = 0, miss_22 = 0, miss_33 = 0, miss_44 = 0, miss_55 = 0, miss_66 = 0, miss_77 = 0; // Direct mapped cache, line size: 16 B, cache sizes change
	double miss_111 = 0, miss_222 = 0, miss_333 = 0, miss_444 = 0, miss_555 = 0; // Full associative cache, line size: 32 B, random, cache sizes change
	double miss_1111 = 0, miss_2222 = 0, miss_3333 = 0; // Full associative cache, line size: 32 B,  access way changes:FIFO, LRU, LFU
	double miss_11111 = 0, miss_22222 = 0, miss_33333 = 0, miss_44444 = 0; // Set associative cache, line size: 32 B, cache size: 64 KB, random, number of ways change
	unsigned int addr;

	// 2D arrays of rows = number of blocks, columns = 2 -> validy, tag
	int cache_4[16384][2] = { 0 };	//when there is 4 bytes in line size
	int cache_8[8192][2] = { 0 };	//when there is 8 bytes in line size
	int cache_16[4096][2] = { 0 };	//when there is 16 bytes in line size 
	int cache_32[2048][2] = { 0 };	//when there is 32 bytes in line size 
	int cache_64[1024][2] = { 0 };	//when there is 64 bytes in line size 
	int cache_128[512][2] = { 0 };	//when there is 128 bytes in line size 

	//defining the cache arrays used for direct mapping: line size= 16 bytes, cache size varies from 1KB - 64 KB  
	int line_1[64][2] = { 0 };
	int line_2[128][2] = { 0 };
	int line_4[256][2] = { 0 };
	int line_8[512][2] = { 0 };
	int line_16[1024][2] = { 0 };
	int line_32[2048][2] = { 0 };
	int line_64[4096][2] = { 0 };

	//cache array sizes for full associative random replacement
	int cache_32_1[32][2] = { 0 };
	int cache_32_2[64][2] = { 0 };
	int cache_32_4[128][2] = { 0 };
	int cache_32_8[256][2] = { 0 };
	int cache_32_16[512][2] = { 0 };

	//Full associative cache arrays
	vector<int>cache_32_FIFO; // Cache array size for full associatve FIFO replacement
	vector<int>cache_32_LRU; // Cache array size for full associatve LRU replacement
	int cache_32_LFU[128][3] = { 0 }; // Validity, tag, use count

	//Set associative cache arrays: line size= 32 bytes, cache size = 64 KB, Random, no. of ways varies from 2 to 16
	int set_2[1024][2][2] = { 0 };
	int set_4[512][4][2] = { 0 };
	int set_8[256][8][2] = { 0 };
	int set_16[128][16][2] = { 0 };

	for (; inst<iter; inst++)
	{
		addr = memGen5();
		//cout << "addr " << inst << ": " << addr << endl;
		r = cacheSim_direct_4(addr, cache_4);
		//	cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";
		miss_1 += double(r) / double(iter);

		r = cacheSim_direct_8(addr, cache_8);
		miss_2 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_16(addr, cache_16);
		miss_3 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_32(addr, cache_32);
		miss_4 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_64(addr, cache_64);
		miss_5 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_128(addr, cache_128);
		miss_6 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line1(addr, line_1);
		miss_11 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line2(addr, line_2);
		miss_22 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line4(addr, line_4);
		miss_33 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line8(addr, line_8);
		miss_44 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line16(addr, line_16);
		miss_55 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line32(addr, line_32);
		miss_66 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line64(addr, line_64);
		miss_77 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_1(addr, cache_32_1);
		miss_111 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_2(addr, cache_32_2);
		miss_222 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_4(addr, cache_32_4);
		miss_333 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_8(addr, cache_32_8);
		miss_444 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_16(addr, cache_32_16);
		miss_555 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_FIFO(addr, cache_32_FIFO);
		miss_1111 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_full_LRU(addr, cache_32_LRU);
		miss_2222 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_full_LFU(addr, cache_32_LFU);
		miss_3333 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_2(addr, set_2);
		miss_11111 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_4(addr, set_4);
		miss_22222 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_8(addr, set_8);
		miss_33333 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_16(addr, set_16);
		miss_44444 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n
	}

	//output the miss ratio;
	cout << "The miss ratios for memgen 5:\n";

	cout << "Experiment 1: Direct Mapping:\na) The following 6 are: Cache Size= 64; Line Size varies from 4-128 bytes:\n";

	cout << 1 - miss_1 << endl << 1 - miss_2 << endl << 1 - miss_3 << endl << 1 - miss_4 << endl << 1 - miss_5 << endl << 1 - miss_6 << endl;

	cout << "b) The following 7 are: Line Size= 16 bytes; Cache Size varies from 1-64 Kbs:\n";
	cout << 1 - miss_11 << endl << 1 - miss_22 << endl << 1 - miss_33 << endl << 1 - miss_44 << endl << 1 - miss_55 << endl << 1 - miss_66 << endl << 1 - miss_77 << endl;

	cout << "Experiment 2: Full Associative:\na)The following 5 are: Line Size= 32 bytes; Random Replacement; Cache Size varies from 1-16 Kbs:\n";
	cout << 1 - miss_111 << endl << 1 - miss_222 << endl << 1 - miss_333 << endl << 1 - miss_444 << endl << 1 - miss_555 << endl;

	cout << "b) The following 4 are: Line Size= 32 bytes; Cache Size = 4 KB; Replacement way varies:\n";
	cout << "FIFO: " << 1 - miss_1111 << endl << "LRU: " << 1 - miss_2222 << endl << "LFU: " << 1 - miss_3333 << endl << "Random: " << 1 - miss_333 << endl;

	cout << "Experiment 3: Set Associative:\nThe following 4 are: Line Size = 32 bytes; Random Replacement; Cache Size = 64 KB; Number of ways varies from 2-16:\n";
	cout << 1 - miss_11111 << endl << 1 - miss_22222 << endl << 1 - miss_33333 << endl << 1 - miss_44444 << endl << endl;
}

void show_miss_ratio_6() {

	int inst = 0;
	cacheResType r;

	// Variables to store the hit ratios
	double miss_1 = 0, miss_2 = 0, miss_3 = 0, miss_4 = 0, miss_5 = 0, miss_6 = 0; // Direct mapped cache, cache size: 64 KB, line sizes change
	double miss_11 = 0, miss_22 = 0, miss_33 = 0, miss_44 = 0, miss_55 = 0, miss_66 = 0, miss_77 = 0; // Direct mapped cache, line size: 16 B, cache sizes change
	double miss_111 = 0, miss_222 = 0, miss_333 = 0, miss_444 = 0, miss_555 = 0; // Full associative cache, line size: 32 B, random, cache sizes change
	double miss_1111 = 0, miss_2222 = 0, miss_3333 = 0; // Full associative cache, line size: 32 B,  access way changes:FIFO, LRU, LFU
	double miss_11111 = 0, miss_22222 = 0, miss_33333 = 0, miss_44444 = 0; // Set associative cache, line size: 32 B, cache size: 64 KB, random, number of ways change
	unsigned int addr;

	// 2D arrays of rows = number of blocks, columns = 2 -> validy, tag
	int cache_4[16384][2] = { 0 };	//when there is 4 bytes in line size
	int cache_8[8192][2] = { 0 };	//when there is 8 bytes in line size
	int cache_16[4096][2] = { 0 };	//when there is 16 bytes in line size 
	int cache_32[2048][2] = { 0 };	//when there is 32 bytes in line size 
	int cache_64[1024][2] = { 0 };	//when there is 64 bytes in line size 
	int cache_128[512][2] = { 0 };	//when there is 128 bytes in line size 

	//defining the cache arrays used for direct mapping: line size= 16 bytes, cache size varies from 1KB - 64 KB  
	int line_1[64][2] = { 0 };
	int line_2[128][2] = { 0 };
	int line_4[256][2] = { 0 };
	int line_8[512][2] = { 0 };
	int line_16[1024][2] = { 0 };
	int line_32[2048][2] = { 0 };
	int line_64[4096][2] = { 0 };

	//cache array sizes for full associative random replacement
	int cache_32_1[32][2] = { 0 };
	int cache_32_2[64][2] = { 0 };
	int cache_32_4[128][2] = { 0 };
	int cache_32_8[256][2] = { 0 };
	int cache_32_16[512][2] = { 0 };

	//Full associative cache arrays
	vector<int>cache_32_FIFO; // Cache array size for full associatve FIFO replacement
	vector<int>cache_32_LRU; // Cache array size for full associatve LRU replacement
	int cache_32_LFU[128][3] = { 0 }; // Validity, tag, use count

	//Set associative cache arrays: line size= 32 bytes, cache size = 64 KB, Random, no. of ways varies from 2 to 16
	int set_2[1024][2][2] = { 0 };
	int set_4[512][4][2] = { 0 };
	int set_8[256][8][2] = { 0 };
	int set_16[128][16][2] = { 0 };
	
	for (; inst<iter; inst++)
	{
		addr = memGen6();
		//cout << "addr " << inst << ": " << addr << endl;
		r = cacheSim_direct_4(addr, cache_4);
		//	cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";
		miss_1 += double(r) / double(iter);

		r = cacheSim_direct_8(addr, cache_8);
		miss_2 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_16(addr, cache_16);
		miss_3 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_32(addr, cache_32);
		miss_4 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_64(addr, cache_64);
		miss_5 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_128(addr, cache_128);
		miss_6 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line1(addr, line_1);
		miss_11 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line2(addr, line_2);
		miss_22 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line4(addr, line_4);
		miss_33 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line8(addr, line_8);
		miss_44 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line16(addr, line_16);
		miss_55 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line32(addr, line_32);
		miss_66 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_direct_line64(addr, line_64);
		miss_77 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_1(addr, cache_32_1);
		miss_111 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_2(addr, cache_32_2);
		miss_222 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_4(addr, cache_32_4);
		miss_333 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_8(addr, cache_32_8);
		miss_444 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_16(addr, cache_32_16);
		miss_555 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n";

		r = cacheSim_full_FIFO(addr, cache_32_FIFO);
		miss_1111 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_full_LRU(addr, cache_32_LRU);
		miss_2222 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_full_LFU(addr, cache_32_LFU);
		miss_3333 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n
		//if (double(r)) { cout << "LFU hit: " << addr << ", inst: " << inst << endl; LFUhits++; }
		r = cacheSim_set_2(addr, set_2);
		miss_11111 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_4(addr, set_4);
		miss_22222 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_8(addr, set_8);
		miss_33333 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n

		r = cacheSim_set_16(addr, set_16);
		miss_44444 += double(r) / double(iter);
		//cout << "0x" << setfill('0') << setw(8) << hex << addr << " (" << msg[r] << ")\n
	}

	//output the miss ratio;
	cout << "The miss ratios for memgen 6:\n";

	cout << "Experiment 1: Direct Mapping:\na) The following 6 are: Cache Size= 64; Line Size varies from 4-128 bytes:\n";

	cout << 1 - miss_1 << endl << 1 - miss_2 << endl << 1 - miss_3 << endl << 1 - miss_4 << endl << 1 - miss_5 << endl << 1 - miss_6 << endl;

	cout << "b) The following 7 are: Line Size= 16 bytes; Cache Size varies from 1-64 Kbs:\n";
	cout << 1 - miss_11 << endl << 1 - miss_22 << endl << 1 - miss_33 << endl << 1 - miss_44 << endl << 1 - miss_55 << endl << 1 - miss_66 << endl << 1 - miss_77 << endl;

	cout << "Experiment 2: Full Associative:\na)The following 5 are: Line Size= 32 bytes; Random Replacement; Cache Size varies from 1-16 Kbs:\n";
	cout << 1 - miss_111 << endl << 1 - miss_222 << endl << 1 - miss_333 << endl << 1 - miss_444 << endl << 1 - miss_555 << endl;

	cout << "b) The following 4 are: Line Size= 32 bytes; Cache Size = 4 KB; Replacement way varies:\n";
	cout << "FIFO: " << 1 - miss_1111 << endl << "LRU: " << 1 - miss_2222 << endl << "LFU: " << 1 - miss_3333 << endl << "Random: " << 1 - miss_333 << endl;

	cout << "Experiment 3: Set Associative:\nThe following 4 are: Line Size = 32 bytes; Random Replacement; Cache Size = 64 KB; Number of ways varies from 2-16:\n";
	cout << 1 - miss_11111 << endl << 1 - miss_22222 << endl << 1 - miss_33333 << endl << 1 - miss_44444 << endl << endl;

	//cout << "LFU hits: " << LFUhits << endl;
}

int main() // Prints all ratios for all six memGen functions
{
	/*for (int i = 0; i < 10; i++)
		cout << "memGen1: " << memGen1() << endl;
	for (int i = 0; i < 10; i++)
		cout << "memGen2: " << memGen2() << endl;
	for (int i = 0; i < 10; i++)
		cout << "memGen3: " << memGen3() << endl;
	for (int i = 0; i < 10; i++)
		cout << "memGen4: " << memGen4() << endl;
	for (int i = 0; i < 10; i++)
		cout << "memGen5: " << memGen5() << endl;
	for (int i = 0; i < 10; i++)
	cout << "memGen6: "<<memGen6() << endl;*/

	//int inst = 0;
	//cacheResType r;
	show_miss_ratio_1(); // Prints all ratios for memGen1 function
	show_miss_ratio_2(); // Prints all ratios for memGen2 function
	show_miss_ratio_3(); // Prints all ratios for memGen3 function
	show_miss_ratio_4(); // Prints all ratios for memGen4 function
	show_miss_ratio_5(); // Prints all ratios for memGen5 function
	show_miss_ratio_6(); // Prints all ratios for memGen6 function
	system("pause");
}