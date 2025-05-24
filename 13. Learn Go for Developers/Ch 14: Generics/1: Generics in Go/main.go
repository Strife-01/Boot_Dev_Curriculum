package main

func getLast[T any](s []T) T {
	if len(s) == 0 {
    var r T
    return r
  }
  return s[len(s) - 1]
}

