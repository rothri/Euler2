#include <cstdio>
#include <iostream>
#include "Header.h"
using namespace std;

void main() {
	long * primes = setPrimeArray(10000);
	int i = 4;
	long lastAnswer = 0;
	long * primeFactors;
	long * factors;
	long answer;
	long sum = 0;
	while (i < 10000) {
		 primeFactors = factorPrimes(i, primes);
		 factors = factor(i, primeFactors);
		 answer = sumArray(factors);
		if (answer<10000 && answer>i) {
			primeFactors = factorPrimes(answer, primes);
			factors = factor(answer, primeFactors);
			lastAnswer = (sumArray(factors));
			if (lastAnswer == i) {
				sum += answer;
				sum += lastAnswer;
			}
		}
		i++;
	}
	printf("The answer is %d", sum);
	cin.get();
}
long sumArray(long * longArray) {
	//takes an Array terminated with 0 and returns the sum
	long sum = 0;
	while (*longArray != 0) {
		sum += *longArray;
//		printf("%d\n", *longArray);
		longArray++;
	}
	return sum;
}
long * factor(long num, long * factorPrimes) {
	int count = -1;
	long factors[100][2];
	long last = 0;
	while (*factorPrimes != 0) {
		if (last == *factorPrimes) {
			factors[count][1]++;
		}
		else {
			count++;
			factors[count][0] = *factorPrimes;
			factors[count][1] = 1;
		}
		last = *factorPrimes;
		factorPrimes++;
	}
	count++;//count now represents how many unique primes there are
	int size = 1;
	int i = 0;
	while (i < count) {
		size *= (factors[i][1] + 1);
		i++;
	}
	long* answer = new long[size];// dont need to add 1 because size includes the factor that is the num itself
	int* countPrimes = new int[count];
	i = 0;
	while (i < count) {
		countPrimes[i] = 0;
		i++;
	}
	i = 0;
	int j = 0;
	int k = 0;
	long ans = 1;
	while (i < size) {
		ans = 1;
		j = 0;
		countPrimes[0]++;
		while (j < count) {
			if (countPrimes[j] > factors[j][1]) {
				countPrimes[j] = 0;
				if ((j + 1) < count) {
					countPrimes[j + 1] += 1;
				}
			}
			k = countPrimes[j];
			while (k != 0) {
				ans = ans*factors[j][0];
				k--;
			}
			j++;
		}
		if (ans == 1) {
			ans = 0;
		}
		if (ans == num) {
			ans = 1;
		}
		answer[i] = ans;
		i++;
	}
	return answer;
}
long * factorPrimes(long num, long  * primes) {
	long i = num;
	int count = 0;
	long factorPrimes[1000];
	int n = 0;
	while (i!=1)
	{
		if (count > 100000) {
			printf("The number %d didnt factor after 100 000 loops", num);
			break;
		}
		if (i % *primes == 0) {
			i = i / *primes;
			factorPrimes[n] = *primes;
			n++;
		}
		else {
			primes++;
			if (*primes == 0) {
				printf("The number %d didnt factor because you ran out of primes\n", num);
				break;
			}
		}
		count++;
	}
	long * answer = new long[n+1];
	i = 0;
	while (i < n) {
		answer[i] = factorPrimes[i];
		i++;
	}
	answer[n] = 0;
	return answer;
}
long * setPrimeArray(long length) {
	//length needs to be above 13
	long startPrimes[10000];
	startPrimes[0] = 2;
	startPrimes[1] = 3;
	startPrimes[2] = 5;
	startPrimes[3] = 7;
	startPrimes[4] = 11;
	long i = 5;
	long n = 13;
	while (n < length) {
		if (IsPrime(&n, startPrimes)) {
			startPrimes[i] = n;
			i++;
		}
		n = n + 2;
	}
	long * primes= new long[i+1];
	n = 0;
	while (n < i) {
		primes[n] = startPrimes[n];
		n++;
	}
	primes[i] = 0;
	return primes;
}
bool IsPrime( long* num,  long*primeArray) {
	long sqNum = ceil(sqrt(*num));
	while (*primeArray != 0) {
		if (*num % *primeArray == 0) {
			return false;
		}
		if (sqNum < *primeArray) {
			return true;
		}
		primeArray++;
	}
	return true;
}