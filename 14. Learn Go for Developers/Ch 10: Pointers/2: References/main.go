package main

import (
	"strings"
)

func removeProfanity(message *string) {
  /*
  words := strings.Split(*message, " ")
  for i, word := range words {
    switch word {
    case "fubb", "shiz":
      words[i] = "****"
    case "witch":
      words[i] = "*****"
    default:
      continue
    }
  }
  */
	*message = strings.ReplaceAll(*message, "shiz", "****")
	*message = strings.ReplaceAll(*message, "fubb", "****")
	*message = strings.ReplaceAll(*message, "witch", "*****")
}

