package main

func countReports(numSentCh chan int) int {
  var totalNumReports int
  
  for true {
    if v, ok := <-numSentCh; ok {
      totalNumReports += v
    } else {
      break
    }
  }

  return totalNumReports
}

// don't touch below this line

func sendReports(numBatches int, ch chan int) {
	for i := 0; i < numBatches; i++ {
		numReports := i*23 + 32%17
		ch <- numReports
	}
	close(ch)
}

