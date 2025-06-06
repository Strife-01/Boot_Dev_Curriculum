package main

import "fmt"

func main() {
	accountAgeFloat := 2.6
	var accountAgeInt int32 = int32(accountAgeFloat)
	fmt.Println("Your account has existed for", accountAgeInt, "years")
}

