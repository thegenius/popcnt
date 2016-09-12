#include <stdio.h>
#include "popcnt.h"

static const size_t popcnt_table[256] ={
            0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
            1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
            1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
            1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
            3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
            4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8
};

int verify_popcnt_u8() {
	int cnt; 
	for (int i=0; i<256; ++i) {
		cnt = popcnt_u8(i);
		if (cnt != popcnt_table[i]) {
			printf("popcnt_u8 verify fail: expect popcnt_u8(%d) == %d, but popcnt_u8(%d) == %d\n", i, popcnt_table[i], i, cnt);
			return -1;
		}
	}
	printf("popcnt_u8 verify sucess!\n");
	return 0;
}

int verify_popcnt_u16() {
	int cnt, expect_cnt; 
	for (int i=0; i<65536; ++i) {
		cnt = popcnt_u16(i);
		expect_cnt = popcnt_table[i&255] + popcnt_table[i>>8];
		if (cnt != expect_cnt) {
			printf("popcnt_u16 verify fail: expect popcnt_u16(%d) == %d, but popcnt_u16(%d) == %d\n", i, expect_cnt, i, cnt);
			return -1;
		}
	}
	printf("popcnt_u16 verify sucess!\n");
	return 0;
}

int verify_popcnt_u32() {
	int cnt, expect_cnt; 
	for (unsigned int i=65536; i<2*65536; ++i) {
		cnt = popcnt_u32(i);
		expect_cnt = popcnt_u16(i&65535) + popcnt_u16(i>>16);
		if (cnt != expect_cnt) {
			printf("popcnt_u32 verify fail: expect popcnt_u32(%d) == %d, but popcnt_u32(%d) == %d\n", i, expect_cnt, i, cnt);
			return -1;
		}
	}
	printf("popcnt_u32 verify sucess!\n");
	return 0;
}

int main(int argc, char* argv[]) {
	size_t success = 0; 
	success = verify_popcnt_u8();	
	success = verify_popcnt_u16();	
	success = verify_popcnt_u32();	
	return 0;
}
