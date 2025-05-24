package main

import "fmt"

func main() {
	const premiumPlanName = "Premium Plan"
	const basicPlanName = "Basic Plan"

	// don't edit below this line

	fmt.Println("plan:", premiumPlanName)
	fmt.Println("plan:", basicPlanName)
}

// can only be declared with const name = value not with :=
// They can only be primitive types, cannot be slices arrays maps or structs
