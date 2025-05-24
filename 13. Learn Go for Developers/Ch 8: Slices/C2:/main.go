package main

func isValidPassword(password string) bool {
	if len(password) < 5 || len(password) > 12 {
    return false
  }
  isUpper, isDigit := false, false
  for _, char := range password {
    if char >= 65 && char <= 90 {
      isUpper = true
    } else if char >= 48 && char <= 57 {
      isDigit = true
    }
    if isDigit && isUpper {
      return true
    }
  }
  return false
}

