package main

// Type alias
type emailStatus = int 

const (
  emailBounced emailStatus = iota
  emailInvalid
  emailDelivered
  emailOpened
)
