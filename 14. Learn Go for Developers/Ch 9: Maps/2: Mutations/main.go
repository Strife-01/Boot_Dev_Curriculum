package main

func deleteIfNecessary(users map[string]user, name string) (deleted bool, err error) {
  u, ok := users[name]
  if !ok {
    deleted = false
    err = deletetionError{}
    return deleted, err
  }
  if !u.scheduledForDeletion {
    return false, nil
  }
  delete(users, name)
  return true, nil
}
type deletetionError struct {
  message string
}

func (d deletetionError) Error() string {
  return "not found"
}

type user struct {
	name                 string
	number               int
	scheduledForDeletion bool
}
