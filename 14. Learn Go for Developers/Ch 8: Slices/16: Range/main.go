package main

func indexOfFirstBadWord(msg []string, badWords []string) int {
  for index, word := range msg {
    for _, badWord := range badWords {
      if word == badWord {
        return index
      }
    }
  }
	return -1
}

