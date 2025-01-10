package main

import "errors"

func getUserMap(names []string, phoneNumbers []int) (map[string]user, error) {
  if len(names) != len(phoneNumbers) {
    return nil, errors.New("invalid sizes")
  }
  phoneBook := make(map[string]user)
  for i := 0; i < len(names); i++ {
    u := user{name:names[i], phoneNumber:phoneNumbers[i]}
    phoneBook[names[i]] = u
  }
  return phoneBook, nil
}

type user struct {
	name        string
	phoneNumber int
}

