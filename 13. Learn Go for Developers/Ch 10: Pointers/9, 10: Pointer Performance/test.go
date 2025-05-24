package main

import "fmt"

func main() {
  x := new(int)
  *x = 12
  fmt.Println(*x)
}
