package main

import (
	"encoding/json"
)

func marshalAll[T any](items []T) ([][]byte, error) {
	var json_slice [][]byte = make([][]byte, 0, len(items))

	for _, data := range items {
		json, err := json.Marshal(data)
		if err != nil {
			return nil, err
		}

		json_slice = append(json_slice, json)
	}

	return json_slice, nil
}

