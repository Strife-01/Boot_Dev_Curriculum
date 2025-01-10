package main

import (
	"time"
)

type email struct {
	body string
	date time.Time
}

func checkEmailAge(emails [3]email) [3]bool {
  // because of resource sharing, the channels are allocated on the heap
	isOldChan := make(chan bool)

  // by making this call a goroutine, we avoid deadlocks as we will have a thread that is concurrently populating the channel while
  // on this main thread we are reading the value
	go sendIsOld(isOldChan, emails)

  // this is blocking and it will wait untill isOld[0] gets an element, ie the channel gets populated by a goroutine
  // after that it will move to the next blocking event
  // everything that uses channels is blocking until we have a gorouting that can read or write
	isOld := [3]bool{}
	isOld[0] = <-isOldChan
	isOld[1] = <-isOldChan
	isOld[2] = <-isOldChan
	return isOld
}

// don't touch below this line

func sendIsOld(isOldChan chan<- bool, emails [3]email) {
	for _, e := range emails {
		if e.date.Before(time.Date(2020, 0, 0, 0, 0, 0, 0, time.UTC)) {
      // this writing operation is blocking and it requires the goroutine to run it so this is why we spawn a thread when calling go sendIsOld(...)
			isOldChan <- true
			continue
		}
		isOldChan <- false
	}
}

