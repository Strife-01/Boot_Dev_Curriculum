package main

import (
	"fmt"
	"strconv"
	)

func main() {
	var username string = "presidentSkroob"
	var password string = strconv.Itoa(12345)

	// don't edit below this line
	fmt.Println("Authorization: Basic", username+":"+password)
}

