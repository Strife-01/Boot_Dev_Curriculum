package main

func bulkSend(numMessages int) float64 {
  if numMessages == 0 {
    return 0.0
  }
  if numMessages == 1 {
    return 1.0
  }
  var total float64
  for i := 0; i < numMessages; i++ {
    total += 1.0 + float64(i) / 100
  }
  return total
}

