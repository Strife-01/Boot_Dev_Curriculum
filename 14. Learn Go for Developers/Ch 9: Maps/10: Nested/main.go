package main

func getNameCounts(names []string) map[rune]map[string]int {
  nestedMap := make(map[rune]map[string]int)
  for _, name := range names {
    // Unicode is multy byte characters so we need an array of bytes to represent it
    firstLetter := []rune(name)[0]
    
    if nestedMap[firstLetter] == nil {
      nestedMap[firstLetter] = make(map[string]int)
    }
    
    nestedMap[firstLetter][name]++
  }
  return nestedMap
}

