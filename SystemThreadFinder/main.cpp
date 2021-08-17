#include "includes.h"

int main() {
	if (threadfinder::driver_range_check()) {
		printf("Detection: Range check\n");
	}
	if (threadfinder::system_time_check(10)) {
		printf("Detection: Time check\n");
	}
	system("pause");
}