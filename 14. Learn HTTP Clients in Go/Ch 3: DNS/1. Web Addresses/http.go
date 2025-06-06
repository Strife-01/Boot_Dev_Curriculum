package main

import (
	"fmt"
	"io"
	"net/http"
	"encoding/json"
)

func getIPAddress(domain string) (string, error) {
	url := fmt.Sprintf("https://1.1.1.1/dns-query?name=%s&type=A", domain)

	req, err := http.NewRequest("GET", url, nil)
	if err != nil {
		return "", fmt.Errorf("error creating request: %w", err)
	}
	req.Header.Set("accept", "application/dns-json")

	client := http.Client{}
	res, err := client.Do(req)
	if err != nil {
		return "", fmt.Errorf("error sending request: %w", err)
	}
	defer res.Body.Close()

	body, err := io.ReadAll(res.Body)
	if err != nil {
		return "", fmt.Errorf("error reading response body: %w", err)
	}

	var dnsResp DNSResponse
	err = json.Unmarshal(body, &dnsResp)
	if err != nil {
		return "", err
	}

	data := dnsResp.Answer[0].Data
	if len(data) == 0 {
		return "", fmt.Errorf("data not found")
	}

	return string(data), nil
}

