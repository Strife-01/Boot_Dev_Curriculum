package main

import (
	"fmt"
)

func printPrimes(max int) {
  for j := 2; j <= max; j++ {
    isPrime := true
    for i := 2; i * i <= j; i++ {
      if j % i == 0 && j / i != 1 {
        isPrime = false
        break
      }
    }
    if isPrime {
      fmt.Println(j)
    }
  }
}

// don't edit below this line

func test(max int) {
	fmt.Printf("Primes up to %v:\n", max)
	printPrimes(max)
	fmt.Println("===============================================================")
}

func main() {
	test(10)
	test(20)
	test(30)
	test(1000000)
}

