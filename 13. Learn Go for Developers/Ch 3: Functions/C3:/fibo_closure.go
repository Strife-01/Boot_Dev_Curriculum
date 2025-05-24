package main

import "fmt"

func fibo() func() int {
  a, b := 0, 1
  return func() int {
    tmp := a
    a = b
    b = tmp + a
    
    return tmp
  }
}

func main() {
  f := fibo()
  for i := 0; i < 9999; i++ {
    f()
  }
  fmt.Println(f())
}
