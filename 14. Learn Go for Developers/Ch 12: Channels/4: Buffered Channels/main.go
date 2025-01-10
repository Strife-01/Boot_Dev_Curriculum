package main

func addEmailsToQueue(emails []string) chan string {
  ch := make(chan string, 100)
  // here the calling goroutine, no matter if it is the main thread will populate the emails and then move forward
  // Anonymous IIFE
  func () {
    for _, email := range emails {
      ch <- email
    }
  }()

  return ch
}

