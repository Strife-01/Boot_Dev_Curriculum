package main

type cost struct {
	day   int
	value float64
}

func sum(nums ...float64) float64 {
  s := 0.0
  for i := 0; i < len(nums); i++ {
    s += nums[i]
  }
  return s
}

func getCostsByDay(costs []cost) []float64 {
  length := 0
  for i := 0; i < len(costs); i++ {
    if length < costs[i].day + 1 {
      length = costs[i].day + 1
    }
  }
  finalCosts := make([]float64, length)
  for i := 0; i < len(costs); i++ {
    finalCosts[costs[i].day] = finalCosts[costs[i].day] + costs[i].value
  }
  return finalCosts
}

