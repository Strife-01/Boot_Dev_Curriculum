package main

func calculateFinalBill(costPerMessage float64, numMessages int) float64 {
	return float64(numMessages) * costPerMessage - calculateDiscountRate(numMessages) * float64(numMessages) * costPerMessage
}

func calculateDiscountRate(messagesSent int) float64 {
	if messagesSent > 5000 {
		return .2
	} else if messagesSent > 1000{
		return .1
	}
	return 0
}

// don't touch below this line

func calculateBaseBill(costPerMessage float64, messagesSent int) float64 {
	return costPerMessage * float64(messagesSent)
}

