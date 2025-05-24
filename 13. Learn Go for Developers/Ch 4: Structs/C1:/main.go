package main

type Membership struct {
  Type string
  MessageCharLimit int
}

type User struct {
	Membership // it is not copying fields it adds a type
  Name string
}

func newUser(name string, membershipType string) User {
  var messageCharLimit int;
  if membershipType == "premium" {
    messageCharLimit = 1000
  } else {
    messageCharLimit = 100
  }
  return User{Membership:Membership{Type:membershipType, MessageCharLimit:messageCharLimit}, Name:name}
}

