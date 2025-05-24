package main

import (
  "strings"
)

func countDistinctWords(messages []string) int {
  if len(messages) == 0 || (len(messages) == 1 && messages[0] == "") {
    return 0
  }

  words := make(map[string]int)
  for _, message := range messages {
    stripped_words := strings.Split(message, " ")
    for _, word := range stripped_words {
      words[strings.ToLower(word)]++
    }
  }
  return len(words)
}

