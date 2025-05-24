package main

func createMatrix(rows, cols int) [][]int {
  matrix := make([][]int, 0)
  for i := 0; i < rows; i++ {
    row := make([]int, cols)
    for j := 0; j < cols; j++ {
      row[j] = i * j
    }
    matrix = append(matrix, row)
  }
  return matrix
}
