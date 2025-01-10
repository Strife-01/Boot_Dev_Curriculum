package main

import "time"

func processMessages(messages []string) []string {
  numberMessages := len(messages)
  processedMessagesChannel := make(chan string, numberMessages)
  done := make(chan struct{}, numberMessages)
  processedMessages := make([]string, 0)

  // process messages concourently
  for _, message := range messages {
    // We pass to the IIFE a message to avoid race conditions
    go func(msg string) {
      processedMessagesChannel <-process(msg)
      done <- struct{}{}
    }(message)
  }

  // check for done messages from all goroutines
  for i := 0; i < numberMessages; i++ {
    <-done
  }

  // Append the modiffied messages
  for i := 0; i < numberMessages; i++ {
    processedMessages = append(processedMessages, <-processedMessagesChannel)
  }

  close(processedMessagesChannel)
  close(done)

  return processedMessages
}

// don't touch below this line

func process(message string) string {
	time.Sleep(1 * time.Second)
	return message + "-processed"
}

