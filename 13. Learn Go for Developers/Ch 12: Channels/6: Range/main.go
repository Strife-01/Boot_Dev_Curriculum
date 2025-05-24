package main

func concurrentFib(n int) (fibo_nums []int) {
  ch := make(chan int)
  go fibonacci(n, ch)
  for num := range ch {
    fibo_nums = append(fibo_nums, num)
  }
  return fibo_nums
}

// don't touch below this line

func fibonacci(n int, ch chan int) {
	x, y := 0, 1
	for i := 0; i < n; i++ {
		ch <- x
		x, y = y, x+y
	}
	close(ch)
}

