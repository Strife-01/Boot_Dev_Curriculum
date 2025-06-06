package main

import (
	"net/http"
)

func getContentType(res *http.Response) string {
	header := res.Header.Get("content-type")
	return header
}

