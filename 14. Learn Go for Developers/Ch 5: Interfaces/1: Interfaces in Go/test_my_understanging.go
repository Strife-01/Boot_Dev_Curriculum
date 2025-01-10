package main

import "fmt"

type Greeter interface {
  greet()
}

type Person struct {
  firstName string
  lastName string
}

func (p Person) greet() {
  fmt.Println("Hello " + p.firstName + " " + p.lastName + "!")
}

func test(g Greeter) {
  g.greet()
}

func main() {
  var g Person;
  g.firstName = "andrei"
  g.lastName = "ursachi"

  g.greet()
  test(g)
}
