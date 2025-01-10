package main

func maxMessages(thresh int) int {
  if thresh == 100 {
    return 1
  }
  for i , total := 0, 0; ; i++ {
    total += 100 + i
    if total > thresh {
      return i
    }
  }
}
