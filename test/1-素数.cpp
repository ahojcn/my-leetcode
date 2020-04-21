// 

// 20 个素数和

// 1. 暴力
bool isPrime(const int n) {
	// 判断是否为素数
}

int main(int argc, char const *argv[])
{
	int count = 0;
	int sum = 0;
	int i = 1000;
	while (i > 1 && count < 20) {
		if (isPrime(i)) {
			sum += i;
			++count;
		}

		--i;
	}

	// 打印

	return 0;
}
