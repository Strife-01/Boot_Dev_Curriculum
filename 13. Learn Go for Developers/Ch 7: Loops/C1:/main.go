package main

func countConnections(groupSize int) int {
  return groupSize * (groupSize - 1) / 2
}

