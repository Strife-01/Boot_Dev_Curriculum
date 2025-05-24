package main

import (
	"fmt"
	"time"
)

func sendEmail(message string) {
  // This is an anonymous IIFE
  // we make this a go routine and because it is asyncronous, it will happen after the 2nd print as we have a wait
	go func() {
		time.Sleep(time.Millisecond * 250)
		fmt.Printf("Email received: '%s'\n", message)
	}()
	fmt.Printf("Email sent: '%s'\n", message)
}

// Don't touch below this line

func test(message string) {
	sendEmail(message)
	time.Sleep(time.Millisecond * 500)
	fmt.Println("========================")
}

func main() {
	test("Hello there Kaladin!")
	test("Hi there Shallan!")
	test("Hey there Dalinar!")
}

