package main

import (
	"fmt"
	"time"
  "reflect" // we can use TypeOf function to determine the type of a variable at runtime

	tinytime "github.com/wagslane/go-tinytime"
)

func main() {
	tt := tinytime.New(1585750374)
	tt = tt.Add(time.Hour * 48)
	fmt.Println("1585750374 converted to a tinytime is:", tt)


  fmt.Println(reflect.TypeOf(tt))
  
}
