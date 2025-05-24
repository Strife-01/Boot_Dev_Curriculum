package main

import "fmt"

// Slices are passed by reference
func testSlicePointer(s []int) {
  s[4] = 10001
}

// Arrays are passed by value
func testArrayPointer(a [5]int) {
  a[2] = 20002
}

func main() {
  vec := [5]int{1,2,3,4,5}

  slice := vec[:]
  fmt.Println(slice)
  fmt.Println(vec)
  slice[0] = 1000


  fmt.Println(slice)
  fmt.Println(vec)

  testSlicePointer(slice)

  fmt.Println(slice)
  fmt.Println(vec)

  // we can pass by reference with pointers
  testArrayPointer(vec)
  fmt.Println(slice)
  fmt.Println(vec)
}
