int log2(unsigned int n) {
	int bits = 0;
	if (n > 32767) {
 		n >>= 16;
		bits += 16;
	}
	if (n > 127) {
		n >>= 8;
		bits += 8;
	}
	if (n > 7) {
		n >>= 4;
		bits += 4;
	}
	if (n > 1) {
		n >>= 2;
		bits += 2;
	}
	if (n > 0) {
		bits++;
	}
	return bits;
}
