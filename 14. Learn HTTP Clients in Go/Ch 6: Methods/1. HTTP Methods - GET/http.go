package main

import (
	"encoding/json"
	"net/http"
)

func getUsers(url string) ([]User, error) {
	resp, err := http.Get(url)
	if err != nil {
		return nil, err
	}

	defer resp.Body.Close()

	var users []User
	decoder := json.NewDecoder(resp.Body)

	err = decoder.Decode(&users)
	return users, err
}

