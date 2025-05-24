package main

import "slices"

func findSuggestedFriends(username string, friendships map[string][]string) []string {
  suggestedFriends := make([]string, 0)
 
  for _, friendFriends := range friendships[username] {
    for _, suggested := range friendships[friendFriends] {
     if !slices.Contains(suggestedFriends, suggested) && !slices.Contains(friendships[username], suggested) && suggested != username {
        suggestedFriends = append(suggestedFriends, suggested)
      }
    }
  }

  if len(suggestedFriends) == 0 {
    return nil
  }
  return suggestedFriends
}

