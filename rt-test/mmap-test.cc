/*!
 * \file
 * \brief test general mmap
 */


#include <rt-test/assert.h>
#include <user/user.h>

void main() {
	for (int i = 1; i < 64; ++i) {
		auto size = i * 4096;
		void *data = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
		assert(data != (void*) MAP_FAILED);
		auto ptr = reinterpret_cast<volatile char*>(data);
		for (int j = 0; j < size; ++j) {
			ptr[j] = j;
			assert(ptr[j] == char(j));
		}
		assert(!munmap(data, size));
	}
}
