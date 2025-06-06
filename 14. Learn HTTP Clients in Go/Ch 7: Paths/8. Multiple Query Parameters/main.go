package main

func fetchTasks(baseURL, availability string) []Issue {
	query := "?sort=estimate&limit="
	switch availability {
	case "Low":
		query += "1"
	case "Medium":
		query += "3"
	case "High":
		query += "5"
	}

	fullURL := baseURL + query
	return getIssues(fullURL)
}

